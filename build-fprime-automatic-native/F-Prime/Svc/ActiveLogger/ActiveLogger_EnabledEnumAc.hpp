// ======================================================================
// \title  ActiveLogger_Enabled.hpp
// \author Auto-generated
// \brief  hpp file for ActiveLogger_Enabled
//
// NOTE: this file was automatically generated
//
// ======================================================================

#ifndef Svc_ActiveLogger_Enabled_HPP
#define Svc_ActiveLogger_Enabled_HPP

#include "Fw/Types/String.hpp"
#include "Fw/Types/BasicTypes.hpp"
#include "Fw/Types/Serializable.hpp"

namespace Svc {
  //! 
  //! Enabled and disabled state
  //! 
  class ActiveLogger_Enabled : public Fw::Serializable
  {
    public:
    // ----------------------------------------------------------------------
    // Types
    // ----------------------------------------------------------------------

    typedef enum {
    ENABLED = 0, //!< Enabled state
    DISABLED = 1, //!< Disabled state
        } t;

    public:

    // ----------------------------------------------------------------------
    // Constants
    // ----------------------------------------------------------------------

    enum {
        SERIALIZED_SIZE = sizeof(I32)
        };

    //! Number of items in ActiveLogger_Enabled enum
    static const U32 NUM_CONSTANTS = 2;

    public:

    // ----------------------------------------------------------------------
    // Constructors
    // ----------------------------------------------------------------------

    //! Construct ActiveLogger_Enabled object with default initialization
    ActiveLogger_Enabled();

    //! Construct ActiveLogger_Enabled object and initialize its value
    ActiveLogger_Enabled(
        const t e //!< The enum value
        );

    //! Copy constructor
    ActiveLogger_Enabled(
        const ActiveLogger_Enabled& other //!< The other object
        );

    public:

    // ----------------------------------------------------------------------
    // Operators
    // ----------------------------------------------------------------------

    //! Assignment operator
    ActiveLogger_Enabled& operator=(
        const ActiveLogger_Enabled& other //!< The other object
        );

    //! Assignment operator
    ActiveLogger_Enabled& operator=(
        const t a //!< The enumerated constant to copy
        );

    //! Assignment operator
    ActiveLogger_Enabled& operator=(
        const NATIVE_INT_TYPE a //!< The integer to copy
        );

    //! Assignment operator
    ActiveLogger_Enabled& operator=(
        const NATIVE_UINT_TYPE a //!< The integer to copy
        );

    //! Equality operator
    bool operator==(
        const ActiveLogger_Enabled& other //!< The other object
        ) const;

    //! Inequality operator
    bool operator!=(
        const ActiveLogger_Enabled& other //!< The other object
        ) const;

#ifdef BUILD_UT
    //! Ostream operator for ActiveLogger_Enabled object
    friend std::ostream& operator<<(
        std::ostream& os, //!< The ostream
        const ActiveLogger_Enabled& obj //!< The object
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
