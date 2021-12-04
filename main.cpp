
// #include <experimental/filesystem>
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

#include "QuestionPack.h"

using namespace std;

int main() {
<<<<<<< Updated upstream
  QuestionPack test;
  srand((unsigned int)time(0));

  test.loadMockTest();
  test.startTest();

  return 0;
=======
  //SetConsoleCP(CP_UTF8);
  DatabaseClientQuestion questionDB("A1");
  vector<Question> quesA1 = questionDB.read();
  cout << quesA1[0].m_id << endl
       << quesA1[0].m_questionText << endl
       << quesA1[0].m_answerTexts[quesA1[0].m_rightAnswer] << endl;

  return 0;
  /*
  Question res = QuestionLoader::Load("data/A1/Bien_Bao_Va_Duong_Bo/BinhThuong/Cau_100.txt",
                       false);
  cout << res.m_id << endl
       << res.m_questionText << endl
       << res.m_answerTexts[res.m_rightAnswer] << endl;
  */
>>>>>>> Stashed changes
}