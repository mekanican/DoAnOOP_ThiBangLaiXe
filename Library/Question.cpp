#include "Question.h"

#include <cstdlib>
#include <ctime>
#include <iostream>

// class Question
Question::Question() {}
Question::Question(int id, string questionText, string imagePath,
                   vector<string> answerTexts, int rightAnswer, string tip,
                   bool isRequired) {
  this->m_id = id;
  this->m_questionText = questionText;
  this->m_imagePath = imagePath;
  this->m_answerTexts = answerTexts;
  this->m_rightAnswer = rightAnswer;
  this->m_tip = tip;
  this->m_isRequired = isRequired;
}

bool Question::required() {
  return this->m_isRequired;
}  // Co phai cau liet (getter cho m_isRequired)

bool Question::checkAnswer(int choice) { return m_rightAnswer == choice; }

string Question::getQuestionText() { return m_questionText; }

string Question::getAnswerText(int index) {
  if (index >= m_answerTexts.size()) return "";
  return m_answerTexts[index];
}  // Lay cau tra loi vi tri index

string Question::getTip() { return m_tip; }  // Lay goi y

string Question::getImagePath() { return m_imagePath; }  // Lay duong dan

void Question::setQuestionText(
    string const& questionText)  // setter m_questionText;
{
  this->m_questionText = questionText;
}

void Question::setAnswerText(string const& answerText,
                             int index)  // setter m_answerTexts
{
  this->m_answerTexts[index] = answerText;
}

void Question::setRightAnswer(int rightAnswer)  // setter m_rightAnswer;
{
  this->m_rightAnswer = rightAnswer;
}

void Question::setTip(string const& tip) { m_tip = tip; }

void Question::setRequired(bool isRequired) {
  m_isRequired = isRequired;
}  // setter required;

void Question::setImagePath(string const& imagePath) {
  m_imagePath = imagePath;
}

