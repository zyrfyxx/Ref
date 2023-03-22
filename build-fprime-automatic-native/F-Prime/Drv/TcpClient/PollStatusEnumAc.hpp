// ======================================================================
// \title  PollStatus.hpp
// \author Auto-generated
// \brief  hpp file for PollStatus
//
// NOTE: this file was automatically generated
//
// ======================================================================

#ifndef Drv_PollStatus_HPP
#define Drv_PollStatus_HPP

#include "Fw/Types/String.hpp"
#include "Fw/Types/BasicTypes.hpp"
#include "Fw/Types/Serializable.hpp"

namespace Drv {
  class PollStatus : public Fw::Serializable
  {
    public:
    // ----------------------------------------------------------------------
    // Types
    // ----------------------------------------------------------------------

    typedef enum {
    POLL_OK = 0, //!< Poll successfully received data
    POLL_RETRY = 1, //!< No data available, retry later
    POLL_ERROR = 2, //!< Error received when polling
        } t;

    public:

    // ----------------------------------------------------------------------
    // Constants
    // ----------------------------------------------------------------------

    enum {
        SERIALIZED_SIZE = sizeof(I32)
        };

    //! Number of items in PollStatus enum
    static const U32 NUM_CONSTANTS = 3;

    public:

    // ----------------------------------------------------------------------
    // Constructors
    // ----------------------------------------------------------------------

    //! Construct PollStatus object with default initialization
    PollStatus();

    //! Construct PollStatus object and initialize its value
    PollStatus(
        const t e //!< The enum value
        );

    //! Copy constructor
    PollStatus(
        const PollStatus& other //!< The other object
        );

    public:

    // ----------------------------------------------------------------------
    // Operators
    // ----------------------------------------------------------------------

    //! Assignment operator
    PollStatus& operator=(
        const PollStatus& other //!< The other object
        );

    //! Assignment operator
    PollStatus& operator=(
        const t a //!< The enumerated constant to copy
        );

    //! Assignment operator
    PollStatus& operator=(
        const NATIVE_INT_TYPE a //!< The integer to copy
        );

    //! Assignment operator
    PollStatus& operator=(
        const NATIVE_UINT_TYPE a //!< The integer to copy
        );

    //! Equality operator
    bool operator==(
        const PollStatus& other //!< The other object
        ) const;

    //! Inequality operator
    bool operator!=(
        const PollStatus& other //!< The other object
        ) const;

#ifdef BUILD_UT
    //! Ostream operator for PollStatus object
    friend std::ostream& operator<<(
        std::ostream& os, //!< The ostream
        const PollStatus& obj //!< The object
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
