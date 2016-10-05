#ifndef CSETUSERBALANCEEVENT_H
#define CSETUSERBALANCEEVENT_H


#include "common/base/BaseEvent.h"
#include <string>


class CSetUserBalanceEvent: public CBaseEventTemplate<CSetUserBalanceEvent>  {
public:
    CSetUserBalanceEvent(const std::string& sbalance = "");
    ~CSetUserBalanceEvent();

    virtual const std::string& balance() const;
    virtual void setBalance(const std::string &sNewbalance);

private:
    std::string m_sNewBalance;
};

#endif // CSETUSERBALANCEEVENT_H
