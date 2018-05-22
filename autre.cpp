#include "autre.h"

#include <QPixmap>
#include <QTimer>
#include <QGraphicsScene>
#include <QtDebug>
#include <math.h>

Image::Image(QString url, QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){
    setPixmap(QPixmap(url));
}

ImageSetting::ImageSetting(QString url, QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){
    setPixmap(QPixmap(url));
}

WheatField::WheatField(int numberWheatToHarvest, int capacity, int size) {
    this->capacity = capacity;
    this->numberWheatToHarvest = numberWheatToHarvest;
    this->size = size;
}

void WheatField::harvest(Resource *bagWheats) {
    qDebug() << "Sac de blé avant : " << bagWheats->getNumber();
    bagWheats->addResource(this->numberWheatToHarvest);
    this->numberWheatToHarvest = 0;
    qDebug() << "Sac de blé après : " << bagWheats->getNumber();
}

void WheatField::ete() {
    srand(time(NULL));
    int nbWheat = ((rand() % this->capacity) + 1);

    if ((this->numberWheatToHarvest + nbWheat) > this->size)
        this->numberWheatToHarvest = this->size;
    else
        this->numberWheatToHarvest += ((rand() % this->capacity) + 1);
}

Score::Score(int points) {
    this->points = points;
}
