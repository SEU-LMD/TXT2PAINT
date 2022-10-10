cmake_minimum_required( VERSION 2.8 )

project(cppCallPythonFunc)
set(CMAKE_BUILD_TYPE "Debug")
add_compile_options(-std=c++11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")
#set(CMAKE_CXX_STANDARD 14)
 
# 用locate Python.h 取得头文件的位置之后可以使用 #include <Python.h>
include_directories(
   #"${CMAKE_CURRENT_SOURCE_DIR}/include"
   "${CMAKE_CURRENT_SOURCE_DIR}/python-3.5/python3.5"
)

# 添加动态库的位置
LINK_DIRECTORIES(
#"${CMAKE_CURRENT_SOURCE_DIR}/lio"
"${CMAKE_CURRENT_SOURCE_DIR}/python-3.5/python3.5-lio"
)
#LINK_DIRECTORIES("${CURRENT_FOLDER}/lio")
#LINK_DIRECTORIES("/usr/lib")
 
add_executable(runpy callpythondraw.cpp exercise1.py)
target_link_libraries(runpy -lpython3.5m)
#target_link_libraries(runpy -ltest)
#add_library(test SHARED test3.cpp)
#target_link_libraries(test -lpython3.5m)
SET(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR})
#SET(LIBRARY_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR})
