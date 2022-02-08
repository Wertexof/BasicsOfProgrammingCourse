#include "vectorVoid.h"

void badAlloc_() {
    fprintf(stderr, "bad alloc");
    exit(1);
}

vectorVoid createVectorVoid(size_t n, size_t baseTypeSize) {
    vectorVoid v = {malloc(sizeof(baseTypeSize * n)), 0, n, baseTypeSize};
    if (v.data == NULL) {
        badAlloc_();
    } else
        return v;
}

void reserveVectorVoid(vectorVoid *v, size_t newCapacity) {
    v->data = realloc(v->data, v->baseTypeSize * newCapacity);
    v->capacity = newCapacity;
    v->size = newCapacity < v->size ? newCapacity : v->size;
    if (newCapacity == 0)
        return;
    if (v->data == NULL) {
        badAlloc_();
    }
}

void shrinkVectorVoidToFit(vectorVoid *v) {
    reserveVectorVoid(v, v->size);
}

void clearVectorVoid(vectorVoid *v) {
    v->size = 0;
}

void deleteVectorVoid(vectorVoid *v) {
    reserveVectorVoid(v, 0);
}

bool isVectorVoidEmpty(vectorVoid *v) {
    return v->size == 0;
}

bool isVectorVoidFull(vectorVoid *v) {
    return v->size == v->capacity;
}

void getVectorVoidValue(vectorVoid *v, size_t index, void *destination) {
    char *source = (char *) v->data + index * v->baseTypeSize;
    memcpy(destination, source, v->baseTypeSize);
}

void setVectorVoidValue(vectorVoid *v, size_t index, void *source) {
    char *destination = (char *) v->data + index * v->baseTypeSize;
    memcpy(destination, source, v->baseTypeSize);
}

void popVectorVoidBack(vectorVoid *v) {
    if (isVectorVoidEmpty(v)) {
        fprintf(stderr, "empty");
        exit(1);
    } else
        v->size--;
}

void pushVectorVoidBack(vectorVoid *v, void *source) {
    if (isVectorVoidFull(v) && v->capacity != 0)
        reserveVectorVoid(v, v->capacity * 2);
    else if (v->capacity == 0)
        reserveVectorVoid(v, 1);
    setVectorVoidValue(v, v->size, source);
    v->size++;
}