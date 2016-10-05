#ifndef CEVENTLISTENER_CPP
#define CEVENTLISTENER_CPP
#include "BaseFilter.h"
#include "BaseStore.h"
template<class EventType>
CEventListener<EventType>::CEventListener(CBaseStore* listener){
    listener->AddFilter(new CBaseFilter<EventType>(this));
}

#endif // CEVENTLISTENER_H
