#ifndef CCreateTableEvent_H
#define CCreateTableEvent_H


#include "common/base/BaseEvent.h"
#include <string>

class CCreateTableEvent: public CBaseEventTemplate<CCreateTableEvent>   {
public:
    CCreateTableEvent(int iContainerId);
    ~CCreateTableEvent();

    virtual int GetContainerId() const;

    virtual void SetContainerId(int iContainerId);

private:
    int m_iContainerId;
};

#endif // CCreateTableEvent_H
