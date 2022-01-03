#pragma once
#include "question_filter.h"

class FiftyFifty : public QuestionFilter {
 public:
  void handle(vector<Question>*) override;
};
