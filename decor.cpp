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
    this->noisette = new Image("/Users/Alexia/Documents/ihm/images/noisette.png");
    this->baie = new Image("/Users/Alexia/Documents/ihm/images/baie.png");
    this->ble = new Image("/Users/Alexia/Documents/ihm/images/ble.png");
}

Foret1::Foret1(int posX, int posY, View *view): Foret(posX, posY, view) {
    this->arbre1 = new Image("/Users/Alexia/Documents/ihm/images/arbre1.png");
    this->arbre2 = new Image("/Users/Alexia/Documents/ihm/images/arbre1.png");
    this->arbre3 = new Image("/Users/Alexia/Documents/ihm/images/arbre1.png");
    this->arbre4 = new Image("/Users/Alexia/Documents/ihm/images/arbre6.png");
    this->arbre5 = new Image("/Users/Alexia/Documents/ihm/images/arbre4.png");
    this->arbre6 = new Image("/Users/Alexia/Documents/ihm/images/arbre6.png");
    this->arbre7 = new Image("/Users/Alexia/Documents/ihm/images/arbre6.png");
    this->arbre8 = new Image("/Users/Alexia/Documents/ihm/images/arbre2.png");
    this->arbre9 = new Image("/Users/Alexia/Documents/ihm/images/arbre7.png");
    this->arbre10 = new Image("/Users/Alexia/Documents/ihm/images/arbre2.png");
    this->arbre11 = new Image("/Users/Alexia/Documents/ihm/images/arbre2.png");
    this->arbre12 = new Image("/Users/Alexia/Documents/ihm/images/arbre2.png");
    this->arbre13 = new Image("/Users/Alexia/Documents/ihm/images/arbre7.png");
    this->arbre14 = new Image("/Users/Alexia/Documents/ihm/images/arbre6.png");
    this->arbre15 = new Image("/Users/Alexia/Documents/ihm/images/arbre6.png");
    this->arbre16 = new Image("/Users/Alexia/Documents/ihm/images/arbre7.png");
    this->arbre17 = new Image("/Users/Alexia/Documents/ihm/images/arbre10.png");

    this->buisson1 = new Image("/Users/Alexia/Documents/ihm/images/buisson1.png");
    this->buisson2 = new Image("/Users/Alexia/Documents/ihm/images/buisson2.png");
    this->buissonbaies1 = new Image("/Users/Alexia/Documents/ihm/images/buissonbaies.png");
    this->buissonbaies2 = new Image("/Users/Alexia/Documents/ihm/images/buissonbaies.png");

    this->arbre1->setPos(posX - 35, posY - 35);
    this->arbre2->setPos(posX + 175, posY - 100);
    this->arbre3->setPos(posX + 45, posY + 60);
    this->arbre4->setPos(posX, posY);
    this->arbre5->setPos(posX + 150, posY - 60);
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
}

/*
Foret2::Foret2(int posX, int posY, View *view): Foret(posX, posY, view) {
    this->arbre1 = new Image("/Users/Alexia/Documents/ihm/images/arbre8.png");
    this->arbre2 = new Image("/Users/Alexia/Documents/ihm/images/arbre9.png");
    this->arbre3 = new Image("/Users/Alexia/Documents/ihm/images/arbre9.png");
    this->arbre4 = new Image("/Users/Alexia/Documents/ihm/images/arbre9.png");
    this->arbre5 = new Image("/Users/Alexia/Documents/ihm/images/arbre9.png");
    this->arbre6 = new Image("/Users/Alexia/Documents/ihm/images/arbre8.png");
    this->arbre7 = new Image("/Users/Alexia/Documents/ihm/images/arbre8.png");
    this->arbre8 = new Image("/Users/Alexia/Documents/ihm/images/arbre9.png");
    this->arbre9 = new Image("/Users/Alexia/Documents/ihm/images/arbre8.png");
    this->arbre10 = new Image("/Users/Alexia/Documents/ihm/images/arbre9.png");

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
