# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/kokaze/fprime/Ref

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/kokaze/fprime/Ref/build-fprime-automatic-native

# Include any dependencies generated for this target.
include Ref/SetSensorState/CMakeFiles/Ref_SetSensorState.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include Ref/SetSensorState/CMakeFiles/Ref_SetSensorState.dir/compiler_depend.make

# Include the progress variables for this target.
include Ref/SetSensorState/CMakeFiles/Ref_SetSensorState.dir/progress.make

# Include the compile flags for this target's objects.
include Ref/SetSensorState/CMakeFiles/Ref_SetSensorState.dir/flags.make

Ref/SetSensorState/SetSensorStateComponentAc.hpp: Ref/SetSensorState/SetSensorStateComponentAi.xml
Ref/SetSensorState/SetSensorStateComponentAc.hpp: /home/kokaze/fprime/config/AcConstants.ini
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/kokaze/fprime/Ref/build-fprime-automatic-native/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating SetSensorStateComponentAc.hpp, SetSensorStateComponentAc.cpp"
	cd /home/kokaze/fprime/Ref/build-fprime-automatic-native/Ref/SetSensorState && /usr/bin/cmake -E env PYTHONPATH=/home/kokaze/fprime/Autocoders/Python/src:/home/kokaze/fprime/Autocoders/Python/utils BUILD_ROOT=/home/kokaze/fprime:/home/kokaze/fprime/Ref/build-fprime-automatic-native:/home/kokaze/fprime/Ref/build-fprime-automatic-native/F-Prime FPRIME_AC_CONSTANTS_FILE=/home/kokaze/fprime/config/AcConstants.ini PYTHON_AUTOCODER_DIR=/home/kokaze/fprime/Autocoders/Python /home/kokaze/anaconda3/envs/fprime-venv/bin/python3 /home/kokaze/fprime/Autocoders/Python/bin/codegen.py -p /home/kokaze/fprime/Ref/build-fprime-automatic-native/Ref/SetSensorState --build_root /home/kokaze/fprime/Ref/build-fprime-automatic-native/Ref/SetSensorState/SetSensorStateComponentAi.xml

Ref/SetSensorState/SetSensorStateComponentAc.cpp: Ref/SetSensorState/SetSensorStateComponentAc.hpp
	@$(CMAKE_COMMAND) -E touch_nocreate Ref/SetSensorState/SetSensorStateComponentAc.cpp

Ref/SetSensorState/SetSensorStatePortAc.hpp: Ref/SetSensorState/SetSensorStatePortAi.xml
Ref/SetSensorState/SetSensorStatePortAc.hpp: /home/kokaze/fprime/config/AcConstants.ini
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/kokaze/fprime/Ref/build-fprime-automatic-native/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Generating SetSensorStatePortAc.hpp, SetSensorStatePortAc.cpp"
	cd /home/kokaze/fprime/Ref/build-fprime-automatic-native/Ref/SetSensorState && /usr/bin/cmake -E env PYTHONPATH=/home/kokaze/fprime/Autocoders/Python/src:/home/kokaze/fprime/Autocoders/Python/utils BUILD_ROOT=/home/kokaze/fprime:/home/kokaze/fprime/Ref/build-fprime-automatic-native:/home/kokaze/fprime/Ref/build-fprime-automatic-native/F-Prime FPRIME_AC_CONSTANTS_FILE=/home/kokaze/fprime/config/AcConstants.ini PYTHON_AUTOCODER_DIR=/home/kokaze/fprime/Autocoders/Python /home/kokaze/anaconda3/envs/fprime-venv/bin/python3 /home/kokaze/fprime/Autocoders/Python/bin/codegen.py -p /home/kokaze/fprime/Ref/build-fprime-automatic-native/Ref/SetSensorState --build_root /home/kokaze/fprime/Ref/build-fprime-automatic-native/Ref/SetSensorState/SetSensorStatePortAi.xml

Ref/SetSensorState/SetSensorStatePortAc.cpp: Ref/SetSensorState/SetSensorStatePortAc.hpp
	@$(CMAKE_COMMAND) -E touch_nocreate Ref/SetSensorState/SetSensorStatePortAc.cpp

Ref/SetSensorState/SetSensorStateComponentAi.xml: ../SetSensorState/SetSensorState.fpp
Ref/SetSensorState/SetSensorStateComponentAi.xml: /home/kokaze/fprime/Fw/Log/Log.fpp
Ref/SetSensorState/SetSensorStateComponentAi.xml: /home/kokaze/fprime/Fw/Time/Time.fpp
Ref/SetSensorState/SetSensorStateComponentAi.xml: /home/kokaze/fprime/Fw/Tlm/Tlm.fpp
Ref/SetSensorState/SetSensorStateComponentAi.xml: ../DataType/DataType.fpp
Ref/SetSensorState/SetSensorStateComponentAi.xml: ../DoActions/DoActions.fpp
Ref/SetSensorState/SetSensorStateComponentAi.xml: ../GetCtrlData/GetCtrlData.fpp
Ref/SetSensorState/SetSensorStateComponentAi.xml: ../GetEnvData/GetEnvData.fpp
Ref/SetSensorState/SetSensorStateComponentAi.xml: ../ProcessData/ProcessData.fpp
Ref/SetSensorState/SetSensorStateComponentAi.xml: ../ProcessInData/ProcessInData.fpp
Ref/SetSensorState/SetSensorStateComponentAi.xml: ../ProcessOutData/ProcessOutData.fpp
Ref/SetSensorState/SetSensorStateComponentAi.xml: ../ProtectFromSunlight/ProtectFromSunlight.fpp
Ref/SetSensorState/SetSensorStateComponentAi.xml: ../ThrDistribute/ThrDistribute.fpp
Ref/SetSensorState/SetSensorStateComponentAi.xml: /home/kokaze/fprime/Svc/Sched/Sched.fpp
Ref/SetSensorState/SetSensorStateComponentAi.xml: /home/kokaze/fprime/config/FpConfig.fpp
Ref/SetSensorState/SetSensorStateComponentAi.xml: lib/Linux/libRef_DataType.a
Ref/SetSensorState/SetSensorStateComponentAi.xml: lib/Linux/libRef_DoActions.a
Ref/SetSensorState/SetSensorStateComponentAi.xml: lib/Linux/libRef_GetCtrlData.a
Ref/SetSensorState/SetSensorStateComponentAi.xml: lib/Linux/libRef_GetEnvData.a
Ref/SetSensorState/SetSensorStateComponentAi.xml: lib/Linux/libRef_ProcessData.a
Ref/SetSensorState/SetSensorStateComponentAi.xml: lib/Linux/libFw_Comp.a
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/kokaze/fprime/Ref/build-fprime-automatic-native/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Generating SetSensorStateComponentAi.xml, SetSensorStatePortAi.xml"
	cd /home/kokaze/fprime/Ref/build-fprime-automatic-native/Ref/SetSensorState && /home/kokaze/anaconda3/envs/fprime-venv/bin/fpp-to-xml -d /home/kokaze/fprime/Ref/build-fprime-automatic-native/Ref/SetSensorState /home/kokaze/fprime/Ref/SetSensorState/SetSensorState.fpp /home/kokaze/fprime/Fw/Log/Log.fpp /home/kokaze/fprime/Fw/Time/Time.fpp /home/kokaze/fprime/Fw/Tlm/Tlm.fpp /home/kokaze/fprime/Ref/DataType/DataType.fpp /home/kokaze/fprime/Ref/DoActions/DoActions.fpp /home/kokaze/fprime/Ref/GetCtrlData/GetCtrlData.fpp /home/kokaze/fprime/Ref/GetEnvData/GetEnvData.fpp /home/kokaze/fprime/Ref/ProcessData/ProcessData.fpp /home/kokaze/fprime/Ref/ProcessInData/ProcessInData.fpp /home/kokaze/fprime/Ref/ProcessOutData/ProcessOutData.fpp /home/kokaze/fprime/Ref/ProtectFromSunlight/ProtectFromSunlight.fpp /home/kokaze/fprime/Ref/ThrDistribute/ThrDistribute.fpp /home/kokaze/fprime/Svc/Sched/Sched.fpp /home/kokaze/fprime/config/FpConfig.fpp -p /home/kokaze/fprime

Ref/SetSensorState/SetSensorStatePortAi.xml: Ref/SetSensorState/SetSensorStateComponentAi.xml
	@$(CMAKE_COMMAND) -E touch_nocreate Ref/SetSensorState/SetSensorStatePortAi.xml

Ref/SetSensorState/CMakeFiles/Ref_SetSensorState.dir/SetSensorState.cpp.o: Ref/SetSensorState/CMakeFiles/Ref_SetSensorState.dir/flags.make
Ref/SetSensorState/CMakeFiles/Ref_SetSensorState.dir/SetSensorState.cpp.o: ../SetSensorState/SetSensorState.cpp
Ref/SetSensorState/CMakeFiles/Ref_SetSensorState.dir/SetSensorState.cpp.o: Ref/SetSensorState/CMakeFiles/Ref_SetSensorState.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kokaze/fprime/Ref/build-fprime-automatic-native/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object Ref/SetSensorState/CMakeFiles/Ref_SetSensorState.dir/SetSensorState.cpp.o"
	cd /home/kokaze/fprime/Ref/build-fprime-automatic-native/Ref/SetSensorState && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -DASSERT_FILE_ID="0x51f9fbe5" -MD -MT Ref/SetSensorState/CMakeFiles/Ref_SetSensorState.dir/SetSensorState.cpp.o -MF CMakeFiles/Ref_SetSensorState.dir/SetSensorState.cpp.o.d -o CMakeFiles/Ref_SetSensorState.dir/SetSensorState.cpp.o -c /home/kokaze/fprime/Ref/SetSensorState/SetSensorState.cpp

Ref/SetSensorState/CMakeFiles/Ref_SetSensorState.dir/SetSensorState.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Ref_SetSensorState.dir/SetSensorState.cpp.i"
	cd /home/kokaze/fprime/Ref/build-fprime-automatic-native/Ref/SetSensorState && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -DASSERT_FILE_ID="0x51f9fbe5" -E /home/kokaze/fprime/Ref/SetSensorState/SetSensorState.cpp > CMakeFiles/Ref_SetSensorState.dir/SetSensorState.cpp.i

Ref/SetSensorState/CMakeFiles/Ref_SetSensorState.dir/SetSensorState.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Ref_SetSensorState.dir/SetSensorState.cpp.s"
	cd /home/kokaze/fprime/Ref/build-fprime-automatic-native/Ref/SetSensorState && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -DASSERT_FILE_ID="0x51f9fbe5" -S /home/kokaze/fprime/Ref/SetSensorState/SetSensorState.cpp -o CMakeFiles/Ref_SetSensorState.dir/SetSensorState.cpp.s

Ref/SetSensorState/CMakeFiles/Ref_SetSensorState.dir/__/tools/SetSensor/SetSensor.cpp.o: Ref/SetSensorState/CMakeFiles/Ref_SetSensorState.dir/flags.make
Ref/SetSensorState/CMakeFiles/Ref_SetSensorState.dir/__/tools/SetSensor/SetSensor.cpp.o: ../tools/SetSensor/SetSensor.cpp
Ref/SetSensorState/CMakeFiles/Ref_SetSensorState.dir/__/tools/SetSensor/SetSensor.cpp.o: Ref/SetSensorState/CMakeFiles/Ref_SetSensorState.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kokaze/fprime/Ref/build-fprime-automatic-native/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object Ref/SetSensorState/CMakeFiles/Ref_SetSensorState.dir/__/tools/SetSensor/SetSensor.cpp.o"
	cd /home/kokaze/fprime/Ref/build-fprime-automatic-native/Ref/SetSensorState && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -DASSERT_FILE_ID="0x817c7b9a" -MD -MT Ref/SetSensorState/CMakeFiles/Ref_SetSensorState.dir/__/tools/SetSensor/SetSensor.cpp.o -MF CMakeFiles/Ref_SetSensorState.dir/__/tools/SetSensor/SetSensor.cpp.o.d -o CMakeFiles/Ref_SetSensorState.dir/__/tools/SetSensor/SetSensor.cpp.o -c /home/kokaze/fprime/Ref/tools/SetSensor/SetSensor.cpp

Ref/SetSensorState/CMakeFiles/Ref_SetSensorState.dir/__/tools/SetSensor/SetSensor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Ref_SetSensorState.dir/__/tools/SetSensor/SetSensor.cpp.i"
	cd /home/kokaze/fprime/Ref/build-fprime-automatic-native/Ref/SetSensorState && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -DASSERT_FILE_ID="0x817c7b9a" -E /home/kokaze/fprime/Ref/tools/SetSensor/SetSensor.cpp > CMakeFiles/Ref_SetSensorState.dir/__/tools/SetSensor/SetSensor.cpp.i

Ref/SetSensorState/CMakeFiles/Ref_SetSensorState.dir/__/tools/SetSensor/SetSensor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Ref_SetSensorState.dir/__/tools/SetSensor/SetSensor.cpp.s"
	cd /home/kokaze/fprime/Ref/build-fprime-automatic-native/Ref/SetSensorState && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -DASSERT_FILE_ID="0x817c7b9a" -S /home/kokaze/fprime/Ref/tools/SetSensor/SetSensor.cpp -o CMakeFiles/Ref_SetSensorState.dir/__/tools/SetSensor/SetSensor.cpp.s

Ref/SetSensorState/CMakeFiles/Ref_SetSensorState.dir/SetSensorStateComponentAc.cpp.o: Ref/SetSensorState/CMakeFiles/Ref_SetSensorState.dir/flags.make
Ref/SetSensorState/CMakeFiles/Ref_SetSensorState.dir/SetSensorStateComponentAc.cpp.o: Ref/SetSensorState/SetSensorStateComponentAc.cpp
Ref/SetSensorState/CMakeFiles/Ref_SetSensorState.dir/SetSensorStateComponentAc.cpp.o: Ref/SetSensorState/CMakeFiles/Ref_SetSensorState.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kokaze/fprime/Ref/build-fprime-automatic-native/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object Ref/SetSensorState/CMakeFiles/Ref_SetSensorState.dir/SetSensorStateComponentAc.cpp.o"
	cd /home/kokaze/fprime/Ref/build-fprime-automatic-native/Ref/SetSensorState && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -DASSERT_FILE_ID="0x2ff50dd8" -MD -MT Ref/SetSensorState/CMakeFiles/Ref_SetSensorState.dir/SetSensorStateComponentAc.cpp.o -MF CMakeFiles/Ref_SetSensorState.dir/SetSensorStateComponentAc.cpp.o.d -o CMakeFiles/Ref_SetSensorState.dir/SetSensorStateComponentAc.cpp.o -c /home/kokaze/fprime/Ref/build-fprime-automatic-native/Ref/SetSensorState/SetSensorStateComponentAc.cpp

Ref/SetSensorState/CMakeFiles/Ref_SetSensorState.dir/SetSensorStateComponentAc.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Ref_SetSensorState.dir/SetSensorStateComponentAc.cpp.i"
	cd /home/kokaze/fprime/Ref/build-fprime-automatic-native/Ref/SetSensorState && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -DASSERT_FILE_ID="0x2ff50dd8" -E /home/kokaze/fprime/Ref/build-fprime-automatic-native/Ref/SetSensorState/SetSensorStateComponentAc.cpp > CMakeFiles/Ref_SetSensorState.dir/SetSensorStateComponentAc.cpp.i

Ref/SetSensorState/CMakeFiles/Ref_SetSensorState.dir/SetSensorStateComponentAc.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Ref_SetSensorState.dir/SetSensorStateComponentAc.cpp.s"
	cd /home/kokaze/fprime/Ref/build-fprime-automatic-native/Ref/SetSensorState && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -DASSERT_FILE_ID="0x2ff50dd8" -S /home/kokaze/fprime/Ref/build-fprime-automatic-native/Ref/SetSensorState/SetSensorStateComponentAc.cpp -o CMakeFiles/Ref_SetSensorState.dir/SetSensorStateComponentAc.cpp.s

Ref/SetSensorState/CMakeFiles/Ref_SetSensorState.dir/SetSensorStatePortAc.cpp.o: Ref/SetSensorState/CMakeFiles/Ref_SetSensorState.dir/flags.make
Ref/SetSensorState/CMakeFiles/Ref_SetSensorState.dir/SetSensorStatePortAc.cpp.o: Ref/SetSensorState/SetSensorStatePortAc.cpp
Ref/SetSensorState/CMakeFiles/Ref_SetSensorState.dir/SetSensorStatePortAc.cpp.o: Ref/SetSensorState/CMakeFiles/Ref_SetSensorState.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kokaze/fprime/Ref/build-fprime-automatic-native/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object Ref/SetSensorState/CMakeFiles/Ref_SetSensorState.dir/SetSensorStatePortAc.cpp.o"
	cd /home/kokaze/fprime/Ref/build-fprime-automatic-native/Ref/SetSensorState && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -DASSERT_FILE_ID="0xaf9b1ed6" -MD -MT Ref/SetSensorState/CMakeFiles/Ref_SetSensorState.dir/SetSensorStatePortAc.cpp.o -MF CMakeFiles/Ref_SetSensorState.dir/SetSensorStatePortAc.cpp.o.d -o CMakeFiles/Ref_SetSensorState.dir/SetSensorStatePortAc.cpp.o -c /home/kokaze/fprime/Ref/build-fprime-automatic-native/Ref/SetSensorState/SetSensorStatePortAc.cpp

Ref/SetSensorState/CMakeFiles/Ref_SetSensorState.dir/SetSensorStatePortAc.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Ref_SetSensorState.dir/SetSensorStatePortAc.cpp.i"
	cd /home/kokaze/fprime/Ref/build-fprime-automatic-native/Ref/SetSensorState && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -DASSERT_FILE_ID="0xaf9b1ed6" -E /home/kokaze/fprime/Ref/build-fprime-automatic-native/Ref/SetSensorState/SetSensorStatePortAc.cpp > CMakeFiles/Ref_SetSensorState.dir/SetSensorStatePortAc.cpp.i

Ref/SetSensorState/CMakeFiles/Ref_SetSensorState.dir/SetSensorStatePortAc.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Ref_SetSensorState.dir/SetSensorStatePortAc.cpp.s"
	cd /home/kokaze/fprime/Ref/build-fprime-automatic-native/Ref/SetSensorState && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -DASSERT_FILE_ID="0xaf9b1ed6" -S /home/kokaze/fprime/Ref/build-fprime-automatic-native/Ref/SetSensorState/SetSensorStatePortAc.cpp -o CMakeFiles/Ref_SetSensorState.dir/SetSensorStatePortAc.cpp.s

# Object files for target Ref_SetSensorState
Ref_SetSensorState_OBJECTS = \
"CMakeFiles/Ref_SetSensorState.dir/SetSensorState.cpp.o" \
"CMakeFiles/Ref_SetSensorState.dir/__/tools/SetSensor/SetSensor.cpp.o" \
"CMakeFiles/Ref_SetSensorState.dir/SetSensorStateComponentAc.cpp.o" \
"CMakeFiles/Ref_SetSensorState.dir/SetSensorStatePortAc.cpp.o"

# External object files for target Ref_SetSensorState
Ref_SetSensorState_EXTERNAL_OBJECTS =

lib/Linux/libRef_SetSensorState.a: Ref/SetSensorState/CMakeFiles/Ref_SetSensorState.dir/SetSensorState.cpp.o
lib/Linux/libRef_SetSensorState.a: Ref/SetSensorState/CMakeFiles/Ref_SetSensorState.dir/__/tools/SetSensor/SetSensor.cpp.o
lib/Linux/libRef_SetSensorState.a: Ref/SetSensorState/CMakeFiles/Ref_SetSensorState.dir/SetSensorStateComponentAc.cpp.o
lib/Linux/libRef_SetSensorState.a: Ref/SetSensorState/CMakeFiles/Ref_SetSensorState.dir/SetSensorStatePortAc.cpp.o
lib/Linux/libRef_SetSensorState.a: Ref/SetSensorState/CMakeFiles/Ref_SetSensorState.dir/build.make
lib/Linux/libRef_SetSensorState.a: Ref/SetSensorState/CMakeFiles/Ref_SetSensorState.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/kokaze/fprime/Ref/build-fprime-automatic-native/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX static library ../../lib/Linux/libRef_SetSensorState.a"
	cd /home/kokaze/fprime/Ref/build-fprime-automatic-native/Ref/SetSensorState && $(CMAKE_COMMAND) -P CMakeFiles/Ref_SetSensorState.dir/cmake_clean_target.cmake
	cd /home/kokaze/fprime/Ref/build-fprime-automatic-native/Ref/SetSensorState && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Ref_SetSensorState.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Ref/SetSensorState/CMakeFiles/Ref_SetSensorState.dir/build: lib/Linux/libRef_SetSensorState.a
.PHONY : Ref/SetSensorState/CMakeFiles/Ref_SetSensorState.dir/build

Ref/SetSensorState/CMakeFiles/Ref_SetSensorState.dir/clean:
	cd /home/kokaze/fprime/Ref/build-fprime-automatic-native/Ref/SetSensorState && $(CMAKE_COMMAND) -P CMakeFiles/Ref_SetSensorState.dir/cmake_clean.cmake
.PHONY : Ref/SetSensorState/CMakeFiles/Ref_SetSensorState.dir/clean

Ref/SetSensorState/CMakeFiles/Ref_SetSensorState.dir/depend: Ref/SetSensorState/SetSensorStateComponentAc.cpp
Ref/SetSensorState/CMakeFiles/Ref_SetSensorState.dir/depend: Ref/SetSensorState/SetSensorStateComponentAc.hpp
Ref/SetSensorState/CMakeFiles/Ref_SetSensorState.dir/depend: Ref/SetSensorState/SetSensorStateComponentAi.xml
Ref/SetSensorState/CMakeFiles/Ref_SetSensorState.dir/depend: Ref/SetSensorState/SetSensorStatePortAc.cpp
Ref/SetSensorState/CMakeFiles/Ref_SetSensorState.dir/depend: Ref/SetSensorState/SetSensorStatePortAc.hpp
Ref/SetSensorState/CMakeFiles/Ref_SetSensorState.dir/depend: Ref/SetSensorState/SetSensorStatePortAi.xml
	cd /home/kokaze/fprime/Ref/build-fprime-automatic-native && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kokaze/fprime/Ref /home/kokaze/fprime/Ref/SetSensorState /home/kokaze/fprime/Ref/build-fprime-automatic-native /home/kokaze/fprime/Ref/build-fprime-automatic-native/Ref/SetSensorState /home/kokaze/fprime/Ref/build-fprime-automatic-native/Ref/SetSensorState/CMakeFiles/Ref_SetSensorState.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Ref/SetSensorState/CMakeFiles/Ref_SetSensorState.dir/depend
