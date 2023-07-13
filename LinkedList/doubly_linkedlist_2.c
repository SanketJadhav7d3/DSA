
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node* next;
  struct Node* prev;
} Node;

Node* create_node(int data) {
  Node* node = malloc(sizeof(*node));
  node->data = data;
  node->next = NULL;
  node->prev = NULL;
  return node;
} 

Node* insert_at_beg(Node* head, int data) {
  if (head == NULL)
    return create_node(data);

  Node* new_node = create_node(data);

  new_node->next = head;
  head->prev = new_node;

  return new_node;
}

Node* insert_at_end(Node* head, int data) {
  if (head == NULL) return create_node(data);

  Node* curr = head;
  while (curr->next != NULL)
    curr = curr->next;

  Node* new_node = create_node(data);

  new_node->prev = curr; 
  curr->next = new_node;

  return head;
}

Node* delete_first(Node* head) {
  if (head == NULL) return head;
  head = head->next; 
  free(head->prev);
  head->prev = NULL;
  return head;
}

void delete_last(Node* head) {
  if (head == NULL) return;

  while (head->next != NULL) head = head->next;

  head->prev->next = NULL;
  free(head);
}

void print_list(Node* head) {
  while (head != NULL) {
    printf("%d ", head->data);
    head = head->next;
  }
  printf("\n");
}

Node *head = NULL;

int main() {
  head = insert_at_end(head, 5);
  head = insert_at_end(head, 50);
  head = insert_at_end(head, 39);
  head = insert_at_beg(head, 39);
  head = insert_at_beg(head, 3);
  head = insert_at_beg(head, 58);
  
  print_list(head);

  head = delete_first(head);

  print_list(head);

  delete_last(head);

  print_list(head);

}
