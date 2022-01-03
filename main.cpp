#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickStyle>

#include "backend.h"

int main(int argc, char *argv[]) {
  srand(time(0));
  QGuiApplication app(argc, argv);

  qmlRegisterType<BackEnd>("io.qt.examples.backend", 1, 0, "BackEnd");

  QQmlApplicationEngine engine;
  QQuickStyle::setStyle("Material");
  engine.load(QUrl(QStringLiteral("qrc:/main.qml")));  // main.qml

  return app.exec();
}
