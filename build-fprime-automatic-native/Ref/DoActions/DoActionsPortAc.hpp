/*
 * DoActionsPort.hpp
 *
 *  Created on: Monday, 20 March 2023
 *  Author:     kokaze
 *
 */
#ifndef REF_DOACTIONS_PORT_HPP_
#define REF_DOACTIONS_PORT_HPP_

#include <cstring>
#include <cstdio>
#include <FpConfig.hpp>
#include <Fw/Port/InputPortBase.hpp>
#include <Fw/Port/OutputPortBase.hpp>
#include <Fw/Comp/PassiveComponentBase.hpp>
#include <Fw/Types/BasicTypes.hpp>
#include <Fw/Types/Serializable.hpp>
#include <Fw/Types/StringType.hpp>
#include <Ref/DoActions/ActionsSerializableAc.hpp>
#include <Ref/DoActions/ParameterSerializableAc.hpp>


namespace Ref {

    /// Input DoActions port description
    /// 

    class InputDoActionsPort : public Fw::InputPortBase  {
    public:
        enum {
            SERIALIZED_SIZE = Ref::Actions::SERIALIZED_SIZE + Ref::Parameter::SERIALIZED_SIZE //!< serialized size of port arguments
        };
        typedef void (*CompFuncPtr)(Fw::PassiveComponentBase* callComp, NATIVE_INT_TYPE portNum, const Ref::Actions &actions, const Ref::Parameter &parameter); //!< port callback definition

        InputDoActionsPort(); //!< constructor
        void init(); //!< initialization function
        void addCallComp(Fw::PassiveComponentBase* callComp, CompFuncPtr funcPtr); //!< call to register a component
        void invoke(const Ref::Actions &actions, const Ref::Parameter &parameter); //!< invoke port interface
    protected:
    private:
        CompFuncPtr m_func; //!< pointer to port callback function
#if FW_PORT_SERIALIZATION == 1        
        Fw::SerializeStatus invokeSerial(Fw::SerializeBufferBase &buffer); //!< invoke the port with serialized arguments
#endif
};
    /// Output DoActions port description
    /// 

    class OutputDoActionsPort : public Fw::OutputPortBase {
      public:
        OutputDoActionsPort();
        void init();
        void addCallPort(InputDoActionsPort* callPort);
        void invoke(const Ref::Actions &actions, const Ref::Parameter &parameter);
      protected:
      private:
        InputDoActionsPort* m_port;
    };
} // end namespace Ref
#endif /* REF_DOACTIONS_PORT_HPP_ */

