#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <malloc.h>
#include "matrix.h"

void badAlloc(const int *a) {
    if (a == NULL) {
        fprintf(stderr, "bad alloc ");
        exit(1);
    }
}

int swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

matrix getMemMatrix(int nRows, int nCols) {
    int **values = (int **) malloc(sizeof(int *) * nRows);
    for (int i = 0; i < nRows; i++)
        values[i] = (int *) malloc(sizeof(int) * nCols);
    return (matrix) {values, nRows, nCols};
}

matrix *getMemArrayOfMatrices(int nMatrices, int nRows, int nCols) {
    matrix *ms = (matrix *) malloc(sizeof(matrix) * nMatrices);
    for (int i = 0; i < nMatrices; i++)
        ms[i] = getMemMatrix(nRows, nCols);
    return ms;
}

void freeMemMatrix(matrix *m) {
    for (int i = 0; i < m->nRows; i++)
        free(m->values[i]);
    free(m->values);
}

void freeMemMatrices(matrix *ms, int nMatrices) {
    for (int i = 0; i < nMatrices; i++)
        freeMemMatrix(&ms[i]);
    free(ms);
}

void inputMatrix(matrix *m) {
    for (int i = 0; i < m->nRows; i++)
        for (int j = 0; j < m->nCols; j++)
            scanf("%d", &m->values[i][j]);
}

void inputMatrices(matrix *ms, int nMatrices) {
    for (int i = 0; i < nMatrices; i++)
        inputMatrix(&ms[i]);
}

void outputMatrix(matrix *m) {
    for (int rIndex = 0; rIndex < m->nRows; rIndex++) {
        for (int cIndex = 0; cIndex < m->nCols; cIndex++) {
            printf("%d ", m->values[rIndex][cIndex]);
        }

        printf("\n");
    }
}

void outputMatrices(matrix *ms, int nMatrices) {
    for (int i = 0; i < nMatrices; i++) {
        outputMatrix(&ms[i]);
    }
}

void swapRows(matrix *m, int i1, int i2) {
    int *t = m->values[i1];
    m->values[i1] = m->values[i2];
    m->values[i2] = t;
}

void swapCols(matrix *m, int j1, int j2) {
    for (int i = 0; i < m->nRows; i++)
        swap(&m->values[i][j1 - 1], &m->values[i][j2 - 1]);
}

void insertionSortRowsMatrixByRowCriteria(matrix *m, int (*criteria)(int *, int)) {
    int *a = (int *) malloc(sizeof(int) * m->nRows);
    badAlloc(a);

    for (int i = 0; i < m->nRows; i++)
        a[i] = criteria(m->values[i], m->nCols);
    for (int i = 1; i < m->nRows; i++) {
        int j = i;
        while (a[j] < a[j - 1] && j > 0) {
            swap(&a[j], &a[j - 1]);
            swapRows(m, j, j - 1);
            j--;
        }
    }

    free(a);
}

void insertionSortColsMatrixByColCriteria(matrix *m, int (*criteria)(int *, int)) {
    int *a = (int *) malloc(sizeof(int) * m->nCols);
    badAlloc(a);

    for (int i = 0; i < m->nCols; i++) {
        int *copyCols = (int *) malloc(sizeof(int) * m->nRows);
        badAlloc(copyCols);
        for (int j = 0; j < m->nRows; j++)
            copyCols[j] = m->values[j][i];
        a[i] = criteria(copyCols, m->nRows);
        free(copyCols);
    }

    for (int i = 1; i < m->nCols; i++) {
        int j = i;
        while (a[j] < a[j - 1] && j > 0) {
            swap(&a[j], &a[j - 1]);
            swapCols(m, j, j - 1);
            j--;
        }
    }

    free(a);
}

bool isSquareMatrix(matrix *m) {
    return m->nCols == m->nCols;
}

bool areTwoMatricesEqual(matrix *m1, matrix *m2) {
    if (m1->nRows != m2->nRows || m1->nCols != m2->nCols)
        return false;

    for (int i = 0; i < m1->nRows; i++)
        for (int j = 0; j < m1->nCols; j++)
            if (m1->values[i][j] != m2->values[i][j])
                return false;
    return true;
}

bool isEMatrix(matrix *m) {
    if (!isSquareMatrix(m))
        return false;

    for (int i = 0; i < m->nRows; i++) {
        if (m->values[i][i] != 1)
            return false;
        for (int j = i + 1; j < m->nCols; j++)
            if (m->values[i][j] != m->values[j][i] && m->values[i][j] != 0)
                return false;
    }

    return true;
}

bool isSymmetricMatrix(matrix *m) {
    if (!isSquareMatrix(m))
        return false;

    for (int i = 0; i < m->nRows; i++)
        for (int j = i + 1; j < m->nCols; j++)
            if (m->values[i][j] != m->values[j][i])
                return false;
    return true;
}

void transposeSquareMatrix(matrix *m) {
    if (!isSquareMatrix(m)) {
        fprintf(stderr, "non-square matrix");
        exit(1);
    }

    for (int i = 0; i < m->nRows; i++)
        for (int j = i + 1; j < m->nCols; j++)
            swap(&m->values[i][j], &m->values[j][i]);
}

position getMinValuePos(matrix *m) {
    int minPosI = 0;
    int minPosJ = 0;
    int min = m->values[minPosI][minPosJ];

    for (int i = 0; i < m->nRows; i++)
        for (int j = 0; j < m->nCols; j++)
            if (min > m->values[i][j]) {
                minPosI = i;
                minPosJ = j;
                min = m->values[minPosI][minPosJ];
            }

    return (position) {minPosI, minPosJ};
}

position getMaxValuePos(matrix *m) {
    int maxPosI = 0;
    int maxPosJ = 0;
    int max = m->values[maxPosI][maxPosJ];

    for (int i = 0; i < m->nRows; i++)
        for (int j = 0; j < m->nCols; j++)
            if (max < m->values[i][j]) {
                maxPosI = i;
                maxPosJ = j;
                max = m->values[maxPosI][maxPosJ];
            }

    return (position) {maxPosI, maxPosJ};
}

matrix createMatrixFromArray(const int *a, int nRows, int nCols) {
    matrix m = getMemMatrix(nRows, nCols);
    int k = 0;
    for (int i = 0; i < nRows; i++)
        for (int j = 0; j < nCols; j++)
            m.values[i][j] = a[k++];
    return m;
}

matrix *createMatrixArrayOfMatrixFromArray(const int *values, size_t nMatrices, size_t nRows, size_t nCols) {
    matrix *ms = getMemArrayOfMatrices(nMatrices, nRows, nCols);
    int l = 0;
    for (int k = 0; k < nMatrices; k++)
        for (int i = 0; i < nRows; i++)
            for (int j = 0; j < nCols; j++)
                ms[k].values[i][j] = values[l++];
    return ms;
}
