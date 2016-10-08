
#include "TableStore.h"

#include "TableDataHolder.h"

CPTableWriteDH CTableStore::GetWriteData()
{
    return m_TableDataHolder.get();
}

CPTableReadDH CTableStore::GetReadData()
{
    return m_TableDataHolder.get();
}
