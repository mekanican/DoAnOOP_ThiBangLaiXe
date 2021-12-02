#pragma once
#include "Question.h"
#include "Score.h"

class Mode{
private:
    QuestionPack m_questionPack;
    Score m_score;
public:
    Score getResult(){}
    void load();
    void run();
};