#include <Ref/DoActions/ActionsSerializableAc.hpp>
#include <Fw/Types/Assert.hpp>
#include <Fw/Types/BasicTypes.hpp>
#include <Fw/Types/StringUtils.hpp>
#if FW_SERIALIZABLE_TO_STRING
#include <Fw/Types/String.hpp>
#endif
#include <cstring>
namespace Ref {
// public methods

Actions::Actions(): Serializable() {
    this->m_thrDistribute = 0;
    this->m_protectFromSunlight = 0;
}

Actions::Actions(const Actions& src) : Serializable() {
    this->set(src.m_thrDistribute, src.m_protectFromSunlight);
}

Actions::Actions(const Actions* src) : Serializable() {
    FW_ASSERT(src);
    this->set(src->m_thrDistribute, src->m_protectFromSunlight);
}

Actions::Actions(U8 thrDistribute, U8 protectFromSunlight) : Serializable() {
    this->set(thrDistribute, protectFromSunlight);
}


Actions& Actions::operator=(const Actions& src) {
    if(this == &src) {
            return *this;
    }

    this->set(src.m_thrDistribute, src.m_protectFromSunlight);
    return *this;
}

bool Actions::operator==(const Actions& src) const {
    return (
        (src.m_thrDistribute == this->m_thrDistribute) &&
        (src.m_protectFromSunlight == this->m_protectFromSunlight) &&
        true);
}

void Actions::set(U8 thrDistribute, U8 protectFromSunlight) {
    this->m_thrDistribute = thrDistribute;
    this->m_protectFromSunlight = protectFromSunlight;
}

U8 Actions::getthrDistribute() const {
    return this->m_thrDistribute;
}

U8 Actions::getprotectFromSunlight() const {
    return this->m_protectFromSunlight;
}


void Actions::setthrDistribute(U8 val) {
    this->m_thrDistribute = val;
}
void Actions::setprotectFromSunlight(U8 val) {
    this->m_protectFromSunlight = val;
}
Fw::SerializeStatus Actions::serialize(Fw::SerializeBufferBase& buffer) const {
    Fw::SerializeStatus stat;

#if FW_SERIALIZATION_TYPE_ID
    // serialize type ID
    stat = buffer.serialize(static_cast<U32>(Actions::TYPE_ID));
#endif

    stat = buffer.serialize(this->m_thrDistribute);
    if (stat != Fw::FW_SERIALIZE_OK) {
        return stat;
    }
    stat = buffer.serialize(this->m_protectFromSunlight);
    if (stat != Fw::FW_SERIALIZE_OK) {
        return stat;
    }
    return stat;
}

Fw::SerializeStatus Actions::deserialize(Fw::SerializeBufferBase& buffer) {
    Fw::SerializeStatus stat;

#if FW_SERIALIZATION_TYPE_ID
    U32 typeId;

    stat = buffer.deserialize(typeId);
    if (stat != Fw::FW_SERIALIZE_OK) {
        return stat;
    }

    if (typeId != Actions::TYPE_ID) {
        return Fw::FW_DESERIALIZE_TYPE_MISMATCH;
    }
#endif

    stat = buffer.deserialize(this->m_thrDistribute);
    if (stat != Fw::FW_SERIALIZE_OK) {
        return stat;
    }
    stat = buffer.deserialize(this->m_protectFromSunlight);
    if (stat != Fw::FW_SERIALIZE_OK) {
        return stat;
    }
    return stat;
}

#if FW_SERIALIZABLE_TO_STRING  || BUILD_UT

void Actions::toString(Fw::StringBase& text) const {

    static const char * formatString =
       "("
       "thrDistribute = %u, "
       "protectFromSunlight = "
       ")";

    // declare strings to hold any serializable toString() arguments


    char outputString[FW_SERIALIZABLE_TO_STRING_BUFFER_SIZE];
    (void)snprintf(outputString,FW_SERIALIZABLE_TO_STRING_BUFFER_SIZE,formatString
       ,this->m_thrDistribute
       ,this->m_protectFromSunlight
    );
    outputString[FW_SERIALIZABLE_TO_STRING_BUFFER_SIZE-1] = 0; // NULL terminate

    text = outputString;
}

#endif

#ifdef BUILD_UT
    std::ostream& operator<<(std::ostream& os, const Actions& obj) {
        Fw::String str;
        obj.toString(str);
        os << str.toChar();
        return os;
    }
#endif
} // end namespace Ref
