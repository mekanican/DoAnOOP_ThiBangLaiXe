// #include <experimental/filesystem>
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include "User.h"
#include "QuestionPack.h"

using namespace std;

void loginTest(){
  User userA;
  userA.login("hello123", "123456");
  userA.login("ahihi", "123456");
  userA.regis("ahihi", "123456");
  userA.login("ahihi", "123456");
  userA.regis("ahihi", "123456");
}

void proxyTest(){
  DatabaseClientQuestion *service = new DatabaseClientQuestion("A1");
  ProxyDataQuestion proxyService(service);
  proxyService.read();
}

int main() {

  // QuestionPack test;
  // srand((unsigned int)time(0));

  // test.loadMockTest();
  // test.startTest();

  // return 0;
}
