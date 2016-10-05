#include "BaseDispatcher.h"
#include "BaseFilter.h"
#include "PokerContext.h"

CBaseStore::CBaseStore()
{
    CPokerContext::Dispatcher()->AddListener(this);
}
CBaseStore::~CBaseStore()
{
    CPokerContext::Dispatcher()->RemoveListener(this);
}

void CBaseStore::Handle(CBaseEvent* event)
{
    if(m_mapFilters.find(event->getTypeId()) != m_mapFilters.end())
        m_mapFilters[event->getTypeId()]->Handle(event);
}

void CBaseStore::AddFilter(IFilter* filter)
{
    m_mapFilters[filter->GetTypeId()] = filter;
}
