#ifndef CSETNICKNAMEFILTER_H
#define CSETNICKNAMEFILTER_H

#include <QEvent>
#include "BaseFilter.h"

template<class ListenerType>
class CSetNicknameFilter: public CBaseFilter<ListenerType>

{
public:
    CSetNicknameFilter(ListenerType* pListener);


    virtual ~CSetNicknameFilter();

    void Handle(CBaseEvent* pEvent) override;

    static std::string Type()
    {
        return typeid(CSetNicknameEvent).name();
    }

};

#include "SetNicknameFilter.cpp"

#endif // CBASEEVENT_H
