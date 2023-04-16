
#include <stdio.h>
#define MAX 10

int deque[MAX];

int front = -1;
int rear = 0;

int overflow() {
    if ((front == 0 && rear == -1) || (front = rear + 1)) 
        return 1;
    return 0;
}

int underflow() {
    if (front == -1)
        return 1;
    return 0;
}

void insert_front(int data) {
    if (front < 1) 
        front = MAX - 1;
    else 
        front--;
    
    deque[front] = data;
}

void insert_end(int data) {
    if (overflow()) {
        rear = 0;
    } else {
        rear++;
    }

    deque[rear] = data; 
}

void delete_front() {
    if (underflow()) {
        printf("Deque underflow\n");
        return;
    }
    else if (front == rear) 
        front = rear = -1;
    else if (front == MAX - 1)
        front = 0;
    else 
        front++;
    deque[front] = 0;
}

void delete_rear() {
    if (underflow()) {
        printf("Deque underflow\n");
        return;
    }
    if (front == rear)
        front = rear = -1;
    else if (rear == 0)
        rear = MAX - 1;
    else 
        rear++;

    deque[rear] = 0;
}

void display() {
    printf("Front: ");
    for (int i = 0; i < MAX; i++) 
        printf("%d  ", deque[i]);
    printf(" : Rear\n");
}

int main() {

    insert_front(34);
    insert_front(4);
    insert_front(3);
    insert_front(50);

    delete_front();
    delete_front();
    delete_front();

    display();

    return 0;
}
