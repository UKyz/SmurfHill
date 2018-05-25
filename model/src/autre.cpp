#include "../includes/autre.h"

Image::Image(QString url, QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){
    setPixmap(QPixmap(url));
}

void Image::mouseReleaseEvent (QGraphicsSceneMouseEvent *e) {
    if ((m_mouseClick) && (e->pos() == m_lastPoint)) {
        emit clicked();
    }
}

void Image::mousePressEvent (QGraphicsSceneMouseEvent *e) {
    m_lastPoint = e->pos();
    m_mouseClick = true;
}

ImageSetting::ImageSetting(QString url, QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){
    setPixmap(QPixmap(url));
}

void ImageSetting::mouseReleaseEvent (QGraphicsSceneMouseEvent *e) {
    if ((m_mouseClick) && (e->pos() == m_lastPoint)) {
        emit clicked();
    }
}

void ImageSetting::mousePressEvent (QGraphicsSceneMouseEvent *e) {
    m_lastPoint = e->pos();
    m_mouseClick = true;
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

void WheatField::summer() {
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
