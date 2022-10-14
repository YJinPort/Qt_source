#include "productmanager.h"
#include "ui_productmanager.h"
#include "product.h"
#include "client.h"
#include <QErrorMessage>
#include <QFile>

ProductManager::ProductManager(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ProductManager)
{
    ui->setupUi(this);

    QFile file("productlist.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QList<QString> row = line.split(", ");
        if(row.size()) {
            int number = row[0].toInt();
            int price = row[2].toInt();
            int count = row[3].toInt();
            Product* p = new Product(number, row[1], price, count, row[4]);
            ui->treeWidget->addTopLevelItem(p);
            productList.insert(number, p);
        }
    }
    file.close();

    //해결해야함
//    QFile file2("clientlist.txt");
//    if (!file2.open(QIODevice::ReadOnly | QIODevice::Text))
//        return;

//    QTextStream in2(&file2);
//    while (!in2.atEnd()) {
//        QString line = in2.readLine();
//        QList<QString> row = line.split(", ");
//        if(row.size()) {
//            int count = row[0].toInt();
//            Client* c = new Client(count, row[1], row[2], row[3], row[4], row[5]);
//            ui->treeWidget_2->addTopLevelItem(c);
//        }
//    }
//    file2.close( );
}

ProductManager::~ProductManager()
{
    delete ui;

    QFile file("productlist.txt");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return;

    QTextStream out(&file);
    for (const auto& v : productList) {
        Product* p = v;
        out << p->getProNumber() << ", " << p->getProName() << ", ";
        out << p->getProPrice() << ", ";
        out << p->getProCount() << ", ";
        out << p->getProType() << "\n";
    }
    file.close( );
}

//제품 등록
void ProductManager::on_pushButton_clicked()
{
    QErrorMessage *errorMessage = new QErrorMessage(this);
    if(ui->lineEdit->text().trimmed() == "") errorMessage->showMessage("제품 번호를 입력하여 주세요.");
    else if(ui->lineEdit_2->text().trimmed() == "") errorMessage->showMessage("제품 이름를 입력하여 주세요.");
    else if(ui->lineEdit_3->text().trimmed() == "") errorMessage->showMessage("제품 가격를 입력하여 주세요.");
    else if(ui->lineEdit_4->text().trimmed() == "") errorMessage->showMessage("제품 수량를 입력하여 주세요.");
    else {
        int proNumber, proPrice, proCount;
        QString proName, proType;

        proNumber = ui->lineEdit->text().toInt();
        proName = ui->lineEdit_2->text();
        proPrice = ui->lineEdit_3->text().toInt();
        proCount = ui->lineEdit_4->text().toInt();
        proType = ui->lineEdit_5->text();

        if(proName.length()) {
            Product *p = new Product(proNumber, proName, proPrice, proCount, proType);
            productList.insert(proNumber, p);
            ui->treeWidget->addTopLevelItem(p);
        }
        qDebug() << "제품 번호: " << proNumber;
        qDebug() << "제품명: " << proName;
        qDebug() << "가격: " << proPrice;
        qDebug() << "수량: " << proCount;
        qDebug() << "종류: " << proType;

        ui->lineEdit->clear();
        ui->lineEdit_2->clear();
        ui->lineEdit_3->clear();
        ui->lineEdit_4->clear();
        ui->lineEdit_5->clear();
    }

    //errorMessage->exec();
}

//나가기
void ProductManager::on_pushButton_2_clicked()
{
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();
    ui->lineEdit_5->clear();

    emit quitProduct();
}

