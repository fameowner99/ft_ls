# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.9

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
CMAKE_COMMAND = /home/fameowner/Programs/clion-2017.3.4/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/fameowner/Programs/clion-2017.3.4/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/fameowner/ft_Ls

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/fameowner/ft_Ls/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/ft_Ls.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ft_Ls.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ft_Ls.dir/flags.make

CMakeFiles/ft_Ls.dir/srcs/flag_tools.c.o: CMakeFiles/ft_Ls.dir/flags.make
CMakeFiles/ft_Ls.dir/srcs/flag_tools.c.o: ../srcs/flag_tools.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fameowner/ft_Ls/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/ft_Ls.dir/srcs/flag_tools.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ft_Ls.dir/srcs/flag_tools.c.o   -c /home/fameowner/ft_Ls/srcs/flag_tools.c

CMakeFiles/ft_Ls.dir/srcs/flag_tools.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ft_Ls.dir/srcs/flag_tools.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/fameowner/ft_Ls/srcs/flag_tools.c > CMakeFiles/ft_Ls.dir/srcs/flag_tools.c.i

CMakeFiles/ft_Ls.dir/srcs/flag_tools.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ft_Ls.dir/srcs/flag_tools.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/fameowner/ft_Ls/srcs/flag_tools.c -o CMakeFiles/ft_Ls.dir/srcs/flag_tools.c.s

CMakeFiles/ft_Ls.dir/srcs/flag_tools.c.o.requires:

.PHONY : CMakeFiles/ft_Ls.dir/srcs/flag_tools.c.o.requires

CMakeFiles/ft_Ls.dir/srcs/flag_tools.c.o.provides: CMakeFiles/ft_Ls.dir/srcs/flag_tools.c.o.requires
	$(MAKE) -f CMakeFiles/ft_Ls.dir/build.make CMakeFiles/ft_Ls.dir/srcs/flag_tools.c.o.provides.build
.PHONY : CMakeFiles/ft_Ls.dir/srcs/flag_tools.c.o.provides

CMakeFiles/ft_Ls.dir/srcs/flag_tools.c.o.provides.build: CMakeFiles/ft_Ls.dir/srcs/flag_tools.c.o


CMakeFiles/ft_Ls.dir/srcs/ft_ls.c.o: CMakeFiles/ft_Ls.dir/flags.make
CMakeFiles/ft_Ls.dir/srcs/ft_ls.c.o: ../srcs/ft_ls.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fameowner/ft_Ls/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/ft_Ls.dir/srcs/ft_ls.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ft_Ls.dir/srcs/ft_ls.c.o   -c /home/fameowner/ft_Ls/srcs/ft_ls.c

CMakeFiles/ft_Ls.dir/srcs/ft_ls.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ft_Ls.dir/srcs/ft_ls.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/fameowner/ft_Ls/srcs/ft_ls.c > CMakeFiles/ft_Ls.dir/srcs/ft_ls.c.i

CMakeFiles/ft_Ls.dir/srcs/ft_ls.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ft_Ls.dir/srcs/ft_ls.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/fameowner/ft_Ls/srcs/ft_ls.c -o CMakeFiles/ft_Ls.dir/srcs/ft_ls.c.s

CMakeFiles/ft_Ls.dir/srcs/ft_ls.c.o.requires:

.PHONY : CMakeFiles/ft_Ls.dir/srcs/ft_ls.c.o.requires

CMakeFiles/ft_Ls.dir/srcs/ft_ls.c.o.provides: CMakeFiles/ft_Ls.dir/srcs/ft_ls.c.o.requires
	$(MAKE) -f CMakeFiles/ft_Ls.dir/build.make CMakeFiles/ft_Ls.dir/srcs/ft_ls.c.o.provides.build
.PHONY : CMakeFiles/ft_Ls.dir/srcs/ft_ls.c.o.provides

CMakeFiles/ft_Ls.dir/srcs/ft_ls.c.o.provides.build: CMakeFiles/ft_Ls.dir/srcs/ft_ls.c.o


CMakeFiles/ft_Ls.dir/srcs/main.c.o: CMakeFiles/ft_Ls.dir/flags.make
CMakeFiles/ft_Ls.dir/srcs/main.c.o: ../srcs/main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fameowner/ft_Ls/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/ft_Ls.dir/srcs/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ft_Ls.dir/srcs/main.c.o   -c /home/fameowner/ft_Ls/srcs/main.c

CMakeFiles/ft_Ls.dir/srcs/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ft_Ls.dir/srcs/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/fameowner/ft_Ls/srcs/main.c > CMakeFiles/ft_Ls.dir/srcs/main.c.i

CMakeFiles/ft_Ls.dir/srcs/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ft_Ls.dir/srcs/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/fameowner/ft_Ls/srcs/main.c -o CMakeFiles/ft_Ls.dir/srcs/main.c.s

CMakeFiles/ft_Ls.dir/srcs/main.c.o.requires:

.PHONY : CMakeFiles/ft_Ls.dir/srcs/main.c.o.requires

CMakeFiles/ft_Ls.dir/srcs/main.c.o.provides: CMakeFiles/ft_Ls.dir/srcs/main.c.o.requires
	$(MAKE) -f CMakeFiles/ft_Ls.dir/build.make CMakeFiles/ft_Ls.dir/srcs/main.c.o.provides.build
.PHONY : CMakeFiles/ft_Ls.dir/srcs/main.c.o.provides

CMakeFiles/ft_Ls.dir/srcs/main.c.o.provides.build: CMakeFiles/ft_Ls.dir/srcs/main.c.o


CMakeFiles/ft_Ls.dir/srcs/main_part.c.o: CMakeFiles/ft_Ls.dir/flags.make
CMakeFiles/ft_Ls.dir/srcs/main_part.c.o: ../srcs/main_part.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fameowner/ft_Ls/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/ft_Ls.dir/srcs/main_part.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ft_Ls.dir/srcs/main_part.c.o   -c /home/fameowner/ft_Ls/srcs/main_part.c

CMakeFiles/ft_Ls.dir/srcs/main_part.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ft_Ls.dir/srcs/main_part.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/fameowner/ft_Ls/srcs/main_part.c > CMakeFiles/ft_Ls.dir/srcs/main_part.c.i

CMakeFiles/ft_Ls.dir/srcs/main_part.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ft_Ls.dir/srcs/main_part.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/fameowner/ft_Ls/srcs/main_part.c -o CMakeFiles/ft_Ls.dir/srcs/main_part.c.s

CMakeFiles/ft_Ls.dir/srcs/main_part.c.o.requires:

.PHONY : CMakeFiles/ft_Ls.dir/srcs/main_part.c.o.requires

CMakeFiles/ft_Ls.dir/srcs/main_part.c.o.provides: CMakeFiles/ft_Ls.dir/srcs/main_part.c.o.requires
	$(MAKE) -f CMakeFiles/ft_Ls.dir/build.make CMakeFiles/ft_Ls.dir/srcs/main_part.c.o.provides.build
.PHONY : CMakeFiles/ft_Ls.dir/srcs/main_part.c.o.provides

CMakeFiles/ft_Ls.dir/srcs/main_part.c.o.provides.build: CMakeFiles/ft_Ls.dir/srcs/main_part.c.o


CMakeFiles/ft_Ls.dir/srcs/manage_list_container.c.o: CMakeFiles/ft_Ls.dir/flags.make
CMakeFiles/ft_Ls.dir/srcs/manage_list_container.c.o: ../srcs/manage_list_container.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fameowner/ft_Ls/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/ft_Ls.dir/srcs/manage_list_container.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ft_Ls.dir/srcs/manage_list_container.c.o   -c /home/fameowner/ft_Ls/srcs/manage_list_container.c

CMakeFiles/ft_Ls.dir/srcs/manage_list_container.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ft_Ls.dir/srcs/manage_list_container.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/fameowner/ft_Ls/srcs/manage_list_container.c > CMakeFiles/ft_Ls.dir/srcs/manage_list_container.c.i

CMakeFiles/ft_Ls.dir/srcs/manage_list_container.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ft_Ls.dir/srcs/manage_list_container.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/fameowner/ft_Ls/srcs/manage_list_container.c -o CMakeFiles/ft_Ls.dir/srcs/manage_list_container.c.s

CMakeFiles/ft_Ls.dir/srcs/manage_list_container.c.o.requires:

.PHONY : CMakeFiles/ft_Ls.dir/srcs/manage_list_container.c.o.requires

CMakeFiles/ft_Ls.dir/srcs/manage_list_container.c.o.provides: CMakeFiles/ft_Ls.dir/srcs/manage_list_container.c.o.requires
	$(MAKE) -f CMakeFiles/ft_Ls.dir/build.make CMakeFiles/ft_Ls.dir/srcs/manage_list_container.c.o.provides.build
.PHONY : CMakeFiles/ft_Ls.dir/srcs/manage_list_container.c.o.provides

CMakeFiles/ft_Ls.dir/srcs/manage_list_container.c.o.provides.build: CMakeFiles/ft_Ls.dir/srcs/manage_list_container.c.o


CMakeFiles/ft_Ls.dir/srcs/parsing.c.o: CMakeFiles/ft_Ls.dir/flags.make
CMakeFiles/ft_Ls.dir/srcs/parsing.c.o: ../srcs/parsing.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fameowner/ft_Ls/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/ft_Ls.dir/srcs/parsing.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ft_Ls.dir/srcs/parsing.c.o   -c /home/fameowner/ft_Ls/srcs/parsing.c

CMakeFiles/ft_Ls.dir/srcs/parsing.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ft_Ls.dir/srcs/parsing.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/fameowner/ft_Ls/srcs/parsing.c > CMakeFiles/ft_Ls.dir/srcs/parsing.c.i

CMakeFiles/ft_Ls.dir/srcs/parsing.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ft_Ls.dir/srcs/parsing.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/fameowner/ft_Ls/srcs/parsing.c -o CMakeFiles/ft_Ls.dir/srcs/parsing.c.s

CMakeFiles/ft_Ls.dir/srcs/parsing.c.o.requires:

.PHONY : CMakeFiles/ft_Ls.dir/srcs/parsing.c.o.requires

CMakeFiles/ft_Ls.dir/srcs/parsing.c.o.provides: CMakeFiles/ft_Ls.dir/srcs/parsing.c.o.requires
	$(MAKE) -f CMakeFiles/ft_Ls.dir/build.make CMakeFiles/ft_Ls.dir/srcs/parsing.c.o.provides.build
.PHONY : CMakeFiles/ft_Ls.dir/srcs/parsing.c.o.provides

CMakeFiles/ft_Ls.dir/srcs/parsing.c.o.provides.build: CMakeFiles/ft_Ls.dir/srcs/parsing.c.o


CMakeFiles/ft_Ls.dir/srcs/print_container.c.o: CMakeFiles/ft_Ls.dir/flags.make
CMakeFiles/ft_Ls.dir/srcs/print_container.c.o: ../srcs/print_container.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fameowner/ft_Ls/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object CMakeFiles/ft_Ls.dir/srcs/print_container.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ft_Ls.dir/srcs/print_container.c.o   -c /home/fameowner/ft_Ls/srcs/print_container.c

CMakeFiles/ft_Ls.dir/srcs/print_container.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ft_Ls.dir/srcs/print_container.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/fameowner/ft_Ls/srcs/print_container.c > CMakeFiles/ft_Ls.dir/srcs/print_container.c.i

CMakeFiles/ft_Ls.dir/srcs/print_container.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ft_Ls.dir/srcs/print_container.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/fameowner/ft_Ls/srcs/print_container.c -o CMakeFiles/ft_Ls.dir/srcs/print_container.c.s

CMakeFiles/ft_Ls.dir/srcs/print_container.c.o.requires:

.PHONY : CMakeFiles/ft_Ls.dir/srcs/print_container.c.o.requires

CMakeFiles/ft_Ls.dir/srcs/print_container.c.o.provides: CMakeFiles/ft_Ls.dir/srcs/print_container.c.o.requires
	$(MAKE) -f CMakeFiles/ft_Ls.dir/build.make CMakeFiles/ft_Ls.dir/srcs/print_container.c.o.provides.build
.PHONY : CMakeFiles/ft_Ls.dir/srcs/print_container.c.o.provides

CMakeFiles/ft_Ls.dir/srcs/print_container.c.o.provides.build: CMakeFiles/ft_Ls.dir/srcs/print_container.c.o


CMakeFiles/ft_Ls.dir/srcs/sort_list.c.o: CMakeFiles/ft_Ls.dir/flags.make
CMakeFiles/ft_Ls.dir/srcs/sort_list.c.o: ../srcs/sort_list.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fameowner/ft_Ls/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object CMakeFiles/ft_Ls.dir/srcs/sort_list.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ft_Ls.dir/srcs/sort_list.c.o   -c /home/fameowner/ft_Ls/srcs/sort_list.c

CMakeFiles/ft_Ls.dir/srcs/sort_list.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ft_Ls.dir/srcs/sort_list.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/fameowner/ft_Ls/srcs/sort_list.c > CMakeFiles/ft_Ls.dir/srcs/sort_list.c.i

CMakeFiles/ft_Ls.dir/srcs/sort_list.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ft_Ls.dir/srcs/sort_list.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/fameowner/ft_Ls/srcs/sort_list.c -o CMakeFiles/ft_Ls.dir/srcs/sort_list.c.s

CMakeFiles/ft_Ls.dir/srcs/sort_list.c.o.requires:

.PHONY : CMakeFiles/ft_Ls.dir/srcs/sort_list.c.o.requires

CMakeFiles/ft_Ls.dir/srcs/sort_list.c.o.provides: CMakeFiles/ft_Ls.dir/srcs/sort_list.c.o.requires
	$(MAKE) -f CMakeFiles/ft_Ls.dir/build.make CMakeFiles/ft_Ls.dir/srcs/sort_list.c.o.provides.build
.PHONY : CMakeFiles/ft_Ls.dir/srcs/sort_list.c.o.provides

CMakeFiles/ft_Ls.dir/srcs/sort_list.c.o.provides.build: CMakeFiles/ft_Ls.dir/srcs/sort_list.c.o


# Object files for target ft_Ls
ft_Ls_OBJECTS = \
"CMakeFiles/ft_Ls.dir/srcs/flag_tools.c.o" \
"CMakeFiles/ft_Ls.dir/srcs/ft_ls.c.o" \
"CMakeFiles/ft_Ls.dir/srcs/main.c.o" \
"CMakeFiles/ft_Ls.dir/srcs/main_part.c.o" \
"CMakeFiles/ft_Ls.dir/srcs/manage_list_container.c.o" \
"CMakeFiles/ft_Ls.dir/srcs/parsing.c.o" \
"CMakeFiles/ft_Ls.dir/srcs/print_container.c.o" \
"CMakeFiles/ft_Ls.dir/srcs/sort_list.c.o"

# External object files for target ft_Ls
ft_Ls_EXTERNAL_OBJECTS =

ft_Ls: CMakeFiles/ft_Ls.dir/srcs/flag_tools.c.o
ft_Ls: CMakeFiles/ft_Ls.dir/srcs/ft_ls.c.o
ft_Ls: CMakeFiles/ft_Ls.dir/srcs/main.c.o
ft_Ls: CMakeFiles/ft_Ls.dir/srcs/main_part.c.o
ft_Ls: CMakeFiles/ft_Ls.dir/srcs/manage_list_container.c.o
ft_Ls: CMakeFiles/ft_Ls.dir/srcs/parsing.c.o
ft_Ls: CMakeFiles/ft_Ls.dir/srcs/print_container.c.o
ft_Ls: CMakeFiles/ft_Ls.dir/srcs/sort_list.c.o
ft_Ls: CMakeFiles/ft_Ls.dir/build.make
ft_Ls: CMakeFiles/ft_Ls.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/fameowner/ft_Ls/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Linking C executable ft_Ls"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ft_Ls.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ft_Ls.dir/build: ft_Ls

.PHONY : CMakeFiles/ft_Ls.dir/build

CMakeFiles/ft_Ls.dir/requires: CMakeFiles/ft_Ls.dir/srcs/flag_tools.c.o.requires
CMakeFiles/ft_Ls.dir/requires: CMakeFiles/ft_Ls.dir/srcs/ft_ls.c.o.requires
CMakeFiles/ft_Ls.dir/requires: CMakeFiles/ft_Ls.dir/srcs/main.c.o.requires
CMakeFiles/ft_Ls.dir/requires: CMakeFiles/ft_Ls.dir/srcs/main_part.c.o.requires
CMakeFiles/ft_Ls.dir/requires: CMakeFiles/ft_Ls.dir/srcs/manage_list_container.c.o.requires
CMakeFiles/ft_Ls.dir/requires: CMakeFiles/ft_Ls.dir/srcs/parsing.c.o.requires
CMakeFiles/ft_Ls.dir/requires: CMakeFiles/ft_Ls.dir/srcs/print_container.c.o.requires
CMakeFiles/ft_Ls.dir/requires: CMakeFiles/ft_Ls.dir/srcs/sort_list.c.o.requires

.PHONY : CMakeFiles/ft_Ls.dir/requires

CMakeFiles/ft_Ls.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ft_Ls.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ft_Ls.dir/clean

CMakeFiles/ft_Ls.dir/depend:
	cd /home/fameowner/ft_Ls/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/fameowner/ft_Ls /home/fameowner/ft_Ls /home/fameowner/ft_Ls/cmake-build-debug /home/fameowner/ft_Ls/cmake-build-debug /home/fameowner/ft_Ls/cmake-build-debug/CMakeFiles/ft_Ls.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ft_Ls.dir/depend
