#ifndef VECTORS_PROJECT_VECTORVOID_H
#define VECTORS_PROJECT_VECTORVOID_H

#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include <memory.h>
#include <malloc.h>
#include <assert.h>

typedef struct vectorVoid {
    void *data; //указатель на нулевой элемент вектора
    size_t size; //размер вектора
    size_t capacity; //вместимость вектора
    size_t baseTypeSize; //размер базового типа:
    /*например, если вектор хранит int -
    то поле baseTypeSize = sizeof(int)
    если вектор хранит float -
    то поле baseTypeSize = sizeof(float)*/
} vectorVoid;

void badAlloc_(); //функция вывода сообщения об ошибке

vectorVoid createVectorVoid(size_t n, size_t baseTypeSize);

void reserveVectorVoid(vectorVoid *v, size_t newCapacity);

void shrinkVectorVoidToFit(vectorVoid *v);

void clearVectorVoid(vectorVoid *v);

void deleteVectorVoid(vectorVoid *v);

bool isVectorVoidEmpty(vectorVoid *v);

bool isVectorVoidFull(vectorVoid *v);

void getVectorVoidValue(vectorVoid *v, size_t index, void *destination);

void setVectorVoidValue(vectorVoid *v, size_t index, void *source);

void popVectorVoidBack(vectorVoid *v);

void pushVectorVoidBack(vectorVoid *v, void *source);

#endif
