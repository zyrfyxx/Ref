// ======================================================================
// \title  Ports_RateGroups
// \author Auto-generated
// \brief  cpp file for Ports_RateGroups
//
// NOTE: this file was automatically generated
//
// ======================================================================

#include <cstring>
#include <limits>
#include "Fw/Types/Assert.hpp"
#include "Ports_RateGroupsEnumAc.hpp"

namespace Ref {

  // ----------------------------------------------------------------------
  // Constructors
  // ----------------------------------------------------------------------

  Ports_RateGroups :: Ports_RateGroups():Serializable()
  {
    this->e = static_cast<t>(rateGroup1);
  }

  Ports_RateGroups :: Ports_RateGroups(const t e):Serializable()
  {
    this->e = e;
  }

  Ports_RateGroups :: Ports_RateGroups(const Ports_RateGroups& other):Serializable()
  {
    this->e = other.e;
  }

  // ----------------------------------------------------------------------
  // Instance methods
  // ----------------------------------------------------------------------

  Ports_RateGroups& Ports_RateGroups :: operator=(const Ports_RateGroups& other)
  {
    this->e = other.e;
    return *this;
  }

  Ports_RateGroups& Ports_RateGroups :: operator=(const t a)
  {
    this->e = a;
    return *this;
  }

  Ports_RateGroups& Ports_RateGroups :: operator=(const NATIVE_INT_TYPE a)
  {
    FW_ASSERT(a == 0 || a == 1 || a == 2, static_cast<t>(a));
    this->e = static_cast<t>(a);
    return *this;
  }

  Ports_RateGroups& Ports_RateGroups :: operator=(const NATIVE_UINT_TYPE a)
  {
    FW_ASSERT(a == 0 || a == 1 || a == 2, static_cast<t>(a));
    this->e = static_cast<t>(a);
    return *this;
  }

  bool Ports_RateGroups :: operator==(const Ports_RateGroups& other) const
  {
    return this->e == other.e;
  }

  bool Ports_RateGroups :: operator!=(const Ports_RateGroups& other) const
  {
    return !(*this == other);
  }

#ifdef BUILD_UT
  std::ostream& operator<<(std::ostream& os, const Ports_RateGroups& obj) {
    os << "Ports_RateGroups::";
    const Ports_RateGroups::t e = obj.e;
    switch (e) {
        case Ports_RateGroups::rateGroup1:
          os << "rateGroup1";
          break;
        case Ports_RateGroups::rateGroup2:
          os << "rateGroup2";
          break;
        case Ports_RateGroups::rateGroup3:
          os << "rateGroup3";
          break;
        default:
          os << "[invalid]";
          break;
    }
    os << " (" << e << ")";
    return os;
  }
#endif

  Fw::SerializeStatus Ports_RateGroups :: serialize(Fw::SerializeBufferBase& buffer) const
  {
    Fw::SerializeStatus status;
    status = buffer.serialize(static_cast<I32>(this->e));
    return status;
  }

  Fw::SerializeStatus Ports_RateGroups :: deserialize(Fw::SerializeBufferBase& buffer)
  {
    Fw::SerializeStatus status;
    I32 es;
    status = buffer.deserialize(es);
    if (status == Fw::FW_SERIALIZE_OK)
      this->e = static_cast<t>(es);
    return status;
  }

  #if FW_SERIALIZABLE_TO_STRING || BUILD_UT
    void Ports_RateGroups :: toString(Fw::StringBase& text) const {
    const Ports_RateGroups::t e = this->e;
    switch (e) {
        case Ports_RateGroups::rateGroup1:
          text = "rateGroup1";
          break;
        case Ports_RateGroups::rateGroup2:
          text = "rateGroup2";
          break;
        case Ports_RateGroups::rateGroup3:
          text = "rateGroup3";
          break;
        default:
          text = "[invalid]";
          break;
    }
  }
  #endif

}
