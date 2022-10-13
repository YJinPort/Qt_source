#include "clientmanager.h"
#include "ui_clientmanager.h"
#include "client.h"
#include <QErrorMessage>

ClientManager::ClientManager(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ClientManager)
{
    ui->setupUi(this);
}

ClientManager::~ClientManager()
{
    delete ui;
}

int ClientManager::userCount() {
    if(clientList.size() == 0) return 1;
    else {
        auto cnt = clientList.lastKey();
        return ++cnt;
    }
}

//등록 취소
void ClientManager::on_pushButton_2_clicked()
{
    ui->checkBox->setChecked(false);
    ui->checkBox_2->setChecked(false);
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();
    emit cancellation();
}

//회원 등록
void ClientManager::on_pushButton_clicked()
{
    QErrorMessage *errorMessage = new QErrorMessage(this);
    if(ui->lineEdit->text().trimmed() == "") {
        qDebug("아이디를 입력하여 주세요.");
        errorMessage->showMessage("아이디를 입력하여 주세요.");
    }
    else if(ui->lineEdit_2->text().trimmed() == "") {
        qDebug("성함을 입력하여 주세요.");
        errorMessage->showMessage("성함을 입력하여 주세요.");
    }
    else if(ui->lineEdit_4->text().trimmed() == "") {
        qDebug("주소를 입력하여 주세요.");
        errorMessage->showMessage("주소를 입력하여 주세요.");
    }
    else if(ui->checkBox->isChecked() == false || ui->checkBox_2->isChecked() == false) {
        qDebug("정보 수집을 동의해주세요.");
        errorMessage->showMessage("정보 수집을 동의해주세요.");
    }
    else {
        QString userId, name, call, address, gender;
        int ucnt = userCount();
        userId = ui->lineEdit->text();
        name = ui->lineEdit_2->text();
        call = ui->lineEdit_3->text();
        address = ui->lineEdit_4->text();
        gender = ui->comboBox->currentText();

//        if(userId.length()) {
//            Client *c = new Client(ucnt, userId, name, call, address, gender);
//            clientList.insert(ucnt, c);
//        }
        qDebug() << "회원 수: " << ucnt;
        qDebug() << "아이디: " << userId;
        qDebug() << "이름: " << name;
        qDebug() << "전화번호: " << call;
        qDebug() << "주소: " << address;
        qDebug() << "성별: " << gender;

        ui->checkBox->setChecked(false);
        ui->checkBox_2->setChecked(false);
        ui->lineEdit->clear();
        ui->lineEdit_2->clear();
        ui->lineEdit_3->clear();
        ui->lineEdit_4->clear();
        emit join();
    }
    //errorMessage->exec();
}

