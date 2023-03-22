// ======================================================================
// \title  ProcessInDataComponentAc.hpp
// \author Auto-generated
// \brief  hpp file for ProcessInData component base class
//
// NOTE: this file was automatically generated
//
// ======================================================================

#ifndef PROCESSINDATA_COMP_HPP_
#define PROCESSINDATA_COMP_HPP_

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
#include <Ref/ProcessInData/ProcessInDataPortAc.hpp>

namespace Ref {

  //! \class ProcessInDataComponentBase
  //! \brief Auto-generated base for ProcessInData component
  //!
  class ProcessInDataComponentBase :
    public Fw::PassiveComponentBase
  {

    // ----------------------------------------------------------------------
    // Friend classes
    // ----------------------------------------------------------------------

    //! Friend class for white-box testing
    //!
    friend class ProcessInDataComponentBaseFriend;

  public:

    // ----------------------------------------------------------------------
    // Getters for typed input ports
    // ----------------------------------------------------------------------

    //! Get input port at index
    //!
    //! \return processInDataIn[portNum]
    //!
    Ref::InputProcessInDataPort* get_processInDataIn_InputPort(
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

    //! Construct a ProcessInDataComponentBase object
    //!
    ProcessInDataComponentBase(
        const char* compName = "" /*!< Component name*/
    );

    //! Initialize a ProcessInDataComponentBase object
    //!
    void init(
        NATIVE_INT_TYPE instance = 0 /*!< The instance number*/
    );

    //! Destroy a ProcessInDataComponentBase object
    //!
    virtual ~ProcessInDataComponentBase();

  PROTECTED:

    // ----------------------------------------------------------------------
    // Handlers to implement for typed input ports
    // ----------------------------------------------------------------------

    //! Handler for input port processInDataIn
    //
    virtual void processInDataIn_handler(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Ref::SGyroData &mGyroData, 
        const Ref::SDSSData &mDSSData, 
        const Ref::SThrDistribute &mThrDistribute, 
        Ref::SAttitude &mAttitude, 
        const Ref::Mode &mode 
    ) = 0;

  PROTECTED:

    // ----------------------------------------------------------------------
    // Port handler base-class functions for typed input ports.
    // ----------------------------------------------------------------------
    // Call these functions directly to bypass the corresponding ports.
    // ----------------------------------------------------------------------

    //! Handler base-class function for input port processInDataIn
    //!
    void processInDataIn_handlerBase(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Ref::SGyroData &mGyroData, 
        const Ref::SDSSData &mDSSData, 
        const Ref::SThrDistribute &mThrDistribute, 
        Ref::SAttitude &mAttitude, 
        const Ref::Mode &mode 
    );

  PROTECTED:

    // ----------------------------------------------------------------------
    // Getters for numbers of input ports
    // ----------------------------------------------------------------------

    //! Get the number of processInDataIn input ports
    //!
    //! \return The number of processInDataIn input ports
    //!
    NATIVE_INT_TYPE getNum_processInDataIn_InputPorts();


    // ----------------------------------------------------------------------
    // Enumerations for number of ports
    // ----------------------------------------------------------------------

    enum {
       NUM_PROCESSINDATAIN_INPUT_PORTS = 1,
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
    // Event IDs
    // ----------------------------------------------------------------------

    enum {
      EVENTID_PROCESS_IN_DATA = 0x0, /*  */
    };

  PROTECTED:

    // ----------------------------------------------------------------------
    // Event logging functions
    // ----------------------------------------------------------------------

    //! Log event PROCESS_IN_DATA
    //!
    void log_ACTIVITY_LO_PROCESS_IN_DATA(

    );


  PROTECTED:

    // ----------------------------------------------------------------------
    // Channel IDs
    // ----------------------------------------------------------------------

    enum {
      CHANNELID_ANGLE1 = 0x0, //!< Channel ID for angle1
      CHANNELID_ANGLE2 = 0x1, //!< Channel ID for angle2
      CHANNELID_ANGLE3 = 0x2, //!< Channel ID for angle3
      CHANNELID_RATE1 = 0x3, //!< Channel ID for rate1
      CHANNELID_RATE2 = 0x4, //!< Channel ID for rate2
      CHANNELID_RATE3 = 0x5, //!< Channel ID for rate3
    };

  PROTECTED:

    // ----------------------------------------------------------------------
    // Telemetry write functions
    // ----------------------------------------------------------------------

    //! Write telemetry channel angle1
    //!
    void tlmWrite_angle1(
        F32 arg /*!< The telemetry value*/,
        Fw::Time _tlmTime=Fw::Time() /*!< Timestamp. Default: unspecified, request from getTime port*/
    );

    //! Write telemetry channel angle2
    //!
    void tlmWrite_angle2(
        F32 arg /*!< The telemetry value*/,
        Fw::Time _tlmTime=Fw::Time() /*!< Timestamp. Default: unspecified, request from getTime port*/
    );

    //! Write telemetry channel angle3
    //!
    void tlmWrite_angle3(
        F32 arg /*!< The telemetry value*/,
        Fw::Time _tlmTime=Fw::Time() /*!< Timestamp. Default: unspecified, request from getTime port*/
    );

    //! Write telemetry channel rate1
    //!
    void tlmWrite_rate1(
        F32 arg /*!< The telemetry value*/,
        Fw::Time _tlmTime=Fw::Time() /*!< Timestamp. Default: unspecified, request from getTime port*/
    );

    //! Write telemetry channel rate2
    //!
    void tlmWrite_rate2(
        F32 arg /*!< The telemetry value*/,
        Fw::Time _tlmTime=Fw::Time() /*!< Timestamp. Default: unspecified, request from getTime port*/
    );

    //! Write telemetry channel rate3
    //!
    void tlmWrite_rate3(
        F32 arg /*!< The telemetry value*/,
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

    //! Input port processInDataIn
    //!
    Ref::InputProcessInDataPort m_processInDataIn_InputPort[NUM_PROCESSINDATAIN_INPUT_PORTS];

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

    //! Callback for port processInDataIn
    //!
    static void m_p_processInDataIn_in(
        Fw::PassiveComponentBase* callComp, /*!< The component instance*/
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Ref::SGyroData &mGyroData, 
        const Ref::SDSSData &mDSSData, 
        const Ref::SThrDistribute &mThrDistribute, 
        Ref::SAttitude &mAttitude, 
        const Ref::Mode &mode 
    );


  PRIVATE:
    // ----------------------------------------------------------------------
    // Counter values for event throttling
    // ----------------------------------------------------------------------

  };

} // end namespace Ref
#endif
