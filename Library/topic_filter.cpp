#include "topic_filter.h"

#include <vector>

#include "topic_data.h"

void TopicFilter::handle(vector<Question>& data) {
  if (data.size() == 0) return;

  auto [a, b, c] = idParser(data[0].getID());
  ExamComponents ec = types[c];
  
  int pos = 0;
  for (int i = 0; i < data.size(); i++) {
      if (ec.questionCount == 0) break;
    auto [a, b, c] = idParser(data[i].getID());
    if (b) {
      if (ec.minCorrectAnswer) {
          std::swap(data[i], data[pos]);
          ec.minCorrectAnswer--;
          ec.questionCount--;
      }
      continue;
    }
    if (ec.topicCount[a] == 0) {
      continue;
    } else {
      ec.topicCount[a]--;
      ec.questionCount--;
      std::swap(data[pos], data[i]);
    }
  }
}
