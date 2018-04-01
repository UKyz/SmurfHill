#include "ressources.h"

Ressource::Ressource(QString nom) {this->nom = nom; this->nombre = 0;}

void Ressource::ajouterRessource(int nb) {this->nombre += nb;}
bool Ressource::retirerRessource(int nb) {
    if (this->nombre - nb >= 0) {
        this->nombre -= nb;
        return true;
    }
    else
        return false;
}

Nourritures::Nourritures(QString nom, int sante)
    :Ressource(nom) {
    this->sante = sante;
}
