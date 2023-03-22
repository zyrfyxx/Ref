/*
 * SignalPair.hpp
 *
 *  Created on: Monday, 20 March 2023
 *  Author:     kokaze
 *
 */
#ifndef SIGNALPAIR_HPP_
#define SIGNALPAIR_HPP_

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

class SignalPair : public Fw::Serializable {


public:

    enum {
        SERIALIZED_SIZE =
        sizeof(F32) +
        sizeof(F32)
    }; //!< serializable size of SignalPair

    SignalPair(); //!< Default constructor
    SignalPair(const SignalPair* src); //!< pointer copy constructor
    SignalPair(const SignalPair& src); //!< reference copy constructor
    SignalPair(F32 time, F32 value); //!< constructor with arguments
    SignalPair& operator=(const SignalPair& src); //!< equal operator
    bool operator==(const SignalPair& src) const; //!< equality operator
#ifdef BUILD_UT
    // to support GoogleTest framework in unit tests
    friend std::ostream& operator<<(std::ostream& os, const SignalPair& obj);
#endif

    void set(F32 time, F32 value); //!< set values

    F32 gettime() const; //!< get member time
    F32 getvalue() const; //!< get member value

    void settime(F32 val); //!< set member time
    void setvalue(F32 val); //!< set member value


    Fw::SerializeStatus serialize(Fw::SerializeBufferBase& buffer) const; //!< serialization function
    Fw::SerializeStatus deserialize(Fw::SerializeBufferBase& buffer); //!< deserialization function
#if FW_SERIALIZABLE_TO_STRING || BUILD_UT
    void toString(Fw::StringBase& text) const; //!< generate text from serializable
#endif
protected:

    enum {
        TYPE_ID = 0xE45408EA //!< type id
    };

    F32 m_time; //<! time - 
    F32 m_value; //<! value - 
private:

};
} // end namespace Ref
#endif /* SIGNALPAIR_HPP_ */

