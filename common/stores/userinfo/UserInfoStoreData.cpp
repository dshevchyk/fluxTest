
#include "UserInfoStore.h"

#include "UserInfoDataHolder.h"

static CUserInfoDataHolder m_UserInfoDataHolder;
CPUserInfoWriteDH CUserInfoStore::GetWriteData()
{
    return &m_UserInfoDataHolder;
}

CPUserInfoReadDH CUserInfoStore::GetReadData()
{
    return &m_UserInfoDataHolder;
}
