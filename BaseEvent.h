#ifndef CBASEEVENT_H
#define CBASEEVENT_H

#include <QEvent>

#include <typeinfo>

class CBaseEvent: public QEvent

{
public:
    CBaseEvent();
    virtual ~CBaseEvent();

    virtual int getTypeId() = 0;

    template<class Event>
    static int TypeId()
    {
        static int iEventTypeId = ++m_iId;
        return iEventTypeId;
    }
private:
    static int m_iId;
};


template<class Event>
class CBaseEventTemplate: public CBaseEvent {
public:
    int getTypeId() override
    {
        return CBaseEvent::TypeId<Event>();
    }
};

#endif // CBASEEVENT_H
