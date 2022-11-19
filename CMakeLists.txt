cmake_minimum_required( VERSION 2.8 )
project(cppCallPythonFunc)
set(CMAKE_BUILD_TYPE "Release")
#set(CMAKE_BUILD_TYPE "Debug")

#add_compile_options(-std=c++11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")
set(CMAKE_CXX_STANDARD 11)

# 用locate Python.h 取得头文件的位置之后可以使用 #include <Python.h>
include_directories(
                   "${CMAKE_CURRENT_SOURCE_DIR}/internal"
                   "${CMAKE_CURRENT_SOURCE_DIR}/python-2.7/python2.7"
)

set(CURPATH ${CMAKE_CURRENT_SOURCE_DIR}/internal/)#for genenrate config.h file
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/internal/config.h.in ${CMAKE_CURRENT_SOURCE_DIR}/internal/config.h)

SET(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR})
add_executable(test ${CMAKE_CURRENT_SOURCE_DIR}/example/test.cpp)
target_link_libraries(test "${CMAKE_CURRENT_SOURCE_DIR}/python-2.7/python2.7-lio/libpython2.7.so")

