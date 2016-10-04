#ifndef QTESTSTORE_H
#define QTESTSTORE_H

#include <QObject>

#include "AppListener.h"
#include "EventListener.h"
#include "SetNicknameEvent.h"
#include "SetUserBalanceEvent.h"

#include "UserInfoDataHolder.h"
class CUserInfoUiModel;

class CUserInfoStore :  public  CAppStore
        , public CEventListener<CSetNicknameEvent>
        , public CEventListener<CSetUserBalanceEvent>
{
    Q_OBJECT
public:
    Q_PROPERTY(CUserInfoUiModel* ui READ ui WRITE setUi NOTIFY onUiChanged)

    explicit CUserInfoStore(QQuickItem *parent = nullptr);
    ~CUserInfoStore();

    static void CreateInstance();
    static CUserInfoStore* Instance();
    static QObject *Instance(QQmlEngine *engine, QJSEngine *scriptEngine);

    CPUserInfoReadDH GetReadData();
signals:
    void onUiChanged();
private:
    void OnMessageReceived(CSetNicknameEvent* event) override;
    void OnMessageReceived(CSetUserBalanceEvent* event) override;

    CUserInfoUiModel*ui();
    void setUi(CUserInfoUiModel* pUi);

    CPUserInfoWriteDH GetWriteData();
private:
    static CUserInfoStore* m_pInstance;

    CUserInfoUiModel* m_pUiData;

};

#endif // QTESTSTORE_H
