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

struct Node* search(int data, struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {

        if (current -> data == data) {
            return current;
        }
        current = current -> next;

    }
    printf("search failed.\n");
    return NULL;
}

struct Node* searchAt(int index, struct Node* head) {

    int count = 0;

    struct Node* current = head;
    while (current != NULL) {

        if (index == count) {
            return current;
        }

        current = current -> next;
        count++;

    }
    printf("search failed.\n");
    return NULL;
}

void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current -> data);
        current = current -> next;
    }
    printf("NULL\n");
}

void add(struct Node* head, struct Node* new_node) {
    struct Node* current = head;

    while (current -> next != NULL) {
        current = current -> next;
    }

    current -> next = new_node;
    new_node->next = NULL;
}

void removeAt(int index, struct Node* head) {

    struct Node* tmp = searchAt(index, head);

    struct Node* prevTmp = searchAt(index - 1, head);

    if (prevTmp != NULL) {
        prevTmp -> next = tmp -> next;
    }

    free(tmp);
}

int main() {

    struct Node* head = NULL;
    struct Node* node = NULL;
    struct Node* node2 = NULL;

    node = createNode(25);
    node2 = createNode(35);

    head = createNode(1);
    head -> next = createNode(2);

    add(head, node);

    removeAt(1, head);

    add(head, node2);

    printList(head);

    return 0;
}