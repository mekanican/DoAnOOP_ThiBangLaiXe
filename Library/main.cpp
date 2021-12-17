// #include <experimental/filesystem>
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include "User.h"
//#include "QuestionPack.h"

using namespace std;

int main() {
  User userA;
  userA.login("hello123", "123456");
  userA.login("ahihi", "123456");
  userA.regis("ahihi", "123456");
  userA.login("ahihi", "123456");
  userA.regis("ahihi", "123456");
  // QuestionPack test;
  // srand((unsigned int)time(0));

  // test.loadMockTest();
  // test.startTest();

  // return 0;
}
