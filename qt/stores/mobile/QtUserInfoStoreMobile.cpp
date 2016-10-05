#include "QtUserInfoStoreMobile.h"

#include "UserInfoUiMobelMobile.h"
#include "common/stores/userinfo/UserInfoDataHolder.h"

CQtUserInfoStoreMobile::CQtUserInfoStoreMobile(QObject *parent) :QObject(parent),
    m_pUiData(nullptr)
{
    setUi(new CUserInfoUiModelMobile());
}

CQtUserInfoStoreMobile::~CQtUserInfoStoreMobile()
{
    m_pUiData->deleteLater();
}

CUserInfoUiModelMobile* CQtUserInfoStoreMobile::ui()
{
    return m_pUiData;
}

void CQtUserInfoStoreMobile::setUi(CUserInfoUiModelMobile* pUi)
{
    m_pUiData = pUi;
    emit onUiChanged();
}
static int counter = 0;
void CQtUserInfoStoreMobile::PostEvent(CSetUserBalanceEvent* event)
{
    CPUserInfoReadDH readDataHolder  = GetReadData();
    auto nickname = readDataHolder->GetNickname();
    if(++counter %2)
        ui()->SetTestColor("red");
    else
        ui()->SetTestColor("blue");
}


//static int counter = 0;
//void CUserInfoStore::OnMessageReceived(CSetNicknameEvent* event)
//{
//    {
//        CPUserInfoWriteDH writeDataHolder = GetWriteData();
//        writeDataHolder->SetNickname(event->nickname());
//    }
//    {
//        CPUserInfoReadDH readDataHolder  = GetReadData();
//        auto nickname = GetReadData()->GetNickname();
//    }

//    CUserInfoStore::Instance()->GetReadData()->GetBalance();
//    if(++counter %2)
//        ui()->SetTestColor("red");
//    else
//        ui()->SetTestColor("blue");
//}
