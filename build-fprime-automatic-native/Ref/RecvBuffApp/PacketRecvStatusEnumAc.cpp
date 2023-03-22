// ======================================================================
// \title  PacketRecvStatus
// \author Auto-generated
// \brief  cpp file for PacketRecvStatus
//
// NOTE: this file was automatically generated
//
// ======================================================================

#include <cstring>
#include <limits>
#include "Fw/Types/Assert.hpp"
#include "PacketRecvStatusEnumAc.hpp"

namespace Ref {

  // ----------------------------------------------------------------------
  // Constructors
  // ----------------------------------------------------------------------

  PacketRecvStatus :: PacketRecvStatus():Serializable()
  {
    this->e = static_cast<t>(PACKET_STATE_NO_PACKETS);
  }

  PacketRecvStatus :: PacketRecvStatus(const t e):Serializable()
  {
    this->e = e;
  }

  PacketRecvStatus :: PacketRecvStatus(const PacketRecvStatus& other):Serializable()
  {
    this->e = other.e;
  }

  // ----------------------------------------------------------------------
  // Instance methods
  // ----------------------------------------------------------------------

  PacketRecvStatus& PacketRecvStatus :: operator=(const PacketRecvStatus& other)
  {
    this->e = other.e;
    return *this;
  }

  PacketRecvStatus& PacketRecvStatus :: operator=(const t a)
  {
    this->e = a;
    return *this;
  }

  PacketRecvStatus& PacketRecvStatus :: operator=(const NATIVE_INT_TYPE a)
  {
    FW_ASSERT(a == 0 || a == 1 || a == 3, static_cast<t>(a));
    this->e = static_cast<t>(a);
    return *this;
  }

  PacketRecvStatus& PacketRecvStatus :: operator=(const NATIVE_UINT_TYPE a)
  {
    FW_ASSERT(a == 0 || a == 1 || a == 3, static_cast<t>(a));
    this->e = static_cast<t>(a);
    return *this;
  }

  bool PacketRecvStatus :: operator==(const PacketRecvStatus& other) const
  {
    return this->e == other.e;
  }

  bool PacketRecvStatus :: operator!=(const PacketRecvStatus& other) const
  {
    return !(*this == other);
  }

#ifdef BUILD_UT
  std::ostream& operator<<(std::ostream& os, const PacketRecvStatus& obj) {
    os << "PacketRecvStatus::";
    const PacketRecvStatus::t e = obj.e;
    switch (e) {
        case PacketRecvStatus::PACKET_STATE_NO_PACKETS:
          os << "PACKET_STATE_NO_PACKETS";
          break;
        case PacketRecvStatus::PACKET_STATE_OK:
          os << "PACKET_STATE_OK";
          break;
        case PacketRecvStatus::PACKET_STATE_ERRORS:
          os << "PACKET_STATE_ERRORS";
          break;
        default:
          os << "[invalid]";
          break;
    }
    os << " (" << e << ")";
    return os;
  }
#endif

  Fw::SerializeStatus PacketRecvStatus :: serialize(Fw::SerializeBufferBase& buffer) const
  {
    Fw::SerializeStatus status;
    status = buffer.serialize(static_cast<I32>(this->e));
    return status;
  }

  Fw::SerializeStatus PacketRecvStatus :: deserialize(Fw::SerializeBufferBase& buffer)
  {
    Fw::SerializeStatus status;
    I32 es;
    status = buffer.deserialize(es);
    if (status == Fw::FW_SERIALIZE_OK)
      this->e = static_cast<t>(es);
    return status;
  }

  #if FW_SERIALIZABLE_TO_STRING || BUILD_UT
    void PacketRecvStatus :: toString(Fw::StringBase& text) const {
    const PacketRecvStatus::t e = this->e;
    switch (e) {
        case PacketRecvStatus::PACKET_STATE_NO_PACKETS:
          text = "PACKET_STATE_NO_PACKETS";
          break;
        case PacketRecvStatus::PACKET_STATE_OK:
          text = "PACKET_STATE_OK";
          break;
        case PacketRecvStatus::PACKET_STATE_ERRORS:
          text = "PACKET_STATE_ERRORS";
          break;
        default:
          text = "[invalid]";
          break;
    }
  }
  #endif

}
