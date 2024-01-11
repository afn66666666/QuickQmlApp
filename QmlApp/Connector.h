#pragma once
#include <QObject>

class QNetworkReply;
class QJsonObject;
class QByteArray;

class Connector : public QObject
{
public:
	void connect();
	void updateWebData(QNetworkReply* reply);
	QJsonObject serializeData(const QByteArray& rawData);
};

