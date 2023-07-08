'
' PwrPerf.vbs
'
' PwrTest example script which measures S3 resume time for 
' 4 sleep transitions, but ignores the first sleep transition.
'
' usage: S3Resume.vbs

Option Explicit

'----------------------------
' Declarations
'----------------------------
Const PERF_PWR_TEST_COMMAND = ".\pwrtest.exe /sleep /c:4 /d:90 /p:90 /h:n /s:3"
Const PERF_PWRTESTLOG_XML_FILE = "PWRTESTLOG.XML"

Const PERF_XML_NODE_LIST_SEARCH_PREFIX = "//"
Const PERF_XML_SLEEP_TRANSITION_NODE_NAME = "SleepTransition"

Const PERF_XML_BIOSINIT_NAME = "BIOSInit"
Const PERF_XML_RESUME_NAME = "DriverInit"

Const PERF_ERROR_MSG_LOG_FILE_NOT_VALID = "ERROR: The PwrTestLog.xml file Could Not Be Found."
Const PERF_MSG_LOG_OPENED_SUCCESSFULLY = "The PwrTestLog.xml file Was Opened Successfuly:"

Const PERF_ERROR_MSG_NO_SLEEP_SCENARIO = "ERROR: The PwrTestLog.xml file does not contain sleep transition data."

Const PERF_ERROR_MSG_FIRST_TRANSITION_IGNORE = "The PwrTestLog.xml does not contain data for more than one sleep transition."

Const PERF_MSG_RESUME_GOAL_MET = "The system resumed from S3 in less than 2 seconds for all tested transitions."

Const PERF_ERROR_MSG_RESUME_GOAL_NOT_MET = "ERROR: The system required more than 2 seconds to resume for at least one of the tested sleep transitions."

Const PERF_RESUME_GOAL_TIME_MS = 2000

Const EXIT_GENERIC_FATAL = 255

Const CMD_NONE	= 0
Const CMD_RUN	= 1

'---------------------------------
' Globals
'---------------------------------
Dim g_bDebug		'Set to True to enable debug spew
Dim g_S3SleepPerfTraceFileDOM

'---------------------------------
' Main
'---------------------------------
PerfMain


Sub PerfMain
	Dim bCmdOption

	g_bDebug = False
	
	bCmdOption = PerfHandleCommandLineArguments

	If( CMD_RUN = bCmdOption )	Then
		PerfRunProgram
		PerfParseXmlFile
	End If
 	
End Sub
'End Main


Sub PerfRunProgram
	Dim RetRun
	Dim wshShell
	Set WshShell = WScript.CreateObject("WScript.Shell")

	RetRun = WshShell.Run(PERF_PWR_TEST_COMMAND, 1, true)
End Sub

Sub PerfParseXmlFile
	Dim bFileExist

	bFileExist = PerfIsLogFileExist
	If(1=bFileExist)	Then
		'
		' Get XML DOM to open / parse the file
		'
		PerfOpenAdvancedPerformanceTraceFileWithDOM g_S3SleepPerfTraceFileDOM, PERF_PWRTESTLOG_XML_FILE 
		
		PerfGetResumeTime()
	End If

End Sub

'
' PerfHandleCommandLineArguments
'
' - Makes sure that one command line argument exists,
' - that the file can be opened and displays usage
' - otherwise
'
Function PerfHandleCommandLineArguments

	if (WScript.Arguments.Count >= 1) then
		if (WScript.Arguments.Item (0) = "/?") OR (WScript.Arguments.Item(0) = "-?") then
			PerfDisplayUsage
		end If
		
		PerfHandleCommandLineArguments = CMD_NONE
	else 
		PerfHandleCommandLineArguments = CMD_RUN
	end if
	
End Function

'
' PerfDisplayUsage
'
' - Displays the usage information for the script
'
Sub PerfDisplayUsage 

	WScript.Echo("Prperf.vbs demonstrates how to script the PwrTest.exe tool for")
	WScript.Echo("the purposes of sleep /resume testing.")
	WScript.Echo(" ")
	WScript.Echo("Pwrperf.vbs instructs PwrTest.exe to trace 4 S3 (standby) transitions")
	WScript.Echo("and then outputs the resume time results by parsing the PwrTest XML")
	WScript.Echo("log file.")
 
 End Sub


'
' PerfLogToPerfFileAndDisplay 
'
' - Writes the text string as a line to the PwrPerf log file
'   and the standard output
'
Sub PerfLogToPerfFileAndDisplay  (Text)

	WScript.Echo (Text)

End Sub

'
' PerfDebugOutput 
'
' - Writes the text string as a line to the PwrPerf log file
'   and the standard output
'
Sub PerfDebugOutput  (Text)
	If( g_bDebug ) 	Then
		WScript.Echo (Text)
	 End If
End Sub


'
' PerfIsLogFileExist
'
' - Makes sure that one command line argument exists,
' - that the file can be opened and displays usage
' - otherwise
'
Function PerfIsLogFileExist
	'
	' Test that the argument is a legit file
	' by opening it
	'
	Err.Clear
	
	Dim tempFile
	Dim FileSystemObject

	Set FileSystemObject = WScript.CreateObject("Scripting.FileSystemObject")
	On Error Resume Next
	Set tempFile = FileSystemObject.OpenTextFile(PERF_PWRTESTLOG_XML_FILE)
	tempFile.Close()

	PerfIsLogFileExist = 1
	if (Err.Number) then

		PerfLogToPerfFileAndDisplay (PERF_ERROR_MSG_LOG_FILE_NOT_VALID)
		Err.Clear
		PerfIsLogFileExist = 0
		Exit Function

	end if

	PerfDebugOutput (PERF_MSG_LOG_OPENED_SUCCESSFULLY & " " & PERF_PWRTESTLOG_XML_FILE & vbNewLine)

End Function


'
' PerfGetResumeTime
'
' Igonore the first power transition, and caculate the following transistions with
'	 CurrentTotalResumeTime = ResumeTime + BiosInitTime
'
'	Caculate and display Min, Max, and Average resume time
'
Function PerfGetResumeTime(  )

	PerfDebugOutput ( "PerfGetResumeTime: Start to parse the sleep scenarios")
	'
	' See if we can spew events
	'
	Dim EventNodeList
	Set EventNodeList = g_S3SleepPerfTraceFileDOM.SelectNodes(PERF_XML_NODE_LIST_SEARCH_PREFIX & PERF_XML_SLEEP_TRANSITION_NODE_NAME)
	'WScript.Echo (EventNodeList.length)

	Dim ResumeTime
	Dim BiosInitTime
	Dim CurrentTotalResumeTime
	Dim ResumeGoalMet

	Dim xEventNode
	Dim EventNode

	Dim bFirstRound
	Dim TotalResumeTime
	Dim MinResumeTime
	Dim AverageResumeTime
	Dim MaxResumeTime

	Dim MinTransition
	Dim MaxTransition

	Dim RetValue

	ResumeGoalMet = True
	RetValue = 0
	
	If( 0 = EventNodeList.length )	Then
		PerfLogToPerfFileAndDisplay(PERF_ERROR_MSG_NO_SLEEP_SCENARIO)
		Exit Function
	End If

	If( 1 = EventNodeList.length )	Then
		PerfLogToPerfFileAndDisplay(PERF_ERROR_MSG_FIRST_TRANSITION_IGNORE)
		Exit Function
	End If
	
	RetValue = 1
	xEventNode = 0

	TotalResumeTime = 0
	bFirstRound = 1
	MinResumeTime = 0
	MaxResumeTime = 0
	
	PerfLogToPerfFileAndDisplay( "Transition # | BIOS Init | Driver Init | Total" & vbNewLine)


	While( xEventNode<EventNodeList.length )

		Set EventNode=EventNodeList.Item(xEventNode)

		PerfGetTextForId EventNode, PERF_XML_BIOSINIT_NAME, BiosInitTime
		PerfGetTextForId EventNode, PERF_XML_RESUME_NAME, ResumeTime

		CurrentTotalResumeTime = CInt(BiosInitTime) + CInt(ResumeTime)

		if( 0 = xEventNode )	Then
		
			PerfLogToPerfFileAndDisplay( "0 (ignored)    " & BiosInitTime &"         " & ResumeTime & "           " & CurrentTotalResumeTime )
		
	
		Else
		
			PerfLogToPerfFileAndDisplay( xEventNode & "              " & BiosInitTime &"         " & ResumeTime & "           " & CurrentTotalResumeTime )
			
			PerfDebugOutput("xEventNode: " & xEventNode &"; CurrentTotalResumeTime: " & CurrentTotalResumeTime)
			
	
			TotalResumeTime = TotalResumeTime + CurrentTotalResumeTime
			
			if( 1 = bFirstRound )	Then
				MinResumeTime = CurrentTotalResumeTime
				MaxResumeTime = CurrentTotalResumeTime
				MinTransition = xEventNode
				MaxTransition= xEventNode
				bFirstRound = 0
			Else
				If( CurrentTotalResumeTime  < MinResumeTime )	Then
					MinResumeTime = CurrentTotalResumeTime
					MinTransition = xEventNode
				End If

				If( CurrentTotalResumeTime  > MaxResumeTime )	Then
					MaxResumeTime = CurrentTotalResumeTime
					MaxTransition= xEventNode
				End If
			End If

			'
			' Check Resume Goal
			'
			if (CurrentTotalResumeTime > PERF_RESUME_GOAL_TIME_MS) then

				ResumeGoalMet = False

			end if

			
		
		End If
		
		xEventNode = xEventNode + 1
	Wend

	if (ResumeGoalMet = True) then

		PerfLogToPerfFileAndDisplay(vbNewLine & PERF_MSG_RESUME_GOAL_MET) 

	else

		PerfLogToPerfFileAndDisplay(vbNewLine & PERF_ERROR_MSG_RESUME_GOAL_NOT_MET)

	end if	
	
	AverageResumeTime = TotalResumeTime / (EventNodeList.length-1)
	
	PerfLogToPerfFileAndDisplay(vbNewLine & "Minimum Total Time: " & MinResumeTime & ", Transition No. " & MinTransition )
	PerfLogToPerfFileAndDisplay("Maximum Total Time: " & MaxResumeTime & ", Transition No. " & MaxTransition ) 
	PerfLogToPerfFileAndDisplay("Average Total Time: " & CInt(AverageResumeTime) )
	
	PerfGetResumeTime = RetValue

End Function



'
' PerfGetEventIDFromSystemNode
'
' - Returns a single event node with a matching EventID
'
Sub PerfGetTextForId (EventNode, IdName, ByRef EventID)

	'
	' Get the EventID node data
	'
	Dim EventIDNode
	Set EventIDNode = EventNode.SelectSingleNode(IdName)
	EventID = EventIDNode.Text
	
	PerfDebugOutput ( IdName & ": " & EventID)

End Sub


'
' PerfOpenAdvancedPerformanceTraceFileWithDOM
'
' - Opens the advanced performance log file using
'   the DOM XML parser
'
Sub PerfOpenAdvancedPerformanceTraceFileWithDOM (ByRef PerfLogFileXML, PerfLogFileName)
	Dim PerfSpyLogFileXML
	
	Set PerfLogFileXML = CreateObject("MSXML.DOMDocument")
	PerfLogFileXML.validateOnParse = True
	
	PerfLogFileXML.Load(PerfLogFileName)
	
	If (PerfLogFileXML.parseError.errorCode <> 0) then
		Dim PerfLogFileXMLError

   		Set PerfLogFileXMLError = PerfLogFileXML.parseError
		PerfLogToPerfFileAndDisplay("*** PowerSpy Log File Error Detected ***")
		PerfLogToPerfFileAndDisplay(" ")
		PerfLogToPerfFileAndDisplay("LineNumber: " & PerfLogFileXMLError.line)
		PerfLogToPerfFileAndDisplay("LinePos:    " & PerfLogFileXMLError.linepos)
		PerfLogToPerfFileAndDisplay("Text:       " & PerfLogFileXMLError.srcText)
		PerfLogToPerfFileAndDisplay("Reason:     " & PerfLogFileXMLError.reason)
		PerfLogToPerfFileAndDisplay("****************************************")
		
		Set PerfSpyLogFileXML = nothing

	end if

End Sub
