# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/mnt/c/Users/Dvir/dev/AUCourse/final project/toBits"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/mnt/c/Users/Dvir/dev/AUCourse/final project/toBits/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/toBits.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/toBits.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/toBits.dir/flags.make

CMakeFiles/toBits.dir/main.cpp.o: CMakeFiles/toBits.dir/flags.make
CMakeFiles/toBits.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/c/Users/Dvir/dev/AUCourse/final project/toBits/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/toBits.dir/main.cpp.o"
	/usr/bin/clang++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/toBits.dir/main.cpp.o -c "/mnt/c/Users/Dvir/dev/AUCourse/final project/toBits/main.cpp"

CMakeFiles/toBits.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/toBits.dir/main.cpp.i"
	/usr/bin/clang++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/mnt/c/Users/Dvir/dev/AUCourse/final project/toBits/main.cpp" > CMakeFiles/toBits.dir/main.cpp.i

CMakeFiles/toBits.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/toBits.dir/main.cpp.s"
	/usr/bin/clang++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/mnt/c/Users/Dvir/dev/AUCourse/final project/toBits/main.cpp" -o CMakeFiles/toBits.dir/main.cpp.s

# Object files for target toBits
toBits_OBJECTS = \
"CMakeFiles/toBits.dir/main.cpp.o"

# External object files for target toBits
toBits_EXTERNAL_OBJECTS =

toBits: CMakeFiles/toBits.dir/main.cpp.o
toBits: CMakeFiles/toBits.dir/build.make
toBits: CMakeFiles/toBits.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/mnt/c/Users/Dvir/dev/AUCourse/final project/toBits/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable toBits"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/toBits.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/toBits.dir/build: toBits

.PHONY : CMakeFiles/toBits.dir/build

CMakeFiles/toBits.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/toBits.dir/cmake_clean.cmake
.PHONY : CMakeFiles/toBits.dir/clean

CMakeFiles/toBits.dir/depend:
	cd "/mnt/c/Users/Dvir/dev/AUCourse/final project/toBits/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/mnt/c/Users/Dvir/dev/AUCourse/final project/toBits" "/mnt/c/Users/Dvir/dev/AUCourse/final project/toBits" "/mnt/c/Users/Dvir/dev/AUCourse/final project/toBits/cmake-build-debug" "/mnt/c/Users/Dvir/dev/AUCourse/final project/toBits/cmake-build-debug" "/mnt/c/Users/Dvir/dev/AUCourse/final project/toBits/cmake-build-debug/CMakeFiles/toBits.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/toBits.dir/depend

