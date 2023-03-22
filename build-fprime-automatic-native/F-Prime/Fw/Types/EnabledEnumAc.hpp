// ======================================================================
// \title  Enabled.hpp
// \author Auto-generated
// \brief  hpp file for Enabled
//
// NOTE: this file was automatically generated
//
// ======================================================================

#ifndef Fw_Enabled_HPP
#define Fw_Enabled_HPP

#include "Fw/Types/String.hpp"
#include "Fw/Types/BasicTypes.hpp"
#include "Fw/Types/Serializable.hpp"

namespace Fw {
  //! 
  //! Enabled and disabled states
  //! 
  class Enabled : public Fw::Serializable
  {
    public:
    // ----------------------------------------------------------------------
    // Types
    // ----------------------------------------------------------------------

    typedef enum {
    DISABLED = 0, //!< Disabled state
    ENABLED = 1, //!< Enabled state
        } t;

    public:

    // ----------------------------------------------------------------------
    // Constants
    // ----------------------------------------------------------------------

    enum {
        SERIALIZED_SIZE = sizeof(I32)
        };

    //! Number of items in Enabled enum
    static const U32 NUM_CONSTANTS = 2;

    public:

    // ----------------------------------------------------------------------
    // Constructors
    // ----------------------------------------------------------------------

    //! Construct Enabled object with default initialization
    Enabled();

    //! Construct Enabled object and initialize its value
    Enabled(
        const t e //!< The enum value
        );

    //! Copy constructor
    Enabled(
        const Enabled& other //!< The other object
        );

    public:

    // ----------------------------------------------------------------------
    // Operators
    // ----------------------------------------------------------------------

    //! Assignment operator
    Enabled& operator=(
        const Enabled& other //!< The other object
        );

    //! Assignment operator
    Enabled& operator=(
        const t a //!< The enumerated constant to copy
        );

    //! Assignment operator
    Enabled& operator=(
        const NATIVE_INT_TYPE a //!< The integer to copy
        );

    //! Assignment operator
    Enabled& operator=(
        const NATIVE_UINT_TYPE a //!< The integer to copy
        );

    //! Equality operator
    bool operator==(
        const Enabled& other //!< The other object
        ) const;

    //! Inequality operator
    bool operator!=(
        const Enabled& other //!< The other object
        ) const;

#ifdef BUILD_UT
    //! Ostream operator for Enabled object
    friend std::ostream& operator<<(
        std::ostream& os, //!< The ostream
        const Enabled& obj //!< The object
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
