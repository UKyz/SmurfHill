#ifndef AUTRE_H
#define AUTRE_H

#include "ressources.h"

#include <QString>
#include <QMainWindow>
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsTextItem>
#include <QGraphicsView>
#include <QGraphicsSceneMouseEvent>
#include <QThread>
#include <QtDebug>

class Resource;

class Image: public QObject, public QGraphicsPixmapItem {

    Q_OBJECT

    public:
        Image(QString url, QGraphicsItem * parent=0);
        void *getParent() {return this->parent;}

    signals:
        void clicked();

    protected:
        // re-implement processing of mouse events
        void mouseReleaseEvent ( QGraphicsSceneMouseEvent *e )
        {
            // check if cursor not moved since click beginning
            if ((m_mouseClick) && (e->pos() == m_lastPoint))
            {
                // do something: for example emit Click signal
                emit clicked();
            }
        }

        void mousePressEvent ( QGraphicsSceneMouseEvent *e )
        {
            // store click position
            m_lastPoint = e->pos();
            // set the flag meaning "click begin"
            m_mouseClick = true;

            qDebug() << "Wallah";
        }

    private:
        bool m_mouseClick;
        QPointF m_lastPoint;
        void *parent;
};

class ImageSetting: public QObject, public QGraphicsPixmapItem {

    Q_OBJECT

    public:
        ImageSetting(QString url, QGraphicsItem * parent=0);

    signals:
        void clicked();

    protected:
        // re-implement processing of mouse events
        void mouseReleaseEvent ( QGraphicsSceneMouseEvent *e )
        {
            // check if cursor not moved since click beginning
            if ((m_mouseClick) && (e->pos() == m_lastPoint))
            {
                // do something: for example emit Click signal
                emit clicked();
            }
        }

        void mousePressEvent ( QGraphicsSceneMouseEvent *e )
        {
            // store click position
            m_lastPoint = e->pos();
            // set the flag meaning "click begin"
            m_mouseClick = true;
        }

    private:
        bool m_mouseClick;
        QPointF m_lastPoint;
};

class WheatField: public QObject {

    Q_OBJECT

    public:
        WheatField(int numberWheatToHarvest = 0, int capacity = 10, int size = 100);
        void increaseCapacity(int capacity) {this->capacity += capacity;}
        void increaseSize(int size) {this->size += size;}
        void harvest(Resource *bagWheats);
        int getNumberWheatToHarvest() {return this->numberWheatToHarvest;}
        int getSize() {return this->size;}
        int getCapacity() {return this->capacity;}

    private:
        int numberWheatToHarvest;
        int capacity;
        int size;

    public slots:
        void ete();
};

class Score: public QObject {

    Q_OBJECT

    public:
        Score(int points = 0);
        int getPoints() {return this->points;}
        void addPoints(int nb) {this->points += nb;}

    private:
        int points;
};

#endif // AUTRE_H
