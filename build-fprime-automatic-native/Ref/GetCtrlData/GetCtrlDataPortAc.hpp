/*
 * GetCtrlDataPort.hpp
 *
 *  Created on: Monday, 20 March 2023
 *  Author:     kokaze
 *
 */
#ifndef REF_GETCTRLDATA_PORT_HPP_
#define REF_GETCTRLDATA_PORT_HPP_

#include <cstring>
#include <cstdio>
#include <FpConfig.hpp>
#include <Fw/Port/InputPortBase.hpp>
#include <Fw/Port/OutputPortBase.hpp>
#include <Fw/Comp/PassiveComponentBase.hpp>
#include <Fw/Types/BasicTypes.hpp>
#include <Fw/Types/Serializable.hpp>
#include <Fw/Types/StringType.hpp>
#include <Ref/GetCtrlData/ModeEnumAc.hpp>


namespace Ref {

    /// Input GetCtrlData port description
    /// 

    class InputGetCtrlDataPort : public Fw::InputPortBase  {
    public:
        enum {
            SERIALIZED_SIZE = Ref::Mode::SERIALIZED_SIZE //!< serialized size of port arguments
        };
        typedef void (*CompFuncPtr)(Fw::PassiveComponentBase* callComp, NATIVE_INT_TYPE portNum, Ref::Mode &mode); //!< port callback definition

        InputGetCtrlDataPort(); //!< constructor
        void init(); //!< initialization function
        void addCallComp(Fw::PassiveComponentBase* callComp, CompFuncPtr funcPtr); //!< call to register a component
        void invoke(Ref::Mode &mode); //!< invoke port interface
    protected:
    private:
        CompFuncPtr m_func; //!< pointer to port callback function
#if FW_PORT_SERIALIZATION == 1        
        Fw::SerializeStatus invokeSerial(Fw::SerializeBufferBase &buffer); //!< invoke the port with serialized arguments
#endif
};
    /// Output GetCtrlData port description
    /// 

    class OutputGetCtrlDataPort : public Fw::OutputPortBase {
      public:
        OutputGetCtrlDataPort();
        void init();
        void addCallPort(InputGetCtrlDataPort* callPort);
        void invoke(Ref::Mode &mode);
      protected:
      private:
        InputGetCtrlDataPort* m_port;
    };
} // end namespace Ref
#endif /* REF_GETCTRLDATA_PORT_HPP_ */

