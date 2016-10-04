
#include "BaseEvent.h"

int CBaseEvent::m_iId = 0;

CBaseEvent::CBaseEvent(): QEvent(QEvent::User )
{
}

CBaseEvent::~CBaseEvent()
{

}
