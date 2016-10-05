#ifndef CPokerContext_H
#define CPokerContext_H

#include <typeinfo>

class CBaseDispatcher;
class CUserInfoStore;

class CPokerContext
{
public:
    static CBaseDispatcher* Dispatcher();
    static CUserInfoStore* UserInfoStore();
};
#endif // CPokerContext_H
