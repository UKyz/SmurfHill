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

    /*PersoNormaux *S2 = new PersoNormaux("S1", 384, 138);
    view->addPersoNormaux(S2);*/

    /* TEST
    Image *arbre = new Image("/Users/Victor/Schtroumph-Hill/images/arbre_1.png");
    this->game->scene->addItem(arbre);
    arbre->setPos(200,400);
    Image *arbre_2 = new Image("/Users/Victor/Schtroumph-Hill/images/arbre_1.png");
    this->game->scene->addItem(arbre_2);
    arbre_2->setPos(320,400);
    Image *arbre_3 = new Image("/Users/Victor/Schtroumph-Hill/images/arbre_1.png");
    this->game->scene->addItem(arbre_3);
    arbre_3->setPos(260,420);
    Image *arbre_4 = new Image("/Users/Victor/Schtroumph-Hill/images/arbre_3.png");
    this->game->scene->addItem(arbre_4);
    arbre_4->setPos(0,400);*/

}

void Controller::actionPerso(int x, int y, int nbS) {
    this->model->actionPerso(x, y, nbS);
}
