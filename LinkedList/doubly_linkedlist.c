
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

void insert_at_beg(struct Node **head, int data) {
    // create node
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));

    node->data = data;
    node->prev = NULL;

    if ((*head) != NULL) {
        (*head)->prev = node;
        node->next = (*head);
    }

    // new head
    (*head) = node;
}

void insert_at_end(struct Node **head, int data) {

    struct Node* node = malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    
    if ((*head) != NULL) {
        struct Node* dummy = (*head);

        // go till end 
        while (dummy->next != NULL) {
            dummy = dummy->next;
        }

        dummy->next = node;
        node->prev = dummy;
    } else {
        *head = node;
    }
}

void insert_after(struct Node** head, int element, int after) {

    // create a node
    // search the after element
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));

    node->data = element;

    struct Node* dummy = (*head);

    while (dummy->data != after) {
        dummy = dummy->next;
    }

    node->next = dummy->next;
    dummy->next = node;
    node->prev = dummy;
}

void delete_node(struct Node** head, int element) {
    struct Node* temp = (*head);

    while (temp->data != element) {
        temp = temp->next;
    }

    // if node to be deleted is at the end
    if (temp->next == NULL) {
        temp->prev->next = NULL;
    }

    // if it is the head node
    if (temp == (*head)) {
        (*head)->next->prev = NULL;
        (*head) = (*head)->next;
    }

    // if it is in the middle
    if (temp->prev != NULL) {
        // need to update next as well as previous of the node
        temp->prev->next = temp->next;
        // reverse link
        temp->next->prev = temp->prev;
    }

    free(temp);
}

void print_list(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    while (head != NULL) {
        printf("%d  ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct Node *head = NULL;

    insert_at_beg(&head, 34);
    insert_at_beg(&head, 3);
    insert_at_beg(&head, 34);

    print_list(head);

    insert_after(&head, 94, 3);

    print_list(head);

    delete_node(&head, 94);

    print_list(head);

    insert_at_end(&head, 392);

    print_list(head);

    return 0;
}
