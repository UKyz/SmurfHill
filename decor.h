#ifndef DECOR_H
#define DECOR_H

#include "autre.h"
#include "view.h"
#include <QtDebug>

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
        Image *getMaisonSette() {return this->maisonSette;}
        Image *getMaisonSCostaud() {return this->maisonSCostaud;}
        Image *getMaisonSPaysan() {return this->maisonSPaysan;}
        Image *getMoulinS() {return this->moulinS;}
        Image *getArbre1() {return this->arbre1;}

    private:

    protected:
        Image *grandS;
        Image *maisonSette;
        Image *maisonSCostaud;
        Image *maisonSPaysan;
        Image *moulinS;
        Image *maison1;
        Image *maison2;
        Image *maison3;
        Image *maison4;
        Image *maison5;
        Image *arbre1;

public slots:
    void pixmapClicked()
    {
        qDebug() << "item clicked!" ;
    }


};

class Foret : public Decor
{

    Q_OBJECT

    public:

        Foret(int posX, int posY, View *view);

    private:

    protected:
        Image *arbre1;
        Image *arbre2;
        Image *arbre3;


};



#endif // DECOR_H
