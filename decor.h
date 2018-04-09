#ifndef DECOR_H
#define DECOR_H

#include "autre.h"
#include "view.h"
#include <QtDebug>

class View;

class Decor : public QObject
{

    Q_OBJECT

    public:

        Decor(int posX, int posY, View *view);

        int getPosX() {return this->posX;}
        int getPosY() {return this->posY;}

    private:

    protected:
        int posX;
        int posY;
        View *view;


};


class Village : public Decor
{

    Q_OBJECT

    public:

        Village(int posX, int posY, View *view);
        Image *getGrandS() {return this->grandS;}
        Image *getMaison1() {return this->maison1;}
        Image *getMaison2() {return this->maison2;}
        Image *getMaison3() {return this->maison3;}
        Image *getMaison4() {return this->maison4;}
        Image *getMaison5() {return this->maison5;}
        Image *getMaison6() {return this->maison6;}
        Image *getMaison7() {return this->maison7;}
        Image *getMaison8() {return this->maison8;}
        Image *getMaison9() {return this->maison9;}
        Image *getMaisonSette() {return this->maisonSette;}
        Image *getMaisonSCostaud() {return this->maisonSCostaud;}
        Image *getMaisonSPaysan() {return this->maisonSPaysan;}
        Image *getMaisonSMusicien() {return this->maisonSMusicien;}
        Image *getMoulinS() {return this->moulinS;}
        Image *getPuits() {return this->puits;}
        Image *getArbre1() {return this->arbre1;}
        Image *getArbre2() {return this->arbre2;}

    private:

        Image *maison1, *maison2, *maison3, *maison4, *maison5, *maison6, *maison7, *maison8, *maison9;
        Image *grandS, *maisonSette, *maisonSCostaud, *maisonSMusicien, *maisonSPaysan;
        Image *moulinS, *puits;
        Image *arbre1, *arbre2;

    public slots:
        void pixmapClicked() {qDebug() << "item clicked!";}

};

class Foret : public Decor
{

    Q_OBJECT

    public:

        Foret(int posX, int posY, View *view);
        Image *getNoisette() {return this->noisette;}
        Image *getBaie() {return this->baie;}
        Image *getBle() {return this->ble;}

    private:

    protected:

        Image *noisette, *baie, *ble;
};

class Foret1 : public Foret
{

    Q_OBJECT

    public:

        Foret1(int posX, int posY, View *view);
        Image *getArbre1() {return this->arbre1;}
        Image *getArbre2() {return this->arbre2;}
        Image *getArbre3() {return this->arbre3;}
        Image *getArbre4() {return this->arbre4;}
        Image *getArbre5() {return this->arbre5;}
        Image *getArbre6() {return this->arbre6;}
        Image *getArbre7() {return this->arbre7;}
        Image *getArbre8() {return this->arbre8;}
        Image *getArbre9() {return this->arbre9;}
        Image *getArbre10() {return this->arbre10;}
        Image *getArbre11() {return this->arbre11;}
        Image *getArbre12() {return this->arbre12;}
        Image *getArbre13() {return this->arbre13;}
        Image *getArbre14() {return this->arbre14;}
        Image *getArbre15() {return this->arbre15;}
        Image *getArbre16() {return this->arbre16;}
        Image *getArbre17() {return this->arbre17;}

        Image *getBuisson1() {return this->buisson1;}
        Image *getBuisson2() {return this->buisson2;}
        Image *getBuissonBaies1() {return this->buissonbaies1;}
        Image *getBuissonBaies2() {return this->buissonbaies2;}

    private:
        Image *arbre1, *arbre2, *arbre3, *arbre4, *arbre5, *arbre6, *arbre7, *arbre8;
        Image *arbre9, *arbre10, *arbre11, *arbre12, *arbre13, *arbre14, *arbre15, *arbre16, *arbre17;
        Image *buisson1, *buisson2, *buissonbaies1, *buissonbaies2;
};
/*
class Foret2 : public Foret
{

    Q_OBJECT

    public:

        Foret2(int posX, int posY, View *view);
        Image *getArbre1() {return this->arbre1;}
        Image *getArbre2() {return this->arbre2;}
        Image *getArbre3() {return this->arbre3;}
        Image *getArbre4() {return this->arbre4;}
        Image *getArbre5() {return this->arbre5;}
        Image *getArbre6() {return this->arbre6;}
        Image *getArbre7() {return this->arbre7;}
        Image *getArbre8() {return this->arbre8;}
        Image *getArbre9() {return this->arbre9;}
        Image *getArbre10() {return this->arbre10;}

    private:
        Image *arbre1, *arbre2, *arbre3, *arbre4, *arbre5, *arbre6, *arbre7, *arbre8, *arbre9, *arbre10;
};
*/

#endif // DECOR_H
