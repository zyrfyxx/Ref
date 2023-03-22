#include <Ref/DataType/SControllerSerializableAc.hpp>
#include <Fw/Types/Assert.hpp>
#include <Fw/Types/BasicTypes.hpp>
#include <Fw/Types/StringUtils.hpp>
#if FW_SERIALIZABLE_TO_STRING
#include <Fw/Types/String.hpp>
#endif
#include <cstring>
namespace Ref {
// public methods

SController::SController(): Serializable() {
    for (NATIVE_INT_TYPE _mem = 0; _mem < 3; _mem++) {
        this->m_Up[_mem] = 0.0f;
    }
    for (NATIVE_INT_TYPE _mem = 0; _mem < 3; _mem++) {
        this->m_Ud[_mem] = 0.0f;
    }
    for (NATIVE_INT_TYPE _mem = 0; _mem < 3; _mem++) {
        this->m_fy[_mem] = 0.0f;
    }
}

SController::SController(const SController& src) : Serializable() {
    this->set(src.m_Up, 3, src.m_Ud, 3, src.m_fy, 3);
}

SController::SController(const SController* src) : Serializable() {
    FW_ASSERT(src);
    this->set(src->m_Up, 3, src->m_Ud, 3, src->m_fy, 3);
}

SController::SController(const F32* Up, NATIVE_INT_TYPE UpSize, const F32* Ud, NATIVE_INT_TYPE UdSize, const F32* fy, NATIVE_INT_TYPE fySize) : Serializable() {
    this->set(Up, 3, Ud, 3, fy, 3);
}

SController::SController(const F32 Up, const F32 Ud, const F32 fy) : Serializable() {
    for (NATIVE_INT_TYPE _mem = 0; _mem < 3; _mem++) {
        this->m_Up[_mem] = Up;
    }
    for (NATIVE_INT_TYPE _mem = 0; _mem < 3; _mem++) {
        this->m_Ud[_mem] = Ud;
    }
    for (NATIVE_INT_TYPE _mem = 0; _mem < 3; _mem++) {
        this->m_fy[_mem] = fy;
    }
}


SController& SController::operator=(const SController& src) {
    if(this == &src) {
            return *this;
    }

    this->set(src.m_Up, 3, src.m_Ud, 3, src.m_fy, 3);
    return *this;
}

bool SController::operator==(const SController& src) const {
    return (
        (src.m_Up == this->m_Up) &&
        (src.m_Ud == this->m_Ud) &&
        (src.m_fy == this->m_fy) &&
        true);
}

void SController::set(const F32* Up, NATIVE_INT_TYPE UpSize, const F32* Ud, NATIVE_INT_TYPE UdSize, const F32* fy, NATIVE_INT_TYPE fySize) {
    for (NATIVE_INT_TYPE _mem = 0; _mem < FW_MIN(UpSize,3); _mem++) {
        this->m_Up[_mem] = Up[_mem];
    }
    for (NATIVE_INT_TYPE _mem = 0; _mem < FW_MIN(UdSize,3); _mem++) {
        this->m_Ud[_mem] = Ud[_mem];
    }
    for (NATIVE_INT_TYPE _mem = 0; _mem < FW_MIN(fySize,3); _mem++) {
        this->m_fy[_mem] = fy[_mem];
    }
}

const F32* SController::getUp(NATIVE_INT_TYPE& size) const {
    size = 3;
    return this->m_Up;
}

const F32* SController::getUd(NATIVE_INT_TYPE& size) const {
    size = 3;
    return this->m_Ud;
}

const F32* SController::getfy(NATIVE_INT_TYPE& size) const {
    size = 3;
    return this->m_fy;
}


void SController::setUp(const F32* val, NATIVE_INT_TYPE size) {
    for (NATIVE_INT_TYPE _mem = 0; _mem < FW_MIN(size,3); _mem++) {
        this->m_Up[_mem] = val[_mem];
    }
}
void SController::setUd(const F32* val, NATIVE_INT_TYPE size) {
    for (NATIVE_INT_TYPE _mem = 0; _mem < FW_MIN(size,3); _mem++) {
        this->m_Ud[_mem] = val[_mem];
    }
}
void SController::setfy(const F32* val, NATIVE_INT_TYPE size) {
    for (NATIVE_INT_TYPE _mem = 0; _mem < FW_MIN(size,3); _mem++) {
        this->m_fy[_mem] = val[_mem];
    }
}
Fw::SerializeStatus SController::serialize(Fw::SerializeBufferBase& buffer) const {
    Fw::SerializeStatus stat;

#if FW_SERIALIZATION_TYPE_ID
    // serialize type ID
    stat = buffer.serialize(static_cast<U32>(SController::TYPE_ID));
#endif

    for (NATIVE_INT_TYPE _mem = 0; _mem < 3; _mem++) {
        stat = buffer.serialize(this->m_Up[_mem]);
        if (stat != Fw::FW_SERIALIZE_OK) {
            return stat;
        }
    }
    for (NATIVE_INT_TYPE _mem = 0; _mem < 3; _mem++) {
        stat = buffer.serialize(this->m_Ud[_mem]);
        if (stat != Fw::FW_SERIALIZE_OK) {
            return stat;
        }
    }
    for (NATIVE_INT_TYPE _mem = 0; _mem < 3; _mem++) {
        stat = buffer.serialize(this->m_fy[_mem]);
        if (stat != Fw::FW_SERIALIZE_OK) {
            return stat;
        }
    }
    return stat;
}

Fw::SerializeStatus SController::deserialize(Fw::SerializeBufferBase& buffer) {
    Fw::SerializeStatus stat;

#if FW_SERIALIZATION_TYPE_ID
    U32 typeId;

    stat = buffer.deserialize(typeId);
    if (stat != Fw::FW_SERIALIZE_OK) {
        return stat;
    }

    if (typeId != SController::TYPE_ID) {
        return Fw::FW_DESERIALIZE_TYPE_MISMATCH;
    }
#endif

    for (NATIVE_INT_TYPE _mem = 0; _mem < 3; _mem++) {
        stat = buffer.deserialize(this->m_Up[_mem]);
        if (stat != Fw::FW_SERIALIZE_OK) {
            return stat;
        }
    }
    for (NATIVE_INT_TYPE _mem = 0; _mem < 3; _mem++) {
        stat = buffer.deserialize(this->m_Ud[_mem]);
        if (stat != Fw::FW_SERIALIZE_OK) {
            return stat;
        }
    }
    for (NATIVE_INT_TYPE _mem = 0; _mem < 3; _mem++) {
        stat = buffer.deserialize(this->m_fy[_mem]);
        if (stat != Fw::FW_SERIALIZE_OK) {
            return stat;
        }
    }
    return stat;
}

#if FW_SERIALIZABLE_TO_STRING  || BUILD_UT

void SController::toString(Fw::StringBase& text) const {

    static const char * formatString =
       "("
       "Up = "
       "[%g]"
       "[%g]"
       "[%g] "
       "Ud = "
       "[%g]"
       "[%g]"
       "[%g] "
       "fy = "
       "[]"
       "[]"
       "[] "
       ")";

    // declare strings to hold any serializable toString() arguments


    char outputString[FW_SERIALIZABLE_TO_STRING_BUFFER_SIZE];
    (void)snprintf(outputString,FW_SERIALIZABLE_TO_STRING_BUFFER_SIZE,formatString
       ,this->m_Up[0]
       ,this->m_Up[1]
       ,this->m_Up[2]
       ,this->m_Ud[0]
       ,this->m_Ud[1]
       ,this->m_Ud[2]
       ,this->m_fy[0]
       ,this->m_fy[1]
       ,this->m_fy[2]
    );
    outputString[FW_SERIALIZABLE_TO_STRING_BUFFER_SIZE-1] = 0; // NULL terminate

    text = outputString;
}

#endif

#ifdef BUILD_UT
    std::ostream& operator<<(std::ostream& os, const SController& obj) {
        Fw::String str;
        obj.toString(str);
        os << str.toChar();
        return os;
    }
#endif
} // end namespace Ref
