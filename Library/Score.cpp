#include <iostream>
#include <fstream>
#include <algorithm>
#include "Score.h"
#include "constants.h"
#include "Tokenizer.h"

using namespace std;



//
//
//
Score::Score() : m_user(), m_correctAnswer(-1), m_dateAndTimeTaken("")
{
}

Score::Score(User user, int corrects_count, string date_and_time) : m_user(user), m_correctAnswer(corrects_count), m_dateAndTimeTaken(date_and_time)
{
}

User Score::getUser() const
{
    return this->m_user;
}

string Score::getDateAndTime() const
{
    return this->m_dateAndTimeTaken;
}

string Score::toString()
{
    return m_user.Username() + kScoreStringSeparator +
           m_user.Password() + kScoreStringSeparator +
           to_string(m_correctAnswer) + kScoreStringSeparator +
           m_dateAndTimeTaken;
}

bool Score::isValid()
{
    return ((!this->m_user.Username().empty()) &&
            (!this->m_user.Password().empty()) &&
            (this->m_correctAnswer >= 0) &&
            (!this->m_dateAndTimeTaken.empty()));
}

Score Score::Parse(string line)
{
    vector<string> tokens = Tokenizer::parse(line, kScoreStringSeparator);

    if (tokens.size() == 4)
        return Score(User(tokens[0], tokens[1]), stoi(tokens[2]), tokens[3]);

    return Score();
}

bool Score::operator>(const Score &s2) const
{
    return (this->m_correctAnswer > s2.m_correctAnswer);
}

bool Score::operator<(const Score &s2) const
{
    return (this->m_correctAnswer < s2.m_correctAnswer);
}



//
//
//
Scoreboard::Scoreboard() : order_(0)
{
    string file_path = kScoreboardFolder + kScoreboardFileName;
    ifstream in_file(file_path, ios_base::in);

    try {
        if (!in_file.is_open() || in_file.eof() || in_file.bad())
            throw runtime_error("Unable to open scoreboard in file or the file is empty");

        int count = 0;
        string line;
        Score line_score;
        while (!in_file.eof() && count < kScoreboardMaxSize)
        {
            getline(in_file, line);
            line_score = Score::Parse(line);
            if (line_score.isValid())
                this->scoreboard_.push_back(line_score);
        }

        in_file.close();

        this->sort(false);

    }  catch (const exception &e) {
        cout << "Exception:\t" << e.what() << endl;
    }
}

void Scoreboard::save()
{
    // neu *this la` scoreboard cua user
    if (this->order_ > 1)
        return;

    this->sort(false);

    string file_path = kScoreboardFolder + kScoreboardFileName;
    ofstream out_file(file_path, ios_base::trunc);

    try {
        if (!out_file.is_open() || out_file.bad())
            throw runtime_error("Unable to open scoreboard out file");

        for (int i = 0; i < scoreboard_.size() && i < kScoreboardMaxSize; i++)
            out_file << scoreboard_[i].toString() << "\n";

        out_file.close();

    }  catch (const exception &e) {
        cout << "Exception:\t" << e.what() << endl;
    }
}

void Scoreboard::sort(bool isInc) {
    if (!scoreboard_.empty()) {
        if (isInc)
        {
            std::sort(scoreboard_.begin(), scoreboard_.end(), less<Score>());
            this->order_ = 1;
        }
        else
        {
            std::sort(scoreboard_.begin(), scoreboard_.end(), greater<Score>());
            this->order_ = 0;
        }
    }
}

Scoreboard Scoreboard::UserScoreboard(User current_user)
{
    Scoreboard res = *this;

    for (vector<Score>::iterator it = res.scoreboard_.begin(); it < res.scoreboard_.end(); it++)
        if (!(it->getUser() == current_user))
            res.scoreboard_.erase(it--);

    res.order_ = 2;

    return res;
}

void Scoreboard::add(Score new_score)
{
    this->scoreboard_.push_back(new_score);
    this->sort(false);
}

void Scoreboard::remove(User user_to_remove)
{
    for (vector<Score>::iterator it = scoreboard_.begin(); it < scoreboard_.end(); it++)
    {
        if (it->getUser() == user_to_remove)
            scoreboard_.erase(it--);
    }
}

void Scoreboard::remove(User user, string date_and_time)
{
    for (vector<Score>::iterator it = scoreboard_.begin(); it < scoreboard_.end(); it++)
    {
        if (it->getUser() == user && it->getDateAndTime() == date_and_time)
            scoreboard_.erase(it--);
    }
}

void Scoreboard::removeAll()
{
    this->scoreboard_.clear();
}

vector<Score> Scoreboard::getList(int from, int to) const
{
    vector<Score> res;

    for (int i = from; i <= to; i++)
        if (i >= 0 && i < scoreboard_.size())
            res.push_back(scoreboard_[i]);

    return res;
}

int Scoreboard::MaxPage() const
{
    int size = scoreboard_.size();

    return (size / kScoreboardPageSize + ((size % kScoreboardPageSize == 0) ? 0 : 1));
}

vector<Score> Scoreboard::getPage(int page_number) const
{

    if (page_number > 0 && page_number <= this->MaxPage())
    {
        int first_index = 5 * (page_number - 1), last_index = 5 * page_number - 1;

        return this->getList(first_index, last_index);
    }

    return vector<Score>();
}
