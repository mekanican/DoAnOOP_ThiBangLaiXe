#include "utility.h"

#include <cstring>
#include <ctime>

std::pair<int, int> idParser(int id) {
  int _type = id >> 8;
  int _topic = id & 0b11111111;
  return {_type, _topic};
}

int idComposer(int type, int topic) { return (type << 8) + topic; }

std::string getCurrentDate() {
  time_t rawtime;
  time(&rawtime);
  struct tm* timeinfo;
  timeinfo = localtime(&rawtime);

  char buffer[50];
  snprintf(buffer, sizeof(buffer), "%d/%d/%d", timeinfo->tm_mday,
           timeinfo->tm_mon + 1, timeinfo->tm_year + 1900);
  return buffer;
}
