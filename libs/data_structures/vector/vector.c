#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "vector.h"

vector createVector(size_t n) {
    vector v = {malloc(sizeof(int) * n), 0, n};
    v.size = 0;
    v.capacity = n;
    v.data = malloc(n);
    if (v.data == NULL) {
        fprintf(stderr, "bad alloc");
        exit(1);
    } else
        return v;
}

void reserveVector(vector *v, size_t newCapacity) {
    v->size = newCapacity < v->size ? newCapacity : v->size;
    v->capacity = newCapacity;
    v->data = realloc(v->data, sizeof(int) * newCapacity);
    if (newCapacity == 0)
        return;
    if (v->data == NULL) {
        fprintf(stderr, "bad alloc");
        exit(1);
    }
}

void clearVector(vector *v) {
    v->size = 0;
}

void shrinkVectorToFit(vector *v) {
    reserveVector(v, v->size);
}

void deleteVector(vector *v) {
    free(v->data);
    v->data = NULL;
    v->size = 0;
    v->capacity = 0;
}

bool isVectorEmpty(const vector *v) {
    return v->size == 0;
}

bool isVectorFull(const vector *v) {
    return v->size == v->capacity;
}

int getVectorValue(vector *v, size_t i) {
    return v->data[i];
}

void pushVectorBack(vector *v, int x) {
    if (isVectorFull(v) && v->capacity != 0)
        reserveVector(v, v->capacity * 2);
    else if (v->capacity == 0)
        reserveVector(v, 1);
    v->data[v->size] = x;
    v->size++;
}

void popVectorBack(vector *v) {
    if (isVectorEmpty(v)) {
        fprintf(stderr, "empty");
        exit(1);
    } else
        v->size--;
}

int* atVector(vector *v, size_t index) {
    if (index < v->size)
        return v->data + index;
    else {
        fprintf(stderr, "index a[%lld] is missing", index);
        exit(1);
    }
}

int* back(vector *v) {
    return atVector(v, v->size - 1);
}

int* front(vector *v) {
    return atVector(v, 0);
}