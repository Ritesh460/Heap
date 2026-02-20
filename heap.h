#ifndef HEAP_H
#define HEAP_H

class Heap {
private:
    static const int MAX_SIZE = 100;
    int heap[MAX_SIZE + 1];  
    int size;
    void heapifyUp(int index);
    void heapifyDown(int index);
    void printTree(int index, int depth);

public:
    Heap();
    void insert(int value);
    void removeMax();
    void removeAll();
    void displayTree();
};

#endif
