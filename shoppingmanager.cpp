#include "shoppingmanager.h"
#include "ui_shoppingmanager.h"
#include "clientmanager.h"
#include "productmanager.h"

#include <QInputDialog>

ShoppingManager::ShoppingManager(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ShoppingManager)
{
    ui->setupUi(this);
}

ShoppingManager::~ShoppingManager()
{
    delete ui;
}

//회원 가입
void ShoppingManager::on_pushButton_clicked()
{
    emit newClient();
}

//회원정보, 제품정보 관리
void ShoppingManager::on_pushButton_6_clicked()
{
    bool ok;
    QString passwd;

    do {
        passwd = QInputDialog::getText(this, "Manager", "관리자 번호를 입력하세요.", QLineEdit::Normal, NULL, &ok);
        if(ok == false) break;
    } while(ok != true || passwd != "ossmall");

    if(ok == true) emit onlyStaff();
}

//쇼핑 종료
void ShoppingManager::on_pushButton_7_clicked()
{
    qDebug("exit");
    emit exitShopping();
}

//로그인
void ShoppingManager::on_pushButton_2_clicked()
{
    if(ui->lineEdit->text() == "oss") {
        qDebug("로그인 성공");
        //ui->label_2->text() = ui->lineEdit->text() + "님의 주문내역";
        ui->label_2->setText(ui->lineEdit->text() + "님의 주문내역");
    }
    else qDebug("로그인 실패");
}

//주문하기
void ShoppingManager::on_pushButton_3_clicked()
{
    qDebug("주문 성공");
}

//주문 변경
void ShoppingManager::on_pushButton_5_clicked()
{
    qDebug("주문 변경");
}

//주문 취소
void ShoppingManager::on_pushButton_4_clicked()
{
    qDebug("주문 취소");
}

