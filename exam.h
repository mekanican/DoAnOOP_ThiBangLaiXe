#ifndef EXAM_H_
#define EXAM_H_
 
#include <fstream>
#include <vector>
#include <ctime>
#include "user.h"
 
using std::fstream;
using std::vector;
 
struct ExamComponents
{
    int question_count;
    int minimum_correct_answer;
    int time_allowed;
 
    int required_count;
    int topic_count[7];
};
 
const ExamComponents kExamComponents[10] =
    {
        {25, 21, 19 * 60, 1, {8, 0, 1, 1, 0, 7, 7}},   // A1
        {25, 23, 19 * 60, 1, {8, 0, 1, 1, 0, 7, 7}},   // A2
        {25, 23, 19 * 60, 1, {8, 0, 1, 1, 0, 7, 7}},   // A3
        {25, 23, 19 * 60, 1, {8, 0, 1, 1, 0, 7, 7}},   // A4
        {30, 27, 20 * 60, 1, {8, 0, 1, 1, 1, 9, 9}},   // B1
        {35, 32, 22 * 60, 1, {9, 1, 1, 2, 1, 10, 10}}, // B2
        {40, 36, 24 * 60, 1, {9, 1, 1, 2, 1, 14, 11}}, // C
        {45, 41, 26 * 60, 1, {9, 1, 1, 2, 1, 16, 14}}, // D
        {45, 41, 26 * 60, 1, {9, 1, 1, 2, 1, 16, 14}}, // E
        {45, 41, 26 * 60, 1, {9, 1, 1, 2, 1, 16, 14}}  // F
};
 
class QuestionPack {};
 
class Question {};
 
class Timer
{
private:
    clock_t start_;
    clock_t timer_limit_;
 
 
public:
    Timer();
    Timer(double seconds);
    void start();
    void set(double seconds);
 
    double Time();
    double TimeLeft();
 
    bool Ended();
    void reset();
};
 
class ExamInfo		// reusable in leaderboard
{
private:
    User user_;
 
    int license_type_;
    int exam_topic_;
    int exam_mode_;
 
    int questions_count_;
    int correct_count_;
 
    double time_taken_;
 
    bool passed_;
 
public:
    ExamInfo(User user, int license_type, int exam_topic);
    bool load(fstream &record_file);
    bool load(const string &file_path);
 
    friend class Exam;
};
 
class Exam
{
private:
    ExamInfo info_;
    vector<Question> questions_;
    vector<int> questions_status_; // 0 if unanswered, 1 if corerct, otherwise -1
 
    double allowed_time_;
    Timer exam_timer_;
 
public:
    Exam(const QuestionPack &pack);                 //        Basic exam
    // Exam(const QuestionPack &pack, int exam_topic); // 0 - 6: Topic exam
                                                    //     7: required question only
    void startAttempt();
 
};
 
#endif
