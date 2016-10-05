#ifndef CPokerContext_H
#define CPokerContext_H

#include <typeinfo>

class CBaseDispatcher;

class CPokerContext
{
public:
    static CBaseDispatcher* Dispatcher();
};
#endif // CPokerContext_H
