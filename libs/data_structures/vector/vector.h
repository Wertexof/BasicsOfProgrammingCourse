#ifndef VECTORS_PROJECT_VECTOR_H
#define VECTORS_PROJECT_VECTOR_H

#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>

typedef struct vector {
    int *data; //указатель на нулевой элемент вектора
    size_t size; //размер вектора
    size_t capacity; //вместимость вектора
} vector;

//функция вывода сообщения об ошибке
void badAlloc();

//возвращает структуру-дескриптор вектор из n значений
vector createVector(size_t n);

//изменяет количество памяти, выделенное под хранение элементов вектора
void reserveVector(vector *v, size_t newCapacity);

//удаляет элементы из контейнера, но не освобождает выделенную память
void clearVector(vector *v);

//освобождает память, выделенную под неиспользуемые элементы
void shrinkVectorToFit(vector *v);

//освобождает память, выделенную вектору
void deleteVector(vector *v);

//проверка на то, является ли вектор пустым
bool isVectorEmpty(const vector *v);

//проверка на то, является ли вектор полным
bool isVectorFull(const vector *v);

//возвращает i-ый элемент вектора v
int getVectorValue(vector *v, size_t i);

//добавляет элемент x в конец вектора v
void pushVectorBack(vector *v, int x);

//удаляет последний элемент из вектора
void popVectorBack(vector *v);

//возвращает указатель на index-ый элемент вектора
int *atVector(vector *v, size_t index);

//возвращает указатель на последний элемент вектора
int *back(vector *v);

//возвращает указатель на первый элемент вектора
int *front(vector *v);

#endif
