# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.9

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2017.3\bin\cmake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2017.3\bin\cmake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\JP Bulman\Desktop\Mini-Projs\C\MyFirstCProject"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\JP Bulman\Desktop\Mini-Projs\C\MyFirstCProject\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/MyFirstCProject.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/MyFirstCProject.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/MyFirstCProject.dir/flags.make

CMakeFiles/MyFirstCProject.dir/main.c.obj: CMakeFiles/MyFirstCProject.dir/flags.make
CMakeFiles/MyFirstCProject.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\JP Bulman\Desktop\Mini-Projs\C\MyFirstCProject\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/MyFirstCProject.dir/main.c.obj"
	C:\PROGRA~2\MINGW-~1\I686-7~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\MyFirstCProject.dir\main.c.obj   -c "C:\Users\JP Bulman\Desktop\Mini-Projs\C\MyFirstCProject\main.c"

CMakeFiles/MyFirstCProject.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/MyFirstCProject.dir/main.c.i"
	C:\PROGRA~2\MINGW-~1\I686-7~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\JP Bulman\Desktop\Mini-Projs\C\MyFirstCProject\main.c" > CMakeFiles\MyFirstCProject.dir\main.c.i

CMakeFiles/MyFirstCProject.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/MyFirstCProject.dir/main.c.s"
	C:\PROGRA~2\MINGW-~1\I686-7~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\Users\JP Bulman\Desktop\Mini-Projs\C\MyFirstCProject\main.c" -o CMakeFiles\MyFirstCProject.dir\main.c.s

CMakeFiles/MyFirstCProject.dir/main.c.obj.requires:

.PHONY : CMakeFiles/MyFirstCProject.dir/main.c.obj.requires

CMakeFiles/MyFirstCProject.dir/main.c.obj.provides: CMakeFiles/MyFirstCProject.dir/main.c.obj.requires
	$(MAKE) -f CMakeFiles\MyFirstCProject.dir\build.make CMakeFiles/MyFirstCProject.dir/main.c.obj.provides.build
.PHONY : CMakeFiles/MyFirstCProject.dir/main.c.obj.provides

CMakeFiles/MyFirstCProject.dir/main.c.obj.provides.build: CMakeFiles/MyFirstCProject.dir/main.c.obj


# Object files for target MyFirstCProject
MyFirstCProject_OBJECTS = \
"CMakeFiles/MyFirstCProject.dir/main.c.obj"

# External object files for target MyFirstCProject
MyFirstCProject_EXTERNAL_OBJECTS =

MyFirstCProject.exe: CMakeFiles/MyFirstCProject.dir/main.c.obj
MyFirstCProject.exe: CMakeFiles/MyFirstCProject.dir/build.make
MyFirstCProject.exe: CMakeFiles/MyFirstCProject.dir/linklibs.rsp
MyFirstCProject.exe: CMakeFiles/MyFirstCProject.dir/objects1.rsp
MyFirstCProject.exe: CMakeFiles/MyFirstCProject.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\JP Bulman\Desktop\Mini-Projs\C\MyFirstCProject\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable MyFirstCProject.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\MyFirstCProject.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/MyFirstCProject.dir/build: MyFirstCProject.exe

.PHONY : CMakeFiles/MyFirstCProject.dir/build

CMakeFiles/MyFirstCProject.dir/requires: CMakeFiles/MyFirstCProject.dir/main.c.obj.requires

.PHONY : CMakeFiles/MyFirstCProject.dir/requires

CMakeFiles/MyFirstCProject.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\MyFirstCProject.dir\cmake_clean.cmake
.PHONY : CMakeFiles/MyFirstCProject.dir/clean

CMakeFiles/MyFirstCProject.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\JP Bulman\Desktop\Mini-Projs\C\MyFirstCProject" "C:\Users\JP Bulman\Desktop\Mini-Projs\C\MyFirstCProject" "C:\Users\JP Bulman\Desktop\Mini-Projs\C\MyFirstCProject\cmake-build-debug" "C:\Users\JP Bulman\Desktop\Mini-Projs\C\MyFirstCProject\cmake-build-debug" "C:\Users\JP Bulman\Desktop\Mini-Projs\C\MyFirstCProject\cmake-build-debug\CMakeFiles\MyFirstCProject.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/MyFirstCProject.dir/depend

