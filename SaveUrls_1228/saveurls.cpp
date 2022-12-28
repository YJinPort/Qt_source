#include "saveurls.h"
#include <QStringList>
#include <QSettings>

SaveUrls::SaveUrls()
{
    qDebug("SaveUrls");
}

/*QSettings 클래스를 이용해서 저장*/
void SaveUrls::save(QStringList urlList) {
    QSettings settings("rssFeeds.ini", QSettings::IniFormat);
    settings.beginWriteArray("rssFeeds");
    settings.remove("");
    for(int i = 0; i < urlList.count(); i++) {
        settings.setArrayIndex(i);
        settings.setValue("url", urlList.at(i));
    }
    settings.endArray();
}

/*QSettings 클래스를 이용해서 불러오기*/
QStringList SaveUrls::load() {
    QStringList urlList;
    QSettings settings("rssFeeds.ini", QSettings::IniFormat);
    int size = settings.beginReadArray("rssFeeds");

    /*저장된 RSS 데이터를 QStringList에 저장*/
    for(int i = 0; i < size; i++) {
        settings.setArrayIndex(i);
        QString url = settings.value("url").toString();
        urlList.append(url);
    }
    settings.endArray();

    return urlList;
}
