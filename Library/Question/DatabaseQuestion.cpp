#include "DatabaseQuestion.h"

#include "../Utility/io.h"

#undef UNICODE
#undef _UNICODE
#include "../Utility/tinydir.h"

void DatabaseQuestion::read() {
  string type_dir_path = BASE_DIR + "/" + m_type + "/";

  for (int i = 0; i < 7; i++)
    for (int j = 0; j < 2; j++) {
      string question_dir_path =
          type_dir_path + TOPIC[i] + "/" + REQUIRED[j] + "/";

      tinydir_dir dir;
      tinydir_open_sorted(&dir, question_dir_path.c_str());
      for (int k = 2; k < (int)dir.n_files; k++) {
        tinydir_file file;
        tinydir_readfile_n(&dir, &file, k);
        this->topic[i].push_back(Question{
            QuestionLoader::Load(question_dir_path + file.name, (bool)j)});
      }
      tinydir_close(&dir);
    }
}
