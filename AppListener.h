#ifndef CAPPLISTENER_H
#define CAPPLISTENER_H

#include "BaseStore.h"
#include "EventThreadInvoker.h"
#include <QQuickItem>
#include <QApplication>
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
