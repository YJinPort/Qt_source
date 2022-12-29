#include <QCoreApplication>
#include <QDebug>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>

void sendRequest();

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    sendRequest();
    return a.exec();
}

void sendRequest() {
    //스택 위의 임시 이벤트 루프(event loop)
    QEventLoop eventLoop;

    //"finished()"가 불려지면 이벤트 루프를 종료("quit()")
    QNetworkAccessManager mgr;
    QObject::connect(&mgr, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));

    //HTTP 요청
    //QNetworkRequest req(QUrl(QString("http://time.jsontest.com/")));
    QNetworkRequest req(QUrl(QString("https://jsonplaceholder.typicode.com/posts/1/comments")));
    QNetworkReply* reply = mgr.get(req);
    eventLoop.exec();

    if(reply->error() == QNetworkReply::NoError) {
        QString strReply = (QString)reply->readAll();
        //Json 파싱
        qDebug() << "Response: " << strReply;
        QJsonDocument jsonResponse = QJsonDocument::fromJson(strReply.toUtf8());
        /*QJsonObject jsonObj = jsonResponse.object();
        qDebug() << "Time: " << jsonObj["time"].toString();
        qDebug() << "Date: " << jsonObj["date"].toString();*/
        QJsonArray jsonArr = jsonResponse.array();
        for(int i = 0; i < jsonArr.size(); i++) {
            QJsonObject jsonObj = jsonArr.at(i).toObject();    //jsonResponse.object();
#if 0
            foreach(const QString& key, jsonObj.keys()) {
                QJsonValue value = jsonObj.value(key);
                qDebug() << "Key = " << key << ", Value = " << value.toString();
            }
#else
            qDebug() << "postId:" << jsonObj["postId"].toInt();
            qDebug() << "id:" << jsonObj["id"].toInt();
            qDebug() << "name:" << jsonObj["name"].toString();
            qDebug() << "email:" << jsonObj["email"].toString();
            qDebug() << "body:" << jsonObj["body"].toString();
#endif
        }

        delete reply;
    }
    else {
        qDebug() << "Failure" << reply->errorString();
        delete reply;
    }
}
