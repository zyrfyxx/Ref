// ======================================================================
// \title  ProcessInDataComponentAc.cpp
// \author Auto-generated
// \brief  cpp file for ProcessInData component base class
//
// NOTE: this file was automatically generated
//
// ======================================================================

#include <cstdio>
#include <FpConfig.hpp>
#include <Ref/ProcessInData/ProcessInDataComponentAc.hpp>
#include <Fw/Types/Assert.hpp>
#if FW_ENABLE_TEXT_LOGGING
#include <Fw/Types/String.hpp>
#endif


namespace Ref {

  // ----------------------------------------------------------------------
  // Getters for numbers of input ports
  // ----------------------------------------------------------------------

  Ref::InputProcessInDataPort *ProcessInDataComponentBase ::
    get_processInDataIn_InputPort(NATIVE_INT_TYPE portNum)
  {
    FW_ASSERT(portNum < this->getNum_processInDataIn_InputPorts(),static_cast<AssertArg>(portNum));
    return &this->m_processInDataIn_InputPort[portNum];
  }

  // ----------------------------------------------------------------------
  // Typed connectors for output ports
  // ----------------------------------------------------------------------

  void ProcessInDataComponentBase ::
    set_eventOut_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputLogPort* port
    )
  {
    FW_ASSERT(portNum < this->getNum_eventOut_OutputPorts(),static_cast<AssertArg>(portNum));
    this->m_eventOut_OutputPort[portNum].addCallPort(port);
  }

#if FW_ENABLE_TEXT_LOGGING == 1
  void ProcessInDataComponentBase ::
    set_textEventOut_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputLogTextPort* port
    )
  {
    FW_ASSERT(portNum < this->getNum_textEventOut_OutputPorts(),static_cast<AssertArg>(portNum));
    this->m_textEventOut_OutputPort[portNum].addCallPort(port);
  }
#endif

  void ProcessInDataComponentBase ::
    set_timeGetOut_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputTimePort* port
    )
  {
    FW_ASSERT(portNum < this->getNum_timeGetOut_OutputPorts(),static_cast<AssertArg>(portNum));
    this->m_timeGetOut_OutputPort[portNum].addCallPort(port);
  }

  void ProcessInDataComponentBase ::
    set_tlmOut_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputTlmPort* port
    )
  {
    FW_ASSERT(portNum < this->getNum_tlmOut_OutputPorts(),static_cast<AssertArg>(portNum));
    this->m_tlmOut_OutputPort[portNum].addCallPort(port);
  }

  // ----------------------------------------------------------------------
  // Serialization connectors for output ports
  // ----------------------------------------------------------------------

#if FW_PORT_SERIALIZATION

  void ProcessInDataComponentBase ::
    set_eventOut_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputSerializePort *port
    )
  {
    FW_ASSERT(portNum < this->getNum_eventOut_OutputPorts(),static_cast<AssertArg>(portNum));
    return this->m_eventOut_OutputPort[portNum].registerSerialPort(port);
  }

#if FW_ENABLE_TEXT_LOGGING == 1
  void ProcessInDataComponentBase ::
    set_textEventOut_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputSerializePort *port
    )
  {
    FW_ASSERT(portNum < this->getNum_textEventOut_OutputPorts(),static_cast<AssertArg>(portNum));
    return this->m_textEventOut_OutputPort[portNum].registerSerialPort(port);
  }
#endif

  void ProcessInDataComponentBase ::
    set_timeGetOut_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputSerializePort *port
    )
  {
    FW_ASSERT(portNum < this->getNum_timeGetOut_OutputPorts(),static_cast<AssertArg>(portNum));
    return this->m_timeGetOut_OutputPort[portNum].registerSerialPort(port);
  }

  void ProcessInDataComponentBase ::
    set_tlmOut_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputSerializePort *port
    )
  {
    FW_ASSERT(portNum < this->getNum_tlmOut_OutputPorts(),static_cast<AssertArg>(portNum));
    return this->m_tlmOut_OutputPort[portNum].registerSerialPort(port);
  }

#endif

  // ----------------------------------------------------------------------
  // Component construction, initialization, and destruction
  // ----------------------------------------------------------------------

    ProcessInDataComponentBase :: ProcessInDataComponentBase(const char* compName) :
        Fw::PassiveComponentBase(compName) {



  }

  void ProcessInDataComponentBase ::
    init(NATIVE_INT_TYPE instance)
  {

    // Initialize base class
    Fw::PassiveComponentBase::init(instance);

    // Connect input port processInDataIn
    for (
        NATIVE_INT_TYPE port = 0;
        port < this->getNum_processInDataIn_InputPorts();
        port++
    ) {

      this->m_processInDataIn_InputPort[port].init();
      this->m_processInDataIn_InputPort[port].addCallComp(
          this,
          m_p_processInDataIn_in
      );
      this->m_processInDataIn_InputPort[port].setPortNum(port);

#if FW_OBJECT_NAMES == 1
      char portName[120];
      (void) snprintf(
          portName,
          sizeof(portName),
          "%s_processInDataIn_InputPort[%d]",
          this->m_objName,
          port
      );
      this->m_processInDataIn_InputPort[port].setObjName(portName);
#endif

    }

    // Initialize output port eventOut
    for (
        NATIVE_INT_TYPE port = 0;
        port < this->getNum_eventOut_OutputPorts();
        port++
    ) {
      this->m_eventOut_OutputPort[port].init();

#if FW_OBJECT_NAMES == 1
      char portName[120];
      (void) snprintf(
          portName,
          sizeof(portName),
          "%s_eventOut_OutputPort[%d]",
          this->m_objName,
          port
      );
      this->m_eventOut_OutputPort[port].setObjName(portName);
#endif

    }

    // Initialize output port textEventOut
#if FW_ENABLE_TEXT_LOGGING == 1
    for (
        NATIVE_INT_TYPE port = 0;
        port < this->getNum_textEventOut_OutputPorts();
        port++
    ) {
      this->m_textEventOut_OutputPort[port].init();

#if FW_OBJECT_NAMES == 1
      char portName[120];
      (void) snprintf(
          portName,
          sizeof(portName),
          "%s_textEventOut_OutputPort[%d]",
          this->m_objName,
          port
      );
      this->m_textEventOut_OutputPort[port].setObjName(portName);
#endif

    }
#endif

    // Initialize output port timeGetOut
    for (
        NATIVE_INT_TYPE port = 0;
        port < this->getNum_timeGetOut_OutputPorts();
        port++
    ) {
      this->m_timeGetOut_OutputPort[port].init();

#if FW_OBJECT_NAMES == 1
      char portName[120];
      (void) snprintf(
          portName,
          sizeof(portName),
          "%s_timeGetOut_OutputPort[%d]",
          this->m_objName,
          port
      );
      this->m_timeGetOut_OutputPort[port].setObjName(portName);
#endif

    }

    // Initialize output port tlmOut
    for (
        NATIVE_INT_TYPE port = 0;
        port < this->getNum_tlmOut_OutputPorts();
        port++
    ) {
      this->m_tlmOut_OutputPort[port].init();

#if FW_OBJECT_NAMES == 1
      char portName[120];
      (void) snprintf(
          portName,
          sizeof(portName),
          "%s_tlmOut_OutputPort[%d]",
          this->m_objName,
          port
      );
      this->m_tlmOut_OutputPort[port].setObjName(portName);
#endif

    }


  }

  ProcessInDataComponentBase::
    ~ProcessInDataComponentBase() {

  }

  // ----------------------------------------------------------------------
  // Invocation functions for output ports
  // ----------------------------------------------------------------------

  // ----------------------------------------------------------------------
  // Getters for numbers of ports
  // ----------------------------------------------------------------------

  NATIVE_INT_TYPE ProcessInDataComponentBase ::
    getNum_eventOut_OutputPorts()
  {
    return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_eventOut_OutputPort));
  }

  NATIVE_INT_TYPE ProcessInDataComponentBase ::
    getNum_processInDataIn_InputPorts()
  {
    return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_processInDataIn_InputPort));
  }

#if FW_ENABLE_TEXT_LOGGING == 1
  NATIVE_INT_TYPE ProcessInDataComponentBase ::
    getNum_textEventOut_OutputPorts()
  {
    return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_textEventOut_OutputPort));
  }
#endif

  NATIVE_INT_TYPE ProcessInDataComponentBase ::
    getNum_timeGetOut_OutputPorts()
  {
    return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_timeGetOut_OutputPort));
  }

  NATIVE_INT_TYPE ProcessInDataComponentBase ::
    getNum_tlmOut_OutputPorts()
  {
    return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_tlmOut_OutputPort));
  }

  // ----------------------------------------------------------------------
  // Port connection status queries
  // ----------------------------------------------------------------------

  bool ProcessInDataComponentBase ::
    isConnected_eventOut_OutputPort(NATIVE_INT_TYPE portNum)
  {
     FW_ASSERT(
        portNum < this->getNum_eventOut_OutputPorts(),
        static_cast<AssertArg>(portNum)
     );
     return this->m_eventOut_OutputPort[portNum].isConnected();
  }

#if FW_ENABLE_TEXT_LOGGING == 1
  bool ProcessInDataComponentBase ::
    isConnected_textEventOut_OutputPort(NATIVE_INT_TYPE portNum)
  {
     FW_ASSERT(
        portNum < this->getNum_textEventOut_OutputPorts(),
        static_cast<AssertArg>(portNum)
     );
     return this->m_textEventOut_OutputPort[portNum].isConnected();
  }
#endif

  bool ProcessInDataComponentBase ::
    isConnected_timeGetOut_OutputPort(NATIVE_INT_TYPE portNum)
  {
     FW_ASSERT(
        portNum < this->getNum_timeGetOut_OutputPorts(),
        static_cast<AssertArg>(portNum)
     );
     return this->m_timeGetOut_OutputPort[portNum].isConnected();
  }

  bool ProcessInDataComponentBase ::
    isConnected_tlmOut_OutputPort(NATIVE_INT_TYPE portNum)
  {
     FW_ASSERT(
        portNum < this->getNum_tlmOut_OutputPorts(),
        static_cast<AssertArg>(portNum)
     );
     return this->m_tlmOut_OutputPort[portNum].isConnected();
  }

  // ----------------------------------------------------------------------
  // Telemetry write functions
  // ----------------------------------------------------------------------

  void ProcessInDataComponentBase ::
    tlmWrite_angle1(F32 arg, Fw::Time _tlmTime)
  {
    if (this->m_tlmOut_OutputPort[0].isConnected()) {
      if (this->m_timeGetOut_OutputPort[0].isConnected() && _tlmTime ==  Fw::ZERO_TIME) {
         this->m_timeGetOut_OutputPort[0].invoke( _tlmTime);
      }
      Fw::TlmBuffer _tlmBuff;
      Fw::SerializeStatus _stat = _tlmBuff.serialize(arg);
      FW_ASSERT(
          _stat == Fw::FW_SERIALIZE_OK,
          static_cast<AssertArg>(_stat)
      );

      FwChanIdType _id;

      _id = this->getIdBase() + CHANNELID_ANGLE1;

      this->m_tlmOut_OutputPort[0].invoke(
          _id,
          _tlmTime,
          _tlmBuff
      );
    }

  }

  void ProcessInDataComponentBase ::
    tlmWrite_angle2(F32 arg, Fw::Time _tlmTime)
  {
    if (this->m_tlmOut_OutputPort[0].isConnected()) {
      if (this->m_timeGetOut_OutputPort[0].isConnected() && _tlmTime ==  Fw::ZERO_TIME) {
         this->m_timeGetOut_OutputPort[0].invoke( _tlmTime);
      }
      Fw::TlmBuffer _tlmBuff;
      Fw::SerializeStatus _stat = _tlmBuff.serialize(arg);
      FW_ASSERT(
          _stat == Fw::FW_SERIALIZE_OK,
          static_cast<AssertArg>(_stat)
      );

      FwChanIdType _id;

      _id = this->getIdBase() + CHANNELID_ANGLE2;

      this->m_tlmOut_OutputPort[0].invoke(
          _id,
          _tlmTime,
          _tlmBuff
      );
    }

  }

  void ProcessInDataComponentBase ::
    tlmWrite_angle3(F32 arg, Fw::Time _tlmTime)
  {
    if (this->m_tlmOut_OutputPort[0].isConnected()) {
      if (this->m_timeGetOut_OutputPort[0].isConnected() && _tlmTime ==  Fw::ZERO_TIME) {
         this->m_timeGetOut_OutputPort[0].invoke( _tlmTime);
      }
      Fw::TlmBuffer _tlmBuff;
      Fw::SerializeStatus _stat = _tlmBuff.serialize(arg);
      FW_ASSERT(
          _stat == Fw::FW_SERIALIZE_OK,
          static_cast<AssertArg>(_stat)
      );

      FwChanIdType _id;

      _id = this->getIdBase() + CHANNELID_ANGLE3;

      this->m_tlmOut_OutputPort[0].invoke(
          _id,
          _tlmTime,
          _tlmBuff
      );
    }

  }

  void ProcessInDataComponentBase ::
    tlmWrite_rate1(F32 arg, Fw::Time _tlmTime)
  {
    if (this->m_tlmOut_OutputPort[0].isConnected()) {
      if (this->m_timeGetOut_OutputPort[0].isConnected() && _tlmTime ==  Fw::ZERO_TIME) {
         this->m_timeGetOut_OutputPort[0].invoke( _tlmTime);
      }
      Fw::TlmBuffer _tlmBuff;
      Fw::SerializeStatus _stat = _tlmBuff.serialize(arg);
      FW_ASSERT(
          _stat == Fw::FW_SERIALIZE_OK,
          static_cast<AssertArg>(_stat)
      );

      FwChanIdType _id;

      _id = this->getIdBase() + CHANNELID_RATE1;

      this->m_tlmOut_OutputPort[0].invoke(
          _id,
          _tlmTime,
          _tlmBuff
      );
    }

  }

  void ProcessInDataComponentBase ::
    tlmWrite_rate2(F32 arg, Fw::Time _tlmTime)
  {
    if (this->m_tlmOut_OutputPort[0].isConnected()) {
      if (this->m_timeGetOut_OutputPort[0].isConnected() && _tlmTime ==  Fw::ZERO_TIME) {
         this->m_timeGetOut_OutputPort[0].invoke( _tlmTime);
      }
      Fw::TlmBuffer _tlmBuff;
      Fw::SerializeStatus _stat = _tlmBuff.serialize(arg);
      FW_ASSERT(
          _stat == Fw::FW_SERIALIZE_OK,
          static_cast<AssertArg>(_stat)
      );

      FwChanIdType _id;

      _id = this->getIdBase() + CHANNELID_RATE2;

      this->m_tlmOut_OutputPort[0].invoke(
          _id,
          _tlmTime,
          _tlmBuff
      );
    }

  }

  void ProcessInDataComponentBase ::
    tlmWrite_rate3(F32 arg, Fw::Time _tlmTime)
  {
    if (this->m_tlmOut_OutputPort[0].isConnected()) {
      if (this->m_timeGetOut_OutputPort[0].isConnected() && _tlmTime ==  Fw::ZERO_TIME) {
         this->m_timeGetOut_OutputPort[0].invoke( _tlmTime);
      }
      Fw::TlmBuffer _tlmBuff;
      Fw::SerializeStatus _stat = _tlmBuff.serialize(arg);
      FW_ASSERT(
          _stat == Fw::FW_SERIALIZE_OK,
          static_cast<AssertArg>(_stat)
      );

      FwChanIdType _id;

      _id = this->getIdBase() + CHANNELID_RATE3;

      this->m_tlmOut_OutputPort[0].invoke(
          _id,
          _tlmTime,
          _tlmBuff
      );
    }

  }

  // ----------------------------------------------------------------------
  // Time
  // ----------------------------------------------------------------------

  Fw::Time ProcessInDataComponentBase ::
    getTime()
  {
    if (this->m_timeGetOut_OutputPort[0].isConnected()) {
      Fw::Time _time;
      this->m_timeGetOut_OutputPort[0].invoke(_time);
      return _time;
    } else {
      return Fw::Time(TB_NONE,0,0);
    }
  }

  // ----------------------------------------------------------------------
  // Event handling functions
  // ----------------------------------------------------------------------

  void ProcessInDataComponentBase ::
    log_ACTIVITY_LO_PROCESS_IN_DATA(
        
    )
  {


    // Get the time
    Fw::Time _logTime;
    if (this->m_timeGetOut_OutputPort[0].isConnected()) {
       this->m_timeGetOut_OutputPort[0].invoke( _logTime);
    }

    FwEventIdType _id = static_cast<FwEventIdType>(0);

    _id = this->getIdBase() + EVENTID_PROCESS_IN_DATA;

    // Emit the event on the log port
    if (this->m_eventOut_OutputPort[0].isConnected()) {

      Fw::LogBuffer _logBuff;
#if FW_AMPCS_COMPATIBLE
      // for AMPCS, need to encode zero arguments
      Fw::SerializeStatus _zero_status = Fw::FW_SERIALIZE_OK;
      _zero_status = _logBuff.serialize(static_cast<U8>(0));
      FW_ASSERT(
          _zero_status == Fw::FW_SERIALIZE_OK,
          static_cast<AssertArg>(_zero_status)
      );
#endif


      this->m_eventOut_OutputPort[0].invoke(
          _id,
          _logTime,Fw::LogSeverity::ACTIVITY_LO,
          _logBuff
      );

    }

    // Emit the event on the text log port
#if FW_ENABLE_TEXT_LOGGING
    if (this->m_textEventOut_OutputPort[0].isConnected()) {

#if FW_OBJECT_NAMES == 1
      const char* _formatString =
        "(%s) %s: Process in data";
#else
      const char* _formatString =
        "%s: Process in data";
#endif

      char _textBuffer[FW_LOG_TEXT_BUFFER_SIZE];

      (void) snprintf(
          _textBuffer,
          FW_LOG_TEXT_BUFFER_SIZE,
          _formatString,
#if FW_OBJECT_NAMES == 1
          this->m_objName,
#endif
          "PROCESS_IN_DATA "
      );

      // Null terminate
      _textBuffer[FW_LOG_TEXT_BUFFER_SIZE-1] = 0;
      Fw::TextLogString _logString = _textBuffer;
      this->m_textEventOut_OutputPort[0].invoke(
          _id,
          _logTime,Fw::LogSeverity::ACTIVITY_LO,
          _logString
      );

    }
#endif

  }


  // ----------------------------------------------------------------------
  // Calls for invocations received on typed input ports
  // ----------------------------------------------------------------------

  void ProcessInDataComponentBase ::
    m_p_processInDataIn_in(
        Fw::PassiveComponentBase* callComp,
        NATIVE_INT_TYPE portNum,
        Ref::SGyroData &mGyroData, const Ref::SDSSData &mDSSData, const Ref::SThrDistribute &mThrDistribute, Ref::SAttitude &mAttitude, const Ref::Mode &mode
    )
  {
    FW_ASSERT(callComp);
    ProcessInDataComponentBase* compPtr = static_cast<ProcessInDataComponentBase*>(callComp);
    compPtr->processInDataIn_handlerBase(portNum, mGyroData, mDSSData, mThrDistribute, mAttitude, mode);
  }

  // ----------------------------------------------------------------------
  // Port handler base-class functions for typed input ports
  // ----------------------------------------------------------------------

  void ProcessInDataComponentBase ::
    processInDataIn_handlerBase(
        NATIVE_INT_TYPE portNum,
        Ref::SGyroData &mGyroData, const Ref::SDSSData &mDSSData, const Ref::SThrDistribute &mThrDistribute, Ref::SAttitude &mAttitude, const Ref::Mode &mode
    )
  {

    // Make sure port number is valid
    FW_ASSERT(portNum < this->getNum_processInDataIn_InputPorts(),static_cast<AssertArg>(portNum));

    // Down call to pure virtual handler method implemented in Impl class
    this->processInDataIn_handler(portNum, mGyroData, mDSSData, mThrDistribute, mAttitude, mode);

  }

} // end namespace Ref
