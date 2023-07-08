WDK 1.1.6001.000
================

### Windows Driver Kit for Windows 2000 - Windows 7
I sometimes still build my projects with this old WDK. I like small binaries and compatibility for Windows 2000 through Windows 7.
This is a bit modified version of the WDK, as the original one doesn't contain some headers that are often needed.

### How to use
This WDK doesn't need to be installed. Just clone the repository comewhere and set your WDKDIR variable to that folder
1) Clone the repository
```
git clone https://github.com/ladislav-zezula/WDK_6001.git
```

2) Set the WDKDIR environment variable so that points to the directory where the WDK is located
```
set WDKDIR=C:\SDK\WDK_6001
```

### Building a project with WDK
As an example, ![FileTest](https://github.com/ladislav-zezula/FileTest) project can be built with this WDK.
0) Do the steps in the above paragraph

1) Clone the FileTest repository
```
git clone https://github.com/ladislav-zezula/FileTest.git
```
2) Build it
```
make.bat
```
That's all you need :-)