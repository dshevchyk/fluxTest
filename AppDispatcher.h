#ifndef QFAPPDISPATCHER_H
#define QFAPPDISPATCHER_H

#include <QObject>
#include <QQmlEngine>

#include <QPointer>
#include <QThread>

class CBaseStore;
class CBaseEvent;
class CAppDispatcher : public QObject
{
    Q_OBJECT
public:
    explicit CAppDispatcher(QObject *parent = 0);
    ~CAppDispatcher();

    static CAppDispatcher* Instance();
    static QObject *Instance(QQmlEngine *engine, QJSEngine *scriptEngine);
    static void CreateInstance();

    Q_INVOKABLE void dispatch(CBaseEvent* message);

    void removeListener(CBaseStore* pListener);
    void addListener(CBaseStore* pListener);

public:

    QQmlEngine *engine() const;

    void setEngine(QQmlEngine *engine);


private:

    bool event( QEvent* ptrEvent ) override;

    bool event( CBaseEvent* ptrEvent );

private:

    static CAppDispatcher* m_pInstance;
    QThread* m_pThread;

    QPointer<QQmlEngine> m_engine;
    std::vector<CBaseStore*> m_vListeners;
};

#endif // APPDISPATCHER_H
