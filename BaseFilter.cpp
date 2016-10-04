
#ifndef BASE_FILTER_CPP
#define BASE_FILTER_CPP

#include "EventListener.h"
template <class EventType>
CBaseFilter<EventType>::CBaseFilter(CEventListener<EventType>* pListener): m_pListener(pListener)
{
}


template <class EventType>
CBaseFilter<EventType>::~CBaseFilter()
{

}

template <class EventType>
std::string CBaseFilter<EventType>::getType()
{
    return typeid(this).name();
}

template <class EventType>
void CBaseFilter<EventType>::handle(CBaseEvent* pEvent)
{
    m_pListener->onMessageReceived(dynamic_cast<EventType*>(pEvent));
}
#endif
