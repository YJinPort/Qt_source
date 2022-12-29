#include "widget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.setObjectName("parent");
    w.setGeometry(86, 70, 200, 120);
    w.show();
    w.dumpObjectTree();
    return a.exec();
}
