#ifndef CONSTANTS_H_
#define CONSTANTS_H_
#include <string>
#include <vector>
using namespace std;

enum class Type { A1 = 9, A2 = 10, A3 = 11, A4 = 12, B1 = 13, B2 = 14, C = 15, D = 16, E = 17, F = 18 };
const vector<string> Types = {"A1", "A2", "A3", "A4", "B1",
                              "B2", "C",  "D",  "E",  "F"};
                        
enum class Topic {
  KHAI_NIEM_VA_QUY_TAC,
  NGHIEP_VU_VAN_TAI,
  VAN_HOA_DAO_DUC,
  KY_THUAT_LAI_XE,
  CAU_TAO_SUA_CHUA,
  BIEN_BAO_DUONG_BO,
  SA_HINH,
  TAP_LUYEN
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

#endif 
