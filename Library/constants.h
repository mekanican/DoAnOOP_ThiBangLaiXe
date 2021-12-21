#ifndef CONSTANTS_H_
#define CONSTANTS_H_
#include <string>
#include <vector>
using namespace std;

enum class Type { A1, A2, A3, A4, B1, B2, C, D, E, F };
const vector<string> Types = {"A1", "A2", "A3", "A4", "B1",
                              "B2", "C",  "D",  "E",  "F"};
                        
enum class Topic {
  KHAI_NIEM_VA_QUY_TAC,
  NGHIEP_VU_VAN_TAI,
  VAN_HOA_DAO_DUC,
  KY_THUAT_LAI_XE,
  CAU_TAO_SUA_CHUA,
  BIEN_BAO_DUONG_BO,
  SA_HINH
};

const vector<string> Topics = {"KHAI_NIEM_VA_QUY_TAC",
                               "NGHIEP_VU_VAN_TAI",
                               "VAN_HOA_DAO_DUC",
                               "KY_THUAT_LAI_XE",
                               "CAU_TAO_SUA_CHUA",
                               "BIEN_BAO_DUONG_BO",
                               "SA_HINH"};
const string TOPIC[] = {
    "Bien_Bao_Va_Duong_Bo", "Khai_Niem_Va_Quy_Tac_Giao_Thong",
    "Ky_Thuat_Lai_Xe",      "Sa_Hinh",
    "Van_Hoa_Va_Dao_Duc",   "Cau_Tao_Va_Sua_Chua",
    "Nghiep_Vu_Van_Tai"};

const string REQUIRED[] = {"Liet", "BinhThuong"};

const string kScoreStringSeparator = ";;;";
const int kScoreboardMaxSize = 100;
const string kScoreboardFolder = "UserData/scoreboard/";
const string kScoreboardFileName = "scores.txt";
const int kScoreboardPageSize = 5;


#endif 
