#ifndef CUserinfoDataHolder_H
#define CUserinfoDataHolder_H

#include "common/base/BaseDataHolder.h"

class CUserInfoDataHolder: public BaseDataHolder

{
public:
    POKER_DATA_HOLDER_PROPERTY(std::string, nickname, GetNickname, SetNickname, "")
    POKER_DATA_HOLDER_PROPERTY(std::string, balance, GetBalance, SetBalance, "")
};


using CPUserInfoWriteDH = CPWriteDataHolder<CUserInfoDataHolder>;
using CPUserInfoReadDH = CPReadDataHolder<CUserInfoDataHolder>;

#endif // CUserinfoDataHolder_H
