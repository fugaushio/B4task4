# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 4.0

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
CMAKE_COMMAND = /home/tatsukawa0353/lib/cmake/4.0.0/bin/cmake

# The command to remove a file.
RM = /home/tatsukawa0353/lib/cmake/4.0.0/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/tatsukawa0353/B4task/B4task4

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/tatsukawa0353/B4task/B4task4/build

# Include any dependencies generated for this target.
include CMakeFiles/HelloWorld.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/HelloWorld.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/HelloWorld.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/HelloWorld.dir/flags.make

CMakeFiles/HelloWorld.dir/codegen:
.PHONY : CMakeFiles/HelloWorld.dir/codegen

CMakeFiles/HelloWorld.dir/src/Greeter.cpp.o: CMakeFiles/HelloWorld.dir/flags.make
CMakeFiles/HelloWorld.dir/src/Greeter.cpp.o: /home/tatsukawa0353/B4task/B4task4/src/Greeter.cpp
CMakeFiles/HelloWorld.dir/src/Greeter.cpp.o: CMakeFiles/HelloWorld.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/tatsukawa0353/B4task/B4task4/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/HelloWorld.dir/src/Greeter.cpp.o"
	/opt/intel/oneapi/compiler/2025.1/bin/icpx $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/HelloWorld.dir/src/Greeter.cpp.o -MF CMakeFiles/HelloWorld.dir/src/Greeter.cpp.o.d -o CMakeFiles/HelloWorld.dir/src/Greeter.cpp.o -c /home/tatsukawa0353/B4task/B4task4/src/Greeter.cpp

CMakeFiles/HelloWorld.dir/src/Greeter.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/HelloWorld.dir/src/Greeter.cpp.i"
	/opt/intel/oneapi/compiler/2025.1/bin/icpx $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tatsukawa0353/B4task/B4task4/src/Greeter.cpp > CMakeFiles/HelloWorld.dir/src/Greeter.cpp.i

CMakeFiles/HelloWorld.dir/src/Greeter.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/HelloWorld.dir/src/Greeter.cpp.s"
	/opt/intel/oneapi/compiler/2025.1/bin/icpx $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tatsukawa0353/B4task/B4task4/src/Greeter.cpp -o CMakeFiles/HelloWorld.dir/src/Greeter.cpp.s

CMakeFiles/HelloWorld.dir/src/main.cpp.o: CMakeFiles/HelloWorld.dir/flags.make
CMakeFiles/HelloWorld.dir/src/main.cpp.o: /home/tatsukawa0353/B4task/B4task4/src/main.cpp
CMakeFiles/HelloWorld.dir/src/main.cpp.o: CMakeFiles/HelloWorld.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/tatsukawa0353/B4task/B4task4/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/HelloWorld.dir/src/main.cpp.o"
	/opt/intel/oneapi/compiler/2025.1/bin/icpx $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/HelloWorld.dir/src/main.cpp.o -MF CMakeFiles/HelloWorld.dir/src/main.cpp.o.d -o CMakeFiles/HelloWorld.dir/src/main.cpp.o -c /home/tatsukawa0353/B4task/B4task4/src/main.cpp

CMakeFiles/HelloWorld.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/HelloWorld.dir/src/main.cpp.i"
	/opt/intel/oneapi/compiler/2025.1/bin/icpx $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tatsukawa0353/B4task/B4task4/src/main.cpp > CMakeFiles/HelloWorld.dir/src/main.cpp.i

CMakeFiles/HelloWorld.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/HelloWorld.dir/src/main.cpp.s"
	/opt/intel/oneapi/compiler/2025.1/bin/icpx $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tatsukawa0353/B4task/B4task4/src/main.cpp -o CMakeFiles/HelloWorld.dir/src/main.cpp.s

# Object files for target HelloWorld
HelloWorld_OBJECTS = \
"CMakeFiles/HelloWorld.dir/src/Greeter.cpp.o" \
"CMakeFiles/HelloWorld.dir/src/main.cpp.o"

# External object files for target HelloWorld
HelloWorld_EXTERNAL_OBJECTS =

HelloWorld: CMakeFiles/HelloWorld.dir/src/Greeter.cpp.o
HelloWorld: CMakeFiles/HelloWorld.dir/src/main.cpp.o
HelloWorld: CMakeFiles/HelloWorld.dir/build.make
HelloWorld: CMakeFiles/HelloWorld.dir/compiler_depend.ts
HelloWorld: CMakeFiles/HelloWorld.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/tatsukawa0353/B4task/B4task4/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable HelloWorld"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/HelloWorld.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/HelloWorld.dir/build: HelloWorld
.PHONY : CMakeFiles/HelloWorld.dir/build

CMakeFiles/HelloWorld.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/HelloWorld.dir/cmake_clean.cmake
.PHONY : CMakeFiles/HelloWorld.dir/clean

CMakeFiles/HelloWorld.dir/depend:
	cd /home/tatsukawa0353/B4task/B4task4/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/tatsukawa0353/B4task/B4task4 /home/tatsukawa0353/B4task/B4task4 /home/tatsukawa0353/B4task/B4task4/build /home/tatsukawa0353/B4task/B4task4/build /home/tatsukawa0353/B4task/B4task4/build/CMakeFiles/HelloWorld.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/HelloWorld.dir/depend

