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
CMAKE_COMMAND = /home/gnkit/lib/cmake/4.0.0/bin/cmake

# The command to remove a file.
RM = /home/gnkit/lib/cmake/4.0.0/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/gnkit/kadai/B4task4

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/gnkit/kadai/B4task4/build

# Include any dependencies generated for this target.
include CMakeFiles/Laplace.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Laplace.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Laplace.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Laplace.dir/flags.make

CMakeFiles/Laplace.dir/codegen:
.PHONY : CMakeFiles/Laplace.dir/codegen

CMakeFiles/Laplace.dir/src/Laplace.cpp.o: CMakeFiles/Laplace.dir/flags.make
CMakeFiles/Laplace.dir/src/Laplace.cpp.o: /home/gnkit/kadai/B4task4/src/Laplace.cpp
CMakeFiles/Laplace.dir/src/Laplace.cpp.o: CMakeFiles/Laplace.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/gnkit/kadai/B4task4/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Laplace.dir/src/Laplace.cpp.o"
	/opt/intel/oneapi/compiler/2025.1/bin/icpx $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Laplace.dir/src/Laplace.cpp.o -MF CMakeFiles/Laplace.dir/src/Laplace.cpp.o.d -o CMakeFiles/Laplace.dir/src/Laplace.cpp.o -c /home/gnkit/kadai/B4task4/src/Laplace.cpp

CMakeFiles/Laplace.dir/src/Laplace.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Laplace.dir/src/Laplace.cpp.i"
	/opt/intel/oneapi/compiler/2025.1/bin/icpx $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/gnkit/kadai/B4task4/src/Laplace.cpp > CMakeFiles/Laplace.dir/src/Laplace.cpp.i

CMakeFiles/Laplace.dir/src/Laplace.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Laplace.dir/src/Laplace.cpp.s"
	/opt/intel/oneapi/compiler/2025.1/bin/icpx $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/gnkit/kadai/B4task4/src/Laplace.cpp -o CMakeFiles/Laplace.dir/src/Laplace.cpp.s

CMakeFiles/Laplace.dir/src/main.cpp.o: CMakeFiles/Laplace.dir/flags.make
CMakeFiles/Laplace.dir/src/main.cpp.o: /home/gnkit/kadai/B4task4/src/main.cpp
CMakeFiles/Laplace.dir/src/main.cpp.o: CMakeFiles/Laplace.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/gnkit/kadai/B4task4/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Laplace.dir/src/main.cpp.o"
	/opt/intel/oneapi/compiler/2025.1/bin/icpx $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Laplace.dir/src/main.cpp.o -MF CMakeFiles/Laplace.dir/src/main.cpp.o.d -o CMakeFiles/Laplace.dir/src/main.cpp.o -c /home/gnkit/kadai/B4task4/src/main.cpp

CMakeFiles/Laplace.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Laplace.dir/src/main.cpp.i"
	/opt/intel/oneapi/compiler/2025.1/bin/icpx $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/gnkit/kadai/B4task4/src/main.cpp > CMakeFiles/Laplace.dir/src/main.cpp.i

CMakeFiles/Laplace.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Laplace.dir/src/main.cpp.s"
	/opt/intel/oneapi/compiler/2025.1/bin/icpx $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/gnkit/kadai/B4task4/src/main.cpp -o CMakeFiles/Laplace.dir/src/main.cpp.s

# Object files for target Laplace
Laplace_OBJECTS = \
"CMakeFiles/Laplace.dir/src/Laplace.cpp.o" \
"CMakeFiles/Laplace.dir/src/main.cpp.o"

# External object files for target Laplace
Laplace_EXTERNAL_OBJECTS =

Laplace: CMakeFiles/Laplace.dir/src/Laplace.cpp.o
Laplace: CMakeFiles/Laplace.dir/src/main.cpp.o
Laplace: CMakeFiles/Laplace.dir/build.make
Laplace: CMakeFiles/Laplace.dir/compiler_depend.ts
Laplace: CMakeFiles/Laplace.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/gnkit/kadai/B4task4/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable Laplace"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Laplace.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Laplace.dir/build: Laplace
.PHONY : CMakeFiles/Laplace.dir/build

CMakeFiles/Laplace.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Laplace.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Laplace.dir/clean

CMakeFiles/Laplace.dir/depend:
	cd /home/gnkit/kadai/B4task4/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/gnkit/kadai/B4task4 /home/gnkit/kadai/B4task4 /home/gnkit/kadai/B4task4/build /home/gnkit/kadai/B4task4/build /home/gnkit/kadai/B4task4/build/CMakeFiles/Laplace.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/Laplace.dir/depend

