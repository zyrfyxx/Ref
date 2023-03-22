// ======================================================================
// \title  SignalType.hpp
// \author Auto-generated
// \brief  hpp file for SignalType
//
// NOTE: this file was automatically generated
//
// ======================================================================

#ifndef Ref_SignalType_HPP
#define Ref_SignalType_HPP

#include "Fw/Types/String.hpp"
#include "Fw/Types/BasicTypes.hpp"
#include "Fw/Types/Serializable.hpp"

namespace Ref {
  class SignalType : public Fw::Serializable
  {
    public:
    // ----------------------------------------------------------------------
    // Types
    // ----------------------------------------------------------------------

    typedef enum {
    TRIANGLE = 0,
    SQUARE = 1,
    SINE = 2,
    NOISE = 3,
        } t;

    public:

    // ----------------------------------------------------------------------
    // Constants
    // ----------------------------------------------------------------------

    enum {
        SERIALIZED_SIZE = sizeof(I32)
        };

    //! Number of items in SignalType enum
    static const U32 NUM_CONSTANTS = 4;

    public:

    // ----------------------------------------------------------------------
    // Constructors
    // ----------------------------------------------------------------------

    //! Construct SignalType object with default initialization
    SignalType();

    //! Construct SignalType object and initialize its value
    SignalType(
        const t e //!< The enum value
        );

    //! Copy constructor
    SignalType(
        const SignalType& other //!< The other object
        );

    public:

    // ----------------------------------------------------------------------
    // Operators
    // ----------------------------------------------------------------------

    //! Assignment operator
    SignalType& operator=(
        const SignalType& other //!< The other object
        );

    //! Assignment operator
    SignalType& operator=(
        const t a //!< The enumerated constant to copy
        );

    //! Assignment operator
    SignalType& operator=(
        const NATIVE_INT_TYPE a //!< The integer to copy
        );

    //! Assignment operator
    SignalType& operator=(
        const NATIVE_UINT_TYPE a //!< The integer to copy
        );

    //! Equality operator
    bool operator==(
        const SignalType& other //!< The other object
        ) const;

    //! Inequality operator
    bool operator!=(
        const SignalType& other //!< The other object
        ) const;

#ifdef BUILD_UT
    //! Ostream operator for SignalType object
    friend std::ostream& operator<<(
        std::ostream& os, //!< The ostream
        const SignalType& obj //!< The object
        );
#endif

    public:

    // ----------------------------------------------------------------------
    // Methods
    // ----------------------------------------------------------------------

    //! Serialization
    Fw::SerializeStatus serialize(
        Fw::SerializeBufferBase& buffer //!< The serial buffer
        ) const;

    //! Deserialization
    Fw::SerializeStatus deserialize(
        Fw::SerializeBufferBase& buffer //!< The serial buffer
        );

#if FW_SERIALIZABLE_TO_STRING || BUILD_UT
    //! ENUM toString
    void toString(Fw::StringBase& text) const;  //!< generate text from serializable
#endif

    public:

    // ----------------------------------------------------------------------
    // Member variables
    // ----------------------------------------------------------------------

    //! The enumeration value
    t e;
  };
}
#endif
