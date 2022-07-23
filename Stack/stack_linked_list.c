
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int elem;
    struct Node* next;
};

struct Node* top;

struct Node* init_node(int i) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));

    node->elem = i;

    node->next = NULL;

    return node;
}

void push(struct Node* root, int elem) {
    if (root == NULL) {
        struct Node* root = (struct Node*)malloc(sizeof(struct Node));
        root->elem = elem;
        top = root;
        return;
    }

    while (root->next != NULL) {
        root = root->next;
    }

    root->next = (struct Node*)malloc(sizeof(struct Node));
    root->next->elem = elem;
    root->next->next = NULL;

    top = root->next;
}

void print_stack(struct Node* root) {
    if (root != NULL) {
        printf("Stack elements: \n");
        do {
            printf("%d\n", root->elem);
            root = root->next;
        } while (root->next != NULL);
    } else {
        printf("No elements in stack\n");
    }
}

void pop(struct Node* root) {
    if (root->next == NULL) {
        // there is only one element in the list
        root = NULL;
        return;
    }

    // to the last second element
    while (root->next->next != NULL) {
        root = root->next;
    }

    // deallocate memory
    free(root->next);

    top = root;
    top->next = NULL;
}

int main() {
    struct Node* root = init_node(34);

    push(root, 50);
    push(root, 50);
    push(root, 50);
    push(root, 50);

    print_stack(root);

    return 0;
}
