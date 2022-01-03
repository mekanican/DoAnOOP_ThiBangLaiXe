#ifndef UTILITY_H
#define UTILITY_H
#include <string>
#include <utility>
using std::string;

// first 8 bit for topic, next 8 bit for type
std::pair<int, int> idParser(int id);
//{
//  int _type = id >> 8;
//  int _topic = id & 0b11111111;
//  return {_type, _topic};
//}

int idComposer(int type, int topic);  // { return (type << 8) + topic; }

string getCurrentDate();

#endif  // UTILITY_H
