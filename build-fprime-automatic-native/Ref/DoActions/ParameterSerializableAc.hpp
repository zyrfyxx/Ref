/*
 * Parameter.hpp
 *
 *  Created on: Monday, 20 March 2023
 *  Author:     kokaze
 *
 */
#ifndef PARAMETER_HPP_
#define PARAMETER_HPP_

#include <Fw/Types/BasicTypes.hpp>
#include <Fw/Types/Serializable.hpp>
#if FW_SERIALIZABLE_TO_STRING
#include <Fw/Types/StringType.hpp>
#include <cstdio> // snprintf
#ifdef BUILD_UT
#include <iostream>
#include <Fw/Types/String.hpp>
#endif
#endif

namespace Ref {

class Parameter : public Fw::Serializable {


public:

    enum {
        SERIALIZED_SIZE =
        sizeof(U8)
    }; //!< serializable size of Parameter

    Parameter(); //!< Default constructor
    Parameter(const Parameter* src); //!< pointer copy constructor
    Parameter(const Parameter& src); //!< reference copy constructor
    Parameter(U8 wPulse); //!< constructor with arguments
    Parameter& operator=(const Parameter& src); //!< equal operator
    bool operator==(const Parameter& src) const; //!< equality operator
#ifdef BUILD_UT
    // to support GoogleTest framework in unit tests
    friend std::ostream& operator<<(std::ostream& os, const Parameter& obj);
#endif

    void set(U8 wPulse); //!< set values

    U8 getwPulse() const; //!< get member wPulse

    void setwPulse(U8 val); //!< set member wPulse


    Fw::SerializeStatus serialize(Fw::SerializeBufferBase& buffer) const; //!< serialization function
    Fw::SerializeStatus deserialize(Fw::SerializeBufferBase& buffer); //!< deserialization function
#if FW_SERIALIZABLE_TO_STRING || BUILD_UT
    void toString(Fw::StringBase& text) const; //!< generate text from serializable
#endif
protected:

    enum {
        TYPE_ID = 0x24693F6C //!< type id
    };

    U8 m_wPulse; //<! wPulse - 
private:

};
} // end namespace Ref
#endif /* PARAMETER_HPP_ */

