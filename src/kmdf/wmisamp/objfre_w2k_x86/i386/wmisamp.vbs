REM Note that missing classes in log file mean tthe hat WMI cannot access them.
REM Most likely this indicates a problem with the driver.
REM See %windir%\system32\wbem\wmiprov.log and nt eventlog for more details.
REM You could also delete the line On Error Resume Next and examine the
REM specific VBScript error


On Error Resume Next

Set fso = CreateObject("Scripting.FileSystemObject")
Set a = fso.CreateTextFile("wmisamp.log", True)
Set Service = GetObject("winmgmts:{impersonationLevel=impersonate}!root/wmi")
Rem WmiSampleClass1 - Description of sample class 1
Set enumSet = Service.InstancesOf ("WmiSampleClass1")
a.WriteLine("WmiSampleClass1")
for each instance in enumSet
    a.WriteLine("    InstanceName=" & instance.InstanceName)
    a.WriteLine("        instance.Xboolean=" & instance.Xboolean)
    a.WriteLine("        instance.Xuint8=" & instance.Xuint8)
    a.WriteLine("        instance.Xuint16=" & instance.Xuint16)
    a.WriteLine("        instance.Xuint32=" & instance.Xuint32)
    a.WriteLine("        instance.Xuint64=" & instance.Xuint64)
    a.WriteLine("        instance.Xint8=" & instance.Xint8)
    a.WriteLine("        instance.Xint16=" & instance.Xint16)
    a.WriteLine("        instance.Xint32=" & instance.Xint32)
    a.WriteLine("        instance.Xint64=" & instance.Xint64)
next 'instance

Rem WmiSampleClass2 - Description of Sample Class 2
Set enumSet = Service.InstancesOf ("WmiSampleClass2")
a.WriteLine("WmiSampleClass2")
for each instance in enumSet
    a.WriteLine("    InstanceName=" & instance.InstanceName)
    a.WriteLine("        instance.EmbeddedClass1.Xboolean=" & instance.EmbeddedClass1.Xboolean)
    a.WriteLine("        instance.EmbeddedClass1.Xuint8=" & instance.EmbeddedClass1.Xuint8)
    a.WriteLine("        instance.EmbeddedClass1.Xuint16=" & instance.EmbeddedClass1.Xuint16)
    a.WriteLine("        instance.EmbeddedClass1.Xuint32=" & instance.EmbeddedClass1.Xuint32)
    a.WriteLine("        instance.EmbeddedClass1.Xuint64=" & instance.EmbeddedClass1.Xuint64)
    a.WriteLine("        instance.EmbeddedClass1.Xint8=" & instance.EmbeddedClass1.Xint8)
    a.WriteLine("        instance.EmbeddedClass1.Xint16=" & instance.EmbeddedClass1.Xint16)
    a.WriteLine("        instance.EmbeddedClass1.Xint32=" & instance.EmbeddedClass1.Xint32)
    a.WriteLine("        instance.EmbeddedClass1.Xint64=" & instance.EmbeddedClass1.Xint64)
next 'instance

Rem WmiSampleClass3 - Description of Sample Class 3
Set enumSet = Service.InstancesOf ("WmiSampleClass3")
a.WriteLine("WmiSampleClass3")
for each instance in enumSet
    a.WriteLine("    InstanceName=" & instance.InstanceName)
    for i1 = 0 to (4-1)
    a.WriteLine("        instance.EmbeddedClass1("&i1&").Xboolean=" & instance.EmbeddedClass1(i1).Xboolean)
    a.WriteLine("        instance.EmbeddedClass1("&i1&").Xuint8=" & instance.EmbeddedClass1(i1).Xuint8)
    a.WriteLine("        instance.EmbeddedClass1("&i1&").Xuint16=" & instance.EmbeddedClass1(i1).Xuint16)
    a.WriteLine("        instance.EmbeddedClass1("&i1&").Xuint32=" & instance.EmbeddedClass1(i1).Xuint32)
    a.WriteLine("        instance.EmbeddedClass1("&i1&").Xuint64=" & instance.EmbeddedClass1(i1).Xuint64)
    a.WriteLine("        instance.EmbeddedClass1("&i1&").Xint8=" & instance.EmbeddedClass1(i1).Xint8)
    a.WriteLine("        instance.EmbeddedClass1("&i1&").Xint16=" & instance.EmbeddedClass1(i1).Xint16)
    a.WriteLine("        instance.EmbeddedClass1("&i1&").Xint32=" & instance.EmbeddedClass1(i1).Xint32)
    a.WriteLine("        instance.EmbeddedClass1("&i1&").Xint64=" & instance.EmbeddedClass1(i1).Xint64)
    next 'i1
next 'instance

Rem WmiSampleClass5 - Description of Sample Class 5
Set enumSet = Service.InstancesOf ("WmiSampleClass5")
a.WriteLine("WmiSampleClass5")
for each instance in enumSet
    a.WriteLine("    InstanceName=" & instance.InstanceName)
    for i2 = 0 to (8-1)
    a.WriteLine("        instance.EmbeddedClass2.Xboolean("&i2&")=" & instance.EmbeddedClass2.Xboolean(i2))
    next 'i2
    for i2 = 0 to (8-1)
    a.WriteLine("        instance.EmbeddedClass2.Xuint8("&i2&")=" & instance.EmbeddedClass2.Xuint8(i2))
    next 'i2
    for i2 = 0 to (4-1)
    a.WriteLine("        instance.EmbeddedClass2.Xuint16("&i2&")=" & instance.EmbeddedClass2.Xuint16(i2))
    next 'i2
    for i2 = 0 to (2-1)
    a.WriteLine("        instance.EmbeddedClass2.Xuint32("&i2&")=" & instance.EmbeddedClass2.Xuint32(i2))
    next 'i2
    a.WriteLine("        instance.EmbeddedClass2.Xuint64=" & instance.EmbeddedClass2.Xuint64)
    for i2 = 0 to (8-1)
    a.WriteLine("        instance.EmbeddedClass2.Xint8("&i2&")=" & instance.EmbeddedClass2.Xint8(i2))
    next 'i2
    for i2 = 0 to (4-1)
    a.WriteLine("        instance.EmbeddedClass2.Xint16("&i2&")=" & instance.EmbeddedClass2.Xint16(i2))
    next 'i2
    for i2 = 0 to (2-1)
    a.WriteLine("        instance.EmbeddedClass2.Xint32("&i2&")=" & instance.EmbeddedClass2.Xint32(i2))
    next 'i2
    a.WriteLine("        instance.EmbeddedClass2.Xint64=" & instance.EmbeddedClass2.Xint64)
next 'instance

Rem WmiSampleClass6 - Description of Sample Class 6
Set enumSet = Service.InstancesOf ("WmiSampleClass6")
a.WriteLine("WmiSampleClass6")
for each instance in enumSet
    a.WriteLine("    InstanceName=" & instance.InstanceName)
    for i1 = 0 to (4-1)
    for i2 = 0 to (8-1)
    a.WriteLine("        instance.EmbeddedClass2("&i1&").Xboolean("&i2&")=" & instance.EmbeddedClass2(i1).Xboolean(i2))
    next 'i2
    for i2 = 0 to (8-1)
    a.WriteLine("        instance.EmbeddedClass2("&i1&").Xuint8("&i2&")=" & instance.EmbeddedClass2(i1).Xuint8(i2))
    next 'i2
    for i2 = 0 to (4-1)
    a.WriteLine("        instance.EmbeddedClass2("&i1&").Xuint16("&i2&")=" & instance.EmbeddedClass2(i1).Xuint16(i2))
    next 'i2
    for i2 = 0 to (2-1)
    a.WriteLine("        instance.EmbeddedClass2("&i1&").Xuint32("&i2&")=" & instance.EmbeddedClass2(i1).Xuint32(i2))
    next 'i2
    a.WriteLine("        instance.EmbeddedClass2("&i1&").Xuint64=" & instance.EmbeddedClass2(i1).Xuint64)
    for i2 = 0 to (8-1)
    a.WriteLine("        instance.EmbeddedClass2("&i1&").Xint8("&i2&")=" & instance.EmbeddedClass2(i1).Xint8(i2))
    next 'i2
    for i2 = 0 to (4-1)
    a.WriteLine("        instance.EmbeddedClass2("&i1&").Xint16("&i2&")=" & instance.EmbeddedClass2(i1).Xint16(i2))
    next 'i2
    for i2 = 0 to (2-1)
    a.WriteLine("        instance.EmbeddedClass2("&i1&").Xint32("&i2&")=" & instance.EmbeddedClass2(i1).Xint32(i2))
    next 'i2
    a.WriteLine("        instance.EmbeddedClass2("&i1&").Xint64=" & instance.EmbeddedClass2(i1).Xint64)
    next 'i1
next 'instance

a.Close
Wscript.Echo "wmisamp Test Completed, see wmisamp.log for details"
