/*
 * SGyroData.hpp
 *
 *  Created on: Monday, 20 March 2023
 *  Author:     kokaze
 *
 */
#ifndef SGYRODATA_HPP_
#define SGYRODATA_HPP_

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

class SGyroData : public Fw::Serializable {


public:

    enum {
        SERIALIZED_SIZE =
        sizeof(U8)*9 +
        sizeof(F32)*3 +
        sizeof(F32)*9 +
        sizeof(F32)*9 +
        sizeof(U8) +
        sizeof(U16) +
        sizeof(U16) +
        sizeof(F32)*3 +
        sizeof(U8)*9 +
        sizeof(U32)*9 +
        sizeof(F32)*5 +
        sizeof(F32)*5 +
        sizeof(F32)*5
    }; //!< serializable size of SGyroData

    SGyroData(); //!< Default constructor
    SGyroData(const SGyroData* src); //!< pointer copy constructor
    SGyroData(const SGyroData& src); //!< reference copy constructor
    SGyroData(const U8* countPick, NATIVE_INT_TYPE countPickSize, const F32* Gi, NATIVE_INT_TYPE GiSize, const F32* wa, NATIVE_INT_TYPE waSize, const F32* wal, NATIVE_INT_TYPE walSize, U8 JoinTotal, U16 gyroStatus0, U16 gyroStatus1, const F32* W, NATIVE_INT_TYPE WSize, const U8* SignFlag, NATIVE_INT_TYPE SignFlagSize, const U32* stateFlag, NATIVE_INT_TYPE stateFlagSize, const F32* Rtemp0, NATIVE_INT_TYPE Rtemp0Size, const F32* Rtemp1, NATIVE_INT_TYPE Rtemp1Size, const F32* Rtemp2, NATIVE_INT_TYPE Rtemp2Size); //!< constructor with arguments
    SGyroData(const U8 countPick, const F32 Gi, const F32 wa, const F32 wal, U8 JoinTotal, U16 gyroStatus0, U16 gyroStatus1, const F32 W, const U8 SignFlag, const U32 stateFlag, const F32 Rtemp0, const F32 Rtemp1, const F32 Rtemp2); //!< constructor with arguments with scalars for array arguments
    SGyroData& operator=(const SGyroData& src); //!< equal operator
    bool operator==(const SGyroData& src) const; //!< equality operator
#ifdef BUILD_UT
    // to support GoogleTest framework in unit tests
    friend std::ostream& operator<<(std::ostream& os, const SGyroData& obj);
#endif

    void set(const U8* countPick, NATIVE_INT_TYPE countPickSize, const F32* Gi, NATIVE_INT_TYPE GiSize, const F32* wa, NATIVE_INT_TYPE waSize, const F32* wal, NATIVE_INT_TYPE walSize, U8 JoinTotal, U16 gyroStatus0, U16 gyroStatus1, const F32* W, NATIVE_INT_TYPE WSize, const U8* SignFlag, NATIVE_INT_TYPE SignFlagSize, const U32* stateFlag, NATIVE_INT_TYPE stateFlagSize, const F32* Rtemp0, NATIVE_INT_TYPE Rtemp0Size, const F32* Rtemp1, NATIVE_INT_TYPE Rtemp1Size, const F32* Rtemp2, NATIVE_INT_TYPE Rtemp2Size); //!< set values

    const U8* getcountPick(NATIVE_INT_TYPE& size) const; //!< get member countPick
    const F32* getGi(NATIVE_INT_TYPE& size) const; //!< get member Gi
    const F32* getwa(NATIVE_INT_TYPE& size) const; //!< get member wa
    const F32* getwal(NATIVE_INT_TYPE& size) const; //!< get member wal
    U8 getJoinTotal() const; //!< get member JoinTotal
    U16 getgyroStatus0() const; //!< get member gyroStatus0
    U16 getgyroStatus1() const; //!< get member gyroStatus1
    const F32* getW(NATIVE_INT_TYPE& size) const; //!< get member W
    const U8* getSignFlag(NATIVE_INT_TYPE& size) const; //!< get member SignFlag
    const U32* getstateFlag(NATIVE_INT_TYPE& size) const; //!< get member stateFlag
    const F32* getRtemp0(NATIVE_INT_TYPE& size) const; //!< get member Rtemp0
    const F32* getRtemp1(NATIVE_INT_TYPE& size) const; //!< get member Rtemp1
    const F32* getRtemp2(NATIVE_INT_TYPE& size) const; //!< get member Rtemp2

    void setcountPick(const U8* val, NATIVE_INT_TYPE size); //!< set member countPick
    void setGi(const F32* val, NATIVE_INT_TYPE size); //!< set member Gi
    void setwa(const F32* val, NATIVE_INT_TYPE size); //!< set member wa
    void setwal(const F32* val, NATIVE_INT_TYPE size); //!< set member wal
    void setJoinTotal(U8 val); //!< set member JoinTotal
    void setgyroStatus0(U16 val); //!< set member gyroStatus0
    void setgyroStatus1(U16 val); //!< set member gyroStatus1
    void setW(const F32* val, NATIVE_INT_TYPE size); //!< set member W
    void setSignFlag(const U8* val, NATIVE_INT_TYPE size); //!< set member SignFlag
    void setstateFlag(const U32* val, NATIVE_INT_TYPE size); //!< set member stateFlag
    void setRtemp0(const F32* val, NATIVE_INT_TYPE size); //!< set member Rtemp0
    void setRtemp1(const F32* val, NATIVE_INT_TYPE size); //!< set member Rtemp1
    void setRtemp2(const F32* val, NATIVE_INT_TYPE size); //!< set member Rtemp2


    Fw::SerializeStatus serialize(Fw::SerializeBufferBase& buffer) const; //!< serialization function
    Fw::SerializeStatus deserialize(Fw::SerializeBufferBase& buffer); //!< deserialization function
#if FW_SERIALIZABLE_TO_STRING || BUILD_UT
    void toString(Fw::StringBase& text) const; //!< generate text from serializable
#endif
protected:

    enum {
        TYPE_ID = 0x55914A99 //!< type id
    };

    U8 m_countPick[9]; //<! countPick - 陀螺原始数据处理时,剔野计数器

    F32 m_Gi[3]; //<! Gi - 陀螺角度积分

    F32 m_wa[9]; //<! wa - 陀螺角速度模拟

    F32 m_wal[9]; //<! wal - 上周期陀螺角速度模拟量

    U8 m_JoinTotal; //<! JoinTotal - 参加定姿的陀螺个数
    U16 m_gyroStatus0; //<! gyroStatus0 - 陀螺状态旧
    U16 m_gyroStatus1; //<! gyroStatus1 - 陀螺状态新
    F32 m_W[3]; //<! W - 陀螺算出的角速度

    U8 m_SignFlag[9]; //<! SignFlag - 参加定姿的陀螺序号

    U32 m_stateFlag[9]; //<! stateFlag - 陀螺加电状态

    F32 m_Rtemp0[5]; //<! Rtemp0 - 

    F32 m_Rtemp1[5]; //<! Rtemp1 - 

    F32 m_Rtemp2[5]; //<! Rtemp2 - 

private:

};
} // end namespace Ref
#endif /* SGYRODATA_HPP_ */

