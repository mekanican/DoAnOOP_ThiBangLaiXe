#pragma once
#include "User.h"
#include <vector>
using namespace std;

class DatabaseClientUser{
public:
    void creat();
    void update(string);
    vector<string> read();
    static vector<User> toVUser(vector<string>);
    static string fromUser(User);
};
