#ifndef QFAPPDISPATCHER_H
#define QFAPPDISPATCHER_H

#include <QObject>
#include <QQmlEngine>

#include "../general/BaseDispatcher.h"

class CAppDispatcher : public QObject, public CBaseDispatcher
{
    Q_OBJECT
public:
    explicit CAppDispatcher(QObject *parent = 0);
    ~CAppDispatcher();
    void Dispatch(CBaseEvent* message) override;
private:
    bool event( QEvent* ptrEvent ) override;
private:
    QThread* m_pThread;
};

#endif // APPDISPATCHER_H
