#pragma once
#include <string>
using namespace std;

class User {
 private:
  string m_username;
  string m_password;
  bool m_isAuth;

 public:
  User() {
    m_password = m_username = "";
    m_isAuth = false;
  }
  User(string name, string pass) {
    m_password = pass;
    m_username = name;
    m_isAuth = false;
  }
  string Username() const { return m_username; }
  string Password() const { return m_password; }
  bool authenticate() const { return m_isAuth; }
  string login(string, string);
  string regis(string, string);
  string logout();

  bool operator==(const User &opr) const;
};
