#include <stdlib.h>
#include "cvector.h"

cvector* createCVector(unsigned int capacity) {
  cvector* rVector = NULL; /* Pointer to return */
  if ( capacity < 1 || capacity >= MAX_VECTOR_SIZE ) {
    rVector = NULL;
  } else {
    rVector = (cvector*)malloc(sizeof(cvector));
    
    if ( rVector != NULL ) {
      rVector->_capacity = getPow2Capacity(capacity);
      rVector->_size = 0;
      rVector->_data = (int*)malloc(rVector->_capacity*sizeof(int));

      if ( rVector->_data == NULL ) {
        rVector == NULL;
      }
    }
  }
  return rVector;
}

void destroyCVector(cvector* v) {
  if ( v != NULL ) {
    if ( v->_data != NULL) {
      free(v->_data);
      v->_data = NULL;
    }
    free(v);
    v = NULL;
  }
}

unsigned int sizeCVector(cvector* v) {
  unsigned int size = 0;
  if (v != NULL) {
    size = v->_size;
  }
  return size;
}

unsigned int capacityCVector() {
  return MAX_VECTOR_SIZE;
}

short int isEmptyCVector(cvector* v) {
  short int empty = 1;
  if ( v != NULL && v->_size > 0 ) {
    empty = 0;
  }
  return empty;
}

int atCVector(cvector* v, int pos) {}

// ! Make static before after testing
unsigned int getPow2Capacity(unsigned int c) {
  unsigned int cap = MIN_VECTOR_SIZE;
  if ( c > cap ) {
    cap = c;
    if ( !(cap && !(cap&(cap-1))) ) {/* If cap is not a power of two... */
      int count = 0;                /* Keep track of shifts */
      while (cap != 0) {
        cap = cap >> 1;             /* Shift bits until a power of two is found */
        ++count;
      }
      cap = 1 << count;             /* Shift the remaining 1 back to the next pow of 2 */
    }
  }
  return cap;
}