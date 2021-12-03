#pragma once
#include <string>
#include <vector>
#include "Question.h"
using std::string;
using std::vector;

class DatabaseClient {
 private:
  string m_location;
  string m_userName;
 public:
  DatabaseClient();  // Init with default location;
  DatabaseClient(string);
  ~DatabaseClient();
  void creat();
  void read();
  virtual void update();
  virtual void deleteDB(int);
};