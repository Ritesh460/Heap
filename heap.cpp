#include "heap.h"
#include <iostream>
using namespace std;
//initial
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


// Remove the root (aka: largest value)
void Heap::removeMax() {
  if (size == 0) {
    cout << "Heap is empty";
    return;
  }
  cout << heap[1] << " ";
  heap[1] = heap[size--];
  heapifyDown(1);
}
// Remove all values
void Heap::removeAll() {
  while (size > 0) {
    removeMax();
  } 
  cout << endl;
}
// Sideways tree display
void Heap::printTree(int index, int depth) {

   if (index > size) {
      return;
   }

   printTree(index * 2 + 1, depth + 1);
   for (int i = 0; i < depth; i++)
     cout << "\t";
   cout << heap[index] << endl;

   printTree(index * 2, depth + 1);
}

void Heap::displayTree() {
  if (size == 0) {
    cout << "Heap is empty.\n";
    return;
  }
  printTree(1, 0);
}


