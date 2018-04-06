#ifndef MODEL_H
#define MODEL_H

#include <QTableWidget>
#include <QMainWindow>

#include "decor.h"
#include "personnages.h"
#include <QList>

class Model
{
    private:
        QList<PersoNormaux *> *listS = new QList<PersoNormaux *>;

    public:
        Model();
        Village *setVillage(View *view);
        void actionPerso(int x, int y, int nbS);
        void addPerso(PersoNormaux *S) {listS->append(S);}
};

#endif // MODEL_H
