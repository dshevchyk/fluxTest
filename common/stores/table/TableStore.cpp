#include "TableStore.h"
#include "TableDataHolder.h"

#include "common/events/userinfo/SetNicknameEvent.h"
#include "common/events/userinfo/SetUserBalanceEvent.h"


CTableStore::CTableStore():
    m_TableDataHolder(std::unique_ptr<CTableDataHolder>(new CTableDataHolder()))
//    CEventListener<CSetNicknameEvent>(this),
//    CEventListener<CSetUserBalanceEvent>(this)
{
}

CTableStore::~CTableStore()
{
}

//void CUserInfoStore::OnMessageReceived(CSetNicknameEvent* event)
//{
//    {
//        CPUserInfoWriteDH writeDataHolder = GetWriteData();
//        writeDataHolder->SetNickname(event->nickname());
//    }
//    {
//        CPUserInfoReadDH readDataHolder  = GetReadData();
//        auto nickname = readDataHolder->GetNickname();
//    }
//}

