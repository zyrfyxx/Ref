#include <FpConfig.hpp>
#include <Fw/Types/Assert.hpp>
#include <Fw/Types/Serializable.hpp>
#include <Fw/Types/StringUtils.hpp>

#include <Ref/ProtectFromSunlight/ProtectFromSunlightPortAc.hpp>
namespace Ref {


    namespace {

        class ProtectFromSunlightPortBuffer : public Fw::SerializeBufferBase {

            public:
                NATIVE_UINT_TYPE getBuffCapacity() const {
                    return InputProtectFromSunlightPort::SERIALIZED_SIZE;
                }

                U8* getBuffAddr() {
                    return nullptr;
                }

                const U8* getBuffAddr() const {
                    return nullptr;
                }

        private:


        };

    }
    InputProtectFromSunlightPort::InputProtectFromSunlightPort() :
        Fw::InputPortBase(),
        m_func(nullptr) {
    }

    void InputProtectFromSunlightPort::init() {
        Fw::InputPortBase::init();
    }

    void InputProtectFromSunlightPort::addCallComp(Fw::PassiveComponentBase* callComp, CompFuncPtr funcPtr) {
        FW_ASSERT(callComp);
        FW_ASSERT(funcPtr);

        this->m_comp = callComp;
        this->m_func = funcPtr;
        this->m_connObj = callComp;
    }

    // call virtual logging function for component
    void InputProtectFromSunlightPort::invoke() {

#if FW_PORT_TRACING == 1
        this->trace();
#endif
        FW_ASSERT(this->m_comp);
        FW_ASSERT(this->m_func);
        this->m_func(this->m_comp, this->m_portNum);
    }

#if FW_PORT_SERIALIZATION == 1    
    Fw::SerializeStatus InputProtectFromSunlightPort::invokeSerial(Fw::SerializeBufferBase &buffer) {
#if FW_PORT_TRACING == 1
        this->trace();
#endif
        FW_ASSERT(this->m_comp);
        FW_ASSERT(this->m_func);


        this->m_func(this->m_comp, this->m_portNum);
    
        return Fw::FW_SERIALIZE_OK;
    }
#endif

OutputProtectFromSunlightPort::OutputProtectFromSunlightPort() :
            Fw::OutputPortBase(),
    m_port(nullptr) {
}

void OutputProtectFromSunlightPort::init() {
    Fw::OutputPortBase::init();
}

void OutputProtectFromSunlightPort::addCallPort(InputProtectFromSunlightPort* callPort) {
    FW_ASSERT(callPort);

    this->m_port = callPort;
    this->m_connObj = callPort;
#if FW_PORT_SERIALIZATION == 1
    this->m_serPort = nullptr;
#endif
}

void OutputProtectFromSunlightPort::invoke() {
#if FW_PORT_TRACING == 1
    this->trace();
#endif

#if FW_PORT_SERIALIZATION
    FW_ASSERT(this->m_port||this->m_serPort);
#else
    FW_ASSERT(this->m_port);
#endif

    if (this->m_port) {
        this->m_port->invoke();
#if FW_PORT_SERIALIZATION
    } else if (this->m_serPort) {

        Fw::SerializeStatus _status;

        ProtectFromSunlightPortBuffer _buffer;
        _status = this->m_serPort->invokeSerial(_buffer);
        FW_ASSERT(Fw::FW_SERIALIZE_OK == _status,static_cast<AssertArg>(_status));
    }
#else
    }
#endif

} // end OutputProtectFromSunlightPort::invoke(...)

} // end namespace Ref
