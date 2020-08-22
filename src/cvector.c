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
    }
    free(v);
  }
}

// ! Make static before after testing
unsigned int getPow2Capacity(unsigned int c) {
  unsigned int cap = 8;
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