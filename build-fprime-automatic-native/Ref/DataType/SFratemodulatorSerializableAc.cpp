#include <Ref/DataType/SFratemodulatorSerializableAc.hpp>
#include <Fw/Types/Assert.hpp>
#include <Fw/Types/BasicTypes.hpp>
#include <Fw/Types/StringUtils.hpp>
#if FW_SERIALIZABLE_TO_STRING
#include <Fw/Types/String.hpp>
#endif
#include <cstring>
namespace Ref {
// public methods

SFratemodulator::SFratemodulator(): Serializable() {
    for (NATIVE_INT_TYPE _mem = 0; _mem < 3; _mem++) {
        this->m_u[_mem] = 0.0f;
    }
    for (NATIVE_INT_TYPE _mem = 0; _mem < 3; _mem++) {
        this->m_r[_mem] = 0.0f;
    }
    for (NATIVE_INT_TYPE _mem = 0; _mem < 3; _mem++) {
        this->m_Yp[_mem] = 0;
    }
    for (NATIVE_INT_TYPE _mem = 0; _mem < 3; _mem++) {
        this->m_Yn[_mem] = 0;
    }
}

SFratemodulator::SFratemodulator(const SFratemodulator& src) : Serializable() {
    this->set(src.m_u, 3, src.m_r, 3, src.m_Yp, 3, src.m_Yn, 3);
}

SFratemodulator::SFratemodulator(const SFratemodulator* src) : Serializable() {
    FW_ASSERT(src);
    this->set(src->m_u, 3, src->m_r, 3, src->m_Yp, 3, src->m_Yn, 3);
}

SFratemodulator::SFratemodulator(const F32* u, NATIVE_INT_TYPE uSize, const F32* r, NATIVE_INT_TYPE rSize, const U8* Yp, NATIVE_INT_TYPE YpSize, const U8* Yn, NATIVE_INT_TYPE YnSize) : Serializable() {
    this->set(u, 3, r, 3, Yp, 3, Yn, 3);
}

SFratemodulator::SFratemodulator(const F32 u, const F32 r, const U8 Yp, const U8 Yn) : Serializable() {
    for (NATIVE_INT_TYPE _mem = 0; _mem < 3; _mem++) {
        this->m_u[_mem] = u;
    }
    for (NATIVE_INT_TYPE _mem = 0; _mem < 3; _mem++) {
        this->m_r[_mem] = r;
    }
    for (NATIVE_INT_TYPE _mem = 0; _mem < 3; _mem++) {
        this->m_Yp[_mem] = Yp;
    }
    for (NATIVE_INT_TYPE _mem = 0; _mem < 3; _mem++) {
        this->m_Yn[_mem] = Yn;
    }
}


SFratemodulator& SFratemodulator::operator=(const SFratemodulator& src) {
    if(this == &src) {
            return *this;
    }

    this->set(src.m_u, 3, src.m_r, 3, src.m_Yp, 3, src.m_Yn, 3);
    return *this;
}

bool SFratemodulator::operator==(const SFratemodulator& src) const {
    return (
        (src.m_u == this->m_u) &&
        (src.m_r == this->m_r) &&
        (src.m_Yp == this->m_Yp) &&
        (src.m_Yn == this->m_Yn) &&
        true);
}

void SFratemodulator::set(const F32* u, NATIVE_INT_TYPE uSize, const F32* r, NATIVE_INT_TYPE rSize, const U8* Yp, NATIVE_INT_TYPE YpSize, const U8* Yn, NATIVE_INT_TYPE YnSize) {
    for (NATIVE_INT_TYPE _mem = 0; _mem < FW_MIN(uSize,3); _mem++) {
        this->m_u[_mem] = u[_mem];
    }
    for (NATIVE_INT_TYPE _mem = 0; _mem < FW_MIN(rSize,3); _mem++) {
        this->m_r[_mem] = r[_mem];
    }
    for (NATIVE_INT_TYPE _mem = 0; _mem < FW_MIN(YpSize,3); _mem++) {
        this->m_Yp[_mem] = Yp[_mem];
    }
    for (NATIVE_INT_TYPE _mem = 0; _mem < FW_MIN(YnSize,3); _mem++) {
        this->m_Yn[_mem] = Yn[_mem];
    }
}

const F32* SFratemodulator::getu(NATIVE_INT_TYPE& size) const {
    size = 3;
    return this->m_u;
}

const F32* SFratemodulator::getr(NATIVE_INT_TYPE& size) const {
    size = 3;
    return this->m_r;
}

const U8* SFratemodulator::getYp(NATIVE_INT_TYPE& size) const {
    size = 3;
    return this->m_Yp;
}

const U8* SFratemodulator::getYn(NATIVE_INT_TYPE& size) const {
    size = 3;
    return this->m_Yn;
}


void SFratemodulator::setu(const F32* val, NATIVE_INT_TYPE size) {
    for (NATIVE_INT_TYPE _mem = 0; _mem < FW_MIN(size,3); _mem++) {
        this->m_u[_mem] = val[_mem];
    }
}
void SFratemodulator::setr(const F32* val, NATIVE_INT_TYPE size) {
    for (NATIVE_INT_TYPE _mem = 0; _mem < FW_MIN(size,3); _mem++) {
        this->m_r[_mem] = val[_mem];
    }
}
void SFratemodulator::setYp(const U8* val, NATIVE_INT_TYPE size) {
    for (NATIVE_INT_TYPE _mem = 0; _mem < FW_MIN(size,3); _mem++) {
        this->m_Yp[_mem] = val[_mem];
    }
}
void SFratemodulator::setYn(const U8* val, NATIVE_INT_TYPE size) {
    for (NATIVE_INT_TYPE _mem = 0; _mem < FW_MIN(size,3); _mem++) {
        this->m_Yn[_mem] = val[_mem];
    }
}
Fw::SerializeStatus SFratemodulator::serialize(Fw::SerializeBufferBase& buffer) const {
    Fw::SerializeStatus stat;

#if FW_SERIALIZATION_TYPE_ID
    // serialize type ID
    stat = buffer.serialize(static_cast<U32>(SFratemodulator::TYPE_ID));
#endif

    for (NATIVE_INT_TYPE _mem = 0; _mem < 3; _mem++) {
        stat = buffer.serialize(this->m_u[_mem]);
        if (stat != Fw::FW_SERIALIZE_OK) {
            return stat;
        }
    }
    for (NATIVE_INT_TYPE _mem = 0; _mem < 3; _mem++) {
        stat = buffer.serialize(this->m_r[_mem]);
        if (stat != Fw::FW_SERIALIZE_OK) {
            return stat;
        }
    }
    for (NATIVE_INT_TYPE _mem = 0; _mem < 3; _mem++) {
        stat = buffer.serialize(this->m_Yp[_mem]);
        if (stat != Fw::FW_SERIALIZE_OK) {
            return stat;
        }
    }
    for (NATIVE_INT_TYPE _mem = 0; _mem < 3; _mem++) {
        stat = buffer.serialize(this->m_Yn[_mem]);
        if (stat != Fw::FW_SERIALIZE_OK) {
            return stat;
        }
    }
    return stat;
}

Fw::SerializeStatus SFratemodulator::deserialize(Fw::SerializeBufferBase& buffer) {
    Fw::SerializeStatus stat;

#if FW_SERIALIZATION_TYPE_ID
    U32 typeId;

    stat = buffer.deserialize(typeId);
    if (stat != Fw::FW_SERIALIZE_OK) {
        return stat;
    }

    if (typeId != SFratemodulator::TYPE_ID) {
        return Fw::FW_DESERIALIZE_TYPE_MISMATCH;
    }
#endif

    for (NATIVE_INT_TYPE _mem = 0; _mem < 3; _mem++) {
        stat = buffer.deserialize(this->m_u[_mem]);
        if (stat != Fw::FW_SERIALIZE_OK) {
            return stat;
        }
    }
    for (NATIVE_INT_TYPE _mem = 0; _mem < 3; _mem++) {
        stat = buffer.deserialize(this->m_r[_mem]);
        if (stat != Fw::FW_SERIALIZE_OK) {
            return stat;
        }
    }
    for (NATIVE_INT_TYPE _mem = 0; _mem < 3; _mem++) {
        stat = buffer.deserialize(this->m_Yp[_mem]);
        if (stat != Fw::FW_SERIALIZE_OK) {
            return stat;
        }
    }
    for (NATIVE_INT_TYPE _mem = 0; _mem < 3; _mem++) {
        stat = buffer.deserialize(this->m_Yn[_mem]);
        if (stat != Fw::FW_SERIALIZE_OK) {
            return stat;
        }
    }
    return stat;
}

#if FW_SERIALIZABLE_TO_STRING  || BUILD_UT

void SFratemodulator::toString(Fw::StringBase& text) const {

    static const char * formatString =
       "("
       "u = "
       "[%g]"
       "[%g]"
       "[%g] "
       "r = "
       "[%g]"
       "[%g]"
       "[%g] "
       "Yp = "
       "[%u]"
       "[%u]"
       "[%u] "
       "Yn = "
       "[]"
       "[]"
       "[] "
       ")";

    // declare strings to hold any serializable toString() arguments


    char outputString[FW_SERIALIZABLE_TO_STRING_BUFFER_SIZE];
    (void)snprintf(outputString,FW_SERIALIZABLE_TO_STRING_BUFFER_SIZE,formatString
       ,this->m_u[0]
       ,this->m_u[1]
       ,this->m_u[2]
       ,this->m_r[0]
       ,this->m_r[1]
       ,this->m_r[2]
       ,this->m_Yp[0]
       ,this->m_Yp[1]
       ,this->m_Yp[2]
       ,this->m_Yn[0]
       ,this->m_Yn[1]
       ,this->m_Yn[2]
    );
    outputString[FW_SERIALIZABLE_TO_STRING_BUFFER_SIZE-1] = 0; // NULL terminate

    text = outputString;
}

#endif

#ifdef BUILD_UT
    std::ostream& operator<<(std::ostream& os, const SFratemodulator& obj) {
        Fw::String str;
        obj.toString(str);
        os << str.toChar();
        return os;
    }
#endif
} // end namespace Ref
