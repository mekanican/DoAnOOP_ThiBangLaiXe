#include <sqlite3.h>

#include <string>
#include <vector>
using std::string;
using std::vector;

class Question {
 private:
  int m_id;                      // ID trong database (Tien cho viec update)
  string m_questionText;         // Cau Hoi
  string m_imagePath;            // Duong dan den anh
  vector<string> m_answerTexts;  // Danh sach cau tra loi
  int m_rightAnswer;             // Thu tu cau tra loi dung (bat dau tu 0)
  string m_tip;                  // Goi y
  bool m_isRequired;             // Co phai cau liet
 public:
  Question();  // Mac dinh co 4 phan tu cho vector
  Question(int m_id, string questionText, vector<string> answerTexts,
           int rightAnswer, string tip, bool isRequired);
  // Default copy constructor & no need Destructor

  bool required();               // Co phai cau liet (getter cho m_isRequired)
  bool checkAnswer(int choice);  // Kiem tra dap an dung

  string getQuestionText();         // Lay cau hoi
  string getAnswerText(int index);  // Lay cau tra loi vi tri index
  string getTip();                  // Lay goi y
  string getImagePath();            // Lay duong dan

  void setQuestionText(string const& questionText);  // setter m_questionText;
  void setAnswerText(string const& answerText,
                     int index);               // setter m_answerTexts
  void setRightAnswer(int rightAnswer);       // setter m_rightAnswer;
  void setTip(string const& tip);              // setter m_tip
  void setRequired(bool isRequired);           // setter required;
  void setImagePath(string const& imagePath);  // setter m_imagePath
};

enum class Type { A1, A2, A3, A4, B1, B2, C, D, E, F };
enum class Topic {
  KHAI_NIEM_VA_QUY_TAC,
  NGHIEP_VU_VAN_TAI,
  VAN_HOA_DAO_DUC,
  KY_THUAT_LAI_XE,
  CAU_TAO_SUA_CHUA,
  BIEN_BAO_DUONG_BO,
  SA_HINH
};

// using sqlite, Can mot class de quan ly cai nay
class DatabaseClient {
 private:
  const string m_location;
  sqlite3* m_db;

 public:
  DatabaseClient();  // Init with default location;
  explicit DatabaseClient(string const& location);  // Init with other location

  vector<Question> getTypeAll(Type type);  // Lay toan bo cau hoi tu loai bang
  vector<Question> getType(
      Type type, Topic topic, int count,
      bool isRequired = false);  // Lay cau hoi voi chu de va so luong

  bool updateQuestion(Question const& q);  // Cap nhat lai cau hoi vao database
  bool insertQuestion(Question const& q);  // Them cau hoi
  bool deleteQuestion(int id);             // Xoa cau hoi voi id

  ~DatabaseClient();  // Giai phong bo nho
};

class QuestionPack {
 private:
  Type m_type;
  vector<Question> m_questions;

 public:
  QuestionPack();
  QuestionPack(Type type, vector<Question> questions);
  // Need processed input from other class
  void loadExam();
  void loadAll();
};

// Khong dung ke thua cho QuestionPack nua ma chuyen sang giao dien lay de
// truyen vao
// Tam thoi bo qua proxy
