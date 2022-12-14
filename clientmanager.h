#ifndef CLIENTMANAGER_H
#define CLIENTMANAGER_H

#include <QWidget>

class Client;

namespace Ui {
class ClientManager;
}

class ClientManager : public QWidget
{
    Q_OBJECT

public:
    explicit ClientManager(QWidget *parent = nullptr);
    ~ClientManager();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::ClientManager *ui;

    int userCount();
    QMap<int, Client*> clientList;

signals:
    void cancellation();
    void join();
};

#endif // CLIENTMANAGER_H
