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

class Village;
class Foret;
class Foret1;
class Foret2;

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
        void addPersoNormaux(PersoNormaux *perso);

        int cptMovie = 0;
        QGraphicsScene *scene;

        bool generique = false;
        QMediaPlayer *player;

        bool menuDisplay = true;

    private slots:

        void on_pushButton_clicked();
        //void test() {QMessageBox::information(this, "Debug", "It works! 2", QMessageBox::Ok);}
        void film();
        void musique();

    private:
        Ui::View *ui;
        Controller *controller;
        void mousePressEvent(QMouseEvent *event);
        QTimer *timer;
        QList <QString> list_movies;
};

#endif // VIEW_H
