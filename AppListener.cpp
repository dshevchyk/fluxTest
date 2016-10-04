
#include "AppListener.h"
#include "BaseEvent.h"
#include "BaseFilter.h"
#include <QApplication>

CAppStore::CAppStore(QQuickItem* parent)
    : CBaseStore(parent)
{
}
void CAppStore::handle(CBaseEvent* event)
{
    std::string typ = event->getType();
    if(m_mapFilters.find(event->getType()) != m_mapFilters.end())
        m_mapFilters[event->getType()]->handle(event);
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

void CAppStore::addFilter(std::string type, void* filter)
{
    if(static_cast<FilterPointerType>(filter))
        m_mapFilters[type]= static_cast<FilterPointerType>(filter);
}
