// ======================================================================
// \title  ThrDistributeComponentAc.hpp
// \author Auto-generated
// \brief  hpp file for ThrDistribute component base class
//
// NOTE: this file was automatically generated
//
// ======================================================================

#ifndef THRDISTRIBUTE_COMP_HPP_
#define THRDISTRIBUTE_COMP_HPP_

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
#include <Ref/ThrDistribute/ThrDistributePortAc.hpp>
#include <Svc/Sched/SchedPortAc.hpp>

namespace Ref {

  //! \class ThrDistributeComponentBase
  //! \brief Auto-generated base for ThrDistribute component
  //!
  class ThrDistributeComponentBase :
    public Fw::QueuedComponentBase
  {

    // ----------------------------------------------------------------------
    // Friend classes
    // ----------------------------------------------------------------------

    //! Friend class for white-box testing
    //!
    friend class ThrDistributeComponentBaseFriend;

  public:

    // ----------------------------------------------------------------------
    // Getters for typed input ports
    // ----------------------------------------------------------------------

    //! Get input port at index
    //!
    //! \return schedIn[portNum]
    //!
    Svc::InputSchedPort* get_schedIn_InputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );

    //! Get input port at index
    //!
    //! \return thrDistributeIn[portNum]
    //!
    Ref::InputThrDistributePort* get_thrDistributeIn_InputPort(
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

    //! Construct a ThrDistributeComponentBase object
    //!
    ThrDistributeComponentBase(
        const char* compName = "" /*!< Component name*/
    );

    //! Initialize a ThrDistributeComponentBase object
    //!
    void init(
        NATIVE_INT_TYPE queueDepth, /*!< The queue depth*/
        NATIVE_INT_TYPE instance = 0 /*!< The instance number*/
    );

    //! Destroy a ThrDistributeComponentBase object
    //!
    virtual ~ThrDistributeComponentBase();

  PROTECTED:

    // ----------------------------------------------------------------------
    // Handlers to implement for typed input ports
    // ----------------------------------------------------------------------

    //! Handler for input port schedIn
    //
    virtual void schedIn_handler(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        NATIVE_UINT_TYPE context /*!< 
      The call order
      */
    ) = 0;

    //! Handler for input port thrDistributeIn
    //
    virtual void thrDistributeIn_handler(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        U8 wPulse 
    ) = 0;

  PROTECTED:

    // ----------------------------------------------------------------------
    // Port handler base-class functions for typed input ports.
    // ----------------------------------------------------------------------
    // Call these functions directly to bypass the corresponding ports.
    // ----------------------------------------------------------------------

    //! Handler base-class function for input port schedIn
    //!
    void schedIn_handlerBase(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        NATIVE_UINT_TYPE context /*!< 
      The call order
      */
    );

    //! Handler base-class function for input port thrDistributeIn
    //!
    void thrDistributeIn_handlerBase(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        U8 wPulse 
    );

  PROTECTED:

    // ----------------------------------------------------------------------
    // Pre-message hooks for typed async input ports.
    // ----------------------------------------------------------------------
    // Each of these functions is invoked just before processing a message
    // on the corresponding port. By default they do nothing. You can
    // override them to provide specific pre-message behavior.
    // ----------------------------------------------------------------------

    //! Pre-message hook for async input port thrDistributeIn
    //!
    virtual void thrDistributeIn_preMsgHook(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        U8 wPulse 
    );

  PROTECTED:

    // ----------------------------------------------------------------------
    // Getters for numbers of input ports
    // ----------------------------------------------------------------------

    //! Get the number of schedIn input ports
    //!
    //! \return The number of schedIn input ports
    //!
    NATIVE_INT_TYPE getNum_schedIn_InputPorts();

    //! Get the number of thrDistributeIn input ports
    //!
    //! \return The number of thrDistributeIn input ports
    //!
    NATIVE_INT_TYPE getNum_thrDistributeIn_InputPorts();


    // ----------------------------------------------------------------------
    // Enumerations for number of ports
    // ----------------------------------------------------------------------

    enum {
       NUM_SCHEDIN_INPUT_PORTS = 1,
       NUM_THRDISTRIBUTEIN_INPUT_PORTS = 1,
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
    // Message dispatch
    // ----------------------------------------------------------------------

    //! Dispatch a message on the queue
    //!
    virtual MsgDispatchStatus doDispatch();

  PROTECTED:

    // ----------------------------------------------------------------------
    // Event IDs
    // ----------------------------------------------------------------------

    enum {
      EVENTID_THRUSTER = 0x0, /*  */
      EVENTID_DOTHRUSTER = 0x1, /*  */
    };

  PROTECTED:

    // ----------------------------------------------------------------------
    // Event logging functions
    // ----------------------------------------------------------------------

    //! Log event THRUSTER
    //!
    void log_ACTIVITY_LO_THRUSTER(
        U8 val 
    );


    //! Log event DOTHRUSTER
    //!
    void log_ACTIVITY_LO_DOTHRUSTER(

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

    //! Input port schedIn
    //!
    Svc::InputSchedPort m_schedIn_InputPort[NUM_SCHEDIN_INPUT_PORTS];

    //! Input port thrDistributeIn
    //!
    Ref::InputThrDistributePort m_thrDistributeIn_InputPort[NUM_THRDISTRIBUTEIN_INPUT_PORTS];

  PRIVATE:

    // ----------------------------------------------------------------------
    // Typed output ports
    // ----------------------------------------------------------------------

    //! Output port eventOut
    //!
    Fw::OutputLogPort m_eventOut_OutputPort[NUM_EVENTOUT_OUTPUT_PORTS];

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

    //! Callback for port schedIn
    //!
    static void m_p_schedIn_in(
        Fw::PassiveComponentBase* callComp, /*!< The component instance*/
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        NATIVE_UINT_TYPE context /*!< 
      The call order
      */
    );

    //! Callback for port thrDistributeIn
    //!
    static void m_p_thrDistributeIn_in(
        Fw::PassiveComponentBase* callComp, /*!< The component instance*/
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        U8 wPulse 
    );


  PRIVATE:
    // ----------------------------------------------------------------------
    // Counter values for event throttling
    // ----------------------------------------------------------------------

  };

} // end namespace Ref
#endif
