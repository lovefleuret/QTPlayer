#-------------------------------------------------
#
# Project created by QtCreator 2025-02-10T17:18:03
#
#-------------------------------------------------

QT       += core gui 
CONFIG += c++11 console

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QTPlayer
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS
# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
    ffmsg_queue.cpp \
    log.cpp \
        main.cpp \
        mainwindow.cpp \
    ctrlbar.cpp \
    titlebar.cpp \
    playlistwind.cpp \
    displaywind.cpp \
    globalhelper.cpp \
    easylogging++.cpp

HEADERS += \
    ffmsg.h \
    ffmsg_queue.h \
    log.h \
        mainwindow.h \
    ctrlbar.h \
    titlebar.h \
    playlistwind.h \
    displaywind.h \
    globalhelper.h \
    easylogging++.h

FORMS += \
        mainwindow.ui \
    ctrlbar.ui \
    titlebar.ui \
    playlistwind.ui \
    displaywind.ui

RESOURCES += \
    icon.qrc
win32 {
INCLUDEPATH += $$PWD/ffmpeg-4.2.1-win32-dev/include
INCLUDEPATH += $$PWD/SDL2/include

LIBS += $$PWD/ffmpeg-4.2.1-win32-dev/lib/avformat.lib   \
        $$PWD/ffmpeg-4.2.1-win32-dev/lib/avcodec.lib    \
        $$PWD/ffmpeg-4.2.1-win32-dev/lib/avdevice.lib   \
        $$PWD/ffmpeg-4.2.1-win32-dev/lib/avfilter.lib   \
        $$PWD/ffmpeg-4.2.1-win32-dev/lib/avutil.lib     \
        $$PWD/ffmpeg-4.2.1-win32-dev/lib/postproc.lib   \
        $$PWD/ffmpeg-4.2.1-win32-dev/lib/swresample.lib \
        $$PWD/ffmpeg-4.2.1-win32-dev/lib/swscale.lib    \
        $$PWD/SDL2/lib/x86/SDL2.lib \
        "C:/Program Files (x86)/Windows Kits/10/Lib/10.0.26100.0/um/x86/Ole32.Lib"
}
