#pragma once
#include "../Question/Question.h"
#include "../Scoreboard/Score.h"
#include "../Question/QuestionPack.h"

class Mode {
 private:
  QuestionPack m_questionPack;
  Score m_score;

 public:
  Score getResult() {}
  void load();
  void run();
};
