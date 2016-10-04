
#include "AppDispatcher.h"
#include "BaseEvent.h"
#include "AppListener.h"
#include "../PokerClient/PokerApplication.h"

#include "AutoLock.h"

CAppDispatcher* CAppDispatcher::m_pInstance = nullptr;
std::mutex listenersMutex;

CAppDispatcher::CAppDispatcher(QObject *parent) : QObject(parent),
    m_pThread(new QThread(this))
  , m_engine(nullptr)
{
    m_pThread->start();
    moveToThread(m_pThread);
}

CAppDispatcher::~CAppDispatcher()
{
    CAppDispatcher::m_pInstance = nullptr;
    CAutoLock l(&listenersMutex);
    m_vListeners.clear();
}



void CAppDispatcher::CreateInstance()
{
    if(CAppDispatcher::m_pInstance == nullptr)
        CAppDispatcher::m_pInstance = new CAppDispatcher();
}


QObject* CAppDispatcher::Instance(QQmlEngine *engine, QJSEngine *scriptEngine)
{
    Q_UNUSED(engine);
    Q_UNUSED(scriptEngine);

    if(CAppDispatcher::m_pInstance && !CAppDispatcher::m_pInstance->m_engine)
        CAppDispatcher::m_pInstance->setEngine(engine);

    return CAppDispatcher::m_pInstance;
}


CAppDispatcher* CAppDispatcher::Instance()
{
    return CAppDispatcher::m_pInstance;
}
void CAppDispatcher::dispatch(CBaseEvent* message)
{
    QCoreApplication::postEvent(this, message);
}

bool CAppDispatcher::event( QEvent* ptrEvent )
{
    if(dynamic_cast<CBaseEvent*>(ptrEvent)) {
        return event(dynamic_cast<CBaseEvent*>(ptrEvent));
    }
    return QObject::event(ptrEvent);
}
bool CAppDispatcher::event( CBaseEvent* ptrEvent )
{
    CAutoLock l(&listenersMutex);
    for(auto& listener: m_vListeners)
    {
        listener->Handle(ptrEvent);
    }
    return true;
}

void CAppDispatcher::removeListener(CBaseStore* pListener)
{
    CAutoLock l(&listenersMutex);
    m_vListeners.erase( std::remove( m_vListeners.begin(), m_vListeners.end(), pListener ), m_vListeners.end() );
}
void CAppDispatcher::addListener(CBaseStore* pListener)
{
    CAutoLock l(&listenersMutex);
    m_vListeners.push_back(pListener);
}


QQmlEngine *CAppDispatcher::engine() const
{
    return m_engine.data();
}


void CAppDispatcher::setEngine(QQmlEngine *engine)
{
    m_engine = engine;
}

