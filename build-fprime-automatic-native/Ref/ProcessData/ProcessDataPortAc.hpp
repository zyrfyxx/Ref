/*
 * ProcessDataPort.hpp
 *
 *  Created on: Monday, 20 March 2023
 *  Author:     kokaze
 *
 */
#ifndef REF_PROCESSDATA_PORT_HPP_
#define REF_PROCESSDATA_PORT_HPP_

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
#include <Ref/GetEnvData/SDSSDataSerializableAc.hpp>
#include <Ref/GetEnvData/SGyroDataSerializableAc.hpp>
#include <Ref/GetEnvData/SThrDistributeSerializableAc.hpp>
#include <Ref/GetCtrlData/ModeEnumAc.hpp>


namespace Ref {

    /// Input ProcessData port description
    /// 

    class InputProcessDataPort : public Fw::InputPortBase  {
    public:
        enum {
            SERIALIZED_SIZE = Ref::SGyroData::SERIALIZED_SIZE + Ref::SDSSData::SERIALIZED_SIZE + Ref::SThrDistribute::SERIALIZED_SIZE + Ref::Mode::SERIALIZED_SIZE + sizeof(U32) + sizeof(U32) + sizeof(F32) + sizeof(F32) + Ref::SFratemodulator::SERIALIZED_SIZE //!< serialized size of port arguments
        };
        typedef Ref::Parameter (*CompFuncPtr)(Fw::PassiveComponentBase* callComp, NATIVE_INT_TYPE portNum, Ref::SGyroData &mGyroData, Ref::SDSSData &mDSSData, Ref::SThrDistribute &mThrDistribute, Ref::Mode &mode, U32 &countPublic, U32 &countMode, F32 &BIASWXRO, F32 &BIASWYPI, Ref::SFratemodulator &mModulator); //!< port callback definition

        InputProcessDataPort(); //!< constructor
        void init(); //!< initialization function
        void addCallComp(Fw::PassiveComponentBase* callComp, CompFuncPtr funcPtr); //!< call to register a component
        Ref::Parameter invoke(Ref::SGyroData &mGyroData, Ref::SDSSData &mDSSData, Ref::SThrDistribute &mThrDistribute, Ref::Mode &mode, U32 &countPublic, U32 &countMode, F32 &BIASWXRO, F32 &BIASWYPI, Ref::SFratemodulator &mModulator); //!< invoke port interface
    protected:
    private:
        CompFuncPtr m_func; //!< pointer to port callback function
#if FW_PORT_SERIALIZATION == 1        
        Fw::SerializeStatus invokeSerial(Fw::SerializeBufferBase &buffer); //!< invoke the port with serialized arguments
#endif
};
    /// Output ProcessData port description
    /// 

    class OutputProcessDataPort : public Fw::OutputPortBase {
      public:
        OutputProcessDataPort();
        void init();
        void addCallPort(InputProcessDataPort* callPort);
        Ref::Parameter invoke(Ref::SGyroData &mGyroData, Ref::SDSSData &mDSSData, Ref::SThrDistribute &mThrDistribute, Ref::Mode &mode, U32 &countPublic, U32 &countMode, F32 &BIASWXRO, F32 &BIASWYPI, Ref::SFratemodulator &mModulator);
      protected:
      private:
        InputProcessDataPort* m_port;
    };
} // end namespace Ref
#endif /* REF_PROCESSDATA_PORT_HPP_ */

