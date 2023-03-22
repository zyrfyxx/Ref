// ======================================================================
// \title  SendBuff_ActiveState
// \author Auto-generated
// \brief  cpp file for SendBuff_ActiveState
//
// NOTE: this file was automatically generated
//
// ======================================================================

#include <cstring>
#include <limits>
#include "Fw/Types/Assert.hpp"
#include "SendBuff_ActiveStateEnumAc.hpp"

namespace Ref {

  // ----------------------------------------------------------------------
  // Constructors
  // ----------------------------------------------------------------------

  SendBuff_ActiveState :: SendBuff_ActiveState():Serializable()
  {
    this->e = static_cast<t>(SEND_IDLE);
  }

  SendBuff_ActiveState :: SendBuff_ActiveState(const t e):Serializable()
  {
    this->e = e;
  }

  SendBuff_ActiveState :: SendBuff_ActiveState(const SendBuff_ActiveState& other):Serializable()
  {
    this->e = other.e;
  }

  // ----------------------------------------------------------------------
  // Instance methods
  // ----------------------------------------------------------------------

  SendBuff_ActiveState& SendBuff_ActiveState :: operator=(const SendBuff_ActiveState& other)
  {
    this->e = other.e;
    return *this;
  }

  SendBuff_ActiveState& SendBuff_ActiveState :: operator=(const t a)
  {
    this->e = a;
    return *this;
  }

  SendBuff_ActiveState& SendBuff_ActiveState :: operator=(const NATIVE_INT_TYPE a)
  {
    FW_ASSERT(a == 0 || a == 1, static_cast<t>(a));
    this->e = static_cast<t>(a);
    return *this;
  }

  SendBuff_ActiveState& SendBuff_ActiveState :: operator=(const NATIVE_UINT_TYPE a)
  {
    FW_ASSERT(a == 0 || a == 1, static_cast<t>(a));
    this->e = static_cast<t>(a);
    return *this;
  }

  bool SendBuff_ActiveState :: operator==(const SendBuff_ActiveState& other) const
  {
    return this->e == other.e;
  }

  bool SendBuff_ActiveState :: operator!=(const SendBuff_ActiveState& other) const
  {
    return !(*this == other);
  }

#ifdef BUILD_UT
  std::ostream& operator<<(std::ostream& os, const SendBuff_ActiveState& obj) {
    os << "SendBuff_ActiveState::";
    const SendBuff_ActiveState::t e = obj.e;
    switch (e) {
        case SendBuff_ActiveState::SEND_IDLE:
          os << "SEND_IDLE";
          break;
        case SendBuff_ActiveState::SEND_ACTIVE:
          os << "SEND_ACTIVE";
          break;
        default:
          os << "[invalid]";
          break;
    }
    os << " (" << e << ")";
    return os;
  }
#endif

  Fw::SerializeStatus SendBuff_ActiveState :: serialize(Fw::SerializeBufferBase& buffer) const
  {
    Fw::SerializeStatus status;
    status = buffer.serialize(static_cast<I32>(this->e));
    return status;
  }

  Fw::SerializeStatus SendBuff_ActiveState :: deserialize(Fw::SerializeBufferBase& buffer)
  {
    Fw::SerializeStatus status;
    I32 es;
    status = buffer.deserialize(es);
    if (status == Fw::FW_SERIALIZE_OK)
      this->e = static_cast<t>(es);
    return status;
  }

  #if FW_SERIALIZABLE_TO_STRING || BUILD_UT
    void SendBuff_ActiveState :: toString(Fw::StringBase& text) const {
    const SendBuff_ActiveState::t e = this->e;
    switch (e) {
        case SendBuff_ActiveState::SEND_IDLE:
          text = "SEND_IDLE";
          break;
        case SendBuff_ActiveState::SEND_ACTIVE:
          text = "SEND_ACTIVE";
          break;
        default:
          text = "[invalid]";
          break;
    }
  }
  #endif

}
