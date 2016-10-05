#ifndef QBASEDISPATCHER_H
#define QBASEDISPATCHER_H

#include <vector>

class CBaseStore;
class CBaseEvent;

class CBaseDispatcher
{
public:
    explicit CBaseDispatcher();
    virtual ~CBaseDispatcher();


    virtual void Dispatch(CBaseEvent* message) = 0;

    void RemoveListener(CBaseStore* pListener);
    void AddListener(CBaseStore* pListener);

protected:

    bool Event( CBaseEvent* ptrEvent );

private:

    std::vector<CBaseStore*> m_vListeners;
};

#endif // APPDISPATCHER_H
