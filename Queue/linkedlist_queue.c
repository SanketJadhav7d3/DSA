
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node* createNode(int data) {
    struct Node* node = malloc(sizeof(struct Node*));

    node->data = data;
    node->next = NULL;

    return node;
}

struct Node* enque(struct Node* head, int data) {

    // insert the element at the start of the linked list
    
    if (head == NULL) {
        head = createNode(data);
        return head;
    }
    
    // create node
    struct Node* dummy = createNode(data);

    dummy->next = head;

    head = dummy;

    return head;
}

int deqeue(struct Node* head) {
    // remove the trailing element

    // go to the second last element
    struct Node* dummy = head;
    while (dummy->next->next != NULL) {
        dummy = dummy->next;
    }

    int value = dummy->next->data;

    free(dummy->next->next);

    dummy->next = NULL;

    return value;
}

void printList(struct Node* head) {
    struct Node* dummy = head;
    printf("Linked list: ");

    while (dummy != NULL) {
        printf("%d  ", dummy->data);
        dummy = dummy->next;
    }
    printf("\n");
}

int main() {

    struct Node *head = NULL;
    head = enque(head, 34);
    head = enque(head, 4);
    head = enque(head, 3);
    head = enque(head, 34);
    head = enque(head, 34);

    printList(head);

    printf("%d\n", deqeue(head));

    printList(head);

    return 0;
}
