// ======================================================================
// \title  DoActionsComponentAc.cpp
// \author Auto-generated
// \brief  cpp file for DoActions component base class
//
// NOTE: this file was automatically generated
//
// ======================================================================

#include <cstdio>
#include <FpConfig.hpp>
#include <Ref/DoActions/DoActionsComponentAc.hpp>
#include <Fw/Types/Assert.hpp>
#if FW_ENABLE_TEXT_LOGGING
#include <Fw/Types/String.hpp>
#endif


namespace Ref {

  // ----------------------------------------------------------------------
  // Getters for numbers of input ports
  // ----------------------------------------------------------------------

  Ref::InputDoActionsPort *DoActionsComponentBase ::
    get_doActionsIn_InputPort(NATIVE_INT_TYPE portNum)
  {
    FW_ASSERT(portNum < this->getNum_doActionsIn_InputPorts(),static_cast<AssertArg>(portNum));
    return &this->m_doActionsIn_InputPort[portNum];
  }

  // ----------------------------------------------------------------------
  // Typed connectors for output ports
  // ----------------------------------------------------------------------

  void DoActionsComponentBase ::
    set_eventOut_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputLogPort* port
    )
  {
    FW_ASSERT(portNum < this->getNum_eventOut_OutputPorts(),static_cast<AssertArg>(portNum));
    this->m_eventOut_OutputPort[portNum].addCallPort(port);
  }

  void DoActionsComponentBase ::
    set_protectFromSunlightOut_OutputPort(
        NATIVE_INT_TYPE portNum,
        Ref::InputProtectFromSunlightPort* port
    )
  {
    FW_ASSERT(portNum < this->getNum_protectFromSunlightOut_OutputPorts(),static_cast<AssertArg>(portNum));
    this->m_protectFromSunlightOut_OutputPort[portNum].addCallPort(port);
  }

#if FW_ENABLE_TEXT_LOGGING == 1
  void DoActionsComponentBase ::
    set_textEventOut_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputLogTextPort* port
    )
  {
    FW_ASSERT(portNum < this->getNum_textEventOut_OutputPorts(),static_cast<AssertArg>(portNum));
    this->m_textEventOut_OutputPort[portNum].addCallPort(port);
  }
#endif

  void DoActionsComponentBase ::
    set_thrDistributeOut_OutputPort(
        NATIVE_INT_TYPE portNum,
        Ref::InputThrDistributePort* port
    )
  {
    FW_ASSERT(portNum < this->getNum_thrDistributeOut_OutputPorts(),static_cast<AssertArg>(portNum));
    this->m_thrDistributeOut_OutputPort[portNum].addCallPort(port);
  }

  void DoActionsComponentBase ::
    set_timeGetOut_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputTimePort* port
    )
  {
    FW_ASSERT(portNum < this->getNum_timeGetOut_OutputPorts(),static_cast<AssertArg>(portNum));
    this->m_timeGetOut_OutputPort[portNum].addCallPort(port);
  }

  void DoActionsComponentBase ::
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

  void DoActionsComponentBase ::
    set_eventOut_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputSerializePort *port
    )
  {
    FW_ASSERT(portNum < this->getNum_eventOut_OutputPorts(),static_cast<AssertArg>(portNum));
    return this->m_eventOut_OutputPort[portNum].registerSerialPort(port);
  }

  void DoActionsComponentBase ::
    set_protectFromSunlightOut_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputSerializePort *port
    )
  {
    FW_ASSERT(portNum < this->getNum_protectFromSunlightOut_OutputPorts(),static_cast<AssertArg>(portNum));
    return this->m_protectFromSunlightOut_OutputPort[portNum].registerSerialPort(port);
  }

#if FW_ENABLE_TEXT_LOGGING == 1
  void DoActionsComponentBase ::
    set_textEventOut_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputSerializePort *port
    )
  {
    FW_ASSERT(portNum < this->getNum_textEventOut_OutputPorts(),static_cast<AssertArg>(portNum));
    return this->m_textEventOut_OutputPort[portNum].registerSerialPort(port);
  }
#endif

  void DoActionsComponentBase ::
    set_thrDistributeOut_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputSerializePort *port
    )
  {
    FW_ASSERT(portNum < this->getNum_thrDistributeOut_OutputPorts(),static_cast<AssertArg>(portNum));
    return this->m_thrDistributeOut_OutputPort[portNum].registerSerialPort(port);
  }

  void DoActionsComponentBase ::
    set_timeGetOut_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputSerializePort *port
    )
  {
    FW_ASSERT(portNum < this->getNum_timeGetOut_OutputPorts(),static_cast<AssertArg>(portNum));
    return this->m_timeGetOut_OutputPort[portNum].registerSerialPort(port);
  }

  void DoActionsComponentBase ::
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

    DoActionsComponentBase :: DoActionsComponentBase(const char* compName) :
        Fw::PassiveComponentBase(compName) {



  }

  void DoActionsComponentBase ::
    init(NATIVE_INT_TYPE instance)
  {

    // Initialize base class
    Fw::PassiveComponentBase::init(instance);

    // Connect input port doActionsIn
    for (
        NATIVE_INT_TYPE port = 0;
        port < this->getNum_doActionsIn_InputPorts();
        port++
    ) {

      this->m_doActionsIn_InputPort[port].init();
      this->m_doActionsIn_InputPort[port].addCallComp(
          this,
          m_p_doActionsIn_in
      );
      this->m_doActionsIn_InputPort[port].setPortNum(port);

#if FW_OBJECT_NAMES == 1
      char portName[120];
      (void) snprintf(
          portName,
          sizeof(portName),
          "%s_doActionsIn_InputPort[%d]",
          this->m_objName,
          port
      );
      this->m_doActionsIn_InputPort[port].setObjName(portName);
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

    // Initialize output port protectFromSunlightOut
    for (
        NATIVE_INT_TYPE port = 0;
        port < this->getNum_protectFromSunlightOut_OutputPorts();
        port++
    ) {
      this->m_protectFromSunlightOut_OutputPort[port].init();

#if FW_OBJECT_NAMES == 1
      char portName[120];
      (void) snprintf(
          portName,
          sizeof(portName),
          "%s_protectFromSunlightOut_OutputPort[%d]",
          this->m_objName,
          port
      );
      this->m_protectFromSunlightOut_OutputPort[port].setObjName(portName);
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

    // Initialize output port thrDistributeOut
    for (
        NATIVE_INT_TYPE port = 0;
        port < this->getNum_thrDistributeOut_OutputPorts();
        port++
    ) {
      this->m_thrDistributeOut_OutputPort[port].init();

#if FW_OBJECT_NAMES == 1
      char portName[120];
      (void) snprintf(
          portName,
          sizeof(portName),
          "%s_thrDistributeOut_OutputPort[%d]",
          this->m_objName,
          port
      );
      this->m_thrDistributeOut_OutputPort[port].setObjName(portName);
#endif

    }

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

  DoActionsComponentBase::
    ~DoActionsComponentBase() {

  }

  // ----------------------------------------------------------------------
  // Invocation functions for output ports
  // ----------------------------------------------------------------------

  void DoActionsComponentBase ::
    protectFromSunlightOut_out(NATIVE_INT_TYPE portNum)
  {
    FW_ASSERT(portNum < this->getNum_protectFromSunlightOut_OutputPorts(),static_cast<AssertArg>(portNum));
    this->m_protectFromSunlightOut_OutputPort[portNum].invoke();
  }

  void DoActionsComponentBase ::
    thrDistributeOut_out(
        NATIVE_INT_TYPE portNum,
        U8 wPulse
    )
  {
    FW_ASSERT(portNum < this->getNum_thrDistributeOut_OutputPorts(),static_cast<AssertArg>(portNum));
    this->m_thrDistributeOut_OutputPort[portNum].invoke(wPulse);
  }

  // ----------------------------------------------------------------------
  // Getters for numbers of ports
  // ----------------------------------------------------------------------

  NATIVE_INT_TYPE DoActionsComponentBase ::
    getNum_doActionsIn_InputPorts()
  {
    return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_doActionsIn_InputPort));
  }

  NATIVE_INT_TYPE DoActionsComponentBase ::
    getNum_eventOut_OutputPorts()
  {
    return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_eventOut_OutputPort));
  }

  NATIVE_INT_TYPE DoActionsComponentBase ::
    getNum_protectFromSunlightOut_OutputPorts()
  {
    return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_protectFromSunlightOut_OutputPort));
  }

#if FW_ENABLE_TEXT_LOGGING == 1
  NATIVE_INT_TYPE DoActionsComponentBase ::
    getNum_textEventOut_OutputPorts()
  {
    return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_textEventOut_OutputPort));
  }
#endif

  NATIVE_INT_TYPE DoActionsComponentBase ::
    getNum_thrDistributeOut_OutputPorts()
  {
    return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_thrDistributeOut_OutputPort));
  }

  NATIVE_INT_TYPE DoActionsComponentBase ::
    getNum_timeGetOut_OutputPorts()
  {
    return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_timeGetOut_OutputPort));
  }

  NATIVE_INT_TYPE DoActionsComponentBase ::
    getNum_tlmOut_OutputPorts()
  {
    return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_tlmOut_OutputPort));
  }

  // ----------------------------------------------------------------------
  // Port connection status queries
  // ----------------------------------------------------------------------

  bool DoActionsComponentBase ::
    isConnected_eventOut_OutputPort(NATIVE_INT_TYPE portNum)
  {
     FW_ASSERT(
        portNum < this->getNum_eventOut_OutputPorts(),
        static_cast<AssertArg>(portNum)
     );
     return this->m_eventOut_OutputPort[portNum].isConnected();
  }

  bool DoActionsComponentBase ::
    isConnected_protectFromSunlightOut_OutputPort(NATIVE_INT_TYPE portNum)
  {
     FW_ASSERT(
        portNum < this->getNum_protectFromSunlightOut_OutputPorts(),
        static_cast<AssertArg>(portNum)
     );
     return this->m_protectFromSunlightOut_OutputPort[portNum].isConnected();
  }

#if FW_ENABLE_TEXT_LOGGING == 1
  bool DoActionsComponentBase ::
    isConnected_textEventOut_OutputPort(NATIVE_INT_TYPE portNum)
  {
     FW_ASSERT(
        portNum < this->getNum_textEventOut_OutputPorts(),
        static_cast<AssertArg>(portNum)
     );
     return this->m_textEventOut_OutputPort[portNum].isConnected();
  }
#endif

  bool DoActionsComponentBase ::
    isConnected_thrDistributeOut_OutputPort(NATIVE_INT_TYPE portNum)
  {
     FW_ASSERT(
        portNum < this->getNum_thrDistributeOut_OutputPorts(),
        static_cast<AssertArg>(portNum)
     );
     return this->m_thrDistributeOut_OutputPort[portNum].isConnected();
  }

  bool DoActionsComponentBase ::
    isConnected_timeGetOut_OutputPort(NATIVE_INT_TYPE portNum)
  {
     FW_ASSERT(
        portNum < this->getNum_timeGetOut_OutputPorts(),
        static_cast<AssertArg>(portNum)
     );
     return this->m_timeGetOut_OutputPort[portNum].isConnected();
  }

  bool DoActionsComponentBase ::
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

  void DoActionsComponentBase ::
    tlmWrite_ACTIONS(const Ref::Actions& arg, Fw::Time _tlmTime)
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

      _id = this->getIdBase() + CHANNELID_ACTIONS;

      this->m_tlmOut_OutputPort[0].invoke(
          _id,
          _tlmTime,
          _tlmBuff
      );
    }

  }

  void DoActionsComponentBase ::
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

  // ----------------------------------------------------------------------
  // Time
  // ----------------------------------------------------------------------

  Fw::Time DoActionsComponentBase ::
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

  void DoActionsComponentBase ::
    log_ACTIVITY_LO_DOACTIONS(
        
    )
  {


    // Get the time
    Fw::Time _logTime;
    if (this->m_timeGetOut_OutputPort[0].isConnected()) {
       this->m_timeGetOut_OutputPort[0].invoke( _logTime);
    }

    FwEventIdType _id = static_cast<FwEventIdType>(0);

    _id = this->getIdBase() + EVENTID_DOACTIONS;

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
        "(%s) %s: do actions";
#else
      const char* _formatString =
        "%s: do actions";
#endif

      char _textBuffer[FW_LOG_TEXT_BUFFER_SIZE];

      (void) snprintf(
          _textBuffer,
          FW_LOG_TEXT_BUFFER_SIZE,
          _formatString,
#if FW_OBJECT_NAMES == 1
          this->m_objName,
#endif
          "DOACTIONS "
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

  void DoActionsComponentBase ::
    m_p_doActionsIn_in(
        Fw::PassiveComponentBase* callComp,
        NATIVE_INT_TYPE portNum,
        const Ref::Actions &actions, const Ref::Parameter &parameter
    )
  {
    FW_ASSERT(callComp);
    DoActionsComponentBase* compPtr = static_cast<DoActionsComponentBase*>(callComp);
    compPtr->doActionsIn_handlerBase(portNum, actions, parameter);
  }

  // ----------------------------------------------------------------------
  // Port handler base-class functions for typed input ports
  // ----------------------------------------------------------------------

  void DoActionsComponentBase ::
    doActionsIn_handlerBase(
        NATIVE_INT_TYPE portNum,
        const Ref::Actions &actions, const Ref::Parameter &parameter
    )
  {

    // Make sure port number is valid
    FW_ASSERT(portNum < this->getNum_doActionsIn_InputPorts(),static_cast<AssertArg>(portNum));

    // Down call to pure virtual handler method implemented in Impl class
    this->doActionsIn_handler(portNum, actions, parameter);

  }

} // end namespace Ref
