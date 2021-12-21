#include <iostream>
#include "User.h"
#include "DatabaseClientUser.h"

string User::login(string username, string password){
    string info = username + ";" + password;
    DatabaseClientUser db;
    vector<string> accounts = db.read();
    for(auto i : accounts){
        if(i == info){
            this->m_password = password;
            this->m_username = username;
            this->m_isAuth = true;
            return "Login successfully!\n";
        }
    }
    return "Login fail, wrong username or password\n";
}

string User::regis(string username, string password){
    string info = username + ";" + password;
    DatabaseClientUser db;
    vector<User> users = DatabaseClientUser::toVUser(db.read());
    for(auto i : users){
        if(i.m_username == username){
            return "This account has been created!\n";
        }
    }
    db.update(info);
    this->m_username = username;
    this->m_password = password;
    this->m_isAuth = true;
    return "Register successfully!\n";
}

string User::logout(){
    this->m_isAuth = false;
    return "Logged out!\n";
}

bool User::operator==(const User &opr) const
{
    return (this->m_username == opr.m_username &&
            this->m_password == opr.m_password);
}
