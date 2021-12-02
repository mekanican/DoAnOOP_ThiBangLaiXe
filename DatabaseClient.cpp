#include "DatabaseClient.h"
#include <fstream>
#include <iostream>
#define CLIENT_LOCATION "client\\"

DatabaseClient::DatabaseClient(){}
DatabaseClient::DatabaseClient(string location){
    m_location = location;
}

void DatabaseClient::creat(){
    string file_name = CLIENT_LOCATION + m_userName;
    ofstream fo(file_name);
    fo << m_userName << std::endl;
}

void DatabaseClient::read(){
    string file_name = CLIENT_LOCATION + m_userName;
    ifstream fi(file_name);
    fi >> m_userName;
}