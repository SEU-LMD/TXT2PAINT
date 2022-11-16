# 1.Prerequisites

Ubuntu 64-bit 16.04

# 2.Clone the repository

**Clone the repository :**

```
git clone https://github.com/SEU-LMD/TXT2PAINT.git
```

**Noted:**

注意在将文件clone到本地后，首先更改/python-2.7/python2.7/pyconfig.h中的文件路径，该文件是去找寻/x86_64-linux-gnu/python2.7/pyconfig.h这个文件，如图所示的文件路径为:

```
“/home/wxy/draw/x86_64-linux-gnu/python2.7/pyconfig.h”
```
![](README.assets/1.PNG)

# 3.Build and Run

## 3.1 Genetate dynamic link libraries

1.Modify CMakeLists.txt file as shown in the figure to generate an  file "liotest.so" by callpythondraw.cpp .

![](README.assets/so.PNG)

## 3.2 Run through the libtest.so file

1.Modify CMakeLists.txt file as shown in the figure to generate an executable file "runpy" by main.cpp .

![](README.assets/run-16684871027642.PNG)

2.Build and Run the executable runpy

```
mkdir build
cd build
cmake ..
make
cd ..
./runpy
```

