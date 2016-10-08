//HERE IS IMPLEMENTATION PER PLATFORM/FRAMEWORK
#include "PokerContext.h"
#include "common/base/Executor.h"
#include "qt/base/AppDispatcher.h"
#include "qt/base/AsyncExecutor.h"
#include "qt/stores/userinfo/mobile/QtUserInfoStoreMobile.h"
#include "qt/stores/table/mobile/QtTableStoreMobile.h"
#include "qt/stores/table/mobile/QtTablesManagerStoreMobile.h"

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

CTablesManagerStore* CPokerContext::TablesManagerStore()
{
    static CTablesManagerStore* tablesManagerStore = new CQtTablesManagerStoreMobile();
    return tablesManagerStore;
}
std::shared_ptr<IExecutor> CPokerContext::GetSyncExecutor()
{
    return std::make_shared<CSyncExecutor>();
}

std::shared_ptr<IExecutor>  CPokerContext::GetAsyncExecutor()
{
    return std::make_shared<CAsyncExecutor>();
}



CTableStore* CPokerContext::GetTableStore()
{
    return new CQtTableStoreMobile();
}
