// ======================================================================
// \title  RecvStatus
// \author Auto-generated
// \brief  cpp file for RecvStatus
//
// NOTE: this file was automatically generated
//
// ======================================================================

#include <cstring>
#include <limits>
#include "Fw/Types/Assert.hpp"
#include "RecvStatusEnumAc.hpp"

namespace Drv {

  // ----------------------------------------------------------------------
  // Constructors
  // ----------------------------------------------------------------------

  RecvStatus :: RecvStatus():Serializable()
  {
    this->e = static_cast<t>(RECV_OK);
  }

  RecvStatus :: RecvStatus(const t e):Serializable()
  {
    this->e = e;
  }

  RecvStatus :: RecvStatus(const RecvStatus& other):Serializable()
  {
    this->e = other.e;
  }

  // ----------------------------------------------------------------------
  // Instance methods
  // ----------------------------------------------------------------------

  RecvStatus& RecvStatus :: operator=(const RecvStatus& other)
  {
    this->e = other.e;
    return *this;
  }

  RecvStatus& RecvStatus :: operator=(const t a)
  {
    this->e = a;
    return *this;
  }

  RecvStatus& RecvStatus :: operator=(const NATIVE_INT_TYPE a)
  {
    FW_ASSERT(a == 0 || a == 1, static_cast<t>(a));
    this->e = static_cast<t>(a);
    return *this;
  }

  RecvStatus& RecvStatus :: operator=(const NATIVE_UINT_TYPE a)
  {
    FW_ASSERT(a == 0 || a == 1, static_cast<t>(a));
    this->e = static_cast<t>(a);
    return *this;
  }

  bool RecvStatus :: operator==(const RecvStatus& other) const
  {
    return this->e == other.e;
  }

  bool RecvStatus :: operator!=(const RecvStatus& other) const
  {
    return !(*this == other);
  }

#ifdef BUILD_UT
  std::ostream& operator<<(std::ostream& os, const RecvStatus& obj) {
    os << "RecvStatus::";
    const RecvStatus::t e = obj.e;
    switch (e) {
        case RecvStatus::RECV_OK:
          os << "RECV_OK";
          break;
        case RecvStatus::RECV_ERROR:
          os << "RECV_ERROR";
          break;
        default:
          os << "[invalid]";
          break;
    }
    os << " (" << e << ")";
    return os;
  }
#endif

  Fw::SerializeStatus RecvStatus :: serialize(Fw::SerializeBufferBase& buffer) const
  {
    Fw::SerializeStatus status;
    status = buffer.serialize(static_cast<I32>(this->e));
    return status;
  }

  Fw::SerializeStatus RecvStatus :: deserialize(Fw::SerializeBufferBase& buffer)
  {
    Fw::SerializeStatus status;
    I32 es;
    status = buffer.deserialize(es);
    if (status == Fw::FW_SERIALIZE_OK)
      this->e = static_cast<t>(es);
    return status;
  }

  #if FW_SERIALIZABLE_TO_STRING || BUILD_UT
    void RecvStatus :: toString(Fw::StringBase& text) const {
    const RecvStatus::t e = this->e;
    switch (e) {
        case RecvStatus::RECV_OK:
          text = "RECV_OK";
          break;
        case RecvStatus::RECV_ERROR:
          text = "RECV_ERROR";
          break;
        default:
          text = "[invalid]";
          break;
    }
  }
  #endif

}
