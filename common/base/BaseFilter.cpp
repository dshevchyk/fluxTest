
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
void CBaseFilter<EventType>::Handle(CBaseEvent* pEvent)
{
    m_pListener->OnMessageReceived(dynamic_cast<EventType*>(pEvent));
    m_pListener->PostEvent(dynamic_cast<EventType*>(pEvent));
}
#endif
