#ifndef CSETNICKNAMEEVENT_H
#define CSETNICKNAMEEVENT_H


#include "BaseEvent.h"
#include <QString>
#include <QObject>



class CSetNicknameEvent:public QObject, public CBaseEventTemplate<CSetNicknameEvent>   {
    Q_OBJECT
public:
    Q_PROPERTY(QString nickname READ nickname WRITE setNickname NOTIFY onNicknameChanged)
    static CSetNicknameEvent* create(QString nickname)
    {
        return new CSetNicknameEvent(nickname);
    }

    CSetNicknameEvent(const CSetNicknameEvent* eventToCopy);
    CSetNicknameEvent(QString sNickname = "");
    ~CSetNicknameEvent();

    virtual QString nickname() const;

    virtual void setNickname(const QString &sNewNickname);


signals:
    void onNicknameChanged();
private:
    QString m_sNewNickname;
};

#endif // CSETNICKNAMEEVENT_H
