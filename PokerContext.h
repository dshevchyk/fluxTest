#ifndef CPokerContext_H
#define CPokerContext_H

#include <memory>

class CBaseDispatcher;
class CUserInfoStore;
class IExecutor;
class CTableStore;
class CTablesManagerStore;

class CPokerContext
{
public:
    static CBaseDispatcher* Dispatcher();
    static CUserInfoStore* UserInfoStore();
    static CTablesManagerStore* TablesManagerStore();
    static std::shared_ptr<IExecutor> GetSyncExecutor();
    static std::shared_ptr<IExecutor> GetAsyncExecutor();
    static CTableStore* GetTableStore();
};
#endif // CPokerContext_H
