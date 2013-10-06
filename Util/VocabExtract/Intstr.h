#ifndef intstr_h
#define intstr_h

#include "Str_cell.h"
class Intstr {
public:
  Intstr();
  Intstr(int sum, char* str);
  int strSum();

  Str_cell* strCell();
  Intstr* next();

  void setNext(Intstr* next_cell);
private:
  int sum;
  Str_cell* _str_cell;
  Intstr* _next;
};

void insert(Intstr*& start, char* str);
#endif
