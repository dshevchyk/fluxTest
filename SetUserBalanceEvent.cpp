
#include "SetUserBalanceEvent.h"


CSetUserBalanceEvent::CSetUserBalanceEvent(QString sBalance):

    QObject(nullptr),
    m_sNewbalance(sBalance)
{
}

CSetUserBalanceEvent::CSetUserBalanceEvent(const CSetUserBalanceEvent* eventToCopy)
{
    this->m_sNewbalance = eventToCopy->balance();
}

CSetUserBalanceEvent::~CSetUserBalanceEvent()
{
}

QString CSetUserBalanceEvent::balance() const {
    return m_sNewbalance;
}

void CSetUserBalanceEvent::setBalance(const QString &sNewBalance) {
    m_sNewbalance = sNewBalance;
    emit onBalanceChanged();
}

