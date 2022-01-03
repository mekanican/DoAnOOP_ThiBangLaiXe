#include "question_filter.h"

#include "fifty_fifty.h"
#include "shuffle_answer.h"
#include "shuffle_question.h"
#include "topic_filter.h"

QuestionFilter::QuestionFilter() { m_nextFilter = nullptr; }

QuestionFilter::QuestionFilter(QuestionFilter const& other) {
  m_nextFilter = other.m_nextFilter;
}
QuestionFilter::~QuestionFilter() {
  // Delete chain (will be called recursively)
  delete m_nextFilter;
}

void QuestionFilter::process(vector<Question>* data) {
  handle(data);
  if (m_nextFilter) m_nextFilter->process(data);
}

QuestionFilter* QuestionFilter::createChainPractice(bool fifty, bool sQues,
                                                    bool sAnsw) {
  QuestionFilter* qf = nullptr;
  QuestionFilter* t = nullptr;
  if (fifty) {
    if (qf == nullptr) {
      qf = new FiftyFifty;
      t = qf;
    } else {
      t = t->setNext(new FiftyFifty);
    }
  }
  if (sQues) {
    if (qf == nullptr) {
      qf = new ShuffleQuestion;
      t = qf;
    } else {
      t = t->setNext(new ShuffleQuestion);
    }
  }
  if (sAnsw) {
    if (qf == nullptr) {
      qf = new ShuffleAnswer;
      t = qf;
    } else {
      t = t->setNext(new ShuffleAnswer);
    }
  }
  return qf;
}

QuestionFilter* QuestionFilter::createChainTest() {
  QuestionFilter* qf = new ShuffleQuestion;
  qf->setNext(new TopicFilter);
  return qf;
}

QuestionFilter* QuestionFilter::setNext(QuestionFilter* next) {
  m_nextFilter = next;
  return m_nextFilter;
}
