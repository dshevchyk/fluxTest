#ifndef TablesManagerStore_H
#define TablesManagerStore_H


#include "common/base/BaseDataHolder.h"
#include "common/base/BaseStore.h"
#include "common/base/EventListener.h"

class CCreateTableEvent;
class CDeleteTableEvent;
class CTableStore;
class CTablesManagerDataHolder;

class CTablesManagerStore :  public  CBaseStore
        , public CEventListener<CCreateTableEvent>
        , public CEventListener<CDeleteTableEvent>
{
public:
    ~CTablesManagerStore();
    CPReadDataHolder<CTablesManagerDataHolder> GetReadData();
protected:
    explicit CTablesManagerStore();
    void OnMessageReceived(CCreateTableEvent* event) override;
    void OnMessageReceived(CDeleteTableEvent* event) override;
protected:
    CPWriteDataHolder<CTablesManagerDataHolder> GetWriteData();
};

#endif // TablesManagerStore_H
