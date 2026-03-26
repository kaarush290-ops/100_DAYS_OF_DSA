/*Given a binary tree, print its vertical order traversal. Nodes that lie on the same vertical line should be printed together from top to bottom and from left to right.

///Input Format:
- First line contains integer N (number of nodes)
- Second line contains N space-separated integers representing level-order traversal (-1 indicates NULL)

Output Format:
- Print nodes column by column from leftmost to rightmost vertical line

Example:
Input:
7
1 2 3 4 5 6 7

Output:
4
2
1 5 6
3
7

Explanation:
Vertical lines are formed based on horizontal distance from root. Nodes sharing the same distance are printed together*/


#include <stdio.h>
#include <stdlib.h>

// Tree Node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create new node
struct Node* newNode(int val) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = val;
    temp->left = temp->right = NULL;
    return temp;
}

// Queue Node for BFS (stores node + HD)
struct QNode {
    struct Node* node;
    int hd;
};

// Queue structure
struct Queue {
    int front, rear, size;
    struct QNode* arr;
};

// Create Queue
struct Queue* createQueue(int size) {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = 0;
    q->size = size;
    q->arr = (struct QNode*)malloc(size * sizeof(struct QNode));
    return q;
}

// Enqueue
void enqueue(struct Queue* q, struct Node* node, int hd) {
    q->arr[q->rear].node = node;
    q->arr[q->rear].hd = hd;
    q->rear++;
}

// Dequeue
struct QNode dequeue(struct Queue* q) {
    return q->arr[q->front++];
}

// Check empty
int isEmpty(struct Queue* q) {
    return q->front == q->rear;
}

// Build Tree (level order)
struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    struct Node* root = newNode(arr[0]);
    struct Queue* q = createQueue(n);

    enqueue(q, root, 0);
    int i = 1;

    while (!isEmpty(q) && i < n) {
        struct Node* curr = dequeue(q).node;

        // Left child
        if (i < n && arr[i] != -1) {
            curr->left = newNode(arr[i]);
            enqueue(q, curr->left, 0);
        }
        i++;

        // Right child
        if (i < n && arr[i] != -1) {
            curr->right = newNode(arr[i]);
            enqueue(q, curr->right, 0);
        }
        i++;
    }

    return root;
}

// Vertical Order Traversal
void verticalOrder(struct Node* root, int n) {
    if (!root) return;

    // Map simulation using array (range -1000 to +1000)
    int offset = 1000;
    int result[2000][100];  // storing nodes
    int count[2000] = {0};

    struct Queue* q = createQueue(n);
    enqueue(q, root, 0);

    int min_hd = 0, max_hd = 0;

    while (!isEmpty(q)) {
        struct QNode temp = dequeue(q);
        struct Node* node = temp.node;
        int hd = temp.hd;

        int index = hd + offset;

        result[index][count[index]++] = node->data;

        if (hd < min_hd) min_hd = hd;
        if (hd > max_hd) max_hd = hd;

        if (node->left)
            enqueue(q, node->left, hd - 1);
        if (node->right)
            enqueue(q, node->right, hd + 1);
    }

    // Print result
    for (int i = min_hd; i <= max_hd; i++) {
        int index = i + offset;
        for (int j = 0; j < count[index]; j++) {
            printf("%d ", result[index][j]);
        }
        printf("\n");
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
    verticalOrder(root, n);

    return 0;
}