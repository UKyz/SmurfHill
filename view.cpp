#include "view.h"
#include "ui_view.h"
#include "controller.h"
#include "model.h"
#include "autre.h"

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
        list_movies.append("/Users/Victor/Schtroumph-Hill//images/movie"+QString::number(i));
    }

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(film()));
    timer->start(5000);

    scene = new QGraphicsScene();
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setFixedSize(600,550);
    scene->addText("Schtroumpf-Hill : The Game");
}

View::~View() {
    delete ui;
}

void View::on_pushButton_clicked() {
    timer->disconnect();
    this->controller->startGame();
}

void View::installScene() {

    scene->clear(); // Supprime le chargement
    this->setCentralWidget(ui->graphicsView);
    scene->setSceneRect(0,0,3000,2000); // make the scene 800x600 instead of infinity by infinity (default)
    // make the newly created scene the scene to visualize (since Game is a QGraphicsView Widget,
    // it can be used to visualize scenes)
    ui->graphicsView->setBackgroundBrush(QBrush(QImage("/Users/Victor/Schtroumph-Hill/images/fond_herbe.png")));
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

void View::musique() {
    generique = !generique;
    if (generique == true) {
        this->player = new QMediaPlayer;
        this->player->setMedia(QUrl::fromLocalFile("/Users/Victor/Schtroumph-Hill/images/generique.mp3"));
        this->player->setVolume(50);
        this->player->play();
    }
    else this->player->stop();
}

void View::displayMessageSette() {

    if (!this->message) {

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

void View::addPersoNormaux(PersoNormaux *perso) {
    this->scene->addItem(perso->getImagePerso());
}

void View::mousePressEvent(QMouseEvent *event) {

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
        QPushButton * ok = new QPushButton("Ok");
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

        if (result == QDialog::Accepted)
        {

            this->controller->actionPerso(pt.x() + ui->graphicsView->horizontalScrollBar()->value(),
                                          pt.y() + ui->graphicsView->verticalScrollBar()->value() - 17, nbS->value());
        }

        delete dial;

}

