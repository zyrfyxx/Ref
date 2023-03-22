#include <FpConfig.hpp>
#include <Fw/Types/Assert.hpp>
#include <Fw/Types/Serializable.hpp>
#include <Fw/Types/StringUtils.hpp>

#include <Svc/Cycle/CyclePortAc.hpp>
namespace Svc {


    namespace {

        class CyclePortBuffer : public Fw::SerializeBufferBase {

            public:
                NATIVE_UINT_TYPE getBuffCapacity() const {
                    return InputCyclePort::SERIALIZED_SIZE;
                }

                U8* getBuffAddr() {
                    return m_buff;
                }

                const U8* getBuffAddr() const {
                    return m_buff;
                }

        private:

            U8 m_buff[InputCyclePort::SERIALIZED_SIZE];

        };

    }
    InputCyclePort::InputCyclePort() :
        Fw::InputPortBase(),
        m_func(nullptr) {
    }

    void InputCyclePort::init() {
        Fw::InputPortBase::init();
    }

    void InputCyclePort::addCallComp(Fw::PassiveComponentBase* callComp, CompFuncPtr funcPtr) {
        FW_ASSERT(callComp);
        FW_ASSERT(funcPtr);

        this->m_comp = callComp;
        this->m_func = funcPtr;
        this->m_connObj = callComp;
    }

    // call virtual logging function for component
    void InputCyclePort::invoke(Svc::TimerVal &cycleStart) {

#if FW_PORT_TRACING == 1
        this->trace();
#endif
        FW_ASSERT(this->m_comp);
        FW_ASSERT(this->m_func);
        this->m_func(this->m_comp, this->m_portNum, cycleStart);
    }

#if FW_PORT_SERIALIZATION == 1    
    Fw::SerializeStatus InputCyclePort::invokeSerial(Fw::SerializeBufferBase &buffer) {
        Fw::SerializeStatus _status;
#if FW_PORT_TRACING == 1
        this->trace();
#endif
        FW_ASSERT(this->m_comp);
        FW_ASSERT(this->m_func);


        Svc::TimerVal cycleStart;
        _status = buffer.deserialize(cycleStart);
        if (Fw::FW_SERIALIZE_OK != _status) {
            return _status;
        }

        this->m_func(this->m_comp, this->m_portNum, cycleStart);
    
        return Fw::FW_SERIALIZE_OK;
    }
#endif

OutputCyclePort::OutputCyclePort() :
            Fw::OutputPortBase(),
    m_port(nullptr) {
}

void OutputCyclePort::init() {
    Fw::OutputPortBase::init();
}

void OutputCyclePort::addCallPort(InputCyclePort* callPort) {
    FW_ASSERT(callPort);

    this->m_port = callPort;
    this->m_connObj = callPort;
#if FW_PORT_SERIALIZATION == 1
    this->m_serPort = nullptr;
#endif
}

void OutputCyclePort::invoke(Svc::TimerVal &cycleStart) {
#if FW_PORT_TRACING == 1
    this->trace();
#endif

#if FW_PORT_SERIALIZATION
    FW_ASSERT(this->m_port||this->m_serPort);
#else
    FW_ASSERT(this->m_port);
#endif

    if (this->m_port) {
        this->m_port->invoke(cycleStart);
#if FW_PORT_SERIALIZATION
    } else if (this->m_serPort) {

        Fw::SerializeStatus _status;

        CyclePortBuffer _buffer;
        _status = _buffer.serialize(cycleStart);
        FW_ASSERT(Fw::FW_SERIALIZE_OK == _status,static_cast<AssertArg>(_status));

        _status = this->m_serPort->invokeSerial(_buffer);
        FW_ASSERT(Fw::FW_SERIALIZE_OK == _status,static_cast<AssertArg>(_status));
    }
#else
    }
#endif

} // end OutputCyclePort::invoke(...)

} // end namespace Svc
