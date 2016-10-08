#ifndef CPokerContext_H
#define CPokerContext_H

#include <memory>

class CBaseDispatcher;
class CUserInfoStore;
class IExecutor;

class CPokerContext
{
public:
    static CBaseDispatcher* Dispatcher();
    static CUserInfoStore* UserInfoStore();
    static std::shared_ptr<IExecutor> GetSyncExecutor();
    static std::shared_ptr<IExecutor> GetAsyncExecutor();
};
#endif // CPokerContext_H
