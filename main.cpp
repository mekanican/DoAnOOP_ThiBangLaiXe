#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickStyle>

#include "backend.h"
#include "backendquestion.h"
//#include "Library/Score.h"
//#include "Library/User.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    qmlRegisterType<BackEnd>("io.qt.examples.backend", 1, 0, "BackEnd");
    qmlRegisterType<BackEndQuestion>("io.question", 1, 0, "BackEndQuestion");

    QQmlApplicationEngine engine;
    QQuickStyle::setStyle("Material");
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

//    Scoreboard test;
//    vector<Score> page1 = test.getPage(1);
//    vector<Score> page2 = test.getPage(2);
//    User user("username1234", "password123");
//    Scoreboard user_record = test.UserScoreboard(user);
//    vector<Score> user_page = user_record.getPage(1);


    return app.exec();
}
