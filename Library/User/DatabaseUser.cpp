#include "DatabaseUser.h"

#include <fstream>
#include <iostream>
#include <sstream>

#include "../Utility/Tokenizer.h"
#define USER_LOCATION "UserDatabase.txt"

void DatabaseUser::create() {
  string file_name = USER_LOCATION;
  ofstream fo(file_name);
  if (!fo.is_open()) {
    cout << "Fail to open!\n";
    return;
  }
  fo << "User Database" << std::endl;
  fo.close();
}

vector<string> DatabaseUser::read() {
  string file_name = USER_LOCATION;
  ifstream fi(file_name);
  vector<string> userInfo;
  if (!fi.is_open()) {
    cout << "Fail to open!\n";
    return userInfo;
  }
  string buffer;
  while (true) {
    getline(fi, buffer);
    userInfo.push_back(buffer);
    if (fi.eof()) break;
  }
  fi.close();
  return userInfo;
}

void DatabaseUser::update(string info) {
  fstream out;
  out.open(USER_LOCATION, ios::app);
  if (!out.is_open()) return;
  out << endl << info;
  out.close();
}

vector<User> DatabaseUser::toVUser(vector<string> users) {
  // tui khong hieu string o day la gi, tui ngam hieu la data user nhe.
  vector<User> res;
  for (auto i : users) {
    vector<string> info = Tokenizer::parse(i, ";");
    User user(info[0], info[1]);
    res.push_back(user);
  }
  return res;
}

string DatabaseUser::fromUser(User user) {
  return user.Username() + ";" + user.Password();
}
