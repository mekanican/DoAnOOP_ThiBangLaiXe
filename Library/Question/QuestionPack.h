#ifndef QUESTION_PACK_H_
#define QUESTION_PACK_H_
#include "DatabaseQuestion.h"
#include "Question.h"

class QuestionPack {
 private:
  DatabaseQuestion type_db;
  Type m_type;
  vector<Question> m_questions;
  vector<int> m_savedAnswers;
  int m_currentIndex;
  int m_correctAnswers;

 public:
  QuestionPack();
  QuestionPack(Type type);
  QuestionPack(Type type, vector<Question> questions);
  // Need processed input from other class
  void goNext();
  void goPrev();
  Question& getCurrentQuestion();

  void setSavedAnswer(int value);
  int getSavedAnswer();

  int evaluateScore();
  void loadMockTest();
  void startTest();
  void loadPractice(Topic);
};
#endif
