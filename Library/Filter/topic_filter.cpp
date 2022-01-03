#include "topic_filter.h"

#include <vector>

#include "../Utility/utility.h"
#include "topic_data.h"

void TopicFilter::handle(vector<Question>* data) {
  if (data == nullptr) return;

  int _type = idParser(data[0][0].getID()).first;

  ExamComponents ec = types[_type];

  bool haveRequired = false;
  for (int i = 0; i < 7; i++) {
    for (int j = 0; j < ec.topicCount[i]; j++) {
      if (data[i][j].required()) haveRequired = true;
    }
  }
  if (haveRequired)
    ec.topicCount[0]++;
  else
    for (int j = ec.topicCount[0]; j < (int)data[0].size(); j++) {
      if (data[0][j].required()) {
        swap(data[0][j], data[0][ec.topicCount[0]]);
        ec.topicCount[0]++;
        break;
      }
    }
  for (int i = 0; i < 7; i++) {
    data[i].resize(ec.topicCount[i]);
  }
}
