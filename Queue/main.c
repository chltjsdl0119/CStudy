#include <stdio.h>

#define MAX_SIZE 10

typedef struct {
    int front, rear;
    int data[MAX_SIZE];
} Queue;

void initializeQueue(Queue* queue) {
    queue -> front = -1;
    queue -> rear = -1;
}

int isEmpty(Queue* queue) {
    return (queue -> front == -1 && queue -> rear == -1);
}

int isFull(Queue* queue) {
    return ((queue -> rear + 1) % MAX_SIZE == queue -> front);
}

void enqueue(Queue* queue, int value) {
    if (isFull(queue)) {
        printf("Queue is Full.\n");
        return;
    }

    if (isEmpty(queue)) {
        queue -> front = 0;
        queue -> rear = 0;
    }
    else {
        queue -> rear = (queue -> rear + 1) % MAX_SIZE;
    }

    queue -> data[queue -> rear] = value;
}

int dequeue(Queue* queue) {
    int value;

    if (isEmpty(queue)) {
        printf("Queue is Empty.\n");
        return -1;
    }
    else if (queue -> front == queue -> rear) {
        value = queue -> data[queue -> front];
        initializeQueue(queue);
    }
    else {
        value = queue -> data[queue -> front];
        queue -> front = (queue -> front + 1) % MAX_SIZE;
    }

    return value;
}

void printQueue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is Empty.\n");
        return;
    }

    printf("Queue : ");
    int i = queue -> front;
    do {
        printf("%d ", queue -> data[i]);
        i = (i + 1) % MAX_SIZE;
    }
    while (i != (queue -> rear + 1) % MAX_SIZE);
    printf("\n");
}

int main() {
    Queue myQueue;
    initializeQueue(&myQueue);

    enqueue(&myQueue, 1);
    enqueue(&myQueue, 2);
    enqueue(&myQueue, 3);
    printQueue(&myQueue);

    dequeue(&myQueue);
    printQueue(&myQueue);

    enqueue(&myQueue, 1);
    printQueue(&myQueue);

    dequeue(&myQueue);
    printQueue(&myQueue);

    return 0;
}