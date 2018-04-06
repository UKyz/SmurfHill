#include "action.h"

#include <QtDebug>
#include <QDebug>

ActionMove::ActionMove(int depX, int depY): Action() {

    this->deplacementX = depX;
    this->deplacementY = depY;

}

void ActionMove::doIt() {

    qDebug() << "coucou";

}
