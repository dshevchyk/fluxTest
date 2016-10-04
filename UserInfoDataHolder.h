#ifndef CBaseDataHolder_H
#define CBaseDataHolder_H

#include "BaseDataHolder.h"
#include <QString>
#include <QQuickItem>



class CUserInfoUiModel:  public CBaseUiModel
{
    Q_OBJECT
public:
    POKER_UI_PROPERTY(QString, testColor, SetTestColor, onTestColorChanged, "green")
signals:
    void onTestColorChanged();
};

class CUserInfoDataHolder: public BaseDataHolder

{
public:
    POKER_DATA_HOLDER_PROPERTY(QString, nickname, GetNickname, SetNickname, "")
    POKER_DATA_HOLDER_PROPERTY(QString, balance, GetBalance, SetBalance, "")
};

#endif // CBaseDataHolder_H
