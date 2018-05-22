#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "autre.h"
#include "view.h"
#include "model.h"

#include <QObject>
#include <QWidget>
#include <QGraphicsTextItem>
#include <QTimer>
#include <QDateTime>

class View;

class Controller: public QObject
{
    Q_OBJECT

    public slots:
        void gameLoop();
        void checkMadPerso();

    private:

        Model *model;
        View *view;
        QTimer *timer;
        QTimer *timerWheat;
        QTimer *chrono;
        QTimer *timerSpawnMadPerso;

        int treatment;
        int nbBreadSelected = 0, nbBerrySelected = 0, nbAcronSelected = 0;

    public:

        Controller(Model *model, View *view);
        void startNewGame();
        void startGame(QString setting, QString nicePerso, QString madPersoFixed, QString madPersoMobile, QString resourceItem);
        void save();
        void loadSave();
        void saveQuit();

        int gameDuration();
        QDateTime timeStart();
        QDateTime getTimeStart() {return this->model->getTimeStart();}

        void displayResourceItem(QString resourceItem);
        void clickedOnMap(int x, int y);
        void actionPerso(int x, int y, int nbS);
        int distanceBetweenPoints(QPointF *p1, QPointF *p2);
        QPointF *getPointDecale(QPointF *beginningPoint, QPointF *nextPoint);

        int getNumberFreePerso();
        int getVillagePosX() {return this->model->getVillagePosX();}
        int getVillagePosY() {return this->model->getVillagePosY();}
        QList<NicePerso *> *getlistNicePerso();
        QList<MadPerso *> *getlistMadPersoFixed() {return this->model->getlistMadPersoFixed();}
        QList<MadPerso *> *getlistMadPersoMobile() {return this->model->getlistMadPersoMobile();}
        QList<Setting *> *getlistSetting() {return this->model->getlistSetting();}
        QPointF *getFreeSpawnNicePerso();
        bool containsMadPersoFixed(MadPerso *perso);

        bool isMessageDisplayed() {return this->model->getMessage();}
        void setMessageDisplayed(bool message) {this->model->setMessage(message);}

        QGraphicsTextItem *getMessageFront() {return this->model->getMessageFront();}
        QGraphicsTextItem *getMessagePapaSmurf();
        QGraphicsTextItem *getMessageSmurfette();
        QGraphicsTextItem *getMessageBrainy();
        Image *getImageFront() {return this->model->getImageFront();}
        Image *getImageBubblePapaSmurf();
        Image *getImageBubbleSmurfette();
        Image *getImageBubbleBrainy();
        Image *getImagePapaSmurf();
        Image *getImageSmurfette();
        Image *getImageBrainy();


        // Farmer
        void farmerUp(int cost);
        int getLevelFarmer() {return this->model->getLevelFarmer();}
        void harvestWheat();
        void sellWheat(int nbWheat);
        int getNumberWheatToHarvest() {return this->model->getNumberWheatToHarvest();}
        int getNumberWheat() {return this->model->getBagWheats()->getNumber();}
        int getCostWheat() {return this->model->getCostWheat();}
        int getSizeFields() {return this->model->getWheatField()->getSize();}
        int getCapacityFields() {return this->model->getWheatField()->getCapacity();}

        // Baker
        void bakerUp(int cost);
        int getNumberBread() {return this->model->getBagBreads()->getNumber();}
        int getCostProductionBread() {return this->model->getCostProductionBread();}
        int getResourceProductionBaker() {return this->model->getResourceProductionBaker();}
        int getLevelBaker() {return this->model->getLevelBaker();}
        void makeBread(int nbBread);

        //Hefty
        void heftyUp(int cost);
        int getLevelHefty() {return this->model->getLevelHefty();}
        void creationNewSmurf(int cost);
        int getSpeedS() {return this->model->getSpeedHefty();}
        int getDamageS() {return this->model->getDamageHefty();}
        int getHpS() {return this->model->getHpHefty();}

        int getNumberBerry() {return this->model->getBagBerries()->getNumber();}
        int getNumberAcorn() {return this->model->getBagAcorns()->getNumber();}
        int getNumberSarsaparilla() {return this->model->getBagSarsaparillas()->getNumber();}
        int getNumberSmurfs() {return this->model->getlistNicePerso()->size();}
        int getScore() {return this->model->getScore();}

        //Doctor
        int setTreatment(int i);
        int getTreatment() {return this->treatment;}
        void treat(int i, int bread, int berries, int acorn);

        int getHealthBread() {return this->model->getBagBreads()->getHealth();}
        int getHealthBerries() {return this->model->getBagBerries()->getHealth();}
        int getHealthAcorn() {return this->model->getBagAcorns()->getHealth();}

        int getMaxBreadForTreatment();
        int getMaxBerriesForTreatment();
        int getMaxAcornForTreatment();

        int setNumberBreadSelected(int nbBread) {return this->nbBreadSelected = nbBread;}
        int setNumberBerrySelected(int nbBerry) {return this->nbBerrySelected = nbBerry;}
        int setNumberAcornSelected(int nbAcorn) {return this->nbAcronSelected = nbAcorn;}
        int getNumberBreadSelected() {return nbBreadSelected;}
        int getNumberBerrySelected() {return nbBerrySelected;}
        int getNumberAcornSelected() {return nbAcronSelected;}
};


#endif // CONTROLLER_H
