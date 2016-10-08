#ifndef CSyncExecutor_H
#define CSyncExecutor_H

#include <QObject>
#include <QThread>

#include "common/base/Executor.h"

#include "EventThreadInvoker.h"

class CAsyncExecutor: public CQtEventThreadInvoker<QObject>, public CSyncExecutor
{
public:
    CAsyncExecutor():
        CQtEventThreadInvoker<QObject>(nullptr),
        m_pThread(new QThread(this))
    {
        m_pThread->start();
        moveToThread(m_pThread);
    }

    void Execute(const IExecutor::Callback &callback) override
    {
        Invoke([callback]() {
            callback();
        });
    }
protected:
    QThread* m_pThread;
};

#endif
