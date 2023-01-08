
#include <stdio.h>
#define SIZE 10

int queue[SIZE];
int rear = -1;
int front = -1;

int isFull() {
    if ((front == 0 && rear == SIZE - 1) || (rear == front - 1))
        return 1;
    return 0;
}

int isEmpty() {
    if (front == -1) {
        return 1;
    }

    return 0;
}

void enque(int a) {

    if (isFull()) {
        printf("Queue is full\n");
        return;
    }

    if (front == -1)
        front = 0;

    rear = (rear + 1) % 10;
    queue[rear] = a;
    printf("Element enqueued in queue: %d\n", queue[rear]);
}

void deque() {

    if (isEmpty()) {
        front = -1;
        rear = -1;
        printf("Queue is empty\n");
        return;
    }

    printf("Element dequeued: %d\n", queue[front++]);
}

void printQueue() {

    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }

    printf("Elements in queue: \n");
    for (int i = 0; i < SIZE; ++i) {
        printf("%d  ", queue[i]);
    }
    printf("\n");
}

int main() {

    for (int i = 0; i < SIZE; ++i)
        enque(i);

    printQueue();

    enque(34);

    deque();

    printQueue();

    enque(34);

    printQueue();

    enque(34);

    printQueue();

    return 0;
}
