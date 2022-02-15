#ifndef VECTORS_PROJECT_MATRIX_H
#define VECTORS_PROJECT_MATRIX_H

#include <stdbool.h>

typedef struct matrix {
    int **values; //элементы матрицы
    int nRows; //количество рядов
    int nCols; //количество столбцов
} matrix;

typedef struct position {
    int rowIndex;
    int colIndex;
} position;

int swap(int *a, int *b); //функция swap для обмена значений двух переменных

void badAlloc(const int *a); //функция вывода ошибки

matrix getMemMatrix(int nRows, int nCols); //размещает в динамической памяти матрицу размером nRows на nCols

matrix *getMemArrayOfMatrices(int nMatrices, int nRows, int nCols); /*размещает в динамической памяти массив из
                                                                     nMatrices матриц размером nRows на nCols*/

void freeMemMatrix(matrix *m); //освобождает память, выделенную под хранение матрицы m

void freeMemMatrices(matrix *ms, int nMatrices); /*освобождает память, выделенную под хранение массива ms из
                                                                                          nMatrices матриц*/

void inputMatrix(matrix *m); //ввод матрицы m

void inputMatrices(matrix *ms, int nMatrices); //ввод массива из nMatrices матриц, хранящейся по адресу ms

void outputMatrix(matrix *m); //вывод матрицы m

void outputMatrices(matrix *ms, int nMatrices); //вывод массива из nMatrices матриц, хранящейся по адресу ms

void swapRows(matrix *m, int i1, int i2); //обмен строк с порядковыми номерами i1 и i2 в матрице m

void swapColumns(matrix *m, int j1, int j2); //обмен столбцов с порядковыми номерами j1 и j2 в матрице m

void insertionSortRowsMatrixByRowCriteria(matrix *m, int (*criteria)(int *, int)); /*выполняет сортировку вставками строк
                                               матрицы m по неубыванию значения функции criteria применяемой для строк*/

void insertionSortColsMatrixByColCriteria(matrix *m, int (*criteria)(int *, int)); /*выполняет сортировку вставками
                             столбцов матрицы m по неубыванию значения функции criteria применяемой для столбцов*/

bool isSquareMatrix(matrix *m); /*возвращает значение ’истина’, если матрица m является квадратной,
                                                                       ложь – в противном случае*/

bool twoMatricesEqual(matrix *m1, matrix *m2); /*возвращает значение ’истина’, если матрицы m1 и m2 равны,
                                                                             ложь – в противном случае*/

bool isEMatrix(matrix *m); //возвращает значение ’истина’, если матрица m является единичной, ложь – в противном случае

bool isSymmetricMatrix(matrix *m); /*возвращает значение ’истина’, если матрица m является симметричной,
                                                                            ложь – в противном случае*/

void transposeSquareMatrix(matrix *m); //транспонирует квадратную матрицу m

position getMinValuePos(matrix *m); //возвращает позицию минимального элемента матрицы m

position getMaxValuePos(matrix *m); //возвращает позицию максимального элемента матрицы m

matrix createMatrixFromArray(const int *a, int nRows, int nCols); /*возвращает матрицу, размера nRows на nCols,
построенного из элементов массива a, размещенную в динамической памяти*/

matrix *createMatrixArrayOfMatrixFromArray(const int *values, size_t nMatrices, size_t nRows, size_t nCols);
/*возвращает указатель на нулевую матрицу массива из nMatrices матриц, размещенных в динамической памяти,
построенных из элементов массива a*/

#endif