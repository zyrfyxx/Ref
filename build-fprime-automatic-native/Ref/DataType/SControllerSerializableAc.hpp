/*
 * SController.hpp
 *
 *  Created on: Monday, 20 March 2023
 *  Author:     kokaze
 *
 */
#ifndef SCONTROLLER_HPP_
#define SCONTROLLER_HPP_

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

class SController : public Fw::Serializable {


public:

    enum {
        SERIALIZED_SIZE =
        sizeof(F32)*3 +
        sizeof(F32)*3 +
        sizeof(F32)*3
    }; //!< serializable size of SController

    SController(); //!< Default constructor
    SController(const SController* src); //!< pointer copy constructor
    SController(const SController& src); //!< reference copy constructor
    SController(const F32* Up, NATIVE_INT_TYPE UpSize, const F32* Ud, NATIVE_INT_TYPE UdSize, const F32* fy, NATIVE_INT_TYPE fySize); //!< constructor with arguments
    SController(const F32 Up, const F32 Ud, const F32 fy); //!< constructor with arguments with scalars for array arguments
    SController& operator=(const SController& src); //!< equal operator
    bool operator==(const SController& src) const; //!< equality operator
#ifdef BUILD_UT
    // to support GoogleTest framework in unit tests
    friend std::ostream& operator<<(std::ostream& os, const SController& obj);
#endif

    void set(const F32* Up, NATIVE_INT_TYPE UpSize, const F32* Ud, NATIVE_INT_TYPE UdSize, const F32* fy, NATIVE_INT_TYPE fySize); //!< set values

    const F32* getUp(NATIVE_INT_TYPE& size) const; //!< get member Up
    const F32* getUd(NATIVE_INT_TYPE& size) const; //!< get member Ud
    const F32* getfy(NATIVE_INT_TYPE& size) const; //!< get member fy

    void setUp(const F32* val, NATIVE_INT_TYPE size); //!< set member Up
    void setUd(const F32* val, NATIVE_INT_TYPE size); //!< set member Ud
    void setfy(const F32* val, NATIVE_INT_TYPE size); //!< set member fy


    Fw::SerializeStatus serialize(Fw::SerializeBufferBase& buffer) const; //!< serialization function
    Fw::SerializeStatus deserialize(Fw::SerializeBufferBase& buffer); //!< deserialization function
#if FW_SERIALIZABLE_TO_STRING || BUILD_UT
    void toString(Fw::StringBase& text) const; //!< generate text from serializable
#endif
protected:

    enum {
        TYPE_ID = 0x3F325D83 //!< type id
    };

    F32 m_Up[3]; //<! Up - 输入参数

    F32 m_Ud[3]; //<! Ud - 输入参数

    F32 m_fy[3]; //<! fy - 输出

private:

};
} // end namespace Ref
#endif /* SCONTROLLER_HPP_ */

