#-------------------------------------------------
#
# Project created by QtCreator 2020-02-06T16:25:02
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = sds
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    person.cpp \
    login.cpp \
    pic/w.cpp \
    zc.cpp

HEADERS  += widget.h \
    person.h \
    login.h \
    zc.h

FORMS    += widget.ui \
    person.ui \
    login.ui \
    zc.ui

DISTFILES += \
    pic/QQͼƬ20200207205651.png

RESOURCES += \
    pic/as.qrc
RC_ICONS =tb.ico
