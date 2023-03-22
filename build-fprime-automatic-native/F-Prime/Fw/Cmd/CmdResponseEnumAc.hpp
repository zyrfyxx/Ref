// ======================================================================
// \title  CmdResponse.hpp
// \author Auto-generated
// \brief  hpp file for CmdResponse
//
// NOTE: this file was automatically generated
//
// ======================================================================

#ifndef Fw_CmdResponse_HPP
#define Fw_CmdResponse_HPP

#include "Fw/Types/String.hpp"
#include "Fw/Types/BasicTypes.hpp"
#include "Fw/Types/Serializable.hpp"

namespace Fw {
  //! 
  //! Enum representing a command response
  //! 
  class CmdResponse : public Fw::Serializable
  {
    public:
    // ----------------------------------------------------------------------
    // Types
    // ----------------------------------------------------------------------

    typedef enum {
    OK = 0, //!< Command successfully executed
    INVALID_OPCODE = 1, //!< Invalid opcode dispatched
    VALIDATION_ERROR = 2, //!< Command failed validation
    FORMAT_ERROR = 3, //!< Command failed to deserialize
    EXECUTION_ERROR = 4, //!< Command had execution error
    BUSY = 5, //!< Component busy
        } t;

    public:

    // ----------------------------------------------------------------------
    // Constants
    // ----------------------------------------------------------------------

    enum {
        SERIALIZED_SIZE = sizeof(I32)
        };

    //! Number of items in CmdResponse enum
    static const U32 NUM_CONSTANTS = 6;

    public:

    // ----------------------------------------------------------------------
    // Constructors
    // ----------------------------------------------------------------------

    //! Construct CmdResponse object with default initialization
    CmdResponse();

    //! Construct CmdResponse object and initialize its value
    CmdResponse(
        const t e //!< The enum value
        );

    //! Copy constructor
    CmdResponse(
        const CmdResponse& other //!< The other object
        );

    public:

    // ----------------------------------------------------------------------
    // Operators
    // ----------------------------------------------------------------------

    //! Assignment operator
    CmdResponse& operator=(
        const CmdResponse& other //!< The other object
        );

    //! Assignment operator
    CmdResponse& operator=(
        const t a //!< The enumerated constant to copy
        );

    //! Assignment operator
    CmdResponse& operator=(
        const NATIVE_INT_TYPE a //!< The integer to copy
        );

    //! Assignment operator
    CmdResponse& operator=(
        const NATIVE_UINT_TYPE a //!< The integer to copy
        );

    //! Equality operator
    bool operator==(
        const CmdResponse& other //!< The other object
        ) const;

    //! Inequality operator
    bool operator!=(
        const CmdResponse& other //!< The other object
        ) const;

#ifdef BUILD_UT
    //! Ostream operator for CmdResponse object
    friend std::ostream& operator<<(
        std::ostream& os, //!< The ostream
        const CmdResponse& obj //!< The object
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
