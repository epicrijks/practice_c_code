/************************************************************************
*  FILENAME : cvector.h
*
* DESCRIPTION :
*       Integer vector interface.
*
* PUBLIC FUNCTIONS :
*       cvector* createCVector(int capacity)
*
* NOTES :
*       These functions are a part of the FM suite;
*       See IMS FM0121 for detailed description.
*
* AUTHOR :    https://github.com/epicrijks        START DATE :    21 Aug 2020
*
***/

#ifndef _C_VECCTOR_H_
#define _C_VECCTOR_H_

#define MIN_VECTOR_SIZE 16
#define MAX_VECTOR_SIZE 2048

typedef struct {
  unsigned int _size;
  unsigned int _capacity;
  int* _data;
} cvector;

/*
 * Function:  createCVector
 * --------------------
 * creates a cvector
 *
 * capacity: the initial number of elements to store
 *
 * returns: pointer to cvector
 *           NULL if capacity < 1 or unable to allocate memory
 */
cvector* createCVector(unsigned int capacity);

/*
 * Function:  destroyCVector
 * --------------------
 * frees memory for vector and associated data
 *
 * returns: void
 */
void destroyCVector(cvector* v);

/*
 * Function:  sizeCVector
 * --------------------
 * returns number of elements in vector v
 *
 * returns: number of elements in vector v
 */
unsigned int sizeCVector(cvector* v);

/*
 * Function:  capacityCVector
 * --------------------
 * returns max number of elements any cvector can hold
 *
 * returns: max number of elements any cvector can hold
 */
unsigned int capacityCVector();

// ! Remove after testing and set to static in cvector.c
unsigned int getPow2Capacity(unsigned int c);
#endif