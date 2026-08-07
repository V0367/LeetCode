// Last updated: 07/08/2026, 15:39:56
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int* queue; // Array to store the queue elements
    int front;  // Front pointer of the queue
    int rear;   // Rear pointer of the queue
    int size;   // Current size of the queue
    int capacity; // Maximum capacity of the queue
} MyCircularQueue;

// Initialize the circular queue with the given size
MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue* obj = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
    obj->queue = (int*)malloc(sizeof(int) * k);
    obj->front = -1;
    obj->rear = -1;
    obj->size = 0;
    obj->capacity = k;
    return obj;
}

// Insert an element into the circular queue
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if (obj->size == obj->capacity) {
        return false; // Queue is full
    }

    if (obj->front == -1) {
        obj->front = 0; // If the queue is empty, set front to 0
    }

    obj->rear = (obj->rear + 1) % obj->capacity; // Circular increment of rear
    obj->queue[obj->rear] = value;
    obj->size++;
    return true;
}

// Remove an element from the circular queue
bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if (obj->size == 0) {
        return false; // Queue is empty
    }

    obj->front = (obj->front + 1) % obj->capacity; // Circular increment of front
    obj->size--;
    return true;
}

// Get the front item from the queue
int myCircularQueueFront(MyCircularQueue* obj) {
    if (obj->size == 0) {
        return -1; // Queue is empty
    }
    return obj->queue[obj->front];
}

// Get the last item from the queue
int myCircularQueueRear(MyCircularQueue* obj) {
    if (obj->size == 0) {
        return -1; // Queue is empty
    }
    return obj->queue[obj->rear];
}

// Check if the queue is empty
bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    return obj->size == 0;
}

// Check if the queue is full
bool myCircularQueueIsFull(MyCircularQueue* obj) {
    return obj->size == obj->capacity;
}

// Free the memory used by the queue
void myCircularQueueFree(MyCircularQueue* obj) {
    free(obj->queue);
    free(obj);
}
