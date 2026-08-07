// Last updated: 07/08/2026, 15:39:26
#include <limits.h>
#include <stdlib.h>

// Union-Find helper functions
int findParent(int* parent, int node) {
    if (parent[node] != node) {
        parent[node] = findParent(parent, parent[node]);
    }
    return parent[node];
}

void unionNodes(int* parent, int* rank, int u, int v) {
    int rootU = findParent(parent, u);
    int rootV = findParent(parent, v);
    if (rootU != rootV) {
        if (rank[rootU] > rank[rootV]) {
            parent[rootV] = rootU;
        } else if (rank[rootU] < rank[rootV]) {
            parent[rootU] = rootV;
        } else {
            parent[rootV] = rootU;
            rank[rootU]++;
        }
    }
}

int minScore(int n, int** roads, int roadsSize, int* roadsColSize) {
    // Initialize Union-Find structures
    int* parent = (int*)malloc((n + 1) * sizeof(int));
    int* rank = (int*)calloc((n + 1), sizeof(int));
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    // Build connected components using Union-Find
    for (int i = 0; i < roadsSize; i++) {
        int u = roads[i][0];
        int v = roads[i][1];
        unionNodes(parent, rank, u, v);
    }

    // Find the root of city 1's component
    int root1 = findParent(parent, 1);

    // Find the minimum score among roads in city 1's component
    int minScore = INT_MAX;
    for (int i = 0; i < roadsSize; i++) {
        int u = roads[i][0];
        int v = roads[i][1];
        int distance = roads[i][2];
        if (findParent(parent, u) == root1 || findParent(parent, v) == root1) {
            if (distance < minScore) {
                minScore = distance;
            }
        }
    }

    // Free allocated memory
    free(parent);
    free(rank);

    return minScore;
}
