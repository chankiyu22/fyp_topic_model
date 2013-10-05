#include <fstream>
#include "Intstr.h"
using namespace std;

int main(int argc, char* argv[]) {
  if (argc == 1)
    return 0;

  ifstream ifs;
  ifs.open(argv[1]);

  Intstr* intstr = new intstr;
  intstr = extractVocab(ifs);

  return 0;
}
