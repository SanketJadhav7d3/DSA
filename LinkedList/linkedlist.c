
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* middle;
int count = 0;

Node* create_node(int data) {
    Node* node = malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

Node* insert_at_middle(Node *head, int data) {
    
    // create node
    Node* node = create_node(data);
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

Node* insert_at_end(Node *head, int data) {

  Node* node = create_node(data); 
  count++;

  if (head == NULL) {
    return node;
  }

  Node* temp = head;
  // go till the last node
  while (temp->next) temp = temp->next;

  temp->next = node;

  return head;
}

Node* insert_after(Node* head, int after_value, int data) {
  Node* node = create_node(data);
  Node* current = head;

  while (current->data != after_value) current = current->next;

  node->next = current->next;
  current->next = node;

  return head;
}

Node* delete_first(Node* head) {
  if (head == NULL)
    return head;

  Node* temp = head;
  head = head->next;
  free(temp);

  return head;
}

Node* delete_last(Node* head) {
  Node* curr = head;

  while (curr->next->next) 
    curr = curr->next;
  free(curr->next);

  curr->next = NULL;

  return head;
}

Node* delete_node(Node* head, int data) {
    Node* temp = head;

    if (temp == NULL) {
        printf("List is empty\n");
        return head;
    }

    while (temp != NULL && temp->data != data) temp = temp->next;

    if (temp == NULL) {
        printf("Element not found\n");
        return head;
    }

    if (temp == head) {
        head = temp->next;
        free(temp);
    } else {
        
        // go till the node previous to the temp
        Node* prev = head;

        while (prev->next != temp) prev = prev->next;

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

Node* createListFromArray(int *arr, int arr_size) {
  Node* head = create_node(arr[0]);

  for (int i = 1; i < arr_size; ++i) {
    head = insert_at_end(head, arr[i]);
  }

  return head;
}

void print_list(Node* head) {
    while (head != NULL) {
        printf("%d  ", head->data);
        head = head->next;
    }
    printf("\n");
}

void print_list_recursive(Node *head) {
  if (head == NULL) return;

  printf("%d  ", head->data);

  print_list_recursive(head->next);
}


int sum_linkedlist_rec(Node* head) {
  if (head == NULL) return 0;
  return head->data + sum_linkedlist_rec(head->next);
}

int sum_linkedlist(Node* head) {
  int sum = 0;

  while (head) {
    sum += head->data;
    head = head->next;
  }

  return sum;
}

void print_reverse(Node* head) {
  if (head == NULL)
    return;
  print_reverse(head->next);
  printf("%d  ", head->data);
}

Node* reverse_list(Node* head) {
  Node* currentP = head;
  Node* nextP = head->next;
  Node* prevP = NULL;

  while (currentP) {
    currentP->next = prevP;
    prevP = currentP;
    currentP = nextP;
    if (nextP) nextP = nextP->next;
  }

  return prevP;
}


void insert_at_end_rec(Node** head, int data) {
  if (*head == NULL) {
    *head = create_node(data);
  } else {
    if ((*head)->next == NULL)
      (*head)->next = create_node(data);
    else
      // will be double pointer to the next node &((*head)->next)
      insert_at_end_rec(&((*head)->next), data);
  }
}

Node* better_insert_end(Node* head, int data) {
  if (head == NULL) return create_node(data);
  head->next = better_insert_end(head->next, data);
  // pointer to the previous node returned to each function call 
  return head;
}

Node* remove_first(Node* head, int data) {
  if (head == NULL)
    return NULL;

  if (head->data == data) {
    Node* temp = head->next;
    free(head);
    return temp;
  } else {
    head->next = remove_first(head->next, data);
    return head;
  }
}

Node* remove_all(Node* head, int data) {
  // memory leak
  if (head == NULL) return NULL;
  else
    if (head->data == data) {
      return remove_all(head->next, data);
    }
    else {
      head->next = remove_all(head->next, data);
      return head;
    }
}


int length(Node* head) {
  if (head) return 1 + length(head->next);
  return 0;
}

// prev = NULL, curr = head;
Node* reverse_list_rec(Node* prev, Node* curr) {
  if (curr == NULL) return prev;
  Node* nextP = curr->next;
  curr->next = prev;
  return reverse_list_rec(curr, nextP); 
}


// prev = NULL, curr = head;
Node* reverse_list_rec3(Node* prev, Node* curr) {
  if (curr == NULL) return prev;
  Node* n = reverse_list_rec3(curr, curr->next); // this will return prev after curr reaches the NULL
  curr->next = prev;
  return n;
}

Node* reverse_list_rec2(Node* curr) {
  if (curr == NULL || curr->next == NULL) return curr;
  Node* n = reverse_list_rec2(curr->next);
  curr->next->next = curr;
  curr->next = NULL;
  return n;
}

Node* mystery(Node* a, Node* b) {
  while (b) {
    Node* t = a->next->next;
    a->next->next = b;
    a = b;
    b = t;
  }
  return a;
}

int main() {
  int a[] = {1, 2, 3, 4};
  int b[] = {6, 7, 8, 9};

  Node* list_a = createListFromArray(a, sizeof(a)/ sizeof(int));
  Node* list_b = createListFromArray(b, sizeof(b)/ sizeof(int));

  Node* res = mystery(list_a, list_b);

  print_list(res);
  // some merging in wierd way 
  print_list(list_a);

  return 0;
}
