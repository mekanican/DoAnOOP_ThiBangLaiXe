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

class DatabaseQuestion {
  Type m_type;
  vector<Question> m_topic[7];

 public:
  explicit DatabaseQuestion(Type type) : m_type(type) {}
  ~DatabaseQuestion() {}
  Type getType() { return m_type; }
  vector<Question>* getTopics() { return m_topic; }
  void read();
  void reload(Type);
};

#endif
