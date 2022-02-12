#ifndef VECTORS_PROJECT_MATRIX_H
#define VECTORS_PROJECT_MATRIX_H

#endif //VECTORS_PROJECT_MATRIX_H

typedef struct matrix {
    int **values; //элементы матрицы
    int nRows; //количество рядов
    int nCols; //количество столбцов
} matrix;

typedef struct position {
    int rowIndex;
    int colIndex;
} position;

//размещает в динамической памяти матрицу размером nRows на nCols
matrix getMemMatrix(int nRows, int nCols);

/*размещает в динамической памяти массив из
nMatrices матриц размером nRows на nCols*/
matrix *getMemArrayOfMatrices(int nMatrices, int nRows, int nCols);

/// dshfksld
/// \param m sdfjd
void freeMemMatrix(matrix m);

///
/// \param ms
/// \param nMatrices
void freeMemMatrices(matrix *ms, int nMatrices);