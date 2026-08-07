// Last updated: 07/08/2026, 15:39:44
#include <stdlib.h>

// Helper function to insert a node into the BST
struct TreeNode* insertIntoBST(struct TreeNode* root, int val) {
    if (root == NULL) {
        struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        newNode->val = val;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }
    
    if (val < root->val) {
        root->left = insertIntoBST(root->left, val);
    } else {
        root->right = insertIntoBST(root->right, val);
    }
    
    return root;
}

// Main function to construct the BST from preorder traversal
struct TreeNode* bstFromPreorder(int* preorder, int preorderSize) {
    if (preorderSize == 0) {
        return NULL;
    }

    struct TreeNode* root = NULL;
    for (int i = 0; i < preorderSize; i++) {
        root = insertIntoBST(root, preorder[i]);
    }
    
    return root;
}
