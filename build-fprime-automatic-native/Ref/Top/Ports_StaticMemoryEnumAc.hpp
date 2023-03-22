// ======================================================================
// \title  Ports_StaticMemory.hpp
// \author Auto-generated
// \brief  hpp file for Ports_StaticMemory
//
// NOTE: this file was automatically generated
//
// ======================================================================

#ifndef Ref_Ports_StaticMemory_HPP
#define Ref_Ports_StaticMemory_HPP

#include "Fw/Types/String.hpp"
#include "Fw/Types/BasicTypes.hpp"
#include "Fw/Types/Serializable.hpp"

namespace Ref {
  class Ports_StaticMemory : public Fw::Serializable
  {
    public:
    // ----------------------------------------------------------------------
    // Types
    // ----------------------------------------------------------------------

    typedef enum {
    downlink = 0,
    uplink = 1,
        } t;

    public:

    // ----------------------------------------------------------------------
    // Constants
    // ----------------------------------------------------------------------

    enum {
        SERIALIZED_SIZE = sizeof(I32)
        };

    //! Number of items in Ports_StaticMemory enum
    static const U32 NUM_CONSTANTS = 2;

    public:

    // ----------------------------------------------------------------------
    // Constructors
    // ----------------------------------------------------------------------

    //! Construct Ports_StaticMemory object with default initialization
    Ports_StaticMemory();

    //! Construct Ports_StaticMemory object and initialize its value
    Ports_StaticMemory(
        const t e //!< The enum value
        );

    //! Copy constructor
    Ports_StaticMemory(
        const Ports_StaticMemory& other //!< The other object
        );

    public:

    // ----------------------------------------------------------------------
    // Operators
    // ----------------------------------------------------------------------

    //! Assignment operator
    Ports_StaticMemory& operator=(
        const Ports_StaticMemory& other //!< The other object
        );

    //! Assignment operator
    Ports_StaticMemory& operator=(
        const t a //!< The enumerated constant to copy
        );

    //! Assignment operator
    Ports_StaticMemory& operator=(
        const NATIVE_INT_TYPE a //!< The integer to copy
        );

    //! Assignment operator
    Ports_StaticMemory& operator=(
        const NATIVE_UINT_TYPE a //!< The integer to copy
        );

    //! Equality operator
    bool operator==(
        const Ports_StaticMemory& other //!< The other object
        ) const;

    //! Inequality operator
    bool operator!=(
        const Ports_StaticMemory& other //!< The other object
        ) const;

#ifdef BUILD_UT
    //! Ostream operator for Ports_StaticMemory object
    friend std::ostream& operator<<(
        std::ostream& os, //!< The ostream
        const Ports_StaticMemory& obj //!< The object
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
