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
include CMakeFiles/all_in_one_01.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/all_in_one_01.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/all_in_one_01.dir/flags.make

CMakeFiles/all_in_one_01.dir/demo/all_in_one_01.cpp.o: CMakeFiles/all_in_one_01.dir/flags.make
CMakeFiles/all_in_one_01.dir/demo/all_in_one_01.cpp.o: ../demo/all_in_one_01.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/media/root/Data/Desktop/Smart_car_paddle-main/c++/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/all_in_one_01.dir/demo/all_in_one_01.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/all_in_one_01.dir/demo/all_in_one_01.cpp.o -c /media/root/Data/Desktop/Smart_car_paddle-main/c++/demo/all_in_one_01.cpp

CMakeFiles/all_in_one_01.dir/demo/all_in_one_01.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/all_in_one_01.dir/demo/all_in_one_01.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /media/root/Data/Desktop/Smart_car_paddle-main/c++/demo/all_in_one_01.cpp > CMakeFiles/all_in_one_01.dir/demo/all_in_one_01.cpp.i

CMakeFiles/all_in_one_01.dir/demo/all_in_one_01.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/all_in_one_01.dir/demo/all_in_one_01.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /media/root/Data/Desktop/Smart_car_paddle-main/c++/demo/all_in_one_01.cpp -o CMakeFiles/all_in_one_01.dir/demo/all_in_one_01.cpp.s

CMakeFiles/all_in_one_01.dir/demo/all_in_one_01.cpp.o.requires:

.PHONY : CMakeFiles/all_in_one_01.dir/demo/all_in_one_01.cpp.o.requires

CMakeFiles/all_in_one_01.dir/demo/all_in_one_01.cpp.o.provides: CMakeFiles/all_in_one_01.dir/demo/all_in_one_01.cpp.o.requires
	$(MAKE) -f CMakeFiles/all_in_one_01.dir/build.make CMakeFiles/all_in_one_01.dir/demo/all_in_one_01.cpp.o.provides.build
.PHONY : CMakeFiles/all_in_one_01.dir/demo/all_in_one_01.cpp.o.provides

CMakeFiles/all_in_one_01.dir/demo/all_in_one_01.cpp.o.provides.build: CMakeFiles/all_in_one_01.dir/demo/all_in_one_01.cpp.o


# Object files for target all_in_one_01
all_in_one_01_OBJECTS = \
"CMakeFiles/all_in_one_01.dir/demo/all_in_one_01.cpp.o"

# External object files for target all_in_one_01
all_in_one_01_EXTERNAL_OBJECTS =

all_in_one_01: CMakeFiles/all_in_one_01.dir/demo/all_in_one_01.cpp.o
all_in_one_01: CMakeFiles/all_in_one_01.dir/build.make
all_in_one_01: /usr/local/lib/libopencv_dnn.so.3.4.3
all_in_one_01: /usr/local/lib/libopencv_ml.so.3.4.3
all_in_one_01: /usr/local/lib/libopencv_objdetect.so.3.4.3
all_in_one_01: /usr/local/lib/libopencv_shape.so.3.4.3
all_in_one_01: /usr/local/lib/libopencv_stitching.so.3.4.3
all_in_one_01: /usr/local/lib/libopencv_superres.so.3.4.3
all_in_one_01: /usr/local/lib/libopencv_videostab.so.3.4.3
all_in_one_01: /usr/local/lib/libopencv_calib3d.so.3.4.3
all_in_one_01: /usr/local/lib/libopencv_features2d.so.3.4.3
all_in_one_01: /usr/local/lib/libopencv_flann.so.3.4.3
all_in_one_01: /usr/local/lib/libopencv_highgui.so.3.4.3
all_in_one_01: /usr/local/lib/libopencv_photo.so.3.4.3
all_in_one_01: /usr/local/lib/libopencv_video.so.3.4.3
all_in_one_01: /usr/local/lib/libopencv_videoio.so.3.4.3
all_in_one_01: /usr/local/lib/libopencv_imgcodecs.so.3.4.3
all_in_one_01: /usr/local/lib/libopencv_imgproc.so.3.4.3
all_in_one_01: /usr/local/lib/libopencv_core.so.3.4.3
all_in_one_01: CMakeFiles/all_in_one_01.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/media/root/Data/Desktop/Smart_car_paddle-main/c++/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable all_in_one_01"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/all_in_one_01.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/all_in_one_01.dir/build: all_in_one_01

.PHONY : CMakeFiles/all_in_one_01.dir/build

CMakeFiles/all_in_one_01.dir/requires: CMakeFiles/all_in_one_01.dir/demo/all_in_one_01.cpp.o.requires

.PHONY : CMakeFiles/all_in_one_01.dir/requires

CMakeFiles/all_in_one_01.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/all_in_one_01.dir/cmake_clean.cmake
.PHONY : CMakeFiles/all_in_one_01.dir/clean

CMakeFiles/all_in_one_01.dir/depend:
	cd /media/root/Data/Desktop/Smart_car_paddle-main/c++/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /media/root/Data/Desktop/Smart_car_paddle-main/c++ /media/root/Data/Desktop/Smart_car_paddle-main/c++ /media/root/Data/Desktop/Smart_car_paddle-main/c++/build /media/root/Data/Desktop/Smart_car_paddle-main/c++/build /media/root/Data/Desktop/Smart_car_paddle-main/c++/build/CMakeFiles/all_in_one_01.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/all_in_one_01.dir/depend

