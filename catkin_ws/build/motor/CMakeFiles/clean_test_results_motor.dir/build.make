# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list

# Produce verbose output by default.
VERBOSE = 1

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
CMAKE_SOURCE_DIR = /home/saurabh/catkin_ws/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/saurabh/catkin_ws/build

# Utility rule file for clean_test_results_motor.

# Include the progress variables for this target.
include motor/CMakeFiles/clean_test_results_motor.dir/progress.make

motor/CMakeFiles/clean_test_results_motor:
	cd /home/saurabh/catkin_ws/build/motor && /usr/bin/python /opt/ros/indigo/share/catkin/cmake/test/remove_test_results.py /home/saurabh/catkin_ws/build/test_results/motor

clean_test_results_motor: motor/CMakeFiles/clean_test_results_motor
clean_test_results_motor: motor/CMakeFiles/clean_test_results_motor.dir/build.make
.PHONY : clean_test_results_motor

# Rule to build all files generated by this target.
motor/CMakeFiles/clean_test_results_motor.dir/build: clean_test_results_motor
.PHONY : motor/CMakeFiles/clean_test_results_motor.dir/build

motor/CMakeFiles/clean_test_results_motor.dir/clean:
	cd /home/saurabh/catkin_ws/build/motor && $(CMAKE_COMMAND) -P CMakeFiles/clean_test_results_motor.dir/cmake_clean.cmake
.PHONY : motor/CMakeFiles/clean_test_results_motor.dir/clean

motor/CMakeFiles/clean_test_results_motor.dir/depend:
	cd /home/saurabh/catkin_ws/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/saurabh/catkin_ws/src /home/saurabh/catkin_ws/src/motor /home/saurabh/catkin_ws/build /home/saurabh/catkin_ws/build/motor /home/saurabh/catkin_ws/build/motor/CMakeFiles/clean_test_results_motor.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : motor/CMakeFiles/clean_test_results_motor.dir/depend
