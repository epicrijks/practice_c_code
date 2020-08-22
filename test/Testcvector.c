#include <stdlib.h>

#include "unity.h"
#include "cvector.h"

cvector* testVector = NULL;

void setUp (void) {} /* Is run before every test, put unit init calls here. */

void tearDown(void) {} /* Is run after every test, put unit clean-up calls here. */
//   if (testVector != NULL) {
//     free(testVector);
//     testVector = NULL;
//   }
// } 

// Used to destory testVector is tests only. 
void destroyTestVector() {
  if ( testVector != NULL ) {
    if ( testVector->_data != NULL) {
      free(testVector->_data);
    }
    free(testVector);
    testVector = NULL;
  }
}

void test_createCVector_sizeShouldBeZero(void) {
  testVector = createCVector(1);
  TEST_ASSERT_EQUAL(0, testVector->_size);
  destroyTestVector();
}

void test_createCVector_capacityPowOf2AboveParamWithMin8(void) {
  testVector = createCVector(1);
  TEST_ASSERT_EQUAL(16, testVector->_capacity);
  destroyTestVector();

  testVector = createCVector(2);
  TEST_ASSERT_EQUAL(16, testVector->_capacity);
  destroyTestVector();

  testVector =  createCVector(8);
  TEST_ASSERT_EQUAL(16, testVector->_capacity);
  destroyTestVector();

  testVector = createCVector(15);
  TEST_ASSERT_EQUAL(16, testVector->_capacity);
  destroyTestVector();

  testVector = createCVector(16);
  TEST_ASSERT_EQUAL(16, testVector->_capacity);
  destroyTestVector();

  testVector = createCVector(17);
  TEST_ASSERT_EQUAL(32, testVector->_capacity);
  destroyTestVector();
}

void test_createCVector_returnsNullIfCapacityLessThan1(void) {
  testVector = createCVector(0);
  TEST_ASSERT_NULL(testVector);

  testVector = createCVector(-1);
  TEST_ASSERT_NULL(testVector);
}

void test_createCVector_returnsNullIfCapacityGreaterThanIntMax(void) {
  testVector = createCVector(MAX_VECTOR_SIZE);
  TEST_ASSERT_NULL(testVector);
}

void test_sizeCVector_sizeShouldBeSizeVariableInVector(void) {
  testVector = NULL;
  TEST_ASSERT_EQUAL(0, sizeCVector(testVector));

  // Set up vector and test for memory allocation
  testVector = (cvector*)malloc(sizeof(cvector));
  TEST_ASSERT_NOT_NULL_MESSAGE(testVector, "unable to allocate memory for vector");

  testVector->_size = 0;
  TEST_ASSERT_EQUAL(0, sizeCVector(testVector));

  testVector->_size = 5;
  TEST_ASSERT_EQUAL(5, sizeCVector(testVector));

  destroyTestVector();
}

void test_capacityCVector_shouldReturnMaxCapacityAsDeclaredInMacros(void) {
  TEST_ASSERT_EQUAL(2048, capacityCVector()); /* MAX_VECTOR_SIZE defined in cvector.h macros */
} 

// ! This is a static funtion that will not be included in future tests.
// ! comment out after testing
void test_getPow2Capacity(void) {
  TEST_ASSERT_EQUAL(16, getPow2Capacity(1));
  TEST_ASSERT_EQUAL(16, getPow2Capacity(2));
  TEST_ASSERT_EQUAL(16, getPow2Capacity(3));
  TEST_ASSERT_EQUAL(16, getPow2Capacity(8));
  TEST_ASSERT_EQUAL(16, getPow2Capacity(15));
  TEST_ASSERT_EQUAL(16, getPow2Capacity(16));
  TEST_ASSERT_EQUAL(32, getPow2Capacity(17));
}

int main(void) {
  UNITY_BEGIN();
  RUN_TEST(test_createCVector_sizeShouldBeZero);
  RUN_TEST(test_createCVector_capacityPowOf2AboveParamWithMin8);
  RUN_TEST(test_createCVector_returnsNullIfCapacityLessThan1);
  RUN_TEST(test_createCVector_returnsNullIfCapacityGreaterThanIntMax);
  RUN_TEST(test_getPow2Capacity); // ! comment out after testing
  RUN_TEST(test_sizeCVector_sizeShouldBeSizeVariableInVector);
  RUN_TEST(test_capacityCVector_shouldReturnMaxCapacityAsDeclaredInMacros);
  return UNITY_END();
}

