#include "DatabaseQuestion.h"

#include "../Utility/io.h"

#undef UNICODE
#undef _UNICODE
#include "../Utility/tinydir.h"
#include "../Utility/utility.h"

void DatabaseQuestion::read() {
  string type_dir_path = BASE_DIR + "/" + Types[(int)m_type] + "/";

  for (int i = 0; i < 7; i++)
    for (int j = 0; j < 2; j++) {
      int id = idComposer((int)m_type, i);

      string question_dir_path =
          type_dir_path + TOPIC[i] + "/" + REQUIRED[j] + "/";

      tinydir_dir dir;
      tinydir_open_sorted(&dir, question_dir_path.c_str());
      for (int k = 2; k < (int)dir.n_files; k++) {
        tinydir_file file;
        tinydir_readfile_n(&dir, &file, k);
        this->m_topic[i].push_back(
            QuestionLoader::Load(question_dir_path + file.name, !(bool)j, id));
      }
      tinydir_close(&dir);
    }
}

void DatabaseQuestion::reload(Type newType) {
  if (newType == m_type)
    return;  // Duplicated
             // Clear everything
  for (int i = 0; i < 7; i++) m_topic[i].clear();
  m_type = newType;
  read();  // Calling read again
}
