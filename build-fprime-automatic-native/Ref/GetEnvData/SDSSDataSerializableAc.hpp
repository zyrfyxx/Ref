/*
 * SDSSData.hpp
 *
 *  Created on: Monday, 20 March 2023
 *  Author:     kokaze
 *
 */
#ifndef SDSSDATA_HPP_
#define SDSSDATA_HPP_

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

class SDSSData : public Fw::Serializable {


public:

    enum {
        SERIALIZED_SIZE =
        sizeof(U32) +
        sizeof(U32) +
        sizeof(F32) +
        sizeof(F32) +
        sizeof(U32)
    }; //!< serializable size of SDSSData

    SDSSData(); //!< Default constructor
    SDSSData(const SDSSData* src); //!< pointer copy constructor
    SDSSData(const SDSSData& src); //!< reference copy constructor
    SDSSData(U32 stateFlag_A, U32 stateFlag_B, F32 royaw, F32 piyaw, U32 flgSP); //!< constructor with arguments
    SDSSData& operator=(const SDSSData& src); //!< equal operator
    bool operator==(const SDSSData& src) const; //!< equality operator
#ifdef BUILD_UT
    // to support GoogleTest framework in unit tests
    friend std::ostream& operator<<(std::ostream& os, const SDSSData& obj);
#endif

    void set(U32 stateFlag_A, U32 stateFlag_B, F32 royaw, F32 piyaw, U32 flgSP); //!< set values

    U32 getstateFlag_A() const; //!< get member stateFlag_A
    U32 getstateFlag_B() const; //!< get member stateFlag_B
    F32 getroyaw() const; //!< get member royaw
    F32 getpiyaw() const; //!< get member piyaw
    U32 getflgSP() const; //!< get member flgSP

    void setstateFlag_A(U32 val); //!< set member stateFlag_A
    void setstateFlag_B(U32 val); //!< set member stateFlag_B
    void setroyaw(F32 val); //!< set member royaw
    void setpiyaw(F32 val); //!< set member piyaw
    void setflgSP(U32 val); //!< set member flgSP


    Fw::SerializeStatus serialize(Fw::SerializeBufferBase& buffer) const; //!< serialization function
    Fw::SerializeStatus deserialize(Fw::SerializeBufferBase& buffer); //!< deserialization function
#if FW_SERIALIZABLE_TO_STRING || BUILD_UT
    void toString(Fw::StringBase& text) const; //!< generate text from serializable
#endif
protected:

    enum {
        TYPE_ID = 0xD9638EAA //!< type id
    };

    U32 m_stateFlag_A; //<! stateFlag_A - 主份加电
    U32 m_stateFlag_B; //<! stateFlag_B - 备份加电
    F32 m_royaw; //<! royaw - 滚动角
    F32 m_piyaw; //<! piyaw - 俯仰校
    U32 m_flgSP; //<! flgSP - 太阳可见标志
private:

};
} // end namespace Ref
#endif /* SDSSDATA_HPP_ */

