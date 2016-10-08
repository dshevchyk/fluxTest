#ifndef CTABLEEVENTLISTENER_CPP
#define CTABLEEVENTLISTENER_CPP
#include "TableEventListener.h"
#include "common/stores/table/TableStore.h"

//void OnMessageReceived(EventType* event) override;
//void PostEvent(EventType* event) override;
template<class EventType>
CTableEventListener<EventType>::CTableEventListener(CTableStore* listener, int iContainerId):
    CEventListener<EventType>(listener),
    m_iContainerId(iContainerId)
{
}
template<class EventType>
void CTableEventListener<EventType>::OnMessageReceived(EventType* event){
    if(event->GetContainerId() == m_iContainerId) {
        OnTableMessageReceived(event);
    }
}


#endif // CTABLEEVENTLISTENER_CPP
