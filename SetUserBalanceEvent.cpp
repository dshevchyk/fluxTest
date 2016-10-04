
#include "SetUserBalanceEvent.h"


CSetUserBalanceEvent::CSetUserBalanceEvent(const std::string& sBalance):
    m_sNewBalance(sBalance)
{
}


CSetUserBalanceEvent::~CSetUserBalanceEvent()
{
}

const std::string& CSetUserBalanceEvent::balance() const {
    return m_sNewBalance;
}

void CSetUserBalanceEvent::setBalance(const std::string &sNewBalance) {
    m_sNewBalance = sNewBalance;
}

