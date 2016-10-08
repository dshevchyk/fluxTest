#ifndef CTableDataHolder_H
#define CTableDataHolder_H

#include "common/base/BaseDataHolder.h"

class CTableDataHolder: public BaseDataHolder

{
public:
    POKER_DATA_HOLDER_PROPERTY(int, containetId, GetContainerId, SetContainerId, -1)
};

using CPTableWriteDH = CPWriteDataHolder<CTableDataHolder>;
using CPTableReadDH = CPReadDataHolder<CTableDataHolder>;

#endif // CTableDataHolder_H
