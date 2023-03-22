#include <Ref/SignalGen/SignalInfoSerializableAc.hpp>
#include <Fw/Types/Assert.hpp>
#include <Fw/Types/BasicTypes.hpp>
#include <Fw/Types/StringUtils.hpp>
#if FW_SERIALIZABLE_TO_STRING
#include <Fw/Types/String.hpp>
#endif
#include <cstring>
namespace Ref {
// public methods

SignalInfo::SignalInfo(): Serializable() {
    this->m_type = Ref::SignalType::TRIANGLE;
    this->m_history = Ref::SignalSet(0.0f, 0.0f, 0.0f, 0.0f);
    this->m_pairHistory = Ref::SignalPairSet(Ref::SignalPair(0.0f, 0.0f), Ref::SignalPair(0.0f, 0.0f), Ref::SignalPair(0.0f, 0.0f), Ref::SignalPair(0.0f, 0.0f));
}

SignalInfo::SignalInfo(const SignalInfo& src) : Serializable() {
    this->set(src.m_type, src.m_history, src.m_pairHistory);
}

SignalInfo::SignalInfo(const SignalInfo* src) : Serializable() {
    FW_ASSERT(src);
    this->set(src->m_type, src->m_history, src->m_pairHistory);
}

SignalInfo::SignalInfo(const Ref::SignalType& type, const Ref::SignalSet& history, const Ref::SignalPairSet& pairHistory) : Serializable() {
    this->set(type, history, pairHistory);
}


SignalInfo& SignalInfo::operator=(const SignalInfo& src) {
    if(this == &src) {
            return *this;
    }

    this->set(src.m_type, src.m_history, src.m_pairHistory);
    return *this;
}

bool SignalInfo::operator==(const SignalInfo& src) const {
    return (
        (src.m_type == this->m_type) &&
        (src.m_history == this->m_history) &&
        (src.m_pairHistory == this->m_pairHistory) &&
        true);
}

void SignalInfo::set(const Ref::SignalType& type, const Ref::SignalSet& history, const Ref::SignalPairSet& pairHistory) {
    this->m_type = type;
    this->m_history = history;
    this->m_pairHistory = pairHistory;
}

const Ref::SignalType& SignalInfo::gettype() const {
    return this->m_type;
}

const Ref::SignalSet& SignalInfo::gethistory() const {
    return this->m_history;
}

const Ref::SignalPairSet& SignalInfo::getpairHistory() const {
    return this->m_pairHistory;
}


void SignalInfo::settype(const Ref::SignalType& val) {
    this->m_type = val;
}
void SignalInfo::sethistory(const Ref::SignalSet& val) {
    this->m_history = val;
}
void SignalInfo::setpairHistory(const Ref::SignalPairSet& val) {
    this->m_pairHistory = val;
}
Fw::SerializeStatus SignalInfo::serialize(Fw::SerializeBufferBase& buffer) const {
    Fw::SerializeStatus stat;

#if FW_SERIALIZATION_TYPE_ID
    // serialize type ID
    stat = buffer.serialize(static_cast<U32>(SignalInfo::TYPE_ID));
#endif

    stat = buffer.serialize(this->m_type);
    if (stat != Fw::FW_SERIALIZE_OK) {
        return stat;
    }
    stat = buffer.serialize(this->m_history);
    if (stat != Fw::FW_SERIALIZE_OK) {
        return stat;
    }
    stat = buffer.serialize(this->m_pairHistory);
    if (stat != Fw::FW_SERIALIZE_OK) {
        return stat;
    }
    return stat;
}

Fw::SerializeStatus SignalInfo::deserialize(Fw::SerializeBufferBase& buffer) {
    Fw::SerializeStatus stat;

#if FW_SERIALIZATION_TYPE_ID
    U32 typeId;

    stat = buffer.deserialize(typeId);
    if (stat != Fw::FW_SERIALIZE_OK) {
        return stat;
    }

    if (typeId != SignalInfo::TYPE_ID) {
        return Fw::FW_DESERIALIZE_TYPE_MISMATCH;
    }
#endif

    stat = buffer.deserialize(this->m_type);
    if (stat != Fw::FW_SERIALIZE_OK) {
        return stat;
    }
    stat = buffer.deserialize(this->m_history);
    if (stat != Fw::FW_SERIALIZE_OK) {
        return stat;
    }
    stat = buffer.deserialize(this->m_pairHistory);
    if (stat != Fw::FW_SERIALIZE_OK) {
        return stat;
    }
    return stat;
}

#if FW_SERIALIZABLE_TO_STRING  || BUILD_UT

void SignalInfo::toString(Fw::StringBase& text) const {

    static const char * formatString =
       "("
       "type = %s, "
       "history = %s, "
       "pairHistory = "
       ")";

    // declare strings to hold any serializable toString() arguments


    Fw::String typeStr;
    this->m_type.toString(typeStr);

    Fw::String historyStr;
    this->m_history.toString(historyStr);

    Fw::String pairHistoryStr;
    this->m_pairHistory.toString(pairHistoryStr);

    char outputString[FW_SERIALIZABLE_TO_STRING_BUFFER_SIZE];
    (void)snprintf(outputString,FW_SERIALIZABLE_TO_STRING_BUFFER_SIZE,formatString
       ,typeStr.toChar()
       ,historyStr.toChar()
       ,pairHistoryStr.toChar()
    );
    outputString[FW_SERIALIZABLE_TO_STRING_BUFFER_SIZE-1] = 0; // NULL terminate

    text = outputString;
}

#endif

#ifdef BUILD_UT
    std::ostream& operator<<(std::ostream& os, const SignalInfo& obj) {
        Fw::String str;
        obj.toString(str);
        os << str.toChar();
        return os;
    }
#endif
} // end namespace Ref
