#include "QuestionPack.h"

// class QuestionPack
QuestionPack::QuestionPack() : type_db("A1"), m_correctAnswers(0) {
  m_currentIndex = 0;
  type_db.read();
}
QuestionPack::QuestionPack(Type type)
    : type_db(Types[(int)type]), m_correctAnswers(0) {
  this->type_db.read();
}
QuestionPack::QuestionPack(Type type, vector<Question> questions)
    : type_db(Types[(int)type]), m_correctAnswers(0) {
  m_type = type;
  m_questions = questions;
}

void QuestionPack::goNext()
{
    m_currentIndex = min((int)m_questions.size() - 1, m_currentIndex + 1);
}

void QuestionPack::goPrev()
{
    m_currentIndex = max(0, m_currentIndex - 1);
}

Question& QuestionPack::getCurrentQuestion()
{
    return m_questions[m_currentIndex];
}

void QuestionPack::setSavedAnswer(int value)
{
    m_savedAnswers[m_currentIndex] = value;
}

int QuestionPack::getSavedAnswer()
{
    return m_savedAnswers[m_currentIndex];
}
// Need processed input from other class

int QuestionPack::evaluateScore() {
    int count = 0;
    for(int i = 0; i < (int)m_savedAnswers.size(); i++) {
        if(m_savedAnswers[i] == 0) continue;
        if(m_questions[i].checkAnswer(m_savedAnswers[i] - 1)) {
            count++;
        }
    }
    return count;
}

void QuestionPack::loadMockTest() {
   m_savedAnswers.resize(7);
  // randomize question
  for (int i = 0; i < 7; i++) {
    int tmp = rand();

    if (int tmp2 = this->type_db.topic[i].size() && tmp2 != 0) tmp %= tmp2;
    else
      continue;

    this->m_questions.push_back(this->type_db.topic[i][tmp]);
  }
}

void QuestionPack::startTest() {
  for (int i = 0; i < (int)this->m_questions.size(); i++) {
    int tmp;

    cout << "Q" << i+1 << ":\t" << this->m_questions[i].m_questionText << endl;
    for (int x = 0; x < (int)this->m_questions[i].m_answerTexts.size(); x++)
      cout << x << ".\t"  << this->m_questions[i].m_answerTexts[x] << "\n";
    cout << "Nhap cau tra loi (0-4): ";

    cin >> tmp;
    this->m_savedAnswers.push_back(tmp);
    if (tmp == this->m_questions[i].m_rightAnswer) this->m_correctAnswers++;
  }

  cout << "Tong diem cua ban: " << this->m_correctAnswers << "/" << this->m_questions.size() << endl;
}

void QuestionPack::loadPractice(Topic topic) {
  int index = static_cast<int>(topic);
  for(auto i : type_db.topic[index]){
    cout << "e";
    m_questions.push_back(i);
  }
}