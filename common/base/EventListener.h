#ifndef CEVENTLISTENER_H
#define CEVENTLISTENER_H

class CBaseStore;
template<class EventType>
class CEventListener
{
public:
    virtual void OnMessageReceived(EventType* event) = 0;
    virtual void PostEvent(EventType* event) {}
    CEventListener(CBaseStore* listener);
};


#include "EventListener.cpp"

#endif // CEVENTLISTENER_H
