#ifndef QTESTSTORE_H
#define QTESTSTORE_H

#include <QObject>

#include "AppListener.h"
#include "EventListener.h"
#include "SetNicknameEvent.h"
#include "SetUserBalanceEvent.h"
#include "BaseDataHolder.h"

class CUserInfoDataHolder;
class CUserInfoUiModel;

class CUserInfoStore :  public  CAppStore,
        public CDataHolder<CUserInfoDataHolder>
        , public CEventListener<CSetNicknameEvent>
        , public CEventListener<CSetUserBalanceEvent>
        , public CEventListener<CSetNicknameEvent>
{
    Q_OBJECT
public:
    Q_PROPERTY(CUserInfoUiModel* ui READ ui)
    CUserInfoUiModel* ui();

    explicit CUserInfoStore(QQuickItem *parent = nullptr);
    ~CUserInfoStore();

    static CUserInfoStore* Instance();
    static QObject *Instance(QQmlEngine *engine, QJSEngine *scriptEngine);
private:
    void onMessageReceived(CSetNicknameEvent* event) override;
    void onMessageReceived(CSetUserBalanceEvent* event) override;

private:
    static CUserInfoStore* m_pInstance;

    CUserInfoUiModel* m_pUiData;
};

#endif // QTESTSTORE_H
