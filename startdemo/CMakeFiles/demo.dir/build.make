# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canoncical targets will work.
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

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/adrian/work/domino-physics/startdemo

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/adrian/work/domino-physics/startdemo

# Include any dependencies generated for this target.
include CMakeFiles/demo.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/demo.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/demo.dir/flags.make

CMakeFiles/demo.dir/src/Camera.cpp.o: CMakeFiles/demo.dir/flags.make
CMakeFiles/demo.dir/src/Camera.cpp.o: src/Camera.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/adrian/work/domino-physics/startdemo/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/demo.dir/src/Camera.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/demo.dir/src/Camera.cpp.o -c /home/adrian/work/domino-physics/startdemo/src/Camera.cpp

CMakeFiles/demo.dir/src/Camera.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/demo.dir/src/Camera.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/adrian/work/domino-physics/startdemo/src/Camera.cpp > CMakeFiles/demo.dir/src/Camera.cpp.i

CMakeFiles/demo.dir/src/Camera.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/demo.dir/src/Camera.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/adrian/work/domino-physics/startdemo/src/Camera.cpp -o CMakeFiles/demo.dir/src/Camera.cpp.s

CMakeFiles/demo.dir/src/Camera.cpp.o.requires:
.PHONY : CMakeFiles/demo.dir/src/Camera.cpp.o.requires

CMakeFiles/demo.dir/src/Camera.cpp.o.provides: CMakeFiles/demo.dir/src/Camera.cpp.o.requires
	$(MAKE) -f CMakeFiles/demo.dir/build.make CMakeFiles/demo.dir/src/Camera.cpp.o.provides.build
.PHONY : CMakeFiles/demo.dir/src/Camera.cpp.o.provides

CMakeFiles/demo.dir/src/Camera.cpp.o.provides.build: CMakeFiles/demo.dir/src/Camera.cpp.o

CMakeFiles/demo.dir/src/CMesh.cpp.o: CMakeFiles/demo.dir/flags.make
CMakeFiles/demo.dir/src/CMesh.cpp.o: src/CMesh.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/adrian/work/domino-physics/startdemo/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/demo.dir/src/CMesh.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/demo.dir/src/CMesh.cpp.o -c /home/adrian/work/domino-physics/startdemo/src/CMesh.cpp

CMakeFiles/demo.dir/src/CMesh.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/demo.dir/src/CMesh.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/adrian/work/domino-physics/startdemo/src/CMesh.cpp > CMakeFiles/demo.dir/src/CMesh.cpp.i

CMakeFiles/demo.dir/src/CMesh.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/demo.dir/src/CMesh.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/adrian/work/domino-physics/startdemo/src/CMesh.cpp -o CMakeFiles/demo.dir/src/CMesh.cpp.s

CMakeFiles/demo.dir/src/CMesh.cpp.o.requires:
.PHONY : CMakeFiles/demo.dir/src/CMesh.cpp.o.requires

CMakeFiles/demo.dir/src/CMesh.cpp.o.provides: CMakeFiles/demo.dir/src/CMesh.cpp.o.requires
	$(MAKE) -f CMakeFiles/demo.dir/build.make CMakeFiles/demo.dir/src/CMesh.cpp.o.provides.build
.PHONY : CMakeFiles/demo.dir/src/CMesh.cpp.o.provides

CMakeFiles/demo.dir/src/CMesh.cpp.o.provides.build: CMakeFiles/demo.dir/src/CMesh.cpp.o

CMakeFiles/demo.dir/src/CSceneNode.cpp.o: CMakeFiles/demo.dir/flags.make
CMakeFiles/demo.dir/src/CSceneNode.cpp.o: src/CSceneNode.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/adrian/work/domino-physics/startdemo/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/demo.dir/src/CSceneNode.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/demo.dir/src/CSceneNode.cpp.o -c /home/adrian/work/domino-physics/startdemo/src/CSceneNode.cpp

CMakeFiles/demo.dir/src/CSceneNode.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/demo.dir/src/CSceneNode.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/adrian/work/domino-physics/startdemo/src/CSceneNode.cpp > CMakeFiles/demo.dir/src/CSceneNode.cpp.i

CMakeFiles/demo.dir/src/CSceneNode.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/demo.dir/src/CSceneNode.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/adrian/work/domino-physics/startdemo/src/CSceneNode.cpp -o CMakeFiles/demo.dir/src/CSceneNode.cpp.s

CMakeFiles/demo.dir/src/CSceneNode.cpp.o.requires:
.PHONY : CMakeFiles/demo.dir/src/CSceneNode.cpp.o.requires

CMakeFiles/demo.dir/src/CSceneNode.cpp.o.provides: CMakeFiles/demo.dir/src/CSceneNode.cpp.o.requires
	$(MAKE) -f CMakeFiles/demo.dir/build.make CMakeFiles/demo.dir/src/CSceneNode.cpp.o.provides.build
.PHONY : CMakeFiles/demo.dir/src/CSceneNode.cpp.o.provides

CMakeFiles/demo.dir/src/CSceneNode.cpp.o.provides.build: CMakeFiles/demo.dir/src/CSceneNode.cpp.o

CMakeFiles/demo.dir/src/Light.cpp.o: CMakeFiles/demo.dir/flags.make
CMakeFiles/demo.dir/src/Light.cpp.o: src/Light.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/adrian/work/domino-physics/startdemo/CMakeFiles $(CMAKE_PROGRESS_4)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/demo.dir/src/Light.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/demo.dir/src/Light.cpp.o -c /home/adrian/work/domino-physics/startdemo/src/Light.cpp

CMakeFiles/demo.dir/src/Light.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/demo.dir/src/Light.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/adrian/work/domino-physics/startdemo/src/Light.cpp > CMakeFiles/demo.dir/src/Light.cpp.i

CMakeFiles/demo.dir/src/Light.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/demo.dir/src/Light.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/adrian/work/domino-physics/startdemo/src/Light.cpp -o CMakeFiles/demo.dir/src/Light.cpp.s

CMakeFiles/demo.dir/src/Light.cpp.o.requires:
.PHONY : CMakeFiles/demo.dir/src/Light.cpp.o.requires

CMakeFiles/demo.dir/src/Light.cpp.o.provides: CMakeFiles/demo.dir/src/Light.cpp.o.requires
	$(MAKE) -f CMakeFiles/demo.dir/build.make CMakeFiles/demo.dir/src/Light.cpp.o.provides.build
.PHONY : CMakeFiles/demo.dir/src/Light.cpp.o.provides

CMakeFiles/demo.dir/src/Light.cpp.o.provides.build: CMakeFiles/demo.dir/src/Light.cpp.o

CMakeFiles/demo.dir/src/main.cpp.o: CMakeFiles/demo.dir/flags.make
CMakeFiles/demo.dir/src/main.cpp.o: src/main.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/adrian/work/domino-physics/startdemo/CMakeFiles $(CMAKE_PROGRESS_5)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/demo.dir/src/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/demo.dir/src/main.cpp.o -c /home/adrian/work/domino-physics/startdemo/src/main.cpp

CMakeFiles/demo.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/demo.dir/src/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/adrian/work/domino-physics/startdemo/src/main.cpp > CMakeFiles/demo.dir/src/main.cpp.i

CMakeFiles/demo.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/demo.dir/src/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/adrian/work/domino-physics/startdemo/src/main.cpp -o CMakeFiles/demo.dir/src/main.cpp.s

CMakeFiles/demo.dir/src/main.cpp.o.requires:
.PHONY : CMakeFiles/demo.dir/src/main.cpp.o.requires

CMakeFiles/demo.dir/src/main.cpp.o.provides: CMakeFiles/demo.dir/src/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/demo.dir/build.make CMakeFiles/demo.dir/src/main.cpp.o.provides.build
.PHONY : CMakeFiles/demo.dir/src/main.cpp.o.provides

CMakeFiles/demo.dir/src/main.cpp.o.provides.build: CMakeFiles/demo.dir/src/main.cpp.o

CMakeFiles/demo.dir/src/OFF.cpp.o: CMakeFiles/demo.dir/flags.make
CMakeFiles/demo.dir/src/OFF.cpp.o: src/OFF.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/adrian/work/domino-physics/startdemo/CMakeFiles $(CMAKE_PROGRESS_6)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/demo.dir/src/OFF.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/demo.dir/src/OFF.cpp.o -c /home/adrian/work/domino-physics/startdemo/src/OFF.cpp

CMakeFiles/demo.dir/src/OFF.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/demo.dir/src/OFF.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/adrian/work/domino-physics/startdemo/src/OFF.cpp > CMakeFiles/demo.dir/src/OFF.cpp.i

CMakeFiles/demo.dir/src/OFF.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/demo.dir/src/OFF.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/adrian/work/domino-physics/startdemo/src/OFF.cpp -o CMakeFiles/demo.dir/src/OFF.cpp.s

CMakeFiles/demo.dir/src/OFF.cpp.o.requires:
.PHONY : CMakeFiles/demo.dir/src/OFF.cpp.o.requires

CMakeFiles/demo.dir/src/OFF.cpp.o.provides: CMakeFiles/demo.dir/src/OFF.cpp.o.requires
	$(MAKE) -f CMakeFiles/demo.dir/build.make CMakeFiles/demo.dir/src/OFF.cpp.o.provides.build
.PHONY : CMakeFiles/demo.dir/src/OFF.cpp.o.provides

CMakeFiles/demo.dir/src/OFF.cpp.o.provides.build: CMakeFiles/demo.dir/src/OFF.cpp.o

CMakeFiles/demo.dir/src/Test1.cpp.o: CMakeFiles/demo.dir/flags.make
CMakeFiles/demo.dir/src/Test1.cpp.o: src/Test1.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/adrian/work/domino-physics/startdemo/CMakeFiles $(CMAKE_PROGRESS_7)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/demo.dir/src/Test1.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/demo.dir/src/Test1.cpp.o -c /home/adrian/work/domino-physics/startdemo/src/Test1.cpp

CMakeFiles/demo.dir/src/Test1.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/demo.dir/src/Test1.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/adrian/work/domino-physics/startdemo/src/Test1.cpp > CMakeFiles/demo.dir/src/Test1.cpp.i

CMakeFiles/demo.dir/src/Test1.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/demo.dir/src/Test1.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/adrian/work/domino-physics/startdemo/src/Test1.cpp -o CMakeFiles/demo.dir/src/Test1.cpp.s

CMakeFiles/demo.dir/src/Test1.cpp.o.requires:
.PHONY : CMakeFiles/demo.dir/src/Test1.cpp.o.requires

CMakeFiles/demo.dir/src/Test1.cpp.o.provides: CMakeFiles/demo.dir/src/Test1.cpp.o.requires
	$(MAKE) -f CMakeFiles/demo.dir/build.make CMakeFiles/demo.dir/src/Test1.cpp.o.provides.build
.PHONY : CMakeFiles/demo.dir/src/Test1.cpp.o.provides

CMakeFiles/demo.dir/src/Test1.cpp.o.provides.build: CMakeFiles/demo.dir/src/Test1.cpp.o

# Object files for target demo
demo_OBJECTS = \
"CMakeFiles/demo.dir/src/Camera.cpp.o" \
"CMakeFiles/demo.dir/src/CMesh.cpp.o" \
"CMakeFiles/demo.dir/src/CSceneNode.cpp.o" \
"CMakeFiles/demo.dir/src/Light.cpp.o" \
"CMakeFiles/demo.dir/src/main.cpp.o" \
"CMakeFiles/demo.dir/src/OFF.cpp.o" \
"CMakeFiles/demo.dir/src/Test1.cpp.o"

# External object files for target demo
demo_EXTERNAL_OBJECTS =

demo: CMakeFiles/demo.dir/src/Camera.cpp.o
demo: CMakeFiles/demo.dir/src/CMesh.cpp.o
demo: CMakeFiles/demo.dir/src/CSceneNode.cpp.o
demo: CMakeFiles/demo.dir/src/Light.cpp.o
demo: CMakeFiles/demo.dir/src/main.cpp.o
demo: CMakeFiles/demo.dir/src/OFF.cpp.o
demo: CMakeFiles/demo.dir/src/Test1.cpp.o
demo: CMakeFiles/demo.dir/build.make
demo: CMakeFiles/demo.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable demo"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/demo.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/demo.dir/build: demo
.PHONY : CMakeFiles/demo.dir/build

CMakeFiles/demo.dir/requires: CMakeFiles/demo.dir/src/Camera.cpp.o.requires
CMakeFiles/demo.dir/requires: CMakeFiles/demo.dir/src/CMesh.cpp.o.requires
CMakeFiles/demo.dir/requires: CMakeFiles/demo.dir/src/CSceneNode.cpp.o.requires
CMakeFiles/demo.dir/requires: CMakeFiles/demo.dir/src/Light.cpp.o.requires
CMakeFiles/demo.dir/requires: CMakeFiles/demo.dir/src/main.cpp.o.requires
CMakeFiles/demo.dir/requires: CMakeFiles/demo.dir/src/OFF.cpp.o.requires
CMakeFiles/demo.dir/requires: CMakeFiles/demo.dir/src/Test1.cpp.o.requires
.PHONY : CMakeFiles/demo.dir/requires

CMakeFiles/demo.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/demo.dir/cmake_clean.cmake
.PHONY : CMakeFiles/demo.dir/clean

CMakeFiles/demo.dir/depend:
	cd /home/adrian/work/domino-physics/startdemo && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/adrian/work/domino-physics/startdemo /home/adrian/work/domino-physics/startdemo /home/adrian/work/domino-physics/startdemo /home/adrian/work/domino-physics/startdemo /home/adrian/work/domino-physics/startdemo/CMakeFiles/demo.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/demo.dir/depend
