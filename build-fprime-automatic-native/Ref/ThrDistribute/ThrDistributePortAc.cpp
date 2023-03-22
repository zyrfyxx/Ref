#include <FpConfig.hpp>
#include <Fw/Types/Assert.hpp>
#include <Fw/Types/Serializable.hpp>
#include <Fw/Types/StringUtils.hpp>

#include <Ref/ThrDistribute/ThrDistributePortAc.hpp>
namespace Ref {


    namespace {

        class ThrDistributePortBuffer : public Fw::SerializeBufferBase {

            public:
                NATIVE_UINT_TYPE getBuffCapacity() const {
                    return InputThrDistributePort::SERIALIZED_SIZE;
                }

                U8* getBuffAddr() {
                    return m_buff;
                }

                const U8* getBuffAddr() const {
                    return m_buff;
                }

        private:

            U8 m_buff[InputThrDistributePort::SERIALIZED_SIZE];

        };

    }
    InputThrDistributePort::InputThrDistributePort() :
        Fw::InputPortBase(),
        m_func(nullptr) {
    }

    void InputThrDistributePort::init() {
        Fw::InputPortBase::init();
    }

    void InputThrDistributePort::addCallComp(Fw::PassiveComponentBase* callComp, CompFuncPtr funcPtr) {
        FW_ASSERT(callComp);
        FW_ASSERT(funcPtr);

        this->m_comp = callComp;
        this->m_func = funcPtr;
        this->m_connObj = callComp;
    }

    // call virtual logging function for component
    void InputThrDistributePort::invoke(U8 wPulse) {

#if FW_PORT_TRACING == 1
        this->trace();
#endif
        FW_ASSERT(this->m_comp);
        FW_ASSERT(this->m_func);
        this->m_func(this->m_comp, this->m_portNum, wPulse);
    }

#if FW_PORT_SERIALIZATION == 1    
    Fw::SerializeStatus InputThrDistributePort::invokeSerial(Fw::SerializeBufferBase &buffer) {
        Fw::SerializeStatus _status;
#if FW_PORT_TRACING == 1
        this->trace();
#endif
        FW_ASSERT(this->m_comp);
        FW_ASSERT(this->m_func);


        U8 wPulse;
        _status = buffer.deserialize(wPulse);
        if (Fw::FW_SERIALIZE_OK != _status) {
            return _status;
        }

        this->m_func(this->m_comp, this->m_portNum, wPulse);
    
        return Fw::FW_SERIALIZE_OK;
    }
#endif

OutputThrDistributePort::OutputThrDistributePort() :
            Fw::OutputPortBase(),
    m_port(nullptr) {
}

void OutputThrDistributePort::init() {
    Fw::OutputPortBase::init();
}

void OutputThrDistributePort::addCallPort(InputThrDistributePort* callPort) {
    FW_ASSERT(callPort);

    this->m_port = callPort;
    this->m_connObj = callPort;
#if FW_PORT_SERIALIZATION == 1
    this->m_serPort = nullptr;
#endif
}

void OutputThrDistributePort::invoke(U8 wPulse) {
#if FW_PORT_TRACING == 1
    this->trace();
#endif

#if FW_PORT_SERIALIZATION
    FW_ASSERT(this->m_port||this->m_serPort);
#else
    FW_ASSERT(this->m_port);
#endif

    if (this->m_port) {
        this->m_port->invoke(wPulse);
#if FW_PORT_SERIALIZATION
    } else if (this->m_serPort) {

        Fw::SerializeStatus _status;

        ThrDistributePortBuffer _buffer;
        _status = _buffer.serialize(wPulse);
        FW_ASSERT(Fw::FW_SERIALIZE_OK == _status,static_cast<AssertArg>(_status));

        _status = this->m_serPort->invokeSerial(_buffer);
        FW_ASSERT(Fw::FW_SERIALIZE_OK == _status,static_cast<AssertArg>(_status));
    }
#else
    }
#endif

} // end OutputThrDistributePort::invoke(...)

} // end namespace Ref
