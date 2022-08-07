
#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int item) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));    

    node->data = item;
    node->right = node->left = NULL;

    return node;
}

void inorder(struct Node *root) {
    if (root != NULL) {
        inorder(root->left);

        cout << root->data << endl;

        inorder(root->right);
    }
}

struct Node* insertNode(struct Node* root, int item) {
    if (root == NULL)
        return createNode(item);

    if (item < root->data)
        root->left = insertNode(root->left, item);

    if (item > root->data)
        root->right = insertNode(root->right, item);

    return root;
}

struct Node* findSmallestNode(struct Node* root) {
    struct Node* current = root;

    while (current && current->left != NULL) 
        current = current->left;

    return current;
}

struct Node * deleteNode(struct Node * root, int item) {
    if (root == NULL)
        return root;

    if (item < root->data)
        deleteNode(root->left, item);
    else if (item > root->data)
        deleteNode(root->right, item);
    else {
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return root;
        } 
        else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        struct Node *temp = findSmallestNode(root);

        root->data = temp->data;

        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

int findLargest(struct Node* root) {
    struct Node * current = root;

    while (current && current->right != NULL) 
        current = current->right;

    return current->data;
}

int findSmallest(struct Node* root) {
    struct Node* current = root;

    while (current && current->left != NULL) 
        current = current->left;

    return current->data;
}

int main() {
    struct Node* root = NULL;
    root = insertNode(root, 34);

    root = insertNode(root, 20);
    root = insertNode(root, 19);
    root = insertNode(root, 1);
    root = insertNode(root, 1);
    root = insertNode(root, 34);
    root = insertNode(root, 59);
    root = insertNode(root, 10);

    cout << "Smallest element: " << findSmallest(root) << endl;
    cout << "Largest element: " << findLargest(root) << endl;

    cout << "Tree values (inorder): " << endl;

    inorder(root);
    return 0;
}
