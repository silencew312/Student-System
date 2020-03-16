#-------------------------------------------------
#
# Project created by QtCreator 2019-01-23T12:43:07
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Stumanager
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
        main.cpp \
    logind.cpp \
    student.cpp \
    base.cpp \
    handle.cpp \
    mgrade.cpp \
    subject.cpp \
    revisephone.cpp \
    teacher.cpp \
    rteacherp.cpp \
    rstup.cpp \
    cclass.cpp \
    mainwindowstu.cpp \
    mainwindowmanager.cpp \
    mainwindowtea.cpp

HEADERS += \
    student.h \
    base.h \
    handle.h \
    mgrade.h \
    subject.h \
    revisephone.h \
    teacher.h \
    rteacherp.h \
    rstup.h \
    cclass.h \
    loginD.h \
    mainwindowstu.h \
    mainwindowmanager.h \
    mainwindowtea.h

FORMS += \
    logind.ui \
    base.ui \
    mgrade.ui \
    revisephone.ui \
    rteacherp.ui \
    rstup.ui \
    mainwindowstu.ui \
    mainwindowmanager.ui \
    mainwindowtea.ui

DISTFILES +=

RESOURCES += \
    picture.qrc
