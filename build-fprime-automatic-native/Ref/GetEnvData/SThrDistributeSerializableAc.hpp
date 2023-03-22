/*
 * SThrDistribute.hpp
 *
 *  Created on: Monday, 20 March 2023
 *  Author:     kokaze
 *
 */
#ifndef STHRDISTRIBUTE_HPP_
#define STHRDISTRIBUTE_HPP_

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

class SThrDistribute : public Fw::Serializable {


public:

    enum {
        SERIALIZED_SIZE =
        sizeof(U16) +
        sizeof(U8) +
        sizeof(U8)*2
    }; //!< serializable size of SThrDistribute

    SThrDistribute(); //!< Default constructor
    SThrDistribute(const SThrDistribute* src); //!< pointer copy constructor
    SThrDistribute(const SThrDistribute& src); //!< reference copy constructor
    SThrDistribute(U16 flagABChoose, U8 wPulse, const U8* stateFlag, NATIVE_INT_TYPE stateFlagSize); //!< constructor with arguments
    SThrDistribute(U16 flagABChoose, U8 wPulse, const U8 stateFlag); //!< constructor with arguments with scalars for array arguments
    SThrDistribute& operator=(const SThrDistribute& src); //!< equal operator
    bool operator==(const SThrDistribute& src) const; //!< equality operator
#ifdef BUILD_UT
    // to support GoogleTest framework in unit tests
    friend std::ostream& operator<<(std::ostream& os, const SThrDistribute& obj);
#endif

    void set(U16 flagABChoose, U8 wPulse, const U8* stateFlag, NATIVE_INT_TYPE stateFlagSize); //!< set values

    U16 getflagABChoose() const; //!< get member flagABChoose
    U8 getwPulse() const; //!< get member wPulse
    const U8* getstateFlag(NATIVE_INT_TYPE& size) const; //!< get member stateFlag

    void setflagABChoose(U16 val); //!< set member flagABChoose
    void setwPulse(U8 val); //!< set member wPulse
    void setstateFlag(const U8* val, NATIVE_INT_TYPE size); //!< set member stateFlag


    Fw::SerializeStatus serialize(Fw::SerializeBufferBase& buffer) const; //!< serialization function
    Fw::SerializeStatus deserialize(Fw::SerializeBufferBase& buffer); //!< deserialization function
#if FW_SERIALIZABLE_TO_STRING || BUILD_UT
    void toString(Fw::StringBase& text) const; //!< generate text from serializable
#endif
protected:

    enum {
        TYPE_ID = 0x5E7B0A81 //!< type id
    };

    U16 m_flagABChoose; //<! flagABChoose - 
    U8 m_wPulse; //<! wPulse - 
    U8 m_stateFlag[2]; //<! stateFlag - 

private:

};
} // end namespace Ref
#endif /* STHRDISTRIBUTE_HPP_ */

