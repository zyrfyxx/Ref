// ======================================================================
// \title  CmdSequencer_SeqMode.hpp
// \author Auto-generated
// \brief  hpp file for CmdSequencer_SeqMode
//
// NOTE: this file was automatically generated
//
// ======================================================================

#ifndef Svc_CmdSequencer_SeqMode_HPP
#define Svc_CmdSequencer_SeqMode_HPP

#include "Fw/Types/String.hpp"
#include "Fw/Types/BasicTypes.hpp"
#include "Fw/Types/Serializable.hpp"

namespace Svc {
  //! 
  //! The sequencer mode
  //! 
  class CmdSequencer_SeqMode : public Fw::Serializable
  {
    public:
    // ----------------------------------------------------------------------
    // Types
    // ----------------------------------------------------------------------

    typedef enum {
    STEP = 0,
    AUTO = 1,
        } t;

    public:

    // ----------------------------------------------------------------------
    // Constants
    // ----------------------------------------------------------------------

    enum {
        SERIALIZED_SIZE = sizeof(I32)
        };

    //! Number of items in CmdSequencer_SeqMode enum
    static const U32 NUM_CONSTANTS = 2;

    public:

    // ----------------------------------------------------------------------
    // Constructors
    // ----------------------------------------------------------------------

    //! Construct CmdSequencer_SeqMode object with default initialization
    CmdSequencer_SeqMode();

    //! Construct CmdSequencer_SeqMode object and initialize its value
    CmdSequencer_SeqMode(
        const t e //!< The enum value
        );

    //! Copy constructor
    CmdSequencer_SeqMode(
        const CmdSequencer_SeqMode& other //!< The other object
        );

    public:

    // ----------------------------------------------------------------------
    // Operators
    // ----------------------------------------------------------------------

    //! Assignment operator
    CmdSequencer_SeqMode& operator=(
        const CmdSequencer_SeqMode& other //!< The other object
        );

    //! Assignment operator
    CmdSequencer_SeqMode& operator=(
        const t a //!< The enumerated constant to copy
        );

    //! Assignment operator
    CmdSequencer_SeqMode& operator=(
        const NATIVE_INT_TYPE a //!< The integer to copy
        );

    //! Assignment operator
    CmdSequencer_SeqMode& operator=(
        const NATIVE_UINT_TYPE a //!< The integer to copy
        );

    //! Equality operator
    bool operator==(
        const CmdSequencer_SeqMode& other //!< The other object
        ) const;

    //! Inequality operator
    bool operator!=(
        const CmdSequencer_SeqMode& other //!< The other object
        ) const;

#ifdef BUILD_UT
    //! Ostream operator for CmdSequencer_SeqMode object
    friend std::ostream& operator<<(
        std::ostream& os, //!< The ostream
        const CmdSequencer_SeqMode& obj //!< The object
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
