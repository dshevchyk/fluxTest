#ifndef CUserInfoUiModel_H
#define CUserInfoUiModel_H

#include "qt/base/QtBaseUiModel.h"

#include <QString>
#include <QQuickItem>

class CUserInfoUiModelMobile:  public CQtBaseUiModel
{
    Q_OBJECT
public:
    POKER_UI_PROPERTY(QString, testColor, SetTestColor, onTestColorChanged, "green")
signals:
    void onTestColorChanged();
};

#endif // CUserInfoUiModel_H
