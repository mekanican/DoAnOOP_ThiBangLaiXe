#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickStyle>

#include "backend.h"
#include "backendquestion.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    qmlRegisterType<BackEnd>("io.qt.examples.backend", 1, 0, "BackEnd");
    qmlRegisterType<BackEndQuestion>("io.question", 1, 0, "BackEndQuestion");

    QQmlApplicationEngine engine;
    QQuickStyle::setStyle("Material");
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
