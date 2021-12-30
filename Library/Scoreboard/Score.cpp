#include "Score.h"

#include <algorithm>
#include <fstream>
#include <iostream>

#include "../Utility/Tokenizer.h"

using namespace std;

int getTypeIndex(Type license_type) {
  int type_index = static_cast<int>(license_type);

  return ((type_index >= 0 && type_index <= 9) ? type_index : 0);
}

string toString(Type license_type) {
  int type_index = getTypeIndex(license_type);

  return Types[type_index];
}

//
//
//
Score::Score() : m_user(), m_correctAnswer(-1), m_timeTaken(""), m_date("") {}

Score::Score(User user, int corrects_count, string time_taken, string date)
    : m_user(user),
      m_correctAnswer(corrects_count),
      m_timeTaken(time_taken),
      m_date(date) {}

User Score::getUser() const { return this->m_user; }

string Score::getTime() const { return this->m_timeTaken; }

string Score::getDate() const { return this->m_date; }

string Score::toString() const {
  return m_user.Username() + kScoreStringSeparator + m_user.Password() +
         kScoreStringSeparator + to_string(m_correctAnswer) +
         kScoreStringSeparator + m_timeTaken + kScoreStringSeparator + m_date;
}

bool Score::isValid() const {
  return ((!this->m_user.Username().empty()) &&
          (!this->m_user.Password().empty()) && (this->m_correctAnswer >= 0) &&
          (!this->m_timeTaken.empty()) && (!this->m_date.empty()));
}

Score Score::Parse(string line) {
  vector<string> tokens = Tokenizer::parse(line, kScoreStringSeparator);

  if (tokens.size() == 5)
    return Score(User(tokens[0], tokens[1]), stoi(tokens[2]), tokens[3],
                 tokens[4]);

  return Score();
}

bool Score::operator>(const Score &s2) const {
  return (this->m_correctAnswer > s2.m_correctAnswer);
}

bool Score::operator<(const Score &s2) const {
  return (this->m_correctAnswer < s2.m_correctAnswer);
}

bool Score::operator==(const Score &s2) const {
  return (this->m_correctAnswer == s2.m_correctAnswer);
}

bool Score::operator>=(const Score &s2) const {
  return ((*this > s2) || (*this == s2));
}

bool Score::operator<=(const Score &s2) const {
  return ((*this < s2) || (*this == s2));
}

//
//
//

ProxyScoreboard::ProxyScoreboard()
    : m_cached{0}, m_currentType(Type::A1), m_typeIndex(0) {
  m_realScoreboard.resize(10);
  fill(m_realScoreboard.begin(), m_realScoreboard.end(), nullptr);

  m_realScoreboard[m_typeIndex] = new Scoreboard(this->m_currentType);
  m_cached[m_typeIndex] = true;
}

ProxyScoreboard::ProxyScoreboard(Type license_type)
    : m_cached{0},
      m_currentType(license_type),
      m_typeIndex(getTypeIndex(m_currentType)) {
  m_realScoreboard.resize(10);
  fill(m_realScoreboard.begin(), m_realScoreboard.end(), nullptr);

  m_realScoreboard[m_typeIndex] = new Scoreboard(license_type);

  m_cached[m_typeIndex] = true;
}

ProxyScoreboard::~ProxyScoreboard() {
  for (auto &e : m_realScoreboard)
    if (e != nullptr) delete e;
}

void ProxyScoreboard::setType(Type license_type) {
  m_typeIndex = getTypeIndex(license_type);
  if (!m_cached[m_typeIndex]) {
    m_currentType = license_type;
    m_cached[m_typeIndex] = true;
    m_realScoreboard[m_typeIndex] = new Scoreboard(license_type);
  }
}

void ProxyScoreboard::save() { m_realScoreboard[m_typeIndex]->save(); }

void ProxyScoreboard::sort(bool isInc) {
  m_realScoreboard[m_typeIndex]->sort(isInc);
}

Scoreboard ProxyScoreboard::UserScoreboard(User current_user) {
  return m_realScoreboard[m_typeIndex]->UserScoreboard(current_user);
}

void ProxyScoreboard::add(Score new_score) {
  m_realScoreboard[m_typeIndex]->add(new_score);
}

void ProxyScoreboard::remove(User current_user) {
  m_realScoreboard[m_typeIndex]->remove(current_user);
}

void ProxyScoreboard::remove(User current_user, string time_taken,
                             string date) {
  m_realScoreboard[m_typeIndex]->remove(current_user, time_taken, date);
}

void ProxyScoreboard::removeAll() {
  m_realScoreboard[m_typeIndex]->removeAll();
}

//
//
//
Scoreboard::Scoreboard() : order_(0), m_licenseType(Type::A1), m_saved(true) {}

Scoreboard::Scoreboard(Type license_type) : order_(0), m_saved(true) {
  string file_path = GetFilePath(license_type);
  ifstream in_file(file_path, ios_base::in);

  try {
    if (!in_file.is_open() || in_file.eof() || in_file.bad())
      throw runtime_error(
          "Unable to open scoreboard in file or the file is empty");

    int count = 0;
    string line;
    Score line_score;
    while (!in_file.eof() && count < kScoreboardMaxSize) {
      getline(in_file, line);
      line_score = Score::Parse(line);
      if (line_score.isValid()) this->scoreboard_.push_back(line_score);
    }

    in_file.close();

    this->sort(false);

  } catch (const exception &e) {
    cout << "Exception:\t" << e.what() << endl;
  }
}

Scoreboard::~Scoreboard() {
  if (!this->m_saved) this->save();
}

void Scoreboard::save() {
  // neu *this la` scoreboard cua user
  if (this->order_ > 1 || this->m_saved == true) return;

  this->sort(false);

  string file_path = GetFilePath(this->m_licenseType);
  ofstream out_file(file_path, ios_base::trunc);

  try {
    if (!out_file.is_open() || out_file.bad())
      throw runtime_error("Unable to open scoreboard out file");

    for (int i = 0; i < (int)scoreboard_.size() && i < kScoreboardMaxSize; i++)
      out_file << scoreboard_[i].toString() << "\n";

    out_file.close();

  } catch (const exception &e) {
    cout << "Exception:\t" << e.what() << endl;
  }
}

void Scoreboard::sort(bool isInc) {
  if (!scoreboard_.empty()) {
    if (isInc) {
      std::sort(scoreboard_.begin(), scoreboard_.end(), less_equal<Score>());
      this->order_ = 1;
    } else {
      std::sort(scoreboard_.begin(), scoreboard_.end(), greater_equal<Score>());
      this->order_ = 0;
    }

    m_saved = true;
  }
}

Scoreboard Scoreboard::UserScoreboard(User current_user) {
  Scoreboard res = *this;

  for (vector<Score>::iterator it = res.scoreboard_.begin();
       it < res.scoreboard_.end(); it++)
    if (!(it->getUser() == current_user)) res.scoreboard_.erase(it--);

  res.order_ = 2;
  res.m_saved = true;

  return res;
}

void Scoreboard::add(Score new_score) {
  this->scoreboard_.push_back(new_score);
  this->sort(false);

  m_saved = false;
}

void Scoreboard::remove(User user_to_remove) {
  bool found = false;
  for (vector<Score>::iterator it = scoreboard_.begin(); it < scoreboard_.end();
       it++) {
    if (it->getUser() == user_to_remove) {
      scoreboard_.erase(it--);
      found = true;
    }
  }

  this->m_saved = !found;
}

void Scoreboard::remove(User user, string time_taken, string date) {
  bool found = false;

  for (vector<Score>::iterator it = scoreboard_.begin(); it < scoreboard_.end();
       it++) {
    if (it->getUser() == user && it->getTime() == time_taken &&
        it->getDate() == date) {
      scoreboard_.erase(it--);
      found = true;
    }
  }

  this->m_saved = !found;
}

void Scoreboard::removeAll() {
  this->scoreboard_.clear();

  this->m_saved = false;
}

vector<Score> Scoreboard::getList(int from, int to) const {
  vector<Score> res;

  for (int i = from; i <= to; i++)
    if (i >= 0 && i < (int)scoreboard_.size()) res.push_back(scoreboard_[i]);

  return res;
}

int Scoreboard::MaxPage() const {
  int size = scoreboard_.size();

  return (size / kScoreboardPageSize +
          ((size % kScoreboardPageSize == 0) ? 0 : 1));
}

vector<Score> Scoreboard::getPage(int page_number) const {
  if (page_number > 0 && page_number <= this->MaxPage()) {
    int first_index = 5 * (page_number - 1), last_index = 5 * page_number - 1;

    return this->getList(first_index, last_index);
  }

  return vector<Score>();
}

//
//
//
string Scoreboard::GetFilePath(Type license_type) {
  string type = toString(license_type), file_path;

  file_path = kScoreboardFolder + type + ".txt";

  return file_path;
}

void Scoreboard::Save(const Score &current_score, Type license_type) {
  if (!current_score.isValid()) return;

  string file_path = GetFilePath(license_type);
  ofstream out_file(file_path, ios_base::app);

  if (out_file.is_open() && out_file.good()) {
    out_file << current_score.toString() << "\n";
    out_file.close();
  }
}
