/*
 * LogPort.hpp
 *
 *  Created on: Monday, 20 March 2023
 *  Author:     kokaze
 *
 */
#ifndef FW_LOG_PORT_HPP_
#define FW_LOG_PORT_HPP_

#include <cstring>
#include <cstdio>
#include <FpConfig.hpp>
#include <Fw/Port/InputPortBase.hpp>
#include <Fw/Port/OutputPortBase.hpp>
#include <Fw/Comp/PassiveComponentBase.hpp>
#include <Fw/Types/BasicTypes.hpp>
#include <Fw/Types/Serializable.hpp>
#include <Fw/Types/StringType.hpp>
#include <Fw/Log/LogSeverityEnumAc.hpp>
#include <Fw/Log/LogBuffer.hpp>
#include <Fw/Time/Time.hpp>


namespace Fw {

    /// Input Log port description
    /// 

    class InputLogPort : public Fw::InputPortBase  {
    public:
        enum {
            SERIALIZED_SIZE = sizeof(FwEventIdType) + Fw::Time::SERIALIZED_SIZE + Fw::LogSeverity::SERIALIZED_SIZE + Fw::LogBuffer::SERIALIZED_SIZE //!< serialized size of port arguments
        };
        typedef void (*CompFuncPtr)(Fw::PassiveComponentBase* callComp, NATIVE_INT_TYPE portNum, FwEventIdType id, Fw::Time &timeTag, const Fw::LogSeverity &severity, Fw::LogBuffer &args); //!< port callback definition

        InputLogPort(); //!< constructor
        void init(); //!< initialization function
        void addCallComp(Fw::PassiveComponentBase* callComp, CompFuncPtr funcPtr); //!< call to register a component
        void invoke(FwEventIdType id, Fw::Time &timeTag, const Fw::LogSeverity &severity, Fw::LogBuffer &args); //!< invoke port interface
    protected:
    private:
        CompFuncPtr m_func; //!< pointer to port callback function
#if FW_PORT_SERIALIZATION == 1        
        Fw::SerializeStatus invokeSerial(Fw::SerializeBufferBase &buffer); //!< invoke the port with serialized arguments
#endif
};
    /// Output Log port description
    /// 

    class OutputLogPort : public Fw::OutputPortBase {
      public:
        OutputLogPort();
        void init();
        void addCallPort(InputLogPort* callPort);
        void invoke(FwEventIdType id, Fw::Time &timeTag, const Fw::LogSeverity &severity, Fw::LogBuffer &args);
      protected:
      private:
        InputLogPort* m_port;
    };
} // end namespace Fw
#endif /* FW_LOG_PORT_HPP_ */

