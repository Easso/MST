#include "heap.h"

heap::heap() {
    //edgeHeap.push_back(nullptr);
    sizeOfHeap = 0;
}
heap::~heap() {
    edgeHeap.clear();
}
int heap::parentEdgeIndex(int index) {
    return index/2;
}
int heap::rightEdgeIndex(int index) {
    return ((index*2)+1);
}
int heap::leftEdgeIndex(int index) {
    return (index*2);
}
edge * heap::returnMax() {
    return edgeHeap[1];
}
void heap::addNewEdge(edge * newEdge) {
    //std::cout << "adding " << newEdge->get_origin()->getRn() << "--" << newEdge->get_weight() << "-->" << newEdge->get_destination()->getRn() << std::endl;
    if (sizeOfHeap + 1 >= edgeHeap.size()) {
        edgeHeap.push_back(nullptr);
    }
    //++sizeOfHeap;
    edgeHeap[++sizeOfHeap] = newEdge;
    moveUp(sizeOfHeap);
    return;
}
void heap::moveUp(int index) {
    //std::cout << "index == " << index << std::endl;
    if (index > sizeOfHeap) {
        return;
    } 
    if (index == 1) {
        return;
    } 
    if ((edgeHeap[index])->get_weight() > edgeHeap[parentEdgeIndex(index)]->get_weight()) {
        mySwap(parentEdgeIndex(index), index);
    }
    //std::cout << "moving up to " << parentEdgeIndex(index) << std::endl;
    moveUp(parentEdgeIndex(index));
}
void heap::moveDown(int index) {
    if (index > sizeOfHeap) return;
    
    int savedIndex = index;

    if ((leftEdgeIndex(index) <= sizeOfHeap) && (edgeHeap[index]->get_weight() < edgeHeap[leftEdgeIndex(index)]->get_weight())) {
        savedIndex = leftEdgeIndex(index);
    } 
    if ((rightEdgeIndex(savedIndex) <= sizeOfHeap) && (edgeHeap[savedIndex]->get_weight() < edgeHeap[rightEdgeIndex(index)]->get_weight())) {
        savedIndex = rightEdgeIndex(index);
    }

    if (savedIndex != index) {
        mySwap(index, savedIndex);
        moveDown(savedIndex);
    }
    return;
}

edge * heap::extractMax() {
    edge * maxEdgeWeight = edgeHeap[1];
    mySwap(1, sizeOfHeap);
    --sizeOfHeap;
    edgeHeap.pop_back();
    moveDown(1);
    return maxEdgeWeight;
}

void heap::mySwap(int index1, int index2) {

    edge * temp = edgeHeap[index1];

    edgeHeap[index1] = edgeHeap[index2];
    edgeHeap[index2] = temp;
}

int heap::returnSize() {
    return sizeOfHeap;
}

edge * heap::returnHeapIndex(int index) {
    return edgeHeap[index];
}

/*
void heap::printHeap() {
    //std::cout << "---printed heap---" << std::endl;
    for (int i{0}; i<edgeHeap.size(); ++i) {
        //std::cout << "---------" << i << "---------" << std::endl;
        if (edgeHeap[i] != nullptr) {
            std::cout << edgeHeap[i]->get_weight() << std::endl;
        } else {
            std::cout << "nullptr at " << i << std::endl;
        }
        
    }
    //std::cout << "---------" << edgeHeap.size() << "---------" << std::endl;
}




int heap::actualHeapSize() {
    return edgeHeap.size();
}
*/