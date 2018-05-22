#include "view.h"
#include "ui_view.h"
#include "controller.h"
#include "model.h"
#include "autre.h"
#include "decor.h"

#include <QTableWidget>
#include <QMessageBox>
#include <QDialog>
#include <QLineEdit>
#include <QTextEdit>
#include <QPushButton>
#include <QLabel>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <QMovie>
#include <QGraphicsProxyWidget>
#include <QPoint>
#include <QScrollBar>
#include <QGroupBox>
#include <QRadioButton>
#include <QSpinBox>
#include <QCheckBox>
#include <QTimer>
#include <QGraphicsRectItem>
#include <QHBoxLayout>
#include <QDateTime>
#include <QSettings>

View::View(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::View)
{
    ui->setupUi(this);


    for (int i=0; i<11; i++) {
        list_movies.append(":/images/movie"+QString::number(i));
    }

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(movie()));
    timer->start(5000);

    scene = new QGraphicsScene();
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setMinimumSize(600,550);
    setWindowTitle(tr("Schtroumpf-Hill : Le jeu"));
    setWindowIcon(QIcon(":/images/smurfHead"));
    scene->addText(QString(tr("Schtroumpf-Hill : Le jeu")), QFont("Monotype Corsiva", 20));

    QFile file("sauvegarde.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::about(this, tr("Erreur"), tr("Impossible de trouver le fichier de sauvegarde"));
    }
    else {
        QTextStream flux(&file);
        if (flux.readAll() == 0) {
            ui->pushButton_2->setEnabled(false);
        }
        else {
            ui->pushButton_2->setEnabled(true);
        }
    }
}

View::~View() {
    delete ui;
}

void View::movie() {
    scene->clear();
    if (cptMovie == 11)
        cptMovie = 0;
    QLabel *gif_anim = new QLabel();
    QMovie *movie = new QMovie(list_movies[cptMovie]);
    gif_anim->setMovie(movie);
    movie->start();
    scene->addWidget(gif_anim);

    cptMovie++;
}

void View::music() {

    generique = !generique;
    if (generique == true) {
        this->player = new QMediaPlayer;
        this->player->setMedia(QUrl::fromLocalFile("/Users/Alexia/Documents/ihm/images/generique.mp3"));
        this->player->setVolume(50);
        this->player->play();
    }
    else this->player->stop();
}

void View::on_pushButton_clicked() { // Bouton Jouer
    timer->disconnect();
    frontMessage = true;
    this->controller->startNewGame();
}

void View::on_pushButton_2_clicked() { // Bouton Reprendre
    timer->disconnect();
    frontMessage = false;
    this->controller->loadSave();
}

void View::installScene() {

    this->menuDisplay = false;
    scene->clear(); // Supprime le chargement
    menu();

    this->setCentralWidget(ui->graphicsView);
    scene->setSceneRect(0,0,3000,2000); // make the scene 800x600 instead of infinity by infinity (default)
    // make the newly created scene the scene to visualize (since Game is a QGraphicsView Widget,
    // it can be used to visualize scenes)
    ui->graphicsView->setBackgroundBrush(QBrush(QImage(":/images/fond_herbe")));
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setMinimumSize(0,0);
    //QObject::connect(scene, SIGNAL(clicked()), this, SLOT(test));
}

void View::menu() {
    QMenu *menu = this->menuBar()->addMenu(tr("Fichier"));

    QAction *save = new QAction(tr("Sauver"), this);
    save = menu->addAction(tr("Sauver"));
    save->setShortcut(QKeySequence("Ctrl+S"));
    save->setToolTip(tr("Sauvegarder la partie"));
    connect(save, SIGNAL(triggered()), this, SLOT(save()));

    QAction *saveQuit = new QAction(tr("Sauver et Quitter"), this);
    saveQuit = menu->addAction(tr("Sauver et Quitter"));
    saveQuit->setToolTip(tr("Sauvegarder la partie et quitter le jeu"));
    connect(saveQuit, SIGNAL(triggered()), this, SLOT(saveQuit()));

    QAction *quit = new QAction(tr("Quitter"), this);
    quit = menu->addAction(tr("Quitter"));
    quit->setShortcut(QKeySequence("Ctrl+Q"));
    quit->setToolTip(tr("Quitter le jeu"));
    connect(quit, SIGNAL(triggered()), this, SLOT(close()));

    menu = this->menuBar()->addMenu(tr("Action"));

    QAction *musician = new QAction(tr("Musicien"), this);
    musician = menu->addAction(tr("Schtroumpf Musicien"));
    musician->setIcon(QIcon(":/images/musique"));
    musician->setShortcut(QKeySequence("Ctrl+M"));
    musician->setToolTip(tr("Action du Schtroumpf Musicien"));
    connect(musician, SIGNAL(triggered()), this, SLOT(music()));

    QAction *farmer = new QAction(tr("Paysan"), this);
    farmer = menu->addAction(tr("Schtroumpf Paysan"));
    farmer->setIcon(QIcon(":/images/ble"));
    farmer->setShortcut(QKeySequence("Ctrl+P"));
    farmer->setToolTip(tr("Action du Schtroumpf Paysan"));
    connect(farmer, SIGNAL(triggered()), this, SLOT(displayActionFarmer()));

    QAction *baker = new QAction(tr("Boulanger"), this);
    baker = menu->addAction(tr("Schtroumpf Boulanger"));
    baker->setIcon(QIcon(":/images/pain"));
    baker->setShortcut(QKeySequence("Ctrl+B"));
    baker->setToolTip(tr("Action du Schtroumpf Boulanger"));
    connect(baker, SIGNAL(triggered()), this, SLOT(displayActionBaker()));

    QAction *hefty = new QAction(tr("Costaud"), this);
    hefty = menu->addAction(tr("Schtroumpf Costaud"));
    hefty->setIcon(QIcon(":/images/smurfHead"));
    hefty->setShortcut(QKeySequence("Ctrl+C"));
    hefty->setToolTip(tr("Action du Schtroumpf Costaud"));
    connect(hefty, SIGNAL(triggered()), this, SLOT(displayActionHefty()));

    QAction *doctor = new QAction(tr("Docteur"), this);
    doctor = menu->addAction(tr("Docteur Schtroumpf"));
    doctor->setIcon(QIcon(":/images/croixRouge"));
    doctor->setShortcut(QKeySequence("Ctrl+D"));
    doctor->setToolTip(tr("Action du Docteur Schtroumpf"));
    connect(doctor, SIGNAL(triggered()), this, SLOT(displayActionDoctor()));

    QAction *inventaire = new QAction(tr("Inventaire"), this);
    inventaire = menu->addAction(tr("Inventaire"));
    inventaire->setIcon(QIcon(":/images/sac"));
    inventaire->setShortcut(QKeySequence("Ctrl+I"));
    inventaire->setToolTip(tr("Contenu de l'inventaire"));
    connect(inventaire, SIGNAL(triggered()), this, SLOT(inventoryContents()));

    menu = this->menuBar()->addMenu(tr("Langage"));

    QAction* french=new QAction(tr("Francais"), this);
    menu->addAction(french);
    french->setCheckable(true);
    connect(french, SIGNAL(triggered()), this, SLOT(SwitchLanguage()));

    QAction* english=new QAction(tr("Anglais"), this);
    menu->addAction(english);
    english->setCheckable(true);
    connect(english, SIGNAL(triggered()), this, SLOT(SwitchLanguage()));

    QActionGroup *group= new QActionGroup(this);
    group->addAction(french);
    group->addAction(english);
    group->setExclusive(true);

    //Vérifie le langage pour le changement
    if (tr("Francais") == "Francais")
        french->setChecked(true);
    else
        english->setChecked(true);
}

void View::SwitchLanguage()
{
    QAction *a = qobject_cast<QAction *>(sender());
    QSettings s("ESME", "langage");
    if (a->text() == "francais")
        s.setValue("lang", "fr_FR");
    else
        s.setValue("lang", "en_EN");
    QMessageBox::information(this, tr("Langage"), tr("Le changement s'effectuera après le redémarrage de l'application."));
}

void View::addVillage(Village *village) {

    this->scene->addItem(village->getTree1());
    this->scene->addItem(village->getTree2());
    this->scene->addItem(village->getTree3());
    this->scene->addItem(village->getTree4());
    this->scene->addItem(village->getTree5());
    this->scene->addItem(village->getTree6());
    this->scene->addItem(village->getTree7());
    this->scene->addItem(village->getTree8());
    this->scene->addItem(village->getTree9());
    this->scene->addItem(village->getTree10());
    this->scene->addItem(village->getTree11());
    this->scene->addItem(village->getTree12());
    this->scene->addItem(village->getTree13());
    this->scene->addItem(village->getTree14());
    this->scene->addItem(village->getTree15());

    this->scene->addItem(village->getHouse7());
    this->scene->addItem(village->getHouse5());
    this->scene->addItem(village->getHouse1());
    this->scene->addItem(village->getHouse2());
    this->scene->addItem(village->getBush3());
    this->scene->addItem(village->getBush4());
    this->scene->addItem(village->getHouse3());
    this->scene->addItem(village->getHouse4());
    this->scene->addItem(village->getHouseBaker());
    this->scene->addItem(village->getMill());
    this->scene->addItem(village->getHouse8());
    this->scene->addItem(village->getBush9());
    this->scene->addItem(village->getHouse6());
    this->scene->addItem(village->getBush6());
    this->scene->addItem(village->getBush7());
    this->scene->addItem(village->getBush8());
    this->scene->addItem(village->getHouse9());
    this->scene->addItem(village->getHouseSmurfette());
    this->scene->addItem(village->getHouseHefty());
    this->scene->addItem(village->getHouseMusician());
    this->scene->addItem(village->getBush1());
    this->scene->addItem(village->getBush2());
    this->scene->addItem(village->getHouseFarmer());
    this->scene->addItem(village->getPapaSmurf());
    this->scene->addItem(village->getBrainy());
    this->scene->addItem(village->getDoctor());
    this->scene->addItem(village->getWell());
    this->scene->addItem(village->getInventory());
    this->scene->addItem(village->getHouse10());
    this->scene->addItem(village->getHouse11());
    this->scene->addItem(village->getHouse12());

    this->scene->addItem(village->getBush5());
}

void View::addForest1(Forest1 *forest) {
    this->scene->addItem(forest->getBushBerries1());
    this->scene->addItem(forest->getBushBerries2());

    this->scene->addItem(forest->getTree16());
    this->scene->addItem(forest->getTree14());
    this->scene->addItem(forest->getTree15());
    this->scene->addItem(forest->getTree8());
    this->scene->addItem(forest->getTree5());
    this->scene->addItem(forest->getTree2());
    this->scene->addItem(forest->getTree6());
    this->scene->addItem(forest->getTree17());
    this->scene->addItem(forest->getTree1());
    this->scene->addItem(forest->getTree9());
    this->scene->addItem(forest->getTree4());
    this->scene->addItem(forest->getTree3());
    this->scene->addItem(forest->getTree7());
    this->scene->addItem(forest->getTree10());
    this->scene->addItem(forest->getTree11());
    this->scene->addItem(forest->getTree12());
    this->scene->addItem(forest->getTree13());

    this->scene->addItem(forest->getBush1());
    this->scene->addItem(forest->getBush2());

}

void View::addForest2(Forest2 *forest) {
    this->scene->addItem(forest->getTree01());
    this->scene->addItem(forest->getTree02());
    this->scene->addItem(forest->getTree03());
    this->scene->addItem(forest->getTree04());
    this->scene->addItem(forest->getTree05());
    this->scene->addItem(forest->getTree06());
    this->scene->addItem(forest->getTree1());
    this->scene->addItem(forest->getBush3());

    this->scene->addItem(forest->getTree2());
    this->scene->addItem(forest->getTree3());
    this->scene->addItem(forest->getTree07());
    this->scene->addItem(forest->getTree4());
    this->scene->addItem(forest->getTree5());
    this->scene->addItem(forest->getBushBerries1());
    this->scene->addItem(forest->getTree6());
    this->scene->addItem(forest->getTree7());
    this->scene->addItem(forest->getTree8());
    this->scene->addItem(forest->getTree9());
    this->scene->addItem(forest->getTree10());
    this->scene->addItem(forest->getTree11());
    this->scene->addItem(forest->getTree12());
    this->scene->addItem(forest->getTree13());
    this->scene->addItem(forest->getBush1());
    this->scene->addItem(forest->getTree14());
    this->scene->addItem(forest->getBush2());

}

void View::addForest3(Forest3 *forest) {
    this->scene->addItem(forest->getTree01());
    this->scene->addItem(forest->getBushBerries3());
    this->scene->addItem(forest->getTree02());
    this->scene->addItem(forest->getBushBerries1());
    this->scene->addItem(forest->getTree1());
    this->scene->addItem(forest->getTree2());
    this->scene->addItem(forest->getTree3());
    this->scene->addItem(forest->getTree4());
    this->scene->addItem(forest->getTree5());
    this->scene->addItem(forest->getTree6());
    this->scene->addItem(forest->getTree7());
    this->scene->addItem(forest->getTree8());
    this->scene->addItem(forest->getTree9());

    this->scene->addItem(forest->getTree10());
    this->scene->addItem(forest->getBushBerries2());

    this->scene->addItem(forest->getTree11());
    this->scene->addItem(forest->getTree12());
    this->scene->addItem(forest->getTree13());
    this->scene->addItem(forest->getSouche1());

    this->scene->addItem(forest->getTree14());
    this->scene->addItem(forest->getBush1());
    this->scene->addItem(forest->getBush2());
    this->scene->addItem(forest->getTree15());

    this->scene->addItem(forest->getTree16());
    this->scene->addItem(forest->getTree17());
}

void View::addForest4(Forest4 *forest) {
    this->scene->addItem(forest->getTree1());
    this->scene->addItem(forest->getTree2());
    this->scene->addItem(forest->getTree3());
    this->scene->addItem(forest->getTree4());
    this->scene->addItem(forest->getTree5());
    this->scene->addItem(forest->getTree6());
    this->scene->addItem(forest->getBush1());
    this->scene->addItem(forest->getBush2());
    this->scene->addItem(forest->getTree7());
    this->scene->addItem(forest->getTree8());
    this->scene->addItem(forest->getTree9());
    this->scene->addItem(forest->getTree10());
    this->scene->addItem(forest->getBush3());

    this->scene->addItem(forest->getTree11());
    this->scene->addItem(forest->getBush6());
    this->scene->addItem(forest->getBush7());
    this->scene->addItem(forest->getTree12());
    this->scene->addItem(forest->getTree13());
    this->scene->addItem(forest->getBush4());
    this->scene->addItem(forest->getBush5());
    this->scene->addItem(forest->getTree14());
    this->scene->addItem(forest->getTree15());
    this->scene->addItem(forest->getBush8());
    this->scene->addItem(forest->getTree16());
    this->scene->addItem(forest->getTree17());
    this->scene->addItem(forest->getTree18());
    this->scene->addItem(forest->getTree19());
    this->scene->addItem(forest->getTree20());

    this->scene->addItem(forest->getTree21());
    this->scene->addItem(forest->getBush9());
    this->scene->addItem(forest->getTree22());
    this->scene->addItem(forest->getTree23());
    this->scene->addItem(forest->getTree24());
    this->scene->addItem(forest->getTree25());
}

void View::addForest5(Forest5 *forest) {
    this->scene->addItem(forest->getTree1());
    this->scene->addItem(forest->getTree2());
    this->scene->addItem(forest->getTree3());
    this->scene->addItem(forest->getTree4());
    this->scene->addItem(forest->getTree5());
    this->scene->addItem(forest->getTree6());
    this->scene->addItem(forest->getBushBerries1());
    this->scene->addItem(forest->getTree7());
    this->scene->addItem(forest->getTree8());
    this->scene->addItem(forest->getTree9());
    this->scene->addItem(forest->getTree10());
    this->scene->addItem(forest->getTree11());
    this->scene->addItem(forest->getTree12());
    this->scene->addItem(forest->getTree13());
    this->scene->addItem(forest->getTree14());
    this->scene->addItem(forest->getTree15());

    this->scene->addItem(forest->getTree16());
    this->scene->addItem(forest->getTree17());
    this->scene->addItem(forest->getTree18());
    this->scene->addItem(forest->getTree19());
    this->scene->addItem(forest->getTree20());
    this->scene->addItem(forest->getTree21());
    this->scene->addItem(forest->getTree22());
    this->scene->addItem(forest->getTree23());
    this->scene->addItem(forest->getTree24());
    this->scene->addItem(forest->getTree25());
    this->scene->addItem(forest->getBushBerries2());
    this->scene->addItem(forest->getTree26());
    this->scene->addItem(forest->getTree27());
    this->scene->addItem(forest->getTree28());
    this->scene->addItem(forest->getTree29());
    this->scene->addItem(forest->getTree30());
}

void View::addForest6(Forest6 *forest) {
    this->scene->addItem(forest->getTree1());
    this->scene->addItem(forest->getTree2());
    this->scene->addItem(forest->getTree3());
    this->scene->addItem(forest->getBush1());
    this->scene->addItem(forest->getTree4());
    this->scene->addItem(forest->getTree5());
    this->scene->addItem(forest->getTree6());
    this->scene->addItem(forest->getBushBerries1());
    this->scene->addItem(forest->getTree7());
    this->scene->addItem(forest->getTree8());
    this->scene->addItem(forest->getTree9());
    this->scene->addItem(forest->getTree10());
    this->scene->addItem(forest->getTree11());
    this->scene->addItem(forest->getTree12());
    this->scene->addItem(forest->getTree13());
    this->scene->addItem(forest->getTree14());
    this->scene->addItem(forest->getTree15());
    this->scene->addItem(forest->getTree16());
    this->scene->addItem(forest->getTree17());
    this->scene->addItem(forest->getTree18());
    this->scene->addItem(forest->getTree19());
    this->scene->addItem(forest->getTree20());
    this->scene->addItem(forest->getTree21());
    this->scene->addItem(forest->getTree22());
    this->scene->addItem(forest->getTree23());
    this->scene->addItem(forest->getTree24());
    this->scene->addItem(forest->getTree25());
    this->scene->addItem(forest->getTree26());
}

void View::addForest7(Forest7 *forest) {
    this->scene->addItem(forest->getTree1());
    this->scene->addItem(forest->getTree2());
    this->scene->addItem(forest->getTree3());
    this->scene->addItem(forest->getTree4());
    this->scene->addItem(forest->getTree5());
    this->scene->addItem(forest->getTree6());
    this->scene->addItem(forest->getTree7());
    this->scene->addItem(forest->getTree8());
    this->scene->addItem(forest->getBushBerries1());
    this->scene->addItem(forest->getTree9());
    this->scene->addItem(forest->getBush1());
    this->scene->addItem(forest->getBush2());
    this->scene->addItem(forest->getBushBerries2());
    this->scene->addItem(forest->getTree10());
    this->scene->addItem(forest->getTree11());
    this->scene->addItem(forest->getTree12());
    this->scene->addItem(forest->getTree13());
    this->scene->addItem(forest->getTree14());
    this->scene->addItem(forest->getTree15());
    this->scene->addItem(forest->getTree16());
    this->scene->addItem(forest->getTree17());
    this->scene->addItem(forest->getTree18());
    this->scene->addItem(forest->getBush3());
    this->scene->addItem(forest->getBush4());
    this->scene->addItem(forest->getTree19());
    this->scene->addItem(forest->getBushBerries3());
    this->scene->addItem(forest->getTree20());
    this->scene->addItem(forest->getTree21());
    this->scene->addItem(forest->getTree22());
    this->scene->addItem(forest->getSouche1());
    this->scene->addItem(forest->getSouche2());
    this->scene->addItem(forest->getTree23());
    this->scene->addItem(forest->getBush5());
    this->scene->addItem(forest->getBush6());
    this->scene->addItem(forest->getBush7());
    this->scene->addItem(forest->getSouche3());
    this->scene->addItem(forest->getTree24());
    this->scene->addItem(forest->getTree25());
    this->scene->addItem(forest->getTree26());
    this->scene->addItem(forest->getTree27());
    this->scene->addItem(forest->getTree28());
    this->scene->addItem(forest->getTree29());
    this->scene->addItem(forest->getTree30());
}

void View::save() {this->controller->save();}
void View::saveQuit() {this->controller->saveQuit();}

void View::displayFrontMessage() {
    if (frontMessage) {
        this->bubbleMessageS = this->controller->getImageFront();
        this->scene->addItem(this->bubbleMessageS);

        this->textMessageS = this->controller->getMessageFront();
        this->scene->addItem(this->textMessageS);

        connect(this->bubbleMessageS, SIGNAL(clicked()), this, SLOT(hideFrontMessage()));
    }
}

void View::displayMessageSmurfette() {
    if (!this->controller->isMessageDisplayed()) {
        this->bubbleMessageS = this->controller->getImageBubbleSmurfette();
        this->scene->addItem(this->bubbleMessageS);

        this->imageMessageS = this->controller->getImageSmurfette();
        this->scene->addItem(this->imageMessageS);

        this->textMessageS = this->controller->getMessageSmurfette();
        this->scene->addItem(this->textMessageS);

        connect(this->imageMessageS, SIGNAL(clicked()), this, SLOT(hideMessageS()));
        connect(this->bubbleMessageS, SIGNAL(clicked()), this, SLOT(hideMessageS()));
    }
    this->controller->setMessageDisplayed(true);
}

void View::displayMessagePapaSmurf() {
    if (!this->controller->isMessageDisplayed()) {
        this->bubbleMessageS = this->controller->getImageBubblePapaSmurf();
        this->scene->addItem(this->bubbleMessageS);

        this->imageMessageS = this->controller->getImagePapaSmurf();
        this->scene->addItem(this->imageMessageS);

        this->textMessageS = this->controller->getMessagePapaSmurf();
        this->scene->addItem(this->textMessageS);

        connect(this->bubbleMessageS, SIGNAL(clicked()), this, SLOT(hideMessageS()));
        connect(this->imageMessageS, SIGNAL(clicked()), this, SLOT(hideMessageS()));
    }
    this->controller->setMessageDisplayed(true);
}

void View::displayMessageBrainy() {
    if (!this->controller->isMessageDisplayed()) {
        this->bubbleMessageS = this->controller->getImageBubbleBrainy();
        this->scene->addItem(this->bubbleMessageS);

        this->imageMessageS = this->controller->getImageBrainy();
        this->scene->addItem(this->imageMessageS);

        this->textMessageS = this->controller->getMessageBrainy();
        this->scene->addItem(this->textMessageS);

        connect(this->bubbleMessageS, SIGNAL(clicked()), this, SLOT(hideMessageS()));
        connect(this->imageMessageS, SIGNAL(clicked()), this, SLOT(hideMessageS()));
    }
    this->controller->setMessageDisplayed(true);
}

void View::hideMessageS() {
    this->controller->setMessageDisplayed(false);

    this->scene->removeItem(this->textMessageS);
    this->scene->removeItem(this->bubbleMessageS);
    if (this->imageMessageS != NULL) {
        this->scene->removeItem(this->imageMessageS);
    }
}

void View::hideFrontMessage() {
    this->controller->setMessageDisplayed(false);

    this->scene->removeItem(this->textMessageS);
    this->scene->removeItem(this->bubbleMessageS);

    frontMessage = false;
}

void View::displayMistakeMoney() {
    QMessageBox::warning(this, tr("Erreur"), tr("Attention, vous n'avez pas assez de salsepareille pour effectuer cette tâche."));
}

void View::inventoryContents() {
    if (!this->menuDisplay) {
        QDialog *dial = new QDialog(this);
        dial->setWindowTitle(tr("Inventaire"));
        dial->setFixedSize(400, 200);
        dial->setStyleSheet("background-color: rgb(182,157,130);");
        dial->setWindowIcon(QIcon(":/images/sac"));
        QGridLayout *l = new QGridLayout();

        QLabel *img_acorn = new QLabel;
        img_acorn->setPixmap(QPixmap(":/images/noisette"));
        l->addWidget(img_acorn, 0, 0);
        l->addWidget(new QLabel(QString::number(this->controller->getNumberAcorn()), dial), 0, 1);

        QLabel *img_berry = new QLabel;
        img_berry->setPixmap(QPixmap(":/images/baie"));
        l->addWidget(img_berry, 1, 0);
        l->addWidget(new QLabel(QString::number(this->controller->getNumberBerry()), dial), 1, 1);

        QLabel *img_wheat = new QLabel;
        img_wheat->setPixmap(QPixmap(":/images/ble"));
        l->addWidget(img_wheat, 2, 0);
        l->addWidget(new QLabel(QString::number(this->controller->getNumberWheat()), dial), 2, 1);

        QLabel *img_sarsaparilla = new QLabel;
        img_sarsaparilla->setPixmap(QPixmap(":/images/salsepareille"));
        l->addWidget(img_sarsaparilla, 3, 0);
        l->addWidget(new QLabel(QString::number(this->controller->getNumberSarsaparilla()), dial), 3, 1);

        QLabel *img_bread = new QLabel;
        img_bread->setPixmap(QPixmap(":/images/pain"));
        l->addWidget(img_bread, 0, 3);
        l->addWidget(new QLabel(QString::number(this->controller->getNumberBread()), dial), 0, 4);

        QLabel *img_smurf = new QLabel;
        img_smurf->setPixmap(QPixmap(":/images/smurfHead"));
        l->addWidget(img_smurf, 1, 3);
        l->addWidget(new QLabel(QString::number(this->controller->getNumberSmurfs()), dial), 1, 4);

        QLabel *img_score = new QLabel;
        img_score->setPixmap(QPixmap(":/images/score"));
        l->addWidget(img_score, 2, 3);
        l->addWidget(new QLabel(QString::number(this->controller->getScore()), dial), 2, 4);

        int time = this->controller->gameDuration();
        int minutes = time/60;
        int seconds = time%60;
        QString min, sec;
        if(minutes<10) min = "0"+ QString::number(minutes);
        else min = QString::number(minutes);
        if (seconds<10) sec = "0"+ QString::number(seconds);
        else sec = QString::number(seconds);
        QString gameDuration = min +":"+ sec;

        QLabel *img_chrono = new QLabel;
        img_chrono->setPixmap(QPixmap(":/images/chrono"));
        l->addWidget(img_chrono, 3, 3);
        l->addWidget(new QLabel(gameDuration, dial), 3, 4);

        dial->setLayout(l);

        int result = dial->exec();
        if (result == QDialog::Accepted) {}
        delete dial;
    }
}

void View::displayActionFarmer() {

    if (!this->menuDisplay) {

        QDialog * dial = new QDialog(this);
        dial->setWindowTitle(tr("Paysan niveau ") + QString::number(this->controller->getLevelFarmer()));
        dial->setFixedSize(300, 170);
        dial->setWindowIcon(QIcon(":/images/ble"));
        QGridLayout * l = new QGridLayout();
        QRadioButton *b1 = new QRadioButton(tr("Récolter le blé : ") + QString::number(this->controller->getNumberWheatToHarvest()));
        b1->setChecked(true);
        QRadioButton *b2 = new QRadioButton(tr("Revendre du blé : (") + QString::number(this->controller->getCostWheat()) + "$/u)");
        QSpinBox *nbWheat = new QSpinBox;
        nbWheat->setMinimum(1);
        nbWheat->setMaximum(this->controller->getNumberWheat());
        QRadioButton *b3 = new QRadioButton(tr("Améliorer : ") + QString::number(50 * this->controller->getLevelFarmer()) + "$");
        QPushButton *ok = new QPushButton(tr("Ok"));
        connect(ok,SIGNAL(clicked()),dial,SLOT(accept()));
        QPushButton * cancel = new QPushButton(tr("Annuler"));
        connect(cancel,SIGNAL(clicked()),dial,SLOT(reject()));

        l->addWidget(b1);
        l->addWidget(b2);
        l->addWidget(nbWheat);
        l->addWidget(b3);
        l->addWidget(ok,4,0);
        l->addWidget(cancel,4,1);
        dial->setLayout(l);

        int result = dial->exec();
        if (result == QDialog::Accepted) {
            if (b1->isChecked()) {
                this->controller->harvestWheat();
            }
            else if (b2->isChecked()) {
                this->controller->sellWheat(nbWheat->value());
            }
            else if (b3->isChecked()) {
                this->controller->farmerUp(50 * this->controller->getLevelFarmer());
            }
        }
        delete dial;
    }

}

void View::displayActionBaker() {

    if (!this->menuDisplay) {

        QDialog * dial = new QDialog(this);
        dial->setWindowTitle(tr("Boulanger niveau ") + QString::number(this->controller->getLevelBaker()));
        dial->setFixedSize(300, 170);
        dial->setWindowIcon(QIcon(":/images/pain"));
        QGridLayout * l = new QGridLayout();
        QRadioButton *b1 = new QRadioButton(tr("Fabriquer du pain : (") + QString::number(this->controller->getCostProductionBread())
                                            + "$/u)");
        b1->setChecked(true);
        QSpinBox *nbBread = new QSpinBox;
        nbBread->setMinimum(1);
        nbBread->setMaximum(this->controller->getNumberWheat() / this->controller->getResourceProductionBaker());
        QRadioButton *b2 = new QRadioButton(tr("Améliorer : ") + QString::number(75 * this->controller->getLevelBaker()) + "$");
        QPushButton *ok = new QPushButton(tr("Ok"));
        connect(ok,SIGNAL(clicked()),dial,SLOT(accept()));
        QPushButton * cancel = new QPushButton(tr("Annuler"));
        connect(cancel,SIGNAL(clicked()),dial,SLOT(reject()));

        l->addWidget(b1);
        l->addWidget(nbBread);
        if (this->controller->getLevelBaker() < 7) {
            l->addWidget(b2);
        }
        l->addWidget(ok,4,0);
        l->addWidget(cancel,4,1);
        dial->setLayout(l);

        int result = dial->exec();
        if (result == QDialog::Accepted) {
            if (b1->isChecked()) {
                this->controller->makeBread(nbBread->value());
            }
            else if (b2->isChecked()) {
                this->controller->bakerUp(75 * this->controller->getLevelBaker());
            }
        }
        delete dial;
    }

}

void View::displayActionHefty() {

    if (!this->menuDisplay) {

        QDialog * dial = new QDialog(this);
        dial->setWindowTitle(tr("Costaud niveau ") + QString::number(this->controller->getLevelHefty()));
        dial->setFixedSize(300, 140);
        dial->setWindowIcon(QIcon(":/images/smurfHead"));
        QGridLayout * l = new QGridLayout();
        QRadioButton *b1 = new QRadioButton(tr("Nouveau Schtroumpf : 5$"));
        b1->setChecked(true);
        QRadioButton *b2 = new QRadioButton(tr("Améliorer : ") + QString::number(50 * this->controller->getLevelHefty()) + "$");
        QPushButton *ok = new QPushButton(tr("Ok"));
        connect(ok,SIGNAL(clicked()),dial,SLOT(accept()));
        QPushButton * cancel = new QPushButton(tr("Annuler"));
        connect(cancel,SIGNAL(clicked()),dial,SLOT(reject()));

        l->addWidget(b1);
        l->addWidget(b2);
        l->addWidget(ok,3,0);
        l->addWidget(cancel,3,1);
        dial->setLayout(l);

        int result = dial->exec();
        if (result == QDialog::Accepted) {
            if (b1->isChecked()) {
                this->controller->creationNewSmurf(5);
            }
            else if (b2->isChecked()) {
                this->controller->heftyUp(50 * this->controller->getLevelHefty());
            }
        }
        delete dial;
    }

}

void View::displayActionDoctor() {

    if (!this->menuDisplay) {

        QDialog * dial = new QDialog(this);
        dial->setWindowTitle(tr("Docteur"));
        dial->setFixedWidth(350);
        dial->setWindowIcon(QIcon(":/images/croixRouge"));
        QGridLayout * l = new QGridLayout();

        QLabel *explanations = new QLabel;
        explanations->setText(tr("1 pain = ") + QString::number(this->controller->getHealthBread()) + tr(" PV, "
                                 "1 baie = ") + QString::number(this->controller->getHealthBerries()) + tr(" PV, "
                                 "1 gland = ") + QString::number(this->controller->getHealthAcorn()) + tr(" PV."));
        l->addWidget(explanations, 0, 0, 1, 5);

        QLabel *stock = new QLabel;
        stock->setText(tr("En stock, il y a ") + QString::number(this->controller->getNumberBread()) + tr(" pain(s),"
                                          " ") + QString::number(this->controller->getNumberBerry()) + tr(" baie(s),"
                                          " ") + QString::number(this->controller->getNumberAcorn()) + tr(" gland(s)."));
        l->addWidget(stock, 1, 0, 1, 5);

        l->addWidget(new QLabel(tr("Besoin de PV"), dial), 2, 0);
        QLabel *img_bread = new QLabel;
        img_bread->setPixmap(QPixmap(":/images/pain"));
        l->addWidget(img_bread, 2, 1);
        QLabel *img_berry = new QLabel;
        img_berry->setPixmap(QPixmap(":/images/baie"));
        l->addWidget(img_berry, 2, 2);
        QLabel *img_acorn = new QLabel;
        img_acorn->setPixmap(QPixmap(":/images/noisette"));
        l->addWidget(img_acorn, 2, 3);

        int nbSmurfToHeal = 0;
        for (int i=0; i<this->controller->getlistNicePerso()->size(); i++) {
            int treatment = this->controller->setTreatment(i);
            if (treatment > 0) {
                nbSmurfToHeal++;
            }
        }
        QVector<QCheckBox *> checkbox;
        QVector<QSpinBox *> spinbox;

        for (int i=0; i<nbSmurfToHeal; i++) {
            int treatment = this->controller->setTreatment(i);
            l->addWidget(new QLabel("<center>" + QString::number(treatment) + "</center>", dial), i+3, 0);

            QSpinBox *nbBreadSelected = new QSpinBox;
            nbBreadSelected->setMinimum(0);
            nbBreadSelected->setMaximum(this->controller->getMaxBreadForTreatment());
            this->controller->setNumberBreadSelected(nbBreadSelected->value());
            l->addWidget(nbBreadSelected, i+3, 1);

            QSpinBox *nbBerrySelected = new QSpinBox;
            nbBerrySelected->setMinimum(0);
            nbBerrySelected->setMaximum(this->controller->getMaxBerriesForTreatment());
            this->controller->setNumberBerrySelected(nbBerrySelected->value());
            l->addWidget(nbBerrySelected, i+3, 2);

            QSpinBox *nbAcornSelected = new QSpinBox;
            nbAcornSelected->setMinimum(0);
            nbAcornSelected->setMaximum(this->controller->getMaxAcornForTreatment());
            this->controller->setNumberAcornSelected(nbAcornSelected->value());
            l->addWidget(nbAcornSelected, i+3, 3);

            QCheckBox *validate = new QCheckBox;
            l->addWidget(validate, i+3, 4);

            checkbox.append(validate);
            spinbox.append(nbBreadSelected);
            spinbox.append(nbBerrySelected);
            spinbox.append(nbAcornSelected);
        }

        QPushButton *ok = new QPushButton(tr("Ok"));
        connect(ok,SIGNAL(clicked()),dial,SLOT(accept()));
        QPushButton * cancel = new QPushButton(tr("Annuler"));
        connect(cancel,SIGNAL(clicked()),dial,SLOT(reject()));

        l->addWidget(ok, nbSmurfToHeal+3, 1, 1, 2);
        l->addWidget(cancel, nbSmurfToHeal+3, 3, 1, 2);
        dial->setLayout(l);

        int result = dial->exec();
        if (result == QDialog::Accepted) {
            for (int i=0; i<nbSmurfToHeal; i++) {
                if (checkbox[i]->isChecked() == true) {
                    if (spinbox[i*3]->value() > this->controller->getNumberBread()) {
                        QMessageBox::warning(this, tr("Erreur"), tr("Attention, vous n'avez pas assez de pains pour effectuer cette tâche."));
                    }
                    else if (spinbox[(i*3)+1]->value() > this->controller->getNumberBerry()) {
                        QMessageBox::warning(this, tr("Erreur"), tr("Attention, vous n'avez pas assez de baies pour effectuer cette tâche."));
                    }
                    else if (spinbox[(i*3)+2]->value() > this->controller->getNumberAcorn()) {
                        QMessageBox::warning(this, tr("Erreur"), tr("Attention, vous n'avez pas assez de glands pour effectuer cette tâche."));
                    }
                    else this->controller->treat(i, spinbox[i*3]->value(), spinbox[(i*3)+1]->value(), spinbox[(i*3)+2]->value());
                }
            }
        }
        delete dial;
    }

}

void View::addNormalPerso(NicePerso *perso) {
    this->scene->addItem(perso->getImagePerso());
}

void View::addNormalPerso(MadPerso *perso) {
    this->scene->addItem(perso->getImagePerso());
}

void View::mousePressEvent(QMouseEvent *event) {

    this->m_lastPoint = event->pos();
    // set the flag meaning "click begin"
    this->m_mouseClick = true;

    if (!this->menuDisplay) {

        QPointF pt = event->pos();

        QDialog * dial = new QDialog(this);
        dial->setWindowTitle(tr("Déplacement"));
        dial->setFixedSize(300, 150);
        QGridLayout * l = new QGridLayout();
        QLabel *movement = new QLabel(tr("Combien de Schtroumpfs?"));
        QSpinBox *nbS = new QSpinBox;
        nbS->setFocus();
        nbS->setMinimum(1);
        nbS->setMaximum(this->controller->getNumberFreePerso());
        QPushButton *ok = new QPushButton(tr("Ok"));
        connect(ok,SIGNAL(clicked()),dial,SLOT(accept()));
        QPushButton * cancel = new QPushButton(tr("Annuler"));
        connect(cancel,SIGNAL(clicked()),dial,SLOT(reject()));

        l->addWidget(movement,0,0);
        l->addWidget(nbS,1,0);
        l->addWidget(ok,2,0);
        l->addWidget(cancel,2,1);
        dial->setLayout(l);

        int result = dial->exec();

        if (result == QDialog::Accepted) {

            this->controller->actionPerso(pt.x() + ui->graphicsView->horizontalScrollBar()->value(),
                                          pt.y() + ui->graphicsView->verticalScrollBar()->value() - 17, nbS->value());
        }

        //qDebug() << "Click [" << pt.x() << ";" << (pt.y() - 17) << "]";

        delete dial;
    }

}

void View::mouseReleaseEvent(QGraphicsSceneMouseEvent *e)
{
    qDebug() << "TestView";
    // check if cursor not moved since click beginning
    if ((m_mouseClick) && (e->pos() == m_lastPoint))
    {
        // do something: for example emit Click signal
        //emit clicked();
        qDebug() << "TestView2";

    }
}
