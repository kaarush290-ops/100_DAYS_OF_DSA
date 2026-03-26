/**/
/*Problem Statement:
Perform zigzag (spiral) level order traversal of a binary tree. Alternate levels should be traversed left-to-right and right-to-left.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 indicates NULL)

Output Format:
- Print traversal in zigzag order

Example:
Input:
7
1 2 3 4 5 6 7

Output:
1 3 2 4 5 6 7

Explanation:
Level 1 is printed left-to-right, level 2 right-to-left, and so on*/

#include <stdio.h>
#include <stdlib.h>

// Tree Node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create node
struct Node* newNode(int val) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = val;
    temp->left = temp->right = NULL;
    return temp;
}

// Queue
struct Queue {
    struct Node* arr[2000];
    int front, rear;
};

// Init queue
void initQueue(struct Queue* q) {
    q->front = q->rear = 0;
}

// Enqueue
void enqueue(struct Queue* q, struct Node* node) {
    q->arr[q->rear++] = node;
}

// Dequeue
struct Node* dequeue(struct Queue* q) {
    return q->arr[q->front++];
}

// Check empty
int isEmpty(struct Queue* q) {
    return q->front == q->rear;
}

// Get size
int size(struct Queue* q) {
    return q->rear - q->front;
}

// Build Tree
struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    struct Node* root = newNode(arr[0]);
    struct Queue q;
    initQueue(&q);

    enqueue(&q, root);
    int i = 1;

    while (!isEmpty(&q) && i < n) {
        struct Node* curr = dequeue(&q);

        if (i < n && arr[i] != -1) {
            curr->left = newNode(arr[i]);
            enqueue(&q, curr->left);
        }
        i++;

        if (i < n && arr[i] != -1) {
            curr->right = newNode(arr[i]);
            enqueue(&q, curr->right);
        }
        i++;
    }

    return root;
}

// Zigzag Traversal
void zigzagTraversal(struct Node* root) {
    if (!root) return;

    struct Queue q;
    initQueue(&q);

    enqueue(&q, root);

    int leftToRight = 1;

    while (!isEmpty(&q)) {
        int levelSize = size(&q);
        int level[2000];

        for (int i = 0; i < levelSize; i++) {
            struct Node* curr = dequeue(&q);

            level[i] = curr->data;

            if (curr->left) enqueue(&q, curr->left);
            if (curr->right) enqueue(&q, curr->right);
        }

        // Print based on direction
        if (leftToRight) {
            for (int i = 0; i < levelSize; i++) {
                printf("%d ", level[i]);
            }
        } else {
            for (int i = levelSize - 1; i >= 0; i--) {
                printf("%d ", level[i]);
            }
        }

        leftToRight = !leftToRight; // flip direction
    }
}

// Main
int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct Node* root = buildTree(arr, n);
    zigzagTraversal(root);

    return 0;
}