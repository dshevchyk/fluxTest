#ifndef QTablesManagerStoreMobile_H
#define QTablesManagerStoreMobile_H

#include <QObject>

#include "common/stores/table/mobile/TablesManagerStoreMobile.h"

class CTablesManagerUiModelMobile;
class CQtTableStoreMobile;
class CPokerContext;

class CQtTablesManagerStoreMobile :  public QObject, public  CTablesManagerStoreMobile
{
    Q_OBJECT
public:
    friend class CPokerContext;
    Q_PROPERTY(CTablesManagerUiModelMobile* ui READ ui WRITE setUi NOTIFY onUiChanged)

    ~CQtTablesManagerStoreMobile();

    void PostEvent(CCreateTableEvent* event) override;
    void PostEvent(CDeleteTableEvent* event) override;

    void Delete() override;
signals:
    void onUiChanged();
private:
    explicit CQtTablesManagerStoreMobile(QObject *parent = nullptr);
    CTablesManagerUiModelMobile* ui();
    void setUi(CTablesManagerUiModelMobile* pUi);
private:
    CTablesManagerUiModelMobile* m_pUiData;
};

#endif // QTablesManagerStoreMobile_H
