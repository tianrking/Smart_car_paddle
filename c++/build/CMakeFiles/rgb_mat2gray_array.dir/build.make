# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_SOURCE_DIR = /root/workspace/SmartCarToolKits/c++

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /root/workspace/SmartCarToolKits/c++/build

# Include any dependencies generated for this target.
include CMakeFiles/rgb_mat2gray_array.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/rgb_mat2gray_array.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/rgb_mat2gray_array.dir/flags.make

CMakeFiles/rgb_mat2gray_array.dir/demo/rgb_mat2gray_array.cpp.o: CMakeFiles/rgb_mat2gray_array.dir/flags.make
CMakeFiles/rgb_mat2gray_array.dir/demo/rgb_mat2gray_array.cpp.o: ../demo/rgb_mat2gray_array.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/workspace/SmartCarToolKits/c++/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/rgb_mat2gray_array.dir/demo/rgb_mat2gray_array.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/rgb_mat2gray_array.dir/demo/rgb_mat2gray_array.cpp.o -c /root/workspace/SmartCarToolKits/c++/demo/rgb_mat2gray_array.cpp

CMakeFiles/rgb_mat2gray_array.dir/demo/rgb_mat2gray_array.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/rgb_mat2gray_array.dir/demo/rgb_mat2gray_array.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/workspace/SmartCarToolKits/c++/demo/rgb_mat2gray_array.cpp > CMakeFiles/rgb_mat2gray_array.dir/demo/rgb_mat2gray_array.cpp.i

CMakeFiles/rgb_mat2gray_array.dir/demo/rgb_mat2gray_array.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/rgb_mat2gray_array.dir/demo/rgb_mat2gray_array.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/workspace/SmartCarToolKits/c++/demo/rgb_mat2gray_array.cpp -o CMakeFiles/rgb_mat2gray_array.dir/demo/rgb_mat2gray_array.cpp.s

CMakeFiles/rgb_mat2gray_array.dir/demo/rgb_mat2gray_array.cpp.o.requires:

.PHONY : CMakeFiles/rgb_mat2gray_array.dir/demo/rgb_mat2gray_array.cpp.o.requires

CMakeFiles/rgb_mat2gray_array.dir/demo/rgb_mat2gray_array.cpp.o.provides: CMakeFiles/rgb_mat2gray_array.dir/demo/rgb_mat2gray_array.cpp.o.requires
	$(MAKE) -f CMakeFiles/rgb_mat2gray_array.dir/build.make CMakeFiles/rgb_mat2gray_array.dir/demo/rgb_mat2gray_array.cpp.o.provides.build
.PHONY : CMakeFiles/rgb_mat2gray_array.dir/demo/rgb_mat2gray_array.cpp.o.provides

CMakeFiles/rgb_mat2gray_array.dir/demo/rgb_mat2gray_array.cpp.o.provides.build: CMakeFiles/rgb_mat2gray_array.dir/demo/rgb_mat2gray_array.cpp.o


# Object files for target rgb_mat2gray_array
rgb_mat2gray_array_OBJECTS = \
"CMakeFiles/rgb_mat2gray_array.dir/demo/rgb_mat2gray_array.cpp.o"

# External object files for target rgb_mat2gray_array
rgb_mat2gray_array_EXTERNAL_OBJECTS =

rgb_mat2gray_array: CMakeFiles/rgb_mat2gray_array.dir/demo/rgb_mat2gray_array.cpp.o
rgb_mat2gray_array: CMakeFiles/rgb_mat2gray_array.dir/build.make
rgb_mat2gray_array: /usr/local/lib/libopencv_dnn.so.3.4.3
rgb_mat2gray_array: /usr/local/lib/libopencv_ml.so.3.4.3
rgb_mat2gray_array: /usr/local/lib/libopencv_objdetect.so.3.4.3
rgb_mat2gray_array: /usr/local/lib/libopencv_shape.so.3.4.3
rgb_mat2gray_array: /usr/local/lib/libopencv_stitching.so.3.4.3
rgb_mat2gray_array: /usr/local/lib/libopencv_superres.so.3.4.3
rgb_mat2gray_array: /usr/local/lib/libopencv_videostab.so.3.4.3
rgb_mat2gray_array: /usr/local/lib/libopencv_calib3d.so.3.4.3
rgb_mat2gray_array: /usr/local/lib/libopencv_features2d.so.3.4.3
rgb_mat2gray_array: /usr/local/lib/libopencv_flann.so.3.4.3
rgb_mat2gray_array: /usr/local/lib/libopencv_highgui.so.3.4.3
rgb_mat2gray_array: /usr/local/lib/libopencv_photo.so.3.4.3
rgb_mat2gray_array: /usr/local/lib/libopencv_video.so.3.4.3
rgb_mat2gray_array: /usr/local/lib/libopencv_videoio.so.3.4.3
rgb_mat2gray_array: /usr/local/lib/libopencv_imgcodecs.so.3.4.3
rgb_mat2gray_array: /usr/local/lib/libopencv_imgproc.so.3.4.3
rgb_mat2gray_array: /usr/local/lib/libopencv_core.so.3.4.3
rgb_mat2gray_array: CMakeFiles/rgb_mat2gray_array.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/root/workspace/SmartCarToolKits/c++/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable rgb_mat2gray_array"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/rgb_mat2gray_array.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/rgb_mat2gray_array.dir/build: rgb_mat2gray_array

.PHONY : CMakeFiles/rgb_mat2gray_array.dir/build

CMakeFiles/rgb_mat2gray_array.dir/requires: CMakeFiles/rgb_mat2gray_array.dir/demo/rgb_mat2gray_array.cpp.o.requires

.PHONY : CMakeFiles/rgb_mat2gray_array.dir/requires

CMakeFiles/rgb_mat2gray_array.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/rgb_mat2gray_array.dir/cmake_clean.cmake
.PHONY : CMakeFiles/rgb_mat2gray_array.dir/clean

CMakeFiles/rgb_mat2gray_array.dir/depend:
	cd /root/workspace/SmartCarToolKits/c++/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /root/workspace/SmartCarToolKits/c++ /root/workspace/SmartCarToolKits/c++ /root/workspace/SmartCarToolKits/c++/build /root/workspace/SmartCarToolKits/c++/build /root/workspace/SmartCarToolKits/c++/build/CMakeFiles/rgb_mat2gray_array.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/rgb_mat2gray_array.dir/depend

