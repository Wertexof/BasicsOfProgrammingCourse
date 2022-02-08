#ifndef VECTORS_PROJECT_VECTOR_H
#define VECTORS_PROJECT_VECTOR_H

#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>

typedef struct vector {
    int *data;
    size_t size;
    size_t capacity;
} vector;

void badAlloc(); //функция вывода сообщения об ошибке

vector createVector(size_t n); //возвращает структуру-дескриптор вектор из n значений

void reserveVector(vector *v, size_t newCapacity); //изменяет количество памяти, выделенное под хранение элементов вектора

void clearVector(vector *v); //удаляет элементы из контейнера, но не освобождает выделенную память

void shrinkVectorToFit(vector *v); //освобождает память, выделенную под неиспользуемые элементы

void deleteVector(vector *v); //освобождает память, выделенную вектору

bool isVectorEmpty(const vector *v); //проверка на то, является ли вектор пустым

bool isVectorFull(const vector *v); //проверка на то, является ли вектор полным

int getVectorValue(vector *v, size_t i); //возвращает i-ый элемент вектора v

void pushVectorBack(vector *v, int x); //добавляет элемент x в конец вектора v

void popVectorBack(vector *v); //удаляет последний элемент из вектора

int* atVector(vector *v, size_t index);

int* back(vector *v);

int* front(vector *v);

#endif
