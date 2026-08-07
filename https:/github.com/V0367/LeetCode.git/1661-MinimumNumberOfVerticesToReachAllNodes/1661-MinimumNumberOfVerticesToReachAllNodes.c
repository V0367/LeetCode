// Last updated: 07/08/2026, 15:39:21
#include <stdlib.h>

int* findSmallestSetOfVertices(int n, int** edges, int edgesSize, int* edgesColSize, int* returnSize) {
    // Initialize indegree array
    int* indegree = (int*)calloc(n, sizeof(int));
    
    // Calculate the indegree of each node
    for (int i = 0; i < edgesSize; i++) {
        int to = edges[i][1];
        indegree[to]++;
    }
    
    // Collect nodes with indegree 0
    int* result = (int*)malloc(n * sizeof(int));
    *returnSize = 0;
    
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            result[*returnSize] = i;
            (*returnSize)++;
        }
    }
    
    // Free the indegree array
    free(indegree);
    
    return result;
}
