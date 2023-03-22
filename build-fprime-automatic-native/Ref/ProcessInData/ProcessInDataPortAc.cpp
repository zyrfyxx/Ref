#include <FpConfig.hpp>
#include <Fw/Types/Assert.hpp>
#include <Fw/Types/Serializable.hpp>
#include <Fw/Types/StringUtils.hpp>

#include <Ref/ProcessInData/ProcessInDataPortAc.hpp>
namespace Ref {


    namespace {

        class ProcessInDataPortBuffer : public Fw::SerializeBufferBase {

            public:
                NATIVE_UINT_TYPE getBuffCapacity() const {
                    return InputProcessInDataPort::SERIALIZED_SIZE;
                }

                U8* getBuffAddr() {
                    return m_buff;
                }

                const U8* getBuffAddr() const {
                    return m_buff;
                }

        private:

            U8 m_buff[InputProcessInDataPort::SERIALIZED_SIZE];

        };

    }
    InputProcessInDataPort::InputProcessInDataPort() :
        Fw::InputPortBase(),
        m_func(nullptr) {
    }

    void InputProcessInDataPort::init() {
        Fw::InputPortBase::init();
    }

    void InputProcessInDataPort::addCallComp(Fw::PassiveComponentBase* callComp, CompFuncPtr funcPtr) {
        FW_ASSERT(callComp);
        FW_ASSERT(funcPtr);

        this->m_comp = callComp;
        this->m_func = funcPtr;
        this->m_connObj = callComp;
    }

    // call virtual logging function for component
    void InputProcessInDataPort::invoke(Ref::SGyroData &mGyroData, const Ref::SDSSData &mDSSData, const Ref::SThrDistribute &mThrDistribute, Ref::SAttitude &mAttitude, const Ref::Mode &mode) {

#if FW_PORT_TRACING == 1
        this->trace();
#endif
        FW_ASSERT(this->m_comp);
        FW_ASSERT(this->m_func);
        this->m_func(this->m_comp, this->m_portNum, mGyroData, mDSSData, mThrDistribute, mAttitude, mode);
    }

#if FW_PORT_SERIALIZATION == 1    
    Fw::SerializeStatus InputProcessInDataPort::invokeSerial(Fw::SerializeBufferBase &buffer) {
        Fw::SerializeStatus _status;
#if FW_PORT_TRACING == 1
        this->trace();
#endif
        FW_ASSERT(this->m_comp);
        FW_ASSERT(this->m_func);


        Ref::SGyroData mGyroData;
        _status = buffer.deserialize(mGyroData);
        if (Fw::FW_SERIALIZE_OK != _status) {
            return _status;
        }

        Ref::SDSSData mDSSData;
        _status = buffer.deserialize(mDSSData);
        if (Fw::FW_SERIALIZE_OK != _status) {
            return _status;
        }

        Ref::SThrDistribute mThrDistribute;
        _status = buffer.deserialize(mThrDistribute);
        if (Fw::FW_SERIALIZE_OK != _status) {
            return _status;
        }

        Ref::SAttitude mAttitude;
        _status = buffer.deserialize(mAttitude);
        if (Fw::FW_SERIALIZE_OK != _status) {
            return _status;
        }

        Ref::Mode mode;
        _status = buffer.deserialize(mode);
        if (Fw::FW_SERIALIZE_OK != _status) {
            return _status;
        }

        this->m_func(this->m_comp, this->m_portNum, mGyroData, mDSSData, mThrDistribute, mAttitude, mode);
    
        return Fw::FW_SERIALIZE_OK;
    }
#endif

OutputProcessInDataPort::OutputProcessInDataPort() :
            Fw::OutputPortBase(),
    m_port(nullptr) {
}

void OutputProcessInDataPort::init() {
    Fw::OutputPortBase::init();
}

void OutputProcessInDataPort::addCallPort(InputProcessInDataPort* callPort) {
    FW_ASSERT(callPort);

    this->m_port = callPort;
    this->m_connObj = callPort;
#if FW_PORT_SERIALIZATION == 1
    this->m_serPort = nullptr;
#endif
}

void OutputProcessInDataPort::invoke(Ref::SGyroData &mGyroData, const Ref::SDSSData &mDSSData, const Ref::SThrDistribute &mThrDistribute, Ref::SAttitude &mAttitude, const Ref::Mode &mode) {
#if FW_PORT_TRACING == 1
    this->trace();
#endif

#if FW_PORT_SERIALIZATION
    FW_ASSERT(this->m_port||this->m_serPort);
#else
    FW_ASSERT(this->m_port);
#endif

    if (this->m_port) {
        this->m_port->invoke(mGyroData, mDSSData, mThrDistribute, mAttitude, mode);
#if FW_PORT_SERIALIZATION
    } else if (this->m_serPort) {

        Fw::SerializeStatus _status;

        ProcessInDataPortBuffer _buffer;
        _status = _buffer.serialize(mGyroData);
        FW_ASSERT(Fw::FW_SERIALIZE_OK == _status,static_cast<AssertArg>(_status));

        _status = _buffer.serialize(mDSSData);
        FW_ASSERT(Fw::FW_SERIALIZE_OK == _status,static_cast<AssertArg>(_status));

        _status = _buffer.serialize(mThrDistribute);
        FW_ASSERT(Fw::FW_SERIALIZE_OK == _status,static_cast<AssertArg>(_status));

        _status = _buffer.serialize(mAttitude);
        FW_ASSERT(Fw::FW_SERIALIZE_OK == _status,static_cast<AssertArg>(_status));

        _status = _buffer.serialize(mode);
        FW_ASSERT(Fw::FW_SERIALIZE_OK == _status,static_cast<AssertArg>(_status));

        _status = this->m_serPort->invokeSerial(_buffer);
        FW_ASSERT(Fw::FW_SERIALIZE_OK == _status,static_cast<AssertArg>(_status));
    }
#else
    }
#endif

} // end OutputProcessInDataPort::invoke(...)

} // end namespace Ref
