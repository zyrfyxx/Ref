/*
 * GetEnvDataPort.hpp
 *
 *  Created on: Monday, 20 March 2023
 *  Author:     kokaze
 *
 */
#ifndef REF_GETENVDATA_PORT_HPP_
#define REF_GETENVDATA_PORT_HPP_

#include <cstring>
#include <cstdio>
#include <FpConfig.hpp>
#include <Fw/Port/InputPortBase.hpp>
#include <Fw/Port/OutputPortBase.hpp>
#include <Fw/Comp/PassiveComponentBase.hpp>
#include <Fw/Types/BasicTypes.hpp>
#include <Fw/Types/Serializable.hpp>
#include <Fw/Types/StringType.hpp>
#include <Ref/GetEnvData/SDSSDataSerializableAc.hpp>
#include <Ref/GetEnvData/SGyroDataSerializableAc.hpp>
#include <Ref/GetEnvData/SThrDistributeSerializableAc.hpp>


namespace Ref {

    /// Input GetEnvData port description
    /// 

    class InputGetEnvDataPort : public Fw::InputPortBase  {
    public:
        enum {
            SERIALIZED_SIZE = Ref::SGyroData::SERIALIZED_SIZE + Ref::SThrDistribute::SERIALIZED_SIZE + Ref::SDSSData::SERIALIZED_SIZE + sizeof(U32) //!< serialized size of port arguments
        };
        typedef void (*CompFuncPtr)(Fw::PassiveComponentBase* callComp, NATIVE_INT_TYPE portNum, Ref::SGyroData &mGyroData, Ref::SThrDistribute &mThrDistribute, Ref::SDSSData &mDSSData, U32 &sunlight); //!< port callback definition

        InputGetEnvDataPort(); //!< constructor
        void init(); //!< initialization function
        void addCallComp(Fw::PassiveComponentBase* callComp, CompFuncPtr funcPtr); //!< call to register a component
        void invoke(Ref::SGyroData &mGyroData, Ref::SThrDistribute &mThrDistribute, Ref::SDSSData &mDSSData, U32 &sunlight); //!< invoke port interface
    protected:
    private:
        CompFuncPtr m_func; //!< pointer to port callback function
#if FW_PORT_SERIALIZATION == 1        
        Fw::SerializeStatus invokeSerial(Fw::SerializeBufferBase &buffer); //!< invoke the port with serialized arguments
#endif
};
    /// Output GetEnvData port description
    /// 

    class OutputGetEnvDataPort : public Fw::OutputPortBase {
      public:
        OutputGetEnvDataPort();
        void init();
        void addCallPort(InputGetEnvDataPort* callPort);
        void invoke(Ref::SGyroData &mGyroData, Ref::SThrDistribute &mThrDistribute, Ref::SDSSData &mDSSData, U32 &sunlight);
      protected:
      private:
        InputGetEnvDataPort* m_port;
    };
} // end namespace Ref
#endif /* REF_GETENVDATA_PORT_HPP_ */

