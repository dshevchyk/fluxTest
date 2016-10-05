#include <QApplication>

#include "AppActions.h"
#include "PokerContext.h"

#include "general/BaseDispatcher.h"
#include "general/SetNicknameEvent.h"
#include "general/SetUserBalanceEvent.h"


CAppEventsQMLProxy* CAppEventsQMLProxy::m_pInstance = nullptr;

CAppEventsQMLProxy::CAppEventsQMLProxy(QObject *pParent)
    : QObject(pParent)
{
}

void CAppEventsQMLProxy::changeNickname(QString nickname)
{
    CPokerContext::Dispatcher()->Dispatch(new CSetNicknameEvent(nickname.toStdString()));
}

void CAppEventsQMLProxy::changeBalance(QString balance)
{
    CPokerContext::Dispatcher()->Dispatch(new CSetUserBalanceEvent(balance.toStdString()));
}

QObject* CAppEventsQMLProxy::Instance(QQmlEngine *engine, QJSEngine *scriptEngine)
{
    Q_UNUSED(engine);
    Q_UNUSED(scriptEngine);

    if(CAppEventsQMLProxy::m_pInstance == nullptr)
        CAppEventsQMLProxy::m_pInstance = new CAppEventsQMLProxy();

    return CAppEventsQMLProxy::m_pInstance;
}
