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
CMAKE_SOURCE_DIR = /media/root/Data/Desktop/Smart_car_paddle-main/c++

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /media/root/Data/Desktop/Smart_car_paddle-main/c++/build

# Include any dependencies generated for this target.
include CMakeFiles/q.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/q.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/q.dir/flags.make

CMakeFiles/q.dir/demo/q.cpp.o: CMakeFiles/q.dir/flags.make
CMakeFiles/q.dir/demo/q.cpp.o: ../demo/q.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/media/root/Data/Desktop/Smart_car_paddle-main/c++/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/q.dir/demo/q.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/q.dir/demo/q.cpp.o -c /media/root/Data/Desktop/Smart_car_paddle-main/c++/demo/q.cpp

CMakeFiles/q.dir/demo/q.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/q.dir/demo/q.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /media/root/Data/Desktop/Smart_car_paddle-main/c++/demo/q.cpp > CMakeFiles/q.dir/demo/q.cpp.i

CMakeFiles/q.dir/demo/q.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/q.dir/demo/q.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /media/root/Data/Desktop/Smart_car_paddle-main/c++/demo/q.cpp -o CMakeFiles/q.dir/demo/q.cpp.s

CMakeFiles/q.dir/demo/q.cpp.o.requires:

.PHONY : CMakeFiles/q.dir/demo/q.cpp.o.requires

CMakeFiles/q.dir/demo/q.cpp.o.provides: CMakeFiles/q.dir/demo/q.cpp.o.requires
	$(MAKE) -f CMakeFiles/q.dir/build.make CMakeFiles/q.dir/demo/q.cpp.o.provides.build
.PHONY : CMakeFiles/q.dir/demo/q.cpp.o.provides

CMakeFiles/q.dir/demo/q.cpp.o.provides.build: CMakeFiles/q.dir/demo/q.cpp.o


# Object files for target q
q_OBJECTS = \
"CMakeFiles/q.dir/demo/q.cpp.o"

# External object files for target q
q_EXTERNAL_OBJECTS =

q : CMakeFiles/q.dir/demo/q.cpp.o
q : CMakeFiles/q.dir/build.make
q : /usr/local/lib/libopencv_dnn.so.3.4.3
q : /usr/local/lib/libopencv_ml.so.3.4.3
q : /usr/local/lib/libopencv_objdetect.so.3.4.3
q : /usr/local/lib/libopencv_shape.so.3.4.3
q : /usr/local/lib/libopencv_stitching.so.3.4.3
q : /usr/local/lib/libopencv_superres.so.3.4.3
q : /usr/local/lib/libopencv_videostab.so.3.4.3
q : /usr/local/lib/libopencv_calib3d.so.3.4.3
q : /usr/local/lib/libopencv_features2d.so.3.4.3
q : /usr/local/lib/libopencv_flann.so.3.4.3
q : /usr/local/lib/libopencv_highgui.so.3.4.3
q : /usr/local/lib/libopencv_photo.so.3.4.3
q : /usr/local/lib/libopencv_video.so.3.4.3
q : /usr/local/lib/libopencv_videoio.so.3.4.3
q : /usr/local/lib/libopencv_imgcodecs.so.3.4.3
q : /usr/local/lib/libopencv_imgproc.so.3.4.3
q : /usr/local/lib/libopencv_core.so.3.4.3
q : CMakeFiles/q.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/media/root/Data/Desktop/Smart_car_paddle-main/c++/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable q"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/q.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/q.dir/build: q

.PHONY : CMakeFiles/q.dir/build

CMakeFiles/q.dir/requires: CMakeFiles/q.dir/demo/q.cpp.o.requires

.PHONY : CMakeFiles/q.dir/requires

CMakeFiles/q.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/q.dir/cmake_clean.cmake
.PHONY : CMakeFiles/q.dir/clean

CMakeFiles/q.dir/depend:
	cd /media/root/Data/Desktop/Smart_car_paddle-main/c++/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /media/root/Data/Desktop/Smart_car_paddle-main/c++ /media/root/Data/Desktop/Smart_car_paddle-main/c++ /media/root/Data/Desktop/Smart_car_paddle-main/c++/build /media/root/Data/Desktop/Smart_car_paddle-main/c++/build /media/root/Data/Desktop/Smart_car_paddle-main/c++/build/CMakeFiles/q.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/q.dir/depend

