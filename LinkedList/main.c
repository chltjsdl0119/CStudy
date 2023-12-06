#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("error");
        exit(1);
    }
    newNode -> data = data;
    newNode -> next = NULL;
    return newNode;
}

void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current -> data);
        current = current -> next;
    }
    printf("NULL\n");
}

void addNode(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    }
    else {
        struct Node* current = *head;
        while (current -> next != NULL) {
            current = current -> next;
        }
        current -> next = newNode;
    }
}

int main() {
    struct Node* head = NULL;

    head = createNode(1);
    head -> next = createNode(2);
    head -> next -> next = createNode(3);

    printList(head);

    return 0;
}