#include "./view/includes/view.h"
#include "../includes/controller.h"
#include "./model/includes/model.h"
#include "./model/includes/autre.h"
#include "./model/includes/personnages.h"
#include "./model/includes/ressources.h"
#include "./model/includes/decor.h"

Controller::Controller(Model *model, View *view): QObject(0) {
    this->model = model;
    this->view = view;
    this->view->setControl(this);
    chrono = new QTimer;
    this->timer = new QTimer;
    this->timerWheat = new QTimer;
    this->timerSpawnMadPersoFixed = new QTimer;
    this->timerSpawnMadPersoMovable = new QTimer;
    this->timerResources = new QTimer;
}

void Controller::startNewGame() {
    QFile file("save.txt");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::about(view, "Erreur", "Impossible de sauvegarder");
    } else {
        QTextStream flux(&file);
        flux << "";
    }
    file.close();

    QString listSetting = "";
    listSetting += "F7 100 50 F1 750 150 F2 1400 100 F3 2000 100 F5 2600 50 "; //1ère ligne
    listSetting += "F6 350 550 F6 1950 400 F4 2600 600 "; //2ème ligne
    listSetting += "F7 100 1100 F4 1600 1300 F2 2100 950 F3 2500 1300 "; //3ème ligne
    listSetting += "F4 200 1600 F5 1000 1400 F6 2300 1600 "; //dernière ligne
    listSetting += "V 1000 800 ";

    QString persoG1 = "1725 1000 1 100 100 10 ", persoG2 = "1775 950 1 100 100 10 ", persoG3 = "1850 975 1 100 100 10 ",
            persoG4 = "1780 1050 1 100 100 10 ", persoG5 = "1845 1040 1 100 100 10 ";
    QString persoG6 = "1100 550 1 100 100 10 ", persoG7 = "1200 600 1 100 100 10 ", persoG8 = "1150 500 1 100 100 10 ",
            persoG9 = "1300 550 1 100 100 10 ", persoG10 = "1250 500 1 100 100 10 ";
    QString persoG11 = "800 1050 1 100 100 10 ", persoG12 = "875 1075 1 100 100 10 ", persoG13 = "750 1125 1 100 100 10 ",
            persoG14 = "825 1150 1 100 100 10 ", persoG15 = "925 1125 1 100 100 10 ";
    QString listNicePerso = persoG1 + persoG2 + persoG3 + persoG4 + persoG5 + persoG6 + persoG7 + persoG8 +
            persoG9 + persoG10;
    listNicePerso += persoG11 + persoG12 + persoG13 + persoG14 + persoG15;

    this->model->initFarmer();
    this->model->initBaker();
    this->model->initHefty();
    this->model->initScore(0);

    startGame(listSetting, listNicePerso, "", "", "");
}

void Controller::startGame(QString setting, QString nicePerso, QString madPersoFixed, QString madPersoMovable, QString resourceItem) {
    view->installScene();

    this->fillListAdvicePapaSmurf();
    this->fillListAdviceSmurfette();
    this->fillListResource();
    this->fillListSpawnNicePerso();
    this->fillListSpotMadPersoFixed();
    this->fillListSpotMadPersoMovable();

    QStringList listSetting = setting.split(" ");
    for (int i=0; i<listSetting.size()-1; i+=3) {
        if (listSetting[i] == "V") {
            view->addVillage(this->model->setVillage(listSetting[i+1].toInt(), listSetting[i+2].toInt(), view));
        } else if(listSetting[i] == "F1") {
            view->addForest1(this->model->setForest1(listSetting[i+1].toInt(), listSetting[i+2].toInt(), view));
        } else if(listSetting[i] == "F2") {
            view->addForest2(this->model->setForest2(listSetting[i+1].toInt(), listSetting[i+2].toInt(), view));
        } else if(listSetting[i] == "F3") {
            view->addForest3(this->model->setForest3(listSetting[i+1].toInt(), listSetting[i+2].toInt(), view));
        } else if(listSetting[i] == "F4") {
            view->addForest4(this->model->setForest4(listSetting[i+1].toInt(), listSetting[i+2].toInt(), view));
        } else if(listSetting[i] == "F5") {
            view->addForest5(this->model->setForest5(listSetting[i+1].toInt(), listSetting[i+2].toInt(), view));
        } else if(listSetting[i] == "F6") {
            view->addForest6(this->model->setForest6(listSetting[i+1].toInt(), listSetting[i+2].toInt(), view));
        } else if(listSetting[i] == "F7") {
            view->addForest7(this->model->setForest7(listSetting[i+1].toInt(), listSetting[i+2].toInt(), view));
        }
    }
    if (nicePerso != "") {
        QStringList listNicePerso = nicePerso.split(" ");
        for (int i=0; i<listNicePerso.size()-1; i+=6) {
            NicePerso *S = new NicePerso(listNicePerso[i].toInt(), listNicePerso[i+1].toInt(), listNicePerso[i+2].toInt(),
                    listNicePerso[i+3].toInt(), listNicePerso[i+4].toInt(), listNicePerso[i+5].toInt());
            model->addNicePerso(S);
            view->addNormalPerso(S);
        }
    }
    if (madPersoFixed != "") {
        QStringList listMadPersoFixed = madPersoFixed.split(" ");
        for (int i=0; i<listMadPersoFixed.size()-1; i+=5) {
            MadPerso *S = new MadPerso(listMadPersoFixed[i].toInt(), listMadPersoFixed[i+1].toInt(),
                    listMadPersoFixed[i+2].toInt(), listMadPersoFixed[i+3].toInt(), listMadPersoFixed[i+4].toInt());
            model->addMadPersoFixed(S);
            view->addNormalPerso(S);
        }
    }
    if (madPersoMovable != "") {
        QStringList listMadPersoMovable = madPersoMovable.split(" ");
        for (int i=0; i<listMadPersoMovable.size()-1; i+=5) {
            MadPerso *S = new MadPerso(listMadPersoMovable[i].toInt(), listMadPersoMovable[i+1].toInt(),
                    listMadPersoMovable[i+2].toInt(), listMadPersoMovable[i+3].toInt(), listMadPersoMovable[i+4].toInt());
            model->addMadPersoFixed(S);
            view->addNormalPerso(S);
        }
    }
    this->displayResourceItem(resourceItem);
    this->model->setFrontMessage(tr("Bonjour et bienvenue dans le village \ndes Schtroumpfs ! \n\n"
                                    "Le Grand Schtroumpf va te guider. \n"
                                    "Clique sur lui pour qu'il t'explique \ncomment jouer. \n"
                                    "La Schtroumpfette va te raconter \nl'histoire des Schtroumpfs. \n"
                                    "\n\nEn cliquant sur ce message, \nil disparaitra."));
    this->view->displayFrontMessage();
    // Start Timers
    this->model->setTimeStart(timeStart());
    connect(timer, SIGNAL(timeout()), this, SLOT(gameLoop()));
    this->timer->start(16);
    connect(timerWheat, SIGNAL(timeout()), this->model->getWheatField(), SLOT(summer()));
    this->timerWheat->start(60000);
    connect(timerSpawnMadPersoFixed, SIGNAL(timeout()), this, SLOT(checkMadPersoFixed()));
    this->timerSpawnMadPersoFixed->start(30000);
    connect(timerSpawnMadPersoMovable, SIGNAL(timeout()), this, SLOT(checkMadPersoMovable()));
    this->timerSpawnMadPersoMovable->start(60000);
    connect(timerResources, SIGNAL(timeout()), this, SLOT(checkResources()));
    this->timerResources->start(60000);
    // Cheat Game
    this->model->getBagSarsaparillas()->addResource(1000);
}

void Controller::save() {
    QFile file("save.txt");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::about(view, tr("Erreur"), tr("Impossible de sauvegarder"));
    } else {
        QTextStream flux(&file);
        flux << tr("Date de la derniere sauvegarde : ") << QDateTime::currentDateTime().toString("dd/MM/yyyy hh:mm:ss") << endl;
        for (Setting *D : *this->model->getlistSetting()) {
            flux << D->getType() << " " << D->getPosX() << " " << D->getPosY() << " ";
        }
        flux << endl;
        for (NicePerso *PG : *this->model->getlistNicePerso()) {
            flux << PG->getPosX() << " " << PG->getPosY() << " " << PG->getDamage() << " " << PG->getHp() << " " << PG->getHpMax() <<
                    " " << PG->getSpeed() << " ";
        }
        flux << endl;
        for (MadPerso *PMF : *this->model->getlistMadPersoFixed()) {
            flux << PMF->getPosX() << " " << PMF->getPosY() << " " << PMF->getDamage() << " " << PMF->getHp() << " " <<
                    PMF->getSpeed() << " ";
        }
        flux << endl;
        for (MadPerso *PMM : *this->model->getlistMadPersoMovable()) {
            qDebug() << "test ";
            flux << PMM->getPosX() << " " << PMM->getPosY() << " " << PMM->getDamage() << " " << PMM->getHp() << " " <<
                    PMM->getSpeed() << " ";
        }
        flux << endl;
        for (ResourceItem *R : *this->model->getlistResourceItem()) {
            flux << R->getName() << " " << R->getNumber() << " " << R->getPosX() << " " << R->getPosY() << " ";
        }
        flux << endl << gameDuration();
        flux << endl << getScore();
        flux << endl << getNumberSarsaparilla();
        flux << endl << getNumberAcorn();
        flux << endl << getNumberBerry();
        flux << endl << getNumberWheat();
        flux << endl << getNumberBread();
        flux << endl << getLevelFarmer();
        flux << endl << getLevelBaker();
        flux << endl << getLevelHefty();
    }
    file.close();
}

void Controller::loadSave() {
    QString setting, nicePerso, madPersoFixed, madPersoMovable, ressouceItem;
    QString time, score, sarsaparillas, berries, acorn, wheat, bread;
    QString farmer, baker, hefty;
    QFile file("save.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::about(view, tr("Erreur"), tr("Impossible de lire le fichier de sauvegarde"));
    }
    else {
        QTextStream flux(&file);
        QString date = flux.readLine();
        QMessageBox::information(view, tr("Date de sauvegarde"), date);

        setting = flux.readLine();
        nicePerso = flux.readLine();
        madPersoFixed = flux.readLine();
        madPersoMovable = flux.readLine();
        ressouceItem = flux.readLine();

        time = flux.readLine();
        score = flux.readLine();
        sarsaparillas = flux.readLine();
        acorn = flux.readLine();
        berries = flux.readLine();
        wheat = flux.readLine();
        bread = flux.readLine();

        farmer = flux.readLine();
        baker = flux.readLine();
        hefty = flux.readLine();
    }
    file.close();

    this->model->initFarmer();
    this->model->farmerUp(farmer.toInt());
    this->model->initBaker();
    this->model->bakerUp(baker.toInt());
    this->model->initHefty();
    this->model->heftyUp(hefty.toInt());
    this->model->initScore(score.toInt());

    this->model->setTimePreviouslyPlayed(time.toInt());
    this->model->getBagSarsaparillas()->addResource(sarsaparillas.toInt());
    this->model->getBagAcorns()->addResource(acorn.toInt());
    this->model->getBagBerries()->addResource(berries.toInt());
    this->model->getBagWheats()->addResource(wheat.toInt());
    this->model->getBagBreads()->addResource(bread.toInt());

    startGame(setting, nicePerso, madPersoFixed, madPersoMovable, ressouceItem);
}

void Controller::saveQuit() {
    save();
    QCoreApplication::quit();
}

int Controller::gameDuration() {
    QDateTime timeNow = QDateTime::currentDateTime();
    QDateTime timeStart = getTimeStart();
    qint64 millisecondsDiff = timeStart.msecsTo(timeNow);
    int chrono = millisecondsDiff/1000 + (this->model->getTimePreviouslyPlayed());
    return chrono;
}

void Controller::displayResourceItem(QString resourceItem) {
    if (resourceItem == "") {
        for (Setting * d : *this->model->getlistSetting()) {
            Forest *forest = dynamic_cast<Forest *>(d);
            if (forest) {
                this->model->addResourceItem(new ResourceItem("Wheat", ((rand() % 6) + 1), new ImageSetting(":/images/ble"),
                                                                forest->getPosXWheat(), forest->getPosYWheat()));
                this->view->scene->addItem(this->model->getlistResourceItem()->last()->getImageItem());
                this->model->addResourceItem(new ResourceItem("Acorn", ((rand() % 5) + 1), new ImageSetting(":/images/noisette"),
                                                                forest->getPosXAcorn(), forest->getPosYAcorn()));
                this->view->scene->addItem(this->model->getlistResourceItem()->last()->getImageItem());
                this->model->addResourceItem(new ResourceItem("Baie", ((rand() % 5) + 1), new ImageSetting(":/images/baie"),
                                                                forest->getPosXBerries(), forest->getPosYBerries()));
                this->view->scene->addItem(this->model->getlistResourceItem()->last()->getImageItem());
             }
        }
        for (QPointF * point : *this->model->getlistSpotResourceItem()) {
            int i = ((rand() % 10) + 1);

            if (i > 9) {
                this->model->addResourceItem(new ResourceItem("Sarsaparilla", ((rand() % 3) + 1),
                                                              new ImageSetting(":/images/salsepareille"),point->x(), point->y()));
            } else if (i > 6) {
                this->model->addResourceItem(new ResourceItem("Wheat", ((rand() % 3) + 1), new ImageSetting(":/images/ble"),
                                                                point->x(), point->y()));
            } else if (i > 3) {
                this->model->addResourceItem(new ResourceItem("Acorn", ((rand() % 3) + 1), new ImageSetting(":/images/noisette"),
                                                                point->x(), point->y()));
            } else if (i > 0) {
                this->model->addResourceItem(new ResourceItem("Berry", ((rand() % 3) + 1), new ImageSetting(":/images/baie"),
                                                                point->x(), point->y()));
            }
            this->view->scene->addItem(this->model->getlistResourceItem()->last()->getImageItem());
        }
    } else {
        QStringList listRessouceItem = resourceItem.split(" ");
        for (int i=0; i<listRessouceItem.size()-1; i+=4) {
            if (listRessouceItem[i] == "Sarsaparilla") {
                this->model->addResourceItem(new ResourceItem(listRessouceItem[i], listRessouceItem[i+1].toInt(),
                                             new ImageSetting(":/images/salsepareille"),
                                                                listRessouceItem[i+2].toInt(), listRessouceItem[i+3].toInt()));
            } else if (listRessouceItem[i] == "Wheat") {
                this->model->addResourceItem(new ResourceItem(listRessouceItem[i], listRessouceItem[i+1].toInt(),
                                             new ImageSetting(":/images/ble"),
                                                                listRessouceItem[i+2].toInt(), listRessouceItem[i+3].toInt()));
            } else if (listRessouceItem[i] == "Acorn") {
                this->model->addResourceItem(new ResourceItem(listRessouceItem[i], listRessouceItem[i+1].toInt(),
                                             new ImageSetting(":/images/noisette"),
                                                                listRessouceItem[i+2].toInt(), listRessouceItem[i+3].toInt()));
            } else if (listRessouceItem[i] == "Berry") {
                this->model->addResourceItem(new ResourceItem(listRessouceItem[i], listRessouceItem[i+1].toInt(),
                                             new ImageSetting(":/images/baie"),
                                                                listRessouceItem[i+2].toInt(), listRessouceItem[i+3].toInt()));
            }
            this->view->scene->addItem(this->model->getlistResourceItem()->last()->getImageItem());
        }
    }
}

void Controller::gameLoop() {

    // NicePerso
    for (NicePerso *S : *this->model->getlistNicePerso()) {

        if (S->hasAction()) {
            ActionMove* nextActionMove = dynamic_cast<ActionMove*>(S->getFirstAction());
            ActionFight* nextActionFight = dynamic_cast<ActionFight*>(S->getFirstAction());

            if (nextActionMove) {
                if (this->view->scene->itemAt(QPointF(S->getPosX() + nextActionMove->getDepX(), S->getPosY() +
                                                      nextActionMove->getDepY()), QTransform()) == NULL)
                    S->setPos(S->getPosX() + nextActionMove->getDepX(), S->getPosY() + nextActionMove->getDepY());
                S->removeFirstAction();

                QList<QGraphicsItem *> listCollision = S->getImagePerso()->collidingItems();
                for (QGraphicsItem * i : listCollision) {
                    ImageSetting *itemSetting = dynamic_cast<ImageSetting *>(i);

                    if (itemSetting) {
                        QPointF *pointDestination = S->getDestination();
                        S->removeAllActions();
                        QPointF *pointSuivant = new QPointF(S->getPosX(), S->getPosY());
                        QPointF *pointOrigine = new QPointF(S->getPosX()-nextActionMove->getDepX(),
                                                            S->getPosY()-nextActionMove->getDepY());
                        pointSuivant = this->getPointDecale(pointOrigine, pointSuivant);
                        S->setPos(pointSuivant->x(), pointSuivant->y());
                        S->moveTo(pointDestination->x(), pointDestination->y());
                    }
                }
            } else if (nextActionFight) {
                if (nextActionFight->getDefender()->getHurt(nextActionFight->getFighter()->getDamage())) {
                    MadPerso* perso = dynamic_cast<MadPerso*>(nextActionFight->getDefender());
                    if (perso) {
                        this->model->getlistMadPersoFixed()->removeAll(perso);
                        this->model->getlistMadPersoMovable()->removeAll(perso);
                        this->view->scene->removeItem(this->view->scene->itemAt(QPointF(perso->getPosX()+20, perso->getPosY()+20),
                                                                                QTransform()));
                        this->model->addPoints(100);
                    }
                }
                S->removeFirstAction();
            }
        }
        bool premier = true;
        for (MadPerso *M : *this->model->getlistMadPersoFixed()) {
            if (distanceBetweenPoints(new QPointF(S->getPosX(), S->getPosY()), new QPointF(M->getPosX(), M->getPosY())) < 100) {
                if (premier) {
                    ActionFight *action = new ActionFight(S, M);
                    S->addActionInFirst(action);
                    premier = false;
                }
            }
        }
        for (MadPerso *M : *this->model->getlistMadPersoMovable()) {
            if (distanceBetweenPoints(new QPointF(S->getPosX(), S->getPosY()), new QPointF(M->getPosX(), M->getPosY())) < 100) {
                if (premier) {
                    ActionFight *action = new ActionFight(S, M);
                    S->addActionInFirst(action);
                    premier = false;
                }
            }
        }
        for (ResourceItem *I : *this->model->getlistResourceItem()) {
            if (distanceBetweenPoints(new QPointF(S->getPosX(), S->getPosY()), new QPointF(I->getPosX(),
                                                                                           I->getPosY())) < 100) {
                this->view->scene->removeItem(this->view->scene->itemAt(QPointF(I->getPosX()+20, I->getPosY()+20),
                                                                        QTransform()));
                if (I->getName() == "Wheat") {
                    this->model->getBagWheats()->addResource(I->getNumber());
                } else if (I->getName() == "Berry") {
                    this->model->getBagBerries()->addResource(I->getNumber());
                } else if (I->getName() == "Bread") {
                    this->model->getBagBreads()->addResource(I->getNumber());
                } else if (I->getName() == "Acorn") {
                    this->model->getBagAcorns()->addResource(I->getNumber());
                } else if (I->getName() == "Sarsaparilla") {
                    this->model->getBagSarsaparillas()->addResource(I->getNumber());
                }
                this->model->addPoints(2);
                this->model->getlistResourceItem()->removeAll(I);
            }
        }
        premier = true;
    }

    // MadPersoFixed
    for (MadPerso *S : *this->model->getlistMadPersoFixed()) {
        if (S->hasAction()) {
            ActionFight* nextActionFight = dynamic_cast<ActionFight*>(S->getFirstAction());
            if (nextActionFight) {
                if (nextActionFight->getDefender()->getHurt(nextActionFight->getFighter()->getDamage())) {
                    NicePerso* perso = dynamic_cast<NicePerso*>(nextActionFight->getDefender());
                    if (perso) {
                        this->model->getlistNicePerso()->removeAll(perso);
                        this->view->scene->removeItem(this->view->scene->itemAt(QPointF(perso->getPosX()+20, perso->getPosY()+20),
                                                                                QTransform()));
                    }
                }
                S->removeFirstAction();
            }
        }
        bool premier = true;
        for (NicePerso *M : *this->model->getlistNicePerso()) {
            if (distanceBetweenPoints(new QPointF(S->getPosX(), S->getPosY()), new QPointF(M->getPosX(), M->getPosY())) < 100) {
                if (premier) {
                    ActionFight *action = new ActionFight(S, M);
                    S->addActionInFirst(action);
                    premier = false;
                }
            }
        }
        premier = true;
    }

    // MadPerso Movable
    for (MadPerso *S : *this->model->getlistMadPersoMovable()) {
        if (S->hasAction()) {
            ActionMove* nextActionMove = dynamic_cast<ActionMove*>(S->getFirstAction());
            ActionFight* nextActionFight = dynamic_cast<ActionFight*>(S->getFirstAction());
            if (nextActionMove) {
                if (this->view->scene->itemAt(QPointF(S->getPosX() + nextActionMove->getDepX(), S->getPosY() +
                                                      nextActionMove->getDepY()), QTransform()) == NULL) {
                    S->setPos(S->getPosX() + nextActionMove->getDepX(), S->getPosY() + nextActionMove->getDepY());
                }
                S->moveTo(S->getPosX() + nextActionMove->getDepX() + 20, S->getPosY() + nextActionMove->getDepY() + 20);
                S->removeFirstAction();
                if (S->getPosX() < 0 || S->getPosY() < 0 || S->getPosX() > 2960 || S->getPosY() > 1960) {
                    changeMoveMadPerso(nextActionMove, S);
                }
                else {
                    QList<QGraphicsItem *> listCollision = S->getImagePerso()->collidingItems();

                    for (QGraphicsItem * i : listCollision) {
                        ImageSetting *itemSetting = dynamic_cast<ImageSetting *>(i);
                        if (itemSetting) {
                            changeMoveMadPerso(nextActionMove, S);
                        }
                    }
                }
                delete nextActionMove;
            }
            else if (nextActionFight) {
                if (nextActionFight->getDefender()->getHurt(nextActionFight->getFighter()->getDamage())) {
                    NicePerso* perso = dynamic_cast<NicePerso*>(nextActionFight->getDefender());
                    if (perso) {
                        this->model->getlistNicePerso()->removeAll(perso);
                        this->view->scene->removeItem(this->view->scene->itemAt(QPointF(perso->getPosX()+20, perso->getPosY()+20),
                                                                                QTransform()));
                    }
                }
                S->removeFirstAction();
            }
            bool premier = true;

            for (NicePerso *M : *this->model->getlistNicePerso()) {
                if (distanceBetweenPoints(new QPointF(S->getPosX(), S->getPosY()), new QPointF(M->getPosX(), M->getPosY())) < 100) {
                    if (premier) {
                        ActionFight *action = new ActionFight(S, M);
                        S->addActionInFirst(action);
                        premier = false;
                    }
                }
            }
            premier = true;
        }
    }
}

void Controller::changeMoveMadPerso(ActionMove *action, MadPerso *S) {
    std::random_device rd;
    std::mt19937_64 gen(rd());
    std::uniform_int_distribution<unsigned long long> dis;

    S->removeAllActions();
    int alea2 = dis(gen) % 100;
    if (alea2 > 66) {
        S->moveTo(S->getPosX() + action->getDepX() + 20, S->getPosY() + (action->getDepY() * -1) + 20);
    } else if (alea2 > 33){
        S->moveTo(S->getPosX() + (action->getDepX() * -1) + 20, S->getPosY() + action->getDepY() + 20);
    } else {
        S->moveTo(S->getPosX() + (action->getDepX() * -1) + 20, S->getPosY() + (action->getDepY() * -1) + 20);
    }
}

void Controller::checkMadPersoFixed() {
    for (QPointF *point : *this->model->getlistSpotMadPersoFixed()) {
        MadPerso *perso = new MadPerso(point->x(), point->y(), 1, 50, 0);
        if (!this->containsMadPersoFixed(perso)) {
            this->model->addMadPersoFixed(perso);
            this->view->scene->addItem(perso->getImagePerso());
        }
    }
}

void Controller::checkMadPersoMovable() {
    if (this->model->getlistMadPersoMovable()->size() < this->model->getNbMaxMadPersoMovable()) {
        int *tabAlea = new int[this->model->getlistSpotMadPersoMovable()->size()];
        for (int i=0; i<this->model->getlistSpotMadPersoMovable()->size(); i++) {
            tabAlea[i]=i;
        }
        for (int i=0; i<this->model->getlistSpotMadPersoMovable()->size(); i++) {
            int nb = (rand() % (this->model->getlistSpotMadPersoMovable()->size()-1)) + 1;
            int tmp = tabAlea[i];
            tabAlea[i] = tabAlea[nb];
            tabAlea[nb] = tmp;
        }
        for (int i=0; i<(this->model->getNbMaxMadPersoMovable() - this->model->getlistMadPersoMovable()->size()); i++) {
            MadPerso *perso = new MadPerso(this->model->getlistSpotMadPersoMovable()->at(tabAlea[i])->x(),
                                           this->model->getlistSpotMadPersoMovable()->at(tabAlea[i])->y(), 2, 100, 1);
            this->model->addMadPersoMovable(perso);
            perso->moveTo(perso->getPosX() + 21, perso->getPosY() + 21);
            this->view->scene->addItem(perso->getImagePerso());
        }
    }
}

void Controller::checkResources() {
    for (int y=0; y<this->model->getlistSpotResourceItem()->size(); y++) {
        int *tabAlea = new int[this->model->getlistSpotResourceItem()->size()];
        for (int i=0; i<this->model->getlistSpotResourceItem()->size(); i++) {
            tabAlea[i]=i;
        }
        for (int i=0; i<this->model->getlistSpotMadPersoMovable()->size(); i++) {
            int nb = (rand() % (10-1)) + 1;
            int tmp = tabAlea[i];
            tabAlea[i] = tabAlea[nb];
            tabAlea[nb] = tmp;
        }
        QPointF *point = new QPointF(this->model->getlistSpotResourceItem()->at(y)->x(),
                                     this->model->getlistSpotResourceItem()->at(y)->y());
        if (this->view->scene->itemAt(point->x() + 15, point->y() + 15, QTransform()) == NULL) {
            if (tabAlea[y] > 9) {
                this->model->addResourceItem(new ResourceItem("Sarsaparilla", ((rand() % 3) + 1),
                                                              new ImageSetting(":/images/salsepareille"),point->x(), point->y()));
            } else if (tabAlea[y] > 6) {
                this->model->addResourceItem(new ResourceItem("Wheat", ((rand() % 3) + 1), new ImageSetting(":/images/ble"),
                                                                point->x(), point->y()));
            } else if (tabAlea[y] > 3) {
                this->model->addResourceItem(new ResourceItem("Acorn", ((rand() % 3) + 1), new ImageSetting(":/images/noisette"),
                                                                point->x(), point->y()));
            } else if (tabAlea[y] > 0) {
                this->model->addResourceItem(new ResourceItem("Berry", ((rand() % 3) + 1), new ImageSetting(":/images/baie"),
                                                                point->x(), point->y()));
            }
            this->view->scene->addItem(this->model->getlistResourceItem()->last()->getImageItem());
        }
    }
}

int Controller::distanceBetweenPoints(QPointF *p1, QPointF *p2) {
    return sqrt(pow((p1->x() - p2->x()), 2) + pow((p1->y() - p2->y()), 2));
}

QPointF *Controller::getPointDecale(QPointF *beginningPoint, QPointF *nextPoint) {
    QPointF *newPoint = new QPointF;
    double rayon = sqrt(pow((beginningPoint->x() - nextPoint->x()), 2) + pow((beginningPoint->y() - nextPoint->y()), 2));
    newPoint->setX(beginningPoint->x() + (rayon * sin(M_PI + (M_PI / 3))));
    newPoint->setY(beginningPoint->y() + (rayon * cos(M_PI + (M_PI / 3))));
    return newPoint;
}

void Controller::actionPerso(int x, int y, int nbS) {
    for (int i=0; i<this->model->getlistNicePerso()->size(); i++) {
        int a = x-(this->model->getlistNicePerso()->at(i)->getPosX());
        int b = y-(this->model->getlistNicePerso()->at(i)->getPosY());
        float distance = sqrt(pow(a,2)+pow(b,2));
        this->model->getlistNicePerso()->at(i)->setDistancePositionClicked(distance);
    }
    QList<NicePerso *> *listSorted = this->model->getlistNicePerso();
    for (int i=(listSorted->size()-1); i>0; i--) {
        for (int j=0; j<(i); j++) {
            if (listSorted->at(j+1)->getDistancePositionClicked() < listSorted->at(j)->getDistancePositionClicked()) {
                listSorted->swap(j+1,j);
            }
        }
    }
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

int Controller::getNumberFreePerso() {
    return this->model->getNumberFreePerso();
}

QList<NicePerso *> *Controller::getlistNicePerso() {
    QList<NicePerso *> *listSorted = this->model->getlistNicePerso();
    for (int i=(listSorted->size()-1); i>0; i--) {
        for (int j=0; j<(i); j++) {
            if ((listSorted->at(j+1)->getHpMax() - listSorted->at(j+1)->getHp()) >
                    (listSorted->at(j)->getHpMax() - listSorted->at(j)->getHp()) ) {
                listSorted->swap(j+1,j);
            }
        }
    }
    return listSorted;
}

void Controller::harvestWheat() {
    this->model->getWheatField()->harvest(this->model->getBagWheats());
}

void Controller::sellWheat(int nbWheat) {
    this->model->useWheat(nbWheat);
    this->model->addSarsaparilla(nbWheat * this->model->getCostWheat());
}

void Controller::farmerUp(int cout) {
    if (!this->model->getBagSarsaparillas()->removeResource(cout)) {
        this->view->displayMistakeMoney();
    } else {
        this->model->farmerUp(1);
        this->model->addPoints(50);
    }
}

void Controller::makeBread(int nbBread) {
    if (!this->model->getBagSarsaparillas()->removeResource(nbBread * this->getCostProductionBread())) {
        this->view->displayMistakeMoney();
    } else {
        this->model->useWheat(nbBread * 2);
        this->model->makeBread(nbBread);
        this->model->addPoints(1);
    }
}

void Controller::bakerUp(int cout) {
    if (!this->model->getBagSarsaparillas()->removeResource(cout)) {
        this->view->displayMistakeMoney();
    } else {
        this->model->bakerUp(1);
        this->model->addPoints(50);
    }
}

void Controller::creationNewSmurf(int cout) {

    if (!this->model->getBagSarsaparillas()->removeResource(cout)) {
        this->view->displayMistakeMoney();
    } else {
        QPointF *point = this->getFreeSpawnNicePerso();
        NicePerso *perso = new NicePerso(point->x(), point->y(), this->model->getHpHefty(), this->model->getHpHefty(),
                                         this->model->getDamageHefty(), this->model->getSpeedHefty());
        this->view->addNormalPerso(perso);
        //connect(perso->getImagePerso(), SIGNAL(clicked()), perso, SLOT(actionS()));
        this->model->addNewSmurf(perso);
    }
}

void Controller::heftyUp(int cout) {
    if (!this->model->getBagSarsaparillas()->removeResource(cout)) {
        this->view->displayMistakeMoney();
    } else {
        this->model->heftyUp(1);
        this->model->addPoints(50);
    }
}

QPointF *Controller::getFreeSpawnNicePerso() {

    int *tabAlea = new int[this->model->getlistSpawnNicePerso()->size()];
    for (int i=0; i<this->model->getlistSpawnNicePerso()->size(); i++) {
        tabAlea[i]=i;
    }
    for (int i=0; i<this->model->getlistSpawnNicePerso()->size(); i++) {
        int nb = (rand() % (this->model->getlistSpawnNicePerso()->size()-1)) + 1;
        int tmp = tabAlea[i];
        tabAlea[i] = tabAlea[nb];
        tabAlea[nb] = tmp;
    }
    for (int y=0; y<this->model->getlistSpawnNicePerso()->size(); y++) {

        QPointF *point = this->model->getlistSpawnNicePerso()->at(tabAlea[y]);
        QList<NicePerso *> *listPerso = this->model->getlistNicePerso();
        int i=0;

        while ((i < listPerso->size())
               && ((listPerso->at(i)->getPosX() > (point->x() + 5) || listPerso->at(i)->getPosX() < (point->x() - 5))
               || (listPerso->at(i)->getPosY() > (point->y() + 5) || listPerso->at(i)->getPosY() < (point->y() - 5)))) {
            i++;
        }
        if (i==listPerso->size()) {
            i = 0;
            QList<MadPerso *> *listPerso2 = this->model->getlistMadPersoMovable();
            while ((i < listPerso2->size())
                   && ((listPerso2->at(i)->getPosX() > (point->x() + 5) || listPerso2->at(i)->getPosX() < (point->x() - 5))
                   || (listPerso2->at(i)->getPosY() > (point->y() + 5) || listPerso2->at(i)->getPosY() < (point->y() - 5)))) {
                i++;
            }
            if (i==listPerso2->size()) {
                return point;
            }
        }
    }
    return this->model->getlistSpawnNicePerso()->at((rand() % (this->model->getlistSpawnNicePerso()->size()-1)) + 1);
}

bool Controller::containsMadPersoFixed(MadPerso *perso) {

    for (MadPerso *p : *this->model->getlistMadPersoFixed()) {
        if (perso->getPosX() == p->getPosX() && perso->getPosY() == p->getPosY()) {
            return true;
        }
    }
    return false;
}

void Controller::fillListResource() {
    this->model->addListSpotResource(new QPointF(100,600));
    this->model->addListSpotResource(new QPointF(70,300));
    this->model->addListSpotResource(new QPointF(450,450));
    this->model->addListSpotResource(new QPointF(250,1000));
    this->model->addListSpotResource(new QPointF(100,1450));
    this->model->addListSpotResource(new QPointF(700,900));
    this->model->addListSpotResource(new QPointF(725,1900));
    this->model->addListSpotResource(new QPointF(1450,1850));
    this->model->addListSpotResource(new QPointF(1700,1750));
    this->model->addListSpotResource(new QPointF(2100,1950));
    this->model->addListSpotResource(new QPointF(2950,1950));
    this->model->addListSpotResource(new QPointF(2700,1800));
    this->model->addListSpotResource(new QPointF(2900,1550));
    this->model->addListSpotResource(new QPointF(2300,1475));
    this->model->addListSpotResource(new QPointF(2000,1500));
    this->model->addListSpotResource(new QPointF(2000,1325));
    this->model->addListSpotResource(new QPointF(1400,1325));
    this->model->addListSpotResource(new QPointF(800,1275));
    this->model->addListSpotResource(new QPointF(2500,1050));
    this->model->addListSpotResource(new QPointF(2950,950));
    this->model->addListSpotResource(new QPointF(2350,825));
    this->model->addListSpotResource(new QPointF(1850,850));
    this->model->addListSpotResource(new QPointF(1450,550));
    this->model->addListSpotResource(new QPointF(950,625));
    this->model->addListSpotResource(new QPointF(800,400));
    this->model->addListSpotResource(new QPointF(1150,300));
    this->model->addListSpotResource(new QPointF(1200,50));
    this->model->addListSpotResource(new QPointF(1850,10));
    this->model->addListSpotResource(new QPointF(2450,50));
    this->model->addListSpotResource(new QPointF(2300,350));
    this->model->addListSpotResource(new QPointF(2925,25));
    this->model->addListSpotResource(new QPointF(2350,550));
}

void Controller::fillListSpawnNicePerso() {
    this->model->addListSpawnNicePerso(new QPointF(880,740));
    this->model->addListSpawnNicePerso(new QPointF(840,780));
    this->model->addListSpawnNicePerso(new QPointF(810,840));
    this->model->addListSpawnNicePerso(new QPointF(785,895));
    this->model->addListSpawnNicePerso(new QPointF(815,950));
    this->model->addListSpawnNicePerso(new QPointF(850,1000));
    this->model->addListSpawnNicePerso(new QPointF(870,1050));
    this->model->addListSpawnNicePerso(new QPointF(920,1100));
    this->model->addListSpawnNicePerso(new QPointF(965,1135));
    this->model->addListSpawnNicePerso(new QPointF(1030,1175));
    this->model->addListSpawnNicePerso(new QPointF(1100,1170));
    this->model->addListSpawnNicePerso(new QPointF(1170,1150));
    this->model->addListSpawnNicePerso(new QPointF(1240,1150));
    this->model->addListSpawnNicePerso(new QPointF(1300,1160));
    this->model->addListSpawnNicePerso(new QPointF(1360,1150));
    this->model->addListSpawnNicePerso(new QPointF(1430,1160));
    this->model->addListSpawnNicePerso(new QPointF(1490,1140));
    this->model->addListSpawnNicePerso(new QPointF(1540,1090));
    this->model->addListSpawnNicePerso(new QPointF(1610,1070));
    this->model->addListSpawnNicePerso(new QPointF(1670,1050));
    this->model->addListSpawnNicePerso(new QPointF(1720,1010));
    this->model->addListSpawnNicePerso(new QPointF(1740,960));
    this->model->addListSpawnNicePerso(new QPointF(1750,900));
    this->model->addListSpawnNicePerso(new QPointF(1740,830));
    this->model->addListSpawnNicePerso(new QPointF(1720,770));
    this->model->addListSpawnNicePerso(new QPointF(1700,720));
    this->model->addListSpawnNicePerso(new QPointF(1660,660));
    this->model->addListSpawnNicePerso(new QPointF(1600,640));
    this->model->addListSpawnNicePerso(new QPointF(1530,620));
    this->model->addListSpawnNicePerso(new QPointF(1460,600));
    this->model->addListSpawnNicePerso(new QPointF(1400,590));
    this->model->addListSpawnNicePerso(new QPointF(1330,600));
    this->model->addListSpawnNicePerso(new QPointF(1255,610));
    this->model->addListSpawnNicePerso(new QPointF(1190,620));
    this->model->addListSpawnNicePerso(new QPointF(1120,600));
    this->model->addListSpawnNicePerso(new QPointF(1050,630));
    this->model->addListSpawnNicePerso(new QPointF(990,665));
    this->model->addListSpawnNicePerso(new QPointF(920,700));
    this->model->addListSpawnNicePerso(new QPointF(880,740));
}

void Controller::fillListSpotMadPersoFixed() {
    this->model->addListSpotMadPersoFixed(new QPointF(300, 50));
    this->model->addListSpotMadPersoFixed(new QPointF(650, 300));
    this->model->addListSpotMadPersoFixed(new QPointF(950, 250));
    this->model->addListSpotMadPersoFixed(new QPointF(1450, 250));
    this->model->addListSpotMadPersoFixed(new QPointF(2150, 25));
    this->model->addListSpotMadPersoFixed(new QPointF(2140, 250));
    this->model->addListSpotMadPersoFixed(new QPointF(2500, 280));
    this->model->addListSpotMadPersoFixed(new QPointF(2850, 300));
    this->model->addListSpotMadPersoFixed(new QPointF(300, 1100));
    this->model->addListSpotMadPersoFixed(new QPointF(625, 1300));
    this->model->addListSpotMadPersoFixed(new QPointF(300, 1600));
    this->model->addListSpotMadPersoFixed(new QPointF(225, 1900));
    this->model->addListSpotMadPersoFixed(new QPointF(900, 1625));
    this->model->addListSpotMadPersoFixed(new QPointF(1500, 1650));
    this->model->addListSpotMadPersoFixed(new QPointF(1700, 1300));
    this->model->addListSpotMadPersoFixed(new QPointF(2700, 625));
    this->model->addListSpotMadPersoFixed(new QPointF(2650, 875));
    this->model->addListSpotMadPersoFixed(new QPointF(2175, 1150));
    this->model->addListSpotMadPersoFixed(new QPointF(2650, 1200));
    this->model->addListSpotMadPersoFixed(new QPointF(2650, 1475));
}

void Controller::fillListSpotMadPersoMovable() {
    this->model->addListSpotMadPersoMovable(new QPointF(270, 470));
    this->model->addListSpotMadPersoMovable(new QPointF(100, 900));
    this->model->addListSpotMadPersoMovable(new QPointF(700, 1600));
    this->model->addListSpotMadPersoMovable(new QPointF(1950, 1800));
    this->model->addListSpotMadPersoMovable(new QPointF(2800, 1700));
    this->model->addListSpotMadPersoMovable(new QPointF(2800, 1050));
    this->model->addListSpotMadPersoMovable(new QPointF(2400, 620));
    this->model->addListSpotMadPersoMovable(new QPointF(1800, 350));
}

void Controller::fillListAdvicePapaSmurf() {
    this->model->addMessageListAdvicePapaSmurf(tr("Je veille chaque jour à ce que \nmes petits Schtroumpfs ne \nmanquent de rien !"));
    this->model->addMessageListAdvicePapaSmurf(tr("Aller en foret te permettra de \ntrouver de la nouriture \npour le village."));
    this->model->addMessageListAdvicePapaSmurf(tr("Le blé permet au Schtroumpf \nBoulanger de faire du pain."));
    this->model->addMessageListAdvicePapaSmurf(tr("La salsepareille est un élément \nessentiel pour les Schtroumpfs."));
    this->model->addMessageListAdvicePapaSmurf(tr("Prend garde aux \nSchtroumpfs noirs !"));
    this->model->addMessageListAdvicePapaSmurf(tr("Prend garde à la réserve \nde nourriture, l'hiver \napproche à grand schtroumpf."));
    this->model->addMessageListAdvicePapaSmurf(tr("Clique sur la maison du \nSchtroumpf Paysan \npour récolter du blé."));
    this->model->addMessageListAdvicePapaSmurf(tr("Clique sur la maison du \nSchtroumpf Boulanger \npour fabriquer le pain."));
    this->model->addMessageListAdvicePapaSmurf(tr("Le Schtroumpf Costaud t'aide \nà améliorer les Schtroumpfs."));
    this->model->addMessageListAdvicePapaSmurf(tr("Docteur Schtroumpf va soigner \nles Schtroumpfs grace à la nourriture : "
                                                  "\n\t1 pain = ") + QString::number(this->model->getBagBreads()->getHealth()) +
                                               tr(" PV \n\t1 baie = ") + QString::number(this->model->getBagBerries()->getHealth()) +
                                               tr(" PV \n\t1 gland = ") + QString::number(this->model->getBagAcorns()->getHealth()) +
                                               tr(" PV."));
    this->model->addMessageListAdvicePapaSmurf(tr("La maison souche est la réserve. \nClique dessus et elle t'indiquera \n"
                                                  "ce que tu possèdes."));
    this->model->addMessageListAdvicePapaSmurf(tr("Schtroumpf à Lunettes, \noù en sont les Schtroumpfs ?"));
}

void Controller::fillListAdviceSmurfette() {
    this->model->addMessageListAdviceSmurfette(tr("Schtroumpf journée pour \nune promenade !"));
    this->model->addMessageListAdviceSmurfette(tr("Schtroumpfera bien qui \nSchtroumpfera le dernier !"));
    this->model->addMessageListAdviceSmurfette(tr("Le Schtroumpf Bricoleur sait \ntoujours comment nous aider."));
    this->model->addMessageListAdviceSmurfette(tr("\"Comme le dit toujours \nle Grand Schtroumpf...\", \n"
                                                  "Pff il est schtroumpfement pénible \nle Schtroumpf à Lunettes..."));
    this->model->addMessageListAdviceSmurfette(tr("Ah non, Schtroumpf à Lunettes... \nNe recommence pas avec tes \n"
                                                  "réflexions schtroumpfistes !"));
    this->model->addMessageListAdviceSmurfette(tr("Waouh! Qu'il est fort\nle Schtroumpf Costaud !"));
    this->model->addMessageListAdviceSmurfette(tr("Des noix ! Toujours des noix ! \nJe me demande ce qu’il peut \nbien schtroumpfer \n"
                                                  "avec toutes ces noix ?..."));
    this->model->addMessageListAdviceSmurfette(tr("Schtroumpf Grognon, tu ne veux \npas schtroumpfer à la balle, \n"
                                                  "tu ne veux pas schtroumpfer du \ngâteau ni de la musique ! \nTu n’aimes donc rien ?"));
    this->model->addMessageListAdviceSmurfette(tr("Schtroumpfs Boulanger, \nSchtroumpf Patissier, \nvous mettez du soleil dans \n"
                                                  "le coeur des Schtroumpfs !"));
    this->model->addMessageListAdviceSmurfette(tr("Le chemin du village est un \nsecret bien schtroumpfé ! \nGargamel ne pourra pas \n"
                                                  "nous trouver!"));
}

QGraphicsTextItem *Controller::getMessagePapaSmurf() {
    int MIN = 0;
    int MAX = this->model->getlistAdvicePapaSmurf()->size()-1;
    int random = (rand() % (MAX - MIN + 1)) + MIN;
    QGraphicsTextItem *texteItem = new QGraphicsTextItem(this->model->getMessagePapaSmurf(random));
    texteItem->setPos(this->getVillagePosX() + 155, this->getVillagePosY() - 80);
    return texteItem;
}

QGraphicsTextItem *Controller::getMessageSmurfette() {
    int MIN = 0;
    qDebug() << "size : " << QString::number(this->model->getlistAdviceSmurfette()->size());
    int MAX = this->model->getlistAdviceSmurfette()->size()-1;
    int random = (rand() % (MAX - MIN + 1)) + MIN;
    QGraphicsTextItem *texteItem = new QGraphicsTextItem(this->model->getMessageSmurfette(random));
    texteItem->setPos(this->getVillagePosX() + 200, this->getVillagePosY() - 110);
    return texteItem;
}

QGraphicsTextItem *Controller::getMessageBrainy() {
    QString texte = "";
    texte += tr("    Schtroumpf Paysan: niveau ") + QString::number(this->getLevelFarmer());
    texte += tr("\nPrix de revente du blé : ") + QString::number(this->getCostWheat());
    texte += tr("\nTaille d'un champs : ") + QString::number(this->getSizeFields());
    texte += tr("\nCapacité d'un champs : ") + QString::number(this->getCapacityFields());
    texte += tr("\n\n    Schtroumpf Boulanger : niveau ") + QString::number(this->getLevelBaker());
    texte += tr("\nPour production de pain : ") + QString::number(this->getResourceProductionBaker());
    texte += tr("\nCout de production du pain : ") + QString::number(this->getCostProductionBread());
    texte += tr("\n\n    Schtroumpf Costaud : niveau ") + QString::number(this->getLevelHefty());
    texte += tr("\nVitesse d'un nouveau Schtroumpf : ") + QString::number(this->getSpeedS());
    texte += tr("\nDegats d'un nouveau Schtroumpf : ") + QString::number(this->getDamageS());
    texte += tr("\nPV d'un nouveau Schtroumpf : ") + QString::number(this->getHpS());
    QGraphicsTextItem *texteItem = new QGraphicsTextItem(texte);
    texteItem->setPos(this->getVillagePosX() - 40, this->getVillagePosY() - 205);
    return texteItem;
}

Image *Controller::getImageBubblePapaSmurf() {
    Image *imageBubble = this->model->getImageBubblePapaSmurf();
    imageBubble->setPos(this->getVillagePosX() + 80, this->getVillagePosY() - 190);
    return imageBubble;
}

Image *Controller::getImageBubbleSmurfette() {
    Image *imageBubble = this->model->getImageBubbleSmurfette();
    imageBubble->setPos(this->getVillagePosX() + 125, this->getVillagePosY() - 210);
    return imageBubble;
}

Image *Controller::getImageBubbleBrainy() {
    Image *imageBubble = this->model->getImageBubbleBrainy();
    imageBubble->setPos(this->getVillagePosX() - 75, this->getVillagePosY() - 245);
    return imageBubble;
}

Image *Controller::getImagePapaSmurf() {
     Image *imagePapaSmurf = this->model->getImagePapaSmurf();
     imagePapaSmurf->setPos(this->getVillagePosX() + 370, this->getVillagePosY() - 180);
     return imagePapaSmurf;
}

Image *Controller::getImageSmurfette() {
    Image *imageSmurfette = this->model->getImageSmurfette();
    imageSmurfette->setPos(this->getVillagePosX() + 370, this->getVillagePosY() - 180);
    return imageSmurfette;
}

Image *Controller::getImageBrainy() {
    Image *imageBrainy = this->model->getImageBrainy();
    imageBrainy->setPos(this->getVillagePosX() + 200, this->getVillagePosY() - 175);
    return imageBrainy;
}

int Controller::getTreatment(int i) {
    return this->getlistNicePerso()->at(i)->getHpMax() - this->getlistNicePerso()->at(i)->getHp();
}

void Controller::treat(int i, int nbBreads, int nbBerries, int nbAcorns) {
    int hpGettingBack = (getHealthBread() * nbBreads) + (getHealthBerries() * nbBerries) + (getHealthAcorn() * nbAcorns);
    if (hpGettingBack <= getTreatment(i)) {
        this->getlistNicePerso()->at(i)->heal(hpGettingBack);
    } else {
        this->getlistNicePerso()->at(i)->heal(getTreatment(i));
    }
    this->model->getBagBreads()->removeResource(nbBreads);
    this->model->getBagBerries()->removeResource(nbBerries);
    this->model->getBagAcorns()->removeResource(nbAcorns);
}
