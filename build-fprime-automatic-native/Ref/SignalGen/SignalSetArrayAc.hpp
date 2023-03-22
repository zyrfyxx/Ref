// ======================================================================
// \title  SignalSet.hpp
// \author Auto-generated
// \brief  hpp file for SignalSet
//
// NOTE: this file was automatically generated
//
// ======================================================================

#ifndef Ref_SignalSet_HPP
#define Ref_SignalSet_HPP

#include "Fw/Types/String.hpp"
#include "Fw/Types/BasicTypes.hpp"
#include "Fw/Types/Serializable.hpp"

namespace Ref {
  class SignalSet : public Fw::Serializable
  {
    public:

    // ----------------------------------------------------------------------
    // Helper Types
    // ----------------------------------------------------------------------

    typedef F32 ElementType;

    enum {
        SIZE=4,
        SERIALIZED_SIZE = SIZE *
        sizeof(F32)
    }; //!< serializable size of SignalSet

    public:

    // ----------------------------------------------------------------------
    // Constructors
    // ----------------------------------------------------------------------

      //! Construct a SignalSet with default initialization
      SignalSet();

      //! Construct a SignalSet and initialize its elements from an array
      SignalSet(
          const ElementType (&a)[SIZE] //!< The array
      );

      //! Construct a SignalSet and initialize its elements from a single element
      SignalSet(
          const ElementType& e //!< The element
      );

      //! Construct a SignalSet and initialize its elements from elements
   SignalSet(
      const ElementType (&e1), //!< Element 1
      const ElementType (&e2), //!< Element 2
      const ElementType (&e3), //!< Element 3
      const ElementType (&e4)
      );

      //! Copy constructor
      SignalSet(
          const SignalSet& other //!< The other object
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
      SignalSet& operator=(
          const SignalSet& other //!< The other object
      );

      //! Assignment operator from array
      SignalSet& operator=(
          const ElementType (&a)[SIZE] //!< The array
      );

      //! Assignment operator from element
      SignalSet& operator=(
          const ElementType& e //!< The element
      );

      //! Equality operator
      bool operator==(
          const SignalSet& other //!< The other object
      ) const;

      //! Inequality operator
      bool operator!=(
          const SignalSet& other //!< The other object
      ) const;

#ifdef BUILD_UT
      //! Ostream operator
      friend std::ostream& operator<<(
          std::ostream& os, //!< The ostream
          const SignalSet& obj //!< The object
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
        TYPE_ID = 0xC523CFF3 //!< type id
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
