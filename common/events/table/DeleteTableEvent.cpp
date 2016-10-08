
#include "DeleteTableEvent.h"

CDeleteTableEvent::CDeleteTableEvent(int iContainerId):
    m_iContainerId(iContainerId)
{
}


CDeleteTableEvent::~CDeleteTableEvent()
{
}

int CDeleteTableEvent::GetContainerId() const {
    return m_iContainerId;
}

void CDeleteTableEvent::SetContainerId(int iContainerId) {
    m_iContainerId = iContainerId;
}
