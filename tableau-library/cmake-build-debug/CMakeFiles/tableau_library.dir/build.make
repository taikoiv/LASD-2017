# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.6

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
CMAKE_COMMAND = /cygdrive/c/Users/Checco/.CLion2016.3/system/cygwin_cmake/bin/cmake.exe

# The command to remove a file.
RM = /cygdrive/c/Users/Checco/.CLion2016.3/system/cygwin_cmake/bin/cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /cygdrive/c/Users/Checco/Desktop/LASD-2017/tableau-library

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /cygdrive/c/Users/Checco/Desktop/LASD-2017/tableau-library/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/tableau_library.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/tableau_library.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/tableau_library.dir/flags.make

CMakeFiles/tableau_library.dir/main.c.o: CMakeFiles/tableau_library.dir/flags.make
CMakeFiles/tableau_library.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/c/Users/Checco/Desktop/LASD-2017/tableau-library/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/tableau_library.dir/main.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/tableau_library.dir/main.c.o   -c /cygdrive/c/Users/Checco/Desktop/LASD-2017/tableau-library/main.c

CMakeFiles/tableau_library.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/tableau_library.dir/main.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /cygdrive/c/Users/Checco/Desktop/LASD-2017/tableau-library/main.c > CMakeFiles/tableau_library.dir/main.c.i

CMakeFiles/tableau_library.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/tableau_library.dir/main.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /cygdrive/c/Users/Checco/Desktop/LASD-2017/tableau-library/main.c -o CMakeFiles/tableau_library.dir/main.c.s

CMakeFiles/tableau_library.dir/main.c.o.requires:

.PHONY : CMakeFiles/tableau_library.dir/main.c.o.requires

CMakeFiles/tableau_library.dir/main.c.o.provides: CMakeFiles/tableau_library.dir/main.c.o.requires
	$(MAKE) -f CMakeFiles/tableau_library.dir/build.make CMakeFiles/tableau_library.dir/main.c.o.provides.build
.PHONY : CMakeFiles/tableau_library.dir/main.c.o.provides

CMakeFiles/tableau_library.dir/main.c.o.provides.build: CMakeFiles/tableau_library.dir/main.c.o


CMakeFiles/tableau_library.dir/tableau.c.o: CMakeFiles/tableau_library.dir/flags.make
CMakeFiles/tableau_library.dir/tableau.c.o: ../tableau.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/c/Users/Checco/Desktop/LASD-2017/tableau-library/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/tableau_library.dir/tableau.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/tableau_library.dir/tableau.c.o   -c /cygdrive/c/Users/Checco/Desktop/LASD-2017/tableau-library/tableau.c

CMakeFiles/tableau_library.dir/tableau.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/tableau_library.dir/tableau.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /cygdrive/c/Users/Checco/Desktop/LASD-2017/tableau-library/tableau.c > CMakeFiles/tableau_library.dir/tableau.c.i

CMakeFiles/tableau_library.dir/tableau.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/tableau_library.dir/tableau.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /cygdrive/c/Users/Checco/Desktop/LASD-2017/tableau-library/tableau.c -o CMakeFiles/tableau_library.dir/tableau.c.s

CMakeFiles/tableau_library.dir/tableau.c.o.requires:

.PHONY : CMakeFiles/tableau_library.dir/tableau.c.o.requires

CMakeFiles/tableau_library.dir/tableau.c.o.provides: CMakeFiles/tableau_library.dir/tableau.c.o.requires
	$(MAKE) -f CMakeFiles/tableau_library.dir/build.make CMakeFiles/tableau_library.dir/tableau.c.o.provides.build
.PHONY : CMakeFiles/tableau_library.dir/tableau.c.o.provides

CMakeFiles/tableau_library.dir/tableau.c.o.provides.build: CMakeFiles/tableau_library.dir/tableau.c.o


# Object files for target tableau_library
tableau_library_OBJECTS = \
"CMakeFiles/tableau_library.dir/main.c.o" \
"CMakeFiles/tableau_library.dir/tableau.c.o"

# External object files for target tableau_library
tableau_library_EXTERNAL_OBJECTS =

tableau_library.exe: CMakeFiles/tableau_library.dir/main.c.o
tableau_library.exe: CMakeFiles/tableau_library.dir/tableau.c.o
tableau_library.exe: CMakeFiles/tableau_library.dir/build.make
tableau_library.exe: CMakeFiles/tableau_library.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/cygdrive/c/Users/Checco/Desktop/LASD-2017/tableau-library/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable tableau_library.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/tableau_library.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/tableau_library.dir/build: tableau_library.exe

.PHONY : CMakeFiles/tableau_library.dir/build

CMakeFiles/tableau_library.dir/requires: CMakeFiles/tableau_library.dir/main.c.o.requires
CMakeFiles/tableau_library.dir/requires: CMakeFiles/tableau_library.dir/tableau.c.o.requires

.PHONY : CMakeFiles/tableau_library.dir/requires

CMakeFiles/tableau_library.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/tableau_library.dir/cmake_clean.cmake
.PHONY : CMakeFiles/tableau_library.dir/clean

CMakeFiles/tableau_library.dir/depend:
	cd /cygdrive/c/Users/Checco/Desktop/LASD-2017/tableau-library/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /cygdrive/c/Users/Checco/Desktop/LASD-2017/tableau-library /cygdrive/c/Users/Checco/Desktop/LASD-2017/tableau-library /cygdrive/c/Users/Checco/Desktop/LASD-2017/tableau-library/cmake-build-debug /cygdrive/c/Users/Checco/Desktop/LASD-2017/tableau-library/cmake-build-debug /cygdrive/c/Users/Checco/Desktop/LASD-2017/tableau-library/cmake-build-debug/CMakeFiles/tableau_library.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/tableau_library.dir/depend
