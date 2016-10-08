#ifndef QUserInfoStoreMobile_H
#define QUserInfoStoreMobile_H

#include <QObject>

#include "common/stores/userinfo/mobile/UserInfoStoreMobile.h"

class CUserInfoUiModelMobile;
class CPokerContext;
class CQtUserInfoStoreMobile :  public QObject, public  CUserInfoStoreMobile
{
    Q_OBJECT
public:
    friend class CPokerContext;
    Q_PROPERTY(CUserInfoUiModelMobile* ui READ ui WRITE setUi NOTIFY onUiChanged)

    void Delete() override;
    ~CQtUserInfoStoreMobile();
signals:
    void onUiChanged();
private:
    explicit CQtUserInfoStoreMobile(QObject *parent = nullptr);
    CUserInfoUiModelMobile* ui();
    void setUi(CUserInfoUiModelMobile* pUi);
    void PostEvent(CSetUserBalanceEvent* event) override;

private:
    CUserInfoUiModelMobile* m_pUiData;
};

#endif // QTESTSTORE_H
