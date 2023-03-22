// ======================================================================
// \title  Mode.hpp
// \author Auto-generated
// \brief  hpp file for Mode
//
// NOTE: this file was automatically generated
//
// ======================================================================

#ifndef Ref_Mode_HPP
#define Ref_Mode_HPP

#include "Fw/Types/String.hpp"
#include "Fw/Types/BasicTypes.hpp"
#include "Fw/Types/Serializable.hpp"

namespace Ref {
  //! 
  //! 控制模式
  //! 
  class Mode : public Fw::Serializable
  {
    public:
    // ----------------------------------------------------------------------
    // Types
    // ----------------------------------------------------------------------

    typedef enum {
    SAM_DAMP = 0, //!< SAM速率阻尼方式
    SAM_PITCH = 1, //!< SAM俯仰搜索方式
    SAM_ROLL = 2, //!< SAM滚动搜索方式
    SAM_CRUISE = 3, //!< SAM巡航方式
    NOCRAL = 4, //!< 不控
        } t;

    public:

    // ----------------------------------------------------------------------
    // Constants
    // ----------------------------------------------------------------------

    enum {
        SERIALIZED_SIZE = sizeof(I32)
        };

    //! Number of items in Mode enum
    static const U32 NUM_CONSTANTS = 5;

    public:

    // ----------------------------------------------------------------------
    // Constructors
    // ----------------------------------------------------------------------

    //! Construct Mode object with default initialization
    Mode();

    //! Construct Mode object and initialize its value
    Mode(
        const t e //!< The enum value
        );

    //! Copy constructor
    Mode(
        const Mode& other //!< The other object
        );

    public:

    // ----------------------------------------------------------------------
    // Operators
    // ----------------------------------------------------------------------

    //! Assignment operator
    Mode& operator=(
        const Mode& other //!< The other object
        );

    //! Assignment operator
    Mode& operator=(
        const t a //!< The enumerated constant to copy
        );

    //! Assignment operator
    Mode& operator=(
        const NATIVE_INT_TYPE a //!< The integer to copy
        );

    //! Assignment operator
    Mode& operator=(
        const NATIVE_UINT_TYPE a //!< The integer to copy
        );

    //! Equality operator
    bool operator==(
        const Mode& other //!< The other object
        ) const;

    //! Inequality operator
    bool operator!=(
        const Mode& other //!< The other object
        ) const;

#ifdef BUILD_UT
    //! Ostream operator for Mode object
    friend std::ostream& operator<<(
        std::ostream& os, //!< The ostream
        const Mode& obj //!< The object
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
