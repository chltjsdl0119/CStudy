#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

TreeNode* insert(TreeNode* root, int value) {
    if (root == NULL) {
        TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));

        newNode -> data = value;
        newNode -> left = NULL;
        newNode -> right = NULL;
        return newNode;
    }

    if (value < root -> data) {
        root -> left = insert(root -> left, value);
    }
    else if (value > root -> data) {
        root -> right = insert(root -> right, value);
    }

    return root;
}

// 중위 순회 함수
void inorderTraversal(TreeNode* root) {
    if (root != NULL) {
        inorderTraversal(root -> left);
        printf("%d ", root -> data);
        inorderTraversal(root -> right);
    }
}

int main() {

    TreeNode* root = NULL;

    root = insert(root, 5);
    root = insert(root, 3);
    root = insert(root, 7);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 6);
    root = insert(root, 8);

    printf("Inorder Traversal: ");
    inorderTraversal(root);
    printf("\n");

    return 0;
}