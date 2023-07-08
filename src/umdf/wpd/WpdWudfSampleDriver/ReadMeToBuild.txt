Building the WPD driver sample

1.	Install Microsoft Visual Studio 8
2.	Install Windows Driver Kit
3.	Create a new directory under C:\WINDDK\XXXX\inc called "copied_atlmfc"
4.	Create two architecture specific lib directories called "C:\WINDDK\XXXX\lib\copied_atlmfc\i386" and "C:\WINDDK\XXXX\lib\copied_atlmfc\amd64"
5.	Copy the entire contents of C:\WINDDK\XXXX\inc\mfc42 into the newly created "C:\WINDDK\XXXX\inc\copied_atlmfc"
6.	Copy the entire contents of "C:\Program Files\Microsoft Visual Studio 8\VC\atlmfc\include" into the newly created "C:\WINDDK\XXXX\inc\copied_atlmfc" directory
7.	Copy the entire contents of "C:\Program Files\Microsoft Visual Studio 8\VC\atlmfc\lib\*.*" into the newly created "C:\WINDDK\XXXX\lib\copied_atlmfc\i386" directory
8.	If you installed the 64 bit libraries for Visual Studio, copy the entire contents of "C:\Program Files\Microsoft Visual Studio 8\VC\atlmfc\lib\amd64" into the newly created "C:\WINDDK\XXXX\lib\copied_atlmfc\amd64" directory
9.	Launch desired build environment e.g. "Windows Vista and Windows Server 2008 x86 Checked Build Environment" from the start menu
10.	Change the environment variable MFC_INCLUDES to point to the copied_atlmfc directory:
    a.	set MFC_INCLUDES=C:\WINDDK\XXX\inc\copied_atlmfc
    b.	set MFC_LIB_PATH=C:\WINDDK\XXXX\lib\copied_atlmfc\*
11.	Build the sample (e.g. "build -cZ")

Caveats: This ATL8 environment is incompatible with code designed for prior versions of ATL, and vice versa.  This sample & environment are also not applicable for IA64, Windows Server 2003 or Windows 2000.

