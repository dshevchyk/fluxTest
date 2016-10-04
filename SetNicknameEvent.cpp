
#include "SetNicknameEvent.h"


CSetNicknameEvent::CSetNicknameEvent(const std::string& sNickname):
    m_sNewNickname(sNickname)
{
}


CSetNicknameEvent::~CSetNicknameEvent()
{

}

const std::string& CSetNicknameEvent::nickname() const {
    return m_sNewNickname;
}

void CSetNicknameEvent::setNickname(const std::string &sNewNickname) {
    m_sNewNickname = sNewNickname;
}
