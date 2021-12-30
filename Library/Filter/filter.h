#pragma once
#include "../Question/Question.h"

class Filter {
 public:
  virtual Filter* setNext(Filter*) = 0;
  virtual void handle(vector<Question>&) = 0;
  virtual ~Filter() {}
};
