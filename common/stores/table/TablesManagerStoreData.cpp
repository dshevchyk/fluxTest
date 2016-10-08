
#include "TablesManagerStore.h"

#include "TablesManagerDataHolder.h"

static CTablesManagerDataHolder m_TablesManagerDataHolder;
CPTablesManagerWriteDH CTablesManagerStore::GetWriteData()
{
    return &m_TablesManagerDataHolder;
}

CPTablesManagerReadDH CTablesManagerStore::GetReadData()
{
    return &m_TablesManagerDataHolder;
}
