# Instruction

In this package, we use this project to convert "txt" files obtained by laser algorithms into trajectories of pose.

目标：通过test1.cpp生成libtest.so,然后通过main.cpp为测试文件，测试.so文件和test.h是否可以调用。

Now:通过test2.cpp生成runpy的可执行文件，判断test1.cpp和exercise1.cpp是否调用成功和传参成功。

其中exercise2.py是先前直接读取“07.txt"文件，exercise1.py是传参后的py文件。



# 1.Prerequisites

## 1.1 Ubuntu 

  Ubuntu 64-bit  18.04.

# 2 Install 

Clone the source code for the project .Before build the project, please rewrite the paths of  include_directories and LINK_DIRECTORIES in CMakeLists.txt.

```
git clone https://github.com/WXY485/PAINT.git
cd ..
mkdir build
cd build
cmake ..
make
```

# 3 RUN

Move the executable file runpy to the same directory as the txt and exercise.py files.Then we can  run the executable file to get the graph.

```
sudo mv runpy /home/users/project/
./runpy exercise1 paint
```