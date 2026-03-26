/**/
/*Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: [[3],[20,9],[15,7]]
Example 2:

Input: root = [1]
Output: [[1]]
Example 3:

Input: root = []
Output: []
 

Constraints:

The number of nodes in the tree is in the range [0, 2000].
-100 <= Node.val <= 100*/

#include <stdio.h>
#include <stdlib.h>

// Tree Node
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Queue
struct Queue {
    struct TreeNode* arr[2000];
    int front, rear;
};

void initQueue(struct Queue* q) {
    q->front = q->rear = 0;
}

void enqueue(struct Queue* q, struct TreeNode* node) {
    q->arr[q->rear++] = node;
}

struct TreeNode* dequeue(struct Queue* q) {
    return q->arr[q->front++];
}

int isEmpty(struct Queue* q) {
    return q->front == q->rear;
}

int size(struct Queue* q) {
    return q->rear - q->front;
}

// Zigzag Traversal (returns 2D array)
int** zigzagLevelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    
    if (!root) {
        *returnSize = 0;
        return NULL;
    }

    int** result = (int**)malloc(2000 * sizeof(int*));
    *returnColumnSizes = (int*)malloc(2000 * sizeof(int));

    struct Queue q;
    initQueue(&q);
    enqueue(&q, root);

    int leftToRight = 1;
    int levelIndex = 0;

    while (!isEmpty(&q)) {
        int levelSize = size(&q);

        int* level = (int*)malloc(levelSize * sizeof(int));

        for (int i = 0; i < levelSize; i++) {
            struct TreeNode* curr = dequeue(&q);

            int index = leftToRight ? i : (levelSize - 1 - i);
            level[index] = curr->val;

            if (curr->left) enqueue(&q, curr->left);
            if (curr->right) enqueue(&q, curr->right);
        }

        result[levelIndex] = level;
        (*returnColumnSizes)[levelIndex] = levelSize;

        levelIndex++;
        leftToRight = !leftToRight;
    }

    *returnSize = levelIndex;
    return result;
}