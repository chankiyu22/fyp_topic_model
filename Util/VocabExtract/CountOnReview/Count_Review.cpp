#include "Count_Review.h"

void linkVocabToCount(Intstr* head, int* vocab_count) {
  Intstr* it = head;
  int i = 0;
  while (it != NULL) {
    Str_cell* sit = it->strCell();
    while (sit != NULL) {
      sit->linkToCount(vocab_count + i);
      i++;
      sit = sit->next();
    }
    it = it->next();
  }
} 

void addCount(const string& word, Intstr* head) {
  char* s = new char[word.size() + 1];
  strcpy(s, word.c_str());
  s[stem(s, 0, word.size() - 1) + 1] = 0;
  int sum = 0;

  for (int i = 0; i < word.size(); i++) {
    sum += (int)s[i];
  }
  for (Intstr* it = head; it != NULL; it = it->next()) {
    if (sum == it->strSum()) {
      for (Str_cell* sit = it->strCell(); sit != NULL; sit = sit->next()) {
        char* t = new char[strlen(sit->str()) + 1];
        strcpy(t, sit->str());
        t[stem(t, 0, strlen(sit->str()) - 1) + 1] = 0;
        if (!strcmp(s, t)) {
          sit->addCount();
          delete t, s;
          return;
        }
        delete t;
      }
    }
  }
  delete s;
}

void initializeCount(Intstr* intstr) {
  Intstr* it = intstr;
  while (it != NULL) {
    Str_cell* sit = intstr->strCell();
    while (sit != NULL) {
      sit->setZero();
      sit = sit->next();
    } 
    it = it->next();
  }
}

int getNumVocab(Intstr* head) {
  int num = 0;
  Intstr* it = head;
  while (it != NULL) {
    Str_cell* sit = it->strCell();
    while (sit != NULL) {
      num++;
      sit = sit->next();
    }
    it = it->next();
  }
  return num;
}

int getExistVocab(int* count_list, int max) {
  int sum = 0;
  for (int i = 0; i < max; i++) {
    if (count_list[i] != 0)
      sum++;
  }
  return sum;
}

void printCounts(Intstr* intstr, int* count_list, ofstream& ofs) {
  ofs << getExistVocab(count_list, getNumVocab(intstr)) << ' ';
  Intstr* it = intstr;
  for (int i = 0; i < getNumVocab(intstr); i++) {
    if (count_list[i] != 0)
      ofs  << i << ':' << count_list[i] << ' ';
  }
  ofs << endl;
}

int findEndPosition(const string& start) {
  int p = 0;
    for (p; start[p] != ' ' && 
          start[p] != '\"' &&
          start[p] != ',' &&
          start[p] != '\\' &&
          start[p] != '\'' &&
          start[p] != '.' &&
          start[p] != '!' &&
          start[p] != '/' &&
          start[p] != '?' &&
          start[p] != ')' &&
          p < start.size(); p++);
  return p;
}
      
void countVocabs(ifstream& ifs, Intstr* intstr) {
  locale loc;
  string token;
  string word;
  ofstream ofs("ap.dat");

  int total_num_vocab = getNumVocab(intstr);
  int* vocab_count = new int[total_num_vocab];

  linkVocabToCount(intstr, vocab_count);

  while (!ifs.eof()) {
    ifs >> token;
    /** Start To See Document When See "text": **/
    if (strcmp(token.c_str(), "\"text\":") == 0) {

      /** Initialize the integer array **/
      for (int i = 0; i < total_num_vocab; i++) {
        vocab_count[i] = 0;
      }

      while (!ifs.eof()) {
        ifs >> token;

        /** Break When See "type": token **/
        if (strcmp(token.c_str(), "\"type\":") == 0) {
          printCounts(intstr, vocab_count, ofs);
          break;
        }

        /** For each token, extract words from unformatted string **/
        for (int i = 0; i < token.size(); i++) {
          if (!isalpha(token[i]))
            continue;
          else {
            int length = findEndPosition(token.substr(i, token.size()));
            word = token.substr(i, length);
            word[0] = toupper(word[0]);
            for (int z = 0; z < word.size(); z++) {
              if (word[z] == '-')
                word[z+1] = toupper(word[z+1]);
            }
            addCount(word.c_str(), intstr);
            i = i + length + 1;
          }
        }
      } 
    }
  }
}
