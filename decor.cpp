#include "decor.h"
#include "view.h"

Decor::Decor(int posX, int posY, View *view): QObject() {

    this->posX = posX;
    this->posY = posY;
    this->view = view;

}

Village::Village(int posX, int posY, View *view): Decor(posX, posY, view) {

    //this->maison1 = new Image("/Users/Victor/Schtroumph-Hill/images/maisonS2.png");
    this->arbre1 = new Image("/Users/Victor/Schtroumph-Hill/images/arbre_1.png");
    this->grandS = new Image("/Users/Victor/Schtroumph-Hill/images/grandS.png");
    this->maison2 = new Image("/Users/Victor/Schtroumph-Hill/images/maisonS2.png");
    this->maison3 = new Image("/Users/Victor/Schtroumph-Hill/images/maisonS3.png");
    this->maison4 = new Image("/Users/Victor/Schtroumph-Hill/images/maisonS4.png");
    this->maison5 = new Image("/Users/Victor/Schtroumph-Hill/images/maisonS5.png");
    this->maisonSette = new Image("/Users/Victor/Schtroumph-Hill/images/maisonSette.png");
    connect(this->maisonSette, SIGNAL(clicked()), this->view, SLOT(test()));
    this->maisonSCostaud = new Image("/Users/Victor/Schtroumph-Hill/images/maisonSCostaud.png");
    this->maisonSPaysan = new Image("/Users/Victor/Schtroumph-Hill/images/maisonSPaysan.png");
    this->moulinS = new Image("/Users/Victor/Schtroumph-Hill/images/moulinS.png");

    this->grandS->setPos(posX + 160, posY + 85);
    this->maison2->setPos(posX, posY + 25);
    this->maison3->setPos(posX + 550, posY + 200);
    this->maison4->setPos(posX + 230, posY + 5);
    this->maison5->setPos(posX + 55, posY + 100);
    this->arbre1->setPos(posX, posY + 105);
    this->maisonSette->setPos(posX + 105, posY -10);
    this->maisonSCostaud->setPos(posX + 330, posY + 40);
    this->maisonSPaysan->setPos(posX + 450, posY - 50);
    this->moulinS->setPos(posX + 210, posY + 100);

}

Foret::Foret(int posX, int posY, View *view): Decor(posX, posY, view) {



}
