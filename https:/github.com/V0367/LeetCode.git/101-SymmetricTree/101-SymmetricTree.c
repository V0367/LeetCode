// Last updated: 07/08/2026, 15:40:24
#include <stdbool.h>

// Helper function to check if two trees are mirror images of each other
bool isMirror(struct TreeNode* t1, struct TreeNode* t2) {
    // If both are NULL, they are symmetric
    if (t1 == NULL && t2 == NULL) {
        return true;
    }
    // If one is NULL and the other is not, they are not symmetric
    if (t1 == NULL || t2 == NULL) {
        return false;
    }
    // Check if the values are the same and recursively check the subtrees
    return (t1->val == t2->val) && isMirror(t1->left, t2->right) && isMirror(t1->right, t2->left);
}

// Main function to check if the tree is symmetric
bool isSymmetric(struct TreeNode* root) {
    if (root == NULL) {
        return true; // An empty tree is symmetric
    }
    return isMirror(root->left, root->right);
}
