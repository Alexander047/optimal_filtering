#include "Gui/main_window.h"
#include <QApplication>



int main (int argc, char *argv[])
{
    QApplication a (argc, argv);
    a.setApplicationName (QObject::tr ("Оптимальная фильтрация"));
    a.setApplicationVersion ("2.4.1");
    a.setApplicationDisplayName (a.applicationName() + "  " + a.applicationVersion());
    MainWindow w;
    w.show();

    return a.exec();
}
