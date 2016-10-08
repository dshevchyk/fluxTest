#include <QApplication>

#include "AppActions.h"
#include "PokerContext.h"

#include "common/base/BaseDispatcher.h"
#include "common/events/userinfo/SetNicknameEvent.h"
#include "common/events/userinfo/SetUserBalanceEvent.h"
#include "common/events/table/CreateTableEvent.h"

CAppEventsQMLProxy::CAppEventsQMLProxy(QObject *pParent)
    : QObject(pParent)
{
}


void CAppEventsQMLProxy::createTable(int containerId)
{
    CPokerContext::Dispatcher()->Dispatch(new CCreateTableEvent(containerId));
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

    static CAppEventsQMLProxy* proxy = new CAppEventsQMLProxy();

    return proxy;
}
