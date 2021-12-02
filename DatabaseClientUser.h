#pragma once
#include "DatabaseClient.h"

class DatabaseClientUser : public DatabaseClient{
public:
    DatabaseClientUser(){}
    DatabaseClientUser(string);
    ~DatabaseClientUser(){}
    
};