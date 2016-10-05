#ifndef QFAPPDISPATCHER_H
#define QFAPPDISPATCHER_H

#include <QObject>
#include <QQmlEngine>

#include "common/base/BaseDispatcher.h"

class CPokerContext;
class CAppDispatcher : public QObject, public CBaseDispatcher
{
    Q_OBJECT
public:
    friend class CPokerContext;
    ~CAppDispatcher();
    void Dispatch(CBaseEvent* message) override;
private:
    explicit CAppDispatcher(QObject *parent = 0);
    bool event( QEvent* ptrEvent ) override;
private:
    QThread* m_pThread;
};

#endif // APPDISPATCHER_H
