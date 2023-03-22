/*
 * PacketStat.hpp
 *
 *  Created on: Monday, 20 March 2023
 *  Author:     kokaze
 *
 */
#ifndef PACKETSTAT_HPP_
#define PACKETSTAT_HPP_

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
#include <Ref/RecvBuffApp/PacketRecvStatusEnumAc.hpp>

namespace Ref {

class PacketStat : public Fw::Serializable {


public:

    enum {
        SERIALIZED_SIZE =
        sizeof(U32) +
        sizeof(U32) +
        Ref::PacketRecvStatus::SERIALIZED_SIZE
    }; //!< serializable size of PacketStat

    PacketStat(); //!< Default constructor
    PacketStat(const PacketStat* src); //!< pointer copy constructor
    PacketStat(const PacketStat& src); //!< reference copy constructor
    PacketStat(U32 BuffRecv, U32 BuffErr, const Ref::PacketRecvStatus& PacketStatus); //!< constructor with arguments
    PacketStat& operator=(const PacketStat& src); //!< equal operator
    bool operator==(const PacketStat& src) const; //!< equality operator
#ifdef BUILD_UT
    // to support GoogleTest framework in unit tests
    friend std::ostream& operator<<(std::ostream& os, const PacketStat& obj);
#endif

    void set(U32 BuffRecv, U32 BuffErr, const Ref::PacketRecvStatus& PacketStatus); //!< set values

    U32 getBuffRecv() const; //!< get member BuffRecv
    U32 getBuffErr() const; //!< get member BuffErr
    const Ref::PacketRecvStatus& getPacketStatus() const; //!< get member PacketStatus

    void setBuffRecv(U32 val); //!< set member BuffRecv
    void setBuffErr(U32 val); //!< set member BuffErr
    void setPacketStatus(const Ref::PacketRecvStatus& val); //!< set member PacketStatus


    Fw::SerializeStatus serialize(Fw::SerializeBufferBase& buffer) const; //!< serialization function
    Fw::SerializeStatus deserialize(Fw::SerializeBufferBase& buffer); //!< deserialization function
#if FW_SERIALIZABLE_TO_STRING || BUILD_UT
    void toString(Fw::StringBase& text) const; //!< generate text from serializable
#endif
protected:

    enum {
        TYPE_ID = 0x1EE78ECB //!< type id
    };

    U32 m_BuffRecv; //<! BuffRecv - Number of buffers received
    U32 m_BuffErr; //<! BuffErr - Number of buffers received with errors
    Ref::PacketRecvStatus m_PacketStatus; //<! PacketStatus - Packet Status
private:

};
} // end namespace Ref
#endif /* PACKETSTAT_HPP_ */

