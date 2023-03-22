// ======================================================================
// \title  SetSensorStateComponentAc.hpp
// \author Auto-generated
// \brief  hpp file for SetSensorState component base class
//
// NOTE: this file was automatically generated
//
// ======================================================================

#ifndef SETSENSORSTATE_COMP_HPP_
#define SETSENSORSTATE_COMP_HPP_

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
#include <Ref/GetCtrlData/GetCtrlDataPortAc.hpp>
#include <Ref/GetEnvData/GetEnvDataPortAc.hpp>
#include <Ref/ProcessData/ProcessDataPortAc.hpp>
#include <Ref/SetSensorState/SetSensorStatePortAc.hpp>
#include <Ref/DoActions/ParameterSerializableAc.hpp>

namespace Ref {

  //! \class SetSensorStateComponentBase
  //! \brief Auto-generated base for SetSensorState component
  //!
  class SetSensorStateComponentBase :
    public Fw::PassiveComponentBase
  {

    // ----------------------------------------------------------------------
    // Friend classes
    // ----------------------------------------------------------------------

    //! Friend class for white-box testing
    //!
    friend class SetSensorStateComponentBaseFriend;

  public:

    // ----------------------------------------------------------------------
    // Getters for typed input ports
    // ----------------------------------------------------------------------

    //! Get input port at index
    //!
    //! \return setSensorStateIn[portNum]
    //!
    Ref::InputSetSensorStatePort* get_setSensorStateIn_InputPort(
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

    //! Connect port to getCtrlDataOut[portNum]
    //!
    void set_getCtrlDataOut_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Ref::InputGetCtrlDataPort *port /*!< The port*/
    );

    //! Connect port to getEnvDataOut[portNum]
    //!
    void set_getEnvDataOut_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Ref::InputGetEnvDataPort *port /*!< The port*/
    );

    //! Connect port to processDataOut[portNum]
    //!
    void set_processDataOut_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Ref::InputProcessDataPort *port /*!< The port*/
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

    //! Connect port to getCtrlDataOut[portNum]
    //!
    void set_getCtrlDataOut_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputSerializePort *port /*!< The port*/
    );

    //! Connect port to getEnvDataOut[portNum]
    //!
    void set_getEnvDataOut_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputSerializePort *port /*!< The port*/
    );

    //! Connect port to processDataOut[portNum]
    //!
    void set_processDataOut_OutputPort(
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

    //! Construct a SetSensorStateComponentBase object
    //!
    SetSensorStateComponentBase(
        const char* compName = "" /*!< Component name*/
    );

    //! Initialize a SetSensorStateComponentBase object
    //!
    void init(
        NATIVE_INT_TYPE instance = 0 /*!< The instance number*/
    );

    //! Destroy a SetSensorStateComponentBase object
    //!
    virtual ~SetSensorStateComponentBase();

  PROTECTED:

    // ----------------------------------------------------------------------
    // Handlers to implement for typed input ports
    // ----------------------------------------------------------------------

    //! Handler for input port setSensorStateIn
    //
    virtual Ref::Parameter setSensorStateIn_handler(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Ref::SGyroData &mGyroData, 
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

    //! Handler base-class function for input port setSensorStateIn
    //!
    Ref::Parameter setSensorStateIn_handlerBase(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Ref::SGyroData &mGyroData, 
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

    //! Invoke output port getCtrlDataOut
    //!
    void getCtrlDataOut_out(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Ref::Mode &mode 
    );

    //! Invoke output port getEnvDataOut
    //!
    void getEnvDataOut_out(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Ref::SGyroData &mGyroData, 
        Ref::SThrDistribute &mThrDistribute, 
        Ref::SDSSData &mDSSData, 
        U32 &sunlight 
    );

    //! Invoke output port processDataOut
    //!
    Ref::Parameter processDataOut_out(
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
    // Getters for numbers of input ports
    // ----------------------------------------------------------------------

    //! Get the number of setSensorStateIn input ports
    //!
    //! \return The number of setSensorStateIn input ports
    //!
    NATIVE_INT_TYPE getNum_setSensorStateIn_InputPorts();


    // ----------------------------------------------------------------------
    // Enumerations for number of ports
    // ----------------------------------------------------------------------

    enum {
       NUM_SETSENSORSTATEIN_INPUT_PORTS = 1,
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

    //! Get the number of getCtrlDataOut output ports
    //!
    //! \return The number of getCtrlDataOut output ports
    //!
    NATIVE_INT_TYPE getNum_getCtrlDataOut_OutputPorts();

    //! Get the number of getEnvDataOut output ports
    //!
    //! \return The number of getEnvDataOut output ports
    //!
    NATIVE_INT_TYPE getNum_getEnvDataOut_OutputPorts();

    //! Get the number of processDataOut output ports
    //!
    //! \return The number of processDataOut output ports
    //!
    NATIVE_INT_TYPE getNum_processDataOut_OutputPorts();

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
       NUM_GETCTRLDATAOUT_OUTPUT_PORTS = 1,
       NUM_GETENVDATAOUT_OUTPUT_PORTS = 1,
       NUM_PROCESSDATAOUT_OUTPUT_PORTS = 1,
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

    //! Check whether port getCtrlDataOut is connected
    //!
    //! \return Whether port getCtrlDataOut is connected
    //!
    bool isConnected_getCtrlDataOut_OutputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );

    //! Check whether port getEnvDataOut is connected
    //!
    //! \return Whether port getEnvDataOut is connected
    //!
    bool isConnected_getEnvDataOut_OutputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );

    //! Check whether port processDataOut is connected
    //!
    //! \return Whether port processDataOut is connected
    //!
    bool isConnected_processDataOut_OutputPort(
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
      EVENTID_SET_SENSOR_STATE = 0x0, /*  */
    };

  PROTECTED:

    // ----------------------------------------------------------------------
    // Event logging functions
    // ----------------------------------------------------------------------

    //! Log event SET_SENSOR_STATE
    //!
    void log_ACTIVITY_LO_SET_SENSOR_STATE(

    );


  PROTECTED:

    // ----------------------------------------------------------------------
    // Channel IDs
    // ----------------------------------------------------------------------

    enum {
      CHANNELID_PARAMETER = 0x0, //!< Channel ID for PARAMETER
      CHANNELID_SUNLIGHT = 0x1, //!< Channel ID for SUNLIGHT
    };

  PROTECTED:

    // ----------------------------------------------------------------------
    // Telemetry write functions
    // ----------------------------------------------------------------------

    //! Write telemetry channel PARAMETER
    //!
    void tlmWrite_PARAMETER(
        const Ref::Parameter& arg /*!< The telemetry value*/,
        Fw::Time _tlmTime=Fw::Time() /*!< Timestamp. Default: unspecified, request from getTime port*/
    );

    //! Write telemetry channel SUNLIGHT
    //!
    void tlmWrite_SUNLIGHT(
        U32 arg /*!< The telemetry value*/,
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

    //! Input port setSensorStateIn
    //!
    Ref::InputSetSensorStatePort m_setSensorStateIn_InputPort[NUM_SETSENSORSTATEIN_INPUT_PORTS];

  PRIVATE:

    // ----------------------------------------------------------------------
    // Typed output ports
    // ----------------------------------------------------------------------

    //! Output port eventOut
    //!
    Fw::OutputLogPort m_eventOut_OutputPort[NUM_EVENTOUT_OUTPUT_PORTS];

    //! Output port getCtrlDataOut
    //!
    Ref::OutputGetCtrlDataPort m_getCtrlDataOut_OutputPort[NUM_GETCTRLDATAOUT_OUTPUT_PORTS];

    //! Output port getEnvDataOut
    //!
    Ref::OutputGetEnvDataPort m_getEnvDataOut_OutputPort[NUM_GETENVDATAOUT_OUTPUT_PORTS];

    //! Output port processDataOut
    //!
    Ref::OutputProcessDataPort m_processDataOut_OutputPort[NUM_PROCESSDATAOUT_OUTPUT_PORTS];

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

    //! Callback for port setSensorStateIn
    //!
    static Ref::Parameter m_p_setSensorStateIn_in(
        Fw::PassiveComponentBase* callComp, /*!< The component instance*/
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Ref::SGyroData &mGyroData, 
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
