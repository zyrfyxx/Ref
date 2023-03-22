#include <Ref/DataType/SAttitudeSerializableAc.hpp>
#include <Fw/Types/Assert.hpp>
#include <Fw/Types/BasicTypes.hpp>
#include <Fw/Types/StringUtils.hpp>
#if FW_SERIALIZABLE_TO_STRING
#include <Fw/Types/String.hpp>
#endif
#include <cstring>
namespace Ref {
// public methods

SAttitude::SAttitude(): Serializable() {
    for (NATIVE_INT_TYPE _mem = 0; _mem < 3; _mem++) {
        this->m_angle[_mem] = 0.0f;
    }
    for (NATIVE_INT_TYPE _mem = 0; _mem < 3; _mem++) {
        this->m_rate[_mem] = 0.0f;
    }
}

SAttitude::SAttitude(const SAttitude& src) : Serializable() {
    this->set(src.m_angle, 3, src.m_rate, 3);
}

SAttitude::SAttitude(const SAttitude* src) : Serializable() {
    FW_ASSERT(src);
    this->set(src->m_angle, 3, src->m_rate, 3);
}

SAttitude::SAttitude(const F32* angle, NATIVE_INT_TYPE angleSize, const F32* rate, NATIVE_INT_TYPE rateSize) : Serializable() {
    this->set(angle, 3, rate, 3);
}

SAttitude::SAttitude(const F32 angle, const F32 rate) : Serializable() {
    for (NATIVE_INT_TYPE _mem = 0; _mem < 3; _mem++) {
        this->m_angle[_mem] = angle;
    }
    for (NATIVE_INT_TYPE _mem = 0; _mem < 3; _mem++) {
        this->m_rate[_mem] = rate;
    }
}


SAttitude& SAttitude::operator=(const SAttitude& src) {
    if(this == &src) {
            return *this;
    }

    this->set(src.m_angle, 3, src.m_rate, 3);
    return *this;
}

bool SAttitude::operator==(const SAttitude& src) const {
    return (
        (src.m_angle == this->m_angle) &&
        (src.m_rate == this->m_rate) &&
        true);
}

void SAttitude::set(const F32* angle, NATIVE_INT_TYPE angleSize, const F32* rate, NATIVE_INT_TYPE rateSize) {
    for (NATIVE_INT_TYPE _mem = 0; _mem < FW_MIN(angleSize,3); _mem++) {
        this->m_angle[_mem] = angle[_mem];
    }
    for (NATIVE_INT_TYPE _mem = 0; _mem < FW_MIN(rateSize,3); _mem++) {
        this->m_rate[_mem] = rate[_mem];
    }
}

const F32* SAttitude::getangle(NATIVE_INT_TYPE& size) const {
    size = 3;
    return this->m_angle;
}

const F32* SAttitude::getrate(NATIVE_INT_TYPE& size) const {
    size = 3;
    return this->m_rate;
}


void SAttitude::setangle(const F32* val, NATIVE_INT_TYPE size) {
    for (NATIVE_INT_TYPE _mem = 0; _mem < FW_MIN(size,3); _mem++) {
        this->m_angle[_mem] = val[_mem];
    }
}
void SAttitude::setrate(const F32* val, NATIVE_INT_TYPE size) {
    for (NATIVE_INT_TYPE _mem = 0; _mem < FW_MIN(size,3); _mem++) {
        this->m_rate[_mem] = val[_mem];
    }
}
Fw::SerializeStatus SAttitude::serialize(Fw::SerializeBufferBase& buffer) const {
    Fw::SerializeStatus stat;

#if FW_SERIALIZATION_TYPE_ID
    // serialize type ID
    stat = buffer.serialize(static_cast<U32>(SAttitude::TYPE_ID));
#endif

    for (NATIVE_INT_TYPE _mem = 0; _mem < 3; _mem++) {
        stat = buffer.serialize(this->m_angle[_mem]);
        if (stat != Fw::FW_SERIALIZE_OK) {
            return stat;
        }
    }
    for (NATIVE_INT_TYPE _mem = 0; _mem < 3; _mem++) {
        stat = buffer.serialize(this->m_rate[_mem]);
        if (stat != Fw::FW_SERIALIZE_OK) {
            return stat;
        }
    }
    return stat;
}

Fw::SerializeStatus SAttitude::deserialize(Fw::SerializeBufferBase& buffer) {
    Fw::SerializeStatus stat;

#if FW_SERIALIZATION_TYPE_ID
    U32 typeId;

    stat = buffer.deserialize(typeId);
    if (stat != Fw::FW_SERIALIZE_OK) {
        return stat;
    }

    if (typeId != SAttitude::TYPE_ID) {
        return Fw::FW_DESERIALIZE_TYPE_MISMATCH;
    }
#endif

    for (NATIVE_INT_TYPE _mem = 0; _mem < 3; _mem++) {
        stat = buffer.deserialize(this->m_angle[_mem]);
        if (stat != Fw::FW_SERIALIZE_OK) {
            return stat;
        }
    }
    for (NATIVE_INT_TYPE _mem = 0; _mem < 3; _mem++) {
        stat = buffer.deserialize(this->m_rate[_mem]);
        if (stat != Fw::FW_SERIALIZE_OK) {
            return stat;
        }
    }
    return stat;
}

#if FW_SERIALIZABLE_TO_STRING  || BUILD_UT

void SAttitude::toString(Fw::StringBase& text) const {

    static const char * formatString =
       "("
       "angle = "
       "[%g]"
       "[%g]"
       "[%g] "
       "rate = "
       "[]"
       "[]"
       "[] "
       ")";

    // declare strings to hold any serializable toString() arguments


    char outputString[FW_SERIALIZABLE_TO_STRING_BUFFER_SIZE];
    (void)snprintf(outputString,FW_SERIALIZABLE_TO_STRING_BUFFER_SIZE,formatString
       ,this->m_angle[0]
       ,this->m_angle[1]
       ,this->m_angle[2]
       ,this->m_rate[0]
       ,this->m_rate[1]
       ,this->m_rate[2]
    );
    outputString[FW_SERIALIZABLE_TO_STRING_BUFFER_SIZE-1] = 0; // NULL terminate

    text = outputString;
}

#endif

#ifdef BUILD_UT
    std::ostream& operator<<(std::ostream& os, const SAttitude& obj) {
        Fw::String str;
        obj.toString(str);
        os << str.toChar();
        return os;
    }
#endif
} // end namespace Ref
