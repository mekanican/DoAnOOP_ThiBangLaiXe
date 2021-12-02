#pragma once

#include "Question.h"

class QuestionLoader 
{
public:
 static Question Load(string file_path, bool is_required);
 
};