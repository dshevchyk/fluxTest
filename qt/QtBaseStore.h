#ifndef CAPPLISTENER_H
#define CAPPLISTENER_H

#include <QQuickItem>

#include "EventThreadInvoker.h"

#include "general/BaseStore.h"
class CBaseEvent;
class IFilter;
class CAppStore  : public CQtEventThreadInvoker<QQuickItem>, public CBaseStore
{
    Q_OBJECT
public:
    explicit CAppStore(QQuickItem* parent);

    virtual ~CAppStore();
protected:
};

#endif // CAPPLISTENER_H
