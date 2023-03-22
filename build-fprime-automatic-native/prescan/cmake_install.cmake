# Install script for directory: /home/kokaze/fprime/Ref

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/kokaze/fprime/Ref/build-artifacts")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/usr/bin/objdump")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/kokaze/fprime/Ref/build-fprime-automatic-native/prescan/F-Prime/Autocoders/cmake_install.cmake")
  include("/home/kokaze/fprime/Ref/build-fprime-automatic-native/prescan/F-Prime/Fw/cmake_install.cmake")
  include("/home/kokaze/fprime/Ref/build-fprime-automatic-native/prescan/F-Prime/Svc/cmake_install.cmake")
  include("/home/kokaze/fprime/Ref/build-fprime-automatic-native/prescan/F-Prime/Os/cmake_install.cmake")
  include("/home/kokaze/fprime/Ref/build-fprime-automatic-native/prescan/F-Prime/Drv/cmake_install.cmake")
  include("/home/kokaze/fprime/Ref/build-fprime-automatic-native/prescan/F-Prime/CFDP/cmake_install.cmake")
  include("/home/kokaze/fprime/Ref/build-fprime-automatic-native/prescan/F-Prime/Utils/cmake_install.cmake")
  include("/home/kokaze/fprime/Ref/build-fprime-automatic-native/prescan/Ref/PingReceiver/cmake_install.cmake")
  include("/home/kokaze/fprime/Ref/build-fprime-automatic-native/prescan/Ref/RecvBuffApp/cmake_install.cmake")
  include("/home/kokaze/fprime/Ref/build-fprime-automatic-native/prescan/Ref/SendBuffApp/cmake_install.cmake")
  include("/home/kokaze/fprime/Ref/build-fprime-automatic-native/prescan/Ref/SignalGen/cmake_install.cmake")
  include("/home/kokaze/fprime/Ref/build-fprime-automatic-native/prescan/Ref/Control/cmake_install.cmake")
  include("/home/kokaze/fprime/Ref/build-fprime-automatic-native/prescan/Ref/DataType/cmake_install.cmake")
  include("/home/kokaze/fprime/Ref/build-fprime-automatic-native/prescan/Ref/SetSensorState/cmake_install.cmake")
  include("/home/kokaze/fprime/Ref/build-fprime-automatic-native/prescan/Ref/GetCtrlData/cmake_install.cmake")
  include("/home/kokaze/fprime/Ref/build-fprime-automatic-native/prescan/Ref/GetEnvData/cmake_install.cmake")
  include("/home/kokaze/fprime/Ref/build-fprime-automatic-native/prescan/Ref/ProcessData/cmake_install.cmake")
  include("/home/kokaze/fprime/Ref/build-fprime-automatic-native/prescan/Ref/ProcessInData/cmake_install.cmake")
  include("/home/kokaze/fprime/Ref/build-fprime-automatic-native/prescan/Ref/ProcessOutData/cmake_install.cmake")
  include("/home/kokaze/fprime/Ref/build-fprime-automatic-native/prescan/Ref/DoActions/cmake_install.cmake")
  include("/home/kokaze/fprime/Ref/build-fprime-automatic-native/prescan/Ref/ThrDistribute/cmake_install.cmake")
  include("/home/kokaze/fprime/Ref/build-fprime-automatic-native/prescan/Ref/ProtectFromSunlight/cmake_install.cmake")
  include("/home/kokaze/fprime/Ref/build-fprime-automatic-native/prescan/Ref/Top/cmake_install.cmake")

endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/home/kokaze/fprime/Ref/build-fprime-automatic-native/prescan/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
