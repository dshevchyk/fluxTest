#ifndef CTableDataHolder_H
#define CTableDataHolder_H

#include "common/base/BaseDataHolder.h"

class CTableDataHolderFlux: public BaseDataHolder

{
public:
    POKER_DATA_HOLDER_PROPERTY(int, containetId, GetContainerId, SetContainerId, -1)
};

using CPTableWriteDH = CPWriteDataHolder<CTableDataHolderFlux>;
using CPTableReadDH = CPReadDataHolder<CTableDataHolderFlux>;

#endif // CTableDataHolder_H
