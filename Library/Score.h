#pragma once
#include "User.h"

class Score{
private:
    User m_user;
    int m_correctAnswer;
    string m_dateAndTimeTaken;
public:
    void save();
};