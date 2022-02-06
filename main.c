#include <stdio.h>
#include <stdint.h>
#include "libs/data_structures/vector/vector.h"
#include "libs/data_structures/vector/vector.c"
#include "libs/data_structures/vector/vectorVoid.h"
#include "libs/data_structures/vector/vectorVoid.c"
#include "libs/tests.c"

void test() {
    test_pushBack_emptyVector();
    test_pushBack_fullVector();
    test_popBack_notEmptyVector();
    //...
}

int main() {
    vector v = createVector(SIZE_MAX);

    return 0;
}
