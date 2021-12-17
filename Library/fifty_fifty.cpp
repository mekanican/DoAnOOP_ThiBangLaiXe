#include "fifty_fifty.h"

void FiftyFifty::handle(vector<Question>& data) {
  for (auto& i : data) {
    int correctAnswer = 0;
    for (; correctAnswer < 4; correctAnswer++)
      if (i.checkAnswer(correctAnswer)) break;
    int unCorrectAnswer = 0;
    for (; unCorrectAnswer < 4; unCorrectAnswer++)
      if (!i.checkAnswer(unCorrectAnswer)) break;

    for (int j = 0; j < 4; j++) {
      if (j != correctAnswer && j != unCorrectAnswer) {
        i.setAnswerText("", j);
      }
    }
  }
}
