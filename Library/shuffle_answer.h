#pragma once

#include "question_filter.h"

class ShuffleAnswer : public QuestionFilter {
 public:
  void handle(vector<Question> &) override;
};
