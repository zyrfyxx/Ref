#include <FpConfig.hpp>
#include <Fw/Types/Assert.hpp>
#include <Fw/Types/Serializable.hpp>
#include <Fw/Types/StringUtils.hpp>

#include <Svc/FileDownlinkPorts/SendFileCompletePortAc.hpp>
namespace Svc {


    namespace {

        class SendFileCompletePortBuffer : public Fw::SerializeBufferBase {

            public:
                NATIVE_UINT_TYPE getBuffCapacity() const {
                    return InputSendFileCompletePort::SERIALIZED_SIZE;
                }

                U8* getBuffAddr() {
                    return m_buff;
                }

                const U8* getBuffAddr() const {
                    return m_buff;
                }

        private:

            U8 m_buff[InputSendFileCompletePort::SERIALIZED_SIZE];

        };

    }
    InputSendFileCompletePort::InputSendFileCompletePort() :
        Fw::InputPortBase(),
        m_func(nullptr) {
    }

    void InputSendFileCompletePort::init() {
        Fw::InputPortBase::init();
    }

    void InputSendFileCompletePort::addCallComp(Fw::PassiveComponentBase* callComp, CompFuncPtr funcPtr) {
        FW_ASSERT(callComp);
        FW_ASSERT(funcPtr);

        this->m_comp = callComp;
        this->m_func = funcPtr;
        this->m_connObj = callComp;
    }

    // call virtual logging function for component
    void InputSendFileCompletePort::invoke(const Svc::SendFileResponse &resp) {

#if FW_PORT_TRACING == 1
        this->trace();
#endif
        FW_ASSERT(this->m_comp);
        FW_ASSERT(this->m_func);
        this->m_func(this->m_comp, this->m_portNum, resp);
    }

#if FW_PORT_SERIALIZATION == 1    
    Fw::SerializeStatus InputSendFileCompletePort::invokeSerial(Fw::SerializeBufferBase &buffer) {
        Fw::SerializeStatus _status;
#if FW_PORT_TRACING == 1
        this->trace();
#endif
        FW_ASSERT(this->m_comp);
        FW_ASSERT(this->m_func);


        Svc::SendFileResponse resp;
        _status = buffer.deserialize(resp);
        if (Fw::FW_SERIALIZE_OK != _status) {
            return _status;
        }

        this->m_func(this->m_comp, this->m_portNum, resp);
    
        return Fw::FW_SERIALIZE_OK;
    }
#endif

OutputSendFileCompletePort::OutputSendFileCompletePort() :
            Fw::OutputPortBase(),
    m_port(nullptr) {
}

void OutputSendFileCompletePort::init() {
    Fw::OutputPortBase::init();
}

void OutputSendFileCompletePort::addCallPort(InputSendFileCompletePort* callPort) {
    FW_ASSERT(callPort);

    this->m_port = callPort;
    this->m_connObj = callPort;
#if FW_PORT_SERIALIZATION == 1
    this->m_serPort = nullptr;
#endif
}

void OutputSendFileCompletePort::invoke(const Svc::SendFileResponse &resp) {
#if FW_PORT_TRACING == 1
    this->trace();
#endif

#if FW_PORT_SERIALIZATION
    FW_ASSERT(this->m_port||this->m_serPort);
#else
    FW_ASSERT(this->m_port);
#endif

    if (this->m_port) {
        this->m_port->invoke(resp);
#if FW_PORT_SERIALIZATION
    } else if (this->m_serPort) {

        Fw::SerializeStatus _status;

        SendFileCompletePortBuffer _buffer;
        _status = _buffer.serialize(resp);
        FW_ASSERT(Fw::FW_SERIALIZE_OK == _status,static_cast<AssertArg>(_status));

        _status = this->m_serPort->invokeSerial(_buffer);
        FW_ASSERT(Fw::FW_SERIALIZE_OK == _status,static_cast<AssertArg>(_status));
    }
#else
    }
#endif

} // end OutputSendFileCompletePort::invoke(...)

} // end namespace Svc
