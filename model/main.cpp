#include "view.h"
#include "model.h"
#include "controller.h"
#include "autre.h"

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <QVBoxLayout>
#include <QApplication>
#include <QTranslator>
#include <QSettings>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    View w;
    Model m;
    Controller *c = new Controller(&m, &w);

    QTranslator t;
    QString locale;
    QSettings s("ESME", "smurfHill");
    QVariant v = s.value("lang");
    if (v.isValid())
        locale = v.toString();
    else
        locale = QLocale::system().name();
    if(t.load("C:/Users/Alexia/Documents/ihm/smurfHill_" + locale))
         a.installTranslator(&t);

    w.show();
    return a.exec();
}
