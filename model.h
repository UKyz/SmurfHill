#ifndef MODEL_H
#define MODEL_H

#include <QTableWidget>
#include <QMainWindow>

#include "decor.h"

class Model
{
    private:

    public:
        Model();
        Village *setVillage(View *view);
};

#endif // MODEL_H
