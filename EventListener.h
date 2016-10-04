#ifndef CEVENTLISTENER_H
#define CEVENTLISTENER_H

class CBaseStore;
template<class EventType>
class CEventListener
{
public:
    virtual void onMessageReceived(EventType* event) = 0;
    CEventListener(CBaseStore* listener);
};


#include "EventListener.cpp"

#endif // CEVENTLISTENER_H
