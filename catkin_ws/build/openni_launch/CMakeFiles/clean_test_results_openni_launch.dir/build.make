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

# Utility rule file for clean_test_results_openni_launch.

# Include the progress variables for this target.
include openni_launch/CMakeFiles/clean_test_results_openni_launch.dir/progress.make

openni_launch/CMakeFiles/clean_test_results_openni_launch:
	cd /home/saurabh/catkin_ws/build/openni_launch && /usr/bin/python /opt/ros/indigo/share/catkin/cmake/test/remove_test_results.py /home/saurabh/catkin_ws/build/test_results/openni_launch

clean_test_results_openni_launch: openni_launch/CMakeFiles/clean_test_results_openni_launch
clean_test_results_openni_launch: openni_launch/CMakeFiles/clean_test_results_openni_launch.dir/build.make
.PHONY : clean_test_results_openni_launch

# Rule to build all files generated by this target.
openni_launch/CMakeFiles/clean_test_results_openni_launch.dir/build: clean_test_results_openni_launch
.PHONY : openni_launch/CMakeFiles/clean_test_results_openni_launch.dir/build

openni_launch/CMakeFiles/clean_test_results_openni_launch.dir/clean:
	cd /home/saurabh/catkin_ws/build/openni_launch && $(CMAKE_COMMAND) -P CMakeFiles/clean_test_results_openni_launch.dir/cmake_clean.cmake
.PHONY : openni_launch/CMakeFiles/clean_test_results_openni_launch.dir/clean

openni_launch/CMakeFiles/clean_test_results_openni_launch.dir/depend:
	cd /home/saurabh/catkin_ws/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/saurabh/catkin_ws/src /home/saurabh/catkin_ws/src/openni_launch /home/saurabh/catkin_ws/build /home/saurabh/catkin_ws/build/openni_launch /home/saurabh/catkin_ws/build/openni_launch/CMakeFiles/clean_test_results_openni_launch.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : openni_launch/CMakeFiles/clean_test_results_openni_launch.dir/depend

