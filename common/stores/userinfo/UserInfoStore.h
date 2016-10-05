#ifndef UserInfoStore_H
#define UserInfoStore_H


#include "common/base/BaseDataHolder.h"
#include "common/base/BaseStore.h"
#include "common/base/EventListener.h"

class CSetNicknameEvent;
class CSetUserBalanceEvent;
class CUserInfoDataHolder;

class CUserInfoStore :  public  CBaseStore
        , public CEventListener<CSetNicknameEvent>
        , public CEventListener<CSetUserBalanceEvent>
{
public:
    ~CUserInfoStore();
    CPReadDataHolder<CUserInfoDataHolder> GetReadData();
protected:
    explicit CUserInfoStore();
    void OnMessageReceived(CSetNicknameEvent* event) override;
    void OnMessageReceived(CSetUserBalanceEvent* event) override;

    CPWriteDataHolder<CUserInfoDataHolder> GetWriteData();
};

#endif // UserInfoStore_H
