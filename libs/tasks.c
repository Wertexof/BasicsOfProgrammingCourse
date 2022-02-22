#include <stdio.h>
#include <stdbool.h>
#include <math.h>
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

int min2(int a, int b) {
    int m = a < b ? a : b;
    return m;
}

float getDistance(int *a, int n) {
    float distance = 0;
    for (int i = 0; i < n; ++i) {
        distance += a[i] * a[i];
    }

    return sqrt(distance);
}

int cmp_long_long(const void *pa, const void *pb) {
    long long arg1 = *(const long long *) pa;
    long long arg2 = *(const long long *) pb;

    if (arg1 < arg2) return -1;
    if (arg1 > arg2) return 1;

    return 0;
}

int countNUnique(long long int *a, int n) {
    qsort(a, n, sizeof(long long), cmp_long_long);
    int nUniqueElements = 1;

    for (int i = 0; i < n-1; ++i) {
        if (a[i] != a[i + 1])
            nUniqueElements++;
    }

    return nUniqueElements;
}

position getLeftMin(matrix *m) {
    position min = {0, 0};

    for (int i = 0; i < m->nRows; ++i) {
        for (int j = 0; j < m->nCols; ++j) {
            if (m->values[i][j] < m->values[min.rowIndex][min.colIndex]) {
                min.rowIndex = i;
                min.colIndex = j;
            } else if (m->values[i][j] == m->values[min.rowIndex][min.colIndex] && j < min.colIndex) {
                min.rowIndex = i;
                min.colIndex = j;
            }
        }
    }

    return min;
}

static bool isNonDescendingSorted(const int *const a, const int n) {
    for (int i = 1; i < n; ++i)
        if (a[i - 1] > a[i])
            return false;
    return true;
}

static bool hasAllNonDescendingRows(const matrix *m) {
    int rows = m->nRows;

    for (int i = 0; i < rows; ++i)
        if (!isNonDescendingSorted(m->values[i], rows))
            return false;
    return true;
}

int countValues(const int *a, int n, int value) {
    int count = 0;

    for (int i = 0; i < n; ++i) {
        if (a[i] == value)
            count++;
    }

    return count;
}

int countZeroRows(matrix *m) {
    int rows = m->nRows;
    int cols = m->nCols;
    int counter = 0;

    for (int i = 0; i < rows; ++i)
        counter += countValues(m->values[i], cols, 0) == cols;

    return counter;
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

//8. Дана прямоугольная матрица, все элементы которой различны. Найти минимальный элемент матрицы в выделенной области
int getMinInArea(matrix *m) {
    position maxPos = getMaxValuePos(m);
    int min = m->values[maxPos.rowIndex][maxPos.colIndex];
    int rightElementColIndex = maxPos.colIndex;
    int length = 1;

    for (int i = maxPos.rowIndex; i >= 0; i--) {
        for (int j = rightElementColIndex; (j - rightElementColIndex) < length && j < m->nCols; ++j) {
            min = min2(min, m->values[i][j]);
        }

        length += 2;
    }

    return min;
}

//9. Дано 𝑛 точек в 𝑚-мерном пространстве. Упорядочить точки по неубыванию их расстояний до начала координат
void sortByDistances(matrix *m) {
    insertionSortRowsMatrixByRowCriteria(m, getDistance);
}

/*10. Определить количество классов эквивалентных строк данной прямоугольной матрицы. Строки считать
                                                     эквивалентными, если равны суммы их элементов*/
int countEqClassesByRowsSum(matrix *m) {
    long long *rowSumArray = (long long *) malloc(sizeof(long long)*m->nRows);
    for (int i = 0; i < m->nRows; ++i) {
        rowSumArray[i] = getSum(m->values[i], m->nCols);
    }

    return countNUnique(rowSumArray, m->nRows);
}

/*11. Дана квадратная матрица. Определить 𝑘 – количество "особых" элементов матрицы, считая элемент "особым",
                                                    если он больше суммы остальных элементов своего столбца*/
int getNSpecialElement(matrix *m) {
    int *maxPosInCol = (int *) malloc(sizeof(int) * m->nCols);
    int *maxOfCols = (int *) malloc(sizeof(int) * m->nCols);

    for (int i = 0; i < m->nRows; ++i) {
        for (int j = 0; j < m->nCols; ++j) {
            if (i == 0) {
                maxOfCols[j] = m->values[i][j];
                maxPosInCol[j] = 0;
            } else if (maxOfCols[j] < m->values[i][j]) {
                maxOfCols[j] = m->values[i][j];
                maxPosInCol[j] = i;
            }
        }
    }

    int countSpecialEl = m->nCols;
    for (int i = 0; i < m->nRows; ++i) {
        for (int j = 0; j < m->nCols; ++j) {
            if (maxPosInCol[j] == i)
                continue;
            maxOfCols[j] -= m->values[i][j];
            if (maxOfCols[j] <= 0)
                countSpecialEl--;
        }
    }

    free(maxPosInCol);
    free(maxOfCols);

    return countSpecialEl;
}

/*12. Дана квадратная матрица. Заменить предпоследнюю строку матрицы первым из столбцов,
                                       в котором находится минимальный элемент матрицы*/
void swapPenultimateRow(matrix *m, int n) {
    position colOfFirstMin = getLeftMin(m);
    for (int j = 0; j < m->nCols; ++j) {
        m->values[m->nRows - 2][j] = m->values[j][colOfFirstMin.colIndex];
    }
}

/*13. Дан массив квадратных матриц. Определить число матриц, строки которых
                                      упорядочены по неубыванию элементов*/
int countNonDescendingRowsMatrices(matrix *ms, int nMatrix) {
    int count = 0;
    for (int i = 0; i < nMatrix; ++i)
        count += hasAllNonDescendingRows(&ms[i]);

    return count;
}

//14. Дан массив целочисленных матриц. Вывести матрицы, имеющие наибольшее число нулевых строк
void printMatrixWithMaxZeroRows(matrix *ms, int nMatrix) {
    int *matricesZeroRows = (int *) malloc(sizeof(int) * nMatrix);

    for (int i = 0; i < nMatrix; ++i)
        matricesZeroRows[i] = countZeroRows(&ms[i]);

    int zeroRowsMax = getMax(matricesZeroRows, nMatrix);

    for (int i = 0; i < nMatrix; ++i)
        if (zeroRowsMax == matricesZeroRows[i]) {
            outputMatrix(&ms[i]);
            printf("\n");
        }

    free(matricesZeroRows);
}