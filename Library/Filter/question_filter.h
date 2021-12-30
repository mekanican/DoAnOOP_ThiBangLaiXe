#pragma once
#include "filter.h"

class QuestionFilter : public Filter {
 private:
  Filter *m_nextFilter;

 public:
  QuestionFilter();
  ~QuestionFilter();
  void process(vector<Question>&);
  Filter *setNext(Filter *) override;
  void handle(vector<Question> &) override;
};
