#pragma once

#include <stdlib.h>
#include <time.h>

class Random {
 public:
  static void Init() { srand(time(0) + 1337); }
  static int getRange(int _min, int _max) {
    return _min + rand() % (_max - _min + 1);
  }
};
