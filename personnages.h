#ifndef PERSONNAGES_H
#define PERSONNAGES_H

#include <QObject>
#include <QList>
#include <QPointF>

#include "autre.h"
#include "action.h"

class Action;

class NormalPerso : public QObject {
    Q_OBJECT
    public:
        NormalPerso(int x, int y, int damage=0, int hp=0, int speed=0);
        ~NormalPerso() {delete this;}

        QString getName() {return this->name;}
        int getPosX() {return this->posX;}
        int getPosY() {return this->posY;}
        void setPos(int x, int y);
        int getHp() {return this->hp;}
        int getSpeed() {return this->speed;}
        int getDamage() {return this->damage;}
        void setImagePerso(Image *image) {this->imagePerso = image;}
        Image *getImagePerso() {return this->imagePerso;}
        void setPosX(int x) {this->posX = x;}
        void setPosY(int y) {this->posY = y;}
        void moveTo(int x, int y);
        bool hasAction() {return !listActions->empty();}
        Action *getFirstAction() {return listActions->first();}
        void removeFirstAction() {this->listActions->removeFirst();}
        void addActionInFirst(Action *action) {this->listActions->insert(0,action);}
        void removeAllActions();
        QPointF *getDestination();
        bool getHurt(int damage);
    public slots:
        void checkAction();
    protected:
        QString name;
        int posX, posY;
        int hp, speed, damage;
        Image *imagePerso;
        int deplacementX, deplacementY;
        int distancePositionClicked;
        QList<Action*> *listActions = new QList<Action*>;
};

class NicePerso : public NormalPerso {
    Q_OBJECT
    public:
        NicePerso(int x, int y, int damage=0, int hp=0, int hpMax=0, int vitesse=0);
        ~NicePerso() {delete this;}
        int getHpMax() {return this->hpMax;}
        bool isFree() {return this->listActions->empty();}
        void setDistancePositionClicked(int a) {this->distancePositionClicked = a;}
        int getDistancePositionClicked() {return this->distancePositionClicked;}
        void heal(int hp) {this->hp += hp;}
    private:
        int hpMax;
        int deplacementX, deplacementY;
        int distancePositionClicked;
        void mousePressEvent(QMouseEvent *event);
};

class MadPerso : public NormalPerso {
    Q_OBJECT
    public:
        MadPerso(int x, int y, int damage=0, int hp=0, int vitesse=0);
        ~MadPerso() {delete this;}
    private:
        int deplacementX, deplacementY;
};

class NonPlayerPerso : public QObject {
    Q_OBJECT
    public:
        NonPlayerPerso(int level);
        ~NonPlayerPerso() {delete this;}
        virtual void up(int lvl) = 0;
        int getLevel() {return this->level;}
    protected:
        int level;
};

class Farmer : public NonPlayerPerso {
    Q_OBJECT
    public:
        Farmer(int resaleCost = 1, int size = 100, int level = 1, int numberToHarvest = 0, int capacity = 10);
        ~Farmer() {delete this;}
        virtual void up(int lvl);
        WheatField *getChamps() {return this->champs;}
        int getResaleCost() {return this->resaleCost;}
    private:
        WheatField *champs;
        int resaleCost;
};

class Baker : public NonPlayerPerso {
    Q_OBJECT
    public:
        Baker(int numberResourceForProduction = 4, int costProduction = 4, int level = 1);
        ~Baker() {delete this;}
        virtual void up(int lvl);
        //void setNumberResourceForProduction(int nb) {this->numberResourceForProduction = nb;}
        int getNumberResourceForProduction() {return this->numberResourceForProduction;}
        int getCostProduction() {return this->costProduction;}
    private:
        int numberResourceForProduction;
        int costProduction;
};

class Hefty : public NonPlayerPerso {
    Q_OBJECT
    public:
        Hefty(int speedS = 5, int damageS = 1, int hpS = 100, int level = 1);
        ~Hefty() {delete this;}
        virtual void up(int lvl);
        int getSpeedS() {return this->speedS;}
        int getDamageS() {return this->damageS;}
        int getHpS() {return this->hpS;}
    private:
        int speedS;
        int damageS;
        int hpS;
};

#endif // PERSONNAGES_H
