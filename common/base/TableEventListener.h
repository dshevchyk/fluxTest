#ifndef CTABLEEVENTLISTENER_H
#define CTABLEEVENTLISTENER_H

#include "EventListener.h"
class CTableStore;
template<class EventType>
class CTableEventListener: public CEventListener<EventType>
{
public:
    friend class CBaseFilter<EventType>;

    virtual void OnTableMessageReceived(EventType* event) = 0;
    virtual void PostTableEvent(EventType* event) {}
    CTableEventListener(CTableStore* listener);
private:
    void OnMessageReceived(EventType* event) override;
    void PostEvent(EventType* event) override;
private:
    const int m_iContainerId;
};


#include "TableEventListener.cpp"

#endif // CEVENTLISTENER_H
