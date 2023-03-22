#include <FpConfig.hpp>
#include <Fw/Types/Assert.hpp>
#include <Fw/Types/Serializable.hpp>
#include <Fw/Types/StringUtils.hpp>

#include <Ref/DoActions/DoActionsPortAc.hpp>
namespace Ref {


    namespace {

        class DoActionsPortBuffer : public Fw::SerializeBufferBase {

            public:
                NATIVE_UINT_TYPE getBuffCapacity() const {
                    return InputDoActionsPort::SERIALIZED_SIZE;
                }

                U8* getBuffAddr() {
                    return m_buff;
                }

                const U8* getBuffAddr() const {
                    return m_buff;
                }

        private:

            U8 m_buff[InputDoActionsPort::SERIALIZED_SIZE];

        };

    }
    InputDoActionsPort::InputDoActionsPort() :
        Fw::InputPortBase(),
        m_func(nullptr) {
    }

    void InputDoActionsPort::init() {
        Fw::InputPortBase::init();
    }

    void InputDoActionsPort::addCallComp(Fw::PassiveComponentBase* callComp, CompFuncPtr funcPtr) {
        FW_ASSERT(callComp);
        FW_ASSERT(funcPtr);

        this->m_comp = callComp;
        this->m_func = funcPtr;
        this->m_connObj = callComp;
    }

    // call virtual logging function for component
    void InputDoActionsPort::invoke(const Ref::Actions &actions, const Ref::Parameter &parameter) {

#if FW_PORT_TRACING == 1
        this->trace();
#endif
        FW_ASSERT(this->m_comp);
        FW_ASSERT(this->m_func);
        this->m_func(this->m_comp, this->m_portNum, actions, parameter);
    }

#if FW_PORT_SERIALIZATION == 1    
    Fw::SerializeStatus InputDoActionsPort::invokeSerial(Fw::SerializeBufferBase &buffer) {
        Fw::SerializeStatus _status;
#if FW_PORT_TRACING == 1
        this->trace();
#endif
        FW_ASSERT(this->m_comp);
        FW_ASSERT(this->m_func);


        Ref::Actions actions;
        _status = buffer.deserialize(actions);
        if (Fw::FW_SERIALIZE_OK != _status) {
            return _status;
        }

        Ref::Parameter parameter;
        _status = buffer.deserialize(parameter);
        if (Fw::FW_SERIALIZE_OK != _status) {
            return _status;
        }

        this->m_func(this->m_comp, this->m_portNum, actions, parameter);
    
        return Fw::FW_SERIALIZE_OK;
    }
#endif

OutputDoActionsPort::OutputDoActionsPort() :
            Fw::OutputPortBase(),
    m_port(nullptr) {
}

void OutputDoActionsPort::init() {
    Fw::OutputPortBase::init();
}

void OutputDoActionsPort::addCallPort(InputDoActionsPort* callPort) {
    FW_ASSERT(callPort);

    this->m_port = callPort;
    this->m_connObj = callPort;
#if FW_PORT_SERIALIZATION == 1
    this->m_serPort = nullptr;
#endif
}

void OutputDoActionsPort::invoke(const Ref::Actions &actions, const Ref::Parameter &parameter) {
#if FW_PORT_TRACING == 1
    this->trace();
#endif

#if FW_PORT_SERIALIZATION
    FW_ASSERT(this->m_port||this->m_serPort);
#else
    FW_ASSERT(this->m_port);
#endif

    if (this->m_port) {
        this->m_port->invoke(actions, parameter);
#if FW_PORT_SERIALIZATION
    } else if (this->m_serPort) {

        Fw::SerializeStatus _status;

        DoActionsPortBuffer _buffer;
        _status = _buffer.serialize(actions);
        FW_ASSERT(Fw::FW_SERIALIZE_OK == _status,static_cast<AssertArg>(_status));

        _status = _buffer.serialize(parameter);
        FW_ASSERT(Fw::FW_SERIALIZE_OK == _status,static_cast<AssertArg>(_status));

        _status = this->m_serPort->invokeSerial(_buffer);
        FW_ASSERT(Fw::FW_SERIALIZE_OK == _status,static_cast<AssertArg>(_status));
    }
#else
    }
#endif

} // end OutputDoActionsPort::invoke(...)

} // end namespace Ref
