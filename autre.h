#ifndef AUTRE_H
#define AUTRE_H

#include <QString>
#include <QMainWindow>
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsTextItem>
#include <QGraphicsView>
#include <QGraphicsSceneMouseEvent>

class Image: public QObject, public QGraphicsPixmapItem {

    Q_OBJECT

    public:
        Image( QString url, QGraphicsItem * parent=0);

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

/*class Message: public QObject {

    Q_OBJECT

    public:
        Message();
        void setBulle() {this->}

    private:
        Image *bulle;
        Image *perso;
        QGraphicsTextItem *texte;

}*/



#endif // AUTRE_H
