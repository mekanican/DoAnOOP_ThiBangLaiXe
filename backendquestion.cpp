#include "backendquestion.h"

BackEndQuestion::BackEndQuestion(QObject *parent) : QObject(parent)
{

    m_qPack = new QuestionPack();
    m_qPack->loadMockTest();
    selected = false;
//    m_c = "0";
//    m_c1 = "1";
//    m_c2 = "2";
//    m_c3 = "3";
//    m_c4 = "4";
}

BackEndQuestion::~BackEndQuestion()
{
    delete m_qPack;
}
