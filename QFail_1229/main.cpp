#include "widget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Widget widget;
    widget.setAge(0);
    QTest::qExec(&widget);

    return a.exec();
}
