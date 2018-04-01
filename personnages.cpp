#include "personnages.h"
#include "autre.h"

Perso::Perso(QString nom){
    this->nom = nom;
}

Perso::~Perso()
{
    delete this;
}

PersoNormaux::PersoNormaux(QString nom, int pv, int vitesse)
    :Perso(nom) {

    this->pv = pv;
    this->vitesse = vitesse;
    setImagePerso(new Image("/Users/Victor/Schtroumph-Hill/images/Schtroumpf.png"));

}


PersoNormaux::~PersoNormaux()
{
    delete this;
}
