// Last updated: 07/08/2026, 15:40:23
#include <stdlib.h>

// Main function to perform level order traversal
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    if (root == NULL) {
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }

    // Initialize queue for BFS
    struct TreeNode** queue = (struct TreeNode**)malloc(2000 * sizeof(struct TreeNode*));  // Assume max 2000 nodes
    int front = 0, rear = 0;
    queue[rear++] = root;

    // Initialize result array
    int** result = (int**)malloc(2000 * sizeof(int*));  // Assume max 2000 levels
    *returnColumnSizes = (int*)malloc(2000 * sizeof(int));  // Store size of each level
    *returnSize = 0;

    while (front < rear) {
        int levelSize = rear - front;
        (*returnColumnSizes)[*returnSize] = levelSize;
        result[*returnSize] = (int*)malloc(levelSize * sizeof(int));

        for (int i = 0; i < levelSize; i++) {
            struct TreeNode* node = queue[front++];
            result[*returnSize][i] = node->val;

            if (node->left) {
                queue[rear++] = node->left;
            }
            if (node->right) {
                queue[rear++] = node->right;
            }
        }

        (*returnSize)++;
    }

    free(queue);
    return result;
}
