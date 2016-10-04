void registerQuickFluxQmlTypes()
{
    //flux base
    qmlRegisterType<CUserInfoUiModel>("com.playtech.filters", 1, 0, "UserInfoUiModel");
    qmlRegisterSingletonType<CUserInfoStore>("QuickFlux", 1, 0, "UserInfoStore", CUserInfoStore::Instance);
    CAppDispatcher::Instance()->addListener(CUserInfoStore::Instance());
    qmlRegisterSingletonType<CAppEventsQMLProxy>("QuickFlux", 1, 0, "AppEvents", CAppEventsQMLProxy::Instance);
    
}
