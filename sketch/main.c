
#include <stdio.h>
#include <stdlib.h>

int main() {
    int a = 34;
    int *ptr = &a;

    int **ptrb = &ptr;

    printf("Value stored in a: %d\n", **ptrb);
    printf("Address of the ptrb: %p\n", &ptrb);
    printf("Value ptrb holds: %p\n", ptrb);

    return 0;
}
