/*
 * ProcessOutDataPort.hpp
 *
 *  Created on: Monday, 20 March 2023
 *  Author:     kokaze
 *
 */
#ifndef REF_PROCESSOUTDATA_PORT_HPP_
#define REF_PROCESSOUTDATA_PORT_HPP_

#include <cstring>
#include <cstdio>
#include <FpConfig.hpp>
#include <Fw/Port/InputPortBase.hpp>
#include <Fw/Port/OutputPortBase.hpp>
#include <Fw/Comp/PassiveComponentBase.hpp>
#include <Fw/Types/BasicTypes.hpp>
#include <Fw/Types/Serializable.hpp>
#include <Fw/Types/StringType.hpp>
#include <Ref/DataType/SAttitudeSerializableAc.hpp>
#include <Ref/DataType/SControllerSerializableAc.hpp>
#include <Ref/DataType/SFratemodulatorSerializableAc.hpp>
#include <Ref/DoActions/ParameterSerializableAc.hpp>
#include <Ref/GetEnvData/SDSSDataSerializableAc.hpp>
#include <Ref/GetCtrlData/ModeEnumAc.hpp>


namespace Ref {

    /// Input ProcessOutData port description
    /// 

    class InputProcessOutDataPort : public Fw::InputPortBase  {
    public:
        enum {
            SERIALIZED_SIZE = Ref::SAttitude::SERIALIZED_SIZE + Ref::SDSSData::SERIALIZED_SIZE + Ref::Mode::SERIALIZED_SIZE + Ref::SController::SERIALIZED_SIZE + Ref::SFratemodulator::SERIALIZED_SIZE + Ref::Parameter::SERIALIZED_SIZE + sizeof(U32) + sizeof(U32) + sizeof(F32) + sizeof(F32) //!< serialized size of port arguments
        };
        typedef void (*CompFuncPtr)(Fw::PassiveComponentBase* callComp, NATIVE_INT_TYPE portNum, const Ref::SAttitude &mAttitude, const Ref::SDSSData &mDSSData, Ref::Mode &mode, Ref::SController &mController, Ref::SFratemodulator &mModulator, Ref::Parameter &parameter, U32 &countPublic, U32 &countMode, F32 &BIASWXRO, F32 &BIASWYPI); //!< port callback definition

        InputProcessOutDataPort(); //!< constructor
        void init(); //!< initialization function
        void addCallComp(Fw::PassiveComponentBase* callComp, CompFuncPtr funcPtr); //!< call to register a component
        void invoke(const Ref::SAttitude &mAttitude, const Ref::SDSSData &mDSSData, Ref::Mode &mode, Ref::SController &mController, Ref::SFratemodulator &mModulator, Ref::Parameter &parameter, U32 &countPublic, U32 &countMode, F32 &BIASWXRO, F32 &BIASWYPI); //!< invoke port interface
    protected:
    private:
        CompFuncPtr m_func; //!< pointer to port callback function
#if FW_PORT_SERIALIZATION == 1        
        Fw::SerializeStatus invokeSerial(Fw::SerializeBufferBase &buffer); //!< invoke the port with serialized arguments
#endif
};
    /// Output ProcessOutData port description
    /// 

    class OutputProcessOutDataPort : public Fw::OutputPortBase {
      public:
        OutputProcessOutDataPort();
        void init();
        void addCallPort(InputProcessOutDataPort* callPort);
        void invoke(const Ref::SAttitude &mAttitude, const Ref::SDSSData &mDSSData, Ref::Mode &mode, Ref::SController &mController, Ref::SFratemodulator &mModulator, Ref::Parameter &parameter, U32 &countPublic, U32 &countMode, F32 &BIASWXRO, F32 &BIASWYPI);
      protected:
      private:
        InputProcessOutDataPort* m_port;
    };
} // end namespace Ref
#endif /* REF_PROCESSOUTDATA_PORT_HPP_ */

