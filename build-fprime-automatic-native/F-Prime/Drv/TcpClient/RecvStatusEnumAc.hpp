// ======================================================================
// \title  RecvStatus.hpp
// \author Auto-generated
// \brief  hpp file for RecvStatus
//
// NOTE: this file was automatically generated
//
// ======================================================================

#ifndef Drv_RecvStatus_HPP
#define Drv_RecvStatus_HPP

#include "Fw/Types/String.hpp"
#include "Fw/Types/BasicTypes.hpp"
#include "Fw/Types/Serializable.hpp"

namespace Drv {
  class RecvStatus : public Fw::Serializable
  {
    public:
    // ----------------------------------------------------------------------
    // Types
    // ----------------------------------------------------------------------

    typedef enum {
    RECV_OK = 0, //!< Receive worked as expected
    RECV_ERROR = 1, //!< Receive error occurred retrying may succeed
        } t;

    public:

    // ----------------------------------------------------------------------
    // Constants
    // ----------------------------------------------------------------------

    enum {
        SERIALIZED_SIZE = sizeof(I32)
        };

    //! Number of items in RecvStatus enum
    static const U32 NUM_CONSTANTS = 2;

    public:

    // ----------------------------------------------------------------------
    // Constructors
    // ----------------------------------------------------------------------

    //! Construct RecvStatus object with default initialization
    RecvStatus();

    //! Construct RecvStatus object and initialize its value
    RecvStatus(
        const t e //!< The enum value
        );

    //! Copy constructor
    RecvStatus(
        const RecvStatus& other //!< The other object
        );

    public:

    // ----------------------------------------------------------------------
    // Operators
    // ----------------------------------------------------------------------

    //! Assignment operator
    RecvStatus& operator=(
        const RecvStatus& other //!< The other object
        );

    //! Assignment operator
    RecvStatus& operator=(
        const t a //!< The enumerated constant to copy
        );

    //! Assignment operator
    RecvStatus& operator=(
        const NATIVE_INT_TYPE a //!< The integer to copy
        );

    //! Assignment operator
    RecvStatus& operator=(
        const NATIVE_UINT_TYPE a //!< The integer to copy
        );

    //! Equality operator
    bool operator==(
        const RecvStatus& other //!< The other object
        ) const;

    //! Inequality operator
    bool operator!=(
        const RecvStatus& other //!< The other object
        ) const;

#ifdef BUILD_UT
    //! Ostream operator for RecvStatus object
    friend std::ostream& operator<<(
        std::ostream& os, //!< The ostream
        const RecvStatus& obj //!< The object
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
