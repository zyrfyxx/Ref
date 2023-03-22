// ======================================================================
// \title  RecvBuffComponentAc.hpp
// \author Auto-generated
// \brief  hpp file for RecvBuff component base class
//
// NOTE: this file was automatically generated
//
// ======================================================================

#ifndef RECVBUFF_COMP_HPP_
#define RECVBUFF_COMP_HPP_

#include <FpConfig.hpp>
#include <Fw/Port/InputSerializePort.hpp>
#include <Fw/Port/OutputSerializePort.hpp>
#include <Fw/Comp/ActiveComponentBase.hpp>
#include <Os/Mutex.hpp>
#include <Fw/Cmd/CmdString.hpp>
#include <Fw/Tlm/TlmString.hpp>
#include <Fw/Time/TimePortAc.hpp>
#include <Fw/Prm/PrmString.hpp>
#include <Fw/Log/LogString.hpp>
#include <Fw/Cmd/CmdArgBuffer.hpp>
#include <Drv/DataTypes/DataBuffer.hpp>
#include <Fw/Log/LogBuffer.hpp>
#include <Fw/Time/Time.hpp>
#include <Fw/Log/TextLogString.hpp>
#include <Fw/Prm/ParamBuffer.hpp>
#include <Fw/Tlm/TlmBuffer.hpp>
#include <Drv/DataTypes/DataBufferPortAc.hpp>
#include <Fw/Cmd/CmdPortAc.hpp>
#include <Fw/Cmd/CmdRegPortAc.hpp>
#include <Fw/Cmd/CmdResponsePortAc.hpp>
#include <Fw/Log/LogPortAc.hpp>
#if FW_ENABLE_TEXT_LOGGING == 1
#include <Fw/Log/LogTextPortAc.hpp>
#endif
#include <Fw/Prm/PrmGetPortAc.hpp>
#include <Fw/Prm/PrmSetPortAc.hpp>
#include <Fw/Time/TimePortAc.hpp>
#include <Fw/Tlm/TlmPortAc.hpp>
#include <Ref/RecvBuffApp/PacketStatSerializableAc.hpp>

namespace Ref {

  //! \class RecvBuffComponentBase
  //! \brief Auto-generated base for RecvBuff component
  //!
  class RecvBuffComponentBase :
    public Fw::PassiveComponentBase
  {

    // ----------------------------------------------------------------------
    // Friend classes
    // ----------------------------------------------------------------------

    //! Friend class for white-box testing
    //!
    friend class RecvBuffComponentBaseFriend;

  public:

    // ----------------------------------------------------------------------
    // Getters for typed input ports
    // ----------------------------------------------------------------------

    //! Get input port at index
    //!
    //! \return CmdDisp[portNum]
    //!
    Fw::InputCmdPort* get_CmdDisp_InputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );

    //! Get input port at index
    //!
    //! \return Data[portNum]
    //!
    Drv::InputDataBufferPort* get_Data_InputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );

  public:

    // ----------------------------------------------------------------------
    // Connect typed input ports to typed output ports
    // ----------------------------------------------------------------------

    //! Connect port to CmdReg[portNum]
    //!
    void set_CmdReg_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputCmdRegPort *port /*!< The port*/
    );

    //! Connect port to CmdStatus[portNum]
    //!
    void set_CmdStatus_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputCmdResponsePort *port /*!< The port*/
    );

    //! Connect port to Log[portNum]
    //!
    void set_Log_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputLogPort *port /*!< The port*/
    );

#if FW_ENABLE_TEXT_LOGGING == 1
    //! Connect port to LogText[portNum]
    //!
    void set_LogText_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputLogTextPort *port /*!< The port*/
    );
#endif

    //! Connect port to ParamGet[portNum]
    //!
    void set_ParamGet_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputPrmGetPort *port /*!< The port*/
    );

    //! Connect port to ParamSet[portNum]
    //!
    void set_ParamSet_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputPrmSetPort *port /*!< The port*/
    );

    //! Connect port to Time[portNum]
    //!
    void set_Time_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputTimePort *port /*!< The port*/
    );

    //! Connect port to Tlm[portNum]
    //!
    void set_Tlm_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputTlmPort *port /*!< The port*/
    );

#if FW_PORT_SERIALIZATION

  public:

    // ----------------------------------------------------------------------
    // Connect serialization input ports to typed output ports
    // ----------------------------------------------------------------------

    //! Connect port to CmdReg[portNum]
    //!
    void set_CmdReg_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputSerializePort *port /*!< The port*/
    );

    //! Connect port to CmdStatus[portNum]
    //!
    void set_CmdStatus_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputSerializePort *port /*!< The port*/
    );

    //! Connect port to Log[portNum]
    //!
    void set_Log_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputSerializePort *port /*!< The port*/
    );

#if FW_ENABLE_TEXT_LOGGING == 1
    //! Connect port to LogText[portNum]
    //!
    void set_LogText_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputSerializePort *port /*!< The port*/
    );
#endif

    //! Connect port to ParamGet[portNum]
    //!
    void set_ParamGet_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputSerializePort *port /*!< The port*/
    );

    //! Connect port to ParamSet[portNum]
    //!
    void set_ParamSet_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputSerializePort *port /*!< The port*/
    );

    //! Connect port to Time[portNum]
    //!
    void set_Time_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputSerializePort *port /*!< The port*/
    );

    //! Connect port to Tlm[portNum]
    //!
    void set_Tlm_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputSerializePort *port /*!< The port*/
    );

#endif

  public:

    // ----------------------------------------------------------------------
    // Command registration
    // ----------------------------------------------------------------------

    //! \brief Register commands with the Command Dispatcher
    //!
    //! Connect the dispatcher first
    //!
    void regCommands();

  public:

    // ----------------------------------------------------------------------
    // Parameter loading
    // ----------------------------------------------------------------------

    //! \brief Load the parameters from a parameter source
    //!
    //! Connect the parameter first
    //!
    void loadParameters();

  PROTECTED:

    // ----------------------------------------------------------------------
    // Component construction, initialization, and destruction
    // ----------------------------------------------------------------------

    //! Construct a RecvBuffComponentBase object
    //!
    RecvBuffComponentBase(
        const char* compName = "" /*!< Component name*/
    );

    //! Initialize a RecvBuffComponentBase object
    //!
    void init(
        NATIVE_INT_TYPE instance = 0 /*!< The instance number*/
    );

    //! Destroy a RecvBuffComponentBase object
    //!
    virtual ~RecvBuffComponentBase();

  PROTECTED:

    // ----------------------------------------------------------------------
    // Handlers to implement for typed input ports
    // ----------------------------------------------------------------------

    //! Handler for input port Data
    //
    virtual void Data_handler(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Drv::DataBuffer &buff /*!< 
      A data buffer
      */
    ) = 0;

  PROTECTED:

    // ----------------------------------------------------------------------
    // Port handler base-class functions for typed input ports.
    // ----------------------------------------------------------------------
    // Call these functions directly to bypass the corresponding ports.
    // ----------------------------------------------------------------------

    //! Handler base-class function for input port Data
    //!
    void Data_handlerBase(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Drv::DataBuffer &buff /*!< 
      A data buffer
      */
    );

  PROTECTED:

    // ----------------------------------------------------------------------
    // Getters for numbers of input ports
    // ----------------------------------------------------------------------

    //! Get the number of CmdDisp input ports
    //!
    //! \return The number of CmdDisp input ports
    //!
    NATIVE_INT_TYPE getNum_CmdDisp_InputPorts();

    //! Get the number of Data input ports
    //!
    //! \return The number of Data input ports
    //!
    NATIVE_INT_TYPE getNum_Data_InputPorts();


    // ----------------------------------------------------------------------
    // Enumerations for number of ports
    // ----------------------------------------------------------------------

    enum {
       NUM_CMDDISP_INPUT_PORTS = 1,
       NUM_DATA_INPUT_PORTS = 1,
    };

  PROTECTED:

    // ----------------------------------------------------------------------
    // Getters for numbers of output ports
    // ----------------------------------------------------------------------

    //! Get the number of CmdReg output ports
    //!
    //! \return The number of CmdReg output ports
    //!
    NATIVE_INT_TYPE getNum_CmdReg_OutputPorts();

    //! Get the number of CmdStatus output ports
    //!
    //! \return The number of CmdStatus output ports
    //!
    NATIVE_INT_TYPE getNum_CmdStatus_OutputPorts();

    //! Get the number of Log output ports
    //!
    //! \return The number of Log output ports
    //!
    NATIVE_INT_TYPE getNum_Log_OutputPorts();

#if FW_ENABLE_TEXT_LOGGING == 1
    //! Get the number of LogText output ports
    //!
    //! \return The number of LogText output ports
    //!
    NATIVE_INT_TYPE getNum_LogText_OutputPorts();
#endif

    //! Get the number of ParamGet output ports
    //!
    //! \return The number of ParamGet output ports
    //!
    NATIVE_INT_TYPE getNum_ParamGet_OutputPorts();

    //! Get the number of ParamSet output ports
    //!
    //! \return The number of ParamSet output ports
    //!
    NATIVE_INT_TYPE getNum_ParamSet_OutputPorts();

    //! Get the number of Time output ports
    //!
    //! \return The number of Time output ports
    //!
    NATIVE_INT_TYPE getNum_Time_OutputPorts();

    //! Get the number of Tlm output ports
    //!
    //! \return The number of Tlm output ports
    //!
    NATIVE_INT_TYPE getNum_Tlm_OutputPorts();


    enum {
       NUM_CMDREG_OUTPUT_PORTS = 1,
       NUM_CMDSTATUS_OUTPUT_PORTS = 1,
       NUM_LOG_OUTPUT_PORTS = 1,
       NUM_LOGTEXT_OUTPUT_PORTS = 1,
       NUM_PARAMGET_OUTPUT_PORTS = 1,
       NUM_PARAMSET_OUTPUT_PORTS = 1,
       NUM_TIME_OUTPUT_PORTS = 1,
       NUM_TLM_OUTPUT_PORTS = 1,
    };

  PROTECTED:

    // ----------------------------------------------------------------------
    // Connection status queries for output ports
    // ----------------------------------------------------------------------

    //! Check whether port CmdReg is connected
    //!
    //! \return Whether port CmdReg is connected
    //!
    bool isConnected_CmdReg_OutputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );

    //! Check whether port CmdStatus is connected
    //!
    //! \return Whether port CmdStatus is connected
    //!
    bool isConnected_CmdStatus_OutputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );

    //! Check whether port Log is connected
    //!
    //! \return Whether port Log is connected
    //!
    bool isConnected_Log_OutputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );

#if FW_ENABLE_TEXT_LOGGING == 1
    //! Check whether port LogText is connected
    //!
    //! \return Whether port LogText is connected
    //!
    bool isConnected_LogText_OutputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );
#endif

    //! Check whether port ParamGet is connected
    //!
    //! \return Whether port ParamGet is connected
    //!
    bool isConnected_ParamGet_OutputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );

    //! Check whether port ParamSet is connected
    //!
    //! \return Whether port ParamSet is connected
    //!
    bool isConnected_ParamSet_OutputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );

    //! Check whether port Time is connected
    //!
    //! \return Whether port Time is connected
    //!
    bool isConnected_Time_OutputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );

    //! Check whether port Tlm is connected
    //!
    //! \return Whether port Tlm is connected
    //!
    bool isConnected_Tlm_OutputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );

  PROTECTED:

    // ----------------------------------------------------------------------
    // Command opcodes
    // ----------------------------------------------------------------------

    enum {
      OPCODE_PARAMETER1_SET = 0x0, //!< opcode to set parameter parameter1
      OPCODE_PARAMETER1_SAVE = 0x1, //!< opcode to save parameter parameter1
      OPCODE_PARAMETER2_SET = 0x2, //!< opcode to set parameter parameter2
      OPCODE_PARAMETER2_SAVE = 0x3, //!< opcode to save parameter parameter2
    };

  PROTECTED:

    // ----------------------------------------------------------------------
    // Command response
    // ----------------------------------------------------------------------

    //! Emit command response
    //!
    void cmdResponse_out(
        FwOpcodeType opCode, /*!< The opcode*/
        U32 cmdSeq, /*!< The command sequence number*/
        Fw::CmdResponse response /*!< The command response*/
    );

  PROTECTED:

    // ----------------------------------------------------------------------
    // Event IDs
    // ----------------------------------------------------------------------

    enum {
      EVENTID_FIRSTPACKETRECEIVED = 0x0, /* First packet received */
      EVENTID_PACKETCHECKSUMERROR = 0x1, /* Packet checksum error */
      EVENTID_BUFFRECVPARAMETERUPDATED = 0x2, /* Report parameter update */
    };

  PROTECTED:

    // ----------------------------------------------------------------------
    // Event logging functions
    // ----------------------------------------------------------------------

    //! Log event FirstPacketReceived
    //!
    /* First packet received */
    void log_ACTIVITY_LO_FirstPacketReceived(
        U32 id /*!< The ID argument*/
    );


    //! Log event PacketChecksumError
    //!
    /* Packet checksum error */
    void log_WARNING_HI_PacketChecksumError(
        U32 id /*!< The ID argument*/
    );


    //! Log event BuffRecvParameterUpdated
    //!
    /* Report parameter update */
    void log_ACTIVITY_LO_BuffRecvParameterUpdated(
        U32 id /*!< The ID argument*/
    );


  PROTECTED:

    // ----------------------------------------------------------------------
    // Channel IDs
    // ----------------------------------------------------------------------

    enum {
      CHANNELID_PKTSTATE = 0x0, //!< Channel ID for PktState
      CHANNELID_SENSOR1 = 0x1, //!< Channel ID for Sensor1
      CHANNELID_SENSOR2 = 0x2, //!< Channel ID for Sensor2
      CHANNELID_PARAMETER1 = 0x3, //!< Channel ID for Parameter1
      CHANNELID_PARAMETER2 = 0x4, //!< Channel ID for Parameter2
    };

  PROTECTED:

    // ----------------------------------------------------------------------
    // Telemetry write functions
    // ----------------------------------------------------------------------

    //! Write telemetry channel PktState
    //!
    /* Packet Statistics */
    void tlmWrite_PktState(
        const Ref::PacketStat& arg /*!< The telemetry value*/,
        Fw::Time _tlmTime=Fw::Time() /*!< Timestamp. Default: unspecified, request from getTime port*/
    );

    //! Write telemetry channel Sensor1
    //!
    /* Value of Sensor1 */
    void tlmWrite_Sensor1(
        F32 arg /*!< The telemetry value*/,
        Fw::Time _tlmTime=Fw::Time() /*!< Timestamp. Default: unspecified, request from getTime port*/
    );

    //! Write telemetry channel Sensor2
    //!
    /* Value of Sensor3 */
    void tlmWrite_Sensor2(
        F32 arg /*!< The telemetry value*/,
        Fw::Time _tlmTime=Fw::Time() /*!< Timestamp. Default: unspecified, request from getTime port*/
    );

    //! Write telemetry channel Parameter1
    //!
    /* Readback of Parameter1 */
    void tlmWrite_Parameter1(
        U32 arg /*!< The telemetry value*/,
        Fw::Time _tlmTime=Fw::Time() /*!< Timestamp. Default: unspecified, request from getTime port*/
    );

    //! Write telemetry channel Parameter2
    //!
    /* Readback of Parameter2 */
    void tlmWrite_Parameter2(
        I16 arg /*!< The telemetry value*/,
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

  PROTECTED:

    // ----------------------------------------------------------------------
    // Parameter IDs
    // ----------------------------------------------------------------------

    enum {
      PARAMID_PARAMETER1 = 0x0,
      PARAMID_PARAMETER2 = 0x1,
    };

  PROTECTED:

    // ----------------------------------------------------------------------
    // Parameter update hook
    // ----------------------------------------------------------------------

    //! \brief Called whenever a parameter is updated
    //!
    //! This function does nothing by default. You may override it.
    //!
    virtual void parameterUpdated(
        FwPrmIdType id /*!< The parameter ID*/
    );

    // ----------------------------------------------------------------------
    // Parameter load hook
    // ----------------------------------------------------------------------

    //! \brief Called whenever parameters are loaded
    //!
    //! This function does nothing by default. You may override it.
    //!
    virtual void parametersLoaded();

  PROTECTED:

    // ----------------------------------------------------------------------
    // Parameter get functions
    // ----------------------------------------------------------------------

    //! Get parameter parameter1
    //!
    /* A test parameter */
    //! \return The parameter value
    //!
    U32 paramGet_parameter1(
        Fw::ParamValid& valid /*!< Whether the parameter is valid*/
    );

    //! Get parameter parameter2
    //!
    /* A test parameter */
    //! \return The parameter value
    //!
    I16 paramGet_parameter2(
        Fw::ParamValid& valid /*!< Whether the parameter is valid*/
    );



  PRIVATE:

    // ----------------------------------------------------------------------
    // Typed input ports
    // ----------------------------------------------------------------------

    //! Input port CmdDisp
    //!
    Fw::InputCmdPort m_CmdDisp_InputPort[NUM_CMDDISP_INPUT_PORTS];

    //! Input port Data
    //!
    Drv::InputDataBufferPort m_Data_InputPort[NUM_DATA_INPUT_PORTS];

  PRIVATE:

    // ----------------------------------------------------------------------
    // Typed output ports
    // ----------------------------------------------------------------------

    //! Output port CmdReg
    //!
    Fw::OutputCmdRegPort m_CmdReg_OutputPort[NUM_CMDREG_OUTPUT_PORTS];

    //! Output port CmdStatus
    //!
    Fw::OutputCmdResponsePort m_CmdStatus_OutputPort[NUM_CMDSTATUS_OUTPUT_PORTS];

    //! Output port Log
    //!
    Fw::OutputLogPort m_Log_OutputPort[NUM_LOG_OUTPUT_PORTS];

#if FW_ENABLE_TEXT_LOGGING == 1
    //! Output port LogText
    //!
    Fw::OutputLogTextPort m_LogText_OutputPort[NUM_LOGTEXT_OUTPUT_PORTS];
#endif

    //! Output port ParamGet
    //!
    Fw::OutputPrmGetPort m_ParamGet_OutputPort[NUM_PARAMGET_OUTPUT_PORTS];

    //! Output port ParamSet
    //!
    Fw::OutputPrmSetPort m_ParamSet_OutputPort[NUM_PARAMSET_OUTPUT_PORTS];

    //! Output port Time
    //!
    Fw::OutputTimePort m_Time_OutputPort[NUM_TIME_OUTPUT_PORTS];

    //! Output port Tlm
    //!
    Fw::OutputTlmPort m_Tlm_OutputPort[NUM_TLM_OUTPUT_PORTS];

  PRIVATE:

    // ----------------------------------------------------------------------
    // Calls for messages received on typed input ports
    // ----------------------------------------------------------------------

    //! Callback for port CmdDisp
    //!
    static void m_p_CmdDisp_in(
        Fw::PassiveComponentBase* callComp, /*!< The component instance*/
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        FwOpcodeType opCode, /*!< 
      Command Op Code
      */
        U32 cmdSeq, /*!< 
      Command Sequence
      */
        Fw::CmdArgBuffer &args /*!< 
      Buffer containing arguments
      */
    );

    //! Callback for port Data
    //!
    static void m_p_Data_in(
        Fw::PassiveComponentBase* callComp, /*!< The component instance*/
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Drv::DataBuffer &buff /*!< 
      A data buffer
      */
    );

  PRIVATE:

    // ----------------------------------------------------------------------
    // Mutexes
    // ----------------------------------------------------------------------

    //! Mutex for locking parameters during sets and saves
    //!
    Os::Mutex m_paramLock;

  PRIVATE:

    // ----------------------------------------------------------------------
    // Parameter validity flags
    // ----------------------------------------------------------------------

    //! True if parameter parameter1 was successfully received
    //!
    Fw::ParamValid m_param_parameter1_valid;

    //! True if parameter parameter2 was successfully received
    //!
    Fw::ParamValid m_param_parameter2_valid;

  PRIVATE:

    // ----------------------------------------------------------------------
    // Parameter variables
    // ----------------------------------------------------------------------

    //! Parameter parameter1
    //!
    /*! A test parameter*/
    U32 m_parameter1;

    //! Parameter parameter2
    //!
    /*! A test parameter*/
    I16 m_parameter2;

  PRIVATE:

    // ----------------------------------------------------------------------
    // Private parameter get function
    // ----------------------------------------------------------------------

    //! Get a parameter by ID
    //!
    //! \return Whether the parameter is valid
    //!
    Fw::ParamValid getParam(
        FwPrmIdType id, /*!< The ID*/
        Fw::ParamBuffer& buff /*!< The parameter value*/
    );

  PRIVATE:

    // ----------------------------------------------------------------------
    // Parameter set functions
    // ----------------------------------------------------------------------

    //! Set parameter parameter1
    //!
    //! \return The command response
    //!
    Fw::CmdResponse paramSet_parameter1(
        Fw::SerializeBufferBase &val /*!< The serialization buffer*/
    );

    //! Set parameter parameter2
    //!
    //! \return The command response
    //!
    Fw::CmdResponse paramSet_parameter2(
        Fw::SerializeBufferBase &val /*!< The serialization buffer*/
    );

  PRIVATE:

    // ----------------------------------------------------------------------
    // Parameter save functions
    // ----------------------------------------------------------------------

    //! Save parameter parameter1
    //!
    //! \return The command response
    //!
    Fw::CmdResponse paramSave_parameter1();

    //! Save parameter parameter2
    //!
    //! \return The command response
    //!
    Fw::CmdResponse paramSave_parameter2();

  PRIVATE:

    // ----------------------------------------------------------------------
    // First update flags for telemetry channels
    // ----------------------------------------------------------------------

    //! Initialized to true; cleared when channel Parameter1 is first updated
    //!
    bool m_first_update_Parameter1;

    //! Initialized to true; cleared when channel Parameter2 is first updated
    //!
    bool m_first_update_Parameter2;

  PRIVATE:

    // ----------------------------------------------------------------------
    // Last value storage for telemetry channels
    // ----------------------------------------------------------------------

    //! Records the last emitted value for channel Parameter1
    //!
    U32 m_last_Parameter1;

    //! Records the last emitted value for channel Parameter2
    //!
    I16 m_last_Parameter2;


  PRIVATE:
    // ----------------------------------------------------------------------
    // Counter values for event throttling
    // ----------------------------------------------------------------------

  };

} // end namespace Ref
#endif
