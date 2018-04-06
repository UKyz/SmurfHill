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
        void installScene();
        void addVillage(Village *village);
        void addPersoNormaux(PersoNormaux *perso);

        QGraphicsScene *scene;

    private slots:

        void on_pushButton_clicked();
        void test() {QMessageBox::information(this, "Debug", "It works! 2", QMessageBox::Ok);}

    private:
        Ui::View *ui;
        Controller *controller;
        void mousePressEvent(QMouseEvent *event);
};

#endif // VIEW_H
