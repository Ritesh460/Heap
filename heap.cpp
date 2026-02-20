#include "heap.h"
#include <iostream>
using namespace std;

Heap::Heap() {
    size = 0;
}

// Restore heap property upward
void Heap::heapifyUp(int index) {
    if (index <= 1) {
      return;
    } 

    int parent = index / 2;
    if (heap[index] > heap[parent]) {
        swap(heap[index], heap[parent]);
        heapifyUp(parent);
    }
}

// Restore heap property downward
void Heap::heapifyDown(int index) {
    int left = index * 2;
    int right = index * 2 + 1;
    int largest = index;

    if (left <= size && heap[left] > heap[largest])
        largest = left;

    if (right <= size && heap[right] > heap[largest])
        largest = right;

    if (largest != index) {
        swap(heap[index], heap[largest]);
        heapifyDown(largest);
    }
}

// Insert one number at a time
void Heap::insert(int value) {
    if (size >= MAX_SIZE) {
        cout << "Heap is full.\n";
        return;
    }

    heap[++size] = value;
    heapifyUp(size);
}

//stuff to do next class
/*
// Remove the root (aka: largest value)
void Heap::removeMax()
// Remove all values
void Heap::removeAll()
// Sideways tree display
// void printTree(int index, int depth)
// void displayTree();
*/
