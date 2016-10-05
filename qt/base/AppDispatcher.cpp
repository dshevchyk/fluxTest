#include <QThread>

#include "AppDispatcher.h"
#include "AutoLock.h"

#include "common/base/BaseEvent.h"

#include "../PokerClient/PokerApplication.h"

#include "PokerContext.h"

class CEventWrapper: public QEvent
{
public:
    CEventWrapper(CBaseEvent* pData):
        QEvent(QEvent::User),
        m_pData(pData)
    {
    }
    ~CEventWrapper()
    {
        if(m_pData)
            delete m_pData;
    }

    CBaseEvent* GetData()
    {
        return m_pData;
    }

private:
    CBaseEvent* m_pData;
};


CAppDispatcher::CAppDispatcher(QObject *parent) : QObject(parent),
    m_pThread(new QThread(this))
{
    m_pThread->start();
    moveToThread(m_pThread);
}

CAppDispatcher::~CAppDispatcher()
{
}

void CAppDispatcher::Dispatch(CBaseEvent* message)
{
    QCoreApplication::postEvent(this, new CEventWrapper(message));
}

bool CAppDispatcher::event( QEvent* ptrEvent )
{
    if(dynamic_cast<CEventWrapper*>(ptrEvent)) {
        return Event(dynamic_cast<CEventWrapper*>(ptrEvent)->GetData());
    }
    return QObject::event(ptrEvent);
}
