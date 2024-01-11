#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QUrl>
#include <QJsonParseError>
#include <QJsonObject>

#include "Connector.h"

void Connector::connect()
{

    QNetworkAccessManager* manager = new QNetworkAccessManager(this);
    QObject::connect(manager, &QNetworkAccessManager::finished,
        this, &Connector::updateWebData);
    auto request = QNetworkRequest{ QUrl("http://jsonplaceholder.typicode.com/users/1") };
    auto reply = manager->get(request);
    QObject::connect(reply, &QNetworkReply::finished, this, &QObject::deleteLater);
    qDebug() << QString(reply->readAll());
}

void Connector::updateWebData(QNetworkReply* reply)
{

    qDebug() << "request sended";
    auto jsonObj = serializeData(reply->readAll());
    if (jsonObj.isEmpty())
        return;
    else {
        qDebug() << jsonObj;
    }

}

QJsonObject Connector::serializeData(const QByteArray& rawData)
{
    if (rawData.isEmpty())
        return{};
    auto parseError = new QJsonParseError();
    auto doc = QJsonDocument::fromJson(rawData, parseError);
    return doc.object();
}
