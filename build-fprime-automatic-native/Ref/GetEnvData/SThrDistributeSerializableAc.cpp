#include <Ref/GetEnvData/SThrDistributeSerializableAc.hpp>
#include <Fw/Types/Assert.hpp>
#include <Fw/Types/BasicTypes.hpp>
#include <Fw/Types/StringUtils.hpp>
#if FW_SERIALIZABLE_TO_STRING
#include <Fw/Types/String.hpp>
#endif
#include <cstring>
namespace Ref {
// public methods

SThrDistribute::SThrDistribute(): Serializable() {
    this->m_flagABChoose = 0;
    this->m_wPulse = 0;
    for (NATIVE_INT_TYPE _mem = 0; _mem < 2; _mem++) {
        this->m_stateFlag[_mem] = 0;
    }
}

SThrDistribute::SThrDistribute(const SThrDistribute& src) : Serializable() {
    this->set(src.m_flagABChoose, src.m_wPulse, src.m_stateFlag, 2);
}

SThrDistribute::SThrDistribute(const SThrDistribute* src) : Serializable() {
    FW_ASSERT(src);
    this->set(src->m_flagABChoose, src->m_wPulse, src->m_stateFlag, 2);
}

SThrDistribute::SThrDistribute(U16 flagABChoose, U8 wPulse, const U8* stateFlag, NATIVE_INT_TYPE stateFlagSize) : Serializable() {
    this->set(flagABChoose, wPulse, stateFlag, 2);
}

SThrDistribute::SThrDistribute(U16 flagABChoose, U8 wPulse, const U8 stateFlag) : Serializable() {
    this->m_flagABChoose = flagABChoose;
    this->m_wPulse = wPulse;
    for (NATIVE_INT_TYPE _mem = 0; _mem < 2; _mem++) {
        this->m_stateFlag[_mem] = stateFlag;
    }
}


SThrDistribute& SThrDistribute::operator=(const SThrDistribute& src) {
    if(this == &src) {
            return *this;
    }

    this->set(src.m_flagABChoose, src.m_wPulse, src.m_stateFlag, 2);
    return *this;
}

bool SThrDistribute::operator==(const SThrDistribute& src) const {
    return (
        (src.m_flagABChoose == this->m_flagABChoose) &&
        (src.m_wPulse == this->m_wPulse) &&
        (src.m_stateFlag == this->m_stateFlag) &&
        true);
}

void SThrDistribute::set(U16 flagABChoose, U8 wPulse, const U8* stateFlag, NATIVE_INT_TYPE stateFlagSize) {
    this->m_flagABChoose = flagABChoose;
    this->m_wPulse = wPulse;
    for (NATIVE_INT_TYPE _mem = 0; _mem < FW_MIN(stateFlagSize,2); _mem++) {
        this->m_stateFlag[_mem] = stateFlag[_mem];
    }
}

U16 SThrDistribute::getflagABChoose() const {
    return this->m_flagABChoose;
}

U8 SThrDistribute::getwPulse() const {
    return this->m_wPulse;
}

const U8* SThrDistribute::getstateFlag(NATIVE_INT_TYPE& size) const {
    size = 2;
    return this->m_stateFlag;
}


void SThrDistribute::setflagABChoose(U16 val) {
    this->m_flagABChoose = val;
}
void SThrDistribute::setwPulse(U8 val) {
    this->m_wPulse = val;
}
void SThrDistribute::setstateFlag(const U8* val, NATIVE_INT_TYPE size) {
    for (NATIVE_INT_TYPE _mem = 0; _mem < FW_MIN(size,2); _mem++) {
        this->m_stateFlag[_mem] = val[_mem];
    }
}
Fw::SerializeStatus SThrDistribute::serialize(Fw::SerializeBufferBase& buffer) const {
    Fw::SerializeStatus stat;

#if FW_SERIALIZATION_TYPE_ID
    // serialize type ID
    stat = buffer.serialize(static_cast<U32>(SThrDistribute::TYPE_ID));
#endif

    stat = buffer.serialize(this->m_flagABChoose);
    if (stat != Fw::FW_SERIALIZE_OK) {
        return stat;
    }
    stat = buffer.serialize(this->m_wPulse);
    if (stat != Fw::FW_SERIALIZE_OK) {
        return stat;
    }
    for (NATIVE_INT_TYPE _mem = 0; _mem < 2; _mem++) {
        stat = buffer.serialize(this->m_stateFlag[_mem]);
        if (stat != Fw::FW_SERIALIZE_OK) {
            return stat;
        }
    }
    return stat;
}

Fw::SerializeStatus SThrDistribute::deserialize(Fw::SerializeBufferBase& buffer) {
    Fw::SerializeStatus stat;

#if FW_SERIALIZATION_TYPE_ID
    U32 typeId;

    stat = buffer.deserialize(typeId);
    if (stat != Fw::FW_SERIALIZE_OK) {
        return stat;
    }

    if (typeId != SThrDistribute::TYPE_ID) {
        return Fw::FW_DESERIALIZE_TYPE_MISMATCH;
    }
#endif

    stat = buffer.deserialize(this->m_flagABChoose);
    if (stat != Fw::FW_SERIALIZE_OK) {
        return stat;
    }
    stat = buffer.deserialize(this->m_wPulse);
    if (stat != Fw::FW_SERIALIZE_OK) {
        return stat;
    }
    for (NATIVE_INT_TYPE _mem = 0; _mem < 2; _mem++) {
        stat = buffer.deserialize(this->m_stateFlag[_mem]);
        if (stat != Fw::FW_SERIALIZE_OK) {
            return stat;
        }
    }
    return stat;
}

#if FW_SERIALIZABLE_TO_STRING  || BUILD_UT

void SThrDistribute::toString(Fw::StringBase& text) const {

    static const char * formatString =
       "("
       "flagABChoose = %u, "
       "wPulse = %u, "
       "stateFlag = "
       "[]"
       "[] "
       ")";

    // declare strings to hold any serializable toString() arguments


    char outputString[FW_SERIALIZABLE_TO_STRING_BUFFER_SIZE];
    (void)snprintf(outputString,FW_SERIALIZABLE_TO_STRING_BUFFER_SIZE,formatString
       ,this->m_flagABChoose
       ,this->m_wPulse
       ,this->m_stateFlag[0]
       ,this->m_stateFlag[1]
    );
    outputString[FW_SERIALIZABLE_TO_STRING_BUFFER_SIZE-1] = 0; // NULL terminate

    text = outputString;
}

#endif

#ifdef BUILD_UT
    std::ostream& operator<<(std::ostream& os, const SThrDistribute& obj) {
        Fw::String str;
        obj.toString(str);
        os << str.toChar();
        return os;
    }
#endif
} // end namespace Ref
