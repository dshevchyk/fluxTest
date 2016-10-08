#include "BaseDispatcher.h"
#include "BaseFilter.h"
#include "PokerContext.h"
#include "Executor.h"


CAsynkStore::CAsynkStore()
{
    m_pExecutor = CPokerContext::GetAsyncExecutor();
}

CBaseStore::CBaseStore(): m_pExecutor(CPokerContext::GetSyncExecutor())
{
    CPokerContext::Dispatcher()->AddListener(this);
}
CBaseStore::~CBaseStore()
{
    CPokerContext::Dispatcher()->RemoveListener(this);
}


void CBaseStore::Execute(std::function<void(void)> callback)
{
    m_pExecutor->Execute(callback);
}

void CBaseStore::Delete()
{
    delete this;
}

void CBaseStore::Handle(const std::shared_ptr<CBaseEvent>& event)
{
//    if(m_mapFilters.find(event->getTypeId()) != m_mapFilters.end())
//        m_mapFilters[event->getTypeId()]->Handle(event);

    if(m_arrayFilters[event->getTypeId()] != nullptr)
        m_arrayFilters[event->getTypeId()]->Handle(event);
}

void CBaseStore::AddFilter(IFilter* filter)
{
    //m_mapFilters[filter->GetTypeId()] = filter;
    m_arrayFilters[filter->GetTypeId()] = filter;
}
