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

View::View(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::View)
{
    ui->setupUi(this);
    scene = new QGraphicsScene();
    ui->graphicsView->setScene(scene);
    scene->addItem(new Image("/Users/Victor/Schtroumph-Hill/images/SchtroumpfChargement"));
    scene->addText("Schtroumpf-Hill : The Game");

    /*QLabel *gif_anim = new QLabel();
    QMovie *movie = new QMovie("/Users/Victor/Schtroumph-Hill/images/SchtroumpfChargement");
    gif_anim->setMovie(movie);
    movie->start();
    scene->addWidget(gif_anim);*/
}

View::~View()
{
    delete ui;
}

void View::on_pushButton_clicked()
{
    this->controller->startGame();
}

void View::installScene() {

    scene->clear(); // Supprime le chargement
    this->setCentralWidget(ui->graphicsView);
    scene->setSceneRect(0,0,800,600); // make the scene 800x600 instead of infinity by infinity (default)
    // make the newly created scene the scene to visualize (since Game is a QGraphicsView Widget,
    // it can be used to visualize scenes)
    ui->graphicsView->setBackgroundBrush(QBrush(QImage("/Users/Victor/Schtroumph-Hill/images/fond_herbe.png")));
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setFixedSize(1155,650);
    QObject::connect(scene, SIGNAL(clicked()), this, SLOT(test));

}

Game::Game(QWidget *parent){

    // create the scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600); // make the scene 800x600 instead of infinity by infinity (default)
    // make the newly created scene the scene to visualize (since Game is a QGraphicsView Widget,
    // it can be used to visualize scenes)
    setBackgroundBrush(QBrush(QImage("/Users/Victor/Schtroumph-Hill/images/fond_herbe.png")));
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1155,650);
    QObject::connect(scene, SIGNAL(selectionChanged()), this, SLOT(whatIsSelected));
}

void View::addVillage(Village *village) {

    //this->scene->addItem(village->getMaison1());
    this->scene->addItem(village->getMaison2());
    this->scene->addItem(village->getMaisonSette());
    this->scene->addItem(village->getMaison3());
    this->scene->addItem(village->getMaison4());
    this->scene->addItem(village->getGrandS());
    this->scene->addItem(village->getMaison5());
    this->scene->addItem(village->getArbre1());
    this->scene->addItem(village->getMaisonSCostaud());
    village->getMaisonSCostaud()->setFlag(QGraphicsItem::ItemIsSelectable, true);
    this->scene->addItem(village->getMaisonSPaysan());
    //this->scene->addItem(village->getMoulinS());

}

