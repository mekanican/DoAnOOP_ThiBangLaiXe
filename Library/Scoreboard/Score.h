#pragma once
#include <string>
#include <vector>

#include "../User/User.h"
#include "../Utility/constants.h"

using std::string;
using std::vector;

class Score;
class Scoreboard;
class RealScoreboard;
class ProxyScoreboard;

class Score {
 private:
  string m_userName;
  int m_correctAnswer;
  string m_timeTaken;
  string m_date;

 public:
  Score();
  Score(string, int, string, string);

  string getUsername() const;
  string getTime() const;
  string getDate() const;
  int getCorrectAnsw() const;

  string toString() const;
  bool isValid() const;
  static Score Parse(string line);

  bool operator>(const Score &s2) const;
  bool operator<(const Score &s2) const;
  bool operator==(const Score &s2) const;
  bool operator>=(const Score &s2) const;
  bool operator<=(const Score &s2) const;
};

//
//
class Scoreboard {
 public:
  Scoreboard();

  virtual void setType(Type) {}

  virtual void save() = 0;
  virtual void sort(bool) = 0;
  virtual RealScoreboard UserScoreboard(string) = 0;
  virtual void add(Score) = 0;
  virtual void remove(string) = 0;
  virtual void remove(string, string, string) = 0;
  virtual void removeAll() = 0;
  virtual int MaxPage() const = 0;
  virtual vector<Score> getPage(int) = 0;
  virtual vector<Score> getCurrentPage() = 0;
  virtual vector<Score> getPreviousPage() = 0;
  virtual vector<Score> getNextPage() = 0;
  virtual vector<Score> getFirstPage() = 0;
  virtual vector<Score> getLastPage() = 0;
  virtual ~Scoreboard();

  static string GetFilePath(Type license_type);
  static void Add(const Score &current_score, Type license_type);
};

//
//
class RealScoreboard : public Scoreboard {
 private:
  vector<Score> scoreboard_;
  Type m_licenseType;
  bool m_saved = false;
  int m_currentPage;

  int order_;  // 0: giam dan theo diem
               // 1: tang dan theo diem
               // 2: loc theo User
               //

 public:
  RealScoreboard();  // Khoi tao tu file, mac dinh:
                     // UserData/scoreboard/scores.txt Sau khi doc file, sap xep
                     // giam dan
  RealScoreboard(Type license_type);
  ~RealScoreboard();

  void save();  // Ghi scoreboard vao file, mac dinh:
                // UserData/scoreboard/scores.txt Mac dinh chi luu lai nhieu
                // nhat 100 scores Chi thuc hien khi order_ = 0 hoac order_ = 1
                // Sap xep giam dan scoreboard_ truoc khi ghi va`o file

  void sort(bool isInc);  // Sap xep tang dan neu tham so la true, nguoc lai
                          // tham so la false

  RealScoreboard UserScoreboard(string current_user);  // Tra ve scoreboard theo
                                                       // nguoi dung order_ = 2

  void add(Score new_score);

  void remove(string);  // Xoa du lieu nguoi dung
  void remove(string, string time_taken, string date);  // Xoa mot Score cu the
  void removeAll();

  vector<Score> getList(int from,
                        int to) const;  // Tra ve scoreboard_[from -> to]
  int MaxPage()
      const;  // So trang toi da (mac dinh 5 Score 1 trang, xem constants.h)
  vector<Score> getPage(
      int page_number);  // Tra ve cac Score cua trang thu n
                         // Cac trang duoc danh so tu 1 -> max: 50
  vector<Score> getCurrentPage();
  vector<Score> getPreviousPage();
  vector<Score> getNextPage();
  vector<Score> getFirstPage();
  vector<Score> getLastPage();

  //    static void DeleteAll(Type license_type);
  //    static void DeleteAll(User);
  //    static void DeleteAll();
};

//
//
class ProxyScoreboard : public Scoreboard {
 private:
  Type m_currentType;
  int m_typeIndex;
  bool m_cached[10];
  vector<RealScoreboard *> m_realScoreboard;

 public:
  ProxyScoreboard();
  ProxyScoreboard(Type license_type);
  ~ProxyScoreboard();

  void setType(Type license_type);

  void save();
  void sort(bool isInc);
  RealScoreboard UserScoreboard(string current_user);
  void add(Score new_score);
  void remove(string);
  void remove(string, string, string);
  void removeAll();

  int MaxPage() const;
  vector<Score> getPage(int page_number);

  vector<Score> getCurrentPage();
  vector<Score> getPreviousPage();
  vector<Score> getNextPage();
  vector<Score> getFirstPage();
  vector<Score> getLastPage();
};
