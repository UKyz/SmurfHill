#include "view.h"
#include "model.h"
#include "controller.h"
#include "autre.h"

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QVBoxLayout>

#include <QApplication>

//Game * game;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    View w;
    Model m;

    // On crée un objet game (QGraphicsView contenant un QGraphicsScene contenant nos images de Schtroumpf)
    //game = new Game();

    Controller(&m, &w);

    // On met l'objet en tant qu'objet principal de la view
    //w.setCentralWidget(game);
    w.show();

    return a.exec();
}
