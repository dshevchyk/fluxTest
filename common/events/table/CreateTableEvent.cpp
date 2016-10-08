
#include "CreateTableEvent.h"

CCreateTableEvent::CCreateTableEvent(int iContainerId):
    m_iContainerId(iContainerId)
{
}


CCreateTableEvent::~CCreateTableEvent()
{
}

int CCreateTableEvent::GetContainerId() const {
    return m_iContainerId;
}

void CCreateTableEvent::SetContainerId(int iContainerId) {
    m_iContainerId = iContainerId;
}
