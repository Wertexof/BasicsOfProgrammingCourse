#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include "data_structures/matrix/matrix.c"
#include "data_structures/matrix/matrix.h"
#include "data_structures/string/string_.c"
#include "data_structures/string/string_.h"

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

    for (int i = 0; i < n - 1; ++i) {
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

int getMatrixNorm(matrix *m) {
    int absMax = abs(m->values[0][0]);
    for (int i = 0; i < m->nRows; ++i) {
        for (int j = 0; j < m->nCols; ++j) {
            int currentEl = abs(m->values[i][j]);
            if (currentEl > absMax)
                absMax = currentEl;
        }
    }

    return absMax;
}

bool isEqualOrMore(const int *a, const size_t n, const int x) {
    for (int i = 0; i < n; i++) {
        if (a[i] >= x)
            return true;
    }

    return false;
}

bool isEqualOrLess(const int *a, const size_t n, const int x) {
    for (int i = 0; i < n; i++) {
        if (a[i] <= x)
            return true;
    }

    return false;
}

long long getScalarProduct(int *a, int *b, int n) {
    long long product = 0;
    for (int i = 0; i < n; i++)
        product += a[i] * b[i];
    return product;
}

//=======================================================TASKS==========================================================
//MATRIX_TASKS


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
    long long *rowSumArray = (long long *) malloc(sizeof(long long) * m->nRows);
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

/*15. Дан массив вещественных квадратных матриц. Вывести матрицы с наименьшей нормой. В качестве
нормы матрицы взять максимум абсолютных величин ее элементов*/
void printOfMatricesInTheMinNorm(matrix *ms, int nMatrix) {
    int *normMatrix = malloc(sizeof(int) * nMatrix);
    for (int iMatrix = 0; iMatrix < nMatrix; ++iMatrix)
        normMatrix[iMatrix] = getMatrixNorm(&ms[iMatrix]);

    int minNorm = getMin(normMatrix, nMatrix);
    for (int iMatrix = 0; iMatrix < nMatrix; ++iMatrix) {
        if (minNorm == normMatrix[iMatrix])
            outputMatrix(&ms[iMatrix]);
    }

    free(normMatrix);
}

/*16. Дана матрица. Определить 𝑘 – количество "особых" элементов данной матрицы, считая элемент
"особым" если в строке слева от него находятся меньшие элементы, а справа – большие*/
int getNSpecialElement2(matrix *m) {
    int countSpecialEl = 0;
    for (int i = 0; i < m->nRows; ++i) {
        for (int j = 0; j < m->nCols; ++j) {
            if (!isEqualOrMore(m->values[i], j, m->values[i][j]) &&
                !isEqualOrLess(m->values[i] + j + 1, m->nCols - j - 1, m->values[i][j]))
                countSpecialEl++;
        }
    }

    return countSpecialEl;
}

/*18. Дана вещественная квадратная матрица, все элементы которой различны. Найти скалярное произведение строки,
в которой находится наибольший элемент матрицы, на столбец с наименьшим элементом*/
long long getScalarProductRowAndCol(matrix *m, int i, int j) {
    int *col = (int *) malloc(sizeof(int) * m->nRows);
    for (int k = 0; k < m->nRows; k++)
        col[k] = m->values[k][j];
    long long res = getScalarProduct(m->values[i], col, m->nCols);

    free(col);

    return res;
}

long long getSpecialScalarProduct(matrix *m) {
    position maxPosRow = getMaxValuePos(m);
    position minPosCol = getMinValuePos(m);

    return getScalarProductRowAndCol(m, maxPosRow.rowIndex, minPosCol.colIndex);
}


//======================================================================================================================
//STRING_TASKS

//№1.
void removeNonLetters(char *s) {
    char *endSource = getEndOfString(s);
    char *destination = copyIf(s, endSource, s, isgraph);
    *destination = '\0 ';
}

//№2.
void removeAdjacentEqualLetters(char *s) {
    if (*s == '\0')
        return;
    char *lastWriten = s;
    s++;

    while (*s) {
        if (*lastWriten != *s) {
            lastWriten++;
            memcpy(lastWriten, s, sizeof(char));
        }

        s++;
    }

    lastWriten++;
    *lastWriten = '\0';
}

void removeExtraSpaces(char *s) {
    if (*s == '\0')
        return;
    char *lastWriten = s;
    s++;

    while (*s) {
        if (isspace(*lastWriten) && isspace(*s)) {
            *lastWriten = ' ';
        } else {
            *++(lastWriten) = *s;
        }

        s++;
    }

    *++(lastWriten) = '\0';
}

//№3.
bool getWordReverse(char *rbegin, char *rend, WordDescriptor *word) {
    word->begin = findNonSpaceReverse(rbegin, rend);
    if (*word->begin == '\0 ')
        return false;

    word->end = findSpaceReverse(rbegin, rend);
    word->begin++;
    word->end++;

    return true;
}

//№4.
void replaceNumber(char *s) {
    char *begin = s;
    char *buf = _stringBuffer;

    while (*begin != '\0') {
        if (isdigit(*begin)) {
            char digit = *begin - '0';
            for (int i = 0; i < digit; i++) {
                *buf = ' ';
                buf++;
            }
        } else {
            *buf = *begin;
            buf++;
        }

        begin++;
    }

    *buf = '\0';
    copy(_stringBuffer, buf, s);
}

//№5.
void replace(char *source, char *w1, char *w2) {
    size_t w1Size = strlen_(w1);
    size_t w2Size = strlen_(w2);

    WordDescriptor word1 = {w1, w1 + w1Size};
    WordDescriptor word2 = {w2, w2 + w2Size};

    char *readPtr, *recPtr;
    if (w1Size >= w2Size) {
        readPtr = source;
        recPtr = source;
    } else {
        copy(source, getEndOfString(source), _stringBuffer);
        readPtr = _stringBuffer;
        recPtr = source;
    }

    WordDescriptor word;
    while (getWord(readPtr, &word)) {
        if (areWordsEqual(word, word1)) {
            recPtr = copy(word2.begin, word2.end, recPtr);
        } else {
            recPtr = copy(word.begin, word.end, recPtr);
            *recPtr = ' ';
            recPtr++;
            readPtr = word.end;
        }

        *recPtr = '\0';
    }
}

//№6.
bool orderedLexicographically(char *s) {
    WordDescriptor beginWord;
    WordDescriptor nextWord;

    if (!getWord(s, &beginWord))
        return true;

    while (getWord(s, &nextWord)) {
        if (areWordsEqual(beginWord, nextWord) == false && strcmp(beginWord.begin, nextWord.begin) > 0)
            return false;

        beginWord = nextWord;
        s = nextWord.end;
    }

    return true;
}

//№7.
void getBagOfWords(BagOfWords *bag, char *s) {
    WordDescriptor w;
    bag->size = 0;

    while (getWord(s, &w)) {
        bag->words[bag->size++] = w;
        s = w.end;
    }
}

//№8.
bool isPalindrome(WordDescriptor s) {
    char *left = s.begin;
    char *right = s.end - 1;

    while (right > left) {
        if (*(left) != *(right))
            return false;

        left++;
        right--;
    }

    return true;
}

char *findComma(char *begin) {
    while (*begin != '\0') {
        if (*begin == ',')
            return begin;
        begin++;
    }

    return begin;
}

//№9.
void mixTwoStrings(char *s1, char *s2, char *s3) {
    WordDescriptor word1, word2;
    bool isW1Found, isW2Found;
    char *beginSearch1 = s1, *beginSearch2 = s2;
    while ((isW1Found = getWord(beginSearch1, &word1)),
            (isW2Found = getWord(beginSearch2, &word2)),
            isW1Found || isW2Found) {

        if (isW1Found) {
            s3 = copy(word1.begin, word1.end, s3);
            *s3 = ' ';
            s3++;
            beginSearch1 = word1.end;
        }

        if (isW2Found) {
            s3 = copy(word2.begin, word2.end, s3);
            *s3 = ' ';
            s3++;
            beginSearch2 = word2.end;
        }
    }

    *(s3 - 1) = '\0';
}

//№10.
void changeTheOrderOfWords(char *s) {
    if (*s == '\0')
        return;

    BagOfWords bag;
    getBagOfWords(&bag, s);
    char *buf = _stringBuffer;

    for (int i = bag.size - 1; i >= 0; i--) {
        buf = copy(bag.words[i].begin, bag.words[i].end, buf);
        *buf = ' ';
        buf++;
    }

    *buf = '\0';
    s = copy(_stringBuffer, buf, s);

    *(s - 1) = '\0';
}

//№11.
bool isLetterA(WordDescriptor w) {
    char *begin = w.begin;

    while (begin != w.end) {
        if (*begin == 'a' || *begin == 'A')
            return true;

        begin++;
    }

    return false;
}

WordBeforeFirstWordWithAReturnCode getWordBeforeFirstWordWithA(char *s, WordDescriptor *word) {
    WordDescriptor prevWord;
    char *startWord = s;

    if (!getWord(startWord, &prevWord))
        return EMPTY_STRING;

    if (*find(prevWord.begin, prevWord.end, 'a') == 'a' || *find(prevWord.begin, prevWord.end, 'A') == 'A')
        return FIRST_WORD_WITH_A;

    startWord = prevWord.end;
    WordDescriptor lastWord;
    while (getWord(startWord, &lastWord)) {
        if (*find(lastWord.begin, lastWord.end, 'a') == 'a' || *find(lastWord.begin, lastWord.end, 'A') == 'A') {
            *word = prevWord;
            return WORD_FOUND;
        }
        startWord = lastWord.end;
        prevWord = lastWord;
    }
    return NOT_FOUND_A_WORD_WITH_A;
}

void printWordBeforeFirstWordWithA(char *s) {
    WordDescriptor w;
    WordBeforeFirstWordWithAReturnCode code = getWordBeforeFirstWordWithA(s, &w);

    if (code == WORD_FOUND) {
        char *buff = copy(w.begin, w.end, _stringBuffer);
        *buff = '\0';

        printf("%s", _stringBuffer);
    }
}

//№12.
bool lastWordFromFirstInSecondString(char *s1, char *s2) {
    WordDescriptor w, lastW;
    BagOfWords bag;

    getBagOfWords(&bag, s2);
    char *start = s1;
    bool haveWord = false;

    while (getWord(start, &w)) {
        WordDescriptor *readBag = bag.words;
        int count = bag.size;

        while (count--) {
            if (areWordsEqual(w, *readBag)) {
                lastW = w;
                haveWord = true;
            }

            readBag++;
        }

        start = w.end;
    }

    return haveWord;
}

//№13.
bool beingEqualWord(char *s) {
    WordDescriptor w1, w2;
    char *start = s;

    while (getWord(start, &w1)) {
        char *cmp = w1.end;
        start = w1.end;
        while (getWord(cmp, &w2)) {
            if (areWordsEqual(w1, w2))
                return true;
            cmp = w2.end;
        }
    }

    return false;
}

//№14.
int compare_chars(const void *a, const void *b) {
    char arg1 = *(const char *) a;
    char arg2 = *(const char *) b;

    if (arg1 < arg2) return -1;
    if (arg1 > arg2) return 1;

    return 0;
}

bool unityOfLettersInWords(char *s) {
    WordDescriptor w;
    char *start = _stringBuffer;
    copy(s, getEndOfString(s) + 1, _stringBuffer);

    while (getWord(start, &w)) {
        qsort(w.begin, w.end - w.begin, sizeof(char), compare_chars);
        start = w.end;
    }

    return beingEqualWord(_stringBuffer);
}

//№15.
void task15(char *s, char *res) {
    WordDescriptor w, lastW;
    char *start = s;
    char *iWrite = res;
    getWordReverse(getEndOfString(s) - 1, s - 1, &lastW);

    while (getWord(start, &w)) {
        if (!areWordsEqual(w, lastW)) {
            iWrite = copy(w.begin, w.end, iWrite);
            *iWrite++ = ' ';
        }

        start = w.end;
    }

    *(--iWrite) = '\0';
}

//№16.
WordBeforeFirstWordWithAReturnCode wordPrecedingTheFirstOccurrence(char *s1, char *s2) {
    WordDescriptor w1, w2, lastW;
    char *start = s1;

    if (!getWord(start, &w1) || !getWord(s2, &w2))
        return EMPTY_STRING;

    while (getWord(start, &w1)) {
        char *cmp = s2;
        while (getWord(cmp, &w2)) {
            if (areWordsEqual(w1, w2)) {
                if (start == s1)
                    return FIRST_WORD_WITH_A;
                else {
                    return WORD_FOUND;
                }
            }

            cmp = w2.end;
        }

        start = w1.end;
        lastW = w1;
    }

    return NOT_FOUND_A_WORD_WITH_A;
}

//№17.
void task17a(char *s) {
    WordDescriptor w, lastW;
    char *start = s;
    char *iWrite = s;
    getWordReverse(getEndOfString(s) - 1, s - 1, &lastW);

    while (getWord(start, &w)) {
        if (!areWordsEqual(w, lastW)) {
            iWrite = copy(w.begin, w.end, iWrite);
            *iWrite++ = ' ';
        }

        start = w.end;
    }

    iWrite = copy(lastW.begin, lastW.end, iWrite);
    *iWrite = '\0';
}

//№18.
void AdditionOfWordsForStringWithASmallerNumOfWords(char *s1, char *s2) {
    WordDescriptor w1, w2;
    bool isW1Found, isW2Found;

    char *start1 = s1;
    char *start2 = s2;

    while ((isW1Found = getWord(start1, &w1)),
            (isW2Found = getWord(start2, &w2)),
            isW1Found || isW2Found) {

        if (isW1Found) {
            start1 = w1.end;
        } else {
            if (start1 != s1)
                *start1++ = ' ';
            start1 = copy(w2.begin, w2.end, start1);
        }

        if (isW2Found) {
            start2 = w2.end;
        } else {
            if (start2 != s2)
                *start2++ = ' ';
            start2 = copy(w1.begin, w1.end, start2);
        }
    }

    *start1 = '\0';
    *start2 = '\0';
}

//№19.
