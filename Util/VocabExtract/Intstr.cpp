#include "Intstr.h"

Intstr::Intstr() {
  sum = 0;
  _str_cell = NULL;
  _next = NULL;
}

Intstr::Intstr(int sum, char* str){
  this->sum = sum;
  _str_cell = new Str_cell(str);
  _next = NULL;
}

int Intstr::strSum() {
  return sum;
}

Str_cell* Intstr::strCell() {
  return _str_cell;
}

Intstr* Intstr::next() {
  return _next;
}

void Intstr::setNext(Intstr* next_cell) {
  _next = next_cell;
}

bool exists(Intstr* intstr, char* str) {
  for (Str_cell* it = intstr->strCell(); it != NULL; it = it->next())
    if (!strcmp(it->str(), str)) {
      return true;
    }
  return false;
}

Str_cell* tail(Intstr* intstr_cell) {
  Str_cell* it = intstr_cell->strCell();
  while (it->next() != NULL)
    it = it->next();
  return it;
}

void insert(Intstr*& start, char* str) {
  int strsum = 0;
  /** TODO: Cal the string sum **/
  int size = strlen(str);
  for (int i = 0; i < size; i++) {
    strsum += (int)str[i];
  }

  for (Intstr* it = start; it != NULL; it = it->next()) {
    if (it == start && strsum < it->strSum()) {
      Intstr* new_cell = new Intstr(strsum, str);
      new_cell->setNext(start);
      start = new_cell;
    } else if (strsum == it->strSum()) {
      if (exists(it, str)) ;
      else{
        /** TODO: create new Str_cell **/
        Str_cell* end = tail(it);
        Str_cell* new_cell = new Str_cell(str);
        end->setNext(new_cell);
      }
    } else if (strsum > it->strSum() && it->next() == NULL) {
      /** TODO: create new Intstr cell and Str_cell **/
      Intstr* new_cell = new Intstr(strsum, str);
      it->setNext(new_cell);
    } else if (strsum > it->strSum() && strsum < it->next()->strSum()) {
      /** TODO: insert Intstr cell between two cells **/
      Intstr* new_cell = new Intstr(strsum, str);
      new_cell->setNext(it->next());
      it->setNext(new_cell);
    }
  }
}
