#-------------------------------------------------
#
# Project created by QtCreator 2017-11-16T15:48:53
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = train
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS
QMAKE_CXXFLAGS_RELEASE = $$QMAKE_CFLAGS_RELEASE_WITH_DEBUGINFO
QMAKE_LFLAGS_RELEASE = $$QMAKE_LFLAGS_RELEASE_WITH_DEBUGINFO

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        ziz.cpp \
    dialog.cpp \
    dialog1.cpp \
    dialog2.cpp \
    dialog3.cpp

HEADERS  += ziz.h \
    dialog.h \
    dialog1.h \
    dialog2.h \
    dialog3.h

FORMS    += ziz.ui \
    dialog.ui \
    dialog1.ui \
    dialog2.ui \
    dialog3.ui

RESOURCES += \
    recource.qrc

QMAKE_CXXFLAGS +=  -Wno-unused-parameter

