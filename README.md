# Instruction

In this package, we use this project to convert "txt" files obtained by ALOAM and other algorithms into trajectories of pose.

# 1.Prerequisites

## 1.1 Ubuntu and ROS

  Ubuntu 64-bit 16.04 or 18.04.

  ROS Kinetic or Melodic. ROS Installation.

## 1.2 python 3.x

You need to install Python (omitted) and its corresponding class libraries. Tested with Python 3.6.9

```
sudo apt install python3.x-dev
sudo apt install python3-tk
```

## 1.3 matplotlib 

 You need to install the corresponding version of  pip. Tested with pip 21.3.1.

```
wget https；//bootstrap.pypa.io/pip/3.x/get-pip.py
python3.x get-pip.py
```

Then install matplotlib through pip. Tested with matplotlib 3.3.4

```
pip install -i http://pypi.douban.com/simple matplotlib
```

# 2 Build paint

Clone the reposity and build. Before compiling,you need to overwrite the paths of  include_directories and LINK_DIRECTORIES  of  CMakeLists.txt. ALSO the version of python in target_link_libraries.   Then you can perform cmake ..

```
git clone https://github.com/WXY485/PAINT.git
mkdir build
cmake ..
make
```

# 3 RUN

```
./runpy exercise1 paint
```