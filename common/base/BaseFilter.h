#ifndef CBASEFilter_H
#define CBASEFilter_H


#include "BaseEvent.h"

class CBaseStore;

template<class EventType>
class CEventListener;

class IFilter
{
public:
    virtual int GetTypeId() = 0;
    virtual void Handle(const std::shared_ptr<CBaseEvent>& pEvent) = 0;
};

template<class EventType>
class CBaseFilter: public IFilter
{
public:
    CBaseFilter(CEventListener<EventType>* pListener);
    virtual ~CBaseFilter();

    void Handle(const std::shared_ptr<CBaseEvent>& pEvent) override;

    int GetTypeId()
    {
        return CBaseEvent::TypeId<EventType>();
    }

protected:
    CEventListener<EventType>* m_pListener;
};


#include "BaseFilter.cpp"
#endif // CBASEEVENT_H
