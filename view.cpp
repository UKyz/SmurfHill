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
#include <QTimer>
#include <QGraphicsRectItem>

View::View(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::View)
{
    ui->setupUi(this);

    for (int i=0; i<11; i++) {
        list_movies.append("://images/movie"+QString::number(i));
    }

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(film()));
    timer->start(5000);

    scene = new QGraphicsScene();
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setFixedSize(600,550);
    scene->addText(QString("Schtroumpf-Hill : The Game"), QFont("Monotype Corsiva", 20));
}

View::~View() {
    delete ui;
}

void View::film()
{
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

void View::on_pushButton_clicked() {
    timer->disconnect();
    this->controller->startGame();
    //this->controller->game();
}

void View::installScene() {

    this->menuDisplay = false;
    scene->clear(); // Supprime le chargement
    this->setCentralWidget(ui->graphicsView);
    scene->setSceneRect(0,0,3000,2000); // make the scene 800x600 instead of infinity by infinity (default)
    // make the newly created scene the scene to visualize (since Game is a QGraphicsView Widget,
    // it can be used to visualize scenes)
    ui->graphicsView->setBackgroundBrush(QBrush(QImage(":/images/fond_herbe")));
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setFixedSize(1155,650);
    //QObject::connect(scene, SIGNAL(clicked()), this, SLOT(test));

}

void View::addVillage(Village *village) {

    this->scene->addItem(village->getMoulinS());
    this->scene->addItem(village->getMaison7());
    this->scene->addItem(village->getMaison5());
    this->scene->addItem(village->getMaison1());
    this->scene->addItem(village->getMaison2());
    this->scene->addItem(village->getMaison3());
    this->scene->addItem(village->getMaison4());
    this->scene->addItem(village->getArbre1());
    this->scene->addItem(village->getMaison6());
    this->scene->addItem(village->getMaison8());
    this->scene->addItem(village->getMaison9());
    this->scene->addItem(village->getMaisonSette());
    this->scene->addItem(village->getMaisonSCostaud());
    this->scene->addItem(village->getMaisonSMusicien());
    this->scene->addItem(village->getMaisonSPaysan());
    this->scene->addItem(village->getGrandS());
    this->scene->addItem(village->getPuits());
    this->scene->addItem(village->getArbre2());

}

void View::musique() {

    generique = !generique;
    if (generique == true) {
        this->player = new QMediaPlayer;
        this->player->setMedia(QUrl::fromLocalFile(":/sons/generique"));
        this->player->setVolume(50);
        this->player->play();
    }
    else this->player->stop();
}

void View::addForet1(Foret1 *foret) {
    this->scene->addItem(foret->getNoisette());
    this->scene->addItem(foret->getBaie());

    this->scene->addItem(foret->getBuissonBaies1());
    this->scene->addItem(foret->getBuissonBaies2());

    this->scene->addItem(foret->getArbre16());
    this->scene->addItem(foret->getArbre14());
    this->scene->addItem(foret->getArbre15());
    this->scene->addItem(foret->getArbre8());
    this->scene->addItem(foret->getArbre5());
    this->scene->addItem(foret->getArbre2());
    this->scene->addItem(foret->getArbre6());
    this->scene->addItem(foret->getArbre17());
    this->scene->addItem(foret->getArbre1());
    this->scene->addItem(foret->getArbre9());
    this->scene->addItem(foret->getArbre4());
    this->scene->addItem(foret->getArbre3());
    this->scene->addItem(foret->getArbre7());
    this->scene->addItem(foret->getArbre10());
    this->scene->addItem(foret->getArbre11());
    this->scene->addItem(foret->getArbre12());
    this->scene->addItem(foret->getArbre13());
    //this->scene->addItem(foret->getArbre14());
    //this->scene->addItem(foret->getArbre15());

    this->scene->addItem(foret->getBuisson1());
    this->scene->addItem(foret->getBuisson2());

    this->scene->addItem(foret->getBle());
}

/*
void View::addForet2(Foret2 *foret) {
    this->scene->addItem(foret->getArbre1());
    this->scene->addItem(foret->getArbre2());
    this->scene->addItem(foret->getArbre3());
    this->scene->addItem(foret->getArbre4());
    this->scene->addItem(foret->getArbre5());
    this->scene->addItem(foret->getArbre6());
    this->scene->addItem(foret->getArbre7());
    this->scene->addItem(foret->getArbre8());
    this->scene->addItem(foret->getArbre9());
    this->scene->addItem(foret->getArbre10());
}
*/

void View::displayMessageSette() {

    if (!this->controller->isMessageDisplayed()) {

        this->bulleMessageS = this->controller->getImageBulle();
        this->scene->addItem(this->bulleMessageS);

        this->imageMessageS = this->controller->getImageSette();
        this->scene->addItem(this->imageMessageS);

        this->texteMessageS = this->controller->getMessageSette();
        this->scene->addItem(this->texteMessageS);

        connect(this->imageMessageS, SIGNAL(clicked()), this, SLOT(hideMessageS()));
        connect(this->bulleMessageS, SIGNAL(clicked()), this, SLOT(hideMessageS()));
        connect(this->texteMessageS, SIGNAL(clicked()), this, SLOT(hideMessageS()));

    }

    this->controller->setMessageDisplayed(true);
}

void View::displayMessageGrandS() {

    if (!this->controller->isMessageDisplayed()) {

        this->bulleMessageS = this->controller->getImageBulle();
        this->scene->addItem(this->bulleMessageS);

        this->imageMessageS = this->controller->getImageGrandS();
        this->scene->addItem(this->imageMessageS);

        this->texteMessageS = this->controller->getMessageGrandS();
        this->scene->addItem(this->texteMessageS);

        connect(this->bulleMessageS, SIGNAL(clicked()), this, SLOT(hideMessageS()));
        connect(this->imageMessageS, SIGNAL(clicked()), this, SLOT(hideMessageS()));
        connect(this->texteMessageS, SIGNAL(clicked()), this, SLOT(hideMessageS()));

    }

    this->controller->setMessageDisplayed(true);
}

void View::hideMessageS() {

    this->controller->setMessageDisplayed(false);

    this->scene->removeItem(this->texteMessageS);
    this->scene->removeItem(this->bulleMessageS);
    this->scene->removeItem(this->imageMessageS);

}

void View::displayActionCostaud() {



}

void View::displayActionPaysan() {

    /*qDebug() << pos.x() << " " << pos.y() << " " << nbNoisette;*/

    if (!this->menuDisplay) {

        QDialog * dial = new QDialog(this);
        dial->setWindowTitle("Schtroumpf Paysan");
        QGridLayout * l = new QGridLayout();
        //QGroupBox *gp = new QGroupBox(tr("Groupe Radio"));
        QRadioButton *b1 = new QRadioButton("Récolter le blé : " + QString::number(this->controller->getNumberWheatToRecolt()));
        b1->setChecked(true);
        QSpinBox *nbPain = new QSpinBox;
        nbPain->setMinimum(1);
        nbPain->setMaximum(this->controller->getNumberWheat() / 2);
        QRadioButton *b2 = new QRadioButton(tr("Fabriquer du pain"));
        QRadioButton *b3 = new QRadioButton(tr("Améliorer : 50$"));
        QPushButton *ok = new QPushButton("Ok");
        connect(ok,SIGNAL(clicked()),dial,SLOT(accept()));
        QPushButton * cancel = new QPushButton("Annuler");
        connect(cancel,SIGNAL(clicked()),dial,SLOT(reject()));

        l->addWidget(b1);
        l->addWidget(nbPain);
        l->addWidget(b2);
        l->addWidget(b3);
        l->addWidget(ok,5,0);
        l->addWidget(cancel,5,1);
        dial->setLayout(l);

        int result = dial->exec();

        if (result == QDialog::Accepted) {

            if (b1->isChecked()) {
                qDebug() << "b1";
                this->controller->recoltWheat();
            }
            else if (b2->isChecked()) {
                qDebug() << "b2";
                this->controller->makeBred(nbPain->value());
            }
            else {
                qDebug() << "b3";
                //this->controller->makeBred();
            }
        }

        delete dial;
    }

}

void View::onResourceAcornClicked(QPointF pos, int nbNoisette) {

    qDebug() << pos.x() << " " << pos.y() << " " << nbNoisette;

    if (!this->menuDisplay) {

        QDialog * dial = new QDialog(this);
        dial->setWindowTitle("Noisette");
        QGridLayout * l = new QGridLayout();
        //QGroupBox *gp = new QGroupBox(tr("Groupe Radio"));
        QSpinBox *nbS = new QSpinBox;
        nbS->setFocus();
        nbS->setMinimum(1);
        nbS->setMaximum(this->controller->getNbSFree());
        QRadioButton *b1 = new QRadioButton(tr("Radio 1"));
        b1->setChecked(true);
        QRadioButton *b2 = new QRadioButton(tr("Radio 2"));
        QRadioButton *b3 = new QRadioButton(tr("Radio 3"));
        QPushButton *ok = new QPushButton("Ok");
        connect(ok,SIGNAL(clicked()),dial,SLOT(accept()));
        QPushButton * cancel = new QPushButton("Annuler");
        connect(cancel,SIGNAL(clicked()),dial,SLOT(reject()));

        l->addWidget(nbS);
        l->addWidget(b1);
        l->addWidget(b2);
        l->addWidget(b3);
        l->addWidget(ok,5,0);
        l->addWidget(cancel,5,1);
        dial->setLayout(l);

        int result = dial->exec();

        if (result == QDialog::Accepted) {

            this->controller->actionPerso(pos.x() + 20,
                                          pos.y() + 20, nbS->value());


            qDebug() << pos.x() + ui->graphicsView->horizontalScrollBar()->value() << " " <<
                        pos.y() + ui->graphicsView->verticalScrollBar()->value() + 17 << " " << nbS->value();
        }

        delete dial;
    }

}

void View::onResourceBayClicked(QPointF pos, int nbBaie) {



}

void View::onResourceWheatClicked(QPointF pos, int nbBle) {



}

void View::addPersoNormaux(PersoGentil *perso) {
    this->scene->addItem(perso->getImagePerso());
}

void View::addPersoNormaux(PersoMechant *perso) {
    this->scene->addItem(perso->getImagePerso());
}

void View::mousePressEvent(QMouseEvent *event) {

    if (!this->menuDisplay) {

        QPointF pt = event->pos();

        QDialog * dial = new QDialog(this);
        dial->setWindowTitle("Choix");
        QGridLayout * l = new QGridLayout();
        //QGroupBox *gp = new QGroupBox(tr("Groupe Radio"));
        QSpinBox *nbS = new QSpinBox;
        nbS->setFocus();
        nbS->setMinimum(1);
        nbS->setMaximum(this->controller->getNbSFree());
        QRadioButton *b1 = new QRadioButton(tr("Radio 1"));
        b1->setChecked(true);
        QRadioButton *b2 = new QRadioButton(tr("Radio 2"));
        QRadioButton *b3 = new QRadioButton(tr("Radio 3"));
        QPushButton *ok = new QPushButton("Ok");
        connect(ok,SIGNAL(clicked()),dial,SLOT(accept()));
        QPushButton * cancel = new QPushButton("Annuler");
        connect(cancel,SIGNAL(clicked()),dial,SLOT(reject()));

        l->addWidget(nbS);
        l->addWidget(b1);
        l->addWidget(b2);
        l->addWidget(b3);
        l->addWidget(ok,5,0);
        l->addWidget(cancel,5,1);
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

