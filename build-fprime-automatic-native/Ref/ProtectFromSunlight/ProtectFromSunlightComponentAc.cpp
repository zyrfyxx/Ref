// ======================================================================
// \title  ProtectFromSunlightComponentAc.cpp
// \author Auto-generated
// \brief  cpp file for ProtectFromSunlight component base class
//
// NOTE: this file was automatically generated
//
// ======================================================================

#include <cstdio>
#include <FpConfig.hpp>
#include <Ref/ProtectFromSunlight/ProtectFromSunlightComponentAc.hpp>
#include <Fw/Types/Assert.hpp>
#if FW_ENABLE_TEXT_LOGGING
#include <Fw/Types/String.hpp>
#endif


namespace Ref {

  // ----------------------------------------------------------------------
  // Getters for numbers of input ports
  // ----------------------------------------------------------------------

  Ref::InputProtectFromSunlightPort *ProtectFromSunlightComponentBase ::
    get_protectFromSunlightIn_InputPort(NATIVE_INT_TYPE portNum)
  {
    FW_ASSERT(portNum < this->getNum_protectFromSunlightIn_InputPorts(),static_cast<AssertArg>(portNum));
    return &this->m_protectFromSunlightIn_InputPort[portNum];
  }

  // ----------------------------------------------------------------------
  // Typed connectors for output ports
  // ----------------------------------------------------------------------

  void ProtectFromSunlightComponentBase ::
    set_eventOut_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputLogPort* port
    )
  {
    FW_ASSERT(portNum < this->getNum_eventOut_OutputPorts(),static_cast<AssertArg>(portNum));
    this->m_eventOut_OutputPort[portNum].addCallPort(port);
  }

#if FW_ENABLE_TEXT_LOGGING == 1
  void ProtectFromSunlightComponentBase ::
    set_textEventOut_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputLogTextPort* port
    )
  {
    FW_ASSERT(portNum < this->getNum_textEventOut_OutputPorts(),static_cast<AssertArg>(portNum));
    this->m_textEventOut_OutputPort[portNum].addCallPort(port);
  }
#endif

  void ProtectFromSunlightComponentBase ::
    set_timeGetOut_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputTimePort* port
    )
  {
    FW_ASSERT(portNum < this->getNum_timeGetOut_OutputPorts(),static_cast<AssertArg>(portNum));
    this->m_timeGetOut_OutputPort[portNum].addCallPort(port);
  }

  void ProtectFromSunlightComponentBase ::
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

  void ProtectFromSunlightComponentBase ::
    set_eventOut_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputSerializePort *port
    )
  {
    FW_ASSERT(portNum < this->getNum_eventOut_OutputPorts(),static_cast<AssertArg>(portNum));
    return this->m_eventOut_OutputPort[portNum].registerSerialPort(port);
  }

#if FW_ENABLE_TEXT_LOGGING == 1
  void ProtectFromSunlightComponentBase ::
    set_textEventOut_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputSerializePort *port
    )
  {
    FW_ASSERT(portNum < this->getNum_textEventOut_OutputPorts(),static_cast<AssertArg>(portNum));
    return this->m_textEventOut_OutputPort[portNum].registerSerialPort(port);
  }
#endif

  void ProtectFromSunlightComponentBase ::
    set_timeGetOut_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputSerializePort *port
    )
  {
    FW_ASSERT(portNum < this->getNum_timeGetOut_OutputPorts(),static_cast<AssertArg>(portNum));
    return this->m_timeGetOut_OutputPort[portNum].registerSerialPort(port);
  }

  void ProtectFromSunlightComponentBase ::
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

    ProtectFromSunlightComponentBase :: ProtectFromSunlightComponentBase(const char* compName) :
        Fw::PassiveComponentBase(compName) {



  }

  void ProtectFromSunlightComponentBase ::
    init(NATIVE_INT_TYPE instance)
  {

    // Initialize base class
    Fw::PassiveComponentBase::init(instance);

    // Connect input port protectFromSunlightIn
    for (
        NATIVE_INT_TYPE port = 0;
        port < this->getNum_protectFromSunlightIn_InputPorts();
        port++
    ) {

      this->m_protectFromSunlightIn_InputPort[port].init();
      this->m_protectFromSunlightIn_InputPort[port].addCallComp(
          this,
          m_p_protectFromSunlightIn_in
      );
      this->m_protectFromSunlightIn_InputPort[port].setPortNum(port);

#if FW_OBJECT_NAMES == 1
      char portName[120];
      (void) snprintf(
          portName,
          sizeof(portName),
          "%s_protectFromSunlightIn_InputPort[%d]",
          this->m_objName,
          port
      );
      this->m_protectFromSunlightIn_InputPort[port].setObjName(portName);
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

  ProtectFromSunlightComponentBase::
    ~ProtectFromSunlightComponentBase() {

  }

  // ----------------------------------------------------------------------
  // Invocation functions for output ports
  // ----------------------------------------------------------------------

  // ----------------------------------------------------------------------
  // Getters for numbers of ports
  // ----------------------------------------------------------------------

  NATIVE_INT_TYPE ProtectFromSunlightComponentBase ::
    getNum_eventOut_OutputPorts()
  {
    return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_eventOut_OutputPort));
  }

  NATIVE_INT_TYPE ProtectFromSunlightComponentBase ::
    getNum_protectFromSunlightIn_InputPorts()
  {
    return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_protectFromSunlightIn_InputPort));
  }

#if FW_ENABLE_TEXT_LOGGING == 1
  NATIVE_INT_TYPE ProtectFromSunlightComponentBase ::
    getNum_textEventOut_OutputPorts()
  {
    return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_textEventOut_OutputPort));
  }
#endif

  NATIVE_INT_TYPE ProtectFromSunlightComponentBase ::
    getNum_timeGetOut_OutputPorts()
  {
    return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_timeGetOut_OutputPort));
  }

  NATIVE_INT_TYPE ProtectFromSunlightComponentBase ::
    getNum_tlmOut_OutputPorts()
  {
    return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_tlmOut_OutputPort));
  }

  // ----------------------------------------------------------------------
  // Port connection status queries
  // ----------------------------------------------------------------------

  bool ProtectFromSunlightComponentBase ::
    isConnected_eventOut_OutputPort(NATIVE_INT_TYPE portNum)
  {
     FW_ASSERT(
        portNum < this->getNum_eventOut_OutputPorts(),
        static_cast<AssertArg>(portNum)
     );
     return this->m_eventOut_OutputPort[portNum].isConnected();
  }

#if FW_ENABLE_TEXT_LOGGING == 1
  bool ProtectFromSunlightComponentBase ::
    isConnected_textEventOut_OutputPort(NATIVE_INT_TYPE portNum)
  {
     FW_ASSERT(
        portNum < this->getNum_textEventOut_OutputPorts(),
        static_cast<AssertArg>(portNum)
     );
     return this->m_textEventOut_OutputPort[portNum].isConnected();
  }
#endif

  bool ProtectFromSunlightComponentBase ::
    isConnected_timeGetOut_OutputPort(NATIVE_INT_TYPE portNum)
  {
     FW_ASSERT(
        portNum < this->getNum_timeGetOut_OutputPorts(),
        static_cast<AssertArg>(portNum)
     );
     return this->m_timeGetOut_OutputPort[portNum].isConnected();
  }

  bool ProtectFromSunlightComponentBase ::
    isConnected_tlmOut_OutputPort(NATIVE_INT_TYPE portNum)
  {
     FW_ASSERT(
        portNum < this->getNum_tlmOut_OutputPorts(),
        static_cast<AssertArg>(portNum)
     );
     return this->m_tlmOut_OutputPort[portNum].isConnected();
  }

  // ----------------------------------------------------------------------
  // Time
  // ----------------------------------------------------------------------

  Fw::Time ProtectFromSunlightComponentBase ::
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

  void ProtectFromSunlightComponentBase ::
    log_ACTIVITY_LO_PROCESS_OUT_DATA(
        
    )
  {


    // Get the time
    Fw::Time _logTime;
    if (this->m_timeGetOut_OutputPort[0].isConnected()) {
       this->m_timeGetOut_OutputPort[0].invoke( _logTime);
    }

    FwEventIdType _id = static_cast<FwEventIdType>(0);

    _id = this->getIdBase() + EVENTID_PROCESS_OUT_DATA;

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
        "(%s) %s: Protect from Sunlight";
#else
      const char* _formatString =
        "%s: Protect from Sunlight";
#endif

      char _textBuffer[FW_LOG_TEXT_BUFFER_SIZE];

      (void) snprintf(
          _textBuffer,
          FW_LOG_TEXT_BUFFER_SIZE,
          _formatString,
#if FW_OBJECT_NAMES == 1
          this->m_objName,
#endif
          "PROCESS_OUT_DATA "
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

  void ProtectFromSunlightComponentBase ::
    m_p_protectFromSunlightIn_in(
        Fw::PassiveComponentBase* callComp,
        NATIVE_INT_TYPE portNum
    )
  {
    FW_ASSERT(callComp);
    ProtectFromSunlightComponentBase* compPtr = static_cast<ProtectFromSunlightComponentBase*>(callComp);
    compPtr->protectFromSunlightIn_handlerBase(portNum);
  }

  // ----------------------------------------------------------------------
  // Port handler base-class functions for typed input ports
  // ----------------------------------------------------------------------

  void ProtectFromSunlightComponentBase ::
    protectFromSunlightIn_handlerBase(NATIVE_INT_TYPE portNum)
  {

    // Make sure port number is valid
    FW_ASSERT(portNum < this->getNum_protectFromSunlightIn_InputPorts(),static_cast<AssertArg>(portNum));

    // Down call to pure virtual handler method implemented in Impl class
    this->protectFromSunlightIn_handler(portNum);

  }

} // end namespace Ref
