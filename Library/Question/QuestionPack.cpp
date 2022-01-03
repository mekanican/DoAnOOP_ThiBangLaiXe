#include "QuestionPack.h"

#include "../Filter/fifty_fifty.h"
// #include "../Filter/filter.h"
#include "../Filter/question_filter.h"
#include "../Filter/shuffle_answer.h"
#include "../Filter/shuffle_question.h"
#include "../Filter/topic_filter.h"

// class QuestionPack
QuestionPack::QuestionPack() : m_typeDB(Type::A1), m_correctAnswers(0) {
  m_currentIndex = 0;
  m_typeDB.read();
}
QuestionPack::QuestionPack(Type type) : m_typeDB(type), m_correctAnswers(0) {
  this->m_typeDB.read();
  m_currentIndex = 0;
}
QuestionPack::QuestionPack(Type type, vector<Question> questions)
    : m_typeDB(type), m_correctAnswers(0) {
  m_type = type;
  m_questions = questions;
  m_currentIndex = 0;
}

QuestionPack::~QuestionPack() {}

void QuestionPack::changeType(Type t) {
  m_typeDB.reload(t);
  // Reset everything
  m_type = t;
  m_correctAnswers = 0;
  m_currentIndex = 0;
}

void QuestionPack::goNext() {
  m_currentIndex = min((int)m_questions.size() - 1, m_currentIndex + 1);
}

void QuestionPack::goPrev() { m_currentIndex = max(0, m_currentIndex - 1); }

Question& QuestionPack::getCurrentQuestion() {
  return m_questions[m_currentIndex];
}

void QuestionPack::setSavedAnswer(int value) {
  m_savedAnswers[m_currentIndex] = value;
}

int QuestionPack::getSavedAnswer() { return m_savedAnswers[m_currentIndex]; }
// Need processed input from other class

int QuestionPack::evaluateScore() {
  int count = 0;
  for (int i = 0; i < (int)m_savedAnswers.size(); i++) {
    if (m_savedAnswers[i] == 0) continue;
    if (m_questions[i].checkAnswer(m_savedAnswers[i] - 1)) {
      count++;
    }
  }
  return count;
}

void QuestionPack::loadMockTest() {
  DatabaseQuestion db(m_typeDB);
  QuestionFilter* qf = QuestionFilter::createChainTest();
  m_questions.clear();
  m_savedAnswers.clear();
  qf->process(db.getTopics());
  for (int i = 0; i < 7; i++) {
    for (auto& j : db.getTopics()[i]) {
      m_questions.push_back(j);
    }
  }
  m_savedAnswers.resize(m_questions.size());
}

void QuestionPack::loadPractice(bool fifty, bool sQues, bool sAnsw, bool t1,
                                bool t2, bool t3, bool t4, bool t5, bool t6,
                                bool t7) {
  DatabaseQuestion db(m_typeDB);
  QuestionFilter* qf = QuestionFilter::createChainPractice(fifty, sQues, sAnsw);
  m_questions.clear();
  m_savedAnswers.clear();
  if (qf) qf->process(db.getTopics());

  if (t1)
    for (auto& q : db.getTopics()[0]) {
      m_questions.push_back(q);
    }
  if (t2)
    for (auto& q : db.getTopics()[1]) {
      m_questions.push_back(q);
    }
  if (t3)
    for (auto& q : db.getTopics()[2]) {
      m_questions.push_back(q);
    }
  if (t4)
    for (auto& q : db.getTopics()[3]) {
      m_questions.push_back(q);
    }
  if (t5)
    for (auto& q : db.getTopics()[4]) {
      m_questions.push_back(q);
    }
  if (t6)
    for (auto& q : db.getTopics()[5]) {
      m_questions.push_back(q);
    }
  if (t7)
    for (auto& q : db.getTopics()[6]) {
      m_questions.push_back(q);
    }
  m_savedAnswers.resize(m_questions.size());
  delete qf;
  return;
}
