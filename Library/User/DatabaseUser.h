#pragma once
#include <vector>

#include "User.h"
using std::vector;

class DatabaseUser {
 public:
  void create();
  void update(string);
  vector<string> read();
  static vector<User> toVUser(vector<string>);
  static string fromUser(User);
};
