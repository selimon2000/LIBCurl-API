# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.26

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /home/selimon/.local/lib/python3.8/site-packages/cmake/data/bin/cmake

# The command to remove a file.
RM = /home/selimon/.local/lib/python3.8/site-packages/cmake/data/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/selimon/Desktop/LibCurl API"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/selimon/Desktop/LibCurl API/build"

# Include any dependencies generated for this target.
include CMakeFiles/your_executable_name_2.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/your_executable_name_2.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/your_executable_name_2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/your_executable_name_2.dir/flags.make

CMakeFiles/your_executable_name_2.dir/parse_json.cpp.o: CMakeFiles/your_executable_name_2.dir/flags.make
CMakeFiles/your_executable_name_2.dir/parse_json.cpp.o: /home/selimon/Desktop/LibCurl\ API/parse_json.cpp
CMakeFiles/your_executable_name_2.dir/parse_json.cpp.o: CMakeFiles/your_executable_name_2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/selimon/Desktop/LibCurl API/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/your_executable_name_2.dir/parse_json.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/your_executable_name_2.dir/parse_json.cpp.o -MF CMakeFiles/your_executable_name_2.dir/parse_json.cpp.o.d -o CMakeFiles/your_executable_name_2.dir/parse_json.cpp.o -c "/home/selimon/Desktop/LibCurl API/parse_json.cpp"

CMakeFiles/your_executable_name_2.dir/parse_json.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/your_executable_name_2.dir/parse_json.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/selimon/Desktop/LibCurl API/parse_json.cpp" > CMakeFiles/your_executable_name_2.dir/parse_json.cpp.i

CMakeFiles/your_executable_name_2.dir/parse_json.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/your_executable_name_2.dir/parse_json.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/selimon/Desktop/LibCurl API/parse_json.cpp" -o CMakeFiles/your_executable_name_2.dir/parse_json.cpp.s

# Object files for target your_executable_name_2
your_executable_name_2_OBJECTS = \
"CMakeFiles/your_executable_name_2.dir/parse_json.cpp.o"

# External object files for target your_executable_name_2
your_executable_name_2_EXTERNAL_OBJECTS =

your_executable_name_2: CMakeFiles/your_executable_name_2.dir/parse_json.cpp.o
your_executable_name_2: CMakeFiles/your_executable_name_2.dir/build.make
your_executable_name_2: /usr/lib/x86_64-linux-gnu/libcurl.so
your_executable_name_2: CMakeFiles/your_executable_name_2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/selimon/Desktop/LibCurl API/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable your_executable_name_2"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/your_executable_name_2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/your_executable_name_2.dir/build: your_executable_name_2
.PHONY : CMakeFiles/your_executable_name_2.dir/build

CMakeFiles/your_executable_name_2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/your_executable_name_2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/your_executable_name_2.dir/clean

CMakeFiles/your_executable_name_2.dir/depend:
	cd "/home/selimon/Desktop/LibCurl API/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/selimon/Desktop/LibCurl API" "/home/selimon/Desktop/LibCurl API" "/home/selimon/Desktop/LibCurl API/build" "/home/selimon/Desktop/LibCurl API/build" "/home/selimon/Desktop/LibCurl API/build/CMakeFiles/your_executable_name_2.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/your_executable_name_2.dir/depend
