// ======================================================================
// \title  ProcessDataComponentAc.cpp
// \author Auto-generated
// \brief  cpp file for ProcessData component base class
//
// NOTE: this file was automatically generated
//
// ======================================================================

#include <cstdio>
#include <FpConfig.hpp>
#include <Ref/ProcessData/ProcessDataComponentAc.hpp>
#include <Fw/Types/Assert.hpp>
#if FW_ENABLE_TEXT_LOGGING
#include <Fw/Types/String.hpp>
#endif


namespace Ref {

  // ----------------------------------------------------------------------
  // Getters for numbers of input ports
  // ----------------------------------------------------------------------

  Ref::InputProcessDataPort *ProcessDataComponentBase ::
    get_processDataIn_InputPort(NATIVE_INT_TYPE portNum)
  {
    FW_ASSERT(portNum < this->getNum_processDataIn_InputPorts(),static_cast<AssertArg>(portNum));
    return &this->m_processDataIn_InputPort[portNum];
  }

  // ----------------------------------------------------------------------
  // Typed connectors for output ports
  // ----------------------------------------------------------------------

  void ProcessDataComponentBase ::
    set_eventOut_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputLogPort* port
    )
  {
    FW_ASSERT(portNum < this->getNum_eventOut_OutputPorts(),static_cast<AssertArg>(portNum));
    this->m_eventOut_OutputPort[portNum].addCallPort(port);
  }

  void ProcessDataComponentBase ::
    set_processInDataOut_OutputPort(
        NATIVE_INT_TYPE portNum,
        Ref::InputProcessInDataPort* port
    )
  {
    FW_ASSERT(portNum < this->getNum_processInDataOut_OutputPorts(),static_cast<AssertArg>(portNum));
    this->m_processInDataOut_OutputPort[portNum].addCallPort(port);
  }

  void ProcessDataComponentBase ::
    set_processOutDataOut_OutputPort(
        NATIVE_INT_TYPE portNum,
        Ref::InputProcessOutDataPort* port
    )
  {
    FW_ASSERT(portNum < this->getNum_processOutDataOut_OutputPorts(),static_cast<AssertArg>(portNum));
    this->m_processOutDataOut_OutputPort[portNum].addCallPort(port);
  }

#if FW_ENABLE_TEXT_LOGGING == 1
  void ProcessDataComponentBase ::
    set_textEventOut_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputLogTextPort* port
    )
  {
    FW_ASSERT(portNum < this->getNum_textEventOut_OutputPorts(),static_cast<AssertArg>(portNum));
    this->m_textEventOut_OutputPort[portNum].addCallPort(port);
  }
#endif

  void ProcessDataComponentBase ::
    set_timeGetOut_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputTimePort* port
    )
  {
    FW_ASSERT(portNum < this->getNum_timeGetOut_OutputPorts(),static_cast<AssertArg>(portNum));
    this->m_timeGetOut_OutputPort[portNum].addCallPort(port);
  }

  void ProcessDataComponentBase ::
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

  void ProcessDataComponentBase ::
    set_eventOut_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputSerializePort *port
    )
  {
    FW_ASSERT(portNum < this->getNum_eventOut_OutputPorts(),static_cast<AssertArg>(portNum));
    return this->m_eventOut_OutputPort[portNum].registerSerialPort(port);
  }

  void ProcessDataComponentBase ::
    set_processInDataOut_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputSerializePort *port
    )
  {
    FW_ASSERT(portNum < this->getNum_processInDataOut_OutputPorts(),static_cast<AssertArg>(portNum));
    return this->m_processInDataOut_OutputPort[portNum].registerSerialPort(port);
  }

  void ProcessDataComponentBase ::
    set_processOutDataOut_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputSerializePort *port
    )
  {
    FW_ASSERT(portNum < this->getNum_processOutDataOut_OutputPorts(),static_cast<AssertArg>(portNum));
    return this->m_processOutDataOut_OutputPort[portNum].registerSerialPort(port);
  }

#if FW_ENABLE_TEXT_LOGGING == 1
  void ProcessDataComponentBase ::
    set_textEventOut_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputSerializePort *port
    )
  {
    FW_ASSERT(portNum < this->getNum_textEventOut_OutputPorts(),static_cast<AssertArg>(portNum));
    return this->m_textEventOut_OutputPort[portNum].registerSerialPort(port);
  }
#endif

  void ProcessDataComponentBase ::
    set_timeGetOut_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputSerializePort *port
    )
  {
    FW_ASSERT(portNum < this->getNum_timeGetOut_OutputPorts(),static_cast<AssertArg>(portNum));
    return this->m_timeGetOut_OutputPort[portNum].registerSerialPort(port);
  }

  void ProcessDataComponentBase ::
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

    ProcessDataComponentBase :: ProcessDataComponentBase(const char* compName) :
        Fw::PassiveComponentBase(compName) {



  }

  void ProcessDataComponentBase ::
    init(NATIVE_INT_TYPE instance)
  {

    // Initialize base class
    Fw::PassiveComponentBase::init(instance);

    // Connect input port processDataIn
    for (
        NATIVE_INT_TYPE port = 0;
        port < this->getNum_processDataIn_InputPorts();
        port++
    ) {

      this->m_processDataIn_InputPort[port].init();
      this->m_processDataIn_InputPort[port].addCallComp(
          this,
          m_p_processDataIn_in
      );
      this->m_processDataIn_InputPort[port].setPortNum(port);

#if FW_OBJECT_NAMES == 1
      char portName[120];
      (void) snprintf(
          portName,
          sizeof(portName),
          "%s_processDataIn_InputPort[%d]",
          this->m_objName,
          port
      );
      this->m_processDataIn_InputPort[port].setObjName(portName);
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

    // Initialize output port processInDataOut
    for (
        NATIVE_INT_TYPE port = 0;
        port < this->getNum_processInDataOut_OutputPorts();
        port++
    ) {
      this->m_processInDataOut_OutputPort[port].init();

#if FW_OBJECT_NAMES == 1
      char portName[120];
      (void) snprintf(
          portName,
          sizeof(portName),
          "%s_processInDataOut_OutputPort[%d]",
          this->m_objName,
          port
      );
      this->m_processInDataOut_OutputPort[port].setObjName(portName);
#endif

    }

    // Initialize output port processOutDataOut
    for (
        NATIVE_INT_TYPE port = 0;
        port < this->getNum_processOutDataOut_OutputPorts();
        port++
    ) {
      this->m_processOutDataOut_OutputPort[port].init();

#if FW_OBJECT_NAMES == 1
      char portName[120];
      (void) snprintf(
          portName,
          sizeof(portName),
          "%s_processOutDataOut_OutputPort[%d]",
          this->m_objName,
          port
      );
      this->m_processOutDataOut_OutputPort[port].setObjName(portName);
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

  ProcessDataComponentBase::
    ~ProcessDataComponentBase() {

  }

  // ----------------------------------------------------------------------
  // Invocation functions for output ports
  // ----------------------------------------------------------------------

  void ProcessDataComponentBase ::
    processInDataOut_out(
        NATIVE_INT_TYPE portNum,
        Ref::SGyroData &mGyroData, const Ref::SDSSData &mDSSData, const Ref::SThrDistribute &mThrDistribute, Ref::SAttitude &mAttitude, const Ref::Mode &mode
    )
  {
    FW_ASSERT(portNum < this->getNum_processInDataOut_OutputPorts(),static_cast<AssertArg>(portNum));
    this->m_processInDataOut_OutputPort[portNum].invoke(mGyroData, mDSSData, mThrDistribute, mAttitude, mode);
  }

  void ProcessDataComponentBase ::
    processOutDataOut_out(
        NATIVE_INT_TYPE portNum,
        const Ref::SAttitude &mAttitude, const Ref::SDSSData &mDSSData, Ref::Mode &mode, Ref::SController &mController, Ref::SFratemodulator &mModulator, Ref::Parameter &parameter, U32 &countPublic, U32 &countMode, F32 &BIASWXRO, F32 &BIASWYPI
    )
  {
    FW_ASSERT(portNum < this->getNum_processOutDataOut_OutputPorts(),static_cast<AssertArg>(portNum));
    this->m_processOutDataOut_OutputPort[portNum].invoke(mAttitude, mDSSData, mode, mController, mModulator, parameter, countPublic, countMode, BIASWXRO, BIASWYPI);
  }

  // ----------------------------------------------------------------------
  // Getters for numbers of ports
  // ----------------------------------------------------------------------

  NATIVE_INT_TYPE ProcessDataComponentBase ::
    getNum_eventOut_OutputPorts()
  {
    return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_eventOut_OutputPort));
  }

  NATIVE_INT_TYPE ProcessDataComponentBase ::
    getNum_processDataIn_InputPorts()
  {
    return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_processDataIn_InputPort));
  }

  NATIVE_INT_TYPE ProcessDataComponentBase ::
    getNum_processInDataOut_OutputPorts()
  {
    return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_processInDataOut_OutputPort));
  }

  NATIVE_INT_TYPE ProcessDataComponentBase ::
    getNum_processOutDataOut_OutputPorts()
  {
    return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_processOutDataOut_OutputPort));
  }

#if FW_ENABLE_TEXT_LOGGING == 1
  NATIVE_INT_TYPE ProcessDataComponentBase ::
    getNum_textEventOut_OutputPorts()
  {
    return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_textEventOut_OutputPort));
  }
#endif

  NATIVE_INT_TYPE ProcessDataComponentBase ::
    getNum_timeGetOut_OutputPorts()
  {
    return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_timeGetOut_OutputPort));
  }

  NATIVE_INT_TYPE ProcessDataComponentBase ::
    getNum_tlmOut_OutputPorts()
  {
    return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_tlmOut_OutputPort));
  }

  // ----------------------------------------------------------------------
  // Port connection status queries
  // ----------------------------------------------------------------------

  bool ProcessDataComponentBase ::
    isConnected_eventOut_OutputPort(NATIVE_INT_TYPE portNum)
  {
     FW_ASSERT(
        portNum < this->getNum_eventOut_OutputPorts(),
        static_cast<AssertArg>(portNum)
     );
     return this->m_eventOut_OutputPort[portNum].isConnected();
  }

  bool ProcessDataComponentBase ::
    isConnected_processInDataOut_OutputPort(NATIVE_INT_TYPE portNum)
  {
     FW_ASSERT(
        portNum < this->getNum_processInDataOut_OutputPorts(),
        static_cast<AssertArg>(portNum)
     );
     return this->m_processInDataOut_OutputPort[portNum].isConnected();
  }

  bool ProcessDataComponentBase ::
    isConnected_processOutDataOut_OutputPort(NATIVE_INT_TYPE portNum)
  {
     FW_ASSERT(
        portNum < this->getNum_processOutDataOut_OutputPorts(),
        static_cast<AssertArg>(portNum)
     );
     return this->m_processOutDataOut_OutputPort[portNum].isConnected();
  }

#if FW_ENABLE_TEXT_LOGGING == 1
  bool ProcessDataComponentBase ::
    isConnected_textEventOut_OutputPort(NATIVE_INT_TYPE portNum)
  {
     FW_ASSERT(
        portNum < this->getNum_textEventOut_OutputPorts(),
        static_cast<AssertArg>(portNum)
     );
     return this->m_textEventOut_OutputPort[portNum].isConnected();
  }
#endif

  bool ProcessDataComponentBase ::
    isConnected_timeGetOut_OutputPort(NATIVE_INT_TYPE portNum)
  {
     FW_ASSERT(
        portNum < this->getNum_timeGetOut_OutputPorts(),
        static_cast<AssertArg>(portNum)
     );
     return this->m_timeGetOut_OutputPort[portNum].isConnected();
  }

  bool ProcessDataComponentBase ::
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

  Fw::Time ProcessDataComponentBase ::
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

  void ProcessDataComponentBase ::
    log_ACTIVITY_LO_PROCESS_DATA(
        
    )
  {


    // Get the time
    Fw::Time _logTime;
    if (this->m_timeGetOut_OutputPort[0].isConnected()) {
       this->m_timeGetOut_OutputPort[0].invoke( _logTime);
    }

    FwEventIdType _id = static_cast<FwEventIdType>(0);

    _id = this->getIdBase() + EVENTID_PROCESS_DATA;

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
          "PROCESS_DATA "
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

  Ref::Parameter ProcessDataComponentBase ::
    m_p_processDataIn_in(
        Fw::PassiveComponentBase* callComp,
        NATIVE_INT_TYPE portNum,
        Ref::SGyroData &mGyroData, Ref::SDSSData &mDSSData, Ref::SThrDistribute &mThrDistribute, Ref::Mode &mode, U32 &countPublic, U32 &countMode, F32 &BIASWXRO, F32 &BIASWYPI, Ref::SFratemodulator &mModulator
    )
  {
    FW_ASSERT(callComp);
    ProcessDataComponentBase* compPtr = static_cast<ProcessDataComponentBase*>(callComp);
    return compPtr->processDataIn_handlerBase(portNum, mGyroData, mDSSData, mThrDistribute, mode, countPublic, countMode, BIASWXRO, BIASWYPI, mModulator);
  }

  // ----------------------------------------------------------------------
  // Port handler base-class functions for typed input ports
  // ----------------------------------------------------------------------

  Ref::Parameter ProcessDataComponentBase ::
    processDataIn_handlerBase(
        NATIVE_INT_TYPE portNum,
        Ref::SGyroData &mGyroData, Ref::SDSSData &mDSSData, Ref::SThrDistribute &mThrDistribute, Ref::Mode &mode, U32 &countPublic, U32 &countMode, F32 &BIASWXRO, F32 &BIASWYPI, Ref::SFratemodulator &mModulator
    )
  {

    // Make sure port number is valid
    FW_ASSERT(portNum < this->getNum_processDataIn_InputPorts(),static_cast<AssertArg>(portNum));
    Ref::Parameter  retVal;

    // Down call to pure virtual handler method implemented in Impl class
    retVal = this->processDataIn_handler(portNum, mGyroData, mDSSData, mThrDistribute, mode, countPublic, countMode, BIASWXRO, BIASWYPI, mModulator);

    return retVal;

  }

} // end namespace Ref
