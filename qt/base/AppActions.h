#ifndef CAPPEVENTSQMLPROXY_H
#define CAPPEVENTSQMLPROXY_H

#include <QObject>
#include <QQmlEngine>

class CAppEventsQMLProxy : public QObject
{
    Q_OBJECT
public:
    static QObject *Instance(QQmlEngine *engine, QJSEngine *scriptEngine);

    Q_INVOKABLE void changeNickname(QString nickname);
    Q_INVOKABLE void createTable(int containerId);
    Q_INVOKABLE void changeBalance(QString balance);
private:
    CAppEventsQMLProxy(QObject* parent = nullptr);
};
#endif // CAPPEVENTSQMLPROXY_H
