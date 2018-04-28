#include "autre.h"

#include <QPixmap>
#include <QTimer>
#include <QGraphicsScene>
#include <QtDebug>
#include <math.h>

Image::Image(QString url, QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){
    setPixmap(QPixmap(url));
}

ImagePersoMechant::ImagePersoMechant(QString url, QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){
    setPixmap(QPixmap(url));
}
ImageDecor::ImageDecor(QString url, QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){
    setPixmap(QPixmap(url));
}

ChampBle::ChampBle() {
    this->capacite = 10;
    this->nbBleARecolter = 0;
}

void ChampBle::recolter(Ressource *sacDeBle) {

    qDebug() << "Sac de blé avant : " << sacDeBle->getNombre();
    sacDeBle->ajouterRessource(this->nbBleARecolter);
    this->nbBleARecolter = 0;
    qDebug() << "Sac de blé après : " << sacDeBle->getNombre();

}

void ChampBle::ete() {

    srand(time(NULL));

    this->nbBleARecolter += ((rand() % this->capacite) + 1);

}


/*GameLoop::GameLoop(Model *model) { // Constructor
    // you could copy data from constructor arguments to internal variables here.
    this->model = model;
}

GameLoop::~GameLoop() { // Destructor
    // free resources
}

void GameLoop::process() { // Process. Start processing data.
    // allocate resources using new here

    qDebug() << "Test";

    for (PersoGentil *S : *this->model->getlistSGentil()) {

        if (S->hasAction()) {
            ActionMove* nextAction = dynamic_cast<ActionMove*>(S->getFirstAction());

            S->setImagePos(S->getPosX() + nextAction->getDepX(), S->getPosY() + nextAction->getDepY());
            delete nextAction;
            S->removeFirstAction();
        }

    }

    for (PersoMechant *S : *this->model->getlistSMechant()) {




    }

    emit finished();
}*/









