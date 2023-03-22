/*
 * SFratemodulator.hpp
 *
 *  Created on: Monday, 20 March 2023
 *  Author:     kokaze
 *
 */
#ifndef SFRATEMODULATOR_HPP_
#define SFRATEMODULATOR_HPP_

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

class SFratemodulator : public Fw::Serializable {


public:

    enum {
        SERIALIZED_SIZE =
        sizeof(F32)*3 +
        sizeof(F32)*3 +
        sizeof(U8)*3 +
        sizeof(U8)*3
    }; //!< serializable size of SFratemodulator

    SFratemodulator(); //!< Default constructor
    SFratemodulator(const SFratemodulator* src); //!< pointer copy constructor
    SFratemodulator(const SFratemodulator& src); //!< reference copy constructor
    SFratemodulator(const F32* u, NATIVE_INT_TYPE uSize, const F32* r, NATIVE_INT_TYPE rSize, const U8* Yp, NATIVE_INT_TYPE YpSize, const U8* Yn, NATIVE_INT_TYPE YnSize); //!< constructor with arguments
    SFratemodulator(const F32 u, const F32 r, const U8 Yp, const U8 Yn); //!< constructor with arguments with scalars for array arguments
    SFratemodulator& operator=(const SFratemodulator& src); //!< equal operator
    bool operator==(const SFratemodulator& src) const; //!< equality operator
#ifdef BUILD_UT
    // to support GoogleTest framework in unit tests
    friend std::ostream& operator<<(std::ostream& os, const SFratemodulator& obj);
#endif

    void set(const F32* u, NATIVE_INT_TYPE uSize, const F32* r, NATIVE_INT_TYPE rSize, const U8* Yp, NATIVE_INT_TYPE YpSize, const U8* Yn, NATIVE_INT_TYPE YnSize); //!< set values

    const F32* getu(NATIVE_INT_TYPE& size) const; //!< get member u
    const F32* getr(NATIVE_INT_TYPE& size) const; //!< get member r
    const U8* getYp(NATIVE_INT_TYPE& size) const; //!< get member Yp
    const U8* getYn(NATIVE_INT_TYPE& size) const; //!< get member Yn

    void setu(const F32* val, NATIVE_INT_TYPE size); //!< set member u
    void setr(const F32* val, NATIVE_INT_TYPE size); //!< set member r
    void setYp(const U8* val, NATIVE_INT_TYPE size); //!< set member Yp
    void setYn(const U8* val, NATIVE_INT_TYPE size); //!< set member Yn


    Fw::SerializeStatus serialize(Fw::SerializeBufferBase& buffer) const; //!< serialization function
    Fw::SerializeStatus deserialize(Fw::SerializeBufferBase& buffer); //!< deserialization function
#if FW_SERIALIZABLE_TO_STRING || BUILD_UT
    void toString(Fw::StringBase& text) const; //!< generate text from serializable
#endif
protected:

    enum {
        TYPE_ID = 0x588C6874 //!< type id
    };

    F32 m_u[3]; //<! u - 输入信号,即控制器输出

    F32 m_r[3]; //<! r - 反馈信号

    U8 m_Yp[3]; //<! Yp - 脉冲方向输出

    U8 m_Yn[3]; //<! Yn - 脉冲方向输出

private:

};
} // end namespace Ref
#endif /* SFRATEMODULATOR_HPP_ */

