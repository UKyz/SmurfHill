#ifndef AUTRE_H
#define AUTRE_H

//#include "personnages.h"
//#include "model.h"
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
    }

private:
    bool m_mouseClick;
    QPointF m_lastPoint;
    void *parent;
};

class ImageDecor: public QObject, public QGraphicsPixmapItem {

    Q_OBJECT

    public:
        ImageDecor(QString url, QGraphicsItem * parent=0);

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

class ImagePersoMechant: public QObject, public QGraphicsPixmapItem {

    Q_OBJECT

    public:
        ImagePersoMechant( QString url, QGraphicsItem * parent=0);

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



class ChampBle: public QObject {

    Q_OBJECT

    public:
        ChampBle();
        void augmenterCapacite(int capacite) {this->capacite += capacite;}
        void recolter(Ressource *sacDeBle);
        int getNbBleARecolter() {return this->nbBleARecolter;}

    private:
        int nbBleARecolter;
        int capacite;

    public slots:
        void ete();
};


/*class GameLoop : public QObject {
    Q_OBJECT
public:
    GameLoop(Model *model);
    ~GameLoop();
public slots:
    void process();
signals:
    void finished();
    void error(QString err);
private:
    Model *model;
};*/

/*class ImageRessourceAcorn: public QObject, public QGraphicsPixmapItem {

    Q_OBJECT

    public:
        ImageRessourceAcorn( QString url, QGraphicsItem * parent=0, int nbElements);

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
    int nbElements;
};*/



#endif // AUTRE_H
