#include "personnages.h"

#include <QTimer>
#include <QtDebug>
#include <QDebug>
#include "qdebug.h"

NormalPerso::NormalPerso(int x, int y, int damage, int hp, int speed) {

    this->posX = x;
    this->posY = y;
    this->hp = hp;
    this->speed = speed;
    this->damage = damage;

    /*QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeost()),this,SLOT(checkAction()));

    // start the timer
    timer->start(16);*/

}

void NormalPerso::setPos(int x, int y) {
    this->setPosX(x);
    this->setPosY(y);
    getImagePerso()->setPos(x, y);
}

void NormalPerso::checkAction() {

    if(!listActions->empty()) {
        ActionMove* nextAction = dynamic_cast<ActionMove*>(listActions->first());
        if (nextAction != NULL) {
            this->setPos(this->getPosX() + nextAction->getDepX(), this->getPosY() + nextAction->getDepY());
            delete nextAction;
            listActions->removeFirst();
        }
    }
}

void NormalPerso::moveTo(int x, int y) {

    // ------- ???? savoir la taille d'une image ???? -------- //
    x-=20;
    y-=20;

    int distanceX = (x-this->getPosX());
    int distanceY = (y-this->getPosY());

    int nbAction = 0;
    int nbActionSupX = 0;
    int speedMax = 0;
    int speedMin = 0;
    int nbActionSupY = 0;

    if (abs(distanceX) > abs(distanceY)) {

        nbAction = (abs(distanceX)/this->speed);
        speedMax = this->speed;
        if (distanceX < 0)
            speedMax *= -1;
        nbActionSupX = (abs(distanceX)%this->speed);

        if (nbAction == 0) {
            return;
        }

        speedMin = (distanceY/nbAction);
        nbActionSupY = (abs(distanceY)%nbAction);

        //qDebug() << "ici 1";

    }
    else {

        nbAction = (abs(distanceY)/this->speed);
        speedMax = this->speed;
        if (distanceY < 0)
            speedMax *= -1;
        nbActionSupY = (abs(distanceY)%this->speed);

        if (nbAction == 0) {
            return;
        }

        speedMin = (distanceX/nbAction);
        nbActionSupX = (abs(distanceX)%nbAction);

        //qDebug() << "ici 2";
    }

    qDebug() << distanceX << " " << distanceY;
    qDebug() << nbAction << " " << speedMax << " " << nbActionSupX << " " << speedMin << " " << nbActionSupY;

    for (int i=0; i<nbAction; i++) {

        int vitX = 0;
        int vitY = 0;

        if (abs(distanceX) > abs(distanceY)) {
            vitX = speedMax;
            vitY = speedMin;
            //qDebug() << "ici" << vitX << " " << vitY;
        }
        else {
            vitX = speedMin;
            vitY = speedMax;
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

void NormalPerso::removeAllActions() {

    while(!this->listActions->empty())
        this->listActions->removeLast();

}

QPointF *NormalPerso::getDestination() {

    int x = this->posX;
    int y = this->posY;

    for (Action *action : *this->listActions) {
        ActionMove *actionMove = dynamic_cast<ActionMove *>(action);
        if (actionMove) {
            x += actionMove->getDepX();
            y += actionMove->getDepY();
        }
    }

    //qDebug() << "Destination -> [" << (x+20) << ";" << (y+20) << "]";
    return new QPointF(x+20, y+20);
    // + 20 pour contrer les -20 de moveTo

}

bool NormalPerso::getHurt(int damage) {

    if ((this->hp - damage) <= 0) {
        this->hp = 0;
        return true;
    }
    else {
        this->hp -= damage;
        return false;
    }

}

NormalPerso::~NormalPerso() {
    delete this;
}

NicePerso::NicePerso(int x, int y, int damage, int hp, int hpMax, int speed):NormalPerso(x, y, damage, hp, speed) {

    setImagePerso(new Image(":/images/smurfHead"));
    this->imagePerso->setPos(posX, posY);
    this->hpMax = hpMax;

}

NicePerso::~NicePerso() {
    delete this;
}

MadPerso::MadPerso(int x, int y, int damage, int hp, int speed):NormalPerso(x, y, damage, hp, speed) {

    setImagePerso(new Image(":/images/BlackSmurf"));
    this->imagePerso->setPos(posX, posY);

}

MadPerso::~MadPerso() {
    delete this;
}

NonPlayerPerso::NonPlayerPerso(int level) {
    this->level = level;
}

NonPlayerPerso::~NonPlayerPerso() {
    delete this;
}

/*PersoAvecResource::PersoAvecResource(int resaleCost, int level) : NonPlayerPerso(level) {
    this->resaleCost = resaleCost;
}

PersoAvecResource::~PersoAvecResource()
{
    delete this;
}*/

Farmer::Farmer(int resaleCost, int size, int level, int numberToHarvest, int capacity) :NonPlayerPerso(level) {
    this->resaleCost = resaleCost;
    WheatField *champ = new WheatField(numberToHarvest, capacity, size);
    this->champs = champ;

}

Farmer::~Farmer() {
    delete this;
}

void Farmer::up(int lvl) {
    for (int i=0; i<lvl; i++) {
        this->level++;
        this->getChamps()->increaseCapacity(3);
        this->getChamps()->increaseSize(15);
        if (this->level % 2 == 1 && this->level > 2 && this->level <= 11) {
            this->resaleCost ++;
        }
    }
}

Baker::Baker(int numberResourceForProduction, int costProduction, int level) :NonPlayerPerso(level) {
    this->costProduction = costProduction;
    this->numberResourceForProduction = numberResourceForProduction;
}

Baker::~Baker() {
    delete this;
}

void Baker::up(int lvl){
    for (int i=0; i<lvl; i++) {
        this->level++;
        if (this->level % 2 == 1 && this->level >= 2 && this->level <= 7) {
            this->costProduction --;
        }
        else if (this->level % 2 == 0 && this->level >= 2 && this->level <= 7) {
            this->numberResourceForProduction--;
        }
    }
}

Hefty::Hefty(int speedS, int damageS, int hpS, int level) :NonPlayerPerso(level) {
    this->speedS = speedS;
    this->damageS = damageS;
    this->hpS = hpS;
}

Hefty::~Hefty() {
    delete this;
}

void Hefty::up(int lvl){
    for (int i=0; i<lvl; i++) {
        this->level++;
        if (this->level % 3 == 1 && this->level > 1 && this->level <= 7) {
            this->speedS += 2;
        }
        else if (this->level % 3 == 2 && this->level > 1 && this->level <= 7) {
            this->hpS += 10;
        }
        else if (this->level % 3 == 0 && this->level > 1 && this->level <= 7) {
            this->damageS++;
        }
    }
}
