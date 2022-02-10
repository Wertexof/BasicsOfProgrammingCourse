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

//Реализация VOID позволяет оперировать векторами произвольного типа ==================================================

void badAlloc_(); //функция вывода сообщения об ошибке

vectorVoid createVectorVoid(size_t n, size_t baseTypeSize); //возвращает структуру-дескриптор вектор из n значений

void reserveVectorVoid(vectorVoid *v, size_t newCapacity); /*изменяет количество памяти, выделенное под хранение
элементов вектора*/

void shrinkVectorVoidToFit(vectorVoid *v); //освобождает память, выделенную под неиспользуемые элементы

void clearVectorVoid(vectorVoid *v); //удаляет элементы из контейнера, но не освобождает выделенную память

void deleteVectorVoid(vectorVoid *v); //освобождает память, выделенную вектору

bool isVectorVoidEmpty(vectorVoid *v); //проверка на то, является ли вектор пустым

bool isVectorVoidFull(vectorVoid *v); //проверка на то, является ли вектор полным

void getVectorVoidValue(vectorVoid *v, size_t index, void *destination); /*записывает по адресу destination index-ый
элемент вектора v*/

void setVectorVoidValue(vectorVoid *v, size_t index, void *source); //записывает на index-ый элемент вектора v значение

void popVectorVoidBack(vectorVoid *v); //удаляет последний элемент из вектора

void pushVectorVoidBack(vectorVoid *v, void *source); //добавляет элемент x в конец вектора v

#endif
