#ifndef count_review_h
#define count_review_h
#include "../Intstr.h"
#include "../VocabExtract/vocabextract.h"
#include <locale>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <fstream>
using namespace std;

/**
 * Count On Reviews
 *
 * Functions of counting vocabs from a bunch of documents
 */
void linkVocabToCount(Intstr*, int*);

void addCount(char*, Intstr*);

void countVocabs(ifstream&, Intstr*);

#endif
