#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QDebug>
#include <QWidget>

#include "organizer.h"
#include "organizermod.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    qmlRegisterType<Organizer>("Organizer", 1,0, "Organizer");
    qmlRegisterType<Organizermod>("Organizermod", 1, 0, "Organizermod");

    const QIcon mainIcon = QIcon::fromTheme("mainIcon", QIcon(":/img/image.png"));
    app.setWindowIcon(mainIcon);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
