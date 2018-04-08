#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "autre.h"
#include "view.h"
#include "model.h"

class Controller;
//class Model;
class View;

class Controller
{
    private:
        Model *model;
        View *view;
    public:
        Controller(Model *model, View *view);
        void startGame();
        void clickedOnMap(int x, int y);
        void actionPerso(int x, int y, int nbS);
        int getNbSFree();
        int getVillagePosX() {return this->model->getVillagePosX();}
        int getVillagePosY() {return this->model->getVillagePosY();}
        bool isMessageDisplayed() {return this->model->getMessage();}
        void setMessageDisplayed(bool message) {this->model->setMessage(message);}
        QGraphicsTextItem *getMessageGrandS() {return this->model->getMessageGrandS();}
        QGraphicsTextItem *getMessageSette() {return this->model->getMessageSette();}
        Image *getImageBulle() {return this->model->getImageBulle();}
        Image *getImageGrandS() {return this->model->getImageGrandS();}
        Image *getImageSette() {return this->model->getImageSette();}
};


#endif // CONTROLLER_H
