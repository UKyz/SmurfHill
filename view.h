#ifndef VIEW_H
#define VIEW_H

#include "autre.h"
#include "controller.h"
#include "decor.h"
#include "personnages.h"

#include <QMainWindow>
#include <QTableWidget>
#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <QMessageBox>
#include <QMediaPlayer>
#include <QPointF>

class Village;
class Foret;
class Foret1;
class Foret2;
class Controller;

namespace Ui {
    class View;
}

class View : public QMainWindow
{
    Q_OBJECT

    public:

        explicit View(QWidget *parent = 0);
        ~View();

        void setControl(Controller *controller) {this->controller = controller;}
        void installScene();
        void addVillage(Village *village);
        void addForet1(Foret1 *foret);
        //void addForet2(Foret2 *foret);
        void addPersoNormaux(PersoGentil *perso);
        void addPersoNormaux(PersoMechant *perso);

        void onResourceWheatClicked(QPointF pos, int nbBle);
        void onResourceAcornClicked(QPointF pos, int nbNoisette);
        void onResourceBayClicked(QPointF pos, int nbBaie);

        QGraphicsScene *scene;

        bool menuDisplay = true;
        int cptMovie = 0;
        bool generique = false;
        QMediaPlayer *player;

    private slots:

        void on_pushButton_clicked();
        //void test() {QMessageBox::information(this, "Debug", "It works! 2", QMessageBox::Ok);}
        void displayMessageSette();
        void displayMessageGrandS();
        void hideMessageS();
        void film();
        void musique();
        void displayActionCostaud();
        void displayActionPaysan();

    private:
        Ui::View *ui;
        Controller *controller;
        void mousePressEvent(QMouseEvent *event);
        QTimer *timer;
        QList <QString> list_movies;

        Image *bulleMessageS;
        Image *imageMessageS;
        QGraphicsTextItem *texteMessageS;
        bool message = false;
};

#endif // VIEW_H
