#ifndef CBASEFilter_H
#define CBASEFilter_H

#include <QEvent>

#include <typeinfo>
#include "BaseEvent.h"

class CBaseStore;

template<class EventType>
class CEventListener;

class IFilter
{
public:
    virtual void handle(CBaseEvent* pEvent) = 0;
};

template<class EventType>
class CBaseFilter: public IFilter
{
public:
    CBaseFilter(CEventListener<EventType>* pListener);
    virtual ~CBaseFilter();
    virtual std::string getType();

    template<class Filter>
    static std::string type()
    {
        return typeid(Filter).name();
    }
    void handle(CBaseEvent* pEvent) override;

    static int Type()
    {
        return CBaseEvent::TypeId<EventType>();
    }


protected:
    CEventListener<EventType>* m_pListener;

};


#include "BaseFilter.cpp"
#endif // CBASEEVENT_H
