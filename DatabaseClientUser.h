#pragma once
#include "DatabaseClient.h"
#include "User.h"

class DatabaseClientUser : public DatabaseClient{
public:
    void creat();
    void update(string);
    vector<string> read();
    static vector<User> toVUser(string);
    static string fromUser(User);
};