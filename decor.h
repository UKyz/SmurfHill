#ifndef DECOR_H
#define DECOR_H

#include "autre.h"
#include "view.h"
#include <QtDebug>

class View;
class ImageDecor;

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
        ImageDecor *getGrandS() {return this->grandS;}
        ImageDecor *getMaison1() {return this->maison1;}
        ImageDecor *getMaison2() {return this->maison2;}
        ImageDecor *getMaison3() {return this->maison3;}
        ImageDecor *getMaison4() {return this->maison4;}
        ImageDecor *getMaison5() {return this->maison5;}
        ImageDecor *getMaison6() {return this->maison6;}
        ImageDecor *getMaison7() {return this->maison7;}
        ImageDecor *getMaison8() {return this->maison8;}
        ImageDecor *getMaison9() {return this->maison9;}
        ImageDecor *getMaisonSette() {return this->maisonSette;}
        ImageDecor *getMaisonSCostaud() {return this->maisonSCostaud;}
        ImageDecor *getMaisonSPaysan() {return this->maisonSPaysan;}
        ImageDecor *getMaisonSMusicien() {return this->maisonSMusicien;}
        ImageDecor *getMoulinS() {return this->moulinS;}
        ImageDecor *getPuits() {return this->puits;}
        ImageDecor *getArbre1() {return this->arbre1;}
        ImageDecor *getArbre2() {return this->arbre2;}

    private:

        ImageDecor *maison1, *maison2, *maison3, *maison4, *maison5, *maison6, *maison7, *maison8, *maison9;
        ImageDecor *grandS, *maisonSette, *maisonSCostaud, *maisonSMusicien, *maisonSPaysan;
        ImageDecor *moulinS, *puits;
        ImageDecor *arbre1, *arbre2;

    public slots:
        void pixmapClicked() {qDebug() << "item clicked!";}

};

class Foret : public Decor
{

    Q_OBJECT

    public:

        Foret(int posX, int posY, View *view);
        ImageDecor *getNoisette() {return this->noisette;}
        ImageDecor *getBaie() {return this->baie;}
        ImageDecor *getBle() {return this->ble;}

    private:

    protected slots:
        void onResourceWheatClicked();
        void onResourceAcornClicked();
        void onResourceBayClicked();

    protected:

        ImageDecor *noisette, *baie, *ble;
        int nbNoisette, nbBaie, nbBle;
};

class Foret1 : public Foret
{

    Q_OBJECT

    public:

        Foret1(int posX, int posY, View *view);
        ImageDecor *getArbre1() {return this->arbre1;}
        ImageDecor *getArbre2() {return this->arbre2;}
        ImageDecor *getArbre3() {return this->arbre3;}
        ImageDecor *getArbre4() {return this->arbre4;}
        ImageDecor *getArbre5() {return this->arbre5;}
        ImageDecor *getArbre6() {return this->arbre6;}
        ImageDecor *getArbre7() {return this->arbre7;}
        ImageDecor *getArbre8() {return this->arbre8;}
        ImageDecor *getArbre9() {return this->arbre9;}
        ImageDecor *getArbre10() {return this->arbre10;}
        ImageDecor *getArbre11() {return this->arbre11;}
        ImageDecor *getArbre12() {return this->arbre12;}
        ImageDecor *getArbre13() {return this->arbre13;}
        ImageDecor *getArbre14() {return this->arbre14;}
        ImageDecor *getArbre15() {return this->arbre15;}
        ImageDecor *getArbre16() {return this->arbre16;}
        ImageDecor *getArbre17() {return this->arbre17;}

        ImageDecor *getBuisson1() {return this->buisson1;}
        ImageDecor *getBuisson2() {return this->buisson2;}
        ImageDecor *getBuissonBaies1() {return this->buissonbaies1;}
        ImageDecor *getBuissonBaies2() {return this->buissonbaies2;}

    private:
        ImageDecor *arbre1, *arbre2, *arbre3, *arbre4, *arbre5, *arbre6, *arbre7, *arbre8;
        ImageDecor *arbre9, *arbre10, *arbre11, *arbre12, *arbre13, *arbre14, *arbre15, *arbre16, *arbre17;
        ImageDecor *buisson1, *buisson2, *buissonbaies1, *buissonbaies2;
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
