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

long long getSum(int *a, int n) {
    long long sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += a[i];
    }
    return sum;
}

bool isUnique(long long int *a, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (a[i] == a[j])
                return 0;
        }
    }
    return 1;
}

int max(int a, int b) {
    int m = a > b ? a : b;
    return m;
}


/*1. Дана квадратная матрица, все элементы которой различны. Поменять местами
         строки, в которых находятся максимальный и минимальный элементы*/
void changeRowsWithMinAndMaxEl(matrix *m) {
    position minPos = getMinValuePos(m);
    position maxPos = getMaxValuePos(m);
    swapRows(m, minPos.rowIndex, maxPos.rowIndex);
}

//2. Упорядочить строки матрицы по неубыванию наибольших элементов строк
void sortRowsByMaxElement(matrix *m) {
    insertionSortRowsMatrixByRowCriteria(m, getMax);
}

/*3. Дана прямоугольная матрица. Упорядочить столбцы матрицы по неубыванию
                                       минимальных элементов столбцов*/
void sortColsByMinElement(matrix *m) {
    insertionSortColsMatrixByColCriteria(m, getMin);
}

//4. Если данная квадратная матрица 𝐴 симметрична, то заменить 𝐴 ее квадратом
void getSquareOfMatrixIfSymmetric(matrix *m) {
    if (isSymmetricMatrix(m))
        *m = mulMatrices(m, m);
}

/*5. Дана квадратная матрица. Если среди сумм элементов строк матрицы нет равных,
                                                  то транспонировать матрицу*/
void transposeIfMatrixHasEqualSumOfRows(matrix *m) {
    long long *arraySumsOfRowElements = (long long *) malloc(sizeof(long long) * m->nRows);
    for (int i = 0; i < m->nRows; ++i) {
        arraySumsOfRowElements[i] = getSum(m->values[i], m->nCols);
    }
    if (isUnique(arraySumsOfRowElements, m->nRows))
        transposeSquareMatrix(m);
}

//6. Даны две квадратные матрицы 𝐴 и 𝐵. Определить, являются ли они взаимно обратными (𝐴 = 𝐵^−1)
bool isMutuallyInverseMatrices(matrix *m1, matrix *m2) {
    matrix mul = mulMatrices(m1, m2);

    bool res = isEMatrix(&mul);
    freeMemMatrix(&mul);

    return res;
}

/*7. Дана прямоугольная матрица. Назовем псевдодиагональю множество элементов этой матрицы, лежащих на прямой
параллельной прямой, содержащей элементы 𝑎𝑖,𝑖. Найти сумму максимальных элементов всех псевдодиагоналей
                                                                                             данной матрицы*/
long long findSumOfMaxesOfPseudoDiagonal(matrix *m) {
    position *start = {m->nRows - 1, -1};
    int s = 0;

    while (start->rowIndex >= 0) {
        while (start->colIndex < m->nCols - 1) {
            start->colIndex++;
            if (start->colIndex == start->rowIndex)
                continue;
            int maximum = m->values[start->rowIndex][start->colIndex];
            for (int j = start->rowIndex, k = start->colIndex; j >= 0 && k >= 0; --j, --k) {
                maximum = max(maximum, m->values[j][k]);
            }
            s += maximum;
        }

        start->rowIndex--;
        start->colIndex--;
    }

    return s;
}

long long findSumOfMaxesOfPseudoDiagonal2(matrix *m) {
    int nDiagonals = m->nRows + m->nCols - 1;
    int *arrayOfMaximums = (int *) malloc(sizeof(int) * nDiagonals);

    for (int i = 0; i < m->nRows; ++i) {
        for (int j = 0; j < m->nCols; ++j) {
            int diagonal_index = j - i - 1 + m->nRows;
            if (j == 0 || i == 0)
                arrayOfMaximums[diagonal_index] = m->values[i][j];
            else
                arrayOfMaximums[diagonal_index] = max(arrayOfMaximums[diagonal_index], m->values[i][j]);
        }
    }

    swap(&arrayOfMaximums[0 - 1 + m->nRows], &arrayOfMaximums[0]);
    long long s = getSum(arrayOfMaximums + 1, nDiagonals - 1);

    free(arrayOfMaximums);

    return s;
}