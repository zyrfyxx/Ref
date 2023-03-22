#include <Ref/SignalGen/SignalPairSerializableAc.hpp>
#include <Fw/Types/Assert.hpp>
#include <Fw/Types/BasicTypes.hpp>
#include <Fw/Types/StringUtils.hpp>
#if FW_SERIALIZABLE_TO_STRING
#include <Fw/Types/String.hpp>
#endif
#include <cstring>
namespace Ref {
// public methods

SignalPair::SignalPair(): Serializable() {
    this->m_time = 0.0f;
    this->m_value = 0.0f;
}

SignalPair::SignalPair(const SignalPair& src) : Serializable() {
    this->set(src.m_time, src.m_value);
}

SignalPair::SignalPair(const SignalPair* src) : Serializable() {
    FW_ASSERT(src);
    this->set(src->m_time, src->m_value);
}

SignalPair::SignalPair(F32 time, F32 value) : Serializable() {
    this->set(time, value);
}


SignalPair& SignalPair::operator=(const SignalPair& src) {
    if(this == &src) {
            return *this;
    }

    this->set(src.m_time, src.m_value);
    return *this;
}

bool SignalPair::operator==(const SignalPair& src) const {
    return (
        (src.m_time == this->m_time) &&
        (src.m_value == this->m_value) &&
        true);
}

void SignalPair::set(F32 time, F32 value) {
    this->m_time = time;
    this->m_value = value;
}

F32 SignalPair::gettime() const {
    return this->m_time;
}

F32 SignalPair::getvalue() const {
    return this->m_value;
}


void SignalPair::settime(F32 val) {
    this->m_time = val;
}
void SignalPair::setvalue(F32 val) {
    this->m_value = val;
}
Fw::SerializeStatus SignalPair::serialize(Fw::SerializeBufferBase& buffer) const {
    Fw::SerializeStatus stat;

#if FW_SERIALIZATION_TYPE_ID
    // serialize type ID
    stat = buffer.serialize(static_cast<U32>(SignalPair::TYPE_ID));
#endif

    stat = buffer.serialize(this->m_time);
    if (stat != Fw::FW_SERIALIZE_OK) {
        return stat;
    }
    stat = buffer.serialize(this->m_value);
    if (stat != Fw::FW_SERIALIZE_OK) {
        return stat;
    }
    return stat;
}

Fw::SerializeStatus SignalPair::deserialize(Fw::SerializeBufferBase& buffer) {
    Fw::SerializeStatus stat;

#if FW_SERIALIZATION_TYPE_ID
    U32 typeId;

    stat = buffer.deserialize(typeId);
    if (stat != Fw::FW_SERIALIZE_OK) {
        return stat;
    }

    if (typeId != SignalPair::TYPE_ID) {
        return Fw::FW_DESERIALIZE_TYPE_MISMATCH;
    }
#endif

    stat = buffer.deserialize(this->m_time);
    if (stat != Fw::FW_SERIALIZE_OK) {
        return stat;
    }
    stat = buffer.deserialize(this->m_value);
    if (stat != Fw::FW_SERIALIZE_OK) {
        return stat;
    }
    return stat;
}

#if FW_SERIALIZABLE_TO_STRING  || BUILD_UT

void SignalPair::toString(Fw::StringBase& text) const {

    static const char * formatString =
       "("
       "time = %f, "
       "value = "
       ")";

    // declare strings to hold any serializable toString() arguments


    char outputString[FW_SERIALIZABLE_TO_STRING_BUFFER_SIZE];
    (void)snprintf(outputString,FW_SERIALIZABLE_TO_STRING_BUFFER_SIZE,formatString
       ,this->m_time
       ,this->m_value
    );
    outputString[FW_SERIALIZABLE_TO_STRING_BUFFER_SIZE-1] = 0; // NULL terminate

    text = outputString;
}

#endif

#ifdef BUILD_UT
    std::ostream& operator<<(std::ostream& os, const SignalPair& obj) {
        Fw::String str;
        obj.toString(str);
        os << str.toChar();
        return os;
    }
#endif
} // end namespace Ref
