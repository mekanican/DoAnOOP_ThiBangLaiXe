#ifndef DB_CLIENT_QUESTION_
#define DB_CLIENT_QUESTION_

#include <iostream>
#include <string>
#include <vector>

#include "../Utility/constants.h"
#include "Question.h"

using std::string;
using std::vector;

const string BASE_DIR = "data";

class DatabaseQuestionInterface {
 public:
  virtual void read() = 0;
  virtual ~DatabaseQuestionInterface() {}
};

class DatabaseQuestion : public DatabaseQuestionInterface {
  string m_type;
  vector<Question> topic[7];

 public:
  explicit DatabaseQuestion(string type) : m_type(type) {}
  ~DatabaseQuestion() {}
  string getType() { return m_type; }
  void read();

  friend class Question;
  friend class QuestionPack;
};

class ProxyDataQuestion : public DatabaseQuestionInterface {
 private:
  DatabaseQuestion *m_service;
  string m_cachedType;

 public:
  ProxyDataQuestion(DatabaseQuestion *service) { m_service = service; }

  ~ProxyDataQuestion() { delete m_service; }

  void read() {
    string type = m_service->getType();
    if (m_cachedType != type) {
      m_cachedType = type;
      m_service->read();
    }
  }
};

#endif
