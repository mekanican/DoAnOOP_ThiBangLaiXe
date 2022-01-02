// #include <experimental/filesystem>
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include "User.h"
#include "QuestionPack.h"

using namespace std;

// void loginTest(){
//   User userA;
//   userA.login("hello123", "123456");
//   userA.login("ahihi", "123456");
//   userA.regis("ahihi", "123456");
//   userA.login("ahihi", "123456");
//   userA.regis("ahihi", "123456");
// }

int main() {
  // DatabaseClientQuestion database("A1");
  // database.read();
  // database.show();
  QuestionPack test;
  // srand((unsigned int)time(0));

  test.loadPractice(Topic::KHAI_NIEM_VA_QUY_TAC);
  //test.loadMockTest();
  test.startTest();

  // return 0;
}
