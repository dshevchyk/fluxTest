#include "UserInfoStore.h"
#include "UserInfoDataHolder.h"

#include "common/events/userinfo/SetNicknameEvent.h"
#include "common/events/userinfo/SetUserBalanceEvent.h"


CUserInfoStore::CUserInfoStore() :
    CEventListener<CSetNicknameEvent>(this),
    CEventListener<CSetUserBalanceEvent>(this)
{
}

CUserInfoStore::~CUserInfoStore()
{
}

void CUserInfoStore::OnMessageReceived(CSetNicknameEvent* event)
{
    {
        CPUserInfoWriteDH writeDataHolder = GetWriteData();
        writeDataHolder->SetNickname(event->nickname());
    }
    {
        CPUserInfoReadDH readDataHolder  = GetReadData();
        auto nickname = readDataHolder->GetNickname();
    }
}

void CUserInfoStore::OnMessageReceived(CSetUserBalanceEvent* event)
{
    int a = 1;
    int b =1;
    a = b;
}
