/*Given the root of a binary tree, flatten the tree into a "linked list":

The "linked list" should use the same TreeNode class where the right child pointer points to the next node in the list and the left child pointer is always null.
The "linked list" should be in the same order as a pre-order traversal of the binary tree.
 

Example 1:


Input: root = [1,2,5,3,4,null,6]
Output: [1,null,2,null,3,null,4,null,5,null,6]
Example 2:

Input: root = []
Output: []
Example 3:

Input: root = [0]
Output: [0]
 

Constraints:

The number of nodes in the tree is in the range [0, 2000].
-100 <= Node.val <= 100*/

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
    node->left = node->right = NULL;
    return node;
}


void flatten(struct TreeNode* root) {
    if (root == NULL)
        return;

    
    flatten(root->left);
    flatten(root->right);

    
    struct TreeNode* left = root->left;
    struct TreeNode* right = root->right;

    
    root->left = NULL;
    root->right = left;

    
    struct TreeNode* temp = root;
    while (temp->right != NULL) {
        temp = temp->right;
    }

    
    temp->right = right;
}


void printList(struct TreeNode* root) {
    while (root != NULL) {
        printf("%d ", root->val);
        root = root->right;
    }
}

int main() {
    

    struct TreeNode* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(5);
    root->left->left = newNode(3);
    root->left->right = newNode(4);
    root->right->right = newNode(6);

    flatten(root);

    printList(root);

    return 0;
}