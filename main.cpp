QObject* userInfoStoreProvider(QQmlEngine *engine, QJSEngine *scriptEngine)
{
    Q_UNUSED(engine)
    Q_UNUSED(scriptEngine)

    QObject* store = dynamic_cast<QObject*>(CPokerContext::UserInfoStore());
    return store;
}

void registerQuickFluxQmlTypes()
{
    //flux base
    qmlRegisterType<CUserInfoUiModelMobile>("QuickFlux", 1, 0, "UserInfoUiModel");
    qmlRegisterSingletonType<CAppEventsQMLProxy>("QuickFlux", 1, 0, "AppEvents", CAppEventsQMLProxy::Instance);
    qmlRegisterSingletonType<CQtUserInfoStoreMobile>("QuickFlux", 1, 0, "UserInfoStore", userInfoStoreProvider);
}
