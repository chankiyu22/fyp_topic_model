#ifndef strcell_h
#define strcell_h
#include <cstddef>
#include "string.h"

class Str_cell {
public:
  Str_cell();
  Str_cell(char* );

  char* str();
  Str_cell* next();

  void setNext(Str_cell* nextCell);
private:
  char* _str;
  Str_cell* _next;
};

#endif
