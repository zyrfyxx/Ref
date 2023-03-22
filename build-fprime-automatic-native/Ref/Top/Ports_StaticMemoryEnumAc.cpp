// ======================================================================
// \title  Ports_StaticMemory
// \author Auto-generated
// \brief  cpp file for Ports_StaticMemory
//
// NOTE: this file was automatically generated
//
// ======================================================================

#include <cstring>
#include <limits>
#include "Fw/Types/Assert.hpp"
#include "Ports_StaticMemoryEnumAc.hpp"

namespace Ref {

  // ----------------------------------------------------------------------
  // Constructors
  // ----------------------------------------------------------------------

  Ports_StaticMemory :: Ports_StaticMemory():Serializable()
  {
    this->e = static_cast<t>(downlink);
  }

  Ports_StaticMemory :: Ports_StaticMemory(const t e):Serializable()
  {
    this->e = e;
  }

  Ports_StaticMemory :: Ports_StaticMemory(const Ports_StaticMemory& other):Serializable()
  {
    this->e = other.e;
  }

  // ----------------------------------------------------------------------
  // Instance methods
  // ----------------------------------------------------------------------

  Ports_StaticMemory& Ports_StaticMemory :: operator=(const Ports_StaticMemory& other)
  {
    this->e = other.e;
    return *this;
  }

  Ports_StaticMemory& Ports_StaticMemory :: operator=(const t a)
  {
    this->e = a;
    return *this;
  }

  Ports_StaticMemory& Ports_StaticMemory :: operator=(const NATIVE_INT_TYPE a)
  {
    FW_ASSERT(a == 0 || a == 1, static_cast<t>(a));
    this->e = static_cast<t>(a);
    return *this;
  }

  Ports_StaticMemory& Ports_StaticMemory :: operator=(const NATIVE_UINT_TYPE a)
  {
    FW_ASSERT(a == 0 || a == 1, static_cast<t>(a));
    this->e = static_cast<t>(a);
    return *this;
  }

  bool Ports_StaticMemory :: operator==(const Ports_StaticMemory& other) const
  {
    return this->e == other.e;
  }

  bool Ports_StaticMemory :: operator!=(const Ports_StaticMemory& other) const
  {
    return !(*this == other);
  }

#ifdef BUILD_UT
  std::ostream& operator<<(std::ostream& os, const Ports_StaticMemory& obj) {
    os << "Ports_StaticMemory::";
    const Ports_StaticMemory::t e = obj.e;
    switch (e) {
        case Ports_StaticMemory::downlink:
          os << "downlink";
          break;
        case Ports_StaticMemory::uplink:
          os << "uplink";
          break;
        default:
          os << "[invalid]";
          break;
    }
    os << " (" << e << ")";
    return os;
  }
#endif

  Fw::SerializeStatus Ports_StaticMemory :: serialize(Fw::SerializeBufferBase& buffer) const
  {
    Fw::SerializeStatus status;
    status = buffer.serialize(static_cast<I32>(this->e));
    return status;
  }

  Fw::SerializeStatus Ports_StaticMemory :: deserialize(Fw::SerializeBufferBase& buffer)
  {
    Fw::SerializeStatus status;
    I32 es;
    status = buffer.deserialize(es);
    if (status == Fw::FW_SERIALIZE_OK)
      this->e = static_cast<t>(es);
    return status;
  }

  #if FW_SERIALIZABLE_TO_STRING || BUILD_UT
    void Ports_StaticMemory :: toString(Fw::StringBase& text) const {
    const Ports_StaticMemory::t e = this->e;
    switch (e) {
        case Ports_StaticMemory::downlink:
          text = "downlink";
          break;
        case Ports_StaticMemory::uplink:
          text = "uplink";
          break;
        default:
          text = "[invalid]";
          break;
    }
  }
  #endif

}
