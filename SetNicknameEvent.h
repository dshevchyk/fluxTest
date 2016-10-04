#ifndef CSETNICKNAMEEVENT_H
#define CSETNICKNAMEEVENT_H


#include "BaseEvent.h"



class CSetNicknameEvent: public CBaseEventTemplate<CSetNicknameEvent>   {
public:
    CSetNicknameEvent(const std::string& sNickname = "");
    ~CSetNicknameEvent();

    virtual const std::string& nickname() const;

    virtual void setNickname(const std::string &sNewNickname);

private:
    std::string m_sNewNickname;
};

#endif // CSETNICKNAMEEVENT_H
