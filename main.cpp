#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickStyle>

#include "backend.h"
#include "backendquestion.h"
#include "Library/Score.h"
//#include "Library/User.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    qmlRegisterType<BackEnd>("io.qt.examples.backend", 1, 0, "BackEnd");
    qmlRegisterType<BackEndQuestion>("io.question", 1, 0, "BackEndQuestion");

    QQmlApplicationEngine engine;
    QQuickStyle::setStyle("Material");
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

//    ProxyScoreboard *test = new ProxyScoreboard(Type::A1);
//    vector<Score> page;
//    page = test->getPage(2);
//    page = test->getPreviousPage();
//    page = test->getNextPage();
//    page = test->getFirstPage();
//    page = test->getLastPage();

//    User user5("username5", "password5"), user10("username10", "password10"), user15("username15", "password15");
//    Score new_score(user15, 15, "1500", "1/1/2022");

//    test->remove(user5);
//    test->add(new_score);
//    test->setType(Type::A2);
//    test->remove(user10);

//    delete test;
//    Scoreboard::Add(new_score, Type::B2);


//    User user("username1234", "password123");
//    Scoreboard user_record = test.UserScoreboard(user);
//    vector<Score> user_page = user_record.getPage(1);


    return app.exec();
}
