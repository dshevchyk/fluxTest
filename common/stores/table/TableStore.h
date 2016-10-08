#ifndef TableStore_H
#define TableStore_H


#include "common/base/BaseDataHolder.h"
#include "common/base/BaseStore.h"
#include "common/base/EventListener.h"

class CTableDataHolder;

class CTableStore :  public  CBaseStore
//        , public CEventListener<CSetNicknameEvent>
//        , public CEventListener<CSetUserBalanceEvent>
{
public:
    ~CTableStore();
    CPReadDataHolder<CTableDataHolder> GetReadData();
protected:
    explicit CTableStore();
//    void OnMessageReceived(CSetNicknameEvent* event) override;
//    void OnMessageReceived(CSetUserBalanceEvent* event) override;

    CPWriteDataHolder<CTableDataHolder> GetWriteData();


    std::unique_ptr<CTableDataHolder> m_TableDataHolder;
};

#endif // TableStore_H
