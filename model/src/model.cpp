#include "./view/includes/view.h"
#include "./controller/includes/controller.h"
#include "../includes/model.h"
#include "../includes/decor.h"
#include "../includes/personnages.h"

Village *Model::setVillage(int x, int y, View *view) {
    this->villagePosX = x;
    this->villagePosY = y;
    Village *villageS = new Village("V", this->villagePosX, this->villagePosY, view);
    addSetting(villageS);
    return villageS;
}

Forest1 *Model::setForest1(int x, int y, View *view) {
    Forest1 *forestN = new Forest1("F1", x, y, view);
    addSetting(forestN);
    return forestN;
}

Forest2 *Model::setForest2(int x, int y, View *view) {
    Forest2 *forestN = new Forest2("F2", x, y, view);
    addSetting(forestN);
    return forestN;
}

Forest3 *Model::setForest3(int x, int y, View *view) {
    Forest3 *forestN = new Forest3("F3", x, y, view);
    addSetting(forestN);
    return forestN;
}

Forest4 *Model::setForest4(int x, int y, View *view) {
    Forest4 *forestN = new Forest4("F4", x, y, view);
    addSetting(forestN);
    return forestN;
}

Forest5 *Model::setForest5(int x, int y, View *view) {
    Forest5 *forestN = new Forest5("F5", x, y, view);
    addSetting(forestN);
    return forestN;
}

Forest6 *Model::setForest6(int x, int y, View *view) {
    Forest6 *forestN = new Forest6("F6", x, y, view);
    addSetting(forestN);
    return forestN;
}

Forest7 *Model::setForest7(int x, int y, View *view) {
    Forest7 *forestN = new Forest7("F7", x, y, view);
    addSetting(forestN);
    return forestN;
}


void Model::initFarmer(int level) {
    this->farmer = new Farmer();
    if (level > 0) {
        this->farmerUp(level-1);
    }
}

void Model::initBaker(int level) {
    this->baker = new Baker();
    if (level > 0) {
        this->bakerUp(level-1);
    }
}

void Model::initHefty(int level) {
    this->hefty = new Hefty();
    if (level > 0) {
        this->heftyUp(level-1);
    }
}

int Model::getNumberFreePerso() {
    int cptS=0;
    for (int i=0; i<listNicePerso->size(); i++) {
        if (listNicePerso->at(i)->isFree())
            cptS++;
    }
    return cptS;
}

Image * Model::getImageFront() {
    Image *imageFront = new Image(":/images/parchemin");
    imageFront->setPos(200, 100);
    return imageFront;
}

QGraphicsTextItem * Model::getMessageFront() {
    QGraphicsTextItem *texteItem = new QGraphicsTextItem(this->frontMessage);
    QFont f("Monotype Corsiva", 10);
    texteItem->setFont(f);
    texteItem->setPos(220, 140);
    return texteItem;
}
