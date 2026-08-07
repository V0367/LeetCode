// Last updated: 07/08/2026, 15:39:36
int findTheCity(int n, int** edges, int edgesSize, int* edgesColSize, int distanceThreshold) {
    // Initialize a distance matrix with infinity for all pairs of cities
    int dist[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                dist[i][j] = 0;  // Distance from a city to itself is 0
            } else {
                dist[i][j] = 10000000;  // A large value (infinity)
            }
        }
    }

    // Populate the distance matrix with the given edges
    for (int i = 0; i < edgesSize; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int weight = edges[i][2];
        dist[u][v] = weight;
        dist[v][u] = weight;
    }

    // Apply the Floyd-Warshall algorithm to find the shortest path between all pairs of cities
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Now, for each city, count how many cities are reachable within the threshold distance
    int minReachable = n;  // Initialize with the maximum possible number of cities
    int city = -1;

    for (int i = 0; i < n; i++) {
        int reachableCount = 0;
        for (int j = 0; j < n; j++) {
            if (dist[i][j] <= distanceThreshold) {
                reachableCount++;
            }
        }
        // If the current city has fewer reachable cities or the same but a greater city number
        if (reachableCount <= minReachable) {
            minReachable = reachableCount;
            city = i;
        }
    }

    return city;
}
