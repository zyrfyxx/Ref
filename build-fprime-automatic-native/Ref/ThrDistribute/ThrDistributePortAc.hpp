/*
 * ThrDistributePort.hpp
 *
 *  Created on: Monday, 20 March 2023
 *  Author:     kokaze
 *
 */
#ifndef REF_THRDISTRIBUTE_PORT_HPP_
#define REF_THRDISTRIBUTE_PORT_HPP_

#include <cstring>
#include <cstdio>
#include <FpConfig.hpp>
#include <Fw/Port/InputPortBase.hpp>
#include <Fw/Port/OutputPortBase.hpp>
#include <Fw/Comp/PassiveComponentBase.hpp>
#include <Fw/Types/BasicTypes.hpp>
#include <Fw/Types/Serializable.hpp>
#include <Fw/Types/StringType.hpp>


namespace Ref {

    /// Input ThrDistribute port description
    /// 

    class InputThrDistributePort : public Fw::InputPortBase  {
    public:
        enum {
            SERIALIZED_SIZE = sizeof(U8) //!< serialized size of port arguments
        };
        typedef void (*CompFuncPtr)(Fw::PassiveComponentBase* callComp, NATIVE_INT_TYPE portNum, U8 wPulse); //!< port callback definition

        InputThrDistributePort(); //!< constructor
        void init(); //!< initialization function
        void addCallComp(Fw::PassiveComponentBase* callComp, CompFuncPtr funcPtr); //!< call to register a component
        void invoke(U8 wPulse); //!< invoke port interface
    protected:
    private:
        CompFuncPtr m_func; //!< pointer to port callback function
#if FW_PORT_SERIALIZATION == 1        
        Fw::SerializeStatus invokeSerial(Fw::SerializeBufferBase &buffer); //!< invoke the port with serialized arguments
#endif
};
    /// Output ThrDistribute port description
    /// 

    class OutputThrDistributePort : public Fw::OutputPortBase {
      public:
        OutputThrDistributePort();
        void init();
        void addCallPort(InputThrDistributePort* callPort);
        void invoke(U8 wPulse);
      protected:
      private:
        InputThrDistributePort* m_port;
    };
} // end namespace Ref
#endif /* REF_THRDISTRIBUTE_PORT_HPP_ */

