// Last updated: 07/08/2026, 15:39:59
#include <stdbool.h>
#include <stdlib.h>

typedef struct {
    int* arr;
    int front, rear, size, capacity;
} MyCircularDeque;

// Initialize the deque with a maximum size of k
MyCircularDeque* myCircularDequeCreate(int k) {
    MyCircularDeque* obj = (MyCircularDeque*)malloc(sizeof(MyCircularDeque));
    obj->arr = (int*)malloc(sizeof(int) * k);
    obj->capacity = k;
    obj->front = 0;
    obj->rear = 0;
    obj->size = 0;
    return obj;
}

// Insert an item at the front of the deque
bool myCircularDequeInsertFront(MyCircularDeque* obj, int value) {
    if (obj->size == obj->capacity) return false;
    obj->front = (obj->front - 1 + obj->capacity) % obj->capacity;
    obj->arr[obj->front] = value;
    obj->size++;
    return true;
}

// Insert an item at the rear of the deque
bool myCircularDequeInsertLast(MyCircularDeque* obj, int value) {
    if (obj->size == obj->capacity) return false;
    obj->arr[obj->rear] = value;
    obj->rear = (obj->rear + 1) % obj->capacity;
    obj->size++;
    return true;
}

// Delete an item from the front of the deque
bool myCircularDequeDeleteFront(MyCircularDeque* obj) {
    if (obj->size == 0) return false;
    obj->front = (obj->front + 1) % obj->capacity;
    obj->size--;
    return true;
}

// Delete an item from the rear of the deque
bool myCircularDequeDeleteLast(MyCircularDeque* obj) {
    if (obj->size == 0) return false;
    obj->rear = (obj->rear - 1 + obj->capacity) % obj->capacity;
    obj->size--;
    return true;
}

// Get the front item of the deque
int myCircularDequeGetFront(MyCircularDeque* obj) {
    if (obj->size == 0) return -1;
    return obj->arr[obj->front];
}

// Get the rear item of the deque
int myCircularDequeGetRear(MyCircularDeque* obj) {
    if (obj->size == 0) return -1;
    return obj->arr[(obj->rear - 1 + obj->capacity) % obj->capacity];
}

// Check if the deque is empty
bool myCircularDequeIsEmpty(MyCircularDeque* obj) {
    return obj->size == 0;
}

// Check if the deque is full
bool myCircularDequeIsFull(MyCircularDeque* obj) {
    return obj->size == obj->capacity;
}

// Free the memory of the deque
void myCircularDequeFree(MyCircularDeque* obj) {
    free(obj->arr);
    free(obj);
}
