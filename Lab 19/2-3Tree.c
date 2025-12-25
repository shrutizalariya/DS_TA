//2-3 Tree Implementation in C

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data1, data2;
    struct Node *left, *middle, *right;
    int isTwoNode; // 1 = two-node, 0 = three-node
} Node;

// Create a new two-node
Node* createTwoNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data1 = data;
    node->data2 = -1;
    node->left = node->middle = node->right = NULL;
    node->isTwoNode = 1;
    return node;
}

// Insert function for leaf level (basic version)
Node* insert(Node* root, int data) {
    if (root == NULL) return createTwoNode(data);

    if (root->isTwoNode) {
        // If it's a 2-node and leaf
        if (!root->left && !root->middle) {
            // Make it 3-node
            root->isTwoNode = 0;
            if (data < root->data1) {
                root->data2 = root->data1;
                root->data1 = data;
            } else {
                root->data2 = data;
            }
            return root;
        }
        // Recurse
        if (data < root->data1)
            root->left = insert(root->left, data);
        else
            root->middle = insert(root->middle, data);
    } else {
        // It's a 3-node
        if (!root->left && !root->middle && !root->right) {
            // Need to split
            Node* newRoot = createTwoNode(0);
            int a = root->data1, b = root->data2, c = data;
            // Sort a, b, c
            if (a > b) { int t = a; a = b; b = t; }
            if (a > c) { int t = a; a = c; c = t; }
            if (b > c) { int t = b; b = c; c = t; }

            newRoot->data1 = b;
            newRoot->left = createTwoNode(a);
            newRoot->middle = createTwoNode(c);
            return newRoot;
        }
        // Recurse into correct child
        if (data < root->data1)
            root->left = insert(root->left, data);
        else if (data < root->data2)
            root->middle = insert(root->middle, data);
        else
            root->right = insert(root->right, data);
    }
    return root;
}

// In-order traversal
void inorder(Node* root) {
    if (root == NULL) return;

    if (root->isTwoNode) {
        inorder(root->left);
        printf("%d ", root->data1);
        inorder(root->middle);
    } else {
        inorder(root->left);
        printf("%d ", root->data1);
        inorder(root->middle);
        printf("%d ", root->data2);
        inorder(root->right);
    }
}

// Main function
int main() {
    Node* root = NULL;

    int arr[] = {10, 20, 5, 15, 25, 30, 3};
    int n = sizeof(arr)/sizeof(arr[0]);

    for (int i = 0; i < n; i++) {
        root = insert(root, arr[i]);
    }

    printf("In-order Traversal of 2-3 Tree:\n");
    inorder(root);
    printf("\n");

    return 0;
}