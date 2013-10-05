#include "Intstr.h"

Intstr::Intstr() {
  sum = 0;
  _str_cell = NULL;
  _next = NULL;
}

void Intstr::insert(char* str) {
 
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

void insert(Intstr* start, char* str) {
  int strsum = 0;
  /** TODO: Cal the string sum **/

  for (Intstr* it = start; it != NULL; it = it->next()) {
    if (strsum == it->strSum()) {
      if (exists(str)) ;
      else
        /** TODO: create new Str_cell **/

    } else if (strsum > it->strSum() && it->next() == NULL) {
      /** TODO: create new Intstr cell and Str_cell **/
    } else if (strsum > it->strSum() && strsum < it->next()->strSum()) {
      /** TODO: insert Intstr cell between two cells **/
    }
  }
}
