#include "productmanager.h"
#include "ui_productmanager.h"
#include "product.h"
#include <QErrorMessage>

ProductManager::ProductManager(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ProductManager)
{
    ui->setupUi(this);
}

ProductManager::~ProductManager()
{
    delete ui;
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

//        if(proName.length()) {
//            Product *p = new Product(proNumber, proName, proPrice, proCount, proType);
//            productList.insert(proNumber, p);
//        }
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

