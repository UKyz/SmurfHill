#ifndef VIEW_H
#define VIEW_H

#include "autre.h"
#include "controller.h"
#include "decor.h"

#include <QMainWindow>
#include <QTableWidget>
#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <QMessageBox>

class Game;
class Village;

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
        //void setGame(Game *game) {this->game = game;}
        //Game *getGame() {return this->game;}
        void installScene();
        void addVillage(Village *village);

        QGraphicsScene *scene;

    private slots:

        void on_pushButton_clicked();
        void test() {QMessageBox::information(this, "Debug", "It works! 2", QMessageBox::Ok);}

    private:
        Ui::View *ui;
        Controller *controller;
        //Game *game;
};

class Game: public QGraphicsView{

    public:
        Game(QWidget * parent=0);
        QGraphicsScene * scene;
        void setView(View *view) {this->view = view;}
        void addVillage(Village *village);

    private:
        View *view;

};

#endif // VIEW_H
