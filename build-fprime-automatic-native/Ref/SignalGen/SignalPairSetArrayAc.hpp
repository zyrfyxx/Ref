// ======================================================================
// \title  SignalPairSet.hpp
// \author Auto-generated
// \brief  hpp file for SignalPairSet
//
// NOTE: this file was automatically generated
//
// ======================================================================

#ifndef Ref_SignalPairSet_HPP
#define Ref_SignalPairSet_HPP

#include "Fw/Types/String.hpp"
#include "Fw/Types/BasicTypes.hpp"
#include "Fw/Types/Serializable.hpp"
#include <Ref/SignalGen/SignalPairSerializableAc.hpp>

namespace Ref {
  class SignalPairSet : public Fw::Serializable
  {
    public:

    // ----------------------------------------------------------------------
    // Helper Types
    // ----------------------------------------------------------------------

    typedef Ref::SignalPair ElementType;

    enum {
        SIZE=4,
        SERIALIZED_SIZE = SIZE *
        Ref::SignalPair::SERIALIZED_SIZE
    }; //!< serializable size of SignalPairSet

    public:

    // ----------------------------------------------------------------------
    // Constructors
    // ----------------------------------------------------------------------

      //! Construct a SignalPairSet with default initialization
      SignalPairSet();

      //! Construct a SignalPairSet and initialize its elements from an array
      SignalPairSet(
          const ElementType (&a)[SIZE] //!< The array
      );

      //! Construct a SignalPairSet and initialize its elements from a single element
      SignalPairSet(
          const ElementType& e //!< The element
      );

      //! Construct a SignalPairSet and initialize its elements from elements
   SignalPairSet(
      const ElementType (&e1), //!< Element 1
      const ElementType (&e2), //!< Element 2
      const ElementType (&e3), //!< Element 3
      const ElementType (&e4)
      );

      //! Copy constructor
      SignalPairSet(
          const SignalPairSet& other //!< The other object
      );

    public:

      // ----------------------------------------------------------------------
      // Public operators
      // ----------------------------------------------------------------------

      //! Subscript operator
      ElementType& operator[](
          const U32 i //!< The subscript index
      );

      //! Const subscript operator
      const ElementType& operator[](
          const U32 i //!< The subscript index
      ) const;

      //! Assignment operator
      SignalPairSet& operator=(
          const SignalPairSet& other //!< The other object
      );

      //! Assignment operator from array
      SignalPairSet& operator=(
          const ElementType (&a)[SIZE] //!< The array
      );

      //! Assignment operator from element
      SignalPairSet& operator=(
          const ElementType& e //!< The element
      );

      //! Equality operator
      bool operator==(
          const SignalPairSet& other //!< The other object
      ) const;

      //! Inequality operator
      bool operator!=(
          const SignalPairSet& other //!< The other object
      ) const;

#ifdef BUILD_UT
      //! Ostream operator
      friend std::ostream& operator<<(
          std::ostream& os, //!< The ostream
          const SignalPairSet& obj //!< The object
      );
#endif

    public:

    // ----------------------------------------------------------------------
    // Public methods
    // ----------------------------------------------------------------------

    //! Serialization
    Fw::SerializeStatus serialize(
        Fw::SerializeBufferBase& buffer //!< The serial buffer
    ) const;

    //! Deserialization
    Fw::SerializeStatus deserialize(
        Fw::SerializeBufferBase& buffer //!< The serial buffer
    );

#if FW_ARRAY_TO_STRING || BUILD_UT
    void toString(Fw::StringBase& text) const; //!< generate text from serializable
#endif

    protected:

    enum {
        TYPE_ID = 0xB7FC714B //!< type id
    };

    private:

    // ----------------------------------------------------------------------
    // Private member variables
    // ----------------------------------------------------------------------

    //! The array elements
    ElementType elements[SIZE];

  };

}

#endif
