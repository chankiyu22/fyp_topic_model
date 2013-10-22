#ifndef vocabextract_h
#define vocabextract_h

#include "../Intstr.h"
#include <fstream>
using namespace std;

/**
 * VocabExtract
 *
 * Functions to extract vocabs from specific JSON File
 */
int findEndPosition(char*);

Intstr* extractVocab(ifstream& ifs);

void printVocabs(Intstr* start);

#endif
