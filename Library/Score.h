#pragma once
#include <vector>
#include <string>
#include "User.h"

using std::string;
using std::vector;

class Score {
private:
    User m_user;
    int m_correctAnswer;
    string m_dateAndTimeTaken;
public:
    Score();
    Score(User, int, string);

    User getUser() const;
    string getDateAndTime() const;

    string toString();
    bool isValid();
    static Score Parse(string line);

    bool operator>(const Score &s2) const;
    bool operator<(const Score &s2) const;
};

class Scoreboard {
private:
    vector<Score> scoreboard_;

    int order_;     // 0: giam dan theo diem
                    // 1: tang dan theo diem
                    // 2: loc theo User
                    //

public:
    Scoreboard();       // Khoi tao tu file, mac dinh: UserData/scoreboard/scores.txt
                        // Sau khi doc file, sap xep giam dan

    void save();        // Ghi scoreboard vao file, mac dinh: UserData/scoreboard/scores.txt
                        // Mac dinh chi luu lai nhieu nhat 100 scores
                        // Chi thuc hien khi order_ = 0 hoac order_ = 1
                        // Sap xep giam dan scoreboard_ truoc khi ghi va`o file

    void sort(bool isInc);    // Sap xep tang dan neu tham so la true, nguoc lai tham so la false

    Scoreboard UserScoreboard(User current_user);   // Tra ve scoreboard theo nguoi dung
                                                    // order_ = 2

    void add(Score new_score);

    void remove(User);                          // Xoa du lieu nguoi dung
    void remove(User, string date_and_time);    // Xoa mot Score cu the
    void removeAll();

    vector<Score> getList(int from, int to) const;      // Tra ve scoreboard_[from -> to]
    int MaxPage() const;                                // So trang toi da (mac dinh 5 Score 1 trang, xem constants.h)
    vector<Score> getPage(int page_number) const;       // Tra ve cac Score cua trang thu n


};
