#include <iostream>
#include "User.h"
#include "DatabaseClientUser.h"

void User::login(string username, string password){
    string info = username + ";" + password;
    DatabaseClientUser db;
    vector<string> accounts = db.read();
    for(auto i : accounts){
        if(i == info){
            cout << "Login successfully!\n";
            this->m_password = password;
            this->m_username = username;
            this->m_isAuth = true;
            return;
        }
    }
    cout << "Login fail, wrong username or password\n";
}

void User::regis(string username, string password){
    string info = username + ";" + password;
    DatabaseClientUser db;
    vector<User> users = DatabaseClientUser::toVUser(db.read());
    for(auto i : users){
        if(i.m_username == username){
            cout << "This account has been created!\n";
            return;
        }
    }
    db.update(info);
    this->m_username = username;
    this->m_password = password;
    this->m_isAuth = true;
    cout << "Register successfully!\n";
}

void User::logout(){
    this->m_isAuth = false;
}