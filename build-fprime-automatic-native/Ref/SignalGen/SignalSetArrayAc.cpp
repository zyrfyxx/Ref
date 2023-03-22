// ======================================================================
// \title  SignalSet
// \author Auto-generated
// \brief  cpp file for SignalSet
//
// NOTE: this file was automatically generated
//
// ======================================================================

#include <cstring>
#include <cstdio>

#include "Fw/Types/Assert.hpp"
#include <Fw/Types/StringUtils.hpp>

#include "SignalSetArrayAc.hpp"

namespace Ref {


  // ----------------------------------------------------------------------
  // Constructors
  // ----------------------------------------------------------------------

  SignalSet ::
    SignalSet() :
      Serializable()
  {
    *this = SignalSet(
      0.0f,
      0.0f,
      0.0f,
      0.0f);
  }

  SignalSet ::
    SignalSet(const ElementType (&a)[SIZE]) :
      Serializable()
  {
    for(U32 index = 0; index < SIZE; index++)
    {
      this->elements[index] = a[index];
    }
  }

  SignalSet ::
    SignalSet(const ElementType& e) :
      Serializable()
  {
    for(U32 index = 0; index < SIZE; index++)
    {
      this->elements[index] = e;
    }
  }

  SignalSet ::
    SignalSet(
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

  SignalSet ::
    SignalSet(const SignalSet& other) :
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


  SignalSet::ElementType& SignalSet ::
    operator[](const U32 i)
  {
    FW_ASSERT(i < SIZE);
    return this->elements[i];
  }

  const SignalSet::ElementType& SignalSet ::
    operator[](const U32 i) const
  {
    FW_ASSERT(i < SIZE);
    return this->elements[i];
  }


  SignalSet& SignalSet ::
    operator=(const SignalSet& other)
  {
    if(this == &other) {
      return *this;
    }

    for(U32 index = 0; index < SIZE; index++) {
      this->elements[index] = other.elements[index];
    }
    return *this;
  }

  SignalSet& SignalSet ::
    operator=(const ElementType (&a)[SIZE])
  {
    for(U32 index = 0; index < SIZE; index++) {
      this->elements[index] = a[index];
    }
    return *this;
  }

  SignalSet& SignalSet ::
    operator=(const ElementType& e)
  {
    for(U32 index = 0; index < SIZE; index++) {
      this->elements[index] = e;
    }
    return *this;
  }

  bool SignalSet ::
    operator==(const SignalSet& other) const
  {
    for (U32 i = 0; i < SIZE; ++i) {
      if (!((*this)[i] == other[i])) {
        return false;
      }
    }
    return true;
  }

  bool SignalSet ::
    operator!=(const SignalSet& other) const
  {
    return !(*this == other);
  }

#if FW_ARRAY_TO_STRING  || BUILD_UT

void SignalSet::toString(Fw::StringBase& text) const {

    static const char * formatString = "[ "
      "%f, "
      "%f, "
      "%f, "
      "%f ]";


    // declare strings to hold any serializable toString() arguments

    char outputString[FW_ARRAY_TO_STRING_BUFFER_SIZE];
    (void)snprintf(outputString,FW_ARRAY_TO_STRING_BUFFER_SIZE,formatString
      ,this->elements[0]
      ,this->elements[1]
      ,this->elements[2]
      ,this->elements[3]
    );
    outputString[FW_ARRAY_TO_STRING_BUFFER_SIZE-1] = 0; // NULL terminate

    text = outputString;
}

#endif

#ifdef BUILD_UT
  std::ostream& operator<<(std::ostream& os, const SignalSet& obj) {
    Fw::String temp;
    obj.toString(temp);

    os << temp;
    return os;
  }
#endif

  Fw::SerializeStatus SignalSet ::
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

  Fw::SerializeStatus SignalSet ::
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
