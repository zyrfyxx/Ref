#include <Ref/GetEnvData/SGyroDataSerializableAc.hpp>
#include <Fw/Types/Assert.hpp>
#include <Fw/Types/BasicTypes.hpp>
#include <Fw/Types/StringUtils.hpp>
#if FW_SERIALIZABLE_TO_STRING
#include <Fw/Types/String.hpp>
#endif
#include <cstring>
namespace Ref {
// public methods

SGyroData::SGyroData(): Serializable() {
    for (NATIVE_INT_TYPE _mem = 0; _mem < 9; _mem++) {
        this->m_countPick[_mem] = 0;
    }
    for (NATIVE_INT_TYPE _mem = 0; _mem < 3; _mem++) {
        this->m_Gi[_mem] = 0.0f;
    }
    for (NATIVE_INT_TYPE _mem = 0; _mem < 9; _mem++) {
        this->m_wa[_mem] = 0.0f;
    }
    for (NATIVE_INT_TYPE _mem = 0; _mem < 9; _mem++) {
        this->m_wal[_mem] = 0.0f;
    }
    this->m_JoinTotal = 0;
    this->m_gyroStatus0 = 0;
    this->m_gyroStatus1 = 0;
    for (NATIVE_INT_TYPE _mem = 0; _mem < 3; _mem++) {
        this->m_W[_mem] = 0.0f;
    }
    for (NATIVE_INT_TYPE _mem = 0; _mem < 9; _mem++) {
        this->m_SignFlag[_mem] = 0;
    }
    for (NATIVE_INT_TYPE _mem = 0; _mem < 9; _mem++) {
        this->m_stateFlag[_mem] = 0;
    }
    for (NATIVE_INT_TYPE _mem = 0; _mem < 5; _mem++) {
        this->m_Rtemp0[_mem] = 0.0f;
    }
    for (NATIVE_INT_TYPE _mem = 0; _mem < 5; _mem++) {
        this->m_Rtemp1[_mem] = 0.0f;
    }
    for (NATIVE_INT_TYPE _mem = 0; _mem < 5; _mem++) {
        this->m_Rtemp2[_mem] = 0.0f;
    }
}

SGyroData::SGyroData(const SGyroData& src) : Serializable() {
    this->set(src.m_countPick, 9, src.m_Gi, 3, src.m_wa, 9, src.m_wal, 9, src.m_JoinTotal, src.m_gyroStatus0, src.m_gyroStatus1, src.m_W, 3, src.m_SignFlag, 9, src.m_stateFlag, 9, src.m_Rtemp0, 5, src.m_Rtemp1, 5, src.m_Rtemp2, 5);
}

SGyroData::SGyroData(const SGyroData* src) : Serializable() {
    FW_ASSERT(src);
    this->set(src->m_countPick, 9, src->m_Gi, 3, src->m_wa, 9, src->m_wal, 9, src->m_JoinTotal, src->m_gyroStatus0, src->m_gyroStatus1, src->m_W, 3, src->m_SignFlag, 9, src->m_stateFlag, 9, src->m_Rtemp0, 5, src->m_Rtemp1, 5, src->m_Rtemp2, 5);
}

SGyroData::SGyroData(const U8* countPick, NATIVE_INT_TYPE countPickSize, const F32* Gi, NATIVE_INT_TYPE GiSize, const F32* wa, NATIVE_INT_TYPE waSize, const F32* wal, NATIVE_INT_TYPE walSize, U8 JoinTotal, U16 gyroStatus0, U16 gyroStatus1, const F32* W, NATIVE_INT_TYPE WSize, const U8* SignFlag, NATIVE_INT_TYPE SignFlagSize, const U32* stateFlag, NATIVE_INT_TYPE stateFlagSize, const F32* Rtemp0, NATIVE_INT_TYPE Rtemp0Size, const F32* Rtemp1, NATIVE_INT_TYPE Rtemp1Size, const F32* Rtemp2, NATIVE_INT_TYPE Rtemp2Size) : Serializable() {
    this->set(countPick, 9, Gi, 3, wa, 9, wal, 9, JoinTotal, gyroStatus0, gyroStatus1, W, 3, SignFlag, 9, stateFlag, 9, Rtemp0, 5, Rtemp1, 5, Rtemp2, 5);
}

SGyroData::SGyroData(const U8 countPick, const F32 Gi, const F32 wa, const F32 wal, U8 JoinTotal, U16 gyroStatus0, U16 gyroStatus1, const F32 W, const U8 SignFlag, const U32 stateFlag, const F32 Rtemp0, const F32 Rtemp1, const F32 Rtemp2) : Serializable() {
    for (NATIVE_INT_TYPE _mem = 0; _mem < 9; _mem++) {
        this->m_countPick[_mem] = countPick;
    }
    for (NATIVE_INT_TYPE _mem = 0; _mem < 3; _mem++) {
        this->m_Gi[_mem] = Gi;
    }
    for (NATIVE_INT_TYPE _mem = 0; _mem < 9; _mem++) {
        this->m_wa[_mem] = wa;
    }
    for (NATIVE_INT_TYPE _mem = 0; _mem < 9; _mem++) {
        this->m_wal[_mem] = wal;
    }
    this->m_JoinTotal = JoinTotal;
    this->m_gyroStatus0 = gyroStatus0;
    this->m_gyroStatus1 = gyroStatus1;
    for (NATIVE_INT_TYPE _mem = 0; _mem < 3; _mem++) {
        this->m_W[_mem] = W;
    }
    for (NATIVE_INT_TYPE _mem = 0; _mem < 9; _mem++) {
        this->m_SignFlag[_mem] = SignFlag;
    }
    for (NATIVE_INT_TYPE _mem = 0; _mem < 9; _mem++) {
        this->m_stateFlag[_mem] = stateFlag;
    }
    for (NATIVE_INT_TYPE _mem = 0; _mem < 5; _mem++) {
        this->m_Rtemp0[_mem] = Rtemp0;
    }
    for (NATIVE_INT_TYPE _mem = 0; _mem < 5; _mem++) {
        this->m_Rtemp1[_mem] = Rtemp1;
    }
    for (NATIVE_INT_TYPE _mem = 0; _mem < 5; _mem++) {
        this->m_Rtemp2[_mem] = Rtemp2;
    }
}


SGyroData& SGyroData::operator=(const SGyroData& src) {
    if(this == &src) {
            return *this;
    }

    this->set(src.m_countPick, 9, src.m_Gi, 3, src.m_wa, 9, src.m_wal, 9, src.m_JoinTotal, src.m_gyroStatus0, src.m_gyroStatus1, src.m_W, 3, src.m_SignFlag, 9, src.m_stateFlag, 9, src.m_Rtemp0, 5, src.m_Rtemp1, 5, src.m_Rtemp2, 5);
    return *this;
}

bool SGyroData::operator==(const SGyroData& src) const {
    return (
        (src.m_countPick == this->m_countPick) &&
        (src.m_Gi == this->m_Gi) &&
        (src.m_wa == this->m_wa) &&
        (src.m_wal == this->m_wal) &&
        (src.m_JoinTotal == this->m_JoinTotal) &&
        (src.m_gyroStatus0 == this->m_gyroStatus0) &&
        (src.m_gyroStatus1 == this->m_gyroStatus1) &&
        (src.m_W == this->m_W) &&
        (src.m_SignFlag == this->m_SignFlag) &&
        (src.m_stateFlag == this->m_stateFlag) &&
        (src.m_Rtemp0 == this->m_Rtemp0) &&
        (src.m_Rtemp1 == this->m_Rtemp1) &&
        (src.m_Rtemp2 == this->m_Rtemp2) &&
        true);
}

void SGyroData::set(const U8* countPick, NATIVE_INT_TYPE countPickSize, const F32* Gi, NATIVE_INT_TYPE GiSize, const F32* wa, NATIVE_INT_TYPE waSize, const F32* wal, NATIVE_INT_TYPE walSize, U8 JoinTotal, U16 gyroStatus0, U16 gyroStatus1, const F32* W, NATIVE_INT_TYPE WSize, const U8* SignFlag, NATIVE_INT_TYPE SignFlagSize, const U32* stateFlag, NATIVE_INT_TYPE stateFlagSize, const F32* Rtemp0, NATIVE_INT_TYPE Rtemp0Size, const F32* Rtemp1, NATIVE_INT_TYPE Rtemp1Size, const F32* Rtemp2, NATIVE_INT_TYPE Rtemp2Size) {
    for (NATIVE_INT_TYPE _mem = 0; _mem < FW_MIN(countPickSize,9); _mem++) {
        this->m_countPick[_mem] = countPick[_mem];
    }
    for (NATIVE_INT_TYPE _mem = 0; _mem < FW_MIN(GiSize,3); _mem++) {
        this->m_Gi[_mem] = Gi[_mem];
    }
    for (NATIVE_INT_TYPE _mem = 0; _mem < FW_MIN(waSize,9); _mem++) {
        this->m_wa[_mem] = wa[_mem];
    }
    for (NATIVE_INT_TYPE _mem = 0; _mem < FW_MIN(walSize,9); _mem++) {
        this->m_wal[_mem] = wal[_mem];
    }
    this->m_JoinTotal = JoinTotal;
    this->m_gyroStatus0 = gyroStatus0;
    this->m_gyroStatus1 = gyroStatus1;
    for (NATIVE_INT_TYPE _mem = 0; _mem < FW_MIN(WSize,3); _mem++) {
        this->m_W[_mem] = W[_mem];
    }
    for (NATIVE_INT_TYPE _mem = 0; _mem < FW_MIN(SignFlagSize,9); _mem++) {
        this->m_SignFlag[_mem] = SignFlag[_mem];
    }
    for (NATIVE_INT_TYPE _mem = 0; _mem < FW_MIN(stateFlagSize,9); _mem++) {
        this->m_stateFlag[_mem] = stateFlag[_mem];
    }
    for (NATIVE_INT_TYPE _mem = 0; _mem < FW_MIN(Rtemp0Size,5); _mem++) {
        this->m_Rtemp0[_mem] = Rtemp0[_mem];
    }
    for (NATIVE_INT_TYPE _mem = 0; _mem < FW_MIN(Rtemp1Size,5); _mem++) {
        this->m_Rtemp1[_mem] = Rtemp1[_mem];
    }
    for (NATIVE_INT_TYPE _mem = 0; _mem < FW_MIN(Rtemp2Size,5); _mem++) {
        this->m_Rtemp2[_mem] = Rtemp2[_mem];
    }
}

const U8* SGyroData::getcountPick(NATIVE_INT_TYPE& size) const {
    size = 9;
    return this->m_countPick;
}

const F32* SGyroData::getGi(NATIVE_INT_TYPE& size) const {
    size = 3;
    return this->m_Gi;
}

const F32* SGyroData::getwa(NATIVE_INT_TYPE& size) const {
    size = 9;
    return this->m_wa;
}

const F32* SGyroData::getwal(NATIVE_INT_TYPE& size) const {
    size = 9;
    return this->m_wal;
}

U8 SGyroData::getJoinTotal() const {
    return this->m_JoinTotal;
}

U16 SGyroData::getgyroStatus0() const {
    return this->m_gyroStatus0;
}

U16 SGyroData::getgyroStatus1() const {
    return this->m_gyroStatus1;
}

const F32* SGyroData::getW(NATIVE_INT_TYPE& size) const {
    size = 3;
    return this->m_W;
}

const U8* SGyroData::getSignFlag(NATIVE_INT_TYPE& size) const {
    size = 9;
    return this->m_SignFlag;
}

const U32* SGyroData::getstateFlag(NATIVE_INT_TYPE& size) const {
    size = 9;
    return this->m_stateFlag;
}

const F32* SGyroData::getRtemp0(NATIVE_INT_TYPE& size) const {
    size = 5;
    return this->m_Rtemp0;
}

const F32* SGyroData::getRtemp1(NATIVE_INT_TYPE& size) const {
    size = 5;
    return this->m_Rtemp1;
}

const F32* SGyroData::getRtemp2(NATIVE_INT_TYPE& size) const {
    size = 5;
    return this->m_Rtemp2;
}


void SGyroData::setcountPick(const U8* val, NATIVE_INT_TYPE size) {
    for (NATIVE_INT_TYPE _mem = 0; _mem < FW_MIN(size,9); _mem++) {
        this->m_countPick[_mem] = val[_mem];
    }
}
void SGyroData::setGi(const F32* val, NATIVE_INT_TYPE size) {
    for (NATIVE_INT_TYPE _mem = 0; _mem < FW_MIN(size,3); _mem++) {
        this->m_Gi[_mem] = val[_mem];
    }
}
void SGyroData::setwa(const F32* val, NATIVE_INT_TYPE size) {
    for (NATIVE_INT_TYPE _mem = 0; _mem < FW_MIN(size,9); _mem++) {
        this->m_wa[_mem] = val[_mem];
    }
}
void SGyroData::setwal(const F32* val, NATIVE_INT_TYPE size) {
    for (NATIVE_INT_TYPE _mem = 0; _mem < FW_MIN(size,9); _mem++) {
        this->m_wal[_mem] = val[_mem];
    }
}
void SGyroData::setJoinTotal(U8 val) {
    this->m_JoinTotal = val;
}
void SGyroData::setgyroStatus0(U16 val) {
    this->m_gyroStatus0 = val;
}
void SGyroData::setgyroStatus1(U16 val) {
    this->m_gyroStatus1 = val;
}
void SGyroData::setW(const F32* val, NATIVE_INT_TYPE size) {
    for (NATIVE_INT_TYPE _mem = 0; _mem < FW_MIN(size,3); _mem++) {
        this->m_W[_mem] = val[_mem];
    }
}
void SGyroData::setSignFlag(const U8* val, NATIVE_INT_TYPE size) {
    for (NATIVE_INT_TYPE _mem = 0; _mem < FW_MIN(size,9); _mem++) {
        this->m_SignFlag[_mem] = val[_mem];
    }
}
void SGyroData::setstateFlag(const U32* val, NATIVE_INT_TYPE size) {
    for (NATIVE_INT_TYPE _mem = 0; _mem < FW_MIN(size,9); _mem++) {
        this->m_stateFlag[_mem] = val[_mem];
    }
}
void SGyroData::setRtemp0(const F32* val, NATIVE_INT_TYPE size) {
    for (NATIVE_INT_TYPE _mem = 0; _mem < FW_MIN(size,5); _mem++) {
        this->m_Rtemp0[_mem] = val[_mem];
    }
}
void SGyroData::setRtemp1(const F32* val, NATIVE_INT_TYPE size) {
    for (NATIVE_INT_TYPE _mem = 0; _mem < FW_MIN(size,5); _mem++) {
        this->m_Rtemp1[_mem] = val[_mem];
    }
}
void SGyroData::setRtemp2(const F32* val, NATIVE_INT_TYPE size) {
    for (NATIVE_INT_TYPE _mem = 0; _mem < FW_MIN(size,5); _mem++) {
        this->m_Rtemp2[_mem] = val[_mem];
    }
}
Fw::SerializeStatus SGyroData::serialize(Fw::SerializeBufferBase& buffer) const {
    Fw::SerializeStatus stat;

#if FW_SERIALIZATION_TYPE_ID
    // serialize type ID
    stat = buffer.serialize(static_cast<U32>(SGyroData::TYPE_ID));
#endif

    for (NATIVE_INT_TYPE _mem = 0; _mem < 9; _mem++) {
        stat = buffer.serialize(this->m_countPick[_mem]);
        if (stat != Fw::FW_SERIALIZE_OK) {
            return stat;
        }
    }
    for (NATIVE_INT_TYPE _mem = 0; _mem < 3; _mem++) {
        stat = buffer.serialize(this->m_Gi[_mem]);
        if (stat != Fw::FW_SERIALIZE_OK) {
            return stat;
        }
    }
    for (NATIVE_INT_TYPE _mem = 0; _mem < 9; _mem++) {
        stat = buffer.serialize(this->m_wa[_mem]);
        if (stat != Fw::FW_SERIALIZE_OK) {
            return stat;
        }
    }
    for (NATIVE_INT_TYPE _mem = 0; _mem < 9; _mem++) {
        stat = buffer.serialize(this->m_wal[_mem]);
        if (stat != Fw::FW_SERIALIZE_OK) {
            return stat;
        }
    }
    stat = buffer.serialize(this->m_JoinTotal);
    if (stat != Fw::FW_SERIALIZE_OK) {
        return stat;
    }
    stat = buffer.serialize(this->m_gyroStatus0);
    if (stat != Fw::FW_SERIALIZE_OK) {
        return stat;
    }
    stat = buffer.serialize(this->m_gyroStatus1);
    if (stat != Fw::FW_SERIALIZE_OK) {
        return stat;
    }
    for (NATIVE_INT_TYPE _mem = 0; _mem < 3; _mem++) {
        stat = buffer.serialize(this->m_W[_mem]);
        if (stat != Fw::FW_SERIALIZE_OK) {
            return stat;
        }
    }
    for (NATIVE_INT_TYPE _mem = 0; _mem < 9; _mem++) {
        stat = buffer.serialize(this->m_SignFlag[_mem]);
        if (stat != Fw::FW_SERIALIZE_OK) {
            return stat;
        }
    }
    for (NATIVE_INT_TYPE _mem = 0; _mem < 9; _mem++) {
        stat = buffer.serialize(this->m_stateFlag[_mem]);
        if (stat != Fw::FW_SERIALIZE_OK) {
            return stat;
        }
    }
    for (NATIVE_INT_TYPE _mem = 0; _mem < 5; _mem++) {
        stat = buffer.serialize(this->m_Rtemp0[_mem]);
        if (stat != Fw::FW_SERIALIZE_OK) {
            return stat;
        }
    }
    for (NATIVE_INT_TYPE _mem = 0; _mem < 5; _mem++) {
        stat = buffer.serialize(this->m_Rtemp1[_mem]);
        if (stat != Fw::FW_SERIALIZE_OK) {
            return stat;
        }
    }
    for (NATIVE_INT_TYPE _mem = 0; _mem < 5; _mem++) {
        stat = buffer.serialize(this->m_Rtemp2[_mem]);
        if (stat != Fw::FW_SERIALIZE_OK) {
            return stat;
        }
    }
    return stat;
}

Fw::SerializeStatus SGyroData::deserialize(Fw::SerializeBufferBase& buffer) {
    Fw::SerializeStatus stat;

#if FW_SERIALIZATION_TYPE_ID
    U32 typeId;

    stat = buffer.deserialize(typeId);
    if (stat != Fw::FW_SERIALIZE_OK) {
        return stat;
    }

    if (typeId != SGyroData::TYPE_ID) {
        return Fw::FW_DESERIALIZE_TYPE_MISMATCH;
    }
#endif

    for (NATIVE_INT_TYPE _mem = 0; _mem < 9; _mem++) {
        stat = buffer.deserialize(this->m_countPick[_mem]);
        if (stat != Fw::FW_SERIALIZE_OK) {
            return stat;
        }
    }
    for (NATIVE_INT_TYPE _mem = 0; _mem < 3; _mem++) {
        stat = buffer.deserialize(this->m_Gi[_mem]);
        if (stat != Fw::FW_SERIALIZE_OK) {
            return stat;
        }
    }
    for (NATIVE_INT_TYPE _mem = 0; _mem < 9; _mem++) {
        stat = buffer.deserialize(this->m_wa[_mem]);
        if (stat != Fw::FW_SERIALIZE_OK) {
            return stat;
        }
    }
    for (NATIVE_INT_TYPE _mem = 0; _mem < 9; _mem++) {
        stat = buffer.deserialize(this->m_wal[_mem]);
        if (stat != Fw::FW_SERIALIZE_OK) {
            return stat;
        }
    }
    stat = buffer.deserialize(this->m_JoinTotal);
    if (stat != Fw::FW_SERIALIZE_OK) {
        return stat;
    }
    stat = buffer.deserialize(this->m_gyroStatus0);
    if (stat != Fw::FW_SERIALIZE_OK) {
        return stat;
    }
    stat = buffer.deserialize(this->m_gyroStatus1);
    if (stat != Fw::FW_SERIALIZE_OK) {
        return stat;
    }
    for (NATIVE_INT_TYPE _mem = 0; _mem < 3; _mem++) {
        stat = buffer.deserialize(this->m_W[_mem]);
        if (stat != Fw::FW_SERIALIZE_OK) {
            return stat;
        }
    }
    for (NATIVE_INT_TYPE _mem = 0; _mem < 9; _mem++) {
        stat = buffer.deserialize(this->m_SignFlag[_mem]);
        if (stat != Fw::FW_SERIALIZE_OK) {
            return stat;
        }
    }
    for (NATIVE_INT_TYPE _mem = 0; _mem < 9; _mem++) {
        stat = buffer.deserialize(this->m_stateFlag[_mem]);
        if (stat != Fw::FW_SERIALIZE_OK) {
            return stat;
        }
    }
    for (NATIVE_INT_TYPE _mem = 0; _mem < 5; _mem++) {
        stat = buffer.deserialize(this->m_Rtemp0[_mem]);
        if (stat != Fw::FW_SERIALIZE_OK) {
            return stat;
        }
    }
    for (NATIVE_INT_TYPE _mem = 0; _mem < 5; _mem++) {
        stat = buffer.deserialize(this->m_Rtemp1[_mem]);
        if (stat != Fw::FW_SERIALIZE_OK) {
            return stat;
        }
    }
    for (NATIVE_INT_TYPE _mem = 0; _mem < 5; _mem++) {
        stat = buffer.deserialize(this->m_Rtemp2[_mem]);
        if (stat != Fw::FW_SERIALIZE_OK) {
            return stat;
        }
    }
    return stat;
}

#if FW_SERIALIZABLE_TO_STRING  || BUILD_UT

void SGyroData::toString(Fw::StringBase& text) const {

    static const char * formatString =
       "("
       "countPick = "
       "[%u]"
       "[%u]"
       "[%u]"
       "[%u]"
       "[%u]"
       "[%u]"
       "[%u]"
       "[%u]"
       "[%u] "
       "Gi = "
       "[%g]"
       "[%g]"
       "[%g] "
       "wa = "
       "[%g]"
       "[%g]"
       "[%g]"
       "[%g]"
       "[%g]"
       "[%g]"
       "[%g]"
       "[%g]"
       "[%g] "
       "wal = "
       "[%g]"
       "[%g]"
       "[%g]"
       "[%g]"
       "[%g]"
       "[%g]"
       "[%g]"
       "[%g]"
       "[%g] "
       "JoinTotal = %u, "
       "gyroStatus0 = %u, "
       "gyroStatus1 = %u, "
       "W = "
       "[%g]"
       "[%g]"
       "[%g] "
       "SignFlag = "
       "[%u]"
       "[%u]"
       "[%u]"
       "[%u]"
       "[%u]"
       "[%u]"
       "[%u]"
       "[%u]"
       "[%u] "
       "stateFlag = "
       "[%u]"
       "[%u]"
       "[%u]"
       "[%u]"
       "[%u]"
       "[%u]"
       "[%u]"
       "[%u]"
       "[%u] "
       "Rtemp0 = "
       "[%g]"
       "[%g]"
       "[%g]"
       "[%g]"
       "[%g] "
       "Rtemp1 = "
       "[%g]"
       "[%g]"
       "[%g]"
       "[%g]"
       "[%g] "
       "Rtemp2 = "
       "[]"
       "[]"
       "[]"
       "[]"
       "[] "
       ")";

    // declare strings to hold any serializable toString() arguments


    char outputString[FW_SERIALIZABLE_TO_STRING_BUFFER_SIZE];
    (void)snprintf(outputString,FW_SERIALIZABLE_TO_STRING_BUFFER_SIZE,formatString
       ,this->m_countPick[0]
       ,this->m_countPick[1]
       ,this->m_countPick[2]
       ,this->m_countPick[3]
       ,this->m_countPick[4]
       ,this->m_countPick[5]
       ,this->m_countPick[6]
       ,this->m_countPick[7]
       ,this->m_countPick[8]
       ,this->m_Gi[0]
       ,this->m_Gi[1]
       ,this->m_Gi[2]
       ,this->m_wa[0]
       ,this->m_wa[1]
       ,this->m_wa[2]
       ,this->m_wa[3]
       ,this->m_wa[4]
       ,this->m_wa[5]
       ,this->m_wa[6]
       ,this->m_wa[7]
       ,this->m_wa[8]
       ,this->m_wal[0]
       ,this->m_wal[1]
       ,this->m_wal[2]
       ,this->m_wal[3]
       ,this->m_wal[4]
       ,this->m_wal[5]
       ,this->m_wal[6]
       ,this->m_wal[7]
       ,this->m_wal[8]
       ,this->m_JoinTotal
       ,this->m_gyroStatus0
       ,this->m_gyroStatus1
       ,this->m_W[0]
       ,this->m_W[1]
       ,this->m_W[2]
       ,this->m_SignFlag[0]
       ,this->m_SignFlag[1]
       ,this->m_SignFlag[2]
       ,this->m_SignFlag[3]
       ,this->m_SignFlag[4]
       ,this->m_SignFlag[5]
       ,this->m_SignFlag[6]
       ,this->m_SignFlag[7]
       ,this->m_SignFlag[8]
       ,this->m_stateFlag[0]
       ,this->m_stateFlag[1]
       ,this->m_stateFlag[2]
       ,this->m_stateFlag[3]
       ,this->m_stateFlag[4]
       ,this->m_stateFlag[5]
       ,this->m_stateFlag[6]
       ,this->m_stateFlag[7]
       ,this->m_stateFlag[8]
       ,this->m_Rtemp0[0]
       ,this->m_Rtemp0[1]
       ,this->m_Rtemp0[2]
       ,this->m_Rtemp0[3]
       ,this->m_Rtemp0[4]
       ,this->m_Rtemp1[0]
       ,this->m_Rtemp1[1]
       ,this->m_Rtemp1[2]
       ,this->m_Rtemp1[3]
       ,this->m_Rtemp1[4]
       ,this->m_Rtemp2[0]
       ,this->m_Rtemp2[1]
       ,this->m_Rtemp2[2]
       ,this->m_Rtemp2[3]
       ,this->m_Rtemp2[4]
    );
    outputString[FW_SERIALIZABLE_TO_STRING_BUFFER_SIZE-1] = 0; // NULL terminate

    text = outputString;
}

#endif

#ifdef BUILD_UT
    std::ostream& operator<<(std::ostream& os, const SGyroData& obj) {
        Fw::String str;
        obj.toString(str);
        os << str.toChar();
        return os;
    }
#endif
} // end namespace Ref
