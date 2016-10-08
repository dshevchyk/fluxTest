
#include "BaseDispatcher.h"
#include "BaseEvent.h"
#include "BaseStore.h"
#include "AutoLock.h"

std::recursive_mutex listenersMutex;

CBaseDispatcher::CBaseDispatcher()
{
}

CBaseDispatcher::~CBaseDispatcher()
{
    CAutoRecursiveLock l(&listenersMutex);
    m_vListeners.clear();
}

bool CBaseDispatcher::Event(const std::shared_ptr<CBaseEvent>&  ptrEvent )
{
    CAutoRecursiveLock l(&listenersMutex);
    for(auto& listener: m_vListeners)
    {
        listener->Execute([listener, ptrEvent]()
        {
            listener->Handle(ptrEvent);
        });
    }
    return true;
}

void CBaseDispatcher::RemoveListener(CBaseStore* pListener)
{
    CAutoRecursiveLock l(&listenersMutex);
    m_vListeners.erase( std::remove( m_vListeners.begin(), m_vListeners.end(), pListener ), m_vListeners.end() );
}
void CBaseDispatcher::AddListener(CBaseStore* pListener)
{
    CAutoRecursiveLock l(&listenersMutex);
    m_vListeners.push_back(pListener);
}

