#include "AppActions.h"
#include <QApplication>
#include "AppDispatcher.h"
#include "SetNicknameEvent.h"
#include "SetUserBalanceEvent.h"

CAppEventsQMLProxy* CAppEventsQMLProxy::m_pInstance = nullptr;

CAppEventsQMLProxy::CAppEventsQMLProxy(QObject *pParent)
    : QObject(pParent)
{
}

void CAppEventsQMLProxy::changeNickname(QString nickname)
{
    CAppDispatcher::Instance()->dispatch(new CSetNicknameEvent(nickname));
}

void CAppEventsQMLProxy::changeBalance(QString balance)
{
    CAppDispatcher::Instance()->dispatch(new CSetUserBalanceEvent(balance));
}

QObject* CAppEventsQMLProxy::Instance(QQmlEngine *engine, QJSEngine *scriptEngine)
{
    Q_UNUSED(engine);
    Q_UNUSED(scriptEngine);

    if(CAppEventsQMLProxy::m_pInstance == nullptr)
        CAppEventsQMLProxy::m_pInstance = new CAppEventsQMLProxy();


    return CAppEventsQMLProxy::m_pInstance;
}
