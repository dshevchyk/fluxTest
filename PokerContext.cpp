//HERE IS IMPLEMENTATION PER PLATFORM/FRAMEWORK
#include "PokerContext.h"
#include "qt/base/AppDispatcher.h"
#include "qt/stores/mobile/QtUserInfoStoreMobile.h"

CBaseDispatcher* CPokerContext::Dispatcher()
{
    static CBaseDispatcher* dispatcher = new CAppDispatcher();
    return dispatcher;
}

CUserInfoStore* CPokerContext::UserInfoStore()
{
    static CUserInfoStore* userInfoStore = new CQtUserInfoStoreMobile();
    return userInfoStore;
}
