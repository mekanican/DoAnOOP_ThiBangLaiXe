#include "question_filter.h"

QuestionFilter::QuestionFilter() { m_nextFilter = nullptr; }
QuestionFilter::~QuestionFilter() { delete m_nextFilter; }

void QuestionFilter::process(vector<Question>& data) {
  handle(data);
  if (m_nextFilter) m_nextFilter->handle(data);
}

Filter* QuestionFilter::setNext(Filter* next) {
  m_nextFilter = next;
  return m_nextFilter;
}

void QuestionFilter::handle(vector<Question>&) {}
