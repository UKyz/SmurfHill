#ifndef MODEL_H
#define MODEL_H

#include <QTableWidget>
#include <QMainWindow>

#include "decor.h"
#include "personnages.h"
#include <QList>

class Village;
class View;

class Model
{
    private:
        QList<PersoGentil *> *listSGentil = new QList<PersoGentil *>;
        QList<PersoMechant *> *listSMechant = new QList<PersoMechant *>;
        QList<QString> *listConseilGrandS = new QList<QString>;
        QList<QString> *listConseilSette = new QList<QString>;

        int villagePosX;
        int villagePosY;

        bool message = false;

    public:
        Model();
        Village *setVillage(View *view);
        void actionPerso(int x, int y, int nbS);
        void addPersoGentil(PersoGentil *S) {listSGentil->append(S);}
        void addPersoMechant(PersoMechant *S) {listSMechant->append(S);}
        int getNbSFree();
        int getVillagePosX() {return villagePosX;}
        int getVillagePosY() {return villagePosY;}
        bool getMessage() {return this->message;}
        void setMessage(bool message) {this->message = message;}
        QGraphicsTextItem *getMessageSette();
        QGraphicsTextItem *getMessageGrandS();
        Image *getImageBulle();
        Image *getImageGrandS();
        Image *getImageSette();

};

#endif // MODEL_H
