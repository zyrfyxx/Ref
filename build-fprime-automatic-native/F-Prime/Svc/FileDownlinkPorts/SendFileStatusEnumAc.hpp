// ======================================================================
// \title  SendFileStatus.hpp
// \author Auto-generated
// \brief  hpp file for SendFileStatus
//
// NOTE: this file was automatically generated
//
// ======================================================================

#ifndef Svc_SendFileStatus_HPP
#define Svc_SendFileStatus_HPP

#include "Fw/Types/String.hpp"
#include "Fw/Types/BasicTypes.hpp"
#include "Fw/Types/Serializable.hpp"

namespace Svc {
  //! 
  //! Send file status enum
  //! 
  class SendFileStatus : public Fw::Serializable
  {
    public:
    // ----------------------------------------------------------------------
    // Types
    // ----------------------------------------------------------------------

    typedef enum {
    STATUS_OK = 0,
    STATUS_ERROR = 1,
    STATUS_INVALID = 2,
    STATUS_BUSY = 3,
        } t;

    public:

    // ----------------------------------------------------------------------
    // Constants
    // ----------------------------------------------------------------------

    enum {
        SERIALIZED_SIZE = sizeof(I32)
        };

    //! Number of items in SendFileStatus enum
    static const U32 NUM_CONSTANTS = 4;

    public:

    // ----------------------------------------------------------------------
    // Constructors
    // ----------------------------------------------------------------------

    //! Construct SendFileStatus object with default initialization
    SendFileStatus();

    //! Construct SendFileStatus object and initialize its value
    SendFileStatus(
        const t e //!< The enum value
        );

    //! Copy constructor
    SendFileStatus(
        const SendFileStatus& other //!< The other object
        );

    public:

    // ----------------------------------------------------------------------
    // Operators
    // ----------------------------------------------------------------------

    //! Assignment operator
    SendFileStatus& operator=(
        const SendFileStatus& other //!< The other object
        );

    //! Assignment operator
    SendFileStatus& operator=(
        const t a //!< The enumerated constant to copy
        );

    //! Assignment operator
    SendFileStatus& operator=(
        const NATIVE_INT_TYPE a //!< The integer to copy
        );

    //! Assignment operator
    SendFileStatus& operator=(
        const NATIVE_UINT_TYPE a //!< The integer to copy
        );

    //! Equality operator
    bool operator==(
        const SendFileStatus& other //!< The other object
        ) const;

    //! Inequality operator
    bool operator!=(
        const SendFileStatus& other //!< The other object
        ) const;

#ifdef BUILD_UT
    //! Ostream operator for SendFileStatus object
    friend std::ostream& operator<<(
        std::ostream& os, //!< The ostream
        const SendFileStatus& obj //!< The object
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
