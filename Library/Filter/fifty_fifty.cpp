#include "fifty_fifty.h"

#include <algorithm>

void FiftyFifty::handle(vector<Question>* data) {
  for (int i = 0; i < 7; i++) {
    for (auto& j : data[i]) {
      int correctAnswer = 0;
      int unCorrectAnswer = 0;

      for (int x = 0; x < 4; x++) {
        if (j.checkAnswer(x)) {
          correctAnswer = x;
        } else {
          if (j.getAnswerText(x) != "") unCorrectAnswer = x;
        }
      }

      for (int x = 0; x < 4; x++) {
        if (x == correctAnswer || x == unCorrectAnswer) continue;
        j.setAnswerText("", x);  // Delete
      }
    }
  }
}
