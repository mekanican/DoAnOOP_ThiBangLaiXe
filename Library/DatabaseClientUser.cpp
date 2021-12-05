#include "DatabaseClientUser.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include "Tokenizer.h"
#define USER_LOCATION "UserDatabase.txt"

void DatabaseClientUser::creat(){
    string file_name = USER_LOCATION;
    ofstream fo(file_name);
    if(!fo.is_open()){
        cout << "Fail to open!\n";
        return;
    }
    fo << "User Database" << std::endl;
    fo.close();
}

vector<string> DatabaseClientUser::read(){
    string file_name = USER_LOCATION;
    ifstream fi(file_name);
    vector<string> userInfo;
    if(!fi.is_open()){
        cout << "Fail to open!\n";
        return userInfo;
    }
    string buffer;
    while (true){
        getline(fi, buffer);
        if(fi.eof()) break;
        userInfo.push_back(buffer);
    }
    return userInfo;
}

void DatabaseClientUser::update(string info){
    fstream out;
    out.open(USER_LOCATION, ios::app);
    if(!out.is_open()) return;
    out << info;
    out.close();
}

vector<User> DatabaseClientUser::toVUser(string users){
    // tui khong hieu string o day la gi, tui ngam hieu la data user nhe.
    vector<User> res;
    stringstream ss(users);
    for(int i = 0; i < 10; i++){
        string tmp;
        ss >> tmp;
        vector<string> info = Tokenizer::parse(tmp, ";");
        User user(info[0], info[1]);
        res.push_back(user);
    }
    return res;
}

string DatabaseClientUser::fromUser(User user){
    return user.Username() + ";" + user.Password();
}