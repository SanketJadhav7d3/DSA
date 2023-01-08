
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};


struct Node* middle;
int count = 0;

struct Node* create_node(int data) {
    struct Node* node = malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;

    return node;
}

struct Node* insert_at_middle(struct Node *head, int data) {
    
    // create node
    struct Node* node = create_node(data);
    if (count < 2) {
        if (head == NULL) {
            head = node;
        } else {
            head->next = node;
        }
        count++;
        // head becomes middle 
        middle = head;
    } else {
        node->next = middle->next;
        middle->next = node;
        count++;

        if (count % 2 != 0) 
            middle = node;
    }

    return head;
}

struct Node* delete_node(struct Node* head, int data) {
    struct Node* temp = head;

    if (temp == NULL) {
        printf("List is empty\n");
        return head;
    }

    while (temp->data != data && temp != NULL)
        temp = temp->next;

    if (temp == NULL) {
        printf("Element not found\n");
        return head;
    }

    if (temp == head) {
        head = temp->next;
        free(temp);
    } else {
        
        // go till the node previous to the temp
        struct Node* prev = head;

        while (prev->next != temp)
            prev = prev->next;

        // if the node to be deleted is the last node
        if (temp->next == NULL) {
            prev->next = NULL;
            free(temp);
        } else {
            prev->next = temp->next;
            free(temp);
        }
    } 
    return head;
}

void print_list(struct Node* head) {
    while (head != NULL) {
        printf("%d  ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;

    head = insert_at_middle(head, 34);
    head = insert_at_middle(head, 3);
    head = insert_at_middle(head, 92);
    head = insert_at_middle(head, 4);

    print_list(head);

    head = delete_node(head, 92);
    head = delete_node(head, 92);
    head = delete_node(head, 92);
    head = delete_node(head, 92);
    head = delete_node(head, 92);

    print_list(head);

    return 0;
}
