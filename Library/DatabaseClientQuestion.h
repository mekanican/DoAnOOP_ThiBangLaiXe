#ifndef DB_CLIENT_QUESTION_
#define DB_CLIENT_QUESTION_
//#include <dirent.h>

// #include <experimental/filesystem>
#include <iostream>
#include <string>
#include <vector>

#include "Question.h"
#include "constants.h"

using std::string;
using std::vector;

const string BASE_DIR = "data";

// char const* TOPIC[] = {
//     "Bien_Bao_Va_Duong_Bo", "Khai_Niem_Va_Quy_Tac_Giao_Thong",
//     "Ky_Thuat_Lai_Xe",      "Sa_Hinh",
//     "Van_Hoa_Va_Dao_Duc",   "Cau_Tao_Va_Sua_Chua",
//     "Nghiep_Vu_Van_Tai"};

// char const* REQUIRED[] = {"Liet", "BinhThuong"};

class DatabaseClientQuestion{
  string m_type;
  vector<Question> topic[7];
  string m_status;
 public:
  explicit DatabaseClientQuestion(string type) : m_type(type), m_status("no data"){}
  string getType(){ return m_type; }
  string getStatus(){ return m_status; }
  void read();
  void show(){
    for(int i = 0; i < 7;i++){
      cout << topic[0][i].getQuestionText() << endl;
    }
  }

//  friend int main();
  friend class Question;
  friend class QuestionPack;
};


#endif