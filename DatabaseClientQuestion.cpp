#include "DatabaseClientQuestion.h"
#include "io.h"

void DatabaseClientQuestion::read() {
  string type_dir_path = BASE_DIR + "/" + m_type + "/";
  DIR* question_dir = nullptr;
  dirent* file = nullptr;

  for (int i = 0; i < 7; i++)
    for (int j = 0; j < 2; j++) {
      string question_dir_path =
          type_dir_path + TOPIC[i] + "/" + REQUIRED[j] + "/";
      string file_path;

      question_dir = opendir(question_dir_path.c_str());
      if (!question_dir) continue;

      while ((file = readdir(question_dir)) != nullptr &&
             string{file->d_name}.length() > 2) {
        file_path = question_dir_path + file->d_name;
        this->topic[i].push_back(
            Question{QuestionLoader::Load(file_path, (bool)j)});
      }

      closedir(question_dir);
    }
}