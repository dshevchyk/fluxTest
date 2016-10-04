#ifndef CAPPLISTENER_H
#define CAPPLISTENER_H

#include <QObject>
#include <QQuickItem>

#include "EventThreadInvoker.h"
#include "BaseStore.h"

#include <QApplication>
class CBaseEvent;
class IFilter;
class CAppStore  : public CBaseStore
{
public:
    typedef IFilter* FilterPointerType;
    typedef std::map<std::string, FilterPointerType > BaseFiltersMap_t;
    explicit CAppStore(QQuickItem* parent);
    void handle(CBaseEvent* event) override;
protected:

    bool event( QEvent* ptrEvent );
    bool event( CBaseEvent* ptrEvent );
    void addFilter(std::string type, void* filter) override;
private:
    BaseFiltersMap_t m_mapFilters;
};

#endif // CAPPLISTENER_H
