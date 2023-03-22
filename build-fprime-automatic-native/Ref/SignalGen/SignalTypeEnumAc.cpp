// ======================================================================
// \title  SignalType
// \author Auto-generated
// \brief  cpp file for SignalType
//
// NOTE: this file was automatically generated
//
// ======================================================================

#include <cstring>
#include <limits>
#include "Fw/Types/Assert.hpp"
#include "SignalTypeEnumAc.hpp"

namespace Ref {

  // ----------------------------------------------------------------------
  // Constructors
  // ----------------------------------------------------------------------

  SignalType :: SignalType():Serializable()
  {
    this->e = static_cast<t>(TRIANGLE);
  }

  SignalType :: SignalType(const t e):Serializable()
  {
    this->e = e;
  }

  SignalType :: SignalType(const SignalType& other):Serializable()
  {
    this->e = other.e;
  }

  // ----------------------------------------------------------------------
  // Instance methods
  // ----------------------------------------------------------------------

  SignalType& SignalType :: operator=(const SignalType& other)
  {
    this->e = other.e;
    return *this;
  }

  SignalType& SignalType :: operator=(const t a)
  {
    this->e = a;
    return *this;
  }

  SignalType& SignalType :: operator=(const NATIVE_INT_TYPE a)
  {
    FW_ASSERT(a == 0 || a == 1 || a == 2 || a == 3, static_cast<t>(a));
    this->e = static_cast<t>(a);
    return *this;
  }

  SignalType& SignalType :: operator=(const NATIVE_UINT_TYPE a)
  {
    FW_ASSERT(a == 0 || a == 1 || a == 2 || a == 3, static_cast<t>(a));
    this->e = static_cast<t>(a);
    return *this;
  }

  bool SignalType :: operator==(const SignalType& other) const
  {
    return this->e == other.e;
  }

  bool SignalType :: operator!=(const SignalType& other) const
  {
    return !(*this == other);
  }

#ifdef BUILD_UT
  std::ostream& operator<<(std::ostream& os, const SignalType& obj) {
    os << "SignalType::";
    const SignalType::t e = obj.e;
    switch (e) {
        case SignalType::TRIANGLE:
          os << "TRIANGLE";
          break;
        case SignalType::SQUARE:
          os << "SQUARE";
          break;
        case SignalType::SINE:
          os << "SINE";
          break;
        case SignalType::NOISE:
          os << "NOISE";
          break;
        default:
          os << "[invalid]";
          break;
    }
    os << " (" << e << ")";
    return os;
  }
#endif

  Fw::SerializeStatus SignalType :: serialize(Fw::SerializeBufferBase& buffer) const
  {
    Fw::SerializeStatus status;
    status = buffer.serialize(static_cast<I32>(this->e));
    return status;
  }

  Fw::SerializeStatus SignalType :: deserialize(Fw::SerializeBufferBase& buffer)
  {
    Fw::SerializeStatus status;
    I32 es;
    status = buffer.deserialize(es);
    if (status == Fw::FW_SERIALIZE_OK)
      this->e = static_cast<t>(es);
    return status;
  }

  #if FW_SERIALIZABLE_TO_STRING || BUILD_UT
    void SignalType :: toString(Fw::StringBase& text) const {
    const SignalType::t e = this->e;
    switch (e) {
        case SignalType::TRIANGLE:
          text = "TRIANGLE";
          break;
        case SignalType::SQUARE:
          text = "SQUARE";
          break;
        case SignalType::SINE:
          text = "SINE";
          break;
        case SignalType::NOISE:
          text = "NOISE";
          break;
        default:
          text = "[invalid]";
          break;
    }
  }
  #endif

}
