#ifndef ACTION_H
#define ACTION_H

#include "personnages.h"

#include <QObject>

class NormalPerso;

class Action {
    public:
        Action() {}
        virtual ~Action() {}
};

class ActionMove: public Action {
    private:
        int deplacementX;
        int deplacementY;
    public:
        ActionMove(int depX, int depY);
        int getDepX() {return this->deplacementX;}
        int getDepY() {return this->deplacementY;}
};

class ActionFight: public Action {
    private:
        NormalPerso *fighter;
        NormalPerso *defender;
    public:
        ActionFight(NormalPerso *fighter, NormalPerso *defender);
        NormalPerso *getFighter() {return this->fighter;}
        NormalPerso *getDefender() {return this->defender;}
};

#endif // ACTION_H
