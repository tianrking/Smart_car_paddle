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
include CMakeFiles/save.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/save.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/save.dir/flags.make

CMakeFiles/save.dir/demo/save.cpp.o: CMakeFiles/save.dir/flags.make
CMakeFiles/save.dir/demo/save.cpp.o: ../demo/save.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/media/root/Data/Desktop/Smart_car_paddle-main/c++/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/save.dir/demo/save.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/save.dir/demo/save.cpp.o -c /media/root/Data/Desktop/Smart_car_paddle-main/c++/demo/save.cpp

CMakeFiles/save.dir/demo/save.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/save.dir/demo/save.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /media/root/Data/Desktop/Smart_car_paddle-main/c++/demo/save.cpp > CMakeFiles/save.dir/demo/save.cpp.i

CMakeFiles/save.dir/demo/save.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/save.dir/demo/save.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /media/root/Data/Desktop/Smart_car_paddle-main/c++/demo/save.cpp -o CMakeFiles/save.dir/demo/save.cpp.s

CMakeFiles/save.dir/demo/save.cpp.o.requires:

.PHONY : CMakeFiles/save.dir/demo/save.cpp.o.requires

CMakeFiles/save.dir/demo/save.cpp.o.provides: CMakeFiles/save.dir/demo/save.cpp.o.requires
	$(MAKE) -f CMakeFiles/save.dir/build.make CMakeFiles/save.dir/demo/save.cpp.o.provides.build
.PHONY : CMakeFiles/save.dir/demo/save.cpp.o.provides

CMakeFiles/save.dir/demo/save.cpp.o.provides.build: CMakeFiles/save.dir/demo/save.cpp.o


# Object files for target save
save_OBJECTS = \
"CMakeFiles/save.dir/demo/save.cpp.o"

# External object files for target save
save_EXTERNAL_OBJECTS =

save: CMakeFiles/save.dir/demo/save.cpp.o
save: CMakeFiles/save.dir/build.make
save: /usr/local/lib/libopencv_dnn.so.3.4.3
save: /usr/local/lib/libopencv_ml.so.3.4.3
save: /usr/local/lib/libopencv_objdetect.so.3.4.3
save: /usr/local/lib/libopencv_shape.so.3.4.3
save: /usr/local/lib/libopencv_stitching.so.3.4.3
save: /usr/local/lib/libopencv_superres.so.3.4.3
save: /usr/local/lib/libopencv_videostab.so.3.4.3
save: /usr/local/lib/libopencv_calib3d.so.3.4.3
save: /usr/local/lib/libopencv_features2d.so.3.4.3
save: /usr/local/lib/libopencv_flann.so.3.4.3
save: /usr/local/lib/libopencv_highgui.so.3.4.3
save: /usr/local/lib/libopencv_photo.so.3.4.3
save: /usr/local/lib/libopencv_video.so.3.4.3
save: /usr/local/lib/libopencv_videoio.so.3.4.3
save: /usr/local/lib/libopencv_imgcodecs.so.3.4.3
save: /usr/local/lib/libopencv_imgproc.so.3.4.3
save: /usr/local/lib/libopencv_core.so.3.4.3
save: CMakeFiles/save.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/media/root/Data/Desktop/Smart_car_paddle-main/c++/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable save"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/save.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/save.dir/build: save

.PHONY : CMakeFiles/save.dir/build

CMakeFiles/save.dir/requires: CMakeFiles/save.dir/demo/save.cpp.o.requires

.PHONY : CMakeFiles/save.dir/requires

CMakeFiles/save.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/save.dir/cmake_clean.cmake
.PHONY : CMakeFiles/save.dir/clean

CMakeFiles/save.dir/depend:
	cd /media/root/Data/Desktop/Smart_car_paddle-main/c++/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /media/root/Data/Desktop/Smart_car_paddle-main/c++ /media/root/Data/Desktop/Smart_car_paddle-main/c++ /media/root/Data/Desktop/Smart_car_paddle-main/c++/build /media/root/Data/Desktop/Smart_car_paddle-main/c++/build /media/root/Data/Desktop/Smart_car_paddle-main/c++/build/CMakeFiles/save.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/save.dir/depend
