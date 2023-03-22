// ======================================================================
// \title  PacketRecvStatus.hpp
// \author Auto-generated
// \brief  hpp file for PacketRecvStatus
//
// NOTE: this file was automatically generated
//
// ======================================================================

#ifndef Ref_PacketRecvStatus_HPP
#define Ref_PacketRecvStatus_HPP

#include "Fw/Types/String.hpp"
#include "Fw/Types/BasicTypes.hpp"
#include "Fw/Types/Serializable.hpp"

namespace Ref {
  //! 
  //! Packet receive status
  //! 
  class PacketRecvStatus : public Fw::Serializable
  {
    public:
    // ----------------------------------------------------------------------
    // Types
    // ----------------------------------------------------------------------

    typedef enum {
    PACKET_STATE_NO_PACKETS = 0,
    PACKET_STATE_OK = 1,
    PACKET_STATE_ERRORS = 3, //!< Receiver has seen errors
        } t;

    public:

    // ----------------------------------------------------------------------
    // Constants
    // ----------------------------------------------------------------------

    enum {
        SERIALIZED_SIZE = sizeof(I32)
        };

    //! Number of items in PacketRecvStatus enum
    static const U32 NUM_CONSTANTS = 3;

    public:

    // ----------------------------------------------------------------------
    // Constructors
    // ----------------------------------------------------------------------

    //! Construct PacketRecvStatus object with default initialization
    PacketRecvStatus();

    //! Construct PacketRecvStatus object and initialize its value
    PacketRecvStatus(
        const t e //!< The enum value
        );

    //! Copy constructor
    PacketRecvStatus(
        const PacketRecvStatus& other //!< The other object
        );

    public:

    // ----------------------------------------------------------------------
    // Operators
    // ----------------------------------------------------------------------

    //! Assignment operator
    PacketRecvStatus& operator=(
        const PacketRecvStatus& other //!< The other object
        );

    //! Assignment operator
    PacketRecvStatus& operator=(
        const t a //!< The enumerated constant to copy
        );

    //! Assignment operator
    PacketRecvStatus& operator=(
        const NATIVE_INT_TYPE a //!< The integer to copy
        );

    //! Assignment operator
    PacketRecvStatus& operator=(
        const NATIVE_UINT_TYPE a //!< The integer to copy
        );

    //! Equality operator
    bool operator==(
        const PacketRecvStatus& other //!< The other object
        ) const;

    //! Inequality operator
    bool operator!=(
        const PacketRecvStatus& other //!< The other object
        ) const;

#ifdef BUILD_UT
    //! Ostream operator for PacketRecvStatus object
    friend std::ostream& operator<<(
        std::ostream& os, //!< The ostream
        const PacketRecvStatus& obj //!< The object
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
