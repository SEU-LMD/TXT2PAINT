# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.23

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\clion\CLion 2022.2.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\clion\CLion 2022.2.3\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\29390\Desktop\2\TXT2PAINT

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\29390\Desktop\2\TXT2PAINT\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/runpy.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/runpy.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/runpy.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/runpy.dir/flags.make

CMakeFiles/runpy.dir/callpythondraw.cpp.obj: CMakeFiles/runpy.dir/flags.make
CMakeFiles/runpy.dir/callpythondraw.cpp.obj: CMakeFiles/runpy.dir/includes_CXX.rsp
CMakeFiles/runpy.dir/callpythondraw.cpp.obj: ../callpythondraw.cpp
CMakeFiles/runpy.dir/callpythondraw.cpp.obj: CMakeFiles/runpy.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\29390\Desktop\2\TXT2PAINT\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/runpy.dir/callpythondraw.cpp.obj"
	D:\clion\CLION2~1.3\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/runpy.dir/callpythondraw.cpp.obj -MF CMakeFiles\runpy.dir\callpythondraw.cpp.obj.d -o CMakeFiles\runpy.dir\callpythondraw.cpp.obj -c C:\Users\29390\Desktop\2\TXT2PAINT\callpythondraw.cpp

CMakeFiles/runpy.dir/callpythondraw.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/runpy.dir/callpythondraw.cpp.i"
	D:\clion\CLION2~1.3\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\29390\Desktop\2\TXT2PAINT\callpythondraw.cpp > CMakeFiles\runpy.dir\callpythondraw.cpp.i

CMakeFiles/runpy.dir/callpythondraw.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/runpy.dir/callpythondraw.cpp.s"
	D:\clion\CLION2~1.3\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\29390\Desktop\2\TXT2PAINT\callpythondraw.cpp -o CMakeFiles\runpy.dir\callpythondraw.cpp.s

# Object files for target runpy
runpy_OBJECTS = \
"CMakeFiles/runpy.dir/callpythondraw.cpp.obj"

# External object files for target runpy
runpy_EXTERNAL_OBJECTS =

../runpy.exe: CMakeFiles/runpy.dir/callpythondraw.cpp.obj
../runpy.exe: CMakeFiles/runpy.dir/build.make
../runpy.exe: CMakeFiles/runpy.dir/linklibs.rsp
../runpy.exe: CMakeFiles/runpy.dir/objects1.rsp
../runpy.exe: CMakeFiles/runpy.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\29390\Desktop\2\TXT2PAINT\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ..\runpy.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\runpy.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/runpy.dir/build: ../runpy.exe
.PHONY : CMakeFiles/runpy.dir/build

CMakeFiles/runpy.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\runpy.dir\cmake_clean.cmake
.PHONY : CMakeFiles/runpy.dir/clean

CMakeFiles/runpy.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\29390\Desktop\2\TXT2PAINT C:\Users\29390\Desktop\2\TXT2PAINT C:\Users\29390\Desktop\2\TXT2PAINT\cmake-build-debug C:\Users\29390\Desktop\2\TXT2PAINT\cmake-build-debug C:\Users\29390\Desktop\2\TXT2PAINT\cmake-build-debug\CMakeFiles\runpy.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/runpy.dir/depend
