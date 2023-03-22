/*
 * Actions.hpp
 *
 *  Created on: Monday, 20 March 2023
 *  Author:     kokaze
 *
 */
#ifndef ACTIONS_HPP_
#define ACTIONS_HPP_

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

class Actions : public Fw::Serializable {


public:

    enum {
        SERIALIZED_SIZE =
        sizeof(U8) +
        sizeof(U8)
    }; //!< serializable size of Actions

    Actions(); //!< Default constructor
    Actions(const Actions* src); //!< pointer copy constructor
    Actions(const Actions& src); //!< reference copy constructor
    Actions(U8 thrDistribute, U8 protectFromSunlight); //!< constructor with arguments
    Actions& operator=(const Actions& src); //!< equal operator
    bool operator==(const Actions& src) const; //!< equality operator
#ifdef BUILD_UT
    // to support GoogleTest framework in unit tests
    friend std::ostream& operator<<(std::ostream& os, const Actions& obj);
#endif

    void set(U8 thrDistribute, U8 protectFromSunlight); //!< set values

    U8 getthrDistribute() const; //!< get member thrDistribute
    U8 getprotectFromSunlight() const; //!< get member protectFromSunlight

    void setthrDistribute(U8 val); //!< set member thrDistribute
    void setprotectFromSunlight(U8 val); //!< set member protectFromSunlight


    Fw::SerializeStatus serialize(Fw::SerializeBufferBase& buffer) const; //!< serialization function
    Fw::SerializeStatus deserialize(Fw::SerializeBufferBase& buffer); //!< deserialization function
#if FW_SERIALIZABLE_TO_STRING || BUILD_UT
    void toString(Fw::StringBase& text) const; //!< generate text from serializable
#endif
protected:

    enum {
        TYPE_ID = 0xBB6DBA93 //!< type id
    };

    U8 m_thrDistribute; //<! thrDistribute - 
    U8 m_protectFromSunlight; //<! protectFromSunlight - 
private:

};
} // end namespace Ref
#endif /* ACTIONS_HPP_ */

