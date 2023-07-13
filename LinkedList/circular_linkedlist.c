
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node *node = malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

Node* insert_at_beg(Node* last, int data) {
    if (last == NULL) {
        last = createNode(data);
        last->next = last;      // link to itself
        return last;
    }

    Node* newNode = createNode(data);

    newNode->next = last->next;
    last->next = newNode;

    return last;
}

Node* insert_at_end(Node* last, int data) {
    if (last == NULL) {
        last = createNode(data);
        last->next = last;
        return last;
    }

    Node* newNode = createNode(data);

    newNode->next = last->next;

    last->next = newNode;

    last = newNode;

    return last;
}

Node* insert_after(Node* last, int after, int data) {
    if (last == NULL) {
        printf("There are no elements present\n");
        return last;
    }
    
    struct Node* prev = last->next;

    while (prev->data != after && prev != last) {
        prev = prev->next;
    }

    if (prev == last) {
        printf("Element %d is not present\n", after);
    } else {
        Node* new_node = createNode(data);
        new_node->next = prev->next;
        prev->next = new_node;
    }

    return last;
}

void display(Node* last) {
    Node* curr = last->next;
    printf("Elements: ");
    while (curr != last) {
        printf("%d  ", curr->data);
        curr = curr->next;
    }
    printf("%d", curr->data);
    printf("\n");
}

int length(Node* last) {
  Node* curr = last->next;
  int length = 1;

  while (curr != last) {
    length++;
    curr = curr->next;
  }

  return length;
}

int main() {
    Node* last = NULL;

    last = insert_at_beg(last, 34);
    last = insert_at_beg(last, 30);
    last = insert_at_beg(last, 10);
    
    display(last);

    last = insert_after(last, 30, 3);

    display(last);

    last = insert_at_end(last, 40);

    display(last);

    printf("Length: %d\n", length(last));

    return 0;
}
