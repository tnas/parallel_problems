# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_SOURCE_DIR = /home/thiago/projects/parallel_samples

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/thiago/projects/parallel_samples/build

# Include any dependencies generated for this target.
include CMakeFiles/parallel_samples.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/parallel_samples.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/parallel_samples.dir/flags.make

CMakeFiles/parallel_samples.dir/main.c.o: CMakeFiles/parallel_samples.dir/flags.make
CMakeFiles/parallel_samples.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/thiago/projects/parallel_samples/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/parallel_samples.dir/main.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/parallel_samples.dir/main.c.o   -c /home/thiago/projects/parallel_samples/main.c

CMakeFiles/parallel_samples.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/parallel_samples.dir/main.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/thiago/projects/parallel_samples/main.c > CMakeFiles/parallel_samples.dir/main.c.i

CMakeFiles/parallel_samples.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/parallel_samples.dir/main.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/thiago/projects/parallel_samples/main.c -o CMakeFiles/parallel_samples.dir/main.c.s

CMakeFiles/parallel_samples.dir/main.c.o.requires:

.PHONY : CMakeFiles/parallel_samples.dir/main.c.o.requires

CMakeFiles/parallel_samples.dir/main.c.o.provides: CMakeFiles/parallel_samples.dir/main.c.o.requires
	$(MAKE) -f CMakeFiles/parallel_samples.dir/build.make CMakeFiles/parallel_samples.dir/main.c.o.provides.build
.PHONY : CMakeFiles/parallel_samples.dir/main.c.o.provides

CMakeFiles/parallel_samples.dir/main.c.o.provides.build: CMakeFiles/parallel_samples.dir/main.c.o


CMakeFiles/parallel_samples.dir/samples/sum_vector.c.o: CMakeFiles/parallel_samples.dir/flags.make
CMakeFiles/parallel_samples.dir/samples/sum_vector.c.o: ../samples/sum_vector.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/thiago/projects/parallel_samples/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/parallel_samples.dir/samples/sum_vector.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/parallel_samples.dir/samples/sum_vector.c.o   -c /home/thiago/projects/parallel_samples/samples/sum_vector.c

CMakeFiles/parallel_samples.dir/samples/sum_vector.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/parallel_samples.dir/samples/sum_vector.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/thiago/projects/parallel_samples/samples/sum_vector.c > CMakeFiles/parallel_samples.dir/samples/sum_vector.c.i

CMakeFiles/parallel_samples.dir/samples/sum_vector.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/parallel_samples.dir/samples/sum_vector.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/thiago/projects/parallel_samples/samples/sum_vector.c -o CMakeFiles/parallel_samples.dir/samples/sum_vector.c.s

CMakeFiles/parallel_samples.dir/samples/sum_vector.c.o.requires:

.PHONY : CMakeFiles/parallel_samples.dir/samples/sum_vector.c.o.requires

CMakeFiles/parallel_samples.dir/samples/sum_vector.c.o.provides: CMakeFiles/parallel_samples.dir/samples/sum_vector.c.o.requires
	$(MAKE) -f CMakeFiles/parallel_samples.dir/build.make CMakeFiles/parallel_samples.dir/samples/sum_vector.c.o.provides.build
.PHONY : CMakeFiles/parallel_samples.dir/samples/sum_vector.c.o.provides

CMakeFiles/parallel_samples.dir/samples/sum_vector.c.o.provides.build: CMakeFiles/parallel_samples.dir/samples/sum_vector.c.o


# Object files for target parallel_samples
parallel_samples_OBJECTS = \
"CMakeFiles/parallel_samples.dir/main.c.o" \
"CMakeFiles/parallel_samples.dir/samples/sum_vector.c.o"

# External object files for target parallel_samples
parallel_samples_EXTERNAL_OBJECTS =

parallel_samples: CMakeFiles/parallel_samples.dir/main.c.o
parallel_samples: CMakeFiles/parallel_samples.dir/samples/sum_vector.c.o
parallel_samples: CMakeFiles/parallel_samples.dir/build.make
parallel_samples: CMakeFiles/parallel_samples.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/thiago/projects/parallel_samples/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable parallel_samples"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/parallel_samples.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/parallel_samples.dir/build: parallel_samples

.PHONY : CMakeFiles/parallel_samples.dir/build

CMakeFiles/parallel_samples.dir/requires: CMakeFiles/parallel_samples.dir/main.c.o.requires
CMakeFiles/parallel_samples.dir/requires: CMakeFiles/parallel_samples.dir/samples/sum_vector.c.o.requires

.PHONY : CMakeFiles/parallel_samples.dir/requires

CMakeFiles/parallel_samples.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/parallel_samples.dir/cmake_clean.cmake
.PHONY : CMakeFiles/parallel_samples.dir/clean

CMakeFiles/parallel_samples.dir/depend:
	cd /home/thiago/projects/parallel_samples/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/thiago/projects/parallel_samples /home/thiago/projects/parallel_samples /home/thiago/projects/parallel_samples/build /home/thiago/projects/parallel_samples/build /home/thiago/projects/parallel_samples/build/CMakeFiles/parallel_samples.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/parallel_samples.dir/depend

