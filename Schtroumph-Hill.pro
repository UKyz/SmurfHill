#-------------------------------------------------
#
# Project created by QtCreator 2018-03-20T14:31:13
#
#-------------------------------------------------

QT += core gui
QT += multimedia
QT += multimediawidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Schtroumph-Hill
TEMPLATE = app
TRANSLATIONS += \
        translations/smurfHill_fr_FR.ts \
        translations/smurfHill_en_EN.ts

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
        view/view.cpp \
    model/model.cpp \
    controller/controller.cpp \
    model/autre.cpp \
    model/personnages.cpp \
    model/ressources.cpp \
    model/decor.cpp \
    model/action.cpp

HEADERS += \
        view/view.h \
    model/model.h \
    controller/controller.h \
    model/autre.h \
    model/personnages.h \
    model/ressources.h \
    model/decor.h \
    model/action.h

FORMS += \
        view/view.ui

SUBDIRS += \
    Schtroumph-Hill.pro

RESOURCES += \
    images.qrc
