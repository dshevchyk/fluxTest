#ifndef CBASEEVENT_H
#define CBASEEVENT_H


class CBaseEvent
{
public:
    CBaseEvent();
    virtual ~CBaseEvent(){}
    virtual int getTypeId() = 0;

    template<class Event>
    static int TypeId()
    {
        static int iEventTypeId = ++m_iIdCounter;
        return iEventTypeId;
    }
private:
    static int m_iIdCounter;
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
