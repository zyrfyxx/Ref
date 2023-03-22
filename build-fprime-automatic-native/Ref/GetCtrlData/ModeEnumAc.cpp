// ======================================================================
// \title  Mode
// \author Auto-generated
// \brief  cpp file for Mode
//
// NOTE: this file was automatically generated
//
// ======================================================================

#include <cstring>
#include <limits>
#include "Fw/Types/Assert.hpp"
#include "ModeEnumAc.hpp"

namespace Ref {

  // ----------------------------------------------------------------------
  // Constructors
  // ----------------------------------------------------------------------

  Mode :: Mode():Serializable()
  {
    this->e = static_cast<t>(SAM_DAMP);
  }

  Mode :: Mode(const t e):Serializable()
  {
    this->e = e;
  }

  Mode :: Mode(const Mode& other):Serializable()
  {
    this->e = other.e;
  }

  // ----------------------------------------------------------------------
  // Instance methods
  // ----------------------------------------------------------------------

  Mode& Mode :: operator=(const Mode& other)
  {
    this->e = other.e;
    return *this;
  }

  Mode& Mode :: operator=(const t a)
  {
    this->e = a;
    return *this;
  }

  Mode& Mode :: operator=(const NATIVE_INT_TYPE a)
  {
    FW_ASSERT(a == 0 || a == 1 || a == 2 || a == 3 || a == 4, static_cast<t>(a));
    this->e = static_cast<t>(a);
    return *this;
  }

  Mode& Mode :: operator=(const NATIVE_UINT_TYPE a)
  {
    FW_ASSERT(a == 0 || a == 1 || a == 2 || a == 3 || a == 4, static_cast<t>(a));
    this->e = static_cast<t>(a);
    return *this;
  }

  bool Mode :: operator==(const Mode& other) const
  {
    return this->e == other.e;
  }

  bool Mode :: operator!=(const Mode& other) const
  {
    return !(*this == other);
  }

#ifdef BUILD_UT
  std::ostream& operator<<(std::ostream& os, const Mode& obj) {
    os << "Mode::";
    const Mode::t e = obj.e;
    switch (e) {
        case Mode::SAM_DAMP:
          os << "SAM_DAMP";
          break;
        case Mode::SAM_PITCH:
          os << "SAM_PITCH";
          break;
        case Mode::SAM_ROLL:
          os << "SAM_ROLL";
          break;
        case Mode::SAM_CRUISE:
          os << "SAM_CRUISE";
          break;
        case Mode::NOCRAL:
          os << "NOCRAL";
          break;
        default:
          os << "[invalid]";
          break;
    }
    os << " (" << e << ")";
    return os;
  }
#endif

  Fw::SerializeStatus Mode :: serialize(Fw::SerializeBufferBase& buffer) const
  {
    Fw::SerializeStatus status;
    status = buffer.serialize(static_cast<I32>(this->e));
    return status;
  }

  Fw::SerializeStatus Mode :: deserialize(Fw::SerializeBufferBase& buffer)
  {
    Fw::SerializeStatus status;
    I32 es;
    status = buffer.deserialize(es);
    if (status == Fw::FW_SERIALIZE_OK)
      this->e = static_cast<t>(es);
    return status;
  }

  #if FW_SERIALIZABLE_TO_STRING || BUILD_UT
    void Mode :: toString(Fw::StringBase& text) const {
    const Mode::t e = this->e;
    switch (e) {
        case Mode::SAM_DAMP:
          text = "SAM_DAMP";
          break;
        case Mode::SAM_PITCH:
          text = "SAM_PITCH";
          break;
        case Mode::SAM_ROLL:
          text = "SAM_ROLL";
          break;
        case Mode::SAM_CRUISE:
          text = "SAM_CRUISE";
          break;
        case Mode::NOCRAL:
          text = "NOCRAL";
          break;
        default:
          text = "[invalid]";
          break;
    }
  }
  #endif

}
