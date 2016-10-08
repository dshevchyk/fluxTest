#ifndef CTablesManagerUiModel_H
#define CTablesManagerUiModel_H

#include "qt/base/QtBaseUiModel.h"

#include <QString>
#include <QQuickItem>
#include "QtTableStoreMobile.h"

class CTablesManagerUiModelMobile:  public CQtBaseUiModel
{
    Q_OBJECT
public:
    void removeTable(int iContainerCode)
    {
        Invoke([this, iContainerCode]()
        {
            auto it = m_mapTables.find(iContainerCode);
            if(it != m_mapTables.end())
            {
                m_mapTables.erase(it);
            }
        });
    }

    void addTable(int iContainerCode, CQtTableStoreMobile* pTable)
    {
        qDebug("addTable called");
        Invoke([this, iContainerCode, pTable]()
        {

            qDebug("addTable invoke called");
            auto it = m_mapTables.find(iContainerCode);
            if(it == m_mapTables.end())
            {
                m_mapTables[iContainerCode] = pTable;
            }
        });
    }
    Q_INVOKABLE CQtTableStoreMobile* GetTable(int iContainerCode)
    {

        if(m_mapTables.find(iContainerCode) != m_mapTables.end())
        {
            return m_mapTables[iContainerCode];
        }
        return nullptr;
    }
private:


    std::map<int, CQtTableStoreMobile*> m_mapTables;
};

#endif // CTablesManagerUiModel_H
