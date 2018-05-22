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
#include <QDateTime>
#include <QSpinBox>

class Controller;
class Village;
class Forest;
class Forest1;
class Forest2;
class Forest3;
class Forest4;
class Forest5;
class Forest6;
class Forest7;

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
        void addForest1(Forest1 *forest);
        void addForest2(Forest2 *forest);
        void addForest3(Forest3 *forest);
        void addForest4(Forest4 *forest);
        void addForest5(Forest5 *forest);
        void addForest6(Forest6 *forest);
        void addForest7(Forest7 *forest);
        void addNormalPerso(NicePerso *perso);
        void addNormalPerso(MadPerso *perso);
        void addNormalPerso(NormalPerso *perso);

        void displayMistakeMoney();

        QDateTime heureDebut();
        void menu();
        QGraphicsScene *scene;

        bool menuDisplay = true;
        int cptMovie = 0;
        bool generique = false;
        QMediaPlayer *player;
        void displayFrontMessage();
        bool frontMessage;

    public slots:
        void SwitchLanguage();

    private slots:

        void movie();
        void music();
        void on_pushButton_clicked();
        void on_pushButton_2_clicked();
        void save();
        void saveQuit();

        void displayMessageSmurfette();
        void displayMessagePapaSmurf();
        void displayMessageBrainy();
        void hideMessageS();
        void hideFrontMessage();

        void inventoryContents();
        void displayActionFarmer();
        void displayActionBaker();
        void displayActionHefty();
        void displayActionDoctor();

    private:
        Ui::View *ui;
        Controller *controller;
        void mousePressEvent(QMouseEvent *event);
        void mouseReleaseEvent(QGraphicsSceneMouseEvent *e);
        bool m_mouseClick;
        QPointF m_lastPoint;
        QTimer *timer;
        QList <QString> list_movies;

        Image *bubbleMessageS;
        Image *imageMessageS;
        QGraphicsTextItem *textMessageS;
        bool message = false;
};

#endif // VIEW_H
