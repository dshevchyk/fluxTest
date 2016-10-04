
#include "BaseEvent.h"
CBaseEvent::CBaseEvent(): QEvent(QEvent::User)
{

}

int CBaseEvent::m_iIdCounter = 0;
