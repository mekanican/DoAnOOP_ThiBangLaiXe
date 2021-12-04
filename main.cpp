
// #include <experimental/filesystem>
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

#include "QuestionPack.h"

using namespace std;

int main() {
  QuestionPack test;
  srand((unsigned int)time(0));

  test.loadMockTest();
  test.startTest();

  return 0;
}