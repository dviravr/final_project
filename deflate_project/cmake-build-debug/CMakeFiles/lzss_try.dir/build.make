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
CMAKE_SOURCE_DIR = "/mnt/c/Users/Dvir/dev/AUCourse/final project/lzss"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/mnt/c/Users/Dvir/dev/AUCourse/final project/lzss/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/lzss_try.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/lzss_try.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lzss_try.dir/flags.make

CMakeFiles/lzss_try.dir/deflate.c.o: CMakeFiles/lzss_try.dir/flags.make
CMakeFiles/lzss_try.dir/deflate.c.o: ../deflate.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/c/Users/Dvir/dev/AUCourse/final project/lzss/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/lzss_try.dir/deflate.c.o"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/lzss_try.dir/deflate.c.o   -c "/mnt/c/Users/Dvir/dev/AUCourse/final project/lzss/deflate.c"

CMakeFiles/lzss_try.dir/deflate.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lzss_try.dir/deflate.c.i"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/mnt/c/Users/Dvir/dev/AUCourse/final project/lzss/deflate.c" > CMakeFiles/lzss_try.dir/deflate.c.i

CMakeFiles/lzss_try.dir/deflate.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lzss_try.dir/deflate.c.s"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/mnt/c/Users/Dvir/dev/AUCourse/final project/lzss/deflate.c" -o CMakeFiles/lzss_try.dir/deflate.c.s

CMakeFiles/lzss_try.dir/inffast.c.o: CMakeFiles/lzss_try.dir/flags.make
CMakeFiles/lzss_try.dir/inffast.c.o: ../inffast.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/c/Users/Dvir/dev/AUCourse/final project/lzss/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/lzss_try.dir/inffast.c.o"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/lzss_try.dir/inffast.c.o   -c "/mnt/c/Users/Dvir/dev/AUCourse/final project/lzss/inffast.c"

CMakeFiles/lzss_try.dir/inffast.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lzss_try.dir/inffast.c.i"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/mnt/c/Users/Dvir/dev/AUCourse/final project/lzss/inffast.c" > CMakeFiles/lzss_try.dir/inffast.c.i

CMakeFiles/lzss_try.dir/inffast.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lzss_try.dir/inffast.c.s"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/mnt/c/Users/Dvir/dev/AUCourse/final project/lzss/inffast.c" -o CMakeFiles/lzss_try.dir/inffast.c.s

CMakeFiles/lzss_try.dir/inflate.c.o: CMakeFiles/lzss_try.dir/flags.make
CMakeFiles/lzss_try.dir/inflate.c.o: ../inflate.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/c/Users/Dvir/dev/AUCourse/final project/lzss/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/lzss_try.dir/inflate.c.o"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/lzss_try.dir/inflate.c.o   -c "/mnt/c/Users/Dvir/dev/AUCourse/final project/lzss/inflate.c"

CMakeFiles/lzss_try.dir/inflate.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lzss_try.dir/inflate.c.i"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/mnt/c/Users/Dvir/dev/AUCourse/final project/lzss/inflate.c" > CMakeFiles/lzss_try.dir/inflate.c.i

CMakeFiles/lzss_try.dir/inflate.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lzss_try.dir/inflate.c.s"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/mnt/c/Users/Dvir/dev/AUCourse/final project/lzss/inflate.c" -o CMakeFiles/lzss_try.dir/inflate.c.s

CMakeFiles/lzss_try.dir/adler32.c.o: CMakeFiles/lzss_try.dir/flags.make
CMakeFiles/lzss_try.dir/adler32.c.o: ../adler32.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/c/Users/Dvir/dev/AUCourse/final project/lzss/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/lzss_try.dir/adler32.c.o"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/lzss_try.dir/adler32.c.o   -c "/mnt/c/Users/Dvir/dev/AUCourse/final project/lzss/adler32.c"

CMakeFiles/lzss_try.dir/adler32.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lzss_try.dir/adler32.c.i"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/mnt/c/Users/Dvir/dev/AUCourse/final project/lzss/adler32.c" > CMakeFiles/lzss_try.dir/adler32.c.i

CMakeFiles/lzss_try.dir/adler32.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lzss_try.dir/adler32.c.s"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/mnt/c/Users/Dvir/dev/AUCourse/final project/lzss/adler32.c" -o CMakeFiles/lzss_try.dir/adler32.c.s

CMakeFiles/lzss_try.dir/crc32.c.o: CMakeFiles/lzss_try.dir/flags.make
CMakeFiles/lzss_try.dir/crc32.c.o: ../crc32.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/c/Users/Dvir/dev/AUCourse/final project/lzss/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/lzss_try.dir/crc32.c.o"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/lzss_try.dir/crc32.c.o   -c "/mnt/c/Users/Dvir/dev/AUCourse/final project/lzss/crc32.c"

CMakeFiles/lzss_try.dir/crc32.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lzss_try.dir/crc32.c.i"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/mnt/c/Users/Dvir/dev/AUCourse/final project/lzss/crc32.c" > CMakeFiles/lzss_try.dir/crc32.c.i

CMakeFiles/lzss_try.dir/crc32.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lzss_try.dir/crc32.c.s"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/mnt/c/Users/Dvir/dev/AUCourse/final project/lzss/crc32.c" -o CMakeFiles/lzss_try.dir/crc32.c.s

CMakeFiles/lzss_try.dir/trees.c.o: CMakeFiles/lzss_try.dir/flags.make
CMakeFiles/lzss_try.dir/trees.c.o: ../trees.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/c/Users/Dvir/dev/AUCourse/final project/lzss/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/lzss_try.dir/trees.c.o"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/lzss_try.dir/trees.c.o   -c "/mnt/c/Users/Dvir/dev/AUCourse/final project/lzss/trees.c"

CMakeFiles/lzss_try.dir/trees.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lzss_try.dir/trees.c.i"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/mnt/c/Users/Dvir/dev/AUCourse/final project/lzss/trees.c" > CMakeFiles/lzss_try.dir/trees.c.i

CMakeFiles/lzss_try.dir/trees.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lzss_try.dir/trees.c.s"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/mnt/c/Users/Dvir/dev/AUCourse/final project/lzss/trees.c" -o CMakeFiles/lzss_try.dir/trees.c.s

CMakeFiles/lzss_try.dir/inftrees.c.o: CMakeFiles/lzss_try.dir/flags.make
CMakeFiles/lzss_try.dir/inftrees.c.o: ../inftrees.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/c/Users/Dvir/dev/AUCourse/final project/lzss/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_7) "Building C object CMakeFiles/lzss_try.dir/inftrees.c.o"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/lzss_try.dir/inftrees.c.o   -c "/mnt/c/Users/Dvir/dev/AUCourse/final project/lzss/inftrees.c"

CMakeFiles/lzss_try.dir/inftrees.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lzss_try.dir/inftrees.c.i"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/mnt/c/Users/Dvir/dev/AUCourse/final project/lzss/inftrees.c" > CMakeFiles/lzss_try.dir/inftrees.c.i

CMakeFiles/lzss_try.dir/inftrees.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lzss_try.dir/inftrees.c.s"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/mnt/c/Users/Dvir/dev/AUCourse/final project/lzss/inftrees.c" -o CMakeFiles/lzss_try.dir/inftrees.c.s

CMakeFiles/lzss_try.dir/main.c.o: CMakeFiles/lzss_try.dir/flags.make
CMakeFiles/lzss_try.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/c/Users/Dvir/dev/AUCourse/final project/lzss/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_8) "Building C object CMakeFiles/lzss_try.dir/main.c.o"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/lzss_try.dir/main.c.o   -c "/mnt/c/Users/Dvir/dev/AUCourse/final project/lzss/main.c"

CMakeFiles/lzss_try.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lzss_try.dir/main.c.i"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/mnt/c/Users/Dvir/dev/AUCourse/final project/lzss/main.c" > CMakeFiles/lzss_try.dir/main.c.i

CMakeFiles/lzss_try.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lzss_try.dir/main.c.s"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/mnt/c/Users/Dvir/dev/AUCourse/final project/lzss/main.c" -o CMakeFiles/lzss_try.dir/main.c.s

CMakeFiles/lzss_try.dir/zutil.c.o: CMakeFiles/lzss_try.dir/flags.make
CMakeFiles/lzss_try.dir/zutil.c.o: ../zutil.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/c/Users/Dvir/dev/AUCourse/final project/lzss/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_9) "Building C object CMakeFiles/lzss_try.dir/zutil.c.o"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/lzss_try.dir/zutil.c.o   -c "/mnt/c/Users/Dvir/dev/AUCourse/final project/lzss/zutil.c"

CMakeFiles/lzss_try.dir/zutil.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lzss_try.dir/zutil.c.i"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/mnt/c/Users/Dvir/dev/AUCourse/final project/lzss/zutil.c" > CMakeFiles/lzss_try.dir/zutil.c.i

CMakeFiles/lzss_try.dir/zutil.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lzss_try.dir/zutil.c.s"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/mnt/c/Users/Dvir/dev/AUCourse/final project/lzss/zutil.c" -o CMakeFiles/lzss_try.dir/zutil.c.s

# Object files for target lzss_try
lzss_try_OBJECTS = \
"CMakeFiles/lzss_try.dir/deflate.c.o" \
"CMakeFiles/lzss_try.dir/inffast.c.o" \
"CMakeFiles/lzss_try.dir/inflate.c.o" \
"CMakeFiles/lzss_try.dir/adler32.c.o" \
"CMakeFiles/lzss_try.dir/crc32.c.o" \
"CMakeFiles/lzss_try.dir/trees.c.o" \
"CMakeFiles/lzss_try.dir/inftrees.c.o" \
"CMakeFiles/lzss_try.dir/main.c.o" \
"CMakeFiles/lzss_try.dir/zutil.c.o"

# External object files for target lzss_try
lzss_try_EXTERNAL_OBJECTS =

lzss_try: CMakeFiles/lzss_try.dir/deflate.c.o
lzss_try: CMakeFiles/lzss_try.dir/inffast.c.o
lzss_try: CMakeFiles/lzss_try.dir/inflate.c.o
lzss_try: CMakeFiles/lzss_try.dir/adler32.c.o
lzss_try: CMakeFiles/lzss_try.dir/crc32.c.o
lzss_try: CMakeFiles/lzss_try.dir/trees.c.o
lzss_try: CMakeFiles/lzss_try.dir/inftrees.c.o
lzss_try: CMakeFiles/lzss_try.dir/main.c.o
lzss_try: CMakeFiles/lzss_try.dir/zutil.c.o
lzss_try: CMakeFiles/lzss_try.dir/build.make
lzss_try: CMakeFiles/lzss_try.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/mnt/c/Users/Dvir/dev/AUCourse/final project/lzss/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_10) "Linking C executable lzss_try"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lzss_try.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/lzss_try.dir/build: lzss_try

.PHONY : CMakeFiles/lzss_try.dir/build

CMakeFiles/lzss_try.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/lzss_try.dir/cmake_clean.cmake
.PHONY : CMakeFiles/lzss_try.dir/clean

CMakeFiles/lzss_try.dir/depend:
	cd "/mnt/c/Users/Dvir/dev/AUCourse/final project/lzss/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/mnt/c/Users/Dvir/dev/AUCourse/final project/lzss" "/mnt/c/Users/Dvir/dev/AUCourse/final project/lzss" "/mnt/c/Users/Dvir/dev/AUCourse/final project/lzss/cmake-build-debug" "/mnt/c/Users/Dvir/dev/AUCourse/final project/lzss/cmake-build-debug" "/mnt/c/Users/Dvir/dev/AUCourse/final project/lzss/cmake-build-debug/CMakeFiles/lzss_try.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/lzss_try.dir/depend
