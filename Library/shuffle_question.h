#pragma once

#include "question_filter.h"

class ShuffleQuestion : public QuestionFilter {
 public:
  void handle(vector<Question> &) override;
};
