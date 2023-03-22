/*
 * ProcessInDataPort.hpp
 *
 *  Created on: Monday, 20 March 2023
 *  Author:     kokaze
 *
 */
#ifndef REF_PROCESSINDATA_PORT_HPP_
#define REF_PROCESSINDATA_PORT_HPP_

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
#include <Ref/GetEnvData/SDSSDataSerializableAc.hpp>
#include <Ref/GetEnvData/SGyroDataSerializableAc.hpp>
#include <Ref/GetEnvData/SThrDistributeSerializableAc.hpp>
#include <Ref/GetCtrlData/ModeEnumAc.hpp>


namespace Ref {

    /// Input ProcessInData port description
    /// 

    class InputProcessInDataPort : public Fw::InputPortBase  {
    public:
        enum {
            SERIALIZED_SIZE = Ref::SGyroData::SERIALIZED_SIZE + Ref::SDSSData::SERIALIZED_SIZE + Ref::SThrDistribute::SERIALIZED_SIZE + Ref::SAttitude::SERIALIZED_SIZE + Ref::Mode::SERIALIZED_SIZE //!< serialized size of port arguments
        };
        typedef void (*CompFuncPtr)(Fw::PassiveComponentBase* callComp, NATIVE_INT_TYPE portNum, Ref::SGyroData &mGyroData, const Ref::SDSSData &mDSSData, const Ref::SThrDistribute &mThrDistribute, Ref::SAttitude &mAttitude, const Ref::Mode &mode); //!< port callback definition

        InputProcessInDataPort(); //!< constructor
        void init(); //!< initialization function
        void addCallComp(Fw::PassiveComponentBase* callComp, CompFuncPtr funcPtr); //!< call to register a component
        void invoke(Ref::SGyroData &mGyroData, const Ref::SDSSData &mDSSData, const Ref::SThrDistribute &mThrDistribute, Ref::SAttitude &mAttitude, const Ref::Mode &mode); //!< invoke port interface
    protected:
    private:
        CompFuncPtr m_func; //!< pointer to port callback function
#if FW_PORT_SERIALIZATION == 1        
        Fw::SerializeStatus invokeSerial(Fw::SerializeBufferBase &buffer); //!< invoke the port with serialized arguments
#endif
};
    /// Output ProcessInData port description
    /// 

    class OutputProcessInDataPort : public Fw::OutputPortBase {
      public:
        OutputProcessInDataPort();
        void init();
        void addCallPort(InputProcessInDataPort* callPort);
        void invoke(Ref::SGyroData &mGyroData, const Ref::SDSSData &mDSSData, const Ref::SThrDistribute &mThrDistribute, Ref::SAttitude &mAttitude, const Ref::Mode &mode);
      protected:
      private:
        InputProcessInDataPort* m_port;
    };
} // end namespace Ref
#endif /* REF_PROCESSINDATA_PORT_HPP_ */

