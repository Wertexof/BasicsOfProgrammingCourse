#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "vector.h"

vector createVector(size_t n) {
    vector v;
    v.size = 0;
    v.capacity = n;
    v.data = malloc(n);
    if (v.data == NULL) {
        fprintf(stderr, "bad alloc");
        exit(1);
    }

    return v;
}

void reserveVector(vector *v, size_t newCapacity) {
    v->capacity = newCapacity;
    if (newCapacity == 0) {
        v->size = 0;
        v->data = NULL;

        return;
    }

    v->data = realloc(v->data, newCapacity);
    if (v->data == NULL) {
        fprintf(stderr, "bad alloc");
        exit(1);
    }

    if (newCapacity < v->size) {
        v->size = newCapacity;
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