#include "BaseStore.h"
#include "BaseFilter.h"

void CBaseStore::Handle(CBaseEvent* event)
{
    if(m_mapFilters.find(event->getTypeId()) != m_mapFilters.end())
        m_mapFilters[event->getTypeId()]->Handle(event);
}

void CBaseStore::AddFilter(IFilter* filter)
{
    m_mapFilters[filter->GetTypeId()] = filter;
}
