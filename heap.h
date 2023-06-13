#include <iostream>
#include <vector>
#include "edge.h"

class heap { //this heap design was adapted from "Coding Jesus's Max Heap Implementation C++ video on youtube"

    private:
        std::vector <edge*> edgeHeap = {nullptr};
        unsigned int sizeOfHeap;
    public:
        heap();
        ~heap();
        int parentEdgeIndex(int index);
        int rightEdgeIndex(int index);
        int leftEdgeIndex(int index); 
        edge * returnMax();
        void addNewEdge(edge * newEdge);
        void moveUp(int index);
        void moveDown(int index);
        edge * extractMax();
        void mySwap(int index1, int index2);
        int returnSize();
        edge * returnHeapIndex(int index);
        //int actualHeapSize();
        //void printHeap(); 

};
