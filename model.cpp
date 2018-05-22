#include "view.h"
#include "controller.h"
#include "model.h"
#include "decor.h"
#include "personnages.h"
#include <time.h>

#include <QFont>
#include <math.h>

Model::Model()
{
    this->listAdvicePapaSmurf->append(QObject::tr("Je veille chaque jour à ce que \nmes petits Schtroumpfs ne \nmanquent de rien !"));
    this->listAdvicePapaSmurf->append(QObject::tr("Aller en foret te permettra de \ntrouver de la nouriture \npour le village."));
    this->listAdvicePapaSmurf->append(QObject::tr("Le blé permet au Schtroumpf \nBoulanger de faire du pain."));
    this->listAdvicePapaSmurf->append(QObject::tr("La salsepareille est un élément \nessentiel de notre alimentation."));
    this->listAdvicePapaSmurf->append(QObject::tr("Prend garde aux \nSchtroumpfs noirs !"));
    this->listAdvicePapaSmurf->append(QObject::tr("Prend garde à la réserve \nde nourriture, l'hiver \napproche à grand schtroumpf."));
    this->listAdvicePapaSmurf->append(QObject::tr("Clique sur la maison du \nSchtroumpf Paysan \npour récolter du blé."));
    this->listAdvicePapaSmurf->append(QObject::tr("Clique sur la maison du \nSchtroumpf Boulanger \npour fabriquer le pain."));
    this->listAdvicePapaSmurf->append(QObject::tr("Le Schtroumpf Costaud t'aide \nà améliorer les Schtroumpfs."));
    this->listAdvicePapaSmurf->append(QObject::tr("Docteur Schtroumpf va soigner \nles Schtroumpfs grace à la nourriture : "
                                                  "\n\t1 pain = ") + QString::number(this->getBagBreads()->getHealth()) + QObject::tr(" PV "
                                                  "\n\t1 baie = ") + QString::number(this->getBagBerries()->getHealth()) + QObject::tr(" PV "
                                                  "\n\t1 gland = ") + QString::number(this->getBagAcorns()->getHealth()) + QObject::tr(" PV."));
    this->listAdvicePapaSmurf->append(QObject::tr("La maison souche est la réserve. \nClique dessus et elle t'indiquera \nce que tu possèdes."));
    this->listAdvicePapaSmurf->append(QObject::tr("Schtroumpf à Lunettes, \noù en sont les Schtroumpfs ?"));

    this->listAdviceSmurfette->append(QObject::tr("Schtroumpf journée pour \nune promenade !"));
    this->listAdviceSmurfette->append(QObject::tr("Schtroumpfera bien qui \nSchtroumpfera le dernier !"));
    this->listAdviceSmurfette->append(QObject::tr("Le Schtroumpf Bricoleur sait \ntoujours comment nous aider."));
    this->listAdviceSmurfette->append(QObject::tr("\"Comme le dit toujours \nle Grand Schtroumpf...\", \nPff il est schtroumpfement pénible \nle Schtroumpf à Lunettes..."));
    this->listAdviceSmurfette->append(QObject::tr("Ah non, Schtroumpf à Lunettes... \nNe recommence pas avec tes \nréflexions schtroumpfistes !"));
    this->listAdviceSmurfette->append(QObject::tr("Waouh! Qu'il est fort\nle Schtroumpf Costaud !"));
    this->listAdviceSmurfette->append(QObject::tr("Des noix ! Toujours des noix ! \nJe me demande ce qu’il peut \nbien schtroumpfer \navec toutes ces noix ?..."));
    this->listAdviceSmurfette->append(QObject::tr("Schtroumpf Grognon, tu ne veux \npas schtroumpfer à la balle, \ntu ne veux pas schtroumpfer du \ngâteau ni de la musique ! \nTu n’aimes donc rien ?"));
    this->listAdviceSmurfette->append(QObject::tr("Schtroumpfs Boulanger, \nSchtroumpf Patissier, \nvous mettez du soleil dans \nle coeur des Schtroumpfs !"));
    this->listAdviceSmurfette->append(QObject::tr("Le chemin du village est un \nsecret bien schtroumpfé ! \nGargamel ne pourra pas \nnous trouver!"));

    this->fillListResource();
    this->fillListSpawnNicePerso();
    this->fillListSpotMadPersoFixed();
}

Village *Model::setVillage(int x, int y, View *view) {
    this->villagePosX = x;
    this->villagePosY = y;
    Village *villageS = new Village("V", this->villagePosX, this->villagePosY, view);
    addSetting(villageS);
    return villageS;
}

Forest1 *Model::setForest1(int x, int y, View *view) {
    Forest1 *forestN = new Forest1("F1", x, y, view);
    addSetting(forestN);
    return forestN;
}

Forest2 *Model::setForest2(int x, int y, View *view) {
    Forest2 *forestN = new Forest2("F2", x, y, view);
    addSetting(forestN);
    return forestN;
}

Forest3 *Model::setForest3(int x, int y, View *view) {
    Forest3 *forestN = new Forest3("F3", x, y, view);
    addSetting(forestN);
    return forestN;
}

Forest4 *Model::setForest4(int x, int y, View *view) {
    Forest4 *forestN = new Forest4("F4", x, y, view);
    addSetting(forestN);
    return forestN;
}

Forest5 *Model::setForest5(int x, int y, View *view) {
    Forest5 *forestN = new Forest5("F5", x, y, view);
    addSetting(forestN);
    return forestN;
}

Forest6 *Model::setForest6(int x, int y, View *view) {
    Forest6 *forestN = new Forest6("F6", x, y, view);
    addSetting(forestN);
    return forestN;
}

Forest7 *Model::setForest7(int x, int y, View *view) {
    Forest7 *forestN = new Forest7("F7", x, y, view);
    addSetting(forestN);
    return forestN;
}


void Model::initFarmer(int level) {
    this->farmer = new Farmer();
    if (level > 0) {
        this->farmerUp(level-1);
    }
}

void Model::initBaker(int level) {
    this->baker = new Baker();
    if (level > 0) {
        this->bakerUp(level-1);
    }
}

void Model::initHefty(int level) {
    this->hefty = new Hefty();
    if (level > 0) {
        this->heftyUp(level-1);
    }
}


void Model::actionPerso(int x, int y, int nbS) {

    // On met à jour les distancePositionClicked de chaque S

    for (int i=0; i<listNicePerso->size(); i++) {
        int a = x-(listNicePerso->at(i)->getPosX());
        int b = y-(listNicePerso->at(i)->getPosY());
        float distance = sqrt(pow(a,2)+pow(b,2));
        listNicePerso->at(i)->setDistancePositionClicked(distance);
        /*if (abs(y-listNicePerso->at(i)->getPosX())/(listNicePerso->at(i)->getSpeed()) > listNicePerso->at(i)->getDistancePositionClicked())
            listNicePerso->at(i)->setDistancePositionClicked(abs(y-listNicePerso->at(i)->getPosX())/(listNicePerso->at(i)->getSpeed()));
*/
    }

    // On duplique la liste de S qu'on va trier en fonction de leur DistancePositionClicked
    QList<NicePerso *> *listSorted = listNicePerso;

    for (int i=(listSorted->size()-1); i>0; i--) {

        for (int j=0; j<(i); j++) {

            if (listSorted->at(j+1)->getDistancePositionClicked() < listSorted->at(j)->getDistancePositionClicked()) {
                listSorted->swap(j+1,j);
            }

        }

    }

    for (int i=0; i<listSorted->size(); i++) {

        qDebug() << " i = " << i << " Distance : " << listSorted->at(i)->getDistancePositionClicked() <<
                    " pos (" << listSorted->at(i)->getPosX() << "," << listSorted->at(i)->getPosY() << ")";

    }

    // On va déplacer les nbS premier S les plus proche du clique

    int cptSLibre=0;
    int cptS=0;
    while (cptSLibre < nbS) {
        if (listSorted->at(cptS)->isFree()) {
            listSorted->at(cptS)->moveTo(x, y);
            cptSLibre++;
        }
        cptS++;
    }
}

int Model::getNumberFreePerso() {

    int cptS=0;
    for (int i=0; i<listNicePerso->size(); i++) {
        if (listNicePerso->at(i)->isFree())
            cptS++;
    }
    return cptS;

}


Image * Model::getImageFront() {

    Image *imageFront = new Image(":/images/parchemin");
    imageFront->setPos(200, 100);

    return imageFront;

}

QGraphicsTextItem * Model::getMessageFront() {
    QString texte = QObject::tr("Bonjour et bienvenue dans le village \ndes Schtroumpfs ! \n\n"
                    "Le Grand Schtroumpf va te guider. \n"
                    "Clique sur lui pour qu'il t'explique \ncomment jouer. \n"
                    "La Schtroumpfette va te raconter \nl'histoire des Schtroumpfs. \n"
                    "\n\nEn cliquant sur ce message, \nil disparaitra.");

    QGraphicsTextItem *texteItem = new QGraphicsTextItem(texte);
    QFont f("Monotype Corsiva", 10);
    texteItem->setFont(f);
    texteItem->setPos(220, 140);
    return texteItem;

}


void Model::fillListResource() {
    this->listSpotResourceItem->append(new QPointF(100,600));
    this->listSpotResourceItem->append(new QPointF(70,300));
    this->listSpotResourceItem->append(new QPointF(450,450));
    this->listSpotResourceItem->append(new QPointF(250,1000));
    this->listSpotResourceItem->append(new QPointF(100,1450));
    this->listSpotResourceItem->append(new QPointF(700,900));
    this->listSpotResourceItem->append(new QPointF(725,1900));
    this->listSpotResourceItem->append(new QPointF(1450,1850));
    this->listSpotResourceItem->append(new QPointF(1700,1750));
    this->listSpotResourceItem->append(new QPointF(2100,1950));
    this->listSpotResourceItem->append(new QPointF(2950,1950));
    this->listSpotResourceItem->append(new QPointF(2700,1800));
    this->listSpotResourceItem->append(new QPointF(2900,1550));
    this->listSpotResourceItem->append(new QPointF(2300,1475));
    this->listSpotResourceItem->append(new QPointF(2000,1500));
    this->listSpotResourceItem->append(new QPointF(2000,1325));
    this->listSpotResourceItem->append(new QPointF(1400,1325));
    this->listSpotResourceItem->append(new QPointF(800,1275));
    this->listSpotResourceItem->append(new QPointF(2500,1050));
    this->listSpotResourceItem->append(new QPointF(2950,950));
    this->listSpotResourceItem->append(new QPointF(2350,825));
    this->listSpotResourceItem->append(new QPointF(1850,850));
    this->listSpotResourceItem->append(new QPointF(1450,550));
    this->listSpotResourceItem->append(new QPointF(950,625));
    this->listSpotResourceItem->append(new QPointF(800,400));
    this->listSpotResourceItem->append(new QPointF(1150,300));
    this->listSpotResourceItem->append(new QPointF(1200,50));
    this->listSpotResourceItem->append(new QPointF(1850,10));
    this->listSpotResourceItem->append(new QPointF(2450,50));
    this->listSpotResourceItem->append(new QPointF(2300,350));
    this->listSpotResourceItem->append(new QPointF(2925,25));
    this->listSpotResourceItem->append(new QPointF(2350,550));
}

void Model::fillListSpawnNicePerso() {
    this->listSpawnNicePerso->append(new QPointF(880,740));
    this->listSpawnNicePerso->append(new QPointF(840,780));
    this->listSpawnNicePerso->append(new QPointF(810,840));
    this->listSpawnNicePerso->append(new QPointF(785,895));
    this->listSpawnNicePerso->append(new QPointF(815,950));
    this->listSpawnNicePerso->append(new QPointF(850,1000));
    this->listSpawnNicePerso->append(new QPointF(870,1050));
    this->listSpawnNicePerso->append(new QPointF(920,1100));
    this->listSpawnNicePerso->append(new QPointF(965,1135));
    this->listSpawnNicePerso->append(new QPointF(1030,1175));
    this->listSpawnNicePerso->append(new QPointF(1100,1170));
    this->listSpawnNicePerso->append(new QPointF(1170,1150));
    this->listSpawnNicePerso->append(new QPointF(1240,1150));
    this->listSpawnNicePerso->append(new QPointF(1300,1160));
    this->listSpawnNicePerso->append(new QPointF(1360,1150));
    this->listSpawnNicePerso->append(new QPointF(1430,1160));
    this->listSpawnNicePerso->append(new QPointF(1490,1140));
    this->listSpawnNicePerso->append(new QPointF(1540,1090));
    this->listSpawnNicePerso->append(new QPointF(1610,1070));
    this->listSpawnNicePerso->append(new QPointF(1670,1050));
    this->listSpawnNicePerso->append(new QPointF(1720,1010));
    this->listSpawnNicePerso->append(new QPointF(1740,960));
    this->listSpawnNicePerso->append(new QPointF(1750,900));
    this->listSpawnNicePerso->append(new QPointF(1740,830));
    this->listSpawnNicePerso->append(new QPointF(1720,770));
    this->listSpawnNicePerso->append(new QPointF(1700,720));
    this->listSpawnNicePerso->append(new QPointF(1660,660));
    this->listSpawnNicePerso->append(new QPointF(1600,640));
    this->listSpawnNicePerso->append(new QPointF(1530,620));
    this->listSpawnNicePerso->append(new QPointF(1460,600));
    this->listSpawnNicePerso->append(new QPointF(1400,590));
    this->listSpawnNicePerso->append(new QPointF(1330,600));
    this->listSpawnNicePerso->append(new QPointF(1255,610));
    this->listSpawnNicePerso->append(new QPointF(1190,620));
    this->listSpawnNicePerso->append(new QPointF(1120,600));
    this->listSpawnNicePerso->append(new QPointF(1050,630));
    this->listSpawnNicePerso->append(new QPointF(990,665));
    this->listSpawnNicePerso->append(new QPointF(920,700));
    this->listSpawnNicePerso->append(new QPointF(880,740));
}

void Model::fillListSpotMadPersoFixed() {
    this->listSpotMadPersoFixed->append((new QPointF(0, 50)));
    this->listSpotMadPersoFixed->append((new QPointF(0, 100)));
    this->listSpotMadPersoFixed->append((new QPointF(0, 150)));
    this->listSpotMadPersoFixed->append((new QPointF(0, 200)));
}
