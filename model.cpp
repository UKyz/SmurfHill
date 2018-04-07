#include "view.h"
#include "controller.h"
#include "model.h"
#include "decor.h"
#include "personnages.h"

Model::Model()
{
}

Village *Model::setVillage(View *view) {

    Village *villageS = new Village(100,100, view);
    return villageS;

}

void Model::actionPerso(int x, int y, int nbS) {

    // On met à jour les distancePositionClicked de chaque S

    for (int i=0; i<listS->size(); i++) {

        listS->at(i)->setDistancePositionClicked(abs(x-listS->at(i)->getPosX())/(listS->at(i)->getVitesse()));
        if (abs(y-listS->at(i)->getPosX())/(listS->at(i)->getVitesse()) > listS->at(i)->getDistancePositionClicked())
            listS->at(i)->setDistancePositionClicked(abs(y-listS->at(i)->getPosX())/(listS->at(i)->getVitesse()));

    }

    // On duplique la liste de S qu'on va trier en fonction de leur DistancePositionClicked
    QList<PersoNormaux *> *listSorted = listS;

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

    for (int i=0; i<listS->size(); i++) {
        if (listS->at(i)->isFree())
            cptS++;
    }

    return cptS;

}
