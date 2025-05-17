#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "mycustompointcloud.h"

int main(int argc, char *argv[])
{
    // High DPI scaling is enabled by default in Qt 6
    // QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling); // Removed in Qt 6

    QGuiApplication app(argc, argv);

    qmlRegisterType<MyCustomPointCloud>("Example", 1, 0, "CustomGeometry");

    QQmlApplicationEngine engine;
    const QUrl url(u"qrc:/main.qml"_qs);
    
    // New style connect syntax for objectCreated in Qt 6
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreationFailed,
                     &app, [url](const QUrl &objUrl) {
        if (url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    
    engine.load(url);

    return app.exec();
}
