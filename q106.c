/*102. Binary Tree Level Order Traversal
Medium
Topics
premium lock icon
Companies
Hint
Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: [[3],[9,20],[15,7]]
Example 2:

Input: root = [1]
Output: [[1]]
Example 3:

Input: root = []
Output: []
 

Constraints:

The number of nodes in the tree is in the range [0, 2000].
-1000 <= Node.val <= 1000*/

#include <stdio.h>
#include <stdlib.h>

// Tree Node
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Create new node
struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// Queue for BFS
struct Queue {
    struct TreeNode* arr[2000];
    int front, rear;
};

// Initialize queue
void initQueue(struct Queue* q) {
    q->front = q->rear = 0;
}

// Enqueue
void enqueue(struct Queue* q, struct TreeNode* node) {
    q->arr[q->rear++] = node;
}

// Dequeue
struct TreeNode* dequeue(struct Queue* q) {
    return q->arr[q->front++];
}

// Check empty
int isEmpty(struct Queue* q) {
    return q->front == q->rear;
}

// Get size of queue
int size(struct Queue* q) {
    return q->rear - q->front;
}

// Build tree from level order array (-1 = NULL)
struct TreeNode* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    struct TreeNode* root = newNode(arr[0]);
    struct Queue q;
    initQueue(&q);

    enqueue(&q, root);
    int i = 1;

    while (!isEmpty(&q) && i < n) {
        struct TreeNode* curr = dequeue(&q);

        // Left child
        if (i < n && arr[i] != -1) {
            curr->left = newNode(arr[i]);
            enqueue(&q, curr->left);
        }
        i++;

        // Right child
        if (i < n && arr[i] != -1) {
            curr->right = newNode(arr[i]);
            enqueue(&q, curr->right);
        }
        i++;
    }

    return root;
}

// Level Order Traversal
void levelOrder(struct TreeNode* root) {
    if (!root) {
        printf("[]\n");
        return;
    }

    struct Queue q;
    initQueue(&q);

    enqueue(&q, root);

    printf("[\n");

    while (!isEmpty(&q)) {
        int levelSize = size(&q);

        printf("  [");

        for (int i = 0; i < levelSize; i++) {
            struct TreeNode* curr = dequeue(&q);

            printf("%d", curr->val);
            if (i < levelSize - 1) printf(", ");

            if (curr->left) enqueue(&q, curr->left);
            if (curr->right) enqueue(&q, curr->right);
        }

        printf("]");

        if (!isEmpty(&q)) printf(",");
        printf("\n");
    }

    printf("]\n");
}

// Main
int main() {
    int n;
    scanf("%d", &n);

    if (n == 0) {
        printf("[]\n");
        return 0;
    }

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct TreeNode* root = buildTree(arr, n);
    levelOrder(root);

    return 0;
}