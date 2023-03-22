/*
 * SignalInfo.hpp
 *
 *  Created on: Monday, 20 March 2023
 *  Author:     kokaze
 *
 */
#ifndef SIGNALINFO_HPP_
#define SIGNALINFO_HPP_

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
#include <Ref/SignalGen/SignalTypeEnumAc.hpp>
#include <Ref/SignalGen/SignalPairSetArrayAc.hpp>
#include <Ref/SignalGen/SignalSetArrayAc.hpp>

namespace Ref {

class SignalInfo : public Fw::Serializable {


public:

    enum {
        SERIALIZED_SIZE =
        Ref::SignalType::SERIALIZED_SIZE +
        Ref::SignalSet::SERIALIZED_SIZE +
        Ref::SignalPairSet::SERIALIZED_SIZE
    }; //!< serializable size of SignalInfo

    SignalInfo(); //!< Default constructor
    SignalInfo(const SignalInfo* src); //!< pointer copy constructor
    SignalInfo(const SignalInfo& src); //!< reference copy constructor
    SignalInfo(const Ref::SignalType& type, const Ref::SignalSet& history, const Ref::SignalPairSet& pairHistory); //!< constructor with arguments
    SignalInfo& operator=(const SignalInfo& src); //!< equal operator
    bool operator==(const SignalInfo& src) const; //!< equality operator
#ifdef BUILD_UT
    // to support GoogleTest framework in unit tests
    friend std::ostream& operator<<(std::ostream& os, const SignalInfo& obj);
#endif

    void set(const Ref::SignalType& type, const Ref::SignalSet& history, const Ref::SignalPairSet& pairHistory); //!< set values

    const Ref::SignalType& gettype() const; //!< get member type
    const Ref::SignalSet& gethistory() const; //!< get member history
    const Ref::SignalPairSet& getpairHistory() const; //!< get member pairHistory

    void settype(const Ref::SignalType& val); //!< set member type
    void sethistory(const Ref::SignalSet& val); //!< set member history
    void setpairHistory(const Ref::SignalPairSet& val); //!< set member pairHistory


    Fw::SerializeStatus serialize(Fw::SerializeBufferBase& buffer) const; //!< serialization function
    Fw::SerializeStatus deserialize(Fw::SerializeBufferBase& buffer); //!< deserialization function
#if FW_SERIALIZABLE_TO_STRING || BUILD_UT
    void toString(Fw::StringBase& text) const; //!< generate text from serializable
#endif
protected:

    enum {
        TYPE_ID = 0x961E2D66 //!< type id
    };

    Ref::SignalType m_type; //<! type - 
    Ref::SignalSet m_history; //<! history - 
    Ref::SignalPairSet m_pairHistory; //<! pairHistory - 
private:

};
} // end namespace Ref
#endif /* SIGNALINFO_HPP_ */

