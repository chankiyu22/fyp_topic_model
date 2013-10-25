#include "vocabextract.h"

int findEndPosition(char* start) {
  int p = 0;
  for (p; start[p] != ' ' && 
          start[p] != '\"' &&
          start[p] != ',' &&
          start[p] != '\\' &&
          start[p] != '\'' &&
          start[p] != '.' &&
          start[p] != '!' &&
          start[p] != ')' &&
          start[p] != '/' ; p++);
  return p;
}

Intstr* extractVocab(ifstream& ifs) {
  locale loc;
  char str[1024];
  Intstr* start = NULL;
  while (!ifs.eof()) {
    ifs.getline(str, 1024);
    
    for (int k = 0; k < strlen(str); k++) {
      if (!strncmp(str + k, "\"categories\":", 13)) {
        for (int i = k + 15; str[i] != ']'; i++) {
          if (!isalpha(str[i])) {
            continue;
          } else {
            /** TODO: Implement findEndPosition(char*)  **/
            int l = findEndPosition(str + i); 

            string vocab(str + i, l);

            /** string s for stemming process **/
            char* vocab_cstr = new char[vocab.length() + 1];
            char* s = new char[vocab.length() + 1];

            strcpy(vocab_cstr, vocab.c_str());
            strcpy(s, vocab.c_str());

            s[stem(s, 0, vocab.size() - 1) + 1] = 0;
            
            int sum = 0;

            for (int z = 0; z < vocab.size(); z++) {
              sum += (int)s[z];
            }
        
            if (start == NULL)
              start = new Intstr(sum, vocab_cstr);
            else
              insert(start, sum, vocab_cstr);

            if (!strncmp(str + i + l, "\"]", 2))
              break;

            i = i + l;
            delete[] s, vocab_cstr;
          }
        }
        break;
      }
    }
  }
  return start;
}

void printVocabs(Intstr* start) {
  ofstream ofs("vocab.txt");
  Intstr* it = start;
  Str_cell* sit;
  while (it != NULL) {
    // cout << it->strSum() << endl;
    sit = it->strCell();
    while (sit != NULL) {
      ofs << sit->str() << endl;
      sit = sit->next();
    }
    // cout << endl;
    it = it->next();
  }
}
