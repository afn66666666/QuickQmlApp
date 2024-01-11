#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QTcpSocket>
#include <QNetworkAccessManager>

#include "Connector.h"

int main(int argc, char *argv[])
{
#if defined(Q_OS_WIN)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    //Connector connector;
    //connector.connect();

    return app.exec();
}
