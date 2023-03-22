#include <Ref/GetEnvData/SDSSDataSerializableAc.hpp>
#include <Fw/Types/Assert.hpp>
#include <Fw/Types/BasicTypes.hpp>
#include <Fw/Types/StringUtils.hpp>
#if FW_SERIALIZABLE_TO_STRING
#include <Fw/Types/String.hpp>
#endif
#include <cstring>
namespace Ref {
// public methods

SDSSData::SDSSData(): Serializable() {
    this->m_stateFlag_A = 0;
    this->m_stateFlag_B = 0;
    this->m_royaw = 0.0f;
    this->m_piyaw = 0.0f;
    this->m_flgSP = 0;
}

SDSSData::SDSSData(const SDSSData& src) : Serializable() {
    this->set(src.m_stateFlag_A, src.m_stateFlag_B, src.m_royaw, src.m_piyaw, src.m_flgSP);
}

SDSSData::SDSSData(const SDSSData* src) : Serializable() {
    FW_ASSERT(src);
    this->set(src->m_stateFlag_A, src->m_stateFlag_B, src->m_royaw, src->m_piyaw, src->m_flgSP);
}

SDSSData::SDSSData(U32 stateFlag_A, U32 stateFlag_B, F32 royaw, F32 piyaw, U32 flgSP) : Serializable() {
    this->set(stateFlag_A, stateFlag_B, royaw, piyaw, flgSP);
}


SDSSData& SDSSData::operator=(const SDSSData& src) {
    if(this == &src) {
            return *this;
    }

    this->set(src.m_stateFlag_A, src.m_stateFlag_B, src.m_royaw, src.m_piyaw, src.m_flgSP);
    return *this;
}

bool SDSSData::operator==(const SDSSData& src) const {
    return (
        (src.m_stateFlag_A == this->m_stateFlag_A) &&
        (src.m_stateFlag_B == this->m_stateFlag_B) &&
        (src.m_royaw == this->m_royaw) &&
        (src.m_piyaw == this->m_piyaw) &&
        (src.m_flgSP == this->m_flgSP) &&
        true);
}

void SDSSData::set(U32 stateFlag_A, U32 stateFlag_B, F32 royaw, F32 piyaw, U32 flgSP) {
    this->m_stateFlag_A = stateFlag_A;
    this->m_stateFlag_B = stateFlag_B;
    this->m_royaw = royaw;
    this->m_piyaw = piyaw;
    this->m_flgSP = flgSP;
}

U32 SDSSData::getstateFlag_A() const {
    return this->m_stateFlag_A;
}

U32 SDSSData::getstateFlag_B() const {
    return this->m_stateFlag_B;
}

F32 SDSSData::getroyaw() const {
    return this->m_royaw;
}

F32 SDSSData::getpiyaw() const {
    return this->m_piyaw;
}

U32 SDSSData::getflgSP() const {
    return this->m_flgSP;
}


void SDSSData::setstateFlag_A(U32 val) {
    this->m_stateFlag_A = val;
}
void SDSSData::setstateFlag_B(U32 val) {
    this->m_stateFlag_B = val;
}
void SDSSData::setroyaw(F32 val) {
    this->m_royaw = val;
}
void SDSSData::setpiyaw(F32 val) {
    this->m_piyaw = val;
}
void SDSSData::setflgSP(U32 val) {
    this->m_flgSP = val;
}
Fw::SerializeStatus SDSSData::serialize(Fw::SerializeBufferBase& buffer) const {
    Fw::SerializeStatus stat;

#if FW_SERIALIZATION_TYPE_ID
    // serialize type ID
    stat = buffer.serialize(static_cast<U32>(SDSSData::TYPE_ID));
#endif

    stat = buffer.serialize(this->m_stateFlag_A);
    if (stat != Fw::FW_SERIALIZE_OK) {
        return stat;
    }
    stat = buffer.serialize(this->m_stateFlag_B);
    if (stat != Fw::FW_SERIALIZE_OK) {
        return stat;
    }
    stat = buffer.serialize(this->m_royaw);
    if (stat != Fw::FW_SERIALIZE_OK) {
        return stat;
    }
    stat = buffer.serialize(this->m_piyaw);
    if (stat != Fw::FW_SERIALIZE_OK) {
        return stat;
    }
    stat = buffer.serialize(this->m_flgSP);
    if (stat != Fw::FW_SERIALIZE_OK) {
        return stat;
    }
    return stat;
}

Fw::SerializeStatus SDSSData::deserialize(Fw::SerializeBufferBase& buffer) {
    Fw::SerializeStatus stat;

#if FW_SERIALIZATION_TYPE_ID
    U32 typeId;

    stat = buffer.deserialize(typeId);
    if (stat != Fw::FW_SERIALIZE_OK) {
        return stat;
    }

    if (typeId != SDSSData::TYPE_ID) {
        return Fw::FW_DESERIALIZE_TYPE_MISMATCH;
    }
#endif

    stat = buffer.deserialize(this->m_stateFlag_A);
    if (stat != Fw::FW_SERIALIZE_OK) {
        return stat;
    }
    stat = buffer.deserialize(this->m_stateFlag_B);
    if (stat != Fw::FW_SERIALIZE_OK) {
        return stat;
    }
    stat = buffer.deserialize(this->m_royaw);
    if (stat != Fw::FW_SERIALIZE_OK) {
        return stat;
    }
    stat = buffer.deserialize(this->m_piyaw);
    if (stat != Fw::FW_SERIALIZE_OK) {
        return stat;
    }
    stat = buffer.deserialize(this->m_flgSP);
    if (stat != Fw::FW_SERIALIZE_OK) {
        return stat;
    }
    return stat;
}

#if FW_SERIALIZABLE_TO_STRING  || BUILD_UT

void SDSSData::toString(Fw::StringBase& text) const {

    static const char * formatString =
       "("
       "stateFlag_A = %u, "
       "stateFlag_B = %u, "
       "royaw = %g, "
       "piyaw = %g, "
       "flgSP = "
       ")";

    // declare strings to hold any serializable toString() arguments


    char outputString[FW_SERIALIZABLE_TO_STRING_BUFFER_SIZE];
    (void)snprintf(outputString,FW_SERIALIZABLE_TO_STRING_BUFFER_SIZE,formatString
       ,this->m_stateFlag_A
       ,this->m_stateFlag_B
       ,this->m_royaw
       ,this->m_piyaw
       ,this->m_flgSP
    );
    outputString[FW_SERIALIZABLE_TO_STRING_BUFFER_SIZE-1] = 0; // NULL terminate

    text = outputString;
}

#endif

#ifdef BUILD_UT
    std::ostream& operator<<(std::ostream& os, const SDSSData& obj) {
        Fw::String str;
        obj.toString(str);
        os << str.toChar();
        return os;
    }
#endif
} // end namespace Ref
