#pragma once

#include <vector>

#include "../Question/Question.h"
using std::vector;

class QuestionFilter {
 private:
  QuestionFilter *m_nextFilter;

 public:
  QuestionFilter();
  QuestionFilter(QuestionFilter const &);
  virtual ~QuestionFilter();
  void process(vector<Question> *);

  static QuestionFilter *createChainPractice(bool fifty, bool sQues,
                                             bool sAnsw);
  static QuestionFilter *createChainTest();

  virtual QuestionFilter *setNext(QuestionFilter *);
  virtual void handle(vector<Question> *) = 0;
};
