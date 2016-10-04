
#include "UserInfoStore.h"
#include "UserInfoDataHolder.h"
#include "AppDispatcher.h"
#include <memory>
CUserInfoStore* CUserInfoStore::m_pInstance = nullptr;

CUserInfoStore::CUserInfoStore(QQuickItem *parent) :CAppStore(parent),
    CEventListener<CSetNicknameEvent>(this),
    CEventListener<CSetUserBalanceEvent>(this),
    m_pUiData(nullptr)
{
    setUi(new CUserInfoUiModel());
    CAppDispatcher::Instance()->addListener(this);
}

CUserInfoStore::~CUserInfoStore()
{
    CUserInfoStore::m_pInstance = nullptr;
    m_pUiData->deleteLater();
    CAppDispatcher::Instance()->removeListener(this);
}

CUserInfoUiModel* CUserInfoStore::ui()
{
    return m_pUiData;
}

void CUserInfoStore::setUi(CUserInfoUiModel* pUi)
{
    m_pUiData = pUi;
    emit onUiChanged();
}

void CUserInfoStore::CreateInstance()
{
    if(CUserInfoStore::m_pInstance == nullptr)
        CUserInfoStore::m_pInstance = new CUserInfoStore();

}

CUserInfoStore* CUserInfoStore::Instance()
{
    return CUserInfoStore::m_pInstance;
}

QObject* CUserInfoStore::Instance(QQmlEngine *engine, QJSEngine *scriptEngine)
{
    Q_UNUSED(engine);
    Q_UNUSED(scriptEngine);

    return CUserInfoStore::m_pInstance;
}

static int counter = 0;
void CUserInfoStore::OnMessageReceived(CSetNicknameEvent* event)
{
    {
        CPUserInfoWriteDH writeDataHolder = GetWriteData();
        writeDataHolder->SetNickname(event->nickname());
    }
    {
        CPUserInfoReadDH readDataHolder  = GetReadData();
        auto nickname = GetReadData()->GetNickname();
    }

    CUserInfoStore::Instance()->GetReadData()->GetBalance();
    if(++counter %2)
        ui()->SetTestColor("red");
    else
        ui()->SetTestColor("blue");
}

void CUserInfoStore::OnMessageReceived(CSetUserBalanceEvent* event)
{
    int a = 1;
    int b =1;
    a = b;
}
