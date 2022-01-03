#include "backend.h"

#include <QDebug>
#include <QDir>

#include "Library/Filter/topic_data.h"
#include "Library/Scoreboard/Score.h"
#include "Library/User/User.h"
#include "Library/Utility/utility.h"

BackEnd::BackEnd(QObject* parent) : QObject(parent) {
  m_qPack = new QuestionPack();
  m_loaded = false;
  m_type = Type::A1;
  m_isPractice = false;
  m_time = 0;
  m_sc = new ProxyScoreboard();
  m_sc->setType(Type::A1);
}

BackEnd::~BackEnd() {
  delete m_qPack;
  delete m_sc;
}

QString BackEnd::userName() { return m_userName; }

QString BackEnd::passWord() { return m_passWord; }

QString BackEnd::realName() { return m_realName; }

bool BackEnd::isLogin() const { return m_isLogin; }

void BackEnd::setUserName(const QString& userName) {
  if (userName == m_userName) return;
  m_userName = userName;
  emit userNameChanged();
}

void BackEnd::setPassWord(const QString& passWord) {
  if (passWord == m_passWord) return;
  m_passWord = passWord;
  emit passWordChanged();
}

void BackEnd::setRealName(const QString& realName) {
  if (realName == m_realName) return;
  m_realName = realName;
  emit realNameChanged();
}

QString BackEnd::buttonClick(bool isRegister) {
  if (isRegister) {
    string result =
        m_user.regis(m_userName.toStdString(), m_passWord.toStdString());
    m_isLogin = result.find("successfully") != string::npos;
    m_realName = m_userName;
    return QString::fromStdString(result);
  }

  string result =
      m_user.login(m_userName.toStdString(), m_passWord.toStdString());
  m_isLogin = result.find("successfully") != string::npos;
  m_realName = m_userName;
  return QString::fromStdString(result);
}

QString BackEnd::c() const { return m_c; }
QString BackEnd::c1() const { return m_c1; }
QString BackEnd::c2() const { return m_c2; }
QString BackEnd::c3() const { return m_c3; }
QString BackEnd::c4() const { return m_c4; }
QString BackEnd::t() const { return m_t; }
QString BackEnd::path() const { return m_path; }

int BackEnd::a1() const { return m_a1; }
int BackEnd::a2() const { return m_a2; }
int BackEnd::a3() const { return m_a3; }
int BackEnd::a4() const { return m_a4; }

void BackEnd::reset(bool r) {
  if (!r) m_qPack->setSavedAnswer(0);
  m_a1 = 0;
  m_a2 = 0;
  m_a3 = 0;
  m_a4 = 0;
  emit a1Changed(m_a1);
  emit a2Changed(m_a2);
  emit a3Changed(m_a3);
  emit a4Changed(m_a4);
}

void BackEnd::c1Click() {
  reset();
  if (!m_isPractice) {
    m_a1 = 1;  // Selected;
    emit a1Changed(m_a1);
    m_qPack->setSavedAnswer(1);
    return;
  }
  Question& q = m_qPack->getCurrentQuestion();
  if (q.checkAnswer(0)) {
    m_a1 = 1;
  } else {
    m_a1 = -1;
  }
  m_qPack->setSavedAnswer(1);
  emit a1Changed(m_a1);
}
void BackEnd::c2Click() {
  reset();
  if (!m_isPractice) {
    m_a2 = 1;  // Selected;
    emit a2Changed(m_a2);
    m_qPack->setSavedAnswer(2);
    return;
  }
  Question& q = m_qPack->getCurrentQuestion();
  if (q.checkAnswer(1)) {
    m_a2 = 1;
  } else {
    m_a2 = -1;
  }
  m_qPack->setSavedAnswer(2);
  emit a2Changed(m_a2);
}
void BackEnd::c3Click() {
  reset();
  if (!m_isPractice) {
    m_a3 = 1;  // Selected;
    emit a3Changed(m_a3);
    m_qPack->setSavedAnswer(3);
    return;
  }
  Question& q = m_qPack->getCurrentQuestion();
  if (q.checkAnswer(2)) {
    m_a3 = 1;
  } else {
    m_a3 = -1;
  }
  m_qPack->setSavedAnswer(3);
  emit a3Changed(m_a3);
}
void BackEnd::c4Click() {
  reset();
  if (!m_isPractice) {
    m_a4 = 1;  // Selected;
    emit a4Changed(m_a4);
    m_qPack->setSavedAnswer(4);
    return;
  }
  Question& q = m_qPack->getCurrentQuestion();
  if (q.checkAnswer(3)) {
    m_a4 = 1;
  } else {
    m_a4 = -1;
  }
  m_qPack->setSavedAnswer(4);
  emit a4Changed(m_a4);
}
void BackEnd::update() {
  Question& q = m_qPack->getCurrentQuestion();
  m_c = QString::fromStdString(q.getQuestionText());
  m_c1 = QString::fromStdString(q.getAnswerText(0));
  m_c2 = QString::fromStdString(q.getAnswerText(1));
  m_c3 = QString::fromStdString(q.getAnswerText(2));
  m_c4 = QString::fromStdString(q.getAnswerText(3));
  m_path = QString::fromStdString(q.getImagePath());

  if (m_path != "") {
    m_path = "file://" + QDir::currentPath() + "/data/" + m_path;
  }
  reset(true);
  if (m_qPack->getSavedAnswer() == 0) {
    selected = false;
  } else {
    selected = true;
    switch (m_qPack->getSavedAnswer()) {
      case 1:
        m_a1 = 1;
        emit a1Changed(m_a1);
        break;
      case 2:
        m_a2 = 1;
        emit a2Changed(m_a2);
        break;
      case 3:
        m_a3 = 1;
        emit a3Changed(m_a3);
        break;
      case 4:
        m_a4 = 1;
        emit a4Changed(m_a4);
        break;
    }
  }
  emit cChanged(m_c);
  emit c1Changed(m_c1);
  emit c2Changed(m_c2);
  emit c3Changed(m_c3);
  emit c4Changed(m_c4);
  emit pathChanged(m_path);
}

int x__ = 0;

void BackEnd::clickForward() {
  m_qPack->goNext();
  update();
  qDebug() << "Page: " << ++x__;
}

void BackEnd::clickPrevious() {
  m_qPack->goPrev();
  update();
  qDebug() << "Page: " << --x__;
}

void BackEnd::A1Click() {
  qDebug() << "A1";
  m_type = Type::A1;
  m_sc->setType(m_type);
}
void BackEnd::A2Click() {
  qDebug() << "A2";
  m_type = Type::A2;
  m_sc->setType(m_type);
}
void BackEnd::A3Click() {
  qDebug() << "A3";
  m_type = Type::A3;
  m_sc->setType(m_type);
}
void BackEnd::A4Click() {
  qDebug() << "A4";
  m_type = Type::A4;
  m_sc->setType(m_type);
}

void BackEnd::B1Click() {
  qDebug() << "B1";
  m_type = Type::B1;
  m_sc->setType(m_type);
}
void BackEnd::B2Click() {
  qDebug() << "B2";
  m_type = Type::B2;
  m_sc->setType(m_type);
}

void BackEnd::CClick() {
  qDebug() << "C";
  m_type = Type::C;
  m_sc->setType(m_type);
}
void BackEnd::DClick() {
  qDebug() << "D";
  m_type = Type::D;
  m_sc->setType(m_type);
}
void BackEnd::EClick() {
  qDebug() << "E";
  m_type = Type::E;
  m_sc->setType(m_type);
}
void BackEnd::FClick() {
  qDebug() << "F";
  m_type = Type::F;
  m_sc->setType(m_type);
}

QString BackEnd::scoreboardReq() {
  auto data = m_sc->getCurrentPage();
  QString result = "Name\tScore\tTime\tDate\n";
  for (auto& x : data) {
    result += QString::fromStdString(x.getUsername()) + "\t";
    result += QString::number(x.getCorrectAnsw()) + "\t";
    result += QString::fromStdString(x.getTime()) + "\t";
    result += QString::fromStdString(x.getDate()) + "\n";
  }
  return result;
}

void BackEnd::ExClick() {
  m_qPack->changeType(m_type);
  m_isPractice = false;
}

void BackEnd::PrClick() {
  m_qPack->changeType(m_type);
  m_isPractice = true;
}

bool BackEnd::isPractice() { return m_isPractice; }

bool BackEnd::isLoaded() { return m_loaded; }

QString BackEnd::getTip() {
  if (!m_isPractice) return "";  // Exam mode
  return QString::fromStdString(m_qPack->getCurrentQuestion().getTip());
}

int BackEnd::getTime() { return types[(int)m_type].timeAllowed; }

int BackEnd::getCorrect() { return m_qPack->evaluateScore(); }

void BackEnd::StartClick(bool fifty, bool sQues, bool sAnsw, bool withTopic,
                         bool t1, bool t2, bool t3, bool t4, bool t5, bool t6,
                         bool t7) {
  m_loaded = false;
  if (!withTopic) t1 = t2 = t3 = t4 = t5 = t6 = t7 = true;
  if (m_isPractice)
    m_qPack->loadPractice(fifty, sQues, sAnsw, t1, t2, t3, t4, t5, t6, t7);
  else
    m_qPack->loadMockTest();
  m_loaded = true;
  selected = false;
}

void BackEnd::addToScoreboard(int timeTaken) {
  m_sc->add(Score(m_realName.toStdString(), getCorrect(), to_string(timeTaken),
                  getCurrentDate()));
  m_sc->save();
  qDebug() << "ADD 1";
}
