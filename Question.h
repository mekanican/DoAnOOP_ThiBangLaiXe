#pragma once
#include "constants.h"

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
                                 // Su dung enumerate Topic o day
 public:
  Question();  // Mac dinh co 4 phan tu cho vector
  Question(int id, string questionText, string imagePath,
           vector<string> answerTexts, int rightAnswer, string tip,
           bool isRequired);
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
  void setRightAnswer(int rightAnswer);        // setter m_rightAnswer;
  void setTip(string const& tip);              // setter m_tip
  void setRequired(bool isRequired);           // setter required;
  void setImagePath(string const& imagePath);  // setter m_imagePath
  friend int main();
  friend class QuestionPack;
};
