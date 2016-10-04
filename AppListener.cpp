
#include "AppListener.h"
#include "BaseEvent.h"
#include "BaseFilter.h"
#include <QApplication>

CAppStore::CAppStore(QQuickItem* parent)
    : CBaseStore(parent)
{
}
void CAppStore::Handle(CBaseEvent* event)
{
    int typ = event->getTypeId();
    if(m_mapFilters.find(event->getTypeId()) != m_mapFilters.end())
        m_mapFilters[event->getTypeId()]->Handle(event);
}

bool CAppStore::event( QEvent* ptrEvent )
{
    if(dynamic_cast<CBaseEvent*>(ptrEvent)) {
        return event(dynamic_cast<CBaseEvent*>(ptrEvent));
    }
    return QObject::event(ptrEvent);
}

bool CAppStore::event( CBaseEvent* ptrEvent )
{
    qDebug("BaseEvent called");

    return true;
}

void CAppStore::AddFilter(IFilter* filter)
{
    m_mapFilters[filter->GetTypeId()] = filter;
}
