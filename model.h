#ifndef MODEL_H
#define MODEL_H

#include <QTableWidget>
#include <QMainWindow>

#include "decor.h"
#include "personnages.h"
#include "ressources.h"
#include "autre.h"
#include <QList>
#include <QGraphicsTextItem>
#include <QDateTime>
#include <QObject>

class Setting;
class Village;
class View;
class Forest1;
class Forest2;
class Forest3;
class Forest4;
class Forest5;
class Forest6;
class Forest7;

class Model: public QObject
{
    private:
        Resource *bagSarsaparillas = new Resource("Sarsaparillas");
        Resource *bagWheats = new Resource("Wheats");
        WheatField *wheatField = new WheatField();
        Farmer *farmer;
        Baker *baker;
        Hefty *hefty;
        Food *bagBreads = new Food("Breads", 5);
        Food *bagBerries = new Food("Berries", 2);
        Food *bagAcorns = new Food("Acorns", 1);
        Score *score;
        int nbMaxMadPersoMovable = 5;
        // Listes
        QList<QString> *listAdvicePapaSmurf = new QList<QString>;
        QList<QString> *listAdviceSmurfette = new QList<QString>;
        QList<NicePerso *> *listNicePerso = new QList<NicePerso *>;
        QList<MadPerso *> *listMadPersoMovable = new QList<MadPerso *>;
        QList<MadPerso *> *listMadPersoFixed = new QList<MadPerso *>;
        QList<Setting *> *listSetting = new QList<Setting *>;
        QList<ResourceItem *> *listResourceItem = new QList<ResourceItem *>;
        QList<QPointF *> *listSpotResourceItem = new QList<QPointF *>;
        QList<QPointF *> *listSpawnNicePerso = new QList<QPointF *>;
        QList<QPointF *> *listSpotMadPersoFixed = new QList<QPointF *>;
        QList<QPointF *> *listSpotMadPersoMovable = new QList<QPointF *>;
        QString frontMessage;
        // Others
        int villagePosX, villagePosY;
        bool message = false;
        QDateTime timeStart;
        int timePreviouslyPlayed = 0;
    public:
        Model() {}
        // Smurf's message
        QList<QString> *getlistAdvicePapaSmurf() {return this->listAdvicePapaSmurf;}
        void addMessageListAdvicePapaSmurf(QString advice) {this->listAdvicePapaSmurf->append(advice);}
        QList<QString> *getlistAdviceSmurfette() {return this->listAdviceSmurfette;}
        void addMessageListAdviceSmurfette(QString advice) {this->listAdviceSmurfette->append(advice);}
        // List's getter
        QList<ResourceItem *> *getlistResourceItem() {return this->listResourceItem;}
        QList<Setting *> *getlistSetting() {return this->listSetting;}
        QList<QPointF *> *getlistSpotResourceItem() {return this->listSpotResourceItem;}
        QList<QPointF *> *getlistSpawnNicePerso() {return this->listSpawnNicePerso;}
        QList<QPointF *> *getlistSpotMadPersoFixed () {return this->listSpotMadPersoFixed;}
        QList<QPointF *> *getlistSpotMadPersoMovable() {return this->listSpotMadPersoMovable;}
        // Resources
        Resource *getBagSarsaparillas() {return bagSarsaparillas;}
        void addSarsaparilla(int nbSarsaparilla) {this->getBagSarsaparillas()->addResource(nbSarsaparilla);}
        Resource *getBagWheats() {return bagWheats;}
        Food *getBagBerries() {return bagBerries;}
        Food *getBagAcorns() {return bagAcorns;}
        void addResourceItem(ResourceItem *item) {this->listResourceItem->append(item);}
        // Farmer
        void initFarmer(int level = 0);
        WheatField *getWheatField() {return this->farmer->getChamps();}
        int getNumberWheatToHarvest() {return this->farmer->getChamps()->getNumberWheatToHarvest();}
        void farmerUp(int lvl) {this->farmer->up(lvl);}
        int getLevelFarmer() {return this->farmer->getLevel();}
        int getCostWheat() {return this->farmer->getResaleCost();}
        void useWheat(int nbWheat) {this->getBagWheats()->removeResource(nbWheat);}
        // Baker
        void initBaker(int level = 0);
        Food *getBagBreads() {return bagBreads;}
        void makeBread(int nbBread) {this->getBagBreads()->addResource(nbBread);}
        int getCostProductionBread() {return this->baker->getCostProduction();}
        int getResourceProductionBaker() {return this->baker->getNumberResourceForProduction();}
        int getLevelBaker() {return this->baker->getLevel();}
        void bakerUp(int lvl) {this->baker->up(lvl);}
        // Hefty
        void initHefty(int level = 0);
        void heftyUp(int lvl) {this->hefty->up(lvl);}
        int getLevelHefty() {return this->hefty->getLevel();}
        int getDamageHefty() {return this->hefty->getDamageS();}
        int getHpHefty() {return this->hefty->getHpS();}
        int getSpeedHefty() {return this->hefty->getSpeedS();}
        // Temps de jeu
        void setTimeStart(QDateTime timeStart) {this->timeStart = timeStart;}
        QDateTime getTimeStart() {return this->timeStart;}
        void setTimePreviouslyPlayed(int time) {this->timePreviouslyPlayed = time;}
        int getTimePreviouslyPlayed() {return this->timePreviouslyPlayed;}
        // Setting
        int getVillagePosX() {return villagePosX;}
        int getVillagePosY() {return villagePosY;}
        Village *setVillage(int x, int y, View *view);
        Forest1 *setForest1(int x, int y, View *view);
        Forest2 *setForest2(int x, int y, View *view);
        Forest3 *setForest3(int x, int y, View *view);
        Forest4 *setForest4(int x, int y, View *view);
        Forest5 *setForest5(int x, int y, View *view);
        Forest6 *setForest6(int x, int y, View *view);
        Forest7 *setForest7(int x, int y, View *view);
        void addSetting(Setting *D) {listSetting->append(D);}
        QList<Setting *> getListSetting() {return *listSetting;}
        // Perso
        void addNewSmurf(NicePerso *perso) {this->listNicePerso->append(perso);}
        void addNicePerso(NicePerso *S) {listNicePerso->append(S);}
        void addMadPersoMovable(MadPerso *S) {listMadPersoMovable->append(S);}
        void addMadPersoFixed(MadPerso *S) {listMadPersoFixed->append(S);}
        int getNumberFreePerso();
        int getNbMaxMadPersoMovable() {return this->nbMaxMadPersoMovable;}
        void incrementNbMaxMadPersoMovable() {this->nbMaxMadPersoMovable++;}
        void setNbMaxMadPersoMovable(int nb) {this->nbMaxMadPersoMovable += nb;}
        QList<NicePerso *> *getlistNicePerso() {return this->listNicePerso;}
        QList<MadPerso *> *getlistMadPersoMovable() {return this->listMadPersoMovable;}
        QList<MadPerso *> *getlistMadPersoFixed() {return this->listMadPersoFixed;}
        // Spot
        void addListSpawnNicePerso(QPointF *point) {this->listSpawnNicePerso->append(point);}
        void addListSpotMadPersoFixed(QPointF *point) {this->listSpotMadPersoFixed->append(point);}
        void addListSpotMadPersoMovable(QPointF *point) {this->listSpotMadPersoMovable->append(point);}
        void addListSpotResource(QPointF *point) {this->listSpotResourceItem->append(point);}
        // Game Messages
        bool getMessage() {return this->message;}
        void setMessage(bool message) {this->message = message;}
        void setFrontMessage(QString fm) {this->frontMessage = fm;}
        QGraphicsTextItem *getMessageFront();
        QString getMessagePapaSmurf(int random) {return this->listAdvicePapaSmurf->at(random);}
        QString getMessageSmurfette(int random) {return this->listAdviceSmurfette->at(random);}
        Image *getImageFront();
        Image *getImageBubblePapaSmurf() {return new Image(":/images/bulleText");}
        Image *getImageBubbleSmurfette() {return new Image(":/images/bulleText");}
        Image *getImageBubbleBrainy() {return new Image(":/images/bulleText2");}
        Image *getImagePapaSmurf() {return new Image(":/images/PapaS01");}
        Image *getImageSmurfette() {return new Image(":/images/Sette01");}
        Image *getImageBrainy() {return new Image(":/images/LunettesS01");}
        // Score
        void initScore(int nb) {this->score = new Score(nb);}
        int getScore() {return this->score->getPoints();}
        void addPoints(int nbPoints) {this->score->addPoints(nbPoints);}
};

#endif // MODEL_H
