#include <Ref/DoActions/ParameterSerializableAc.hpp>
#include <Fw/Types/Assert.hpp>
#include <Fw/Types/BasicTypes.hpp>
#include <Fw/Types/StringUtils.hpp>
#if FW_SERIALIZABLE_TO_STRING
#include <Fw/Types/String.hpp>
#endif
#include <cstring>
namespace Ref {
// public methods

Parameter::Parameter(): Serializable() {
    this->m_wPulse = 0;
}

Parameter::Parameter(const Parameter& src) : Serializable() {
    this->set(src.m_wPulse);
}

Parameter::Parameter(const Parameter* src) : Serializable() {
    FW_ASSERT(src);
    this->set(src->m_wPulse);
}

Parameter::Parameter(U8 wPulse) : Serializable() {
    this->set(wPulse);
}


Parameter& Parameter::operator=(const Parameter& src) {
    if(this == &src) {
            return *this;
    }

    this->set(src.m_wPulse);
    return *this;
}

bool Parameter::operator==(const Parameter& src) const {
    return (
        (src.m_wPulse == this->m_wPulse) &&
        true);
}

void Parameter::set(U8 wPulse) {
    this->m_wPulse = wPulse;
}

U8 Parameter::getwPulse() const {
    return this->m_wPulse;
}


void Parameter::setwPulse(U8 val) {
    this->m_wPulse = val;
}
Fw::SerializeStatus Parameter::serialize(Fw::SerializeBufferBase& buffer) const {
    Fw::SerializeStatus stat;

#if FW_SERIALIZATION_TYPE_ID
    // serialize type ID
    stat = buffer.serialize(static_cast<U32>(Parameter::TYPE_ID));
#endif

    stat = buffer.serialize(this->m_wPulse);
    if (stat != Fw::FW_SERIALIZE_OK) {
        return stat;
    }
    return stat;
}

Fw::SerializeStatus Parameter::deserialize(Fw::SerializeBufferBase& buffer) {
    Fw::SerializeStatus stat;

#if FW_SERIALIZATION_TYPE_ID
    U32 typeId;

    stat = buffer.deserialize(typeId);
    if (stat != Fw::FW_SERIALIZE_OK) {
        return stat;
    }

    if (typeId != Parameter::TYPE_ID) {
        return Fw::FW_DESERIALIZE_TYPE_MISMATCH;
    }
#endif

    stat = buffer.deserialize(this->m_wPulse);
    if (stat != Fw::FW_SERIALIZE_OK) {
        return stat;
    }
    return stat;
}

#if FW_SERIALIZABLE_TO_STRING  || BUILD_UT

void Parameter::toString(Fw::StringBase& text) const {

    static const char * formatString =
       "("
       "wPulse = "
       ")";

    // declare strings to hold any serializable toString() arguments


    char outputString[FW_SERIALIZABLE_TO_STRING_BUFFER_SIZE];
    (void)snprintf(outputString,FW_SERIALIZABLE_TO_STRING_BUFFER_SIZE,formatString
       ,this->m_wPulse
    );
    outputString[FW_SERIALIZABLE_TO_STRING_BUFFER_SIZE-1] = 0; // NULL terminate

    text = outputString;
}

#endif

#ifdef BUILD_UT
    std::ostream& operator<<(std::ostream& os, const Parameter& obj) {
        Fw::String str;
        obj.toString(str);
        os << str.toChar();
        return os;
    }
#endif
} // end namespace Ref
