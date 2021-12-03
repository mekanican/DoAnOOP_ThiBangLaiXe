#pragma once
#include "DatabaseClient.h"

class DatabaseClientUser : public DatabaseClient{
public:
    void creat();
    void update(string);
    vector<string> read();
};