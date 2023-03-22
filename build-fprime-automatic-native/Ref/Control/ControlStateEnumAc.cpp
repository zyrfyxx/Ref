// ======================================================================
// \title  ControlState
// \author Auto-generated
// \brief  cpp file for ControlState
//
// NOTE: this file was automatically generated
//
// ======================================================================

#include <cstring>
#include <limits>
#include "Fw/Types/Assert.hpp"
#include "ControlStateEnumAc.hpp"

namespace Ref {

  // ----------------------------------------------------------------------
  // Constructors
  // ----------------------------------------------------------------------

  ControlState :: ControlState():Serializable()
  {
    this->e = static_cast<t>(RUN);
  }

  ControlState :: ControlState(const t e):Serializable()
  {
    this->e = e;
  }

  ControlState :: ControlState(const ControlState& other):Serializable()
  {
    this->e = other.e;
  }

  // ----------------------------------------------------------------------
  // Instance methods
  // ----------------------------------------------------------------------

  ControlState& ControlState :: operator=(const ControlState& other)
  {
    this->e = other.e;
    return *this;
  }

  ControlState& ControlState :: operator=(const t a)
  {
    this->e = a;
    return *this;
  }

  ControlState& ControlState :: operator=(const NATIVE_INT_TYPE a)
  {
    FW_ASSERT(a == 0 || a == 1 || a == 2, static_cast<t>(a));
    this->e = static_cast<t>(a);
    return *this;
  }

  ControlState& ControlState :: operator=(const NATIVE_UINT_TYPE a)
  {
    FW_ASSERT(a == 0 || a == 1 || a == 2, static_cast<t>(a));
    this->e = static_cast<t>(a);
    return *this;
  }

  bool ControlState :: operator==(const ControlState& other) const
  {
    return this->e == other.e;
  }

  bool ControlState :: operator!=(const ControlState& other) const
  {
    return !(*this == other);
  }

#ifdef BUILD_UT
  std::ostream& operator<<(std::ostream& os, const ControlState& obj) {
    os << "ControlState::";
    const ControlState::t e = obj.e;
    switch (e) {
        case ControlState::RUN:
          os << "RUN";
          break;
        case ControlState::PAUSE:
          os << "PAUSE";
          break;
        case ControlState::END:
          os << "END";
          break;
        default:
          os << "[invalid]";
          break;
    }
    os << " (" << e << ")";
    return os;
  }
#endif

  Fw::SerializeStatus ControlState :: serialize(Fw::SerializeBufferBase& buffer) const
  {
    Fw::SerializeStatus status;
    status = buffer.serialize(static_cast<I32>(this->e));
    return status;
  }

  Fw::SerializeStatus ControlState :: deserialize(Fw::SerializeBufferBase& buffer)
  {
    Fw::SerializeStatus status;
    I32 es;
    status = buffer.deserialize(es);
    if (status == Fw::FW_SERIALIZE_OK)
      this->e = static_cast<t>(es);
    return status;
  }

  #if FW_SERIALIZABLE_TO_STRING || BUILD_UT
    void ControlState :: toString(Fw::StringBase& text) const {
    const ControlState::t e = this->e;
    switch (e) {
        case ControlState::RUN:
          text = "RUN";
          break;
        case ControlState::PAUSE:
          text = "PAUSE";
          break;
        case ControlState::END:
          text = "END";
          break;
        default:
          text = "[invalid]";
          break;
    }
  }
  #endif

}
