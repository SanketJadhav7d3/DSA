#include <stdlib.h>
#include <stdio.h>

// binary tree node
struct Node {
    int value;
    struct Node* left;
    struct Node* right;
};

void traverseInOrder(struct Node* root) {
    if (root == NULL) {
        return;
    }

    traverseInOrder(root->left);

    printf("%d\n", root->value);

    traverseInOrder(root->right);
}

void traversePostOrder(struct Node* root) {
    if (root == NULL) {
        return;
    }

    // print the left first
    traversePostOrder(root->left);

    // then print the right 
    traversePostOrder(root->right);

    printf("%d\n", root->value);
}

void traversePreOrder(struct Node* root) {
    if (root == NULL) {
        return;
    }

    printf("%d\n", root->value);

    // print the left first
    traversePostOrder(root->left);

    // then print the right 
    traversePostOrder(root->right);
}

int main(int argc, char *argv[]) {

    struct Node* root = (struct Node*)malloc(sizeof(struct Node));

    printf("Argc: %d\n", argc);
    printf("File name: %s\n", argv[0]);

    root->value = 34;

    root->left = (struct Node*)malloc(sizeof(struct Node));

    root->left->value = 93;

    root->right = (struct Node*)malloc(sizeof(struct Node));

    root->right->value = 30;

    root->right->right = NULL;

    root->right->left = NULL;

    root->left->right = NULL;

    root->left->left = NULL;

    traversePostOrder(root);

    return 0;
}
