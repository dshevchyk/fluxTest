#ifndef CQTBASEUIMODEL_H
#define CQTBASEUIMODEL_H

#include <QQuickItem>

#include "EventThreadInvoker.h"

#define POKER_UI_PROPERTY(Type, QmlName, Setter, NotifySignal, DefaultValue)\
public:\
    Q_PROPERTY(Type QmlName READ Get##QmlName WRITE Setter NOTIFY NotifySignal)\
    void Setter( const Type& value ){\
        Invoke([this, value]()\
        {\
            m_##QmlName = value;\
            emit NotifySignal();\
        });\
    }\
private:\
    Type m_##QmlName = DefaultValue;\
    Type Get##QmlName(){\
        return m_##QmlName;\
    }\


class CQtBaseUiModel:  public CQtEventThreadInvoker<QQuickItem>
{
    Q_OBJECT
public:

    CQtBaseUiModel();
};


#endif // CQTBASEUIMODEL_H
