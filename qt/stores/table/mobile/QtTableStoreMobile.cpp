#include "QtTableStoreMobile.h"

#include "TableUiMobelMobile.h"
#include "common/stores/table/TableDataHolder.h"

CQtTableStoreMobile::CQtTableStoreMobile(QObject *parent) :QObject(parent),
    m_pUiData(nullptr)
{
    moveToThread(QApplication::instance()->thread());
    setUi(new CTableUiModelMobile());
}

CQtTableStoreMobile::~CQtTableStoreMobile()
{
    m_pUiData->deleteLater();
}

CTableUiModelMobile* CQtTableStoreMobile::ui()
{
    return m_pUiData;
}

void CQtTableStoreMobile::setUi(CTableUiModelMobile* pUi)
{
    m_pUiData = pUi;
    emit onUiChanged();
}

void CQtTableStoreMobile::Delete()
{
    deleteLater();
}

static int counter = 0;
void CQtTableStoreMobile::PostEvent(CSetNicknameEvent* event)
{
        if(++counter %2)
            ui()->SetTestColor("red");
        else
            ui()->SetTestColor("blue");
}

//static int counter = 0;
//void CQtTableStoreMobile::PostEvent(CSetUserBalanceEvent* event)
//{
//    CPUserInfoReadDH readDataHolder  = GetReadData();
//    auto nickname = readDataHolder->GetNickname();
//    if(++counter %2)
//        ui()->SetTestColor("red");
//    else
//        ui()->SetTestColor("blue");
//}
