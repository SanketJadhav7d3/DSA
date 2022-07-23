
#include <stdio.h>
#define MAX 10

int stack[MAX];

int top = -1;

void pop() {
    if (top == -1 || top == 0) {
        printf("No elements in the stack\n");
        return;
    }
    top--;
}

void push(int e) {
    if (top == (MAX - 1)) {
        printf("Stack is full\n");
        return;
    }
    stack[top++] = e;
}

void print_stack() {
    printf("Stack elements: \n");
    for (int i = top; i >= 0; i--) {
        printf("%d\n", stack[i]);
    }
}

int main() {

    push(34);
    push(34);
    push(34);
    pop();

    print_stack();

    return 0;
}
