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
};


#endif // CONTROLLER_H
