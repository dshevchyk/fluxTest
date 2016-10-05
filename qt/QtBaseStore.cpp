#include <QApplication>

#include "QtBaseStore.h"
#include "AppDispatcher.h"

#include "general/BaseEvent.h"
#include "general/BaseFilter.h"

#include "PokerContext.h"
CAppStore::CAppStore(QQuickItem* parent)
    : CQtEventThreadInvoker<QQuickItem>(parent)
{
    if(parent == nullptr)
    {
        moveToThread(QApplication::instance()->thread());
    }
}

CAppStore::~CAppStore()
{
}

