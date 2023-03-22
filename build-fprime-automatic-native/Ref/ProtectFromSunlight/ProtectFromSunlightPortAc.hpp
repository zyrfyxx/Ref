/*
 * ProtectFromSunlightPort.hpp
 *
 *  Created on: Monday, 20 March 2023
 *  Author:     kokaze
 *
 */
#ifndef REF_PROTECTFROMSUNLIGHT_PORT_HPP_
#define REF_PROTECTFROMSUNLIGHT_PORT_HPP_

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

    /// Input ProtectFromSunlight port description
    /// 

    class InputProtectFromSunlightPort : public Fw::InputPortBase  {
    public:
        enum {
            SERIALIZED_SIZE = 0 //!< serialized size of port arguments
        };
        typedef void (*CompFuncPtr)(Fw::PassiveComponentBase* callComp, NATIVE_INT_TYPE portNum); //!< port callback definition

        InputProtectFromSunlightPort(); //!< constructor
        void init(); //!< initialization function
        void addCallComp(Fw::PassiveComponentBase* callComp, CompFuncPtr funcPtr); //!< call to register a component
        void invoke(); //!< invoke port interface
    protected:
    private:
        CompFuncPtr m_func; //!< pointer to port callback function
#if FW_PORT_SERIALIZATION == 1        
        Fw::SerializeStatus invokeSerial(Fw::SerializeBufferBase &buffer); //!< invoke the port with serialized arguments
#endif
};
    /// Output ProtectFromSunlight port description
    /// 

    class OutputProtectFromSunlightPort : public Fw::OutputPortBase {
      public:
        OutputProtectFromSunlightPort();
        void init();
        void addCallPort(InputProtectFromSunlightPort* callPort);
        void invoke();
      protected:
      private:
        InputProtectFromSunlightPort* m_port;
    };
} // end namespace Ref
#endif /* REF_PROTECTFROMSUNLIGHT_PORT_HPP_ */

