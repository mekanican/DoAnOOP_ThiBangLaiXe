#pragma once

#include "question_filter.h"

class TopicFilter : public QuestionFilter {
 public:
  void handle(vector<Question> *) override;
};
