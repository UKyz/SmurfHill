#include "view.h"
#include "controller.h"
#include "model.h"
#include "decor.h"
#include "personnages.h"

Model::Model()
{
    this->listConseilGrandS->append("Salut mon petit, tu vas bien ?");
    this->listConseilSette->append("Hey salut ! La forme ?");
}

Village *Model::setVillage(View *view) {

    Village *villageS = new Village(300,300, view);
    this->villagePosX = 300;
    this->villagePosY = 300;
    return villageS;
}

Foret1 *Model::setForet1(View *view) {
    Foret1 *foretN = new Foret1(1000,200, view);
    return foretN;
}
/*
Foret2 *Model::setForet2(View *view) {
    Foret2 *foretN = new Foret2(100,100, view);
    return foretN;
}
*/

void Model::actionPerso(int x, int y, int nbS) {

    // On met à jour les distancePositionClicked de chaque S

    for (int i=0; i<listSGentil->size(); i++) {

        listSGentil->at(i)->setDistancePositionClicked(abs(x-listSGentil->at(i)->getPosX())/(listSGentil->at(i)->getVitesse()));
        if (abs(y-listSGentil->at(i)->getPosX())/(listSGentil->at(i)->getVitesse()) > listSGentil->at(i)->getDistancePositionClicked())
            listSGentil->at(i)->setDistancePositionClicked(abs(y-listSGentil->at(i)->getPosX())/(listSGentil->at(i)->getVitesse()));

    }

    // On duplique la liste de S qu'on va trier en fonction de leur DistancePositionClicked
    QList<PersoGentil *> *listSorted = listSGentil;

    for (int i=(listSorted->size()-1); i>0; i--) {

        for (int j=0; j<(i); j++) {

            if (listSorted->at(j+1)->getDistancePositionClicked() < listSorted->at(j)->getDistancePositionClicked()) {
                listSorted->swap(j+1,j);
            }

        }

    }

    for (int i=0; i<listSorted->size(); i++) {

        qDebug() << " i = " << i << " Distance : " << listSorted->at(i)->getDistancePositionClicked() <<
                    " pos (" << listSorted->at(i)->getPosX() << "," << listSorted->at(i)->getPosY() << ")";

    }

    // On va déplacer les nbS premier S les plus proche du clique

    int cptSLibre=0;
    int cptS=0;

    while (cptSLibre < nbS) {

        if (listSorted->at(cptS)->isFree()) {
            listSorted->at(cptS)->moveTo(x, y);
            cptSLibre++;
        }

        cptS++;
    }
}

int Model::getNbSFree() {

    int cptS=0;

    for (int i=0; i<listSGentil->size(); i++) {
        if (listSGentil->at(i)->isFree())
            cptS++;
    }

    return cptS;

}

QGraphicsTextItem * Model::getMessageGrandS() {

    QString texte = this->listConseilGrandS->at(0);

    QGraphicsTextItem *texteItem = new QGraphicsTextItem(texte);
    texteItem->setPos(this->villagePosX + 200, this->villagePosY - 100);
    return texteItem;

}

QGraphicsTextItem * Model::getMessageSette() {

    QString texte = this->listConseilSette->at(0);

    QGraphicsTextItem *texteItem = new QGraphicsTextItem(texte);
    texteItem->setPos(this->villagePosX + 200, this->villagePosY - 100);
    return texteItem;

}

Image * Model::getImageBulle() {

    Image *imageBulle = new Image("/Users/Victor/Schtroumph-Hill/images/bulleText.png");
    imageBulle->setPos(this->villagePosX + 125, this->villagePosY - 210);

    return imageBulle;

}

Image * Model::getImageGrandS() {

    Image *imageGrandS = new Image("/Users/Victor/Schtroumph-Hill/images/GrandS.png");
    imageGrandS->setPos(this->villagePosX + 370, this->villagePosY - 180);

    return imageGrandS;

}


Image * Model::getImageSette() {

    Image *imageBulle = new Image("/Users/Victor/Schtroumph-Hill/images/Sette01.png");
    imageBulle->setPos(this->villagePosX + 370, this->villagePosY - 180);

    return imageBulle;

}
