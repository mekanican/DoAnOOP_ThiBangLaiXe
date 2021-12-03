#include <iostream>

#include "DatabaseClientUser.h"
int main() {
  // de test cac chuc nang cua user database
  using namespace std;
  DatabaseClientUser* userDB = new DatabaseClientUser;
  userDB->creat();
  userDB->update("\nhello123;123456");
  vector<string> info = userDB->read();
  for (size_t i = 0; i < info.size(); i++) {
    cout << info[i] << endl;
  }
  
  delete userDB;
  return 0;
}