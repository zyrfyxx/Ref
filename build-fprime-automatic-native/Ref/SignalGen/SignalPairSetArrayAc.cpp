// ======================================================================
// \title  SignalPairSet
// \author Auto-generated
// \brief  cpp file for SignalPairSet
//
// NOTE: this file was automatically generated
//
// ======================================================================

#include <cstring>
#include <cstdio>

#include "Fw/Types/Assert.hpp"
#include <Fw/Types/StringUtils.hpp>

#include "SignalPairSetArrayAc.hpp"

namespace Ref {


  // ----------------------------------------------------------------------
  // Constructors
  // ----------------------------------------------------------------------

  SignalPairSet ::
    SignalPairSet() :
      Serializable()
  {
    *this = SignalPairSet(
      Ref::SignalPair(0.0f, 0.0f),
      Ref::SignalPair(0.0f, 0.0f),
      Ref::SignalPair(0.0f, 0.0f),
      Ref::SignalPair(0.0f, 0.0f));
  }

  SignalPairSet ::
    SignalPairSet(const ElementType (&a)[SIZE]) :
      Serializable()
  {
    for(U32 index = 0; index < SIZE; index++)
    {
      this->elements[index] = a[index];
    }
  }

  SignalPairSet ::
    SignalPairSet(const ElementType& e) :
      Serializable()
  {
    for(U32 index = 0; index < SIZE; index++)
    {
      this->elements[index] = e;
    }
  }

  SignalPairSet ::
    SignalPairSet(
      const ElementType (&e1), //!< Element 1
      const ElementType (&e2), //!< Element 2
      const ElementType (&e3), //!< Element 3
      const ElementType (&e4)
    ) :
      Serializable()
  {
    this->elements[0] = e1;
    this->elements[1] = e2;
    this->elements[2] = e3;
    this->elements[3] = e4;
  }

  SignalPairSet ::
    SignalPairSet(const SignalPairSet& other) :
      Serializable()
  {
    for(U32 index = 0; index < SIZE; index++)
    {
      this->elements[index] = other.elements[index];
    }
  }

  // ----------------------------------------------------------------------
  // Public functions
  // ----------------------------------------------------------------------


  SignalPairSet::ElementType& SignalPairSet ::
    operator[](const U32 i)
  {
    FW_ASSERT(i < SIZE);
    return this->elements[i];
  }

  const SignalPairSet::ElementType& SignalPairSet ::
    operator[](const U32 i) const
  {
    FW_ASSERT(i < SIZE);
    return this->elements[i];
  }


  SignalPairSet& SignalPairSet ::
    operator=(const SignalPairSet& other)
  {
    if(this == &other) {
      return *this;
    }

    for(U32 index = 0; index < SIZE; index++) {
      this->elements[index] = other.elements[index];
    }
    return *this;
  }

  SignalPairSet& SignalPairSet ::
    operator=(const ElementType (&a)[SIZE])
  {
    for(U32 index = 0; index < SIZE; index++) {
      this->elements[index] = a[index];
    }
    return *this;
  }

  SignalPairSet& SignalPairSet ::
    operator=(const ElementType& e)
  {
    for(U32 index = 0; index < SIZE; index++) {
      this->elements[index] = e;
    }
    return *this;
  }

  bool SignalPairSet ::
    operator==(const SignalPairSet& other) const
  {
    for (U32 i = 0; i < SIZE; ++i) {
      if (!((*this)[i] == other[i])) {
        return false;
      }
    }
    return true;
  }

  bool SignalPairSet ::
    operator!=(const SignalPairSet& other) const
  {
    return !(*this == other);
  }

#if FW_ARRAY_TO_STRING  || BUILD_UT

void SignalPairSet::toString(Fw::StringBase& text) const {

    static const char * formatString = "[ "
      "%s, "
      "%s, "
      "%s, "
      "%s ]";

    // Need to instantiate toString for arrays and serializable types
    Fw::String str0;
    this->elements[0].toString(str0);
    Fw::String str1;
    this->elements[1].toString(str1);
    Fw::String str2;
    this->elements[2].toString(str2);
    Fw::String str3;
    this->elements[3].toString(str3);

    // declare strings to hold any serializable toString() arguments

    char outputString[FW_ARRAY_TO_STRING_BUFFER_SIZE];
    (void)snprintf(outputString,FW_ARRAY_TO_STRING_BUFFER_SIZE,formatString
      ,str0.toChar()
      ,str1.toChar()
      ,str2.toChar()
      ,str3.toChar()
    );
    outputString[FW_ARRAY_TO_STRING_BUFFER_SIZE-1] = 0; // NULL terminate

    text = outputString;
}

#endif

#ifdef BUILD_UT
  std::ostream& operator<<(std::ostream& os, const SignalPairSet& obj) {
    Fw::String temp;
    obj.toString(temp);

    os << temp;
    return os;
  }
#endif

  Fw::SerializeStatus SignalPairSet ::
    serialize(Fw::SerializeBufferBase& buffer) const
  {
    Fw::SerializeStatus status = Fw::FW_SERIALIZE_OK;
    for (U32 i = 0; i < SIZE; ++i) {
      status = buffer.serialize((*this)[i]);
      if (status != Fw::FW_SERIALIZE_OK) {
        return status;
      }
    }
    return status;
  }

  Fw::SerializeStatus SignalPairSet ::
    deserialize(Fw::SerializeBufferBase& buffer)
  {
    Fw::SerializeStatus status = Fw::FW_SERIALIZE_OK;
    for (U32 i = 0; i < SIZE; ++i) {
      status = buffer.deserialize((*this)[i]);
      if (status != Fw::FW_SERIALIZE_OK) {
        return status;
      }
    }
    return status;
  }

}
