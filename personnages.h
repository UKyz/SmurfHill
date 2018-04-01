#ifndef PERSONNAGES_H
#define PERSONNAGES_H

#include <QObject>

#include "autre.h"

class Perso : public QObject
{

    Q_OBJECT

    public:

        Perso(QString nom);
        ~Perso();

        QString getNom() {return this->nom;}
        int getPosX() {return this->posX;}
        int getPosY() {return this->posY;}

    private:

    protected:
        QString nom;
        int posX;
        int posY;


};

class PersoNormaux : public Perso
{

    Q_OBJECT

    public:

        PersoNormaux(QString nom, int pv=0, int vitesse=0);
        ~PersoNormaux();
        int getPv() {return this->pv;}
        int getVitesse() {return this->vitesse;}
        void setImagePerso(Image *image) {this->imagePerso = image;}
        Image *getImagePerso() {return this->imagePerso;}

    private:

        int pv;
        int vitesse;
        Image *imagePerso;

};


#endif // PERSONNAGES_H
