REM Note that missing classes in log file mean tthe hat WMI cannot access them.
REM Most likely this indicates a problem with the driver.
REM See %windir%\system32\wbem\wmiprov.log and nt eventlog for more details.
REM You could also delete the line On Error Resume Next and examine the
REM specific VBScript error


On Error Resume Next

Set fso = CreateObject("Scripting.FileSystemObject")
Set a = fso.CreateTextFile("acpimof.log", True)
Set Service = GetObject("winmgmts:{impersonationLevel=impersonate}!root/wmi")
Rem AcpiTest_QSPackage - Class to test Query/Set a package
Set enumSet = Service.InstancesOf ("AcpiTest_QSPackage")
a.WriteLine("AcpiTest_QSPackage")
for each instance in enumSet
    a.WriteLine("    InstanceName=" & instance.InstanceName)
    for i2 = 0 to (16-1)
    a.WriteLine("        instance.Data.Bytes("&i2&")=" & instance.Data.Bytes(i2))
    next 'i2
next 'instance

Rem AcpiTest_QSString - Class to test Query/Set a string
Set enumSet = Service.InstancesOf ("AcpiTest_QSString")
a.WriteLine("AcpiTest_QSString")
for each instance in enumSet
    a.WriteLine("    InstanceName=" & instance.InstanceName)
    a.WriteLine("        instance.Text=" & instance.Text)
next 'instance

Rem AcpiTest_QULong - Class to test Query/Set a ULONG
Set enumSet = Service.InstancesOf ("AcpiTest_QULong")
a.WriteLine("AcpiTest_QULong")
for each instance in enumSet
    a.WriteLine("    InstanceName=" & instance.InstanceName)
    a.WriteLine("        instance.ULong=" & instance.ULong)
next 'instance

Rem AcpiTest_MPackage - Class used to operate methods on a package
Set enumSet = Service.InstancesOf ("AcpiTest_MPackage")
a.WriteLine("AcpiTest_MPackage")
for each instance in enumSet
    a.WriteLine("    InstanceName=" & instance.InstanceName)
next 'instance

Rem AcpiTest_MString - Class used to operate methods on a string
Set enumSet = Service.InstancesOf ("AcpiTest_MString")
a.WriteLine("AcpiTest_MString")
for each instance in enumSet
    a.WriteLine("    InstanceName=" & instance.InstanceName)
next 'instance

Rem AcpiTest_MULong - Class used to operate methods on a ULong
Set enumSet = Service.InstancesOf ("AcpiTest_MULong")
a.WriteLine("AcpiTest_MULong")
for each instance in enumSet
    a.WriteLine("    InstanceName=" & instance.InstanceName)
next 'instance

a.Close
Wscript.Echo "acpimof Test Completed, see acpimof.log for details"
