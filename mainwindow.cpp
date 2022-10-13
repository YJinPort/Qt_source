#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "clientmanager.h"
#include "productmanager.h"
#include "shoppingmanager.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    shoppingManager = new ShoppingManager(this);
    clientManager = new ClientManager(this);
    productManager = new ProductManager(this);

    ui->mdiArea->addSubWindow(shoppingManager);
    ui->mdiArea->addSubWindow(clientManager);
    ui->mdiArea->addSubWindow(productManager);
    shoppingManager->showMaximized();

    connect(shoppingManager, SIGNAL(newClient()), this, SLOT(openClientWindow()));
    connect(shoppingManager, SIGNAL(onlyStaff()), this, SLOT(openProductWindow()));
    connect(shoppingManager, SIGNAL(exitShopping()), this, SLOT(close()));

    connect(clientManager, SIGNAL(cancellation()), this, SLOT(cancellationClient()));
    connect(clientManager, SIGNAL(join()), this, SLOT(joinClient()));

    connect(productManager, SIGNAL(quitProduct()), this, SLOT(quitProductWindow()));
}

void MainWindow::openClientWindow() {
    clientManager->setFocus();
    subWindow = ui->mdiArea->currentSubWindow();
}

void MainWindow::joinClient() {
    shoppingManager->setFocus();
}

void MainWindow::cancellationClient() {
    shoppingManager->setFocus();
}

void MainWindow::openProductWindow() {
    productManager->setFocus();
}

void MainWindow::quitProductWindow() {
    shoppingManager->setFocus();
}

MainWindow::~MainWindow()
{
    delete ui;
}
