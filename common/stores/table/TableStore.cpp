#include "TableStore.h"
#include "TableDataHolder.h"

#include "common/events/userinfo/SetNicknameEvent.h"
#include "common/events/userinfo/SetUserBalanceEvent.h"


CTableStore::CTableStore():
    m_TableDataHolder(std::unique_ptr<CTableDataHolderFlux>(new CTableDataHolderFlux())),
    CEventListener<CSetNicknameEvent>(this)
{
}


CTableStore::~CTableStore()
{
}

void CTableStore::OnMessageReceived(CSetNicknameEvent* event)
{
//    {
//        CPUserInfoWriteDH writeDataHolder = GetWriteData();
//        writeDataHolder->SetNickname(event->nickname());
//    }
//    {
//        CPUserInfoReadDH readDataHolder  = GetReadData();
//        auto nickname = readDataHolder->GetNickname();
//    }
}

