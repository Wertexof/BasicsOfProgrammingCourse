#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>
#include <assert.h>
#include "data_structures/matrix/matrix.c"
#include "data_structures/matrix/matrix.h"

int getMin(const int *a, int n) {
    int minElement = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] < minElement)
            minElement = a[i];
    }

    return minElement;
}

int getMax(const int *a, int n) {
    int maxElement = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] > maxElement)
            maxElement = a[i];
    }

    return maxElement;
}

int mulRowsOnCols(matrix *m1, int index1, matrix *m2, int index2) {
    int mul = 0;
    int i = m1->nCols - 1;
    while (i >= 0) {
        mul += m1->values[index1][i] * m2->values[i][index2];
        i--;
    }

    return mul;
}

matrix mulMatrices(matrix *m1, matrix *m2) {
    if (m1->nCols != m2->nRows) {
        fprintf(stderr, "you can't multiply ");
        exit(1);
    }

    matrix mRes = getMemMatrix(m1->nRows, m2->nCols);
    for (int i = 0; i < m1->nRows; i++)
        for (int j = 0; j < m2->nCols; j++)
            mRes.values[i][j] = mulRowsOnCols(m1, i, m2, j);
    return mRes;
}

/*Дана квадратная матрица, все элементы которой различны. Поменять местами
         строки, в которых находятся максимальный и минимальный элементы*/
void changeRowsWithMinAndMaxEl(matrix *m) {
    position minPos = getMinValuePos(m);
    position maxPos = getMaxValuePos(m);
    swapRows(m, minPos.rowIndex, maxPos.rowIndex);
}

//Упорядочить строки матрицы по неубыванию наибольших элементов строк
void sortRowsByMaxElement(matrix *m) {
    insertionSortRowsMatrixByRowCriteria(m, getMax);
}

/*Дана прямоугольная матрица. Упорядочить столбцы матрицы по неубыванию
                                       минимальных элементов столбцов*/
void sortColsByMinElement(matrix *m) {
    insertionSortColsMatrixByColCriteria(m, getMin);
}

//Если данная квадратная матрица 𝐴 симметрична, то заменить 𝐴 ее квадратом
void changeSymmetricMatrixWithSquare(matrix *m) {
    if (isSymmetricMatrix(m))
        *m = mulMatrices(m1, m2);
}

/*Дана квадратная матрица. Если среди сумм элементов строк матрицы нет равных,
                                                  то транспонировать матрицу*/
//WIP

//Даны две квадратные матрицы 𝐴 и 𝐵. Определить, являются ли они взаимно обратными (𝐴 = 𝐵^−1)
bool isMutuallyInverseMatrices(matrix m1, matrix m2) {
    return isEMatrix(mulMatrices(m1, m2));
}