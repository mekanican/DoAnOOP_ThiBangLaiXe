#ifndef IO_H_
#define IO_H_
#include "../Question/Question.h"

class QuestionLoader {
 public:
  static Question Load(string file_path, bool is_required);
};

#endif
