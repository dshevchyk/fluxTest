
#include "BaseDispatcher.h"
#include "BaseEvent.h"
#include "BaseStore.h"
#include "AutoLock.h"

std::mutex listenersMutex;

CBaseDispatcher::CBaseDispatcher()
{
}

CBaseDispatcher::~CBaseDispatcher()
{
    CAutoLock l(&listenersMutex);
    m_vListeners.clear();
}

bool CBaseDispatcher::Event( CBaseEvent* ptrEvent )
{
    CAutoLock l(&listenersMutex);
    for(auto& listener: m_vListeners)
    {
        listener->Handle(ptrEvent);
    }
    return true;
}

void CBaseDispatcher::RemoveListener(CBaseStore* pListener)
{
    CAutoLock l(&listenersMutex);
    m_vListeners.erase( std::remove( m_vListeners.begin(), m_vListeners.end(), pListener ), m_vListeners.end() );
}
void CBaseDispatcher::AddListener(CBaseStore* pListener)
{
    CAutoLock l(&listenersMutex);
    m_vListeners.push_back(pListener);
}

