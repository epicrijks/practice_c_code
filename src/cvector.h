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

#define MAX_VECTOR_SIZE 1024

typedef struct {
  int _size;
  int _capacity;
  int* _data;
} cvector;

/*
 * Function:  createCVector
 * --------------------
 * creates a cvector
 *
 * capacity: the initial number of elements to store
 *
 *  returns: pointer to cvector
 *           NULL if capacity < 1 or unable to allocate memory
 */
cvector* createCVector(int capacity);


void destroyCVector(cvector* v);


// ! Remove after testing and set to static in cvector.c
int getPow2Capacity(int c);
#endif