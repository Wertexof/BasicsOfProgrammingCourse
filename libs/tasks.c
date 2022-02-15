#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>
#include <assert.h>
#include "matrix.c"
#include "matrix.h"

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

/*Дана квадратная матрица, все элементы которой различны. Поменять местами
         строки, в которых находятся максимальный и минимальный элементы*/
void changeRowsWithMinAndMaxEl(matrix *m) {
    position minPos = getMinValuePos(m);
    position maxPos = getMaxValuePos(m);
    swapRows(m, minPos->rowIndex, maxPos->rowIndex);
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
