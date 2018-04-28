#include "view.h"
#include "controller.h"
#include "model.h"
#include "autre.h"
#include "personnages.h"
#include "decor.h"

#include <QMessageBox>
#include <QGraphicsScene>
#include <QPixmap>
#include <QTimer>
#include <QFileDialog>
#include <QGraphicsView>
#include <QPointF>
#include <QtDebug>
#include <math.h>
#include <time.h>
//#include <QObject>

Controller::Controller(Model *model, View *view): QObject(0) {
    this->model = model;
    this->view = view;
    this->view->setControl(this);
    timer = new QTimer;
    timerBle = new QTimer;
    //Q_ASSERT(timer == NULL);
    connect(timer, SIGNAL(timeout()), this, SLOT(gameLoop()));
    connect(timerBle, SIGNAL(timeout()), this->model->getChampBle(), SLOT(ete()));
    /*game_loop();
    QTimer *timer = new QTimer();
    qDebug() << "Salut";
    timer->setInterval(16);
    qDebug() << connect(timer, SIGNAL(timeout()), this, SLOT(game_loop()));
    qDebug() << "Wesh";
    timer->start();*/

}

void Controller::startGame() {

    view->installScene();
    view->addVillage(this->model->setVillage(view));
    view->addForet1(this->model->setForet1(view));
    //view->addForet2(this->model->setForet2(view));

    PersoGentil *S1 = new PersoGentil("S1", 0, 0, 0, 10);
    model->addPersoGentil(S1);
    view->addPersoNormaux(S1);

    PersoGentil *S2 = new PersoGentil("S2", 50, 0, 0, 10);
    model->addPersoGentil(S2);
    view->addPersoNormaux(S2);

    PersoGentil *S3 = new PersoGentil("S3", 50, 50, 0, 10);
    model->addPersoGentil(S3);
    view->addPersoNormaux(S3);

    PersoGentil *S4 = new PersoGentil("S4", 100, 50, 0, 2);
    model->addPersoGentil(S4);
    view->addPersoNormaux(S4);

    PersoMechant *S5 = new PersoMechant("S5", 400, 50, 0, 2);
    model->addPersoMechant(S5);
    view->addPersoNormaux(S5);


    this->timer->start(16);
    this->timerBle->start(1000);

}

void Controller::gameLoop() {

    for (PersoGentil *S : *this->model->getlistSGentil()) {

        if (S->hasAction()) {
            ActionMove* nextAction = dynamic_cast<ActionMove*>(S->getFirstAction());

            S->setPos(S->getPosX() + nextAction->getDepX(), S->getPosY() + nextAction->getDepY());
            //delete nextAction;
            S->removeFirstAction();

            QList<QGraphicsItem *> listCollision = S->getImagePerso()->collidingItems();

            for (QGraphicsItem * i : listCollision) {

                ImageDecor *itemDecor = dynamic_cast<ImageDecor *>(i);

                if (itemDecor) {

                    QPointF *pointDestination = S->getDestination();
                    S->removeAllActions();

                    QPointF *pointSuivant = new QPointF(S->getPosX(), S->getPosY());

                    //qDebug() << "point SUivant 1 [" << pointSuivant->x() << ";" << pointSuivant->y() << "]";

                    //S->setPos(S->getPosX() - nextAction->getDepX(), S->getPosY() - nextAction->getDepY());

                    QPointF *pointOrigine = new QPointF(S->getPosX()-nextAction->getDepX(), S->getPosY()-nextAction->getDepY());

                    //qDebug() << "point Origine [" << pointOrigine->x() << ";" << pointOrigine->y() << "]";

                    pointSuivant = this->getPointDecale(pointOrigine, pointSuivant);

                    //qDebug() << "point SUivant 2 [" << pointSuivant->x() << ";" << pointSuivant->y() << "]";

                    //delete nextAction;

                    S->setPos(pointSuivant->x(), pointSuivant->y());
                    S->moveTo(pointDestination->x(), pointDestination->y());

                }

            }

            // Regarder s'il n'y a pas collision

            for (PersoMechant *M : *this->model->getlistSMechant()) {

                if (distanceEntrePersos(S, M) < 100) {

                    S->removeAllActions();

                }

            }

            // Si oui retour en arrière et décallage
            // Puis on regarde les ennemis
        }

    }

    for (PersoMechant *S : *this->model->getlistSMechant()) {

    }

}

int Controller::distanceEntrePersos(Perso *S, Perso *M) {

    return sqrt(pow((S->getPosX() - M->getPosX()), 2) + pow((S->getPosY() - M->getPosY()), 2));

}

QPointF *Controller::getPointDecale(QPointF *pointOrigine, QPointF *pointSuivant) {

    QPointF *nouveauPoint = new QPointF;
    double rayon = sqrt(pow((pointOrigine->x() - pointSuivant->x()), 2) + pow((pointOrigine->y() - pointSuivant->y()), 2));

    nouveauPoint->setX(pointOrigine->x() + (rayon * sin(M_PI + (M_PI / 3))));
    nouveauPoint->setY(pointOrigine->y() + (rayon * cos(M_PI + (M_PI / 3))));

    return nouveauPoint;

}


void Controller::actionPerso(int x, int y, int nbS) {
    this->model->actionPerso(x, y, nbS);
}

int Controller::getNbSFree() {
    return this->model->getNbSFree();
}

void Controller::recoltWheat() {

    /*Ressource *wheats = this->model->getSacBles();
    wheats->ajouterRessource(this->model->nbBleARecolter);*/
    this->model->getChampBle()->recolter(this->model->getSacBles());

}

void Controller::makeBred(int nbBred) {

    this->model->useWheat(nbBred * 2);
    this->model->makeBred(nbBred);

}
