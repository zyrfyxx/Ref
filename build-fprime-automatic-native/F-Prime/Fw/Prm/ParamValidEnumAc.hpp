// ======================================================================
// \title  ParamValid.hpp
// \author Auto-generated
// \brief  hpp file for ParamValid
//
// NOTE: this file was automatically generated
//
// ======================================================================

#ifndef Fw_ParamValid_HPP
#define Fw_ParamValid_HPP

#include "Fw/Types/String.hpp"
#include "Fw/Types/BasicTypes.hpp"
#include "Fw/Types/Serializable.hpp"

namespace Fw {
  //! 
  //! Enum representing parameter validity
  //! 
  class ParamValid : public Fw::Serializable
  {
    public:
    // ----------------------------------------------------------------------
    // Types
    // ----------------------------------------------------------------------

    typedef enum {
    UNINIT = 0,
    VALID = 1,
    INVALID = 2,
    DEFAULT = 3,
        } t;

    public:

    // ----------------------------------------------------------------------
    // Constants
    // ----------------------------------------------------------------------

    enum {
        SERIALIZED_SIZE = sizeof(I32)
        };

    //! Number of items in ParamValid enum
    static const U32 NUM_CONSTANTS = 4;

    public:

    // ----------------------------------------------------------------------
    // Constructors
    // ----------------------------------------------------------------------

    //! Construct ParamValid object with default initialization
    ParamValid();

    //! Construct ParamValid object and initialize its value
    ParamValid(
        const t e //!< The enum value
        );

    //! Copy constructor
    ParamValid(
        const ParamValid& other //!< The other object
        );

    public:

    // ----------------------------------------------------------------------
    // Operators
    // ----------------------------------------------------------------------

    //! Assignment operator
    ParamValid& operator=(
        const ParamValid& other //!< The other object
        );

    //! Assignment operator
    ParamValid& operator=(
        const t a //!< The enumerated constant to copy
        );

    //! Assignment operator
    ParamValid& operator=(
        const NATIVE_INT_TYPE a //!< The integer to copy
        );

    //! Assignment operator
    ParamValid& operator=(
        const NATIVE_UINT_TYPE a //!< The integer to copy
        );

    //! Equality operator
    bool operator==(
        const ParamValid& other //!< The other object
        ) const;

    //! Inequality operator
    bool operator!=(
        const ParamValid& other //!< The other object
        ) const;

#ifdef BUILD_UT
    //! Ostream operator for ParamValid object
    friend std::ostream& operator<<(
        std::ostream& os, //!< The ostream
        const ParamValid& obj //!< The object
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
