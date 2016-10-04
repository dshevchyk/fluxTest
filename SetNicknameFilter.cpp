
#ifndef SETNICKNAME_FILTER_CPP
#define SETNICKNAME_FILTER_CPP

#include "SetNicknameEvent.h"
#include "SetNicknameFilter.h"

template<class ListenerType>
CSetNicknameFilter<ListenerType>::CSetNicknameFilter(ListenerType* pListener): CBaseFilter<ListenerType>(pListener)
{
}

template<class ListenerType>
CSetNicknameFilter<ListenerType>::~CSetNicknameFilter()
{

}

template<class ListenerType>
void CSetNicknameFilter<ListenerType>::handle(CBaseEvent* pEvent)
{
    CBaseFilter<ListenerType>::m_pListener->onMessageReceived(dynamic_cast<CSetNicknameEvent*>(pEvent));
}

#endif
