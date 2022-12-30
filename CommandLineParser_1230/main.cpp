#include "mainwindow.h"
#include <QCommandLineParser>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    w.resize(1280, 720);

    QCommandLineParser parser;
    // -h (help)옵션을 추가
    parser.addHelpOption( );
    // 짧은 이름(-s)을 가진 bool 옵션 추가
    QCommandLineOption showWindowOption("s",                                                  QCoreApplication::translate("main", "Show Window"));
    parser.addOption(showWindowOption);
    // 여러 이름을(-f, —force)가진 bool 옵션 추가.
    QCommandLineOption forceOption(QStringList() << "f" << "force",
            QCoreApplication::translate("main", "Overwrite existing files."));
    parser.addOption(forceOption);

    // 실제 명령 줄 인수 처리
    parser.process(a);
    if(parser.isSet(showWindowOption))  /* 옵션(-s)이 포함되면 윈도우를 보여준다. */

    w.show();
    return a.exec();
}
