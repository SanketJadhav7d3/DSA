
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

typedef struct Node Node;


void inorder(Node* root) {
    if (root != NULL) {
        // left -> root -> right

        inorder(root->left);

        printf(" %d ", root->data);

        inorder(root->right);
    }
}

void postorder(Node* root) {
    if (root != NULL) {
        // left -> right -> root
        
        postorder(root->left);

        postorder(root->right);

        printf(" %d ", root->data);
    }
}

void preorder(Node* root) {
    if (root != NULL) {
        // root -> left -> right

        printf(" %d ", root->data);

        preorder(root->left);

        preorder(root->right);
    }
}


int main() {

    Node* root = malloc(sizeof(Node));

    root->data = 34;

    root->left = malloc(sizeof(Node));

    root->left->data = 23;

    root->right = malloc(sizeof(Node));

    root->right->data = 58;

    root->left->right = malloc(sizeof(Node));

    root->left->right->data = 59;

    root->right->left = malloc(sizeof(Node));

    root->right->left->data = 10;

    printf("Inorder: ");

    inorder(root);

    printf("\nPreorder: ");

    preorder(root);

    printf("\nPostorder: ");
     
    postorder(root);

    return 0;
}
