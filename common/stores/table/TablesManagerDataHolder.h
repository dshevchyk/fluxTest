#ifndef CTablesManagerDataHolder_H
#define CTablesManagerDataHolder_H

#include "common/base/BaseDataHolder.h"
class CTableStore;
class CTablesManagerDataHolder: public BaseDataHolder

{
public:
    std::map<int, CTableStore*> m_mapTables;
};

using CPTablesManagerWriteDH = CPWriteDataHolder<CTablesManagerDataHolder>;
using CPTablesManagerReadDH = CPReadDataHolder<CTablesManagerDataHolder>;

#endif // CTablesManagerDataHolder_H
