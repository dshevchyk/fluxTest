#include "TablesManagerStore.h"
//#include "TablesManagerDataHolder.h"

#include "common/events/table/CreateTableEvent.h"
#include "common/events/table/DeleteTableEvent.h"


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
}

void CTablesManagerStore::OnMessageReceived(CDeleteTableEvent* event)
{
}
