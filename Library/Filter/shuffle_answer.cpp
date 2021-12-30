#include "shuffle_answer.h"

#include "random_generator.h"

void ShuffleAnswer::handle(vector<Question>& data) {
  // Random::Init();

  for (auto& i : data) {
    int currPos = Random::getRange(0, 3);
    int nextPos = Random::getRange(0, 3);

    // Swaping
    string temp = i.getAnswerText(nextPos);
    i.setAnswerText(i.getAnswerText(currPos), nextPos);
    i.setAnswerText(temp, currPos);

    // Also swaping the correct answer
    if (i.checkAnswer(currPos))
      i.setRightAnswer(nextPos);
    else if (i.checkAnswer(nextPos))
      i.setRightAnswer(currPos);
  }
}
