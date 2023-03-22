/*
 * SetSensorStatePort.hpp
 *
 *  Created on: Monday, 20 March 2023
 *  Author:     kokaze
 *
 */
#ifndef REF_SETSENSORSTATE_PORT_HPP_
#define REF_SETSENSORSTATE_PORT_HPP_

#include <cstring>
#include <cstdio>
#include <FpConfig.hpp>
#include <Fw/Port/InputPortBase.hpp>
#include <Fw/Port/OutputPortBase.hpp>
#include <Fw/Comp/PassiveComponentBase.hpp>
#include <Fw/Types/BasicTypes.hpp>
#include <Fw/Types/Serializable.hpp>
#include <Fw/Types/StringType.hpp>
#include <Ref/DataType/SFratemodulatorSerializableAc.hpp>
#include <Ref/DoActions/ParameterSerializableAc.hpp>
#include <Ref/GetEnvData/SGyroDataSerializableAc.hpp>
#include <Ref/GetCtrlData/ModeEnumAc.hpp>


namespace Ref {

    /// Input SetSensorState port description
    /// 

    class InputSetSensorStatePort : public Fw::InputPortBase  {
    public:
        enum {
            SERIALIZED_SIZE = Ref::SGyroData::SERIALIZED_SIZE + Ref::Mode::SERIALIZED_SIZE + sizeof(U32) + sizeof(U32) + sizeof(F32) + sizeof(F32) + Ref::SFratemodulator::SERIALIZED_SIZE //!< serialized size of port arguments
        };
        typedef Ref::Parameter (*CompFuncPtr)(Fw::PassiveComponentBase* callComp, NATIVE_INT_TYPE portNum, Ref::SGyroData &mGyroData, Ref::Mode &mode, U32 &countPublic, U32 &countMode, F32 &BIASWXRO, F32 &BIASWYPI, Ref::SFratemodulator &mModulator); //!< port callback definition

        InputSetSensorStatePort(); //!< constructor
        void init(); //!< initialization function
        void addCallComp(Fw::PassiveComponentBase* callComp, CompFuncPtr funcPtr); //!< call to register a component
        Ref::Parameter invoke(Ref::SGyroData &mGyroData, Ref::Mode &mode, U32 &countPublic, U32 &countMode, F32 &BIASWXRO, F32 &BIASWYPI, Ref::SFratemodulator &mModulator); //!< invoke port interface
    protected:
    private:
        CompFuncPtr m_func; //!< pointer to port callback function
#if FW_PORT_SERIALIZATION == 1        
        Fw::SerializeStatus invokeSerial(Fw::SerializeBufferBase &buffer); //!< invoke the port with serialized arguments
#endif
};
    /// Output SetSensorState port description
    /// 

    class OutputSetSensorStatePort : public Fw::OutputPortBase {
      public:
        OutputSetSensorStatePort();
        void init();
        void addCallPort(InputSetSensorStatePort* callPort);
        Ref::Parameter invoke(Ref::SGyroData &mGyroData, Ref::Mode &mode, U32 &countPublic, U32 &countMode, F32 &BIASWXRO, F32 &BIASWYPI, Ref::SFratemodulator &mModulator);
      protected:
      private:
        InputSetSensorStatePort* m_port;
    };
} // end namespace Ref
#endif /* REF_SETSENSORSTATE_PORT_HPP_ */

