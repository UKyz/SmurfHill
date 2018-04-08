#-------------------------------------------------
#
# Project created by QtCreator 2018-03-20T14:31:13
#
#-------------------------------------------------

QT       += core gui
QT += multimedia
QT += multimediawidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Schtroumph-Hill
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
        view.cpp \
    model.cpp \
    controller.cpp \
    autre.cpp \
    personnages.cpp \
    ressources.cpp \
    decor.cpp \
    action.cpp

HEADERS += \
        view.h \
    model.h \
    controller.h \
    autre.h \
    personnages.h \
    ressources.h \
    decor.h \
    action.h

FORMS += \
        view.ui

DISTFILES += \
    images/generique.mp3 \
    images/movie0.gif \
    images/movie1.gif \
    images/movie10.gif \
    images/movie2.gif \
    images/movie3.gif \
    images/movie4.gif \
    images/movie5.gif \
    images/movie6.gif \
    images/movie7.gif \
    images/movie8.gif \
    images/movie9.gif \
    images/SchtroumpfChargement.gif \
    images/arbre_1.png \
    images/arbre_2.png \
    images/arbre_3.png \
    images/BlackSmurf.png \
    images/bulleText.png \
    images/fond_herbe.png \
    images/grandS.png \
    images/maisonS1.png \
    images/maisonS2.png \
    images/maisonS3.png \
    images/maisonS4.png \
    images/maisonS5.png \
    images/maisonS6.png \
    images/maisonS7.png \
    images/maisonS8.png \
    images/maisonSCostaud.png \
    images/maisonSette.png \
    images/maisonSMusicien.png \
    images/maisonSPaysan.png \
    images/MoulinS.png \
    images/puits.png \
    images/schtroumpf.png \
    images/Sette01.png \
    images/smurfHead.png \
    images/generique.mp3

SUBDIRS += \
    Schtroumph-Hill.pro
