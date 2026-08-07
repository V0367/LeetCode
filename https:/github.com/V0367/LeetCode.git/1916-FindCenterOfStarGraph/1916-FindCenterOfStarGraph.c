// Last updated: 07/08/2026, 15:39:27
int findCenter(int** edges, int edgesSize, int* edgesColSize) {
    // The center of the star graph is the node that appears in both of the first two edges.
    if (edges[0][0] == edges[1][0] || edges[0][0] == edges[1][1]) {
        return edges[0][0];
    } else {
        return edges[0][1];
    }
}
