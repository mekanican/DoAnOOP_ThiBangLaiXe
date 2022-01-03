#include "shuffle_answer.h"

#include "random_generator.h"

void ShuffleAnswer::handle(vector<Question>* data) {
  // Random::Init();

  for (int i = 0; i < 7; i++) {
    for (auto& j : data[i]) {
      int currPos = Random::getRange(0, 3);
      int nextPos = Random::getRange(0, 3);
      while (currPos == nextPos || j.getAnswerText(currPos) == "" ||
             j.getAnswerText(nextPos) == "") {
        currPos = Random::getRange(0, 3);
        nextPos = Random::getRange(0, 3);
      }

      // Swaping
      string temp = j.getAnswerText(nextPos);
      j.setAnswerText(j.getAnswerText(currPos), nextPos);
      j.setAnswerText(temp, currPos);

      // Also swaping the correct answer
      if (j.checkAnswer(currPos))
        j.setRightAnswer(nextPos);
      else if (j.checkAnswer(nextPos))
        j.setRightAnswer(currPos);
    }
  }
}
