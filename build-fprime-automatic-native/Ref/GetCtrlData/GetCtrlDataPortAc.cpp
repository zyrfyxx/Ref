#include <FpConfig.hpp>
#include <Fw/Types/Assert.hpp>
#include <Fw/Types/Serializable.hpp>
#include <Fw/Types/StringUtils.hpp>

#include <Ref/GetCtrlData/GetCtrlDataPortAc.hpp>
namespace Ref {


    namespace {

        class GetCtrlDataPortBuffer : public Fw::SerializeBufferBase {

            public:
                NATIVE_UINT_TYPE getBuffCapacity() const {
                    return InputGetCtrlDataPort::SERIALIZED_SIZE;
                }

                U8* getBuffAddr() {
                    return m_buff;
                }

                const U8* getBuffAddr() const {
                    return m_buff;
                }

        private:

            U8 m_buff[InputGetCtrlDataPort::SERIALIZED_SIZE];

        };

    }
    InputGetCtrlDataPort::InputGetCtrlDataPort() :
        Fw::InputPortBase(),
        m_func(nullptr) {
    }

    void InputGetCtrlDataPort::init() {
        Fw::InputPortBase::init();
    }

    void InputGetCtrlDataPort::addCallComp(Fw::PassiveComponentBase* callComp, CompFuncPtr funcPtr) {
        FW_ASSERT(callComp);
        FW_ASSERT(funcPtr);

        this->m_comp = callComp;
        this->m_func = funcPtr;
        this->m_connObj = callComp;
    }

    // call virtual logging function for component
    void InputGetCtrlDataPort::invoke(Ref::Mode &mode) {

#if FW_PORT_TRACING == 1
        this->trace();
#endif
        FW_ASSERT(this->m_comp);
        FW_ASSERT(this->m_func);
        this->m_func(this->m_comp, this->m_portNum, mode);
    }

#if FW_PORT_SERIALIZATION == 1    
    Fw::SerializeStatus InputGetCtrlDataPort::invokeSerial(Fw::SerializeBufferBase &buffer) {
        Fw::SerializeStatus _status;
#if FW_PORT_TRACING == 1
        this->trace();
#endif
        FW_ASSERT(this->m_comp);
        FW_ASSERT(this->m_func);


        Ref::Mode mode;
        _status = buffer.deserialize(mode);
        if (Fw::FW_SERIALIZE_OK != _status) {
            return _status;
        }

        this->m_func(this->m_comp, this->m_portNum, mode);
    
        return Fw::FW_SERIALIZE_OK;
    }
#endif

OutputGetCtrlDataPort::OutputGetCtrlDataPort() :
            Fw::OutputPortBase(),
    m_port(nullptr) {
}

void OutputGetCtrlDataPort::init() {
    Fw::OutputPortBase::init();
}

void OutputGetCtrlDataPort::addCallPort(InputGetCtrlDataPort* callPort) {
    FW_ASSERT(callPort);

    this->m_port = callPort;
    this->m_connObj = callPort;
#if FW_PORT_SERIALIZATION == 1
    this->m_serPort = nullptr;
#endif
}

void OutputGetCtrlDataPort::invoke(Ref::Mode &mode) {
#if FW_PORT_TRACING == 1
    this->trace();
#endif

#if FW_PORT_SERIALIZATION
    FW_ASSERT(this->m_port||this->m_serPort);
#else
    FW_ASSERT(this->m_port);
#endif

    if (this->m_port) {
        this->m_port->invoke(mode);
#if FW_PORT_SERIALIZATION
    } else if (this->m_serPort) {

        Fw::SerializeStatus _status;

        GetCtrlDataPortBuffer _buffer;
        _status = _buffer.serialize(mode);
        FW_ASSERT(Fw::FW_SERIALIZE_OK == _status,static_cast<AssertArg>(_status));

        _status = this->m_serPort->invokeSerial(_buffer);
        FW_ASSERT(Fw::FW_SERIALIZE_OK == _status,static_cast<AssertArg>(_status));
    }
#else
    }
#endif

} // end OutputGetCtrlDataPort::invoke(...)

} // end namespace Ref
