#ifndef QTableStoreMobile_H
#define QTableStoreMobile_H

#include <QObject>

#include "common/stores/table/mobile/TableStoreMobile.h"

class CTableUiModelMobile;
class CPokerContext;
class CTablesManagerStore;

class CQtTableStoreMobile :  public QObject, public  CTableStoreMobile
{
    Q_OBJECT
public:
    friend class CPokerContext;
    explicit CQtTableStoreMobile(QObject *parent = nullptr);
    Q_PROPERTY(CTableUiModelMobile* ui READ ui WRITE setUi NOTIFY onUiChanged)

    ~CQtTableStoreMobile();
signals:
    void onUiChanged();
private:
    CTableUiModelMobile* ui();
    void setUi(CTableUiModelMobile* pUi);

    void PostEvent(CSetNicknameEvent* event) override;

    void Delete() override;
private:
    CTableUiModelMobile* m_pUiData;
};

#endif // QTESTSTORE_H
