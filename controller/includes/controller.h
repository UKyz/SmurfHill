#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "./model/includes/autre.h"
#include "./view/includes/view.h"
#include "./model/includes/model.h"

#include <QObject>
#include <QWidget>
#include <QGraphicsTextItem>
#include <QTimer>
#include <QMessageBox>
#include <QGraphicsScene>
#include <QPixmap>
#include <QTimer>
#include <QFileDialog>
#include <QGraphicsView>
#include <QDateTime>
#include <QCoreApplication>
#include <QPointF>
#include <QtDebug>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <QDateTime>
#include <random>
#include <iostream>

class View;

class Controller: public QObject {
    Q_OBJECT
    public slots:
        void gameLoop();
        void checkMadPersoFixed();
        void checkMadPersoMovable();
        void checkResources();
    private:
        Model *model;
        View *view;
        QTimer *timer;
        QTimer *timerWheat;
        QTimer *chrono;
        QTimer *timerSpawnMadPersoFixed;
        QTimer *timerSpawnMadPersoMovable;
        QTimer *timerResources;
        int nbBreadSelected = 0, nbBerrySelected = 0, nbAcronSelected = 0;
    public:
        Controller(Model *model, View *view);
        // Start and save
        void startNewGame();
        void startGame(QString setting, QString nicePerso, QString madPersoFixed, QString madPersoMovable, QString resourceItem);
        void save();
        void loadSave();
        void saveQuit();
        // Game's time
        int gameDuration();
        QDateTime timeStart() {return QDateTime::currentDateTime();}
        QDateTime getTimeStart() {return this->model->getTimeStart();}
        // Other
        void displayResourceItem(QString resourceItem);
        void clickedOnMap(int x, int y);
        int distanceBetweenPoints(QPointF *p1, QPointF *p2);
        QPointF *getPointDecale(QPointF *beginningPoint, QPointF *nextPoint);
        int getVillagePosX() {return this->model->getVillagePosX();}
        int getVillagePosY() {return this->model->getVillagePosY();}
        void fillListResource();
        void fillListSpawnNicePerso();
        void fillListSpotMadPersoFixed();
        void fillListSpotMadPersoMovable();
        // Perso
        void actionPerso(int x, int y, int nbS);
        int getNumberFreePerso();
        QList<NicePerso *> *getlistNicePerso();
        QList<MadPerso *> *getlistMadPersoFixed() {return this->model->getlistMadPersoFixed();}
        QList<MadPerso *> *getlistMadPersoMovable() {return this->model->getlistMadPersoMovable();}
        QList<Setting *> *getlistSetting() {return this->model->getlistSetting();}
        QPointF *getFreeSpawnNicePerso();
        bool containsMadPersoFixed(MadPerso *perso);
        void changeMoveMadPerso(ActionMove *action, MadPerso *S);
        // Smurf's Message
        bool isMessageDisplayed() {return this->model->getMessage();}
        void setMessageDisplayed(bool message) {this->model->setMessage(message);}
        void fillListAdvicePapaSmurf();
        void fillListAdviceSmurfette();
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
        // Hefty
        void heftyUp(int cost);
        int getLevelHefty() {return this->model->getLevelHefty();}
        void creationNewSmurf(int cost);
        int getSpeedS() {return this->model->getSpeedHefty();}
        int getDamageS() {return this->model->getDamageHefty();}
        int getHpS() {return this->model->getHpHefty();}
        // Resources
        int getNumberBerry() {return this->model->getBagBerries()->getNumber();}
        int getNumberAcorn() {return this->model->getBagAcorns()->getNumber();}
        int getNumberSarsaparilla() {return this->model->getBagSarsaparillas()->getNumber();}
        int getNumberSmurfs() {return this->model->getlistNicePerso()->size();}
        int getScore() {return this->model->getScore();}
        //Doctor
        int getTreatment(int i);
        void treat(int i, int bread, int berries, int acorn);
        int getHealthBread() {return this->model->getBagBreads()->getHealth();}
        int getHealthBerries() {return this->model->getBagBerries()->getHealth();}
        int getHealthAcorn() {return this->model->getBagAcorns()->getHealth();}
        int getMaxBreadForTreatment(int nb) {return nb/getHealthBread();}
        int getMaxBerriesForTreatment(int nb) {return nb/getHealthBerries();}
        int getMaxAcornForTreatment(int nb) {return nb/getHealthAcorn();}
};


#endif // CONTROLLER_H
