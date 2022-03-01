#ifndef VECTORS_PROJECT_STRING__H
#define VECTORS_PROJECT_STRING__H

#include <stdio.h>
#include <stdbool.h>

size_t strlen_(const char *begin); //Возвращает количество символов в строке (не считая ноль-символ)

int strcmp_(const char *lhs, const char *rhs); /*Функция возвращает отрицательное значение, если lhs
располагается до rhs в лексикографическом порядке (как в словаре), значение 0, если lhs и rhs равны,
                                                                    иначе – положительное значение*/

char *find(char *begin, char *end, int ch); /*возвращает указатель на первый элемент с кодом ch,
расположенным на ленте памяти между адресами begin и end не включая end. Если символ не найден,
                                                                     возвращается значение end*/

char *findNonSpace(char *begin); /*возвращает указатель на первый символ, отличный от пробельных,
расположенный на ленте памяти, начиная с begin и заканчивая ноль-символом.  Если символ не найден,
                                                         возвращается адрес первого ноль-символа*/

char *findSpace(char *begin); /*возвращает указатель на первый пробельный символ, расположенный на
                                   ленте памяти начиная с адреса begin или на первый ноль-символ*/

char *findNonSpaceReverse(char *rbegin, const char *rend); /*возвращает указатель на первый справа
символ, отличный от пробельных, расположенный на ленте памяти, начиная с rbegin (последний символ
  строки, за которым следует ноль-символ) и заканчивая rend (адрес символа перед началом строки)*/

char *findSpaceReverse(char *rbegin, const char *rend); /*возвращает указатель на первый пробельный
символ справа, расположенный на ленте памяти, начиная с rbegin и заканчивая rend. Если символ не найден,
                                                                                 возвращается адрес re*/

int strcmp(const char *lhs, const char *rhs); /*Функция возвращает отрицательное значение, если lhs
располагается до rhs в лексикографическом порядке (как в словаре), значение 0, если lhs и rhs равны,
                                                                    иначе – положительное значение*/

char *copy(const char *beginSource, const char *endSource, char *beginDestination); /*записывает по
адресу beginDestination фрагмент памяти, начиная с адреса beginSource до endSource. Возвращает указатель
                                                  на следующий свободный фрагмент памяти в destination*/

char *copyIf(char *beginSource, const char *endSource, char *beginDestination, int (*f)(int)); /*записывает
по адресу beginDestination элементы из фрагмента памяти начиная с beginSource заканчивая endSource,
удовлетворяющие функции-предикату f. Функция возвращает указатель на следующий свободный для записи
                                                                                         фрагмент впамяти*/

char *copyIfReverse(char *rbeginSource, const char *rendSource, char *beginDestination, int (*f)(int)); /*записывает
по адресу beginDestination элементы из фрагмента памяти начиная с rbeginSource заканчивая rendSource, удовлетворяющие
                      функции-предикату f. Функция возвращает значение beginDestination по окончанию работы функции*/

char *getEndOfString(char *str); //Возвращает конец строки

#endif
