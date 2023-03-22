// ======================================================================
// \title  ProcessDataComponentAc.hpp
// \author Auto-generated
// \brief  hpp file for ProcessData component base class
//
// NOTE: this file was automatically generated
//
// ======================================================================

#ifndef PROCESSDATA_COMP_HPP_
#define PROCESSDATA_COMP_HPP_

#include <FpConfig.hpp>
#include <Fw/Port/InputSerializePort.hpp>
#include <Fw/Port/OutputSerializePort.hpp>
#include <Fw/Comp/ActiveComponentBase.hpp>
#include <Fw/Time/TimePortAc.hpp>
#include <Fw/Log/LogString.hpp>
#include <Fw/Log/LogBuffer.hpp>
#include <Fw/Time/Time.hpp>
#include <Fw/Log/TextLogString.hpp>
#include <Fw/Tlm/TlmBuffer.hpp>
#include <Fw/Log/LogPortAc.hpp>
#if FW_ENABLE_TEXT_LOGGING == 1
#include <Fw/Log/LogTextPortAc.hpp>
#endif
#include <Fw/Time/TimePortAc.hpp>
#include <Fw/Tlm/TlmPortAc.hpp>
#include <Ref/ProcessData/ProcessDataPortAc.hpp>
#include <Ref/ProcessInData/ProcessInDataPortAc.hpp>
#include <Ref/ProcessOutData/ProcessOutDataPortAc.hpp>

namespace Ref {

  //! \class ProcessDataComponentBase
  //! \brief Auto-generated base for ProcessData component
  //!
  class ProcessDataComponentBase :
    public Fw::PassiveComponentBase
  {

    // ----------------------------------------------------------------------
    // Friend classes
    // ----------------------------------------------------------------------

    //! Friend class for white-box testing
    //!
    friend class ProcessDataComponentBaseFriend;

  public:

    // ----------------------------------------------------------------------
    // Getters for typed input ports
    // ----------------------------------------------------------------------

    //! Get input port at index
    //!
    //! \return processDataIn[portNum]
    //!
    Ref::InputProcessDataPort* get_processDataIn_InputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );

  public:

    // ----------------------------------------------------------------------
    // Connect typed input ports to typed output ports
    // ----------------------------------------------------------------------

    //! Connect port to eventOut[portNum]
    //!
    void set_eventOut_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputLogPort *port /*!< The port*/
    );

    //! Connect port to processInDataOut[portNum]
    //!
    void set_processInDataOut_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Ref::InputProcessInDataPort *port /*!< The port*/
    );

    //! Connect port to processOutDataOut[portNum]
    //!
    void set_processOutDataOut_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Ref::InputProcessOutDataPort *port /*!< The port*/
    );

#if FW_ENABLE_TEXT_LOGGING == 1
    //! Connect port to textEventOut[portNum]
    //!
    void set_textEventOut_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputLogTextPort *port /*!< The port*/
    );
#endif

    //! Connect port to timeGetOut[portNum]
    //!
    void set_timeGetOut_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputTimePort *port /*!< The port*/
    );

    //! Connect port to tlmOut[portNum]
    //!
    void set_tlmOut_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputTlmPort *port /*!< The port*/
    );

#if FW_PORT_SERIALIZATION

  public:

    // ----------------------------------------------------------------------
    // Connect serialization input ports to typed output ports
    // ----------------------------------------------------------------------

    //! Connect port to eventOut[portNum]
    //!
    void set_eventOut_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputSerializePort *port /*!< The port*/
    );

    //! Connect port to processInDataOut[portNum]
    //!
    void set_processInDataOut_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputSerializePort *port /*!< The port*/
    );

    //! Connect port to processOutDataOut[portNum]
    //!
    void set_processOutDataOut_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputSerializePort *port /*!< The port*/
    );

#if FW_ENABLE_TEXT_LOGGING == 1
    //! Connect port to textEventOut[portNum]
    //!
    void set_textEventOut_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputSerializePort *port /*!< The port*/
    );
#endif

    //! Connect port to timeGetOut[portNum]
    //!
    void set_timeGetOut_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputSerializePort *port /*!< The port*/
    );

    //! Connect port to tlmOut[portNum]
    //!
    void set_tlmOut_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputSerializePort *port /*!< The port*/
    );

#endif

  PROTECTED:

    // ----------------------------------------------------------------------
    // Component construction, initialization, and destruction
    // ----------------------------------------------------------------------

    //! Construct a ProcessDataComponentBase object
    //!
    ProcessDataComponentBase(
        const char* compName = "" /*!< Component name*/
    );

    //! Initialize a ProcessDataComponentBase object
    //!
    void init(
        NATIVE_INT_TYPE instance = 0 /*!< The instance number*/
    );

    //! Destroy a ProcessDataComponentBase object
    //!
    virtual ~ProcessDataComponentBase();

  PROTECTED:

    // ----------------------------------------------------------------------
    // Handlers to implement for typed input ports
    // ----------------------------------------------------------------------

    //! Handler for input port processDataIn
    //
    virtual Ref::Parameter processDataIn_handler(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Ref::SGyroData &mGyroData, 
        Ref::SDSSData &mDSSData, 
        Ref::SThrDistribute &mThrDistribute, 
        Ref::Mode &mode, 
        U32 &countPublic, 
        U32 &countMode, 
        F32 &BIASWXRO, 
        F32 &BIASWYPI, 
        Ref::SFratemodulator &mModulator 
    ) = 0;

  PROTECTED:

    // ----------------------------------------------------------------------
    // Port handler base-class functions for typed input ports.
    // ----------------------------------------------------------------------
    // Call these functions directly to bypass the corresponding ports.
    // ----------------------------------------------------------------------

    //! Handler base-class function for input port processDataIn
    //!
    Ref::Parameter processDataIn_handlerBase(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Ref::SGyroData &mGyroData, 
        Ref::SDSSData &mDSSData, 
        Ref::SThrDistribute &mThrDistribute, 
        Ref::Mode &mode, 
        U32 &countPublic, 
        U32 &countMode, 
        F32 &BIASWXRO, 
        F32 &BIASWYPI, 
        Ref::SFratemodulator &mModulator 
    );

  PROTECTED:

    // ----------------------------------------------------------------------
    // Invocation functions for typed output ports
    // ----------------------------------------------------------------------

    //! Invoke output port processInDataOut
    //!
    void processInDataOut_out(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Ref::SGyroData &mGyroData, 
        const Ref::SDSSData &mDSSData, 
        const Ref::SThrDistribute &mThrDistribute, 
        Ref::SAttitude &mAttitude, 
        const Ref::Mode &mode 
    );

    //! Invoke output port processOutDataOut
    //!
    void processOutDataOut_out(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        const Ref::SAttitude &mAttitude, 
        const Ref::SDSSData &mDSSData, 
        Ref::Mode &mode, 
        Ref::SController &mController, 
        Ref::SFratemodulator &mModulator, 
        Ref::Parameter &parameter, 
        U32 &countPublic, 
        U32 &countMode, 
        F32 &BIASWXRO, 
        F32 &BIASWYPI 
    );

  PROTECTED:

    // ----------------------------------------------------------------------
    // Getters for numbers of input ports
    // ----------------------------------------------------------------------

    //! Get the number of processDataIn input ports
    //!
    //! \return The number of processDataIn input ports
    //!
    NATIVE_INT_TYPE getNum_processDataIn_InputPorts();


    // ----------------------------------------------------------------------
    // Enumerations for number of ports
    // ----------------------------------------------------------------------

    enum {
       NUM_PROCESSDATAIN_INPUT_PORTS = 1,
    };

  PROTECTED:

    // ----------------------------------------------------------------------
    // Getters for numbers of output ports
    // ----------------------------------------------------------------------

    //! Get the number of eventOut output ports
    //!
    //! \return The number of eventOut output ports
    //!
    NATIVE_INT_TYPE getNum_eventOut_OutputPorts();

    //! Get the number of processInDataOut output ports
    //!
    //! \return The number of processInDataOut output ports
    //!
    NATIVE_INT_TYPE getNum_processInDataOut_OutputPorts();

    //! Get the number of processOutDataOut output ports
    //!
    //! \return The number of processOutDataOut output ports
    //!
    NATIVE_INT_TYPE getNum_processOutDataOut_OutputPorts();

#if FW_ENABLE_TEXT_LOGGING == 1
    //! Get the number of textEventOut output ports
    //!
    //! \return The number of textEventOut output ports
    //!
    NATIVE_INT_TYPE getNum_textEventOut_OutputPorts();
#endif

    //! Get the number of timeGetOut output ports
    //!
    //! \return The number of timeGetOut output ports
    //!
    NATIVE_INT_TYPE getNum_timeGetOut_OutputPorts();

    //! Get the number of tlmOut output ports
    //!
    //! \return The number of tlmOut output ports
    //!
    NATIVE_INT_TYPE getNum_tlmOut_OutputPorts();


    enum {
       NUM_EVENTOUT_OUTPUT_PORTS = 1,
       NUM_PROCESSINDATAOUT_OUTPUT_PORTS = 1,
       NUM_PROCESSOUTDATAOUT_OUTPUT_PORTS = 1,
       NUM_TEXTEVENTOUT_OUTPUT_PORTS = 1,
       NUM_TIMEGETOUT_OUTPUT_PORTS = 1,
       NUM_TLMOUT_OUTPUT_PORTS = 1,
    };

  PROTECTED:

    // ----------------------------------------------------------------------
    // Connection status queries for output ports
    // ----------------------------------------------------------------------

    //! Check whether port eventOut is connected
    //!
    //! \return Whether port eventOut is connected
    //!
    bool isConnected_eventOut_OutputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );

    //! Check whether port processInDataOut is connected
    //!
    //! \return Whether port processInDataOut is connected
    //!
    bool isConnected_processInDataOut_OutputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );

    //! Check whether port processOutDataOut is connected
    //!
    //! \return Whether port processOutDataOut is connected
    //!
    bool isConnected_processOutDataOut_OutputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );

#if FW_ENABLE_TEXT_LOGGING == 1
    //! Check whether port textEventOut is connected
    //!
    //! \return Whether port textEventOut is connected
    //!
    bool isConnected_textEventOut_OutputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );
#endif

    //! Check whether port timeGetOut is connected
    //!
    //! \return Whether port timeGetOut is connected
    //!
    bool isConnected_timeGetOut_OutputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );

    //! Check whether port tlmOut is connected
    //!
    //! \return Whether port tlmOut is connected
    //!
    bool isConnected_tlmOut_OutputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );

  PROTECTED:

    // ----------------------------------------------------------------------
    // Event IDs
    // ----------------------------------------------------------------------

    enum {
      EVENTID_PROCESS_DATA = 0x0, /*  */
    };

  PROTECTED:

    // ----------------------------------------------------------------------
    // Event logging functions
    // ----------------------------------------------------------------------

    //! Log event PROCESS_DATA
    //!
    void log_ACTIVITY_LO_PROCESS_DATA(

    );


  PROTECTED:

    // ----------------------------------------------------------------------
    // Time
    // ----------------------------------------------------------------------

    //! Get the time
    //!
    //! \return The current time
    //!
    Fw::Time getTime();



  PRIVATE:

    // ----------------------------------------------------------------------
    // Typed input ports
    // ----------------------------------------------------------------------

    //! Input port processDataIn
    //!
    Ref::InputProcessDataPort m_processDataIn_InputPort[NUM_PROCESSDATAIN_INPUT_PORTS];

  PRIVATE:

    // ----------------------------------------------------------------------
    // Typed output ports
    // ----------------------------------------------------------------------

    //! Output port eventOut
    //!
    Fw::OutputLogPort m_eventOut_OutputPort[NUM_EVENTOUT_OUTPUT_PORTS];

    //! Output port processInDataOut
    //!
    Ref::OutputProcessInDataPort m_processInDataOut_OutputPort[NUM_PROCESSINDATAOUT_OUTPUT_PORTS];

    //! Output port processOutDataOut
    //!
    Ref::OutputProcessOutDataPort m_processOutDataOut_OutputPort[NUM_PROCESSOUTDATAOUT_OUTPUT_PORTS];

#if FW_ENABLE_TEXT_LOGGING == 1
    //! Output port textEventOut
    //!
    Fw::OutputLogTextPort m_textEventOut_OutputPort[NUM_TEXTEVENTOUT_OUTPUT_PORTS];
#endif

    //! Output port timeGetOut
    //!
    Fw::OutputTimePort m_timeGetOut_OutputPort[NUM_TIMEGETOUT_OUTPUT_PORTS];

    //! Output port tlmOut
    //!
    Fw::OutputTlmPort m_tlmOut_OutputPort[NUM_TLMOUT_OUTPUT_PORTS];

  PRIVATE:

    // ----------------------------------------------------------------------
    // Calls for messages received on typed input ports
    // ----------------------------------------------------------------------

    //! Callback for port processDataIn
    //!
    static Ref::Parameter m_p_processDataIn_in(
        Fw::PassiveComponentBase* callComp, /*!< The component instance*/
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Ref::SGyroData &mGyroData, 
        Ref::SDSSData &mDSSData, 
        Ref::SThrDistribute &mThrDistribute, 
        Ref::Mode &mode, 
        U32 &countPublic, 
        U32 &countMode, 
        F32 &BIASWXRO, 
        F32 &BIASWYPI, 
        Ref::SFratemodulator &mModulator 
    );


  PRIVATE:
    // ----------------------------------------------------------------------
    // Counter values for event throttling
    // ----------------------------------------------------------------------

  };

} // end namespace Ref
#endif
