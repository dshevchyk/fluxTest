
#include "AppDispatcher.h"
#include "../PokerClient/PokerApplication.h"

#include "AutoLock.h"
CAppDispatcher* CAppDispatcher::m_pInstance = nullptr;
std::mutex instanceMutex;

CAppDispatcher::CAppDispatcher(QObject *parent) : QObject(parent), m_pThread(new QThread(this))
{
    m_pThread->start();
    moveToThread(m_pThread);
}

CAppDispatcher::~CAppDispatcher()
{
    CAutoLock l(&instanceMutex);
    CAppDispatcher::m_pInstance = nullptr;
    m_vListeners.clear();
}



QObject* CAppDispatcher::Instance(QQmlEngine *engine, QJSEngine *scriptEngine)
{
    CAutoLock l(&instanceMutex);
    Q_UNUSED(engine);
    Q_UNUSED(scriptEngine);

    if(CAppDispatcher::m_pInstance == nullptr)
        CAppDispatcher::m_pInstance = new CAppDispatcher();

    CAppDispatcher::m_pInstance->setEngine(engine);

    return CAppDispatcher::m_pInstance;
}


CAppDispatcher* CAppDispatcher::Instance()
{
    CAutoLock l(&instanceMutex);

    if(CAppDispatcher::m_pInstance == nullptr)
        CAppDispatcher::m_pInstance = new CAppDispatcher();
    return dynamic_cast<CAppDispatcher*>(CAppDispatcher::m_pInstance);
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

    CAutoLock l(&instanceMutex);
    for(auto& listener: m_vListeners)
    {
        listener->handle(ptrEvent);
    }
    return true;
}

void CAppDispatcher::removeListener(CBaseStore* pListener)
{
    CAutoLock l(&instanceMutex);
    m_vListeners.erase( std::remove( m_vListeners.begin(), m_vListeners.end(), pListener ), m_vListeners.end() );
}
void CAppDispatcher::addListener(CBaseStore* pListener)
{
    CAutoLock l(&instanceMutex);
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

