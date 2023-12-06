#include <stdio.h>

#define MAX_SIZE 100

typedef  struct {
    int arr[MAX_SIZE];
    int top;
} Stack;

void initialize(Stack* stack) {
    stack -> top = -1;
}

int isEmpty(Stack* stack) {
    return stack -> top == -1;
}

int isFull(Stack* stack) {
    return stack -> top == MAX_SIZE - 1;
}

void push(Stack* stack, int data) {
    if (isFull(stack)) {
        printf("Stack Overflow\n");
        return;
    }
    stack -> arr[++stack -> top] = data;
}

int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack -> arr[stack -> top--];
}

int peek(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is Empty.\n");
        return -1;
    }
    return stack -> arr[stack -> top];
}

int main() {
    Stack myStack;
    initialize(&myStack);

    push(&myStack, 10);
    push(&myStack, 20);
    push(&myStack, 30);

    printf("%d\n", peek(&myStack));

    printf("%d\n", pop(&myStack));
    printf("%d\n", pop(&myStack));

    printf("%d\n", peek(&myStack));
}