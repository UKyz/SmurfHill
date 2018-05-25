#include "ressources.h"

Resource::Resource(QString name) {
    this->name = name;
    this->number = 0;
}

Resource::Resource(QString name, int number) {
    this->name = name;
    this->number = number;
}

bool Resource::removeResource(int nb) {
    if (this->number - nb >= 0) {
        this->number -= nb;
        return true;
    } else {
        return false;
    }
}

Food::Food(QString name, int health) :Resource(name) {
    this->health = health;
}

ResourceItem::ResourceItem(QString name, int number, ImageSetting *image, int posX, int posY): Resource(name, number) {
    this->imageItem = image;
    this->posX = posX;
    this->posY = posY;
    this->imageItem->setPos(posX, posY);
}
