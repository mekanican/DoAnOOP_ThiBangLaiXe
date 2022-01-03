#include "io.h"

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

string getFileName(string file_path) {
  size_t found = file_path.find_last_of("/");
  if (found == string::npos) return file_path;
  return file_path.substr(found + 1);
}

int getFileIndex(string file_name) {
  size_t start = file_name.find("_");
  size_t end = file_name.find(".txt");
  if (start < end) return stoi(file_name.substr(start + 1, end - start - 1));

  return -1;
}

Question QuestionLoader::Load(string file_path, bool is_required, int id) {
  try {
    fstream question_file(file_path, ios_base::in);

    if (!question_file.is_open() || question_file.bad())
      throw runtime_error("Log: Cant open question file: " + file_path);

    string questionText;
    int n, rightAnswer;
    string tmp;
    vector<string> answerText;
    string image_path;
    string tip;

    getline(question_file, questionText);
    getline(question_file, tmp);
    n = stoi(tmp);

    for (int i = 0; i < n; i++) {
      getline(question_file, tmp);
      answerText.push_back(tmp);
    }

    getline(question_file, tmp);
    rightAnswer = stoi(tmp);

    if (!question_file.eof()) {
      getline(question_file, tmp);
      if (tmp.find("image/") == string::npos)
        tip = tmp;
      else {
        image_path = tmp;
        if (!question_file.eof() && question_file.good())
          getline(question_file, tip);
      }
    }

    question_file.close();

    return Question{id,          questionText, image_path, answerText,
                    rightAnswer, tip,          is_required};
  } catch (const std::exception& e) {
    cerr << e.what() << '\n';
    return Question{};
  }
}
