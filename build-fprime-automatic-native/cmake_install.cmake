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

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/Linux/bin/Ref" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/Linux/bin/Ref")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/Linux/bin/Ref"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/Linux/bin" TYPE EXECUTABLE FILES "/home/kokaze/fprime/Ref/build-fprime-automatic-native/bin/Linux/Ref")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/Linux/bin/Ref" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/Linux/bin/Ref")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/Linux/bin/Ref")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/Linux/lib/static" TYPE STATIC_LIBRARY FILES "/home/kokaze/fprime/Ref/build-fprime-automatic-native/lib/Linux/libFw_Cfg.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/Linux/lib/static" TYPE STATIC_LIBRARY FILES "/home/kokaze/fprime/Ref/build-fprime-automatic-native/lib/Linux/libFw_Types.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/Linux/lib/static" TYPE STATIC_LIBRARY FILES "/home/kokaze/fprime/Ref/build-fprime-automatic-native/lib/Linux/libFw_Logger.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/Linux/lib/static" TYPE STATIC_LIBRARY FILES "/home/kokaze/fprime/Ref/build-fprime-automatic-native/lib/Linux/libFw_Obj.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/Linux/lib/static" TYPE STATIC_LIBRARY FILES "/home/kokaze/fprime/Ref/build-fprime-automatic-native/lib/Linux/libFw_Port.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/Linux/lib/static" TYPE STATIC_LIBRARY FILES "/home/kokaze/fprime/Ref/build-fprime-automatic-native/lib/Linux/libFw_Time.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/Linux/lib/static" TYPE STATIC_LIBRARY FILES "/home/kokaze/fprime/Ref/build-fprime-automatic-native/lib/Linux/libFw_Comp.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/Linux/lib/static" TYPE STATIC_LIBRARY FILES "/home/kokaze/fprime/Ref/build-fprime-automatic-native/lib/Linux/libSvc_Time.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/Linux/lib/static" TYPE STATIC_LIBRARY FILES "/home/kokaze/fprime/Ref/build-fprime-automatic-native/lib/Linux/libSvc_LinuxTime.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/Linux/lib/static" TYPE STATIC_LIBRARY FILES "/home/kokaze/fprime/Ref/build-fprime-automatic-native/lib/Linux/libFw_Com.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/Linux/lib/static" TYPE STATIC_LIBRARY FILES "/home/kokaze/fprime/Ref/build-fprime-automatic-native/lib/Linux/libFw_Tlm.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/Linux/lib/static" TYPE STATIC_LIBRARY FILES "/home/kokaze/fprime/Ref/build-fprime-automatic-native/lib/Linux/libFw_Log.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/Linux/lib/static" TYPE STATIC_LIBRARY FILES "/home/kokaze/fprime/Ref/build-fprime-automatic-native/lib/Linux/libFw_Cmd.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/Linux/lib/static" TYPE STATIC_LIBRARY FILES "/home/kokaze/fprime/Ref/build-fprime-automatic-native/lib/Linux/libFw_Prm.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/Linux/lib/static" TYPE STATIC_LIBRARY FILES "/home/kokaze/fprime/Ref/build-fprime-automatic-native/lib/Linux/libFw_Buffer.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/Linux/lib/static" TYPE STATIC_LIBRARY FILES "/home/kokaze/fprime/Ref/build-fprime-automatic-native/lib/Linux/libUtils_Hash.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/Linux/lib/static" TYPE STATIC_LIBRARY FILES "/home/kokaze/fprime/Ref/build-fprime-automatic-native/lib/Linux/libOs.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/Linux/lib/static" TYPE STATIC_LIBRARY FILES "/home/kokaze/fprime/Ref/build-fprime-automatic-native/lib/Linux/libDrv_ByteStreamDriverModel.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/Linux/lib/static" TYPE STATIC_LIBRARY FILES "/home/kokaze/fprime/Ref/build-fprime-automatic-native/lib/Linux/libDrv_Ip.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/Linux/lib/static" TYPE STATIC_LIBRARY FILES "/home/kokaze/fprime/Ref/build-fprime-automatic-native/lib/Linux/libDrv_Udp.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/Linux/lib/static" TYPE STATIC_LIBRARY FILES "/home/kokaze/fprime/Ref/build-fprime-automatic-native/lib/Linux/libDrv_TcpClient.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/Linux/lib/static" TYPE STATIC_LIBRARY FILES "/home/kokaze/fprime/Ref/build-fprime-automatic-native/lib/Linux/libDrv_DataTypes.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/Linux/lib/static" TYPE STATIC_LIBRARY FILES "/home/kokaze/fprime/Ref/build-fprime-automatic-native/lib/Linux/libSvc_Cycle.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/Linux/lib/static" TYPE STATIC_LIBRARY FILES "/home/kokaze/fprime/Ref/build-fprime-automatic-native/lib/Linux/libSvc_Ping.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/Linux/lib/static" TYPE STATIC_LIBRARY FILES "/home/kokaze/fprime/Ref/build-fprime-automatic-native/lib/Linux/libSvc_Sched.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/Linux/lib/static" TYPE STATIC_LIBRARY FILES "/home/kokaze/fprime/Ref/build-fprime-automatic-native/lib/Linux/libFw_CompQueued.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/Linux/lib/static" TYPE STATIC_LIBRARY FILES "/home/kokaze/fprime/Ref/build-fprime-automatic-native/lib/Linux/libDrv_BlockDriver.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/Linux/lib/static" TYPE STATIC_LIBRARY FILES "/home/kokaze/fprime/Ref/build-fprime-automatic-native/lib/Linux/libRef_DataType.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/Linux/lib/static" TYPE STATIC_LIBRARY FILES "/home/kokaze/fprime/Ref/build-fprime-automatic-native/lib/Linux/libRef_ProtectFromSunlight.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/Linux/lib/static" TYPE STATIC_LIBRARY FILES "/home/kokaze/fprime/Ref/build-fprime-automatic-native/lib/Linux/libRef_ThrDistribute.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/Linux/lib/static" TYPE STATIC_LIBRARY FILES "/home/kokaze/fprime/Ref/build-fprime-automatic-native/lib/Linux/libRef_DoActions.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/Linux/lib/static" TYPE STATIC_LIBRARY FILES "/home/kokaze/fprime/Ref/build-fprime-automatic-native/lib/Linux/libRef_GetCtrlData.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/Linux/lib/static" TYPE STATIC_LIBRARY FILES "/home/kokaze/fprime/Ref/build-fprime-automatic-native/lib/Linux/libRef_GetEnvData.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/Linux/lib/static" TYPE STATIC_LIBRARY FILES "/home/kokaze/fprime/Ref/build-fprime-automatic-native/lib/Linux/libRef_ProcessInData.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/Linux/lib/static" TYPE STATIC_LIBRARY FILES "/home/kokaze/fprime/Ref/build-fprime-automatic-native/lib/Linux/libRef_ProcessOutData.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/Linux/lib/static" TYPE STATIC_LIBRARY FILES "/home/kokaze/fprime/Ref/build-fprime-automatic-native/lib/Linux/libRef_ProcessData.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/Linux/lib/static" TYPE STATIC_LIBRARY FILES "/home/kokaze/fprime/Ref/build-fprime-automatic-native/lib/Linux/libRef_SetSensorState.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/Linux/lib/static" TYPE STATIC_LIBRARY FILES "/home/kokaze/fprime/Ref/build-fprime-automatic-native/lib/Linux/libRef_Control.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/Linux/lib/static" TYPE STATIC_LIBRARY FILES "/home/kokaze/fprime/Ref/build-fprime-automatic-native/lib/Linux/libRef_PingReceiver.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/Linux/lib/static" TYPE STATIC_LIBRARY FILES "/home/kokaze/fprime/Ref/build-fprime-automatic-native/lib/Linux/libRef_RecvBuffApp.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/Linux/lib/static" TYPE STATIC_LIBRARY FILES "/home/kokaze/fprime/Ref/build-fprime-automatic-native/lib/Linux/libRef_SendBuffApp.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/Linux/lib/static" TYPE STATIC_LIBRARY FILES "/home/kokaze/fprime/Ref/build-fprime-automatic-native/lib/Linux/libRef_SignalGen.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/Linux/lib/static" TYPE STATIC_LIBRARY FILES "/home/kokaze/fprime/Ref/build-fprime-automatic-native/lib/Linux/libSvc_Fatal.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/Linux/lib/static" TYPE STATIC_LIBRARY FILES "/home/kokaze/fprime/Ref/build-fprime-automatic-native/lib/Linux/libSvc_ActiveLogger.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/Linux/lib/static" TYPE STATIC_LIBRARY FILES "/home/kokaze/fprime/Ref/build-fprime-automatic-native/lib/Linux/libSvc_ActiveRateGroup.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/Linux/lib/static" TYPE STATIC_LIBRARY FILES "/home/kokaze/fprime/Ref/build-fprime-automatic-native/lib/Linux/libSvc_AssertFatalAdapter.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/Linux/lib/static" TYPE STATIC_LIBRARY FILES "/home/kokaze/fprime/Ref/build-fprime-automatic-native/lib/Linux/libSvc_BufferManager.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/Linux/lib/static" TYPE STATIC_LIBRARY FILES "/home/kokaze/fprime/Ref/build-fprime-automatic-native/lib/Linux/libSvc_CmdDispatcher.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/Linux/lib/static" TYPE STATIC_LIBRARY FILES "/home/kokaze/fprime/Ref/build-fprime-automatic-native/lib/Linux/libSvc_Seq.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/Linux/lib/static" TYPE STATIC_LIBRARY FILES "/home/kokaze/fprime/Ref/build-fprime-automatic-native/lib/Linux/libSvc_CmdSequencer.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/Linux/lib/static" TYPE STATIC_LIBRARY FILES "/home/kokaze/fprime/Ref/build-fprime-automatic-native/lib/Linux/libUtils_Types.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/Linux/lib/static" TYPE STATIC_LIBRARY FILES "/home/kokaze/fprime/Ref/build-fprime-automatic-native/lib/Linux/libSvc_FramingProtocol.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/Linux/lib/static" TYPE STATIC_LIBRARY FILES "/home/kokaze/fprime/Ref/build-fprime-automatic-native/lib/Linux/libSvc_Deframer.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/Linux/lib/static" TYPE STATIC_LIBRARY FILES "/home/kokaze/fprime/Ref/build-fprime-automatic-native/lib/Linux/libSvc_FatalHandler.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/Linux/lib/static" TYPE STATIC_LIBRARY FILES "/home/kokaze/fprime/Ref/build-fprime-automatic-native/lib/Linux/libCFDP_Checksum.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/Linux/lib/static" TYPE STATIC_LIBRARY FILES "/home/kokaze/fprime/Ref/build-fprime-automatic-native/lib/Linux/libFw_FilePacket.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/Linux/lib/static" TYPE STATIC_LIBRARY FILES "/home/kokaze/fprime/Ref/build-fprime-automatic-native/lib/Linux/libSvc_FileDownlinkPorts.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/Linux/lib/static" TYPE STATIC_LIBRARY FILES "/home/kokaze/fprime/Ref/build-fprime-automatic-native/lib/Linux/libSvc_FileDownlink.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/Linux/lib/static" TYPE STATIC_LIBRARY FILES "/home/kokaze/fprime/Ref/build-fprime-automatic-native/lib/Linux/libSvc_FileManager.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/Linux/lib/static" TYPE STATIC_LIBRARY FILES "/home/kokaze/fprime/Ref/build-fprime-automatic-native/lib/Linux/libSvc_FileUplink.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/Linux/lib/static" TYPE STATIC_LIBRARY FILES "/home/kokaze/fprime/Ref/build-fprime-automatic-native/lib/Linux/libSvc_Framer.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/Linux/lib/static" TYPE STATIC_LIBRARY FILES "/home/kokaze/fprime/Ref/build-fprime-automatic-native/lib/Linux/libSvc_WatchDog.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/Linux/lib/static" TYPE STATIC_LIBRARY FILES "/home/kokaze/fprime/Ref/build-fprime-automatic-native/lib/Linux/libSvc_Health.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/Linux/lib/static" TYPE STATIC_LIBRARY FILES "/home/kokaze/fprime/Ref/build-fprime-automatic-native/lib/Linux/libSvc_PassiveConsoleTextLogger.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/Linux/lib/static" TYPE STATIC_LIBRARY FILES "/home/kokaze/fprime/Ref/build-fprime-automatic-native/lib/Linux/libSvc_PrmDb.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/Linux/lib/static" TYPE STATIC_LIBRARY FILES "/home/kokaze/fprime/Ref/build-fprime-automatic-native/lib/Linux/libSvc_RateGroupDriver.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/Linux/lib/static" TYPE STATIC_LIBRARY FILES "/home/kokaze/fprime/Ref/build-fprime-automatic-native/lib/Linux/libSvc_StaticMemory.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/Linux/lib/static" TYPE STATIC_LIBRARY FILES "/home/kokaze/fprime/Ref/build-fprime-automatic-native/lib/Linux/libSvc_SystemResources.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/Linux/lib/static" TYPE STATIC_LIBRARY FILES "/home/kokaze/fprime/Ref/build-fprime-automatic-native/lib/Linux/libSvc_TlmChan.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/Linux/lib/static" TYPE STATIC_LIBRARY FILES "/home/kokaze/fprime/Ref/build-fprime-automatic-native/lib/Linux/libRef_Top.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/Linux/dict" TYPE FILE FILES "/home/kokaze/fprime/Ref/build-fprime-automatic-native/Ref/Top/RefTopologyAppDictionary.xml")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/kokaze/fprime/Ref/build-fprime-automatic-native/F-Prime/Autocoders/cmake_install.cmake")
  include("/home/kokaze/fprime/Ref/build-fprime-automatic-native/F-Prime/Fw/cmake_install.cmake")
  include("/home/kokaze/fprime/Ref/build-fprime-automatic-native/F-Prime/Svc/cmake_install.cmake")
  include("/home/kokaze/fprime/Ref/build-fprime-automatic-native/F-Prime/Os/cmake_install.cmake")
  include("/home/kokaze/fprime/Ref/build-fprime-automatic-native/F-Prime/Drv/cmake_install.cmake")
  include("/home/kokaze/fprime/Ref/build-fprime-automatic-native/F-Prime/CFDP/cmake_install.cmake")
  include("/home/kokaze/fprime/Ref/build-fprime-automatic-native/F-Prime/Utils/cmake_install.cmake")
  include("/home/kokaze/fprime/Ref/build-fprime-automatic-native/Ref/PingReceiver/cmake_install.cmake")
  include("/home/kokaze/fprime/Ref/build-fprime-automatic-native/Ref/RecvBuffApp/cmake_install.cmake")
  include("/home/kokaze/fprime/Ref/build-fprime-automatic-native/Ref/SendBuffApp/cmake_install.cmake")
  include("/home/kokaze/fprime/Ref/build-fprime-automatic-native/Ref/SignalGen/cmake_install.cmake")
  include("/home/kokaze/fprime/Ref/build-fprime-automatic-native/Ref/Control/cmake_install.cmake")
  include("/home/kokaze/fprime/Ref/build-fprime-automatic-native/Ref/DataType/cmake_install.cmake")
  include("/home/kokaze/fprime/Ref/build-fprime-automatic-native/Ref/SetSensorState/cmake_install.cmake")
  include("/home/kokaze/fprime/Ref/build-fprime-automatic-native/Ref/GetCtrlData/cmake_install.cmake")
  include("/home/kokaze/fprime/Ref/build-fprime-automatic-native/Ref/GetEnvData/cmake_install.cmake")
  include("/home/kokaze/fprime/Ref/build-fprime-automatic-native/Ref/ProcessData/cmake_install.cmake")
  include("/home/kokaze/fprime/Ref/build-fprime-automatic-native/Ref/ProcessInData/cmake_install.cmake")
  include("/home/kokaze/fprime/Ref/build-fprime-automatic-native/Ref/ProcessOutData/cmake_install.cmake")
  include("/home/kokaze/fprime/Ref/build-fprime-automatic-native/Ref/DoActions/cmake_install.cmake")
  include("/home/kokaze/fprime/Ref/build-fprime-automatic-native/Ref/ThrDistribute/cmake_install.cmake")
  include("/home/kokaze/fprime/Ref/build-fprime-automatic-native/Ref/ProtectFromSunlight/cmake_install.cmake")
  include("/home/kokaze/fprime/Ref/build-fprime-automatic-native/Ref/Top/cmake_install.cmake")

endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/home/kokaze/fprime/Ref/build-fprime-automatic-native/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
