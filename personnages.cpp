#include "personnages.h"
#include "autre.h"

#include <QTimer>
#include <QtDebug>
#include <QDebug>
#include "qdebug.h"

Perso::Perso(QString nom, int x, int y){
    this->nom = nom;
    this->posX = x;
    this->posY = y;
}

Perso::~Perso()
{
    delete this;
}

PersoNormaux::PersoNormaux(QString nom, int x, int y, int pv, int vitesse)
    :Perso(nom, x, y) {

    this->pv = pv;
    this->vitesse = vitesse;

    setImagePerso(new Image("/Users/Victor/Schtroumph-Hill/images/smurfHead.png"));
    this->imagePerso->setPos(posX, posY);

    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(checkAction()));

    // start the timer
    timer->start(50);

}

void PersoNormaux::setPos(int x, int y) {
    this->setPosX(x);
    this->setPosY(y);
    getImagePerso()->setPos(x, y);
}

void PersoNormaux::checkAction() {
    // get a list of all the items currently colliding with this bullet
    /*QList<QGraphicsItem *> colliding_items = collidingItems();

    // if one of the colliding items is an Enemy, destroy both the bullet and the enemy
    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if (typeid(*(colliding_items[i])) == typeid(Enemy)){
            // increase the score
            game->score->increase();

            // remove them from the scene (still on the heap)
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);

            // delete them from the heap to save memory
            delete colliding_items[i];
            delete this;

            // return (all code below refers to a non existint bullet)
            return;
        }
    }*/

    // if there was no collision with an Enemy, move the bullet forward
    //this->setPos(this->getPosX(),this->getPosY()-10);

    //qDebug() << "Salut";
    // if the bullet is off the screen, destroy it
    /*if (getPosY() < 0){
        scene()->removeItem(this);
        delete this;
    }*/

    if(!listActions->empty()) {


        ActionMove* nextAction = dynamic_cast<ActionMove*>(listActions->first());

        //qDebug() << listActions->length();

        if (nextAction != NULL) {

            this->setPos(this->getPosX() + nextAction->getDepX(), this->getPosY() + nextAction->getDepY());
            /*this->setPosX(this->getPosX() + test->getDepX());
            this->setPosY(this->getPosY() + test->getDepY());*/
            delete nextAction;
            listActions->removeFirst();

        }

    }
}

void PersoNormaux::moveTo(int x, int y) {

    // ------- ???? savoir la taille d'une image ???? -------- //
    x-=20;
    y-=20;

    int distanceX = (x-this->getPosX());
    int distanceY = (y-this->getPosY());

    int nbAction = 0;
    int nbActionSupX = 0;
    int vitesseMax = 0;
    int vitesseMin = 0;
    int nbActionSupY = 0;

    if (abs(distanceX) > abs(distanceY)) {


        nbAction = (abs(distanceX)/this->vitesse);
        vitesseMax = this->vitesse;
        if (distanceX < 0)
            vitesseMax *= -1;
        nbActionSupX = (abs(distanceX)%this->vitesse);

        if (nbAction == 0) {
            return;
        }

        vitesseMin = (distanceY/nbAction);
        nbActionSupY = (abs(distanceY)%nbAction);

        qDebug() << "ici 1";

    }
    else {

        nbAction = (abs(distanceY)/this->vitesse);
        vitesseMax = this->vitesse;
        if (distanceY < 0)
            vitesseMax *= -1;
        nbActionSupY = (abs(distanceY)%this->vitesse);

        if (nbAction == 0) {
            return;
        }

        vitesseMin = (distanceX/nbAction);
        nbActionSupX = (abs(distanceX)%nbAction);

        qDebug() << "ici 2";
    }

    qDebug() << distanceX << " " << distanceY;
    qDebug() << nbAction << " " << vitesseMax << " " << nbActionSupX << " " << vitesseMin << " " << nbActionSupY;

    for (int i=0; i<nbAction; i++) {

        int vitX = 0;
        int vitY = 0;

        if (abs(distanceX) > abs(distanceY)) {
            vitX = vitesseMax;
            vitY = vitesseMin;
            //qDebug() << "ici" << vitX << " " << vitY;
        }
        else {
            vitX = vitesseMin;
            vitY = vitesseMax;
            //qDebug() << "ici 2" << vitX << " " << vitY;
        }

        if (i < nbActionSupX) {
            if (distanceX < 0)
                vitX -= 1;
            else
                vitX += 1;
        }
        if (i < nbActionSupY) {
            if (distanceY < 0)
                vitY -= 1;
            else
                vitY += 1;
        }

        qDebug() << "État n°" << i << " vitX: " << vitX << ", vitY: " << vitY;
        ActionMove *action = new ActionMove(vitX, vitY);
        listActions->push_back(action);
    }

}

/*PersoNormaux::moveTo(int x, int y) {



}*/


PersoNormaux::~PersoNormaux()
{
    delete this;
}
