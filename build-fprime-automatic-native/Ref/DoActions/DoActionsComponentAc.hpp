// ======================================================================
// \title  DoActionsComponentAc.hpp
// \author Auto-generated
// \brief  hpp file for DoActions component base class
//
// NOTE: this file was automatically generated
//
// ======================================================================

#ifndef DOACTIONS_COMP_HPP_
#define DOACTIONS_COMP_HPP_

#include <FpConfig.hpp>
#include <Fw/Port/InputSerializePort.hpp>
#include <Fw/Port/OutputSerializePort.hpp>
#include <Fw/Comp/ActiveComponentBase.hpp>
#include <Fw/Tlm/TlmString.hpp>
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
#include <Ref/DoActions/DoActionsPortAc.hpp>
#include <Ref/ProtectFromSunlight/ProtectFromSunlightPortAc.hpp>
#include <Ref/ThrDistribute/ThrDistributePortAc.hpp>
#include <Ref/DoActions/ActionsSerializableAc.hpp>
#include <Ref/DoActions/ParameterSerializableAc.hpp>

namespace Ref {

  //! \class DoActionsComponentBase
  //! \brief Auto-generated base for DoActions component
  //!
  class DoActionsComponentBase :
    public Fw::PassiveComponentBase
  {

    // ----------------------------------------------------------------------
    // Friend classes
    // ----------------------------------------------------------------------

    //! Friend class for white-box testing
    //!
    friend class DoActionsComponentBaseFriend;

  public:

    // ----------------------------------------------------------------------
    // Getters for typed input ports
    // ----------------------------------------------------------------------

    //! Get input port at index
    //!
    //! \return doActionsIn[portNum]
    //!
    Ref::InputDoActionsPort* get_doActionsIn_InputPort(
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

    //! Connect port to protectFromSunlightOut[portNum]
    //!
    void set_protectFromSunlightOut_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Ref::InputProtectFromSunlightPort *port /*!< The port*/
    );

#if FW_ENABLE_TEXT_LOGGING == 1
    //! Connect port to textEventOut[portNum]
    //!
    void set_textEventOut_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputLogTextPort *port /*!< The port*/
    );
#endif

    //! Connect port to thrDistributeOut[portNum]
    //!
    void set_thrDistributeOut_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Ref::InputThrDistributePort *port /*!< The port*/
    );

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

    //! Connect port to protectFromSunlightOut[portNum]
    //!
    void set_protectFromSunlightOut_OutputPort(
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

    //! Connect port to thrDistributeOut[portNum]
    //!
    void set_thrDistributeOut_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputSerializePort *port /*!< The port*/
    );

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

    //! Construct a DoActionsComponentBase object
    //!
    DoActionsComponentBase(
        const char* compName = "" /*!< Component name*/
    );

    //! Initialize a DoActionsComponentBase object
    //!
    void init(
        NATIVE_INT_TYPE instance = 0 /*!< The instance number*/
    );

    //! Destroy a DoActionsComponentBase object
    //!
    virtual ~DoActionsComponentBase();

  PROTECTED:

    // ----------------------------------------------------------------------
    // Handlers to implement for typed input ports
    // ----------------------------------------------------------------------

    //! Handler for input port doActionsIn
    //
    virtual void doActionsIn_handler(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        const Ref::Actions &actions, 
        const Ref::Parameter &parameter 
    ) = 0;

  PROTECTED:

    // ----------------------------------------------------------------------
    // Port handler base-class functions for typed input ports.
    // ----------------------------------------------------------------------
    // Call these functions directly to bypass the corresponding ports.
    // ----------------------------------------------------------------------

    //! Handler base-class function for input port doActionsIn
    //!
    void doActionsIn_handlerBase(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        const Ref::Actions &actions, 
        const Ref::Parameter &parameter 
    );

  PROTECTED:

    // ----------------------------------------------------------------------
    // Invocation functions for typed output ports
    // ----------------------------------------------------------------------

    //! Invoke output port protectFromSunlightOut
    //!
    void protectFromSunlightOut_out(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );

    //! Invoke output port thrDistributeOut
    //!
    void thrDistributeOut_out(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        U8 wPulse 
    );

  PROTECTED:

    // ----------------------------------------------------------------------
    // Getters for numbers of input ports
    // ----------------------------------------------------------------------

    //! Get the number of doActionsIn input ports
    //!
    //! \return The number of doActionsIn input ports
    //!
    NATIVE_INT_TYPE getNum_doActionsIn_InputPorts();


    // ----------------------------------------------------------------------
    // Enumerations for number of ports
    // ----------------------------------------------------------------------

    enum {
       NUM_DOACTIONSIN_INPUT_PORTS = 1,
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

    //! Get the number of protectFromSunlightOut output ports
    //!
    //! \return The number of protectFromSunlightOut output ports
    //!
    NATIVE_INT_TYPE getNum_protectFromSunlightOut_OutputPorts();

#if FW_ENABLE_TEXT_LOGGING == 1
    //! Get the number of textEventOut output ports
    //!
    //! \return The number of textEventOut output ports
    //!
    NATIVE_INT_TYPE getNum_textEventOut_OutputPorts();
#endif

    //! Get the number of thrDistributeOut output ports
    //!
    //! \return The number of thrDistributeOut output ports
    //!
    NATIVE_INT_TYPE getNum_thrDistributeOut_OutputPorts();

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
       NUM_PROTECTFROMSUNLIGHTOUT_OUTPUT_PORTS = 1,
       NUM_TEXTEVENTOUT_OUTPUT_PORTS = 1,
       NUM_THRDISTRIBUTEOUT_OUTPUT_PORTS = 1,
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

    //! Check whether port protectFromSunlightOut is connected
    //!
    //! \return Whether port protectFromSunlightOut is connected
    //!
    bool isConnected_protectFromSunlightOut_OutputPort(
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

    //! Check whether port thrDistributeOut is connected
    //!
    //! \return Whether port thrDistributeOut is connected
    //!
    bool isConnected_thrDistributeOut_OutputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );

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
      EVENTID_DOACTIONS = 0x0, /*  */
    };

  PROTECTED:

    // ----------------------------------------------------------------------
    // Event logging functions
    // ----------------------------------------------------------------------

    //! Log event DOACTIONS
    //!
    void log_ACTIVITY_LO_DOACTIONS(

    );


  PROTECTED:

    // ----------------------------------------------------------------------
    // Channel IDs
    // ----------------------------------------------------------------------

    enum {
      CHANNELID_ACTIONS = 0x0, //!< Channel ID for ACTIONS
      CHANNELID_PARAMETER = 0x1, //!< Channel ID for PARAMETER
    };

  PROTECTED:

    // ----------------------------------------------------------------------
    // Telemetry write functions
    // ----------------------------------------------------------------------

    //! Write telemetry channel ACTIONS
    //!
    void tlmWrite_ACTIONS(
        const Ref::Actions& arg /*!< The telemetry value*/,
        Fw::Time _tlmTime=Fw::Time() /*!< Timestamp. Default: unspecified, request from getTime port*/
    );

    //! Write telemetry channel PARAMETER
    //!
    void tlmWrite_PARAMETER(
        const Ref::Parameter& arg /*!< The telemetry value*/,
        Fw::Time _tlmTime=Fw::Time() /*!< Timestamp. Default: unspecified, request from getTime port*/
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

    //! Input port doActionsIn
    //!
    Ref::InputDoActionsPort m_doActionsIn_InputPort[NUM_DOACTIONSIN_INPUT_PORTS];

  PRIVATE:

    // ----------------------------------------------------------------------
    // Typed output ports
    // ----------------------------------------------------------------------

    //! Output port eventOut
    //!
    Fw::OutputLogPort m_eventOut_OutputPort[NUM_EVENTOUT_OUTPUT_PORTS];

    //! Output port protectFromSunlightOut
    //!
    Ref::OutputProtectFromSunlightPort m_protectFromSunlightOut_OutputPort[NUM_PROTECTFROMSUNLIGHTOUT_OUTPUT_PORTS];

#if FW_ENABLE_TEXT_LOGGING == 1
    //! Output port textEventOut
    //!
    Fw::OutputLogTextPort m_textEventOut_OutputPort[NUM_TEXTEVENTOUT_OUTPUT_PORTS];
#endif

    //! Output port thrDistributeOut
    //!
    Ref::OutputThrDistributePort m_thrDistributeOut_OutputPort[NUM_THRDISTRIBUTEOUT_OUTPUT_PORTS];

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

    //! Callback for port doActionsIn
    //!
    static void m_p_doActionsIn_in(
        Fw::PassiveComponentBase* callComp, /*!< The component instance*/
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        const Ref::Actions &actions, 
        const Ref::Parameter &parameter 
    );


  PRIVATE:
    // ----------------------------------------------------------------------
    // Counter values for event throttling
    // ----------------------------------------------------------------------

  };

} // end namespace Ref
#endif
