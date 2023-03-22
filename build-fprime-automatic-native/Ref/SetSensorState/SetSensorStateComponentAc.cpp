// ======================================================================
// \title  SetSensorStateComponentAc.cpp
// \author Auto-generated
// \brief  cpp file for SetSensorState component base class
//
// NOTE: this file was automatically generated
//
// ======================================================================

#include <cstdio>
#include <FpConfig.hpp>
#include <Ref/SetSensorState/SetSensorStateComponentAc.hpp>
#include <Fw/Types/Assert.hpp>
#if FW_ENABLE_TEXT_LOGGING
#include <Fw/Types/String.hpp>
#endif


namespace Ref {

  // ----------------------------------------------------------------------
  // Getters for numbers of input ports
  // ----------------------------------------------------------------------

  Ref::InputSetSensorStatePort *SetSensorStateComponentBase ::
    get_setSensorStateIn_InputPort(NATIVE_INT_TYPE portNum)
  {
    FW_ASSERT(portNum < this->getNum_setSensorStateIn_InputPorts(),static_cast<AssertArg>(portNum));
    return &this->m_setSensorStateIn_InputPort[portNum];
  }

  // ----------------------------------------------------------------------
  // Typed connectors for output ports
  // ----------------------------------------------------------------------

  void SetSensorStateComponentBase ::
    set_eventOut_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputLogPort* port
    )
  {
    FW_ASSERT(portNum < this->getNum_eventOut_OutputPorts(),static_cast<AssertArg>(portNum));
    this->m_eventOut_OutputPort[portNum].addCallPort(port);
  }

  void SetSensorStateComponentBase ::
    set_getCtrlDataOut_OutputPort(
        NATIVE_INT_TYPE portNum,
        Ref::InputGetCtrlDataPort* port
    )
  {
    FW_ASSERT(portNum < this->getNum_getCtrlDataOut_OutputPorts(),static_cast<AssertArg>(portNum));
    this->m_getCtrlDataOut_OutputPort[portNum].addCallPort(port);
  }

  void SetSensorStateComponentBase ::
    set_getEnvDataOut_OutputPort(
        NATIVE_INT_TYPE portNum,
        Ref::InputGetEnvDataPort* port
    )
  {
    FW_ASSERT(portNum < this->getNum_getEnvDataOut_OutputPorts(),static_cast<AssertArg>(portNum));
    this->m_getEnvDataOut_OutputPort[portNum].addCallPort(port);
  }

  void SetSensorStateComponentBase ::
    set_processDataOut_OutputPort(
        NATIVE_INT_TYPE portNum,
        Ref::InputProcessDataPort* port
    )
  {
    FW_ASSERT(portNum < this->getNum_processDataOut_OutputPorts(),static_cast<AssertArg>(portNum));
    this->m_processDataOut_OutputPort[portNum].addCallPort(port);
  }

#if FW_ENABLE_TEXT_LOGGING == 1
  void SetSensorStateComponentBase ::
    set_textEventOut_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputLogTextPort* port
    )
  {
    FW_ASSERT(portNum < this->getNum_textEventOut_OutputPorts(),static_cast<AssertArg>(portNum));
    this->m_textEventOut_OutputPort[portNum].addCallPort(port);
  }
#endif

  void SetSensorStateComponentBase ::
    set_timeGetOut_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputTimePort* port
    )
  {
    FW_ASSERT(portNum < this->getNum_timeGetOut_OutputPorts(),static_cast<AssertArg>(portNum));
    this->m_timeGetOut_OutputPort[portNum].addCallPort(port);
  }

  void SetSensorStateComponentBase ::
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

  void SetSensorStateComponentBase ::
    set_eventOut_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputSerializePort *port
    )
  {
    FW_ASSERT(portNum < this->getNum_eventOut_OutputPorts(),static_cast<AssertArg>(portNum));
    return this->m_eventOut_OutputPort[portNum].registerSerialPort(port);
  }

  void SetSensorStateComponentBase ::
    set_getCtrlDataOut_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputSerializePort *port
    )
  {
    FW_ASSERT(portNum < this->getNum_getCtrlDataOut_OutputPorts(),static_cast<AssertArg>(portNum));
    return this->m_getCtrlDataOut_OutputPort[portNum].registerSerialPort(port);
  }

  void SetSensorStateComponentBase ::
    set_getEnvDataOut_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputSerializePort *port
    )
  {
    FW_ASSERT(portNum < this->getNum_getEnvDataOut_OutputPorts(),static_cast<AssertArg>(portNum));
    return this->m_getEnvDataOut_OutputPort[portNum].registerSerialPort(port);
  }

  void SetSensorStateComponentBase ::
    set_processDataOut_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputSerializePort *port
    )
  {
    FW_ASSERT(portNum < this->getNum_processDataOut_OutputPorts(),static_cast<AssertArg>(portNum));
    return this->m_processDataOut_OutputPort[portNum].registerSerialPort(port);
  }

#if FW_ENABLE_TEXT_LOGGING == 1
  void SetSensorStateComponentBase ::
    set_textEventOut_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputSerializePort *port
    )
  {
    FW_ASSERT(portNum < this->getNum_textEventOut_OutputPorts(),static_cast<AssertArg>(portNum));
    return this->m_textEventOut_OutputPort[portNum].registerSerialPort(port);
  }
#endif

  void SetSensorStateComponentBase ::
    set_timeGetOut_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputSerializePort *port
    )
  {
    FW_ASSERT(portNum < this->getNum_timeGetOut_OutputPorts(),static_cast<AssertArg>(portNum));
    return this->m_timeGetOut_OutputPort[portNum].registerSerialPort(port);
  }

  void SetSensorStateComponentBase ::
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

    SetSensorStateComponentBase :: SetSensorStateComponentBase(const char* compName) :
        Fw::PassiveComponentBase(compName) {



  }

  void SetSensorStateComponentBase ::
    init(NATIVE_INT_TYPE instance)
  {

    // Initialize base class
    Fw::PassiveComponentBase::init(instance);

    // Connect input port setSensorStateIn
    for (
        NATIVE_INT_TYPE port = 0;
        port < this->getNum_setSensorStateIn_InputPorts();
        port++
    ) {

      this->m_setSensorStateIn_InputPort[port].init();
      this->m_setSensorStateIn_InputPort[port].addCallComp(
          this,
          m_p_setSensorStateIn_in
      );
      this->m_setSensorStateIn_InputPort[port].setPortNum(port);

#if FW_OBJECT_NAMES == 1
      char portName[120];
      (void) snprintf(
          portName,
          sizeof(portName),
          "%s_setSensorStateIn_InputPort[%d]",
          this->m_objName,
          port
      );
      this->m_setSensorStateIn_InputPort[port].setObjName(portName);
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

    // Initialize output port getCtrlDataOut
    for (
        NATIVE_INT_TYPE port = 0;
        port < this->getNum_getCtrlDataOut_OutputPorts();
        port++
    ) {
      this->m_getCtrlDataOut_OutputPort[port].init();

#if FW_OBJECT_NAMES == 1
      char portName[120];
      (void) snprintf(
          portName,
          sizeof(portName),
          "%s_getCtrlDataOut_OutputPort[%d]",
          this->m_objName,
          port
      );
      this->m_getCtrlDataOut_OutputPort[port].setObjName(portName);
#endif

    }

    // Initialize output port getEnvDataOut
    for (
        NATIVE_INT_TYPE port = 0;
        port < this->getNum_getEnvDataOut_OutputPorts();
        port++
    ) {
      this->m_getEnvDataOut_OutputPort[port].init();

#if FW_OBJECT_NAMES == 1
      char portName[120];
      (void) snprintf(
          portName,
          sizeof(portName),
          "%s_getEnvDataOut_OutputPort[%d]",
          this->m_objName,
          port
      );
      this->m_getEnvDataOut_OutputPort[port].setObjName(portName);
#endif

    }

    // Initialize output port processDataOut
    for (
        NATIVE_INT_TYPE port = 0;
        port < this->getNum_processDataOut_OutputPorts();
        port++
    ) {
      this->m_processDataOut_OutputPort[port].init();

#if FW_OBJECT_NAMES == 1
      char portName[120];
      (void) snprintf(
          portName,
          sizeof(portName),
          "%s_processDataOut_OutputPort[%d]",
          this->m_objName,
          port
      );
      this->m_processDataOut_OutputPort[port].setObjName(portName);
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

  SetSensorStateComponentBase::
    ~SetSensorStateComponentBase() {

  }

  // ----------------------------------------------------------------------
  // Invocation functions for output ports
  // ----------------------------------------------------------------------

  void SetSensorStateComponentBase ::
    getCtrlDataOut_out(
        NATIVE_INT_TYPE portNum,
        Ref::Mode &mode
    )
  {
    FW_ASSERT(portNum < this->getNum_getCtrlDataOut_OutputPorts(),static_cast<AssertArg>(portNum));
    this->m_getCtrlDataOut_OutputPort[portNum].invoke(mode);
  }

  void SetSensorStateComponentBase ::
    getEnvDataOut_out(
        NATIVE_INT_TYPE portNum,
        Ref::SGyroData &mGyroData, Ref::SThrDistribute &mThrDistribute, Ref::SDSSData &mDSSData, U32 &sunlight
    )
  {
    FW_ASSERT(portNum < this->getNum_getEnvDataOut_OutputPorts(),static_cast<AssertArg>(portNum));
    this->m_getEnvDataOut_OutputPort[portNum].invoke(mGyroData, mThrDistribute, mDSSData, sunlight);
  }

  Ref::Parameter SetSensorStateComponentBase ::
    processDataOut_out(
        NATIVE_INT_TYPE portNum,
        Ref::SGyroData &mGyroData, Ref::SDSSData &mDSSData, Ref::SThrDistribute &mThrDistribute, Ref::Mode &mode, U32 &countPublic, U32 &countMode, F32 &BIASWXRO, F32 &BIASWYPI, Ref::SFratemodulator &mModulator
    )
  {
    FW_ASSERT(portNum < this->getNum_processDataOut_OutputPorts(),static_cast<AssertArg>(portNum));
    return this->m_processDataOut_OutputPort[portNum].invoke(mGyroData, mDSSData, mThrDistribute, mode, countPublic, countMode, BIASWXRO, BIASWYPI, mModulator);
  }

  // ----------------------------------------------------------------------
  // Getters for numbers of ports
  // ----------------------------------------------------------------------

  NATIVE_INT_TYPE SetSensorStateComponentBase ::
    getNum_eventOut_OutputPorts()
  {
    return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_eventOut_OutputPort));
  }

  NATIVE_INT_TYPE SetSensorStateComponentBase ::
    getNum_getCtrlDataOut_OutputPorts()
  {
    return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_getCtrlDataOut_OutputPort));
  }

  NATIVE_INT_TYPE SetSensorStateComponentBase ::
    getNum_getEnvDataOut_OutputPorts()
  {
    return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_getEnvDataOut_OutputPort));
  }

  NATIVE_INT_TYPE SetSensorStateComponentBase ::
    getNum_processDataOut_OutputPorts()
  {
    return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_processDataOut_OutputPort));
  }

  NATIVE_INT_TYPE SetSensorStateComponentBase ::
    getNum_setSensorStateIn_InputPorts()
  {
    return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_setSensorStateIn_InputPort));
  }

#if FW_ENABLE_TEXT_LOGGING == 1
  NATIVE_INT_TYPE SetSensorStateComponentBase ::
    getNum_textEventOut_OutputPorts()
  {
    return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_textEventOut_OutputPort));
  }
#endif

  NATIVE_INT_TYPE SetSensorStateComponentBase ::
    getNum_timeGetOut_OutputPorts()
  {
    return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_timeGetOut_OutputPort));
  }

  NATIVE_INT_TYPE SetSensorStateComponentBase ::
    getNum_tlmOut_OutputPorts()
  {
    return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_tlmOut_OutputPort));
  }

  // ----------------------------------------------------------------------
  // Port connection status queries
  // ----------------------------------------------------------------------

  bool SetSensorStateComponentBase ::
    isConnected_eventOut_OutputPort(NATIVE_INT_TYPE portNum)
  {
     FW_ASSERT(
        portNum < this->getNum_eventOut_OutputPorts(),
        static_cast<AssertArg>(portNum)
     );
     return this->m_eventOut_OutputPort[portNum].isConnected();
  }

  bool SetSensorStateComponentBase ::
    isConnected_getCtrlDataOut_OutputPort(NATIVE_INT_TYPE portNum)
  {
     FW_ASSERT(
        portNum < this->getNum_getCtrlDataOut_OutputPorts(),
        static_cast<AssertArg>(portNum)
     );
     return this->m_getCtrlDataOut_OutputPort[portNum].isConnected();
  }

  bool SetSensorStateComponentBase ::
    isConnected_getEnvDataOut_OutputPort(NATIVE_INT_TYPE portNum)
  {
     FW_ASSERT(
        portNum < this->getNum_getEnvDataOut_OutputPorts(),
        static_cast<AssertArg>(portNum)
     );
     return this->m_getEnvDataOut_OutputPort[portNum].isConnected();
  }

  bool SetSensorStateComponentBase ::
    isConnected_processDataOut_OutputPort(NATIVE_INT_TYPE portNum)
  {
     FW_ASSERT(
        portNum < this->getNum_processDataOut_OutputPorts(),
        static_cast<AssertArg>(portNum)
     );
     return this->m_processDataOut_OutputPort[portNum].isConnected();
  }

#if FW_ENABLE_TEXT_LOGGING == 1
  bool SetSensorStateComponentBase ::
    isConnected_textEventOut_OutputPort(NATIVE_INT_TYPE portNum)
  {
     FW_ASSERT(
        portNum < this->getNum_textEventOut_OutputPorts(),
        static_cast<AssertArg>(portNum)
     );
     return this->m_textEventOut_OutputPort[portNum].isConnected();
  }
#endif

  bool SetSensorStateComponentBase ::
    isConnected_timeGetOut_OutputPort(NATIVE_INT_TYPE portNum)
  {
     FW_ASSERT(
        portNum < this->getNum_timeGetOut_OutputPorts(),
        static_cast<AssertArg>(portNum)
     );
     return this->m_timeGetOut_OutputPort[portNum].isConnected();
  }

  bool SetSensorStateComponentBase ::
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

  void SetSensorStateComponentBase ::
    tlmWrite_PARAMETER(const Ref::Parameter& arg, Fw::Time _tlmTime)
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

      _id = this->getIdBase() + CHANNELID_PARAMETER;

      this->m_tlmOut_OutputPort[0].invoke(
          _id,
          _tlmTime,
          _tlmBuff
      );
    }

  }

  void SetSensorStateComponentBase ::
    tlmWrite_SUNLIGHT(U32 arg, Fw::Time _tlmTime)
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

      _id = this->getIdBase() + CHANNELID_SUNLIGHT;

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

  Fw::Time SetSensorStateComponentBase ::
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

  void SetSensorStateComponentBase ::
    log_ACTIVITY_LO_SET_SENSOR_STATE(
        
    )
  {


    // Get the time
    Fw::Time _logTime;
    if (this->m_timeGetOut_OutputPort[0].isConnected()) {
       this->m_timeGetOut_OutputPort[0].invoke( _logTime);
    }

    FwEventIdType _id = static_cast<FwEventIdType>(0);

    _id = this->getIdBase() + EVENTID_SET_SENSOR_STATE;

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
        "(%s) %s: set sensor state";
#else
      const char* _formatString =
        "%s: set sensor state";
#endif

      char _textBuffer[FW_LOG_TEXT_BUFFER_SIZE];

      (void) snprintf(
          _textBuffer,
          FW_LOG_TEXT_BUFFER_SIZE,
          _formatString,
#if FW_OBJECT_NAMES == 1
          this->m_objName,
#endif
          "SET_SENSOR_STATE "
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

  Ref::Parameter SetSensorStateComponentBase ::
    m_p_setSensorStateIn_in(
        Fw::PassiveComponentBase* callComp,
        NATIVE_INT_TYPE portNum,
        Ref::SGyroData &mGyroData, Ref::Mode &mode, U32 &countPublic, U32 &countMode, F32 &BIASWXRO, F32 &BIASWYPI, Ref::SFratemodulator &mModulator
    )
  {
    FW_ASSERT(callComp);
    SetSensorStateComponentBase* compPtr = static_cast<SetSensorStateComponentBase*>(callComp);
    return compPtr->setSensorStateIn_handlerBase(portNum, mGyroData, mode, countPublic, countMode, BIASWXRO, BIASWYPI, mModulator);
  }

  // ----------------------------------------------------------------------
  // Port handler base-class functions for typed input ports
  // ----------------------------------------------------------------------

  Ref::Parameter SetSensorStateComponentBase ::
    setSensorStateIn_handlerBase(
        NATIVE_INT_TYPE portNum,
        Ref::SGyroData &mGyroData, Ref::Mode &mode, U32 &countPublic, U32 &countMode, F32 &BIASWXRO, F32 &BIASWYPI, Ref::SFratemodulator &mModulator
    )
  {

    // Make sure port number is valid
    FW_ASSERT(portNum < this->getNum_setSensorStateIn_InputPorts(),static_cast<AssertArg>(portNum));
    Ref::Parameter  retVal;

    // Down call to pure virtual handler method implemented in Impl class
    retVal = this->setSensorStateIn_handler(portNum, mGyroData, mode, countPublic, countMode, BIASWXRO, BIASWYPI, mModulator);

    return retVal;

  }

} // end namespace Ref
