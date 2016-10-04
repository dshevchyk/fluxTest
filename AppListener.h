#ifndef CAPPLISTENER_H
#define CAPPLISTENER_H

#include "EventThreadInvoker.h"
#include "BaseStore.h"

class CBaseEvent;
class IFilter;
class CAppStore  : public CBaseStore
{
public:
    typedef std::map<int, IFilter* > BaseFiltersMap_t;
    explicit CAppStore(QQuickItem* parent);
    void Handle(CBaseEvent* event) override;
protected:

    bool event( QEvent* ptrEvent );
    bool event( CBaseEvent* ptrEvent );
    void AddFilter(IFilter* filter) override;
private:
    BaseFiltersMap_t m_mapFilters;
};

#endif // CAPPLISTENER_H
