// ======================================================================
// \title  SendBuff_ActiveState.hpp
// \author Auto-generated
// \brief  hpp file for SendBuff_ActiveState
//
// NOTE: this file was automatically generated
//
// ======================================================================

#ifndef Ref_SendBuff_ActiveState_HPP
#define Ref_SendBuff_ActiveState_HPP

#include "Fw/Types/String.hpp"
#include "Fw/Types/BasicTypes.hpp"
#include "Fw/Types/Serializable.hpp"

namespace Ref {
  //! 
  //! Active state
  //! 
  class SendBuff_ActiveState : public Fw::Serializable
  {
    public:
    // ----------------------------------------------------------------------
    // Types
    // ----------------------------------------------------------------------

    typedef enum {
    SEND_IDLE = 0,
    SEND_ACTIVE = 1,
        } t;

    public:

    // ----------------------------------------------------------------------
    // Constants
    // ----------------------------------------------------------------------

    enum {
        SERIALIZED_SIZE = sizeof(I32)
        };

    //! Number of items in SendBuff_ActiveState enum
    static const U32 NUM_CONSTANTS = 2;

    public:

    // ----------------------------------------------------------------------
    // Constructors
    // ----------------------------------------------------------------------

    //! Construct SendBuff_ActiveState object with default initialization
    SendBuff_ActiveState();

    //! Construct SendBuff_ActiveState object and initialize its value
    SendBuff_ActiveState(
        const t e //!< The enum value
        );

    //! Copy constructor
    SendBuff_ActiveState(
        const SendBuff_ActiveState& other //!< The other object
        );

    public:

    // ----------------------------------------------------------------------
    // Operators
    // ----------------------------------------------------------------------

    //! Assignment operator
    SendBuff_ActiveState& operator=(
        const SendBuff_ActiveState& other //!< The other object
        );

    //! Assignment operator
    SendBuff_ActiveState& operator=(
        const t a //!< The enumerated constant to copy
        );

    //! Assignment operator
    SendBuff_ActiveState& operator=(
        const NATIVE_INT_TYPE a //!< The integer to copy
        );

    //! Assignment operator
    SendBuff_ActiveState& operator=(
        const NATIVE_UINT_TYPE a //!< The integer to copy
        );

    //! Equality operator
    bool operator==(
        const SendBuff_ActiveState& other //!< The other object
        ) const;

    //! Inequality operator
    bool operator!=(
        const SendBuff_ActiveState& other //!< The other object
        ) const;

#ifdef BUILD_UT
    //! Ostream operator for SendBuff_ActiveState object
    friend std::ostream& operator<<(
        std::ostream& os, //!< The ostream
        const SendBuff_ActiveState& obj //!< The object
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
