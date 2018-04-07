#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "autre.h"
#include "view.h"

class Controller;
class Model;
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
};


#endif // CONTROLLER_H
