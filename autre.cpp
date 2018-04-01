#include "autre.h"

#include <QPixmap>
#include <QTimer>
#include <QGraphicsScene>

Image::Image(QString url, QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){
    // draw graphics
    setPixmap(QPixmap(url));

    // make/connect a timer to move() the bullet every so often
    /*QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));*/

    // start the timer
    //timer->start(50);
}









