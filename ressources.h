#ifndef RESSOURCES_H
#define RESSOURCES_H

#include <QObject>

class Ressource : public QObject {

    Q_OBJECT

    public:

        Ressource(QString nom);
        QString getNom() {return this->nom;}
        int getNombre() {return this->nombre;}
        void ajouterRessource(int nb);
        bool retirerRessource(int nb);

    protected:

        QString nom;
        int nombre;

};

class Nourritures : public Ressource {

    Q_OBJECT

    public:

        Nourritures(QString nom, int sante);
        int getSante() {return this->sante;}

    private:

        int sante;

};

#endif // RESSOURCES_H
