#ifndef TableStore_H
#define TableStore_H


#include "common/base/BaseDataHolder.h"
#include "common/base/BaseStore.h"
#include "common/base/EventListener.h"

class CTableDataHolderFlux;
class CSetNicknameEvent;

class CTableStore :  public  CBaseStore
        , public CEventListener<CSetNicknameEvent>
//        , public CEventListener<CSetUserBalanceEvent>
{
public:
    ~CTableStore();
    CPReadDataHolder<CTableDataHolderFlux> GetReadData();

protected:
    explicit CTableStore();
    void OnMessageReceived(CSetNicknameEvent* event) override;
//    void OnMessageReceived(CSetUserBalanceEvent* event) override;

    CPWriteDataHolder<CTableDataHolderFlux> GetWriteData();


    std::unique_ptr<CTableDataHolderFlux> m_TableDataHolder;
};

#endif // TableStore_H
