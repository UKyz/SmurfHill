#ifndef ACTION_H
#define ACTION_H

#include <QObject>

class Action {

    public:
        Action() {}
        virtual void doIt() {}
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
        void doIt();

};


#endif // ACTION_H
