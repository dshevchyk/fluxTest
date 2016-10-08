#ifndef TableStoreMobile_H
#define TableStoreMobile_H


#include "../TableStore.h"

//here is some desktop specific logic for user info
class CTableStoreMobile :  public  CTableStore
{
protected:
    explicit CTableStoreMobile();
};

#endif // TableStoreMobile_H
