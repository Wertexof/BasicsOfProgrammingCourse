# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.20

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2021.2.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2021.2.3\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\perso\CLionProjects\vectors_project

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\perso\CLionProjects\vectors_project\cmake-build-debug

# Include any dependencies generated for this target.
include libs/vector/matrix/CMakeFiles/data_structures.dir/depend.make
# Include the progress variables for this target.
include libs/vector/matrix/CMakeFiles/data_structures.dir/progress.make

# Include the compile flags for this target's objects.
include libs/vector/matrix/CMakeFiles/data_structures.dir/flags.make

libs/vector/matrix/CMakeFiles/data_structures.dir/vector/vector.c.obj: libs/vector/matrix/CMakeFiles/data_structures.dir/flags.make
libs/vector/matrix/CMakeFiles/data_structures.dir/vector/vector.c.obj: ../libs/data_structures/vector/vector.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\perso\CLionProjects\vectors_project\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object libs/vector/matrix/CMakeFiles/data_structures.dir/vector/vector.c.obj"
	cd /d C:\Users\perso\CLionProjects\vectors_project\cmake-build-debug\libs\vector\matrix && C:\PROGRA~1\JETBRA~1\CLION2~1.3\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\data_structures.dir\vector\vector.c.obj -c C:\Users\perso\CLionProjects\vectors_project\libs\data_structures\vector\vector.c

libs/vector/matrix/CMakeFiles/data_structures.dir/vector/vector.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/data_structures.dir/vector/vector.c.i"
	cd /d C:\Users\perso\CLionProjects\vectors_project\cmake-build-debug\libs\vector\matrix && C:\PROGRA~1\JETBRA~1\CLION2~1.3\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\perso\CLionProjects\vectors_project\libs\data_structures\vector\vector.c > CMakeFiles\data_structures.dir\vector\vector.c.i

libs/vector/matrix/CMakeFiles/data_structures.dir/vector/vector.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/data_structures.dir/vector/vector.c.s"
	cd /d C:\Users\perso\CLionProjects\vectors_project\cmake-build-debug\libs\vector\matrix && C:\PROGRA~1\JETBRA~1\CLION2~1.3\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\perso\CLionProjects\vectors_project\libs\data_structures\vector\vector.c -o CMakeFiles\data_structures.dir\vector\vector.c.s

libs/vector/matrix/CMakeFiles/data_structures.dir/matrix/matrix.c.obj: libs/vector/matrix/CMakeFiles/data_structures.dir/flags.make
libs/vector/matrix/CMakeFiles/data_structures.dir/matrix/matrix.c.obj: ../libs/data_structures/matrix/matrix.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\perso\CLionProjects\vectors_project\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object libs/vector/matrix/CMakeFiles/data_structures.dir/matrix/matrix.c.obj"
	cd /d C:\Users\perso\CLionProjects\vectors_project\cmake-build-debug\libs\vector\matrix && C:\PROGRA~1\JETBRA~1\CLION2~1.3\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\data_structures.dir\matrix\matrix.c.obj -c C:\Users\perso\CLionProjects\vectors_project\libs\data_structures\matrix\matrix.c

libs/vector/matrix/CMakeFiles/data_structures.dir/matrix/matrix.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/data_structures.dir/matrix/matrix.c.i"
	cd /d C:\Users\perso\CLionProjects\vectors_project\cmake-build-debug\libs\vector\matrix && C:\PROGRA~1\JETBRA~1\CLION2~1.3\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\perso\CLionProjects\vectors_project\libs\data_structures\matrix\matrix.c > CMakeFiles\data_structures.dir\matrix\matrix.c.i

libs/vector/matrix/CMakeFiles/data_structures.dir/matrix/matrix.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/data_structures.dir/matrix/matrix.c.s"
	cd /d C:\Users\perso\CLionProjects\vectors_project\cmake-build-debug\libs\vector\matrix && C:\PROGRA~1\JETBRA~1\CLION2~1.3\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\perso\CLionProjects\vectors_project\libs\data_structures\matrix\matrix.c -o CMakeFiles\data_structures.dir\matrix\matrix.c.s

# Object files for target data_structures
data_structures_OBJECTS = \
"CMakeFiles/data_structures.dir/vector/vector.c.obj" \
"CMakeFiles/data_structures.dir/matrix/matrix.c.obj"

# External object files for target data_structures
data_structures_EXTERNAL_OBJECTS =

libs/vector/matrix/libdata_structures.a: libs/vector/matrix/CMakeFiles/data_structures.dir/vector/vector.c.obj
libs/vector/matrix/libdata_structures.a: libs/vector/matrix/CMakeFiles/data_structures.dir/matrix/matrix.c.obj
libs/vector/matrix/libdata_structures.a: libs/vector/matrix/CMakeFiles/data_structures.dir/build.make
libs/vector/matrix/libdata_structures.a: libs/vector/matrix/CMakeFiles/data_structures.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\perso\CLionProjects\vectors_project\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C static library libdata_structures.a"
	cd /d C:\Users\perso\CLionProjects\vectors_project\cmake-build-debug\libs\vector\matrix && $(CMAKE_COMMAND) -P CMakeFiles\data_structures.dir\cmake_clean_target.cmake
	cd /d C:\Users\perso\CLionProjects\vectors_project\cmake-build-debug\libs\vector\matrix && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\data_structures.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
libs/vector/matrix/CMakeFiles/data_structures.dir/build: libs/vector/matrix/libdata_structures.a
.PHONY : libs/vector/matrix/CMakeFiles/data_structures.dir/build

libs/vector/matrix/CMakeFiles/data_structures.dir/clean:
	cd /d C:\Users\perso\CLionProjects\vectors_project\cmake-build-debug\libs\vector\matrix && $(CMAKE_COMMAND) -P CMakeFiles\data_structures.dir\cmake_clean.cmake
.PHONY : libs/vector/matrix/CMakeFiles/data_structures.dir/clean

libs/vector/matrix/CMakeFiles/data_structures.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\perso\CLionProjects\vectors_project C:\Users\perso\CLionProjects\vectors_project\libs\data_structures C:\Users\perso\CLionProjects\vectors_project\cmake-build-debug C:\Users\perso\CLionProjects\vectors_project\cmake-build-debug\libs\vector\matrix C:\Users\perso\CLionProjects\vectors_project\cmake-build-debug\libs\vector\matrix\CMakeFiles\data_structures.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : libs/vector/matrix/CMakeFiles/data_structures.dir/depend

