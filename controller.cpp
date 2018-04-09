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

Controller::Controller(Model *model, View *view) :
    view(view)
{
    this->model = model;
    view->setControl(this);
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

    PersoMechant *S5 = new PersoMechant("S5", 150, 50, 0, 2);
    model->addPersoMechant(S5);
    view->addPersoNormaux(S5);

}

void Controller::actionPerso(int x, int y, int nbS) {
    this->model->actionPerso(x, y, nbS);
}

int Controller::getNbSFree() {
    return this->model->getNbSFree();
}
