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
    bool authenticate(){ return m_isAuth;}
};