#ifndef CEVENTLISTENER_CPP
#define CEVENTLISTENER_CPP
#include "BaseStore.h"
#include "BaseFilter.h"
template<class EventType>
CEventListener<EventType>::CEventListener(CBaseStore* listener){
    listener->addFilter(new CBaseFilter<EventType>(this));
}

#endif // CEVENTLISTENER_H
