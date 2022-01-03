#ifndef QUESTION_PACK_H_
#define QUESTION_PACK_H_
#include "../Filter/question_filter.h"
#include "DatabaseQuestion.h"
#include "Question.h"

class QuestionPack {
 private:
  DatabaseQuestion m_typeDB;
  Type m_type;
  vector<Question> m_questions;
  vector<int> m_savedAnswers;
  int m_currentIndex;
  int m_correctAnswers;

 public:
  QuestionPack();
  QuestionPack(Type type);
  QuestionPack(Type type, vector<Question> questions);
  ~QuestionPack();

  void changeType(Type);

  void goNext();
  void goPrev();
  Question& getCurrentQuestion();

  void setSavedAnswer(int value);
  int getSavedAnswer();

  int evaluateScore();
  void loadMockTest();
  void loadPractice(bool, bool, bool, bool = true, bool = true, bool = true,
                    bool = true, bool = true, bool = true,
                    bool = true);  // Khuc nay UML ghi bool[] la duoc r
};
#endif
