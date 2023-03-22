#include <FpConfig.hpp>
#include <Fw/Types/Assert.hpp>
#include <Fw/Types/Serializable.hpp>
#include <Fw/Types/StringUtils.hpp>

#include <Ref/ProcessOutData/ProcessOutDataPortAc.hpp>
namespace Ref {


    namespace {

        class ProcessOutDataPortBuffer : public Fw::SerializeBufferBase {

            public:
                NATIVE_UINT_TYPE getBuffCapacity() const {
                    return InputProcessOutDataPort::SERIALIZED_SIZE;
                }

                U8* getBuffAddr() {
                    return m_buff;
                }

                const U8* getBuffAddr() const {
                    return m_buff;
                }

        private:

            U8 m_buff[InputProcessOutDataPort::SERIALIZED_SIZE];

        };

    }
    InputProcessOutDataPort::InputProcessOutDataPort() :
        Fw::InputPortBase(),
        m_func(nullptr) {
    }

    void InputProcessOutDataPort::init() {
        Fw::InputPortBase::init();
    }

    void InputProcessOutDataPort::addCallComp(Fw::PassiveComponentBase* callComp, CompFuncPtr funcPtr) {
        FW_ASSERT(callComp);
        FW_ASSERT(funcPtr);

        this->m_comp = callComp;
        this->m_func = funcPtr;
        this->m_connObj = callComp;
    }

    // call virtual logging function for component
    void InputProcessOutDataPort::invoke(const Ref::SAttitude &mAttitude, const Ref::SDSSData &mDSSData, Ref::Mode &mode, Ref::SController &mController, Ref::SFratemodulator &mModulator, Ref::Parameter &parameter, U32 &countPublic, U32 &countMode, F32 &BIASWXRO, F32 &BIASWYPI) {

#if FW_PORT_TRACING == 1
        this->trace();
#endif
        FW_ASSERT(this->m_comp);
        FW_ASSERT(this->m_func);
        this->m_func(this->m_comp, this->m_portNum, mAttitude, mDSSData, mode, mController, mModulator, parameter, countPublic, countMode, BIASWXRO, BIASWYPI);
    }

#if FW_PORT_SERIALIZATION == 1    
    Fw::SerializeStatus InputProcessOutDataPort::invokeSerial(Fw::SerializeBufferBase &buffer) {
        Fw::SerializeStatus _status;
#if FW_PORT_TRACING == 1
        this->trace();
#endif
        FW_ASSERT(this->m_comp);
        FW_ASSERT(this->m_func);


        Ref::SAttitude mAttitude;
        _status = buffer.deserialize(mAttitude);
        if (Fw::FW_SERIALIZE_OK != _status) {
            return _status;
        }

        Ref::SDSSData mDSSData;
        _status = buffer.deserialize(mDSSData);
        if (Fw::FW_SERIALIZE_OK != _status) {
            return _status;
        }

        Ref::Mode mode;
        _status = buffer.deserialize(mode);
        if (Fw::FW_SERIALIZE_OK != _status) {
            return _status;
        }

        Ref::SController mController;
        _status = buffer.deserialize(mController);
        if (Fw::FW_SERIALIZE_OK != _status) {
            return _status;
        }

        Ref::SFratemodulator mModulator;
        _status = buffer.deserialize(mModulator);
        if (Fw::FW_SERIALIZE_OK != _status) {
            return _status;
        }

        Ref::Parameter parameter;
        _status = buffer.deserialize(parameter);
        if (Fw::FW_SERIALIZE_OK != _status) {
            return _status;
        }

        U32 countPublic;
        _status = buffer.deserialize(countPublic);
        if (Fw::FW_SERIALIZE_OK != _status) {
            return _status;
        }

        U32 countMode;
        _status = buffer.deserialize(countMode);
        if (Fw::FW_SERIALIZE_OK != _status) {
            return _status;
        }

        F32 BIASWXRO;
        _status = buffer.deserialize(BIASWXRO);
        if (Fw::FW_SERIALIZE_OK != _status) {
            return _status;
        }

        F32 BIASWYPI;
        _status = buffer.deserialize(BIASWYPI);
        if (Fw::FW_SERIALIZE_OK != _status) {
            return _status;
        }

        this->m_func(this->m_comp, this->m_portNum, mAttitude, mDSSData, mode, mController, mModulator, parameter, countPublic, countMode, BIASWXRO, BIASWYPI);
    
        return Fw::FW_SERIALIZE_OK;
    }
#endif

OutputProcessOutDataPort::OutputProcessOutDataPort() :
            Fw::OutputPortBase(),
    m_port(nullptr) {
}

void OutputProcessOutDataPort::init() {
    Fw::OutputPortBase::init();
}

void OutputProcessOutDataPort::addCallPort(InputProcessOutDataPort* callPort) {
    FW_ASSERT(callPort);

    this->m_port = callPort;
    this->m_connObj = callPort;
#if FW_PORT_SERIALIZATION == 1
    this->m_serPort = nullptr;
#endif
}

void OutputProcessOutDataPort::invoke(const Ref::SAttitude &mAttitude, const Ref::SDSSData &mDSSData, Ref::Mode &mode, Ref::SController &mController, Ref::SFratemodulator &mModulator, Ref::Parameter &parameter, U32 &countPublic, U32 &countMode, F32 &BIASWXRO, F32 &BIASWYPI) {
#if FW_PORT_TRACING == 1
    this->trace();
#endif

#if FW_PORT_SERIALIZATION
    FW_ASSERT(this->m_port||this->m_serPort);
#else
    FW_ASSERT(this->m_port);
#endif

    if (this->m_port) {
        this->m_port->invoke(mAttitude, mDSSData, mode, mController, mModulator, parameter, countPublic, countMode, BIASWXRO, BIASWYPI);
#if FW_PORT_SERIALIZATION
    } else if (this->m_serPort) {

        Fw::SerializeStatus _status;

        ProcessOutDataPortBuffer _buffer;
        _status = _buffer.serialize(mAttitude);
        FW_ASSERT(Fw::FW_SERIALIZE_OK == _status,static_cast<AssertArg>(_status));

        _status = _buffer.serialize(mDSSData);
        FW_ASSERT(Fw::FW_SERIALIZE_OK == _status,static_cast<AssertArg>(_status));

        _status = _buffer.serialize(mode);
        FW_ASSERT(Fw::FW_SERIALIZE_OK == _status,static_cast<AssertArg>(_status));

        _status = _buffer.serialize(mController);
        FW_ASSERT(Fw::FW_SERIALIZE_OK == _status,static_cast<AssertArg>(_status));

        _status = _buffer.serialize(mModulator);
        FW_ASSERT(Fw::FW_SERIALIZE_OK == _status,static_cast<AssertArg>(_status));

        _status = _buffer.serialize(parameter);
        FW_ASSERT(Fw::FW_SERIALIZE_OK == _status,static_cast<AssertArg>(_status));

        _status = _buffer.serialize(countPublic);
        FW_ASSERT(Fw::FW_SERIALIZE_OK == _status,static_cast<AssertArg>(_status));

        _status = _buffer.serialize(countMode);
        FW_ASSERT(Fw::FW_SERIALIZE_OK == _status,static_cast<AssertArg>(_status));

        _status = _buffer.serialize(BIASWXRO);
        FW_ASSERT(Fw::FW_SERIALIZE_OK == _status,static_cast<AssertArg>(_status));

        _status = _buffer.serialize(BIASWYPI);
        FW_ASSERT(Fw::FW_SERIALIZE_OK == _status,static_cast<AssertArg>(_status));

        _status = this->m_serPort->invokeSerial(_buffer);
        FW_ASSERT(Fw::FW_SERIALIZE_OK == _status,static_cast<AssertArg>(_status));
    }
#else
    }
#endif

} // end OutputProcessOutDataPort::invoke(...)

} // end namespace Ref
