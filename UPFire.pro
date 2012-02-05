#-------------------------------------------------
#
# Project created by QtCreator 2011-04-22T12:58:57
#
#-------------------------------------------------

QT       += core gui

TARGET = UPFire
TEMPLATE = app

DEFINES += QT_PROJECT
DEFINES -= UNICODE


INCLUDEPATH += "c:\Program Files\WinpkFilter\include"
INCLUDEPATH += "UPfireDLL_coff\UPFire_DLL_coff"
INCLUDEPATH += .\ndis_qt\ndisapi_qt\

SOURCES += main.cpp\
           mainwindow.cpp \
           select_rule.cpp \
           make_rule.cpp  \

HEADERS  += mainwindow.h \
            ndisapi_qt.h \            
            iphlp.h \
            upfire_dll_coff.h \
            select_rule.h \
            make_rule.h \
            C:/QtSDK/mingw/include/iphlpapi.h

FORMS    += mainwindow.ui \
    select_rule.ui \
    make_rule.ui


LIBS += -lwsock32 ./UPfireDLL_coff/UPFire_DLL_coff/libndisapi_qt.a
LIBS += -lpthread
LIBS += "C:\QtSDK\mingw\lib\libiphlpapi.a"
LIBS += ".\\libUPFire_DLL_coff.a"

RESOURCES += icons.qrc
RC_FILE = app_icon.rc
