// ======================================================================
// \title  GetEnvDataComponentAc.hpp
// \author Auto-generated
// \brief  hpp file for GetEnvData component base class
//
// NOTE: this file was automatically generated
//
// ======================================================================

#ifndef GETENVDATA_COMP_HPP_
#define GETENVDATA_COMP_HPP_

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
#include <Ref/GetEnvData/GetEnvDataPortAc.hpp>
#include <Ref/GetEnvData/SDSSDataSerializableAc.hpp>
#include <Ref/GetEnvData/SThrDistributeSerializableAc.hpp>

namespace Ref {

  //! \class GetEnvDataComponentBase
  //! \brief Auto-generated base for GetEnvData component
  //!
  class GetEnvDataComponentBase :
    public Fw::PassiveComponentBase
  {

    // ----------------------------------------------------------------------
    // Friend classes
    // ----------------------------------------------------------------------

    //! Friend class for white-box testing
    //!
    friend class GetEnvDataComponentBaseFriend;

  public:

    // ----------------------------------------------------------------------
    // Getters for typed input ports
    // ----------------------------------------------------------------------

    //! Get input port at index
    //!
    //! \return getEnvDataIn[portNum]
    //!
    Ref::InputGetEnvDataPort* get_getEnvDataIn_InputPort(
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

    //! Construct a GetEnvDataComponentBase object
    //!
    GetEnvDataComponentBase(
        const char* compName = "" /*!< Component name*/
    );

    //! Initialize a GetEnvDataComponentBase object
    //!
    void init(
        NATIVE_INT_TYPE instance = 0 /*!< The instance number*/
    );

    //! Destroy a GetEnvDataComponentBase object
    //!
    virtual ~GetEnvDataComponentBase();

  PROTECTED:

    // ----------------------------------------------------------------------
    // Handlers to implement for typed input ports
    // ----------------------------------------------------------------------

    //! Handler for input port getEnvDataIn
    //
    virtual void getEnvDataIn_handler(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Ref::SGyroData &mGyroData, 
        Ref::SThrDistribute &mThrDistribute, 
        Ref::SDSSData &mDSSData, 
        U32 &sunlight 
    ) = 0;

  PROTECTED:

    // ----------------------------------------------------------------------
    // Port handler base-class functions for typed input ports.
    // ----------------------------------------------------------------------
    // Call these functions directly to bypass the corresponding ports.
    // ----------------------------------------------------------------------

    //! Handler base-class function for input port getEnvDataIn
    //!
    void getEnvDataIn_handlerBase(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Ref::SGyroData &mGyroData, 
        Ref::SThrDistribute &mThrDistribute, 
        Ref::SDSSData &mDSSData, 
        U32 &sunlight 
    );

  PROTECTED:

    // ----------------------------------------------------------------------
    // Getters for numbers of input ports
    // ----------------------------------------------------------------------

    //! Get the number of getEnvDataIn input ports
    //!
    //! \return The number of getEnvDataIn input ports
    //!
    NATIVE_INT_TYPE getNum_getEnvDataIn_InputPorts();


    // ----------------------------------------------------------------------
    // Enumerations for number of ports
    // ----------------------------------------------------------------------

    enum {
       NUM_GETENVDATAIN_INPUT_PORTS = 1,
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
      EVENTID_GET_ENV_DATA = 0x0, /*  */
    };

  PROTECTED:

    // ----------------------------------------------------------------------
    // Event logging functions
    // ----------------------------------------------------------------------

    //! Log event GET_ENV_DATA
    //!
    void log_ACTIVITY_LO_GET_ENV_DATA(

    );


  PROTECTED:

    // ----------------------------------------------------------------------
    // Channel IDs
    // ----------------------------------------------------------------------

    enum {
      CHANNELID_MDSSDATA = 0x0, //!< Channel ID for mDSSData
      CHANNELID_MTHRDISTRIBUTE = 0x1, //!< Channel ID for mThrDistribute
    };

  PROTECTED:

    // ----------------------------------------------------------------------
    // Telemetry write functions
    // ----------------------------------------------------------------------

    //! Write telemetry channel mDSSData
    //!
    void tlmWrite_mDSSData(
        const Ref::SDSSData& arg /*!< The telemetry value*/,
        Fw::Time _tlmTime=Fw::Time() /*!< Timestamp. Default: unspecified, request from getTime port*/
    );

    //! Write telemetry channel mThrDistribute
    //!
    void tlmWrite_mThrDistribute(
        const Ref::SThrDistribute& arg /*!< The telemetry value*/,
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

    //! Input port getEnvDataIn
    //!
    Ref::InputGetEnvDataPort m_getEnvDataIn_InputPort[NUM_GETENVDATAIN_INPUT_PORTS];

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

    //! Callback for port getEnvDataIn
    //!
    static void m_p_getEnvDataIn_in(
        Fw::PassiveComponentBase* callComp, /*!< The component instance*/
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Ref::SGyroData &mGyroData, 
        Ref::SThrDistribute &mThrDistribute, 
        Ref::SDSSData &mDSSData, 
        U32 &sunlight 
    );


  PRIVATE:
    // ----------------------------------------------------------------------
    // Counter values for event throttling
    // ----------------------------------------------------------------------

  };

} // end namespace Ref
#endif
