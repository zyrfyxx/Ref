// ======================================================================
// \title  SendStatus.hpp
// \author Auto-generated
// \brief  hpp file for SendStatus
//
// NOTE: this file was automatically generated
//
// ======================================================================

#ifndef Drv_SendStatus_HPP
#define Drv_SendStatus_HPP

#include "Fw/Types/String.hpp"
#include "Fw/Types/BasicTypes.hpp"
#include "Fw/Types/Serializable.hpp"

namespace Drv {
  class SendStatus : public Fw::Serializable
  {
    public:
    // ----------------------------------------------------------------------
    // Types
    // ----------------------------------------------------------------------

    typedef enum {
    SEND_OK = 0, //!< Send worked as expected
    SEND_RETRY = 1, //!< Data send should be retried
    SEND_ERROR = 2, //!< Send error occurred retrying may succeed
        } t;

    public:

    // ----------------------------------------------------------------------
    // Constants
    // ----------------------------------------------------------------------

    enum {
        SERIALIZED_SIZE = sizeof(I32)
        };

    //! Number of items in SendStatus enum
    static const U32 NUM_CONSTANTS = 3;

    public:

    // ----------------------------------------------------------------------
    // Constructors
    // ----------------------------------------------------------------------

    //! Construct SendStatus object with default initialization
    SendStatus();

    //! Construct SendStatus object and initialize its value
    SendStatus(
        const t e //!< The enum value
        );

    //! Copy constructor
    SendStatus(
        const SendStatus& other //!< The other object
        );

    public:

    // ----------------------------------------------------------------------
    // Operators
    // ----------------------------------------------------------------------

    //! Assignment operator
    SendStatus& operator=(
        const SendStatus& other //!< The other object
        );

    //! Assignment operator
    SendStatus& operator=(
        const t a //!< The enumerated constant to copy
        );

    //! Assignment operator
    SendStatus& operator=(
        const NATIVE_INT_TYPE a //!< The integer to copy
        );

    //! Assignment operator
    SendStatus& operator=(
        const NATIVE_UINT_TYPE a //!< The integer to copy
        );

    //! Equality operator
    bool operator==(
        const SendStatus& other //!< The other object
        ) const;

    //! Inequality operator
    bool operator!=(
        const SendStatus& other //!< The other object
        ) const;

#ifdef BUILD_UT
    //! Ostream operator for SendStatus object
    friend std::ostream& operator<<(
        std::ostream& os, //!< The ostream
        const SendStatus& obj //!< The object
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
