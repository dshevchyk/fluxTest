#ifndef CTableUiModel_H
#define CTableUiModel_H

#include "qt/base/QtBaseUiModel.h"

#include <QString>
#include <QQuickItem>

class CTableUiModelMobile:  public CQtBaseUiModel
{
    Q_OBJECT
public:
    POKER_UI_PROPERTY(QString, testColor, SetTestColor, onTestColorChanged, "yellow")
signals:
    void onTestColorChanged();
};

#endif // CTableUiModel_H
