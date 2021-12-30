#include "shuffle_question.h"

#include <utility>

#include "random_generator.h"

void ShuffleQuestion::handle(vector<Question>& data) {
  // Random::Init();

  int size = data.size();

  for (int i = 0; i < size; i++) {
    int pos = Random::getRange(0, size - 1);
    std::swap(data[i], data[pos]);
  }
}
