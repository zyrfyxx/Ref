// ======================================================================
// \title  CMD
// \author Auto-generated
// \brief  cpp file for CMD
//
// NOTE: this file was automatically generated
//
// ======================================================================

#include <cstring>
#include <limits>
#include "Fw/Types/Assert.hpp"
#include "CMDEnumAc.hpp"

namespace Ref {

  // ----------------------------------------------------------------------
  // Constructors
  // ----------------------------------------------------------------------

  CMD :: CMD():Serializable()
  {
    this->e = static_cast<t>(PAUSE);
  }

  CMD :: CMD(const t e):Serializable()
  {
    this->e = e;
  }

  CMD :: CMD(const CMD& other):Serializable()
  {
    this->e = other.e;
  }

  // ----------------------------------------------------------------------
  // Instance methods
  // ----------------------------------------------------------------------

  CMD& CMD :: operator=(const CMD& other)
  {
    this->e = other.e;
    return *this;
  }

  CMD& CMD :: operator=(const t a)
  {
    this->e = a;
    return *this;
  }

  CMD& CMD :: operator=(const NATIVE_INT_TYPE a)
  {
    FW_ASSERT(a == 0 || a == 1 || a == 2, static_cast<t>(a));
    this->e = static_cast<t>(a);
    return *this;
  }

  CMD& CMD :: operator=(const NATIVE_UINT_TYPE a)
  {
    FW_ASSERT(a == 0 || a == 1 || a == 2, static_cast<t>(a));
    this->e = static_cast<t>(a);
    return *this;
  }

  bool CMD :: operator==(const CMD& other) const
  {
    return this->e == other.e;
  }

  bool CMD :: operator!=(const CMD& other) const
  {
    return !(*this == other);
  }

#ifdef BUILD_UT
  std::ostream& operator<<(std::ostream& os, const CMD& obj) {
    os << "CMD::";
    const CMD::t e = obj.e;
    switch (e) {
        case CMD::PAUSE:
          os << "PAUSE";
          break;
        case CMD::RESUME:
          os << "RESUME";
          break;
        case CMD::STOP:
          os << "STOP";
          break;
        default:
          os << "[invalid]";
          break;
    }
    os << " (" << e << ")";
    return os;
  }
#endif

  Fw::SerializeStatus CMD :: serialize(Fw::SerializeBufferBase& buffer) const
  {
    Fw::SerializeStatus status;
    status = buffer.serialize(static_cast<I32>(this->e));
    return status;
  }

  Fw::SerializeStatus CMD :: deserialize(Fw::SerializeBufferBase& buffer)
  {
    Fw::SerializeStatus status;
    I32 es;
    status = buffer.deserialize(es);
    if (status == Fw::FW_SERIALIZE_OK)
      this->e = static_cast<t>(es);
    return status;
  }

  #if FW_SERIALIZABLE_TO_STRING || BUILD_UT
    void CMD :: toString(Fw::StringBase& text) const {
    const CMD::t e = this->e;
    switch (e) {
        case CMD::PAUSE:
          text = "PAUSE";
          break;
        case CMD::RESUME:
          text = "RESUME";
          break;
        case CMD::STOP:
          text = "STOP";
          break;
        default:
          text = "[invalid]";
          break;
    }
  }
  #endif

}
