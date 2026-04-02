/*You are given the root of a binary tree. We install cameras on the tree nodes where each camera at a node can monitor its parent, itself, and its immediate children.

Return the minimum number of cameras needed to monitor all nodes of the tree.

 

Example 1:


Input: root = [0,0,null,0,0]
Output: 1
Explanation: One camera is enough to monitor all nodes if placed as shown.
Example 2:


Input: root = [0,0,null,0,null,0,null,null,0]
Output: 2
Explanation: At least two cameras are needed to monitor all nodes of the tree. The above image shows one of the valid configurations of camera placement.
 

Constraints:

The number of nodes in the tree is in the range [1, 1000].
Node.val == 0*/

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct node* createNode(int val) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int cameras = 0;

int dfs(struct node* root) {
    if (root == NULL)
        return 1;

    int left = dfs(root->left);
    int right = dfs(root->right);

    if (left == -1 || right == -1) {
        cameras++;
        return 0;
    }

    if (left == 0 || right == 0)
        return 1;

    return -1;
}

int minCameraCover(struct node* root) {
    if (dfs(root) == -1)
        cameras++;
    return cameras;
}

struct node* buildTree(int arr[], int i, int n) {
    if (i >= n || arr[i] == -1)
        return NULL;

    struct node* root = createNode(arr[i]);
    root->left = buildTree(arr, 2 * i + 1, n);
    root->right = buildTree(arr, 2 * i + 2, n);
    return root;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct node* root = buildTree(arr, 0, n);

    printf("%d", minCameraCover(root));

    return 0;
}