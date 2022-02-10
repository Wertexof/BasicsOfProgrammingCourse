#include "libs/data_structures/vector/vector.h"
#include "libs/data_structures/vector/vector.c"
#include "libs/data_structures/vector/vectorVoid.h"
#include "libs/data_structures/vector/vectorVoid.c"
#include "libs/tests.c"

int main() {
    size_t n;
    scanf("%zd", &n);

    vectorVoid v = createVectorVoid(0, sizeof(int));
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);

        pushVectorVoidBack(&v, &x);
    }

    for (int i = 0; i < n; i++) {
        int x;
        getVectorVoidValue(&v, i, &x);

        printf("%d ", x);
    }

    return 0;
}
