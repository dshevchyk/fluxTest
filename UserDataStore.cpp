
#include "UserDataStore.h"
#include "UserInfoDataHolder.h"

#include <memory>
CUserInfoStore* CUserInfoStore::m_pInstance = nullptr;

CUserInfoStore::CUserInfoStore(QQuickItem *parent) :CAppStore(parent),
    CEventListener<CSetNicknameEvent>(this),
    CEventListener<CSetUserBalanceEvent>(this)
{
    m_pUiData = new CUserInfoUiModel();
}

CUserInfoStore::~CUserInfoStore()
{
    CUserInfoStore::m_pInstance = nullptr;
    m_pUiData->deleteLater();
}

CUserInfoUiModel* CUserInfoStore::ui()
{
    return m_pUiData;
}

CUserInfoStore* CUserInfoStore::Instance()
{
    if(CUserInfoStore::m_pInstance == nullptr)
        CUserInfoStore::m_pInstance = new CUserInfoStore();
    return CUserInfoStore::m_pInstance;
}

QObject* CUserInfoStore::Instance(QQmlEngine *engine, QJSEngine *scriptEngine)
{
    Q_UNUSED(engine);
    Q_UNUSED(scriptEngine);

    if(CUserInfoStore::m_pInstance == nullptr)
        CUserInfoStore::m_pInstance = new CUserInfoStore();

    return CUserInfoStore::m_pInstance;
}

void CUserInfoStore::onMessageReceived(CSetNicknameEvent* event)
{
    {
        WriteDataHolderPtr writeDataHolder = GetWriteData();
        writeDataHolder->data()->SetNickname(event->nickname());
    }
    {
        ReadDataHolderPtr readDataHolder  = GetReadData();
        auto nickname = GetReadData()->data()->GetNickname();
    }

    CUserInfoStore::Instance()->GetReadData()->data()->GetBalance();

    ui()->SetTestColor("red");
}

void CUserInfoStore::onMessageReceived(CSetUserBalanceEvent* event)
{
    int a = 1;
    int b =1;
    a = b;
}
