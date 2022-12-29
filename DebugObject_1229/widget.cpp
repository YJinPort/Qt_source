#include "widget.h"
#include <QApplication>
#include <QPushButton>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QPushButton* quit = new QPushButton("Quit", this);
    //quit->move(30, 30);
    quit->resize(75, 35);
    quit->setGeometry(75, 30, 62, 40);
    quit->setObjectName("child");
    quit->show();
    connect(quit, SIGNAL(clicked()), qApp, SLOT(quit()));
    quit->dumpObjectInfo();
}

Widget::~Widget()
{
}

