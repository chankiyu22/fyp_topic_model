#include <iostream>
#include <fstream>
#include "Intstr.h"
using namespace std;

int findEndPosition(char* start) {
  int p = 0;
  for (p; start[p] != ' ' && start[p] != '\"'; p++);
  return p;
}

void printVocabs(Intstr* start) {
  Intstr* it = start;
  Str_cell* sit;
  while (it != NULL) {
    // cout << it->strSum() << endl;
    sit = it->strCell();
    while (sit != NULL) {
      cout << '\t' << sit->str() << endl;
      sit = sit->next();
    }
    it = it->next();
  }
}
    

Intstr* extractVocab(ifstream& ifs) {
  char str[1024];
  Intstr* start = NULL;
  while (!ifs.eof()) {
    ifs.getline(str, 1024);
    
    for (int k = 0; k < strlen(str); k++) {
      if (!strncmp(str + k, "\"categories\":", 13)) {
        for (int i = k + 15; str[i] != ']'; i++) {
          if (str[i] == '\"' || str[i] == ' ') {
            /** TODO: Implement findEndPosition(char*)  **/
            int l = findEndPosition(str + i + 1); 
            int sum = 0;
            for (int z = 0; z < l; z++)
              sum += (int)str[i + z + 1];
            string vocab(str + i + 1, l);
            char* vocab_cstr = new char[vocab.length() + 1];
            strcpy(vocab_cstr, vocab.c_str());

            if (start == NULL)
              start = new Intstr(sum, vocab_cstr);
            else
              insert(start, vocab_cstr);

            if (!strncmp(str + i + l + 1, "\"]", 2))
              break;
            if (str[i + l + 1] == '\"')
              i = i + l + 3;
            else
              i = i + l;
          }
        }
        break;
      }
    }
  }
  return start;
}

int main(int argc, char* argv[]) {
  if (argc == 1)
    return 0;

  ifstream ifs;
  ifs.open(argv[1]);

  Intstr* intstr = NULL;
  intstr = extractVocab(ifs);

  printVocabs(intstr);

  return 0;
}
