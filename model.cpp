#include "view.h"
#include "controller.h"
#include "model.h"
#include "decor.h"
#include "personnages.h"

Model::Model() {}

Village *Model::setVillage(View *view) {
    Village *villageS = new Village(500,500, view);
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
