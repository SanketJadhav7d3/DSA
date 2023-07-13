
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* next;
} Node;

Node* init_node(int value) {
  Node* node = malloc(sizeof(*node));
  node->value = value;
  node->next = NULL;

  return node;
}

Node* push(Node* top, int value) {
  // O(1)
  if (top == NULL)
    return init_node(value);

  Node* node = init_node(value);
  node->next = top;
  top = node;

  return top;
}

Node* pop(Node* top) {
  // O(1)
  if (top == NULL) 
    return NULL;

  Node* temp = top;
  top = top->next;
  free(temp);

  return top;
}

void print_block(int value, int is_top) {
  int totalWidth = 8; 
  int numDigits = snprintf(NULL, 1, "%d", value); 

  int leftSpace = (totalWidth - numDigits - 2) / 2; 
  int rightSpace = totalWidth - numDigits - 2 - leftSpace; 

  if (is_top)
    printf("|%*s%d%*s| <- top\n", leftSpace, "", value, rightSpace, "");
  else 
    printf("|%*s%d%*s|\n", leftSpace, "", value, rightSpace, ""); 
}


int pop_with_return(Node** top) {
  if (*top == NULL) 
    return -1;

  Node* temp = *top;
  *top = (*top)->next;
  int value = temp->value;

  free(temp);

  return value;
}

void print_stack(Node* top) {
  if (top == NULL) {
    printf("No elements\n");
    return;
  }

  printf("Stack elements: (Top -> Bottom)\n");
  print_block(top->value, 1);
  top = top->next;
  while (top != NULL) {
    print_block(top->value, 0);
    top = top->next;
  }
}

int main() {
  Node* top = NULL;

  for (int i = 0; i < 20; i += 1)
    top = push(top , i);

  print_stack(top);
  printf("Popped: %d\n", pop_with_return(&top));
  printf("Popped: %d\n", pop_with_return(&top));
  printf("Popped: %d\n", pop_with_return(&top));
  printf("Popped: %d\n", pop_with_return(&top));
  print_stack(top);

  return 0;
}
