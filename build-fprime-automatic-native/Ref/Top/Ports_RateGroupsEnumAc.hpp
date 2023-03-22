// ======================================================================
// \title  Ports_RateGroups.hpp
// \author Auto-generated
// \brief  hpp file for Ports_RateGroups
//
// NOTE: this file was automatically generated
//
// ======================================================================

#ifndef Ref_Ports_RateGroups_HPP
#define Ref_Ports_RateGroups_HPP

#include "Fw/Types/String.hpp"
#include "Fw/Types/BasicTypes.hpp"
#include "Fw/Types/Serializable.hpp"

namespace Ref {
  class Ports_RateGroups : public Fw::Serializable
  {
    public:
    // ----------------------------------------------------------------------
    // Types
    // ----------------------------------------------------------------------

    typedef enum {
    rateGroup1 = 0,
    rateGroup2 = 1,
    rateGroup3 = 2,
        } t;

    public:

    // ----------------------------------------------------------------------
    // Constants
    // ----------------------------------------------------------------------

    enum {
        SERIALIZED_SIZE = sizeof(I32)
        };

    //! Number of items in Ports_RateGroups enum
    static const U32 NUM_CONSTANTS = 3;

    public:

    // ----------------------------------------------------------------------
    // Constructors
    // ----------------------------------------------------------------------

    //! Construct Ports_RateGroups object with default initialization
    Ports_RateGroups();

    //! Construct Ports_RateGroups object and initialize its value
    Ports_RateGroups(
        const t e //!< The enum value
        );

    //! Copy constructor
    Ports_RateGroups(
        const Ports_RateGroups& other //!< The other object
        );

    public:

    // ----------------------------------------------------------------------
    // Operators
    // ----------------------------------------------------------------------

    //! Assignment operator
    Ports_RateGroups& operator=(
        const Ports_RateGroups& other //!< The other object
        );

    //! Assignment operator
    Ports_RateGroups& operator=(
        const t a //!< The enumerated constant to copy
        );

    //! Assignment operator
    Ports_RateGroups& operator=(
        const NATIVE_INT_TYPE a //!< The integer to copy
        );

    //! Assignment operator
    Ports_RateGroups& operator=(
        const NATIVE_UINT_TYPE a //!< The integer to copy
        );

    //! Equality operator
    bool operator==(
        const Ports_RateGroups& other //!< The other object
        ) const;

    //! Inequality operator
    bool operator!=(
        const Ports_RateGroups& other //!< The other object
        ) const;

#ifdef BUILD_UT
    //! Ostream operator for Ports_RateGroups object
    friend std::ostream& operator<<(
        std::ostream& os, //!< The ostream
        const Ports_RateGroups& obj //!< The object
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
