#-------------------------------------------------
#
# Project created by QtCreator 2017-12-11T13:51:00
#
#-------------------------------------------------

QT      += core gui
QT      += core xml

TARGET = GxxCryptoTool
TEMPLATE = app

SOURCES += main.cpp\
    mainwindow.cpp \
    mc_kernelwork.cpp \
    mc_log.cpp \

HEADERS  += mainwindow.h \
    mc_kernelwork.h \
    mc_log.h \


CONFIG(debug, debug|release){
    DESTDIR += ../bin/debug
} else {
    DESTDIR += ../bin/release
}

FORMS    += mainwindow.ui

