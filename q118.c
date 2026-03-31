/*Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree and postorder is the postorder traversal of the same tree, construct and return the binary tree.

 

Example 1:


Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
Output: [3,9,20,null,null,15,7]
Example 2:

Input: inorder = [-1], postorder = [-1]
Output: [-1]
 

Constraints:

1 <= inorder.length <= 3000
postorder.length == inorder.length
-3000 <= inorder[i], postorder[i] <= 3000
inorder and postorder consist of unique values.
Each value of postorder also appears in inorder.
inorder is guaranteed to be the inorder traversal of the tree.
postorder is guaranteed to be the postorder traversal of the tree.*/

#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int search(int inorder[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == value)
            return i;
    }
    return -1;
}

struct TreeNode* build(int inorder[], int postorder[], int start, int end, int* index) {
    if (start > end)
        return NULL;

    int val = postorder[*index];
    (*index)--;

    struct TreeNode* root = newNode(val);

    if (start == end)
        return root;

    int pos = search(inorder, start, end, val);

    root->right = build(inorder, postorder, pos + 1, end, index);
    root->left = build(inorder, postorder, start, pos - 1, index);

    return root;
}

struct TreeNode* buildTree(int inorder[], int postorder[], int n) {
    int index = n - 1;
    return build(inorder, postorder, 0, n - 1, &index);
}