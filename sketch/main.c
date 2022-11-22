
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

int main() {
    // pointers

    int a = 34;
    int *ptr = &a;
        
    printf("Without using pointer: \n");
    printf("%p\n", &a);
    printf("%d\n", *(&a));

    printf("With using pointer: \n");
    printf("%p\n", ptr);
    printf("%d\n", *ptr);
    printf("Address of the pointer: %p\n", &ptr);

    return 0;
}
