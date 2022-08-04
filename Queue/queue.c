
#include <stdio.h>
#include <stdlib.h>
#define MAX 10

struct Queue {
    int arr[MAX];
    int front;
    int rear;
};

int is_full(struct Queue*q) {
    if (q->rear == MAX - 1) {
        return 1;
    }
    return 0;
}

int is_empty(struct Queue* q) {
    if (q->front == -1 || q->front > q->rear) {
        return 1;
    }
    return 0;
}

struct Queue* init_queue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

void enque(struct Queue*q, int i) {
    if (!is_full(q)) {
        if (q->front == -1) {
            q->front = 0;
        }
        q->arr[++q->rear] = i;
        return;
    }
    printf("Array full\n");
}

void deque(struct Queue*q) {
    if (!is_empty(q)) {
        printf("Removed element: %d\n", q->arr[q->front++]);
        return;
    }
    printf("Queue is empty\n");
}

void traverse(struct Queue* q) {
    if (!is_empty(q)) {
        printf("Elements in the queue: \n");
        for (int i = q->front; i <= q->rear; i++) {
            printf("%d\n",  q->arr[i]);
        }
        return;
    }
    printf("Queue empty\n");
}

int main() {
    struct Queue* q = init_queue();

    enque(q, 3);

    traverse(q);

    deque(q);

    traverse(q);

    free(q);

    return 0;
}
