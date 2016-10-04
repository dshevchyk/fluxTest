#ifndef CBASESTORE_H
#define CBASESTORE_H

#include <QObject>
#include <QQuickItem>

#include "EventThreadInvoker.h"

#include <QApplication>
class CBaseEvent;
class IFilter;
class CBaseStore: public CQtEventThreadInvoker<QQuickItem>
{
    Q_OBJECT
public:
    explicit CBaseStore(QQuickItem* parent):
        CQtEventThreadInvoker<QQuickItem>(parent)
        //m_pThread(new QThread())
    {
        if(parent == nullptr)
        {
            //m_pThread->start();
            moveToThread(QApplication::instance()->thread());
        }
    }

    virtual void handle(CBaseEvent* event) = 0;

    virtual void addFilter(std::string type, void* filter) = 0;
protected:
    //QThread* m_pThread;
};

#endif // CBASESTORE_H
