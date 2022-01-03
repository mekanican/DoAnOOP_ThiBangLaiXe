#include "shuffle_question.h"

#include <utility>

#include "random_generator.h"

void ShuffleQuestion::handle(vector<Question>* data) {
  // Random::Init();

  for (int i = 0; i < 7; i++) {
    for (int j = 0; j < (int)data[i].size(); j++) {
      int pos = Random::getRange(0, data[i].size() - 1);
      std::swap(data[i][j], data[i][pos]);
    }
  }
}
