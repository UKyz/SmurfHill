#ifndef RESSOURCES_H
#define RESSOURCES_H

#include "autre.h"
#include <QObject>

class Image;
class ImageSetting;

class Resource : public QObject {
    Q_OBJECT
    public:
        Resource(QString name);
        Resource(QString name, int number);
        QString getName() {return this->name;}
        int getNumber() {return this->number;}
        void addResource(int nb) {this->number += nb;}
        bool removeResource(int nb);
    protected:
        QString name;
        int number;
};

class Food : public Resource {
    Q_OBJECT
    public:
        Food(QString name, int health);
        int getHealth() {return this->health;}
    private:
        int health;
};

class ResourceItem : public Resource {
    Q_OBJECT
    public:
        ResourceItem(QString name, int nombre, ImageSetting *image, int posX, int posY);
        ImageSetting *getImageItem() {return this->imageItem;}
        void setImageItem(ImageSetting *image) {this->imageItem = image;}
        int getPosX() {return this->posX;}
        int getPosY() {return this->posY;}
        void setPosX(int posX) {this->posX = posX;}
        void setPosY(int posY) {this->posY = posY;}
    private:
        ImageSetting *imageItem;
        int posX;
        int posY;
};

#endif // RESSOURCES_H
