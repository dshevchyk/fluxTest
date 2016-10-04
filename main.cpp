void registerQuickFluxQmlTypes()
{
    //flux base
    CAppDispatcher::CreateInstance();
    CUserInfoStore::CreateInstance();
    qmlRegisterType<CUserInfoUiModel>("com.playtech.filters", 1, 0, "UserInfoUiModel");
    qmlRegisterSingletonType<CUserInfoStore>("QuickFlux", 1, 0, "UserInfoStore", CUserInfoStore::Instance);
    qmlRegisterSingletonType<CAppEventsQMLProxy>("QuickFlux", 1, 0, "AppEvents", CAppEventsQMLProxy::Instance);

}
