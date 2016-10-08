#ifndef CDeleteTableEvent_H
#define CDeleteTableEvent_H


#include "common/base/BaseEvent.h"
#include <string>

class CDeleteTableEvent: public CBaseEventTemplate<CDeleteTableEvent>   {
public:
    CDeleteTableEvent(int iContainerId);
    ~CDeleteTableEvent();

    virtual int GetContainerId() const;

    virtual void SetContainerId(int iContainerId);

private:
    int m_iContainerId;
};

#endif // CDeleteTableEvent_H
