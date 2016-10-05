#include "QtBaseUiModel.h"

#include <QApplication>

CQtBaseUiModel::CQtBaseUiModel():
    CQtEventThreadInvoker<QQuickItem>(nullptr)
{
    moveToThread(QApplication::instance()->thread());
}
