#include <assert.h>
#include "matrix.h"
#include "matrix.c"

void test_pushBack_emptyVector() {
    vector v = createVector(0);
    pushVectorBack(&v, 1);

    assert(getVectorValue(&v, 0) == 1);
    assert(v.size == 1);
    assert(v.capacity == 1);
    deleteVector(&v);
}

void test_pushBack_fullVector() {
    vector v = createVector(0);
    pushVectorBack(&v, 1);
    pushVectorBack(&v, 2);

    assert(getVectorValue(&v, 1) == 2);
    assert(v.size == 2);
    assert(v.capacity == 2);
    deleteVector(&v);
}

void test_pushBack_notEmptyNotFullVector() {
    vector v = createVector(0);
    pushVectorBack(&v, 1);
    pushVectorBack(&v, 2);
    pushVectorBack(&v, 3);
    pushVectorBack(&v, 4);

    assert(getVectorValue(&v, 3) == 4);
    assert(v.size == 4);
    assert(v.capacity == 4);
    deleteVector(&v);
}

void tests_pushVectorBack() {
    test_pushBack_emptyVector();
    test_pushBack_fullVector();
    test_pushBack_notEmptyNotFullVector();
}

//======================================================================================================================

void test_popBack_notEmptyVector() {
    vector v = createVector(0);
    pushVectorBack(&v, 10);

    assert(v.size == 1);
    popVectorBack(&v);
    assert(v.size == 0);
    assert(v.capacity == 1);
}

void tests_popVectorBack() {
    test_popBack_notEmptyVector();
}

//======================================================================================================================

void test_createVector_emptyCapacity() {
    vector v = createVector(0);

    assert(v.size == 0);
    assert(v.capacity == 0);
    deleteVector(&v);
}

void test_createVector_notEmptyCapacity() {
    vector v = createVector(6);

    assert(v.size == 0);
    assert(v.capacity == 6);
    deleteVector(&v);
}

void tests_createVector() {
    test_createVector_emptyCapacity();
    test_createVector_notEmptyCapacity();
}

//======================================================================================================================

void test_reserveVector_newEmptyCapacity() {
    vector v = createVector(3);
    reserveVector(&v, 0);

    assert(v.capacity == 0);
    assert(v.size == 0);
    assert(v.data == NULL);
    deleteVector(&v);
}

void test_reserveVector_newCapacityMoreThenSize() {
    vector v = createVector(1);
    pushVectorBack(&v, 2);
    reserveVector(&v, 3);

    assert(v.capacity == 3);
    assert(v.size == 1);
    deleteVector(&v);
}

void test_reserve_newCapacityLessThenSize() {
    vector v = createVector(2);
    pushVectorBack(&v, 2);
    pushVectorBack(&v, 3);
    reserveVector(&v, 1);

    assert(v.capacity == 1);
    assert(v.size == 1);
    deleteVector(&v);
}

void tests_reserveVector() {
    test_reserveVector_newEmptyCapacity();
    test_reserveVector_newCapacityMoreThenSize();
    test_reserve_newCapacityLessThenSize();
}

//======================================================================================================================

void test_clear_notEmptyVector() {
    vector v = createVector(2);
    pushVectorBack(&v, 2);
    pushVectorBack(&v, 3);
    clearVector(&v);

    assert(v.size == 0);
    assert(v.capacity == 2);
    deleteVector(&v);
}

void tests_clearVector() {
    test_clear_notEmptyVector();
}

//======================================================================================================================

void test_shrinkVectorToFit() {
    vector v = createVector(4);
    v.size = 2;
    shrinkVectorToFit(&v);

    assert(v.size == v.capacity);
    deleteVector(&v);
}

void test_shrinkEmptyVectorToFit() {
    vector v = createVector(5);
    shrinkVectorToFit(&v);

    assert(isVectorFull(&v));
    deleteVector(&v);
}

void test_shrinkFullVectorToFit() {
    vector v = createVector(1);
    pushVectorBack(&v, 3);
    shrinkVectorToFit(&v);

    assert(isVectorFull(&v));
    deleteVector(&v);
}

void tests_shrinkVectorToFit() {
    test_shrinkVectorToFit();
    test_shrinkEmptyVectorToFit();
    test_shrinkFullVectorToFit();
}

//======================================================================================================================

void test_isVectorEmpty() {
    vector v = createVector(4);

    assert(isVectorEmpty(&v));
    deleteVector(&v);
}

void test_isVectorFull() {
    vector v = createVector(4);
    v.size = 4;

    assert(isVectorFull(&v));
    deleteVector(&v);
}

void tests_isVectorEmptyOrFull() {
    test_isVectorEmpty();
    test_isVectorFull();
}

//======================================================================================================================

void test_getVectorValue() {
    vector v = createVector(10);
    v.data[10] = 12;

    assert(getVectorValue(&v, 10) == v.data[10]);
    deleteVector(&v);
}

void tests_getVectorValue() {
    test_getVectorValue();
}

//======================================================================================================================

void test_atVector_notEmptyVector() {
    vector v = createVector(0);
    pushVectorBack(&v, 1);
    pushVectorBack(&v, 2);
    pushVectorBack(&v, 3);

    assert(atVector(&v, 1) == v.data + 1);
    deleteVector(&v);
}

void tests_atVector() {
    test_atVector_notEmptyVector();
}

//======================================================================================================================

void test_back_oneElementInVector() {
    vector v = createVector(0);
    pushVectorBack(&v, 1);

    assert(back(&v) == v.data + v.size - 1);
    deleteVector(&v);
}

void test_back_multipleElements() {
    vector v = createVector(0);
    pushVectorBack(&v, 1);
    pushVectorBack(&v, 2);
    pushVectorBack(&v, 3);

    assert(back(&v) == v.data + v.size - 1);
    deleteVector(&v);
}

void tests_back() {
    test_back_oneElementInVector();
    test_back_multipleElements();
}

//======================================================================================================================

void test_front_oneElementInVector() {
    vector v = createVector(0);
    pushVectorBack(&v, 1);

    assert(front(&v) == v.data);
    deleteVector(&v);
}

void test_front_multipleElements() {
    vector v = createVector(0);
    pushVectorBack(&v, 1);
    pushVectorBack(&v, 2);
    pushVectorBack(&v, 3);

    assert(front(&v) == v.data);
    deleteVector(&v);
}

void tests_front() {
    test_front_oneElementInVector();
    test_front_multipleElements();
}

//======================================================================================================================
//Global test vector:
void test_vector() {
    tests_createVector();
    tests_reserveVector();
    tests_clearVector();
    tests_shrinkVectorToFit();
    tests_pushVectorBack();
    tests_popVectorBack();
    tests_getVectorValue();
    tests_isVectorEmptyOrFull();
    tests_atVector();
    tests_back();
    tests_front();
}

//MATRIX_TESTS==========================================================================================================

matrix createMatrixFromArray(const int *a, int nRows, int nCols) {
    matrix m = getMemMatrix(nRows, nCols);

    int k = 0;
    for (int i = 0; i < nRows; i++)
        for (int j = 0; j < nCols; j++)
            m->values[i][j] = a[k++];

    return m;
}

void test_countZeroRows() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 1, 0,
                    0, 0, 0,
                    0, 0, 1,
                    0, 0, 0,
                    0, 1, 1,
            },
            5, 3
    );

    assert (countZeroRows(m, 5, 3) == 2);

    freeMemMatrix(m, 5);
}
