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

    PersoNormaux *S1 = new PersoNormaux("S1", 0, 0, 0, 10);
    model->addPerso(S1);
    view->addPersoNormaux(S1);

    PersoNormaux *S2 = new PersoNormaux("S2", 50, 0, 0, 10);
    model->addPerso(S2);
    view->addPersoNormaux(S2);

    PersoNormaux *S3 = new PersoNormaux("S3", 50, 50, 0, 10);
    model->addPerso(S3);
    view->addPersoNormaux(S3);

    PersoNormaux *S4 = new PersoNormaux("S4", 100, 50, 0, 2);
    model->addPerso(S4);
    view->addPersoNormaux(S4);

}

void Controller::actionPerso(int x, int y, int nbS) {
    this->model->actionPerso(x, y, nbS);
}

int Controller::getNbSFree() {
    return this->model->getNbSFree();
}
