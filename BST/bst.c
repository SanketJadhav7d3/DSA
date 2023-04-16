
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int data) {
    Node* node = malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return node;
}

Node* insert(Node* root, int data) {
    if (root == NULL) {
        root = createNode(data);
        return root;
    }
    else if (root->data > data) 
        root->left = insert(root->left, data);
    else if (root->data < data)
        root->right = insert(root->right, data);

    return root;
}

void find(Node* root, int data) {
    if (root == NULL) {
        printf("BST empty");
        return;
    }

    if (root->data == data) {
        printf("Element found");
        return;
    }

    else if (data < root->data)
        find(root->left, data);
    else if (data > root->data)
        find(root->right, data);
}

void delete(int data) {

}

void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);

        printf("%d ", root->data);

        inorder(root->right);
    }
}

void preorder(Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);

        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);

        printf("%d ", root->data);
    }
}

int main() {
    Node* root = NULL;

    root = insert(root, 30);
    root = insert(root, 58);
    root = insert(root, 12);
    root = insert(root, 2);
    root = insert(root, 50);
    root = insert(root, 19);

    inorder(root);
    printf("\n");

    preorder(root);
    printf("\n");

    postorder(root);



    return 0;
}
