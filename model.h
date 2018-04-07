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
        QList<PersoGentil *> *listSGentil = new QList<PersoGentil *>;
        QList<PersoMechant *> *listSMechant = new QList<PersoMechant *>;

    public:
        Model();
        Village *setVillage(View *view);
        void actionPerso(int x, int y, int nbS);
        void addPersoGentil(PersoGentil *S) {listSGentil->append(S);}
        void addPersoMechant(PersoMechant *S) {listSMechant->append(S);}
        int getNbSFree();
};

#endif // MODEL_H
