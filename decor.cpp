#include "decor.h"
#include "view.h"

Decor::Decor(int posX, int posY, View *view): QObject() {

    this->posX = posX;
    this->posY = posY;
    this->view = view;

}

Village::Village(int posX, int posY, View *view): Decor(posX, posY, view) {

    this->maison1 = new Image("/Users/Victor/Schtroumph-Hill/images/maisonS1.png");
    this->maison2 = new Image("/Users/Victor/Schtroumph-Hill/images/maisonS2.png");
    this->maison3 = new Image("/Users/Victor/Schtroumph-Hill/images/maisonS3.png");
    this->maison4 = new Image("/Users/Victor/Schtroumph-Hill//images/maisonS4.png");
    this->maison5 = new Image("/Users/Victor/Schtroumph-Hill//images/maisonS5.png");
    this->maison6 = new Image("/Users/Victor/Schtroumph-Hill//images/maisonS6.png");
    this->maison7 = new Image("/Users/Victor/Schtroumph-Hill//images/maisonS7.png");
    this->maison8 = new Image("/Users/Victor/Schtroumph-Hill//images/maisonS8.png");
    this->maison9 = new Image("/Users/Victor/Schtroumph-Hill//images/maisonS9.png");
    this->grandS = new Image("/Users/Victor/Schtroumph-Hill//images/grandS.png");
    this->maisonSette = new Image("/Users/Victor/Schtroumph-Hill//images/maisonSette.png");
    this->maisonSCostaud = new Image("/Users/Victor/Schtroumph-Hill//images/maisonSCostaud.png");
    this->maisonSMusicien = new Image("/Users/Victor/Schtroumph-Hill//images/maisonSMusicien.png");
    this->maisonSPaysan = new Image("/Users/Victor/Schtroumph-Hill//images/maisonSPaysan.png");
    this->moulinS = new Image("/Users/Victor/Schtroumph-Hill//images/moulinS.png");
    this->puits = new Image("/Users/Victor/Schtroumph-Hill//images/puits.png");
    this->arbre1 = new Image("/Users/Victor/Schtroumph-Hill//images/arbre_1.png");
    this->arbre2 = new Image("/Users/Victor/Schtroumph-Hill//images/arbre_1.png");

    connect(this->maisonSette, SIGNAL(clicked()), this->view, SLOT(displayMessageSette()));
    connect(this->grandS, SIGNAL(clicked()), this->view, SLOT(displayMessageGrandS()));
    connect(this->maisonSMusicien, SIGNAL(clicked()), this->view, SLOT(musique()));

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

}
