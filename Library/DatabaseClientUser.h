#pragma once
#include "User.h"
#include <vector>
using std::vector;

class DatabaseClientUser{
public:
    void creat();
    void update(string);
    vector<string> read();
    static vector<User> toVUser(string);
    static string fromUser(User);
};
