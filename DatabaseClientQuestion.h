#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <filesystem>
#include "Question.h"

using std::string;
using std::vector;

char const* BASE_DIR = "data";

char const* TOPIC[] = {
    "Bien_Bao_Va_Duong_Bo", "Khai_Niem_Va_Quy_Tac_Giao_Thong",
    "Ky_Thuat_Lai_Xe",      "Sa_Hinh",
    "Van_Hoa_Va_Dao_Duc",   "Cau_Tao_Va_Sua_Chua",
    "Nghiep_Vu_Van_Tai"};

char const* REQUIRED[] = {"Liet", "BinhThuong"};

class DatabaseClientQuestion {
  string m_type;

 public:
  explicit DatabaseClientQuestion(string type) : m_type(type) {}


  vector<Question> read() {  // also known as query
      std::filesystem::path path{ BASE_DIR + m_type};
      for (auto& p : std::filesystem::recursive_directory_iterator(path)) {
         string realPath = p.path().string();
         // Do something to file (also parse the path to get topic and required, use string::find())
         std::cout << realPath << endl;
         
      }
  }
};
