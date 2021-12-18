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
class DatabaseQuestionInterface{
public:
  virtual void read() = 0;
};

class DatabaseClientQuestion : public DatabaseQuestionInterface {
  string m_type;
  vector<Question> topic[7];

 public:
  explicit DatabaseClientQuestion(string type) : m_type(type) {}
  string getType(){ return m_type; }
  void read();

//  friend int main();
  friend class Question;
  friend class QuestionPack;

  // vector<Question> read() {  // also known as query
  //     std::filesystem::path path{ BASE_DIR + m_type};
  //     vector<Question> res;
  //     for (auto& p : std::filesystem::recursive_directory_iterator(path)) {
  //        string realPath = p.path().string();
  //        // Do something to file (also parse the path to get topic and required, use string::find())
  //        std::cout << realPath << endl;
         
  //     }
  //     return res;
  // }
};
#endif


class ProxyDataQuestion : public DatabaseQuestionInterface{
private:
  DatabaseClientQuestion *m_service;
  vector<string> m_cachedType;
public:
  ProxyDataQuestion(DatabaseClientQuestion * service){
    m_service = service;
  }
  
  ~ProxyDataQuestion(){
    delete m_service;
  }

  void read(){
    string type = m_service->getType();
    if(find(m_cachedType.begin(), m_cachedType.end(), type) == m_cachedType.end()){
      m_cachedType.push_back(type);
      m_service->read();
    }
  }
};