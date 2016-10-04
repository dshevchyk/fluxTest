
#include "AppListener.h"
#include "BaseEvent.h"
#include "BaseFilter.h"
#include "AppDispatcher.h"
#include <QApplication>

CAppStore::CAppStore(QQuickItem* parent)
    : CQtEventThreadInvoker<QQuickItem>(parent)
{
    if(parent == nullptr)
    {
        moveToThread(QApplication::instance()->thread());
    }
    CAppDispatcher::Instance()->AddListener(this);
}

CAppStore::~CAppStore()
{
    CAppDispatcher::Instance()->RemoveListener(this);
}

