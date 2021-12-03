#pragma once
#include <string>

using namespace std;

class User
{
private:
    string m_userName;
    string m_password;
    bool m_isAuth;
public:
    User(string name, string pass){
        m_password = pass;
        m_userName = name;
    }
    string Username(){ return m_userName; }
    string Password(){ return m_password; }
    bool authenticate(){ return m_isAuth;}
};