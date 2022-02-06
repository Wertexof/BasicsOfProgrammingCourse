#include <stdio.h>
#include <assert.h>

void test_pushBack_emptyVector() {
    vector v = createVector(0);
    pushVectorBack(&v, 1);

    assert(getVectorValue(&v, 0) == 1);
    assert(v.size == 1);
    assert(v.capacity == 1);
    deleteVector(&v);
}

void test_pushBack_fullVector() {
    vector v = createVector(0);
    pushVectorBack(&v, 1);
    pushVectorBack(&v, 2);

    assert(getVectorValue(&v, 1) == 2);
    assert(v.size == 2);
    assert(v.capacity == 2);
    deleteVector(&v);
}

void test_popBack_notEmptyVector() {
    vector v = createVector(0);
    pushVectorBack(&v, 10);

    assert(v.size == 1);
    popVectorBack(&v);
    assert(v.size == 0);
    assert(v.capacity == 1);

}
