#ifndef BACKEND_H
#define BACKEND_H

#include <QDebug>
#include <QObject>
#include <QString>

#include "Library/Question/QuestionPack.h"
#include "Library/User/User.h"

class BackEnd : public QObject {
  Q_OBJECT

  // Login interface --------------------
  Q_PROPERTY(QString userName READ userName WRITE setUserName NOTIFY
                 userNameChanged)  // UserName
  Q_PROPERTY(QString passWord READ passWord WRITE setPassWord NOTIFY
                 passWordChanged)  // Password
  Q_PROPERTY(QString realName READ realName WRITE setRealName NOTIFY
                 realNameChanged)  // readName (deprecated)
  Q_PROPERTY(bool isLogin READ isLogin)
  // Question interface --------------------
  Q_PROPERTY(QString c READ c NOTIFY cChanged)     // Question
  Q_PROPERTY(QString c1 READ c1 NOTIFY c1Changed)  // Answer 1
  Q_PROPERTY(QString c2 READ c2 NOTIFY c2Changed)  // Answer 2
  Q_PROPERTY(QString c3 READ c3 NOTIFY c3Changed)  // Answer 3
  Q_PROPERTY(QString c4 READ c4 NOTIFY c4Changed)  // Answer 4
  Q_PROPERTY(QString t READ t NOTIFY tChanged)     // Tips (If possible)
  Q_PROPERTY(
      QString path READ path NOTIFY pathChanged)  // Path to Image (If possible)
  Q_PROPERTY(
      int a1 READ a1 NOTIFY a1Changed)  // Signal for c1 (true/false/not select)
  Q_PROPERTY(
      int a2 READ a2 NOTIFY a2Changed)  // Signal for c2 (true/false/not select)
  Q_PROPERTY(
      int a3 READ a3 NOTIFY a3Changed)  // Signal for c3 (true/false/not select)
  Q_PROPERTY(
      int a4 READ a4 NOTIFY a4Changed)  // Signal for c4 (true/false/not select)

 public:
  explicit BackEnd(QObject *parent = nullptr);
  ~BackEnd();

  // getter login
  QString userName();
  QString passWord();
  QString realName();
  bool isLogin() const;
  // getter question
  QString c() const;
  QString c1() const;
  QString c2() const;
  QString c3() const;
  QString c4() const;
  QString t() const;
  QString path() const;
  int a1() const;
  int a2() const;
  int a3() const;
  int a4() const;

  // --------------------------------

  // setter login
  void setUserName(const QString &userName);
  void setPassWord(const QString &passWord);
  void setRealName(const QString &realName);
  // setter question

 public slots:
  QString buttonClick(bool isRegister);  // Login button
  // question page:
  void c1Click();
  void c2Click();
  void c3Click();
  void c4Click();
  void reset(bool = false);
  void update();  // Directly call update on front-end
  // Navigation:
  void clickForward();
  void clickPrevious();
  // Type selection page
  void A1Click();
  void A2Click();
  void A3Click();
  void A4Click();

  void B1Click();
  void B2Click();

  void CClick();
  void DClick();
  void EClick();
  void FClick();

  // Scoreboard request
  QString scoreboardReq();

 signals:
  // Login signal
  void userNameChanged();
  void passWordChanged();
  void realNameChanged();
  // question signal
  void cChanged(QString c);
  void c1Changed(QString c1);
  void c2Changed(QString c2);
  void c3Changed(QString c3);
  void c4Changed(QString c4);
  void tChanged(QString t);
  void pathChanged(QString path);
  void a1Changed(int a1);
  void a2Changed(int a2);
  void a3Changed(int a3);
  void a4Changed(int a4);

  // Private attribute
 private:
  // Attribute for login
  QString m_userName;
  QString m_passWord;
  QString m_realName;
  bool m_isLogin;
  // Attribute for question
  QString m_c;
  QString m_c1;
  QString m_c2;
  QString m_c3;
  QString m_c4;
  QString m_t;
  QuestionPack *m_qPack;
  QString m_path;
  int m_a1;
  int m_a2;
  int m_a3;
  int m_a4;
  bool selected;

  // attribute for client interaction
  User m_user;    // Current user;
  Type m_type;    // Current type;
  Topic m_topic;  // Current topic;
};

#endif  // BACKEND_H
