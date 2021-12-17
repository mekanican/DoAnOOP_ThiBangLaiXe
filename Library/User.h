#pragma once
#include <string>
using namespace std;

class User
{
private:
    string m_username;
    string m_password;
    bool m_isAuth;
public:
    User(){
        m_password = m_username = "";
        m_isAuth = false;
    }
    User(string name, string pass){
        m_password = pass;
        m_username = name;
        m_isAuth = false;
    }
    string Username(){ return m_username; }
    string Password(){ return m_password; }
    bool authenticate(){ return m_isAuth; }
    void login(string, string);
    void regis(string, string);
    void logout();
};
