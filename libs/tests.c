#include <assert.h>
#include "data_structures/matrix/matrix.h"
#include "data_structures/vector/vector.h"
#include "tasks.c"

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

void test_getMemMatrix_zeroElements() {
    matrix m = getMemMatrix(0, 0);

    assert(m.nRows == 0);
    assert(m.nCols == 0);
    freeMemMatrix(&m);
}

void test_getMemMatrix_moreZeroElements() {
    matrix m = getMemMatrix(7, 8);

    assert(m.nRows == 7);
    assert(m.nCols == 8);
    freeMemMatrix(&m);
}

void tests_getMemMatrix() {
    test_getMemMatrix_zeroElements();
    test_getMemMatrix_moreZeroElements();
}

//======================================================================================================================

void test_getMemArrayOfMatrices_notEmptyArray() {
    int size = 5;
    matrix *m = getMemArrayOfMatrices(size, 6, 4);

    assert(m->nRows == 6);
    assert(m->nCols == 4);
    freeMemMatrices(m, size);
}

void tests_getMemArrayOfMatrices() {
    test_getMemArrayOfMatrices_notEmptyArray();
}

//======================================================================================================================

void test_freeMemMatrix_moreZeroElements() {
    matrix m = getMemMatrix(5, 6);
    freeMemMatrix(&m);

    assert(m.nRows == 0);
    assert(m.nCols == 0);
    assert(m.values == NULL);
}

void tests_freeMemMatrix() {
    test_freeMemMatrix_moreZeroElements();
}

//======================================================================================================================

void test_swapRows_oneCol() {
    matrix m = createMatrixFromArray(
            (int[]) {
                1,
                2,
                3
            },
            3, 1);
    matrix expectedResult = createMatrixFromArray(
            (int[]) {
                3,
                2,
                1
            },
            3, 1);
    swapRows(&m, 0, 2);

    assert(areTwoMatricesEqual(&m, &expectedResult));
    freeMemMatrix(&m);
    freeMemMatrix(&expectedResult);
}

void test_swapRows1() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    9, 5, 6,
                    1, 9, 8,
                    48, 6, 14
            },
            3, 3);
    matrix expectedResult = createMatrixFromArray(
            (int[]) {
                    9, 5, 6,
                    48, 6, 14,
                    1, 9, 8
            },
            3, 3);

    swapRows(&m, 1, 2);

    assert(areTwoMatricesEqual(&m, &expectedResult));
    freeMemMatrix(&m);
    freeMemMatrix(&expectedResult);
}

void test_swapRows2() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    3, 8, 7,
                    1, 9, 2,
                    19, 4, 11
            },
            3, 3);
    matrix expectedResult = createMatrixFromArray(
            (int[]) {
                    19, 4, 11,
                    1, 9, 2,
                    3, 8, 7
            },
            3, 3);
    swapRows(&m, 0, 2);

    assert(areTwoMatricesEqual(&m, &expectedResult));
    freeMemMatrix(&m);
    freeMemMatrix(&expectedResult);
}

void tests_swapRows() {
    test_swapRows_oneCol();
    test_swapRows1();
    test_swapRows2();
}

//======================================================================================================================

void test_swapCols_oneRow() {
    matrix m = createMatrixFromArray(
            (int[]) {
                1, 9, 7
            },
            1, 3);
    matrix expectedResult = createMatrixFromArray(
            (int[]) {
                9, 1, 7
            },
            1, 3);
    swapCols(&m, 0, 1);

    assert(areTwoMatricesEqual(&m, &expectedResult));
    freeMemMatrix(&m);
    freeMemMatrix(&expectedResult);
}

void test_swapCols1() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    3, 8, 7,
                    1, 9, 2,
                    19, 4, 11
            },
            3, 3);
    matrix expectedResult = createMatrixFromArray(
            (int[]) {
                    7, 8, 3,
                    2, 9, 1,
                    11, 4, 19
            },
            3, 3);
    swapCols(&m, 0, 2);

    assert(areTwoMatricesEqual(&m, &expectedResult));
    freeMemMatrix(&m);
    freeMemMatrix(&expectedResult);
}

void test_swapCols2() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    3, 8, 7,
                    1, 9, 2,
                    19, 4, 11
            },
            3, 3);
    matrix expectedResult = createMatrixFromArray(
            (int[]) {
                    3, 7, 8,
                    1, 2, 9,
                    19, 11, 4
            },
            3, 3);
    swapCols(&m, 1, 2);

    assert(areTwoMatricesEqual(&m, &expectedResult));
    freeMemMatrix(&m);
    freeMemMatrix(&expectedResult);
}

void tests_swapCols() {
    test_swapCols_oneRow();
    test_swapCols1();
    test_swapCols2();
}

//======================================================================================================================

void test_insertionSortRowsMatrixByRowCriteria_rectangularMatrix() {
    matrix m = createMatrixFromArray(
            (int[]) {
                2, 9,
                1, 4,
                3, 7
            },
            3, 2);
    insertionSortRowsMatrixByRowCriteria(&m, getSum);
    matrix expectedResult = createMatrixFromArray(
            (int[]) {
                2, 9,
                1, 4,
                3, 7
            },
            3, 2);

    assert(areTwoMatricesEqual(&m, &expectedResult));
    freeMemMatrix(&m);
    freeMemMatrix(&expectedResult);
}

void test_insertionSortRowsMatrixByRowCriteria1() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    2, 4,
                    5, 6
            },
            2, 2);
    insertionSortRowsMatrixByRowCriteria(&m, getSum);
    matrix expectedResult = createMatrixFromArray(
            (int[]) {
                    2, 4,
                    5, 6
            },
            2, 2);

    assert(areTwoMatricesEqual(&m, &expectedResult));
    freeMemMatrix(&m);
    freeMemMatrix(&expectedResult);
}

void tests_insertionSortRowsMatrixByRowCriteria() {
    test_insertionSortRowsMatrixByRowCriteria_rectangularMatrix();
    test_insertionSortRowsMatrixByRowCriteria1();
}

//======================================================================================================================

void test_insertionSortColsMatrixByColCriteria_rectangularMatrix() {
    matrix m = createMatrixFromArray(
            (int[]) {
                1, 4,
                0, 9,
                7, 8
            },
            3, 2);
    insertionSortColsMatrixByColCriteria(&m, getSum);
    matrix expectedResult = createMatrixFromArray(
            (int[]) {
                0, 0,
                9, 0,
                1, 4
            },
            3, 2);

    assert(areTwoMatricesEqual(&m, &expectedResult));
    freeMemMatrix(&m);
    freeMemMatrix(&expectedResult);
}

void test_insertionSortColsMatrixByColCriteria1() {
    matrix m = createMatrixFromArray(
            (int[]) {
                8, 4,
                5, 9
            },
            2, 2);
    insertionSortColsMatrixByColCriteria(&m, getSum);
    matrix expectedResult = createMatrixFromArray(
            (int[]) {
                8, 4,
                5, 9
            },
            2, 2);

    assert(areTwoMatricesEqual(&m, &expectedResult));
    freeMemMatrix(&m);
    freeMemMatrix(&expectedResult);
}

void test_insertionSortColsMatrixByColCriteria2() {
    matrix m = createMatrixFromArray(
            (int[]) {
                1, 5,
                4, 8
            },
            2, 2);
    insertionSortColsMatrixByColCriteria(&m, getSum);
    matrix expectedResult = createMatrixFromArray(
            (int[]) {
                1, 5,
                4, 8
            },
            2, 2);

    assert(areTwoMatricesEqual(&m, &expectedResult));
    freeMemMatrix(&m);
    freeMemMatrix(&expectedResult);
}

void tests_insertionSortColsMatrixByColCriteria() {
    test_insertionSortColsMatrixByColCriteria_rectangularMatrix();
    test_insertionSortColsMatrixByColCriteria1();
    test_insertionSortColsMatrixByColCriteria2();
}

//======================================================================================================================

void test_isSquareMatrix1() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    9, 2, 7,
                    5, 6, 0,
                    4, 0, 0,
            },
            3, 3);

    assert(isSquareMatrix(&m));
    freeMemMatrix(&m);
}

void test_isSquareMatrix2() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    2, 4,
                    1, 5,
            },
            2, 2);

    assert(isSquareMatrix(&m));
    freeMemMatrix(&m);
}

void test_isSquareMatrix3() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 0,
                    0, 1
            },
            2, 2);

    assert(isSquareMatrix(&m));
    freeMemMatrix(&m);
}

void tests_isSquareMatrix() {
    test_isSquareMatrix1();
    test_isSquareMatrix2();
}

//======================================================================================================================
//Global test matrix:

void test_matrix() {
    tests_getMemMatrix();
    tests_getMemArrayOfMatrices();
    tests_freeMemMatrix();
    tests_freeMemMatrix();
    tests_swapRows();
    tests_swapCols();
    tests_insertionSortRowsMatrixByRowCriteria();
    tests_insertionSortColsMatrixByColCriteria();
    tests_isSquareMatrix();
    tests_isEMatrix();
    tests_isSymmetricMatrix();
    tests_transposeSquareMatrix();
    tests_getMinValuePos();
    tests_getMaxValuePos();
}
