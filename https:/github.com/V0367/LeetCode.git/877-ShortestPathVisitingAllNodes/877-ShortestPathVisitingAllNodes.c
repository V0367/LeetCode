// Last updated: 07/08/2026, 15:39:54
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define INF 1e9

typedef struct {
    int node;
    int visited;
    int dist;
} State;

typedef struct {
    State* data;
    int front, rear, size, capacity;
} Queue;

Queue* createQueue(int capacity) {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->data = (State*)malloc(capacity * sizeof(State));
    q->front = q->rear = 0;
    q->size = 0;
    q->capacity = capacity;
    return q;
}

bool isEmpty(Queue* q) {
    return q->size == 0;
}

void enqueue(Queue* q, State s) {
    q->data[q->rear] = s;
    q->rear = (q->rear + 1) % q->capacity;
    q->size++;
}

State dequeue(Queue* q) {
    State s = q->data[q->front];
    q->front = (q->front + 1) % q->capacity;
    q->size--;
    return s;
}

void freeQueue(Queue* q) {
    free(q->data);
    free(q);
}

int shortestPathLength(int** graph, int graphSize, int* graphColSize) {
    int n = graphSize;
    if (n == 1) return 0;  // Special case: only one node
    
    int allVisited = (1 << n) - 1;  // Bitmask where all nodes are visited
    bool** visited = (bool**)malloc(n * sizeof(bool*));
    for (int i = 0; i < n; i++) {
        visited[i] = (bool*)calloc(1 << n, sizeof(bool));
    }
    
    Queue* q = createQueue(10000);
    
    // Initialize BFS with all nodes
    for (int i = 0; i < n; i++) {
        enqueue(q, (State){i, 1 << i, 0});
        visited[i][1 << i] = true;
    }
    
    while (!isEmpty(q)) {
        State curr = dequeue(q);
        int node = curr.node;
        int visitedNodes = curr.visited;
        int dist = curr.dist;
        
        // If all nodes are visited, return the distance
        if (visitedNodes == allVisited) {
            for (int i = 0; i < n; i++) free(visited[i]);
            free(visited);
            freeQueue(q);
            return dist;
        }
        
        // Explore neighbors
        for (int i = 0; i < graphColSize[node]; i++) {
            int nextNode = graph[node][i];
            int nextVisited = visitedNodes | (1 << nextNode);
            if (!visited[nextNode][nextVisited]) {
                visited[nextNode][nextVisited] = true;
                enqueue(q, (State){nextNode, nextVisited, dist + 1});
            }
        }
    }
    
    // Cleanup
    for (int i = 0; i < n; i++) free(visited[i]);
    free(visited);
    freeQueue(q);
    
    return -1;  // Should never reach here
}
