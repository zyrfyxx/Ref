#include <Ref/RecvBuffApp/PacketStatSerializableAc.hpp>
#include <Fw/Types/Assert.hpp>
#include <Fw/Types/BasicTypes.hpp>
#include <Fw/Types/StringUtils.hpp>
#if FW_SERIALIZABLE_TO_STRING
#include <Fw/Types/String.hpp>
#endif
#include <cstring>
namespace Ref {
// public methods

PacketStat::PacketStat(): Serializable() {
    this->m_BuffRecv = 0;
    this->m_BuffErr = 0;
    this->m_PacketStatus = Ref::PacketRecvStatus::PACKET_STATE_NO_PACKETS;
}

PacketStat::PacketStat(const PacketStat& src) : Serializable() {
    this->set(src.m_BuffRecv, src.m_BuffErr, src.m_PacketStatus);
}

PacketStat::PacketStat(const PacketStat* src) : Serializable() {
    FW_ASSERT(src);
    this->set(src->m_BuffRecv, src->m_BuffErr, src->m_PacketStatus);
}

PacketStat::PacketStat(U32 BuffRecv, U32 BuffErr, const Ref::PacketRecvStatus& PacketStatus) : Serializable() {
    this->set(BuffRecv, BuffErr, PacketStatus);
}


PacketStat& PacketStat::operator=(const PacketStat& src) {
    if(this == &src) {
            return *this;
    }

    this->set(src.m_BuffRecv, src.m_BuffErr, src.m_PacketStatus);
    return *this;
}

bool PacketStat::operator==(const PacketStat& src) const {
    return (
        (src.m_BuffRecv == this->m_BuffRecv) &&
        (src.m_BuffErr == this->m_BuffErr) &&
        (src.m_PacketStatus == this->m_PacketStatus) &&
        true);
}

void PacketStat::set(U32 BuffRecv, U32 BuffErr, const Ref::PacketRecvStatus& PacketStatus) {
    this->m_BuffRecv = BuffRecv;
    this->m_BuffErr = BuffErr;
    this->m_PacketStatus = PacketStatus;
}

U32 PacketStat::getBuffRecv() const {
    return this->m_BuffRecv;
}

U32 PacketStat::getBuffErr() const {
    return this->m_BuffErr;
}

const Ref::PacketRecvStatus& PacketStat::getPacketStatus() const {
    return this->m_PacketStatus;
}


void PacketStat::setBuffRecv(U32 val) {
    this->m_BuffRecv = val;
}
void PacketStat::setBuffErr(U32 val) {
    this->m_BuffErr = val;
}
void PacketStat::setPacketStatus(const Ref::PacketRecvStatus& val) {
    this->m_PacketStatus = val;
}
Fw::SerializeStatus PacketStat::serialize(Fw::SerializeBufferBase& buffer) const {
    Fw::SerializeStatus stat;

#if FW_SERIALIZATION_TYPE_ID
    // serialize type ID
    stat = buffer.serialize(static_cast<U32>(PacketStat::TYPE_ID));
#endif

    stat = buffer.serialize(this->m_BuffRecv);
    if (stat != Fw::FW_SERIALIZE_OK) {
        return stat;
    }
    stat = buffer.serialize(this->m_BuffErr);
    if (stat != Fw::FW_SERIALIZE_OK) {
        return stat;
    }
    stat = buffer.serialize(this->m_PacketStatus);
    if (stat != Fw::FW_SERIALIZE_OK) {
        return stat;
    }
    return stat;
}

Fw::SerializeStatus PacketStat::deserialize(Fw::SerializeBufferBase& buffer) {
    Fw::SerializeStatus stat;

#if FW_SERIALIZATION_TYPE_ID
    U32 typeId;

    stat = buffer.deserialize(typeId);
    if (stat != Fw::FW_SERIALIZE_OK) {
        return stat;
    }

    if (typeId != PacketStat::TYPE_ID) {
        return Fw::FW_DESERIALIZE_TYPE_MISMATCH;
    }
#endif

    stat = buffer.deserialize(this->m_BuffRecv);
    if (stat != Fw::FW_SERIALIZE_OK) {
        return stat;
    }
    stat = buffer.deserialize(this->m_BuffErr);
    if (stat != Fw::FW_SERIALIZE_OK) {
        return stat;
    }
    stat = buffer.deserialize(this->m_PacketStatus);
    if (stat != Fw::FW_SERIALIZE_OK) {
        return stat;
    }
    return stat;
}

#if FW_SERIALIZABLE_TO_STRING  || BUILD_UT

void PacketStat::toString(Fw::StringBase& text) const {

    static const char * formatString =
       "("
       "BuffRecv = %u, "
       "BuffErr = %u, "
       "PacketStatus = "
       ")";

    // declare strings to hold any serializable toString() arguments


    Fw::String PacketStatusStr;
    this->m_PacketStatus.toString(PacketStatusStr);

    char outputString[FW_SERIALIZABLE_TO_STRING_BUFFER_SIZE];
    (void)snprintf(outputString,FW_SERIALIZABLE_TO_STRING_BUFFER_SIZE,formatString
       ,this->m_BuffRecv
       ,this->m_BuffErr
       ,PacketStatusStr.toChar()
    );
    outputString[FW_SERIALIZABLE_TO_STRING_BUFFER_SIZE-1] = 0; // NULL terminate

    text = outputString;
}

#endif

#ifdef BUILD_UT
    std::ostream& operator<<(std::ostream& os, const PacketStat& obj) {
        Fw::String str;
        obj.toString(str);
        os << str.toChar();
        return os;
    }
#endif
} // end namespace Ref
