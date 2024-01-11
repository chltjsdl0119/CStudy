#include <stdio.h>
#include <stdlib.h>

// 이진 트리 노드를 나타내는 구조체 정의
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// 새로운 이진 트리 노드를 생성하는 함수
struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// 이진 트리에 노드를 삽입하는 함수
struct TreeNode* insertNode(struct TreeNode* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }

    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else if (data > root->data) {
        root->right = insertNode(root->right, data);
    }

    return root;
}

// 이진 트리를 중위 순회하여 노드를 출력하는 함수
void inorderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// 메모리를 해제하는 함수
void freeTree(struct TreeNode* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main() {
    struct TreeNode* root = NULL;

    // 이진 트리에 노드 삽입
    root = insertNode(root, 50);
    insertNode(root, 30);
    insertNode(root, 20);
    insertNode(root, 40);
    insertNode(root, 70);
    insertNode(root, 60);
    insertNode(root, 80);

    // 중위 순회하여 노드 출력
    printf("Inorder Traversal: ");
    inorderTraversal(root);
    printf("\n");

    // 메모리 해제
    freeTree(root);

    return 0;
}
