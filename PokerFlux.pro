include(../BuildConfig.pri)

TEMPLATE = lib
TARGET = PokerFlux
QT += gui widgets network quick xml multimedia webkit webkitwidgets
DEFINES += POKERFLUX_LIB

# Sources section
INCLUDEPATH = \
    $$PWD \
    $$WORKSPACE_DIR/Includes \
    $$WORKSPACE_DIR/Logger \
    $$WORKSPACE_DIR/PokerShare \
    $$WORKSPACE_DIR/PlatformSpecific \
    $$WORKSPACE_DIR/PokerQtShare

win32 {
    CONFIG(Debug) {
        DESTDIR = $$WORKSPACE_DIR/CompiledQtCreator/Debug/data
    } else {
        DESTDIR = $$WORKSPACE_DIR/CompiledQtCreator/Release/data
    }

    # Output options
    UI_DIR = $$PWD/GeneratedFiles

    CONFIG( Release ){
        INCLUDEPATH += $$PWD/GeneratedFiles/Release
        MOC_DIR = $$PWD/GeneratedFiles/Release
        RCC_DIR = $$PWD/GeneratedFiles/Release
    } else {
        INCLUDEPATH += $$PWD/GeneratedFiles/Debug
        MOC_DIR = $$PWD/GeneratedFiles/Debug
        RCC_DIR = $$PWD/GeneratedFiles/Debug
    }
}

HEADERS = $$files(*.h, true) \
    $$files(priv/*.h)
SOURCES = $$files(*.cpp, true) \
    $$files(priv/*.cpp)

SOURCES -= $$files(DebugQtCreator/GeneratedFiles/Debug/*.cpp, true)
HEADERS -= $$files(DebugQtCreator/GeneratedFiles/Debug/*.h, true)

SOURCES -= $$files(DebugQtCreator/GeneratedFiles/Release/*.cpp, true)
HEADERS -= $$files(DebugQtCreator/GeneratedFiles/Release/*.h, true)

ios|android|macx {
    # Configuration
    CONFIG += staticlib
    LIBS += -lqjson
    # Sources
    ios|android {
        QT -= webkit webkitwidgets
    }

    android {
	QT += core-private
    }

    macx {
        QT += webkit webkitwidgets
    }
}

win32 {
    # Configuration
    DEFINES += UNICODE
    CONFIG += dll

    # Linker options
    LIBS += -L$$DESTDIR -lLogger
}
