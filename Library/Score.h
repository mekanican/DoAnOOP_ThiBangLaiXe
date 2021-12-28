#pragma once
#include <vector>
#include <string>
#include "User.h"
#include "constants.h"

using std::string;
using std::vector;

class Score {
private:
    User m_user;
    int m_correctAnswer;
    string m_timeTaken;
    string m_date;
public:
    Score();
    Score(User, int, string, string);

    User getUser() const;
    string getTime() const;
    string getDate() const;

    string toString();
    bool isValid();
    static Score Parse(string line);

    bool operator>(const Score &s2) const;
    bool operator<(const Score &s2) const;
    bool operator==(const Score &s2) const;
    bool operator>=(const Score &s2) const;
    bool operator<=(const Score &s2) const;
};

class Scoreboard {
private:
    vector<Score> scoreboard_;
    Type m_licenseType;
    bool m_saved = false;


    int order_;     // 0: giam dan theo diem
                    // 1: tang dan theo diem
                    // 2: loc theo User
                    //

public:
    Scoreboard();       // Khoi tao tu file, mac dinh: UserData/scoreboard/scores.txt
                        // Sau khi doc file, sap xep giam dan
    Scoreboard(Type license_type);
    ~Scoreboard();


    void save();        // Ghi scoreboard vao file, mac dinh: UserData/scoreboard/scores.txt
                        // Mac dinh chi luu lai nhieu nhat 100 scores
                        // Chi thuc hien khi order_ = 0 hoac order_ = 1
                        // Sap xep giam dan scoreboard_ truoc khi ghi va`o file

    void sort(bool isInc);    // Sap xep tang dan neu tham so la true, nguoc lai tham so la false

    Scoreboard UserScoreboard(User current_user);   // Tra ve scoreboard theo nguoi dung
                                                    // order_ = 2

    void add(Score new_score);

    void remove(User);                                    // Xoa du lieu nguoi dung
    void remove(User, string time_taken, string date);    // Xoa mot Score cu the
    void removeAll();

    vector<Score> getList(int from, int to) const;      // Tra ve scoreboard_[from -> to]
    int MaxPage() const;                                // So trang toi da (mac dinh 5 Score 1 trang, xem constants.h)
    vector<Score> getPage(int page_number) const;       // Tra ve cac Score cua trang thu n

    static string GetFilePath(Type license_type);
    static void Save(const Score &current_score, Type license_type);
//    static void DeleteAll(Type license_type);
//    static void DeleteAll(User);
//    static void DeleteAll();
};

class ProxyScoreboard
{
private:
    Type m_currentType;
    int m_typeIndex;
    bool m_cached[10];
    vector<Scoreboard *> m_realScoreboard;
public:
    ProxyScoreboard();
    ProxyScoreboard(Type license_type);
    ~ProxyScoreboard();

    void setType(Type license_type);


    void save();
    void sort(bool isInc);
    Scoreboard UserScoreboard(User current_user);
    void add(Score new_score);
    void remove(User);
    void remove(User, string, string);
    void removeAll();
};

