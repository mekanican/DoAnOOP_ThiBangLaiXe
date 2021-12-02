#pragma once
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