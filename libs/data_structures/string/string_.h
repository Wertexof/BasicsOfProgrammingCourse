#ifndef VECTORS_PROJECT_STRING__H
#define VECTORS_PROJECT_STRING__H
#define MAX_STRING_SIZE 100
#define MAX_N_WORDS_IN_STRING 100
#define MAX_WORD_SIZE 20

#include <stdio.h>
#include <stdbool.h>
#include <memory.h>
#include <ctype.h>

static char _stringBuffer[MAX_STRING_SIZE + 1];

typedef struct WordDescriptor {
    char *begin; //позиция начала слова
    char *end; //позиция первого символа, после последнего символа слова
} WordDescriptor;

typedef struct BagOfWords {
    WordDescriptor words[MAX_N_WORDS_IN_STRING];
    size_t size;
} BagOfWords;

typedef enum WordBeforeFirstWordWithAReturnCode {
    FIRST_WORD_WITH_A,
    NOT_FOUND_A_WORD_WITH_A,
    WORD_FOUND,
    EMPTY_STRING
} WordBeforeFirstWordWithAReturnCode;

//Возвращает количество символов в строке (не считая ноль-символ)
size_t strlen_(const char *begin);

//Функция возвращает отрицательное значение, если lhs
//располагается до rhs в лексикографическом порядке (как в словаре),
//значение 0, если lhs и rhs равны, иначе – положительное значение
int strcmp_(const char *lhs, const char *rhs);

//возвращает указатель на первый элемент с кодом ch, оасположенным на ленте памяти
//между адресами begin и end не включая end. Если символ не найден, возвращается значение end
char *find(char *begin, char *end, int ch);

//возвращает указатель на первый символ, отличный от пробельных,
//расположенный на ленте памяти, начиная с begin и заканчивая ноль-символом.
//Если символ не найден, возвращается адрес первого ноль-символа
char *findNonSpace(char *begin);

//возвращает указатель на первый пробельный символ, расположенный на
//ленте памяти начиная с адреса begin или на первый ноль-символ
char *findSpace(char *begin);

//возвращает указатель на первый справа символ, отличный от пробельных,
//расположенный на ленте памяти, начиная с rbegin (последний символ
//строки, за которым следует ноль-символ) и заканчивая rend (адрес символа перед началом строки)
char *findNonSpaceReverse(char *rbegin, const char *rend);

//возвращает указатель на первый пробельный символ справа, расположенный на ленте памяти,
//начиная с rbegin и заканчивая rend. Если символ не найден, возвращается адрес rend
char *findSpaceReverse(char *rbegin, const char *rend);

//Функция возвращает отрицательное значение, если lhs
//располагается до rhs в лексикографическом порядке (как в словаре), значение 0,
//если lhs и rhs равны, иначе – положительное значение
int strcmp(const char *lhs, const char *rhs);

//записывает по адресу beginDestination фрагмент памяти,
//начиная с адреса beginSource до endSource. Возвращает указатель
//на следующий свободный фрагмент памяти в destination
char *copy(const char *beginSource, const char *endSource, char *beginDestination);

//записывает по адресу beginDestination элементы из фрагмента
//памяти начиная с beginSource заканчивая endSource, удовлетворяющие функции-предикату f.
//Функция возвращает указатель на следующий свободный для записи фрагмент впамяти
char *copyIf(char *beginSource, const char *endSource, char *beginDestination, int (*f)(int));

//записывает по адресу beginDestination элементы из фрагмента
//памяти начиная с rbeginSource заканчивая rendSource, удовлетворяющие
//функции-предикату f. Функция возвращает значение beginDestination по окончанию работы функции
char *copyIfReverse(char *rbeginSource, const char *rendSource, char *beginDestination, int (*f)(int));

//Возвращает конец строки
char *getEndOfString(char *str);

//проверка на идентичность слов
int areWordsEqual(WordDescriptor w1, WordDescriptor w2);

//вернёт значение 0, если слово не было считано, в противном
//случае будет возвращено значение 1
int getWord(char *beginSearch, WordDescriptor *word);

//считывает слова с конца строки
bool getWordReverse(char *rbegin, char *rend, WordDescriptor *word);

#endif
