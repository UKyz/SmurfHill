#include "decor.h"
#include "view.h"

Decor::Decor(int posX, int posY, View *view): QObject() {

    this->posX = posX;
    this->posY = posY;
    this->view = view;

}

Village::Village(int posX, int posY, View *view): Decor(posX, posY, view) {

    this->maison1 = new ImageDecor(":/images/maisonS1");
    this->maison2 = new ImageDecor(":/images/maisonS2");
    this->maison3 = new ImageDecor(":/images/maisonS3");
    this->maison4 = new ImageDecor(":/images/maisonS4");
    this->maison5 = new ImageDecor(":/images/maisonS5");
    this->maison6 = new ImageDecor(":/images/maisonS6");
    this->maison7 = new ImageDecor(":/images/maisonS7");
    this->maison8 = new ImageDecor(":/images/maisonS8");
    this->maison9 = new ImageDecor(":/images/maisonS9");
    this->grandS = new ImageDecor(":/images/grandS");
    this->maisonSette = new ImageDecor("://images/maisonSette");
    this->maisonSCostaud = new ImageDecor("://images/maisonSCostaud");
    this->maisonSMusicien = new ImageDecor("://images/maisonSMusicien");
    this->maisonSPaysan = new ImageDecor("://images/maisonSPaysan");
    this->moulinS = new ImageDecor("://images/moulinS");
    this->puits = new ImageDecor("://images/puits");
    this->arbre1 = new ImageDecor("://images/arbre_1");
    this->arbre2 = new ImageDecor("://images/arbre_1");

    connect(this->maisonSette, SIGNAL(clicked()), this->view, SLOT(displayMessageSette()));
    connect(this->grandS, SIGNAL(clicked()), this->view, SLOT(displayMessageGrandS()));
    connect(this->maisonSMusicien, SIGNAL(clicked()), this->view, SLOT(musique()));
    connect(this->maisonSPaysan, SIGNAL(clicked()), this->view, SLOT(displayActionPaysan()));
    connect(this->maisonSCostaud, SIGNAL(clicked()), this->view, SLOT(displayActionCostaud()));

    this->grandS->setPos(posX + 145, posY + 85);
    this->maison1->setPos(posX + 200, posY - 40);
    this->maison2->setPos(posX - 100, posY - 10);
    this->maison3->setPos(posX - 20, posY + 25);
    this->maison4->setPos(posX + 325, posY - 70);
    this->maison5->setPos(posX + 150, posY - 100);
    this->maison6->setPos(posX + 270, posY + 190);
    this->maison7->setPos(posX + 5, posY - 80);
    this->maison8->setPos(posX + 155, posY + 175);
    this->maison9->setPos(posX - 120, posY + 80);
    this->maisonSette->setPos(posX + 105, posY -10);
    this->maisonSCostaud->setPos(posX + 300, posY + 25);
    this->maisonSMusicien->setPos(posX, posY+ 125);
    this->maisonSPaysan->setPos(posX + 425, posY + 100);
    this->moulinS->setPos(posX + 470, posY - 55);
    this->puits->setPos(posX + 170, posY + 100);
    this->arbre1->setPos(posX + 320, posY + 170);
    this->arbre2->setPos(posX + 400, posY + 100);

}

Foret::Foret(int posX, int posY, View *view): Decor(posX, posY, view) {
    nbNoisette = 10;
    nbBaie = 0;
    nbBle = 0;

    this->noisette = new ImageDecor(":/images/noisette");
    this->baie = new ImageDecor(":/images/baie");
    this->ble = new ImageDecor(":/images/ble");
}

void Foret::onResourceWheatClicked() {this->view->onResourceWheatClicked(this->ble->pos(), nbBle);}
void Foret::onResourceAcornClicked() {this->view->onResourceAcornClicked(this->noisette->pos(), nbNoisette);}
void Foret::onResourceBayClicked() {this->view->onResourceBayClicked(this->baie->pos(), nbBaie);}

Foret1::Foret1(int posX, int posY, View *view): Foret(posX, posY, view) {
    this->arbre1 = new ImageDecor(":/images/arbre1");
    this->arbre2 = new ImageDecor(":/images/arbre1");
    this->arbre3 = new ImageDecor(":/images/arbre1");
    this->arbre4 = new ImageDecor(":/images/arbre6");
    this->arbre5 = new ImageDecor(":/images/arbre4");
    this->arbre6 = new ImageDecor(":/images/arbre6");
    this->arbre7 = new ImageDecor(":/images/arbre6");
    this->arbre8 = new ImageDecor(":/images/arbre2");
    this->arbre9 = new ImageDecor(":/images/arbre7");
    this->arbre10 = new ImageDecor(":/images/arbre2");
    this->arbre11 = new ImageDecor(":/images/arbre2");
    this->arbre12 = new ImageDecor(":/images/arbre2");
    this->arbre13 = new ImageDecor(":/images/arbre7");
    this->arbre14 = new ImageDecor(":/images/arbre6");
    this->arbre15 = new ImageDecor(":/images/arbre6");
    this->arbre16 = new ImageDecor(":/images/arbre7");
    this->arbre17 = new ImageDecor(":/images/arbre10");

    this->buisson1 = new ImageDecor(":/images/buisson1");
    this->buisson2 = new ImageDecor(":/images/buisson2");
    this->buissonbaies1 = new ImageDecor(":/images/buissonbaies");
    this->buissonbaies2 = new ImageDecor(":/images/buissonbaies");

    this->arbre1->setPos(posX - 35, posY - 35);
    this->arbre2->setPos(posX + 175, posY - 100);
    this->arbre3->setPos(posX + 45, posY + 60);
    this->arbre4->setPos(posX, posY);
    this->arbre5->setPos(posX + 155, posY - 55);
    this->arbre6->setPos(posX + 220, posY - 50);
    this->arbre7->setPos(posX - 30, posY + 55);
    this->arbre8->setPos(posX + 140, posY - 80);
    this->arbre9->setPos(posX - 100, posY + 10);
    this->arbre10->setPos(posX + 100, posY + 110);
    this->arbre11->setPos(posX + 120, posY + 110);
    this->arbre12->setPos(posX + 110, posY + 120);
    this->arbre13->setPos(posX + 250, posY - 30);
    this->arbre14->setPos(posX + 200, posY - 130);
    this->arbre15->setPos(posX + 250, posY - 100);
    this->arbre16->setPos(posX + 120, posY - 120);
    this->arbre17->setPos(posX - 100, posY - 50);

    this->buisson1->setPos(posX + 260, posY + 40);
    this->buisson2->setPos(posX + 15, posY + 140);
    this->buissonbaies1->setPos(posX + 170, posY - 10);
    this->buissonbaies2->setPos(posX + 10, posY + 110);

    this->noisette->setPos(posX + 125, posY - 25);
    this->baie->setPos(posX + 110, posY + 80);
    this->ble->setPos(posX + 220, posY + 30);

    connect(this->noisette, SIGNAL(clicked()), SLOT(onResourceAcornClicked()));
    connect(this->baie, SIGNAL(clicked()), SLOT(onResourceBayClicked()));
    connect(this->ble, SIGNAL(clicked()), SLOT(onResourceWheatClicked()));
}

/*
Foret2::Foret2(int posX, int posY, View *view): Foret(posX, posY, view) {
    this->arbre1 = new Image(":/images/arbre8");
    this->arbre2 = new Image(":/images/arbre9");
    this->arbre3 = new Image(":/images/arbre9");
    this->arbre4 = new Image(":/images/arbre9");
    this->arbre5 = new Image(":/images/arbre9");
    this->arbre6 = new Image(":/images/arbre8");
    this->arbre7 = new Image(":/images/arbre8");
    this->arbre8 = new Image(":/images/arbre9");
    this->arbre9 = new Image(":/images/arbre8");
    this->arbre10 = new Image(":/images/arbre9");

    this->arbre1->setPos(posX, posY);
    this->arbre2->setPos(posX - 60, posY + 20);
    this->arbre3->setPos(posX + 60, posY + 10);
    this->arbre4->setPos(posX - 40, posY + 40);
    this->arbre5->setPos(posX + 60, posY);
    this->arbre6->setPos(posX + 90, posY + 30);
    this->arbre7->setPos(posX, posY);
    this->arbre8->setPos(posX, posY);
    this->arbre9->setPos(posX, posY);
    this->arbre10->setPos(posX, posY);
}
*/
