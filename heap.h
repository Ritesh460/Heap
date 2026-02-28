#ifndef HEAP_H
#define HEAP_H
//heap class
class Heap {
private: //private var
    static const int MAX_SIZE = 100;
    int heap[MAX_SIZE + 1];  
    int size;
    void heapifyUp(int index);
    void heapifyDown(int index);
    void printTree(int index, int depth);

public: //public var
    Heap();
    void insert(int value);
    void removeMax();
    void removeAll();
    void displayTree();
};

#endif
