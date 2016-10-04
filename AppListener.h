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
    typedef std::map<int, IFilter* > BaseFiltersMap_t;
    explicit CAppStore(QQuickItem* parent);
    void handle(CBaseEvent* event) override;
protected:

    bool event( QEvent* ptrEvent );
    bool event( CBaseEvent* ptrEvent );
    void addFilter(IFilter* filter) override;
private:
    BaseFiltersMap_t m_mapFilters;
};

#endif // CAPPLISTENER_H
