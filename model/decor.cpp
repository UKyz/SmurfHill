#include "decor.h"
#include "../view/view.h"

Setting::Setting(QString type, int posX, int posY, View *view): QObject() {
    this->type = type;
    this->posX = posX;
    this->posY = posY;
    this->view = view;
}

Village::Village(QString type, int posX, int posY, View *view): Setting(type, posX, posY, view) {
    // Houses
    this->house1 = new ImageSetting(":/images/maisonS1");
    this->house2 = new ImageSetting(":/images/maisonS2");
    this->house3 = new ImageSetting(":/images/maisonS3");
    this->house4 = new ImageSetting(":/images/maisonS4");
    this->house5 = new ImageSetting(":/images/maisonS5");
    this->house6 = new ImageSetting(":/images/maisonS6");
    this->house7 = new ImageSetting(":/images/maisonS7");
    this->house8 = new ImageSetting(":/images/maisonS8");
    this->house9 = new ImageSetting(":/images/maisonS9");
    this->house10 = new ImageSetting(":/images/maisonS10");
    this->house11 = new ImageSetting(":/images/maisonS11");
    this->house12 = new ImageSetting(":/images/maisonS12");
    this->papaSmurf = new ImageSetting(":/images/grandS");
    this->brainy = new ImageSetting(":/images/lunettesS");
    this->doctor = new ImageSetting(":/images/docteurS");
    this->houseSmurfette = new ImageSetting(":/images/maisonSette");
    this->houseHefty = new ImageSetting(":/images/maisonSCostaud");
    this->houseMusician = new ImageSetting(":/images/maisonSMusicien");
    this->houseFarmer = new ImageSetting(":/images/maisonSPaysan");
    this->houseBaker = new ImageSetting(":/images/maisonSBoulanger");
    this->mill = new ImageSetting(":/images/moulinS");
    this->well = new ImageSetting(":/images/puits");
    this->inventory = new ImageSetting(":/images/reserveS");
    // Trees
    this->tree1 = new ImageSetting(":/images/arbre9");
    this->tree2 = new ImageSetting(":/images/arbre9");
    this->tree3 = new ImageSetting(":/images/arbre9");
    this->tree4 = new ImageSetting(":/images/arbre8");
    this->tree5 = new ImageSetting(":/images/arbre8");
    this->tree6 = new ImageSetting(":/images/arbre9");
    this->tree7 = new ImageSetting(":/images/arbre9");
    this->tree8 = new ImageSetting(":/images/arbre9");
    this->tree9 = new ImageSetting(":/images/arbre8");
    this->tree10 = new ImageSetting(":/images/arbre9");
    this->tree11 = new ImageSetting(":/images/arbre8");
    this->tree12 = new ImageSetting(":/images/arbre8");
    this->tree13 = new ImageSetting(":/images/arbre9");
    this->tree14 = new ImageSetting(":/images/arbre9");
    this->tree15 = new ImageSetting(":/images/arbre9");
    // Bush
    this->bush1 = new ImageSetting(":/images/buisson1");
    this->bush2 = new ImageSetting(":/images/buisson1");
    this->bush3 = new ImageSetting(":/images/buisson1");
    this->bush4 = new ImageSetting(":/images/buisson2");
    this->bush5 = new ImageSetting(":/images/buisson2");
    this->bush6 = new ImageSetting(":/images/buisson1");
    this->bush7 = new ImageSetting(":/images/buisson2");
    this->bush8 = new ImageSetting(":/images/buisson1");
    this->bush9 = new ImageSetting(":/images/buisson1");

    connect(this->houseSmurfette, SIGNAL(clicked()), this->view, SLOT(displayMessageSmurfette()));
    connect(this->papaSmurf, SIGNAL(clicked()), this->view, SLOT(displayMessagePapaSmurf()));
    connect(this->brainy, SIGNAL(clicked()), this->view, SLOT(displayMessageBrainy()));
    connect(this->houseMusician, SIGNAL(clicked()), this->view, SLOT(music()));
    connect(this->houseFarmer, SIGNAL(clicked()), this->view, SLOT(displayActionFarmer()));
    connect(this->houseBaker, SIGNAL(clicked()), this->view, SLOT(displayActionBaker()));
    connect(this->houseHefty, SIGNAL(clicked()), this->view, SLOT(displayActionHefty()));
    connect(this->doctor, SIGNAL(clicked()), this->view, SLOT(displayActionDoctor()));
    connect(this->inventory, SIGNAL(clicked()), this->view, SLOT(inventoryContents()));

    this->papaSmurf->setPos(posX + 145, posY + 85);
    this->brainy->setPos(posX + 240, posY + 110);
    this->doctor->setPos(posX + 300, posY + 140);
    this->house1->setPos(posX + 200, posY - 40);
    this->house2->setPos(posX - 100, posY - 10);
    this->house3->setPos(posX - 20, posY + 25);
    this->house4->setPos(posX + 325, posY - 70);
    this->house5->setPos(posX + 150, posY - 100);
    this->house6->setPos(posX + 270, posY + 210);
    this->house7->setPos(posX + 5, posY - 80);
    this->house8->setPos(posX + 155, posY + 195);
    this->house9->setPos(posX - 120, posY + 80);
    this->house10->setPos(posX + 40, posY + 240);
    this->house11->setPos(posX - 80, posY + 170);
    this->house12->setPos(posX + 395, posY + 220);
    this->houseSmurfette->setPos(posX + 105, posY - 10);
    this->houseHefty->setPos(posX + 300, posY + 25);
    this->houseMusician->setPos(posX, posY+ 125);
    this->houseFarmer->setPos(posX + 425, posY + 100);
    this->houseBaker->setPos(posX + 430, posY - 20);
    this->mill->setPos(posX + 560, posY - 40);
    this->well->setPos(posX + 170, posY + 100);
    this->inventory->setPos(posX + 530, posY + 120);

    this->tree1->setPos(posX + 370, posY - 135);
    this->tree2->setPos(posX + 300, posY - 125);
    this->tree3->setPos(posX + 260, posY - 115);
    this->tree4->setPos(posX + 320, posY - 110);
    this->tree5->setPos(posX + 430, posY - 140);
    this->tree6->setPos(posX + 400, posY - 100);
    this->tree7->setPos(posX + 480, posY - 120);
    this->tree8->setPos(posX + 540, posY - 110);
    this->tree9->setPos(posX + 450, posY - 80);
    this->tree10->setPos(posX + 500, posY - 75);
    this->tree11->setPos(posX + 590, posY - 85);
    this->tree12->setPos(posX + 545, posY - 60);
    this->tree13->setPos(posX + 95, posY - 120);
    this->tree14->setPos(posX- 25, posY - 90);
    this->tree15->setPos(posX - 60, posY - 70);

    this->bush1->setPos(posX + 550, posY + 120);
    this->bush2->setPos(posX + 660, posY + 160);
    this->bush3->setPos(posX + 60, posY + 40);
    this->bush4->setPos(posX + 75, posY + 75);
    this->bush5->setPos(posX + 235, posY + 290);
    this->bush6->setPos(posX - 120, posY + 80);
    this->bush7->setPos(posX - 140, posY + 100);
    this->bush8->setPos(posX - 130, posY + 120);
    this->bush9->setPos(posX + 250, posY + 260);

}

Forest1::Forest1(QString type, int posX, int posY, View *view): Forest(type, posX, posY, view) {
    this->tree1 = new ImageSetting(":/images/arbre1");
    this->tree2 = new ImageSetting(":/images/arbre1");
    this->tree3 = new ImageSetting(":/images/arbre1");
    this->tree4 = new ImageSetting(":/images/arbre6");
    this->tree5 = new ImageSetting(":/images/arbre4");
    this->tree6 = new ImageSetting(":/images/arbre6");
    this->tree7 = new ImageSetting(":/images/arbre6");
    this->tree8 = new ImageSetting(":/images/arbre2");
    this->tree9 = new ImageSetting(":/images/arbre7");
    this->tree10 = new ImageSetting(":/images/arbre2");
    this->tree11 = new ImageSetting(":/images/arbre2");
    this->tree12 = new ImageSetting(":/images/arbre2");
    this->tree13 = new ImageSetting(":/images/arbre7");
    this->tree14 = new ImageSetting(":/images/arbre6");
    this->tree15 = new ImageSetting(":/images/arbre6");
    this->tree16 = new ImageSetting(":/images/arbre7");
    this->tree17 = new ImageSetting(":/images/arbre10");

    this->bush1 = new ImageSetting(":/images/buisson1");
    this->bush2 = new ImageSetting(":/images/buisson2");
    this->bushBerries1 = new ImageSetting(":/images/buissonbaies");
    this->bushBerries2 = new ImageSetting(":/images/buissonbaies");

    this->tree1->setPos(posX - 35, posY - 35);
    this->tree2->setPos(posX + 175, posY - 100);
    this->tree3->setPos(posX + 45, posY + 60);
    this->tree4->setPos(posX, posY);
    this->tree5->setPos(posX + 155, posY - 55);
    this->tree6->setPos(posX + 220, posY - 50);
    this->tree7->setPos(posX - 30, posY + 55);
    this->tree8->setPos(posX + 140, posY - 80);
    this->tree9->setPos(posX - 100, posY + 10);
    this->tree10->setPos(posX + 100, posY + 110);
    this->tree11->setPos(posX + 120, posY + 110);
    this->tree12->setPos(posX + 110, posY + 120);
    this->tree13->setPos(posX + 250, posY - 30);
    this->tree14->setPos(posX + 200, posY - 130);
    this->tree15->setPos(posX + 250, posY - 100);
    this->tree16->setPos(posX + 120, posY - 120);
    this->tree17->setPos(posX - 100, posY - 50);

    this->bush1->setPos(posX + 260, posY + 40);
    this->bush2->setPos(posX + 15, posY + 140);
    this->bushBerries1->setPos(posX + 170, posY - 10);
    this->bushBerries2->setPos(posX + 10, posY + 110);

    this->posXAcorn = posX + 125;
    this->posYAcorn = posY - 25;
    this->posXBerries = posX + 110;
    this->posYBerries = posY + 80;
    this->posXWheat = posX + 220;
    this->posYWheat = posY + 30;
}

Forest2::Forest2(QString type, int posX, int posY, View *view): Forest(type, posX, posY, view) {

    this->tree01 = new ImageSetting(":/images/arbre9");
    this->tree02 = new ImageSetting(":/images/arbre8");
    this->tree03 = new ImageSetting(":/images/arbre8");
    this->tree04 = new ImageSetting(":/images/arbre9");
    this->tree05 = new ImageSetting(":/images/arbre9");
    this->tree06 = new ImageSetting(":/images/arbre9");
    this->tree07 = new ImageSetting(":/images/arbre8");
    this->tree1 = new ImageSetting(":/images/arbre8");
    this->tree2 = new ImageSetting(":/images/arbre9");
    this->tree3 = new ImageSetting(":/images/arbre9");
    this->tree4 = new ImageSetting(":/images/arbre9");
    this->tree5 = new ImageSetting(":/images/arbre8");
    this->tree6 = new ImageSetting(":/images/arbre9");
    this->tree7 = new ImageSetting(":/images/arbre8");
    this->tree8 = new ImageSetting(":/images/arbre9");
    this->tree9 = new ImageSetting(":/images/arbre9");
    this->tree10 = new ImageSetting(":/images/arbre9");
    this->tree11 = new ImageSetting(":/images/arbre8");
    this->tree12 = new ImageSetting(":/images/arbre8");
    this->tree13 = new ImageSetting(":/images/arbre8");
    this->tree14 = new ImageSetting(":/images/arbre9");

    this->bushBerries1 = new ImageSetting(":/images/buissonbaies");
    this->bush1 = new ImageSetting(":/images/buisson2");
    this->bush2 = new ImageSetting(":/images/buisson2");
    this->bush3 = new ImageSetting(":/images/buisson1");

    this->tree01->setPos(posX - 30, posY - 40);
    this->tree02->setPos(posX - 80, posY - 20);
    this->tree03->setPos(posX - 115, posY + 5);
    this->tree04->setPos(posX - 140, posY + 40);
    this->tree05->setPos(posX + 25, posY - 35);
    this->tree06->setPos(posX + 70, posY - 20);
    this->tree07->setPos(posX + 120, posY + 20);
    this->tree1->setPos(posX, posY);
    this->tree2->setPos(posX - 60, posY + 20);
    this->tree3->setPos(posX + 100, posY);
    this->tree4->setPos(posX - 90, posY + 40);
    this->tree5->setPos(posX + 60, posY + 10);
    this->tree6->setPos(posX + 160, posY + 40);
    this->tree7->setPos(posX - 130, posY + 80);
    this->tree8->setPos(posX - 80, posY + 90);
    this->tree9->setPos(posX + 140, posY + 50);
    this->tree10->setPos(posX - 80, posY + 90);
    this->tree11->setPos(posX - 120, posY + 120);
    this->tree12->setPos(posX + 160, posY + 70);
    this->tree13->setPos(posX - 100, posY + 150);
    this->tree14->setPos(posX - 70, posY + 170);

    this->bushBerries1->setPos(posX + 105, posY + 85);
    this->bush1->setPos(posX - 85, posY + 250);
    this->bush2->setPos(posX + 160, posY + 160);
    this->bush3->setPos(posX, posY + 90);

    this->posXAcorn = posX + 50;
    this->posYAcorn = posY + 90;
    this->posXBerries = posX + 130;
    this->posYBerries = posY + 140;
    this->posXWheat = posX;
    this->posYWheat = posY + 200;
}

Forest3::Forest3(QString type, int posX, int posY, View *view): Forest(type, posX, posY, view) {
    this->tree01 = new ImageSetting(":/images/arbre7");
    this->tree02 = new ImageSetting(":/images/arbre7");
    this->tree1 = new ImageSetting(":/images/arbre10");
    this->tree1 = new ImageSetting(":/images/arbre7");
    this->tree2 = new ImageSetting(":/images/arbre10");
    this->tree3 = new ImageSetting(":/images/arbre10");
    this->tree4 = new ImageSetting(":/images/arbre10");
    this->tree5 = new ImageSetting(":/images/arbre7");
    this->tree6 = new ImageSetting(":/images/arbre6");
    this->tree7 = new ImageSetting(":/images/arbre6");
    this->tree8 = new ImageSetting(":/images/arbre6");
    this->tree9 = new ImageSetting(":/images/arbre6");
    this->tree10 = new ImageSetting(":/images/arbre7");
    this->tree11 = new ImageSetting(":/images/arbre6");
    this->tree12 = new ImageSetting(":/images/arbre10");
    this->tree13 = new ImageSetting(":/images/arbre10");
    this->tree14 = new ImageSetting(":/images/arbre10");
    this->tree15 = new ImageSetting(":/images/arbre7");
    this->tree16 = new ImageSetting(":/images/arbre6");
    this->tree17 = new ImageSetting(":/images/arbre6");

    this->bushBerries1 = new ImageSetting(":/images/buissonbaies");
    this->bushBerries2 = new ImageSetting(":/images/buissonbaies");
    this->bushBerries3 = new ImageSetting(":/images/buissonbaies");
    this->bush1 = new ImageSetting(":/images/buisson2");
    this->bush2 = new ImageSetting(":/images/buisson2");
    this->souche1 = new ImageSetting(":/images/souche2");


    this->tree01->setPos(posX - 110, posY - 50);
    this->tree02->setPos(posX - 140, posY - 10);
    this->tree1->setPos(posX - 60, posY - 90);
    this->tree2->setPos(posX + 20, posY - 90);
    this->tree3->setPos(posX + 300, posY - 90);
    this->tree4->setPos(posX + 230, posY - 80);
    this->tree5->setPos(posX + 260, posY - 50);
    this->tree6->setPos(posX + 320, posY - 20);
    this->tree7->setPos(posX, posY - 50);
    this->tree8->setPos(posX + 50, posY - 40);
    this->tree9->setPos(posX - 45, posY - 25);
    this->tree10->setPos(posX, posY);
    this->tree11->setPos(posX + 250, posY);
    this->tree12->setPos(posX - 60, posY + 30);
    this->tree13->setPos(posX - 30, posY + 45);
    this->tree14->setPos(posX + 300, posY + 25);
    this->tree15->setPos(posX + 230, posY + 40);
    this->tree16->setPos(posX - 110, posY + 55);
    this->tree17->setPos(posX - 60, posY + 80);

    this->bushBerries1->setPos(posX + 220, posY - 25);
    this->bushBerries2->setPos(posX + 10, posY + 80);
    this->bushBerries3->setPos(posX - 140, posY + 50);
    this->bush1->setPos(posX + 250, posY + 100);
    this->bush2->setPos(posX + 300, posY + 110);
    this->souche1->setPos(posX + 15, posY + 140);

    this->posXAcorn = posX - 5;
    this->posYAcorn = posY + 160;
    this->posXBerries = posX + 70;
    this->posYBerries = posY + 70;
    this->posXWheat = posX + 250;
    this->posYWheat = posY + 120;
}

Forest4::Forest4(QString type, int posX, int posY, View *view): Forest(type, posX, posY, view) {
    this->tree1 = new ImageSetting(":/images/arbreM1");
    this->tree2 = new ImageSetting(":/images/arbreM4");
    this->tree3 = new ImageSetting(":/images/arbreM3");
    this->tree4 = new ImageSetting(":/images/arbreM2");
    this->tree5 = new ImageSetting(":/images/arbreM3");
    this->tree6 = new ImageSetting(":/images/arbreM3");
    this->tree7 = new ImageSetting(":/images/arbreM2");
    this->tree8 = new ImageSetting(":/images/arbreM1");
    this->tree9 = new ImageSetting(":/images/arbreM1");
    this->tree10 = new ImageSetting(":/images/arbreM1");

    this->tree11 = new ImageSetting(":/images/arbreM4");
    this->tree12 = new ImageSetting(":/images/arbreM5");
    this->tree13 = new ImageSetting(":/images/arbreM5");
    this->tree14 = new ImageSetting(":/images/arbreM1");
    this->tree15 = new ImageSetting(":/images/arbreM4");
    this->tree16 = new ImageSetting(":/images/arbreM3");
    this->tree17 = new ImageSetting(":/images/arbreM3");
    this->tree18 = new ImageSetting(":/images/arbreM3");
    this->tree19 = new ImageSetting(":/images/arbreM5");
    this->tree20 = new ImageSetting(":/images/arbreM5");

    this->tree21 = new ImageSetting(":/images/arbreM4");
    this->tree22 = new ImageSetting(":/images/arbreM2");
    this->tree23 = new ImageSetting(":/images/arbreM1");
    this->tree24 = new ImageSetting(":/images/arbreM1");
    this->tree25 = new ImageSetting(":/images/arbreM3");

    this->bushBerries1 = new ImageSetting(":/images/buissonbaies");
    this->bush1 = new ImageSetting(":/images/buisson1");
    this->bush2 = new ImageSetting(":/images/buisson1");
    this->bush3 = new ImageSetting(":/images/buisson2");
    this->bush4 = new ImageSetting(":/images/buisson1");
    this->bush5 = new ImageSetting(":/images/buisson2");
    this->bush6 = new ImageSetting(":/images/buisson1");
    this->bush7 = new ImageSetting(":/images/buisson1");
    this->bush8 = new ImageSetting(":/images/buisson2");
    this->bush9 = new ImageSetting(":/images/buisson2");

    this->tree1->setPos(posX, posY);
    this->tree2->setPos(posX + 200, posY - 40);
    this->tree3->setPos(posX - 40, posY + 30);
    this->tree4->setPos(posX + 175, posY + 25);
    this->tree5->setPos(posX + 240, posY + 30);
    this->tree6->setPos(posX + 10, posY + 50);
    this->tree7->setPos(posX - 60, posY + 90);
    this->tree8->setPos(posX + 200, posY + 60);
    this->tree9->setPos(posX + 220, posY + 75);
    this->tree10->setPos(posX + 250, posY + 65);

    this->tree11->setPos(posX + 260, posY + 55);
    this->tree12->setPos(posX + 185, posY + 105);
    this->tree13->setPos(posX - 10, posY + 100);
    this->tree14->setPos(posX + 250, posY + 130);
    this->tree15->setPos(posX - 105, posY + 100);
    this->tree16->setPos(posX + 200, posY + 150);
    this->tree17->setPos(posX + 270, posY + 145);
    this->tree18->setPos(posX + 220, posY + 160);
    this->tree19->setPos(posX + 165, posY + 175);
    this->tree20->setPos(posX + 200, posY + 195);

    this->tree21->setPos(posX + 250, posY + 170);
    this->tree22->setPos(posX + 150, posY + 230);
    this->tree23->setPos(posX + 120, posY + 250);
    this->tree24->setPos(posX + 150, posY + 270);
    this->tree25->setPos(posX + 210, posY + 250);

    this->bushBerries1->setPos(posX + 300, posY + 300);
    this->bush1->setPos(posX - 10, posY + 140);
    this->bush2->setPos(posX + 10, posY + 150);
    this->bush3->setPos(posX + 250, posY + 160);
    this->bush4->setPos(posX - 50, posY + 190);
    this->bush5->setPos(posX - 20, posY + 200);
    this->bush6->setPos(posX + 280, posY + 185);
    this->bush7->setPos(posX + 310, posY + 190);
    this->bush8->setPos(posX + 200, posY + 210);
    this->bush9->setPos(posX + 250, posY + 310);

    this->posXAcorn = posX + 50;
    this->posYAcorn = posY + 160;
    this->posXBerries = posX + 180;
    this->posYBerries = posY + 170;
    this->posXWheat = posX - 40;
    this->posYWheat = posY + 230;
}

Forest5::Forest5(QString type, int posX, int posY, View *view): Forest(type, posX, posY, view) {
    this->tree1 = new ImageSetting(":/images/arbre9");
    this->tree2 = new ImageSetting(":/images/arbre8");
    this->tree3 = new ImageSetting(":/images/arbre9");
    this->tree4 = new ImageSetting(":/images/arbre9");
    this->tree5 = new ImageSetting(":/images/arbre8");
    this->tree6 = new ImageSetting(":/images/arbre8");
    this->tree7 = new ImageSetting(":/images/arbre9");
    this->tree8 = new ImageSetting(":/images/arbre8");
    this->tree9 = new ImageSetting(":/images/arbre8");
    this->tree10 = new ImageSetting(":/images/arbre9");
    this->tree11 = new ImageSetting(":/images/arbre9");
    this->tree12 = new ImageSetting(":/images/arbre8");
    this->tree13 = new ImageSetting(":/images/arbre8");
    this->tree14 = new ImageSetting(":/images/arbre9");
    this->tree15 = new ImageSetting(":/images/arbre9");

    this->tree16 = new ImageSetting(":/images/arbre8");
    this->tree17 = new ImageSetting(":/images/arbre9");
    this->tree18 = new ImageSetting(":/images/arbre9");
    this->tree19 = new ImageSetting(":/images/arbre9");
    this->tree20 = new ImageSetting(":/images/arbre8");
    this->tree21 = new ImageSetting(":/images/arbre8");
    this->tree22 = new ImageSetting(":/images/arbre9");
    this->tree23 = new ImageSetting(":/images/arbre9");
    this->tree24 = new ImageSetting(":/images/arbre9");
    this->tree25 = new ImageSetting(":/images/arbre8");
    this->tree26 = new ImageSetting(":/images/arbre9");
    this->tree27 = new ImageSetting(":/images/arbre8");
    this->tree28 = new ImageSetting(":/images/arbre8");
    this->tree29 = new ImageSetting(":/images/arbre9");
    this->tree30 = new ImageSetting(":/images/arbre9");

    this->bushBerries1 = new ImageSetting(":/images/buissonbaies");
    this->bushBerries2 = new ImageSetting(":/images/buissonbaies");

    this->tree1->setPos(posX, posY);
    this->tree2->setPos(posX + 70, posY + 10);
    this->tree3->setPos(posX + 150, posY);
    this->tree4->setPos(posX - 60, posY + 20);
    this->tree5->setPos(posX - 10, posY + 30);
    this->tree6->setPos(posX + 200, posY + 20);
    this->tree7->setPos(posX + 130, posY + 30);
    this->tree8->setPos(posX + 60, posY + 30);
    this->tree9->setPos(posX - 100, posY + 50);
    this->tree10->setPos(posX - 50, posY + 65);
    this->tree11->setPos(posX + 250, posY + 50);
    this->tree12->setPos(posX + 175, posY + 65);
    this->tree13->setPos(posX + 230, posY + 90);
    this->tree14->setPos(posX - 140, posY + 75);
    this->tree15->setPos(posX - 75, posY + 85);

    this->tree16->setPos(posX - 80, posY + 300);
    this->tree17->setPos(posX + 220, posY + 300);
    this->tree18->setPos(posX - 20, posY + 320);
    this->tree19->setPos(posX + 40, posY + 330);
    this->tree20->setPos(posX + 165, posY + 325);
    this->tree21->setPos(posX + 95, posY + 335);
    this->tree22->setPos(posX + 260, posY + 320);
    this->tree23->setPos(posX - 140, posY + 315);
    this->tree24->setPos(posX - 90, posY + 340);
    this->tree25->setPos(posX + 210, posY + 350);
    this->tree26->setPos(posX + 140, posY + 370);
    this->tree27->setPos(posX - 30, posY + 360);
    this->tree28->setPos(posX + 50, posY + 370);
    this->tree29->setPos(posX + 30, posY + 400);
    this->tree30->setPos(posX + 120, posY + 400);

    this->bushBerries1->setPos(posX + 130, posY + 100);
    this->bushBerries2->setPos(posX + 160, posY + 425);

    this->posXAcorn = posX + 160;
    this->posYAcorn = posY + 330;
    this->posXBerries = posX + 115;
    this->posYBerries = posY + 130;
    this->posXWheat = posX;
    this->posYWheat = posY + 130;
}

Forest6::Forest6(QString type, int posX, int posY, View *view): Forest(type, posX, posY, view) {
    this->tree1 = new ImageSetting(":/images/arbre7");
    this->tree2 = new ImageSetting(":/images/arbre7");
    this->tree3 = new ImageSetting(":/images/arbre10");
    this->tree4 = new ImageSetting(":/images/arbre6");
    this->tree5 = new ImageSetting(":/images/arbre10");
    this->tree6 = new ImageSetting(":/images/arbre6");
    this->tree7 = new ImageSetting(":/images/arbre7");
    this->tree8 = new ImageSetting(":/images/arbre7");
    this->tree9 = new ImageSetting(":/images/arbre6");
    this->tree10 = new ImageSetting(":/images/arbre10");
    this->tree11 = new ImageSetting(":/images/arbre6");
    this->tree12 = new ImageSetting(":/images/arbre10");
    this->tree13 = new ImageSetting(":/images/arbre10");
    this->tree14 = new ImageSetting(":/images/arbre6");
    this->tree15 = new ImageSetting(":/images/arbre6");
    this->tree16 = new ImageSetting(":/images/arbre10");
    this->tree17 = new ImageSetting(":/images/arbre6");
    this->tree18 = new ImageSetting(":/images/arbre6");
    this->tree19 = new ImageSetting(":/images/arbre10");
    this->tree20 = new ImageSetting(":/images/arbre10");
    this->tree21 = new ImageSetting(":/images/arbre6");
    this->tree22 = new ImageSetting(":/images/arbre6");
    this->tree23 = new ImageSetting(":/images/arbre6");
    this->tree24 = new ImageSetting(":/images/arbre10");
    this->tree25 = new ImageSetting(":/images/arbre7");
    this->tree26 = new ImageSetting(":/images/arbre7");

    this->bushBerries1 = new ImageSetting(":/images/buissonbaies");
    this->bush1 = new ImageSetting(":/images/buisson2");

    this->tree1->setPos(posX, posY);
    this->tree2->setPos(posX - 30, posY + 20);
    this->tree3->setPos(posX + 50, posY + 30);
    this->tree4->setPos(posX - 70, posY + 35);
    this->tree5->setPos(posX - 15, posY + 50);
    this->tree6->setPos(posX + 100, posY + 40);
    this->tree7->setPos(posX - 130, posY + 60);
    this->tree8->setPos(posX + 130, posY + 55);
    this->tree9->setPos(posX + 170, posY + 90);
    this->tree10->setPos(posX - 140, posY + 110);
    this->tree11->setPos(posX - 120, posY + 140);
    this->tree12->setPos(posX + 210, posY + 130);
    this->tree13->setPos(posX + 150, posY + 140);
    this->tree14->setPos(posX + 190, posY + 160);
    this->tree15->setPos(posX + 100, posY + 200);
    this->tree16->setPos(posX - 80, posY + 160);
    this->tree17->setPos(posX - 50, posY + 200);
    this->tree18->setPos(posX + 30, posY + 200);
    this->tree19->setPos(posX - 10, posY + 220);
    this->tree20->setPos(posX + 60, posY + 230);
    this->tree21->setPos(posX - 50, posY + 230);
    this->tree22->setPos(posX + 10, posY + 260);
    this->tree23->setPos(posX + 90, posY + 250);
    this->tree24->setPos(posX + 140, posY + 210);
    this->tree25->setPos(posX + 170, posY + 220);
    this->tree26->setPos(posX - 140, posY + 200);

    this->bushBerries1->setPos(posX - 80, posY + 100);
    this->bush1->setPos(posX + 60, posY + 110);

    this->posXAcorn = posX - 60;
    this->posYAcorn = posY + 300;
    this->posXBerries = posX + 160;
    this->posYBerries = posY + 310;
    this->posXWheat = posX + 80;
    this->posYWheat = posY + 310;
}

Forest7::Forest7(QString type, int posX, int posY, View *view): Forest(type, posX, posY, view) {
    this->tree1 = new ImageSetting(":/images/arbre1");
    this->tree2 = new ImageSetting(":/images/arbre1");
    this->tree3 = new ImageSetting(":/images/arbre1");
    this->tree4 = new ImageSetting(":/images/arbre6");
    this->tree5 = new ImageSetting(":/images/arbre2");
    this->tree6 = new ImageSetting(":/images/arbre2");
    this->tree7 = new ImageSetting(":/images/arbre2");
    this->tree8 = new ImageSetting(":/images/arbre4");
    this->tree9 = new ImageSetting(":/images/arbre6");
    this->tree10 = new ImageSetting(":/images/arbre1");
    this->tree11 = new ImageSetting(":/images/arbreM3");
    this->tree12 = new ImageSetting(":/images/arbre4");
    this->tree13 = new ImageSetting(":/images/arbre4");
    this->tree14 = new ImageSetting(":/images/arbre6");
    this->tree15 = new ImageSetting(":/images/arbre2");
    this->tree16 = new ImageSetting(":/images/arbre2");
    this->tree17 = new ImageSetting(":/images/arbre6");
    this->tree18 = new ImageSetting(":/images/arbre1");
    this->tree19 = new ImageSetting(":/images/arbre4");
    this->tree20 = new ImageSetting(":/images/arbreM3");
    this->tree21 = new ImageSetting(":/images/arbre10");
    this->tree22 = new ImageSetting(":/images/arbre10");
    this->tree23 = new ImageSetting(":/images/arbre1");
    this->tree24 = new ImageSetting(":/images/arbre1");
    this->tree25 = new ImageSetting(":/images/arbre6");
    this->tree26 = new ImageSetting(":/images/arbre10");
    this->tree27 = new ImageSetting(":/images/arbre10");
    this->tree28 = new ImageSetting(":/images/arbre4");
    this->tree29 = new ImageSetting(":/images/arbre4");
    this->tree30 = new ImageSetting(":/images/arbre6");

    this->bushBerries1 = new ImageSetting(":/images/buissonbaies");
    this->bushBerries2 = new ImageSetting(":/images/buissonbaies");
    this->bushBerries3 = new ImageSetting(":/images/buissonbaies");
    this->bush1 = new ImageSetting(":/images/buisson2");
    this->bush2 = new ImageSetting(":/images/buisson2");
    this->bush3 = new ImageSetting(":/images/buisson2");
    this->bush4 = new ImageSetting(":/images/buisson1");
    this->bush5 = new ImageSetting(":/images/buisson2");
    this->bush6 = new ImageSetting(":/images/buisson1");
    this->bush7 = new ImageSetting(":/images/buisson1");
    this->souche1 = new ImageSetting(":/images/souche2");
    this->souche2 = new ImageSetting(":/images/souche1");
    this->souche3 = new ImageSetting(":/images/souche2");

    this->tree1->setPos(posX, posY);
    this->tree2->setPos(posX + 80, posY);
    this->tree3->setPos(posX - 20, posY + 30);
    this->tree4->setPos(posX + 100, posY + 40);
    this->tree5->setPos(posX + 65, posY + 70);
    this->tree6->setPos(posX + 50, posY + 90);
    this->tree7->setPos(posX + 90, posY + 100);
    this->tree8->setPos(posX + 50, posY + 150);
    this->tree9->setPos(posX - 10, posY + 85);
    this->tree10->setPos(posX + 140, posY + 110);
    this->tree11->setPos(posX + 190, posY + 135);
    this->tree12->setPos(posX + 200, posY + 240);
    this->tree13->setPos(posX + 120, posY + 250);
    this->tree14->setPos(posX + 135, posY + 185);
    this->tree15->setPos(posX + 160, posY + 250);
    this->tree16->setPos(posX + 180, posY + 255);
    this->tree17->setPos(posX + 290, posY + 200);
    this->tree18->setPos(posX + 240, posY + 185);
    this->tree19->setPos(posX + 240, posY + 300);
    this->tree20->setPos(posX + 370, posY + 230);
    this->tree21->setPos(posX + 330, posY + 250);
    this->tree22->setPos(posX + 270, posY + 270);
    this->tree23->setPos(posX + 435, posY + 240);
    this->tree24->setPos(posX + 360, posY - 30);
    this->tree25->setPos(posX + 300, posY - 10);
    this->tree26->setPos(posX + 400, posY + 25);
    this->tree27->setPos(posX + 350, posY + 40);
    this->tree28->setPos(posX + 460, posY + 80);
    this->tree29->setPos(posX + 490, posY + 110);
    this->tree30->setPos(posX + 400, posY + 70);

    this->bushBerries1->setPos(posX + 100, posY + 140);
    this->bushBerries2->setPos(posX + 50, posY + 210);
    this->bushBerries3->setPos(posX + 395, posY + 325);
    this->bush1->setPos(posX + 90, posY + 185);
    this->bush2->setPos(posX + 20, posY + 185);
    this->bush3->setPos(posX + 240, posY + 270);
    this->bush4->setPos(posX + 210, posY + 285);
    this->bush5->setPos(posX + 430, posY);
    this->bush6->setPos(posX + 460, posY + 25);
    this->bush7->setPos(posX + 480, posY + 50);
    this->souche1->setPos(posX + 330, posY + 340);
    this->souche2->setPos(posX + 380, posY + 335);
    this->souche3->setPos(posX + 500, posY + 85);

    this->posXAcorn = posX + 300;
    this->posYAcorn = posY + 60;
    this->posXBerries = posX + 250;
    this->posYBerries = posY + 150;
    this->posXWheat = posX + 460;
    this->posYWheat = posY + 135;
}
