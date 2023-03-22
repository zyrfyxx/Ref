#include <FpConfig.hpp>
#include <Fw/Types/Assert.hpp>
#include <Fw/Types/Serializable.hpp>
#include <Fw/Types/StringUtils.hpp>

#include <Ref/ProcessData/ProcessDataPortAc.hpp>
namespace Ref {


    namespace {

        class ProcessDataPortBuffer : public Fw::SerializeBufferBase {

            public:
                NATIVE_UINT_TYPE getBuffCapacity() const {
                    return InputProcessDataPort::SERIALIZED_SIZE;
                }

                U8* getBuffAddr() {
                    return m_buff;
                }

                const U8* getBuffAddr() const {
                    return m_buff;
                }

        private:

            U8 m_buff[InputProcessDataPort::SERIALIZED_SIZE];

        };

    }
    InputProcessDataPort::InputProcessDataPort() :
        Fw::InputPortBase(),
        m_func(nullptr) {
    }

    void InputProcessDataPort::init() {
        Fw::InputPortBase::init();
    }

    void InputProcessDataPort::addCallComp(Fw::PassiveComponentBase* callComp, CompFuncPtr funcPtr) {
        FW_ASSERT(callComp);
        FW_ASSERT(funcPtr);

        this->m_comp = callComp;
        this->m_func = funcPtr;
        this->m_connObj = callComp;
    }

    // call virtual logging function for component
    Ref::Parameter InputProcessDataPort::invoke(Ref::SGyroData &mGyroData, Ref::SDSSData &mDSSData, Ref::SThrDistribute &mThrDistribute, Ref::Mode &mode, U32 &countPublic, U32 &countMode, F32 &BIASWXRO, F32 &BIASWYPI, Ref::SFratemodulator &mModulator) {

#if FW_PORT_TRACING == 1
        this->trace();
#endif
        FW_ASSERT(this->m_comp);
        FW_ASSERT(this->m_func);
        return this->m_func(this->m_comp, this->m_portNum, mGyroData, mDSSData, mThrDistribute, mode, countPublic, countMode, BIASWXRO, BIASWYPI, mModulator);
    }

#if FW_PORT_SERIALIZATION == 1    
    Fw::SerializeStatus InputProcessDataPort::invokeSerial(Fw::SerializeBufferBase &buffer) {
        FW_ASSERT(0);

        return Fw::FW_SERIALIZE_OK;
    }
#endif

OutputProcessDataPort::OutputProcessDataPort() :
            Fw::OutputPortBase(),
    m_port(nullptr) {
}

void OutputProcessDataPort::init() {
    Fw::OutputPortBase::init();
}

void OutputProcessDataPort::addCallPort(InputProcessDataPort* callPort) {
    FW_ASSERT(callPort);

    this->m_port = callPort;
    this->m_connObj = callPort;
#if FW_PORT_SERIALIZATION == 1
    this->m_serPort = nullptr;
#endif
}

Ref::Parameter OutputProcessDataPort::invoke(Ref::SGyroData &mGyroData, Ref::SDSSData &mDSSData, Ref::SThrDistribute &mThrDistribute, Ref::Mode &mode, U32 &countPublic, U32 &countMode, F32 &BIASWXRO, F32 &BIASWYPI, Ref::SFratemodulator &mModulator) {
#if FW_PORT_TRACING == 1
    this->trace();
#endif

#if FW_PORT_SERIALIZATION
    FW_ASSERT(this->m_port||this->m_serPort);
#else
    FW_ASSERT(this->m_port);
#endif

    return this->m_port->invoke(mGyroData, mDSSData, mThrDistribute, mode, countPublic, countMode, BIASWXRO, BIASWYPI, mModulator);

} // end OutputProcessDataPort::invoke(...)

} // end namespace Ref
