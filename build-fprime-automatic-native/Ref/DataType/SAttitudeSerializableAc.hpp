/*
 * SAttitude.hpp
 *
 *  Created on: Monday, 20 March 2023
 *  Author:     kokaze
 *
 */
#ifndef SATTITUDE_HPP_
#define SATTITUDE_HPP_

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

class SAttitude : public Fw::Serializable {


public:

    enum {
        SERIALIZED_SIZE =
        sizeof(F32)*3 +
        sizeof(F32)*3
    }; //!< serializable size of SAttitude

    SAttitude(); //!< Default constructor
    SAttitude(const SAttitude* src); //!< pointer copy constructor
    SAttitude(const SAttitude& src); //!< reference copy constructor
    SAttitude(const F32* angle, NATIVE_INT_TYPE angleSize, const F32* rate, NATIVE_INT_TYPE rateSize); //!< constructor with arguments
    SAttitude(const F32 angle, const F32 rate); //!< constructor with arguments with scalars for array arguments
    SAttitude& operator=(const SAttitude& src); //!< equal operator
    bool operator==(const SAttitude& src) const; //!< equality operator
#ifdef BUILD_UT
    // to support GoogleTest framework in unit tests
    friend std::ostream& operator<<(std::ostream& os, const SAttitude& obj);
#endif

    void set(const F32* angle, NATIVE_INT_TYPE angleSize, const F32* rate, NATIVE_INT_TYPE rateSize); //!< set values

    const F32* getangle(NATIVE_INT_TYPE& size) const; //!< get member angle
    const F32* getrate(NATIVE_INT_TYPE& size) const; //!< get member rate

    void setangle(const F32* val, NATIVE_INT_TYPE size); //!< set member angle
    void setrate(const F32* val, NATIVE_INT_TYPE size); //!< set member rate


    Fw::SerializeStatus serialize(Fw::SerializeBufferBase& buffer) const; //!< serialization function
    Fw::SerializeStatus deserialize(Fw::SerializeBufferBase& buffer); //!< deserialization function
#if FW_SERIALIZABLE_TO_STRING || BUILD_UT
    void toString(Fw::StringBase& text) const; //!< generate text from serializable
#endif
protected:

    enum {
        TYPE_ID = 0xB9413ADD //!< type id
    };

    F32 m_angle[3]; //<! angle - 三轴姿态角

    F32 m_rate[3]; //<! rate - 三轴角速度

private:

};
} // end namespace Ref
#endif /* SATTITUDE_HPP_ */

