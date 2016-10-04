
#include "SetNicknameEvent.h"


CSetNicknameEvent::CSetNicknameEvent(QString sNickname):

    QObject(nullptr),
    CBaseEvent(),
    m_sNewNickname(sNickname)
{
}

CSetNicknameEvent::CSetNicknameEvent(const CSetNicknameEvent* eventToCopy)
{
    this->m_sNewNickname = eventToCopy->nickname();
}

CSetNicknameEvent::~CSetNicknameEvent()
{

}

QString CSetNicknameEvent::nickname() const {
    return m_sNewNickname;
}

void CSetNicknameEvent::setNickname(const QString &sNewNickname) {
    m_sNewNickname = sNewNickname;
    emit onNicknameChanged();
}

CBaseEvent* CSetNicknameEvent::copy()
{
    return new CSetNicknameEvent(nickname());
}

std::string CSetNicknameEvent::getType()
{
    return typeid(*this).name();
}
