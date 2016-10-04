#ifndef CSETUSERBALANCEEVENT_H
#define CSETUSERBALANCEEVENT_H


#include "BaseEvent.h"
#include <QString>
#include <QObject>



class CSetUserBalanceEvent:public QObject, public CBaseEventTemplate<CSetUserBalanceEvent>  {
    Q_OBJECT
public:
    Q_PROPERTY(QString balance READ balance WRITE setBalance NOTIFY onBalanceChanged)


    CSetUserBalanceEvent(const CSetUserBalanceEvent* eventToCopy);
    CSetUserBalanceEvent(QString sbalance = "");
    ~CSetUserBalanceEvent();

    virtual QString balance() const;
    virtual void setBalance(const QString &sNewbalance);
signals:
    void onBalanceChanged();
private:
    QString m_sNewbalance;
};

#endif // CSETUSERBALANCEEVENT_H
