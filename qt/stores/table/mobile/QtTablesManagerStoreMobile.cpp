#include "QtTablesManagerStoreMobile.h"

#include "TablesManagerUiMobelMobile.h"
#include "common/events/table/CreateTableEvent.h"
#include "common/events/table/DeleteTableEvent.h"
#include "common/stores/table/TablesManagerDataHolder.h"

#include "PokerContext.h"
#include "QtTableStoreMobile.h"

CQtTablesManagerStoreMobile::CQtTablesManagerStoreMobile(QObject *parent) :QObject(parent),
    m_pUiData(nullptr)
{
    moveToThread(QApplication::instance()->thread());
    setUi(new CTablesManagerUiModelMobile());

}

CQtTablesManagerStoreMobile::~CQtTablesManagerStoreMobile()
{
    m_pUiData->deleteLater();
}



void CQtTablesManagerStoreMobile::PostEvent(CCreateTableEvent* event)
{
    ui()->addTable(event->GetContainerId(),
                   (dynamic_cast<CQtTableStoreMobile*>( GetWriteData()->m_mapTables[event->GetContainerId()])));
}

void CQtTablesManagerStoreMobile::Delete()
{
    deleteLater();
}

void CQtTablesManagerStoreMobile::PostEvent(CDeleteTableEvent* event)
{
    ui()->removeTable(event->GetContainerId());
}

CTablesManagerUiModelMobile* CQtTablesManagerStoreMobile::ui()
{
    return m_pUiData;
}

void CQtTablesManagerStoreMobile::setUi(CTablesManagerUiModelMobile* pUi)
{
    m_pUiData = pUi;
    emit onUiChanged();
}
