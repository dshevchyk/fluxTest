//HERE IS IMPLEMENTATION PER PLATFORM/FRAMEWORK
#include "PokerContext.h"
#include "qt/AppDispatcher.h"

CBaseDispatcher* CPokerContext::Dispatcher()
{
    static CBaseDispatcher* dispatcher = new CAppDispatcher();
    return dispatcher;
}
