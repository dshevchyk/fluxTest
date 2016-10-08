#include "TablesManagerStore.h"
#include "TableStore.h"
#include "TablesManagerDataHolder.h"

#include "common/events/table/CreateTableEvent.h"
#include "common/events/table/DeleteTableEvent.h"

#include "PokerContext.h"
CTablesManagerStore::CTablesManagerStore() :
    CEventListener<CCreateTableEvent>(this),
    CEventListener<CDeleteTableEvent>(this)
{
}

CTablesManagerStore::~CTablesManagerStore()
{
}

void CTablesManagerStore::OnMessageReceived(CCreateTableEvent* event)
{

    CPTablesManagerWriteDH dataHolder = GetWriteData();
    if(dataHolder->m_mapTables.find(event->GetContainerId()) == dataHolder->m_mapTables.end())
    {
        dataHolder->m_mapTables[event->GetContainerId()] = CPokerContext::GetTableStore();
    }
}

void CTablesManagerStore::OnMessageReceived(CDeleteTableEvent* event)
{
    CPTablesManagerWriteDH dataHolder = GetWriteData();
    auto it = dataHolder->m_mapTables.find(event->GetContainerId());

    if(it != dataHolder->m_mapTables.end())
    {
        CTableStore* tableStore = it->second;
        dataHolder->m_mapTables.erase(it);
        if(tableStore)
        {
            tableStore->Delete();
        }
    }
}
