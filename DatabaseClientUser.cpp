#include "DatabaseClientUser.h"
#include <fstream>
#include <iostream>
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