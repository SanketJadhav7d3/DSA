
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int elem;
    struct Node* next;
};

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
        return;
    }

    while (root->next != NULL) {
        root = root->next;
    }

    root->next = (struct Node*)malloc(sizeof(struct Node));
    root->next->elem = elem;
    root->next->next = NULL;
}

void pull(struct Node* root) {

}

int main() {

}
