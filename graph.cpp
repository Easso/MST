#include "graph.h"
#include "illegal_exception.h"

graph::graph() {
    vertexCount = 0;
}
graph::~graph() {
    for (int i{0}; i<23134; ++i) {
        if (adjacencyList[i].size() > 0) {
            adjacencyList[i].clear();
        }
    }
}
void graph::printSize() {
    std::cout << "number of vertices is " << vertexCount << std::endl;
}
void graph::insert(int a, int b, double weight, bool print) {
    if ( a > 23133 || a < 1 || b > 23133 || b < 1 || weight < 0 || weight > 1) {
        illegal_exception A;
        throw A;
    }

    node * newA = nullptr;
    node * newB = nullptr;

    //check if both nodes exist yet

    if (adjacencyList[a].size() == 0) { //origin
        newA = new node(a);
        edge * newEdge = new edge(newA, newA, -1);
        adjacencyList[a].push_back(newEdge);
        ++vertexCount;
    } else {
        newA = adjacencyList[a][0]->get_origin();
    }
    if (adjacencyList[b].size() == 0) { //origin
        newB = new node(b);
        edge * newEdge = new edge(newB, newB, -1); //creating an edge pointing to itself to represent it's node existing
        adjacencyList[b].push_back(newEdge);
        ++vertexCount;
    } else {
        newB = adjacencyList[b][0]->get_origin();
    }

    bool alrExists = false;

    //check if edge already exists

    for (int i{0}; i<adjacencyList[a].size(); ++i) {
        if (adjacencyList[b][0]->get_origin() == adjacencyList[a][i]->get_destination()) {
            alrExists = true;
            if (print) {
                std::cout << "failure" << std::endl;
            }
            break;
        }
    }
    
    if (!alrExists) {
        edge * newEdge = new edge(newA, newB, weight);
        adjacencyList[a].push_back(newEdge);
        adjacencyList[b][0]->get_origin()->addToDests(newA);
        if (print) {
            std::cout << "success" << std::endl;
        }
    }

}
/*
bool graph::searchNode(int RNtoSearch) {

}
*/
void graph::deleteNode(int RntoDelete) {
    if ( RntoDelete > 23133 || RntoDelete < 1) {
        illegal_exception A;
        throw A;
    }
    if (adjacencyList[RntoDelete].size() == 0) { //check if node exists
        std::cout << "failure" << std::endl;
    } else {
        for (int i{0}; i<adjacencyList[RntoDelete][0]->get_origin()->getDestListSize(); ++i) { //accessing edges where it's included as a destination
            int index = adjacencyList[RntoDelete][0]->get_origin()->getDest(i)->getRn();
            for (int j{0}; j<adjacencyList[index].size(); ++j) {
                if (adjacencyList[index][j]->get_destination()->getRn() == RntoDelete) {
                    adjacencyList[index].erase(adjacencyList[index].begin()+j, adjacencyList[index].begin()+j+1);
                }
            }
        }
        
        int amountToDecrement = adjacencyList[RntoDelete].size();
        //vertexCount = vertexCount-amountToDecrement;
        --vertexCount;
        adjacencyList[RntoDelete].clear();

        std::cout << "success" << std::endl;

    }
}


void graph::mst() {
    int startNode = 1;
    bool trackingTable [23134];
    int highestMst = 0;
    for (int i{0}; i<23134; ++i) {
        trackingTable[i] = false;
    }
    for (int startNode{1}; startNode<23134; ++startNode) {
        if (!trackingTable[startNode]) {
            //std::cout << "----" << startNode << "----" << std::endl;
            std::vector <node*> discovered;
            heap * newheap = new heap();
            graph * mstGraph = new graph();
            bool single = true;
            //go through first node and grab all adjacent edges

            for (int i{1}; i<this->adjacencyList[startNode].size(); ++i) {
                newheap->addNewEdge(this->adjacencyList[startNode][i]);
                single = false;
                if (!trackingTable[this->adjacencyList[startNode][i]->get_destination()->getRn()]) {
                    trackingTable[this->adjacencyList[startNode][i]->get_destination()->getRn()] = true;
                }
                
            }
                //std::cout << "test 1" << std::endl;

            adjacencyList[startNode][0]->get_origin()->changeDiscoveryStatus();
            //std::cout << "changed discovery status of " << this->adjacencyList[startNode][0]->get_origin()->getRn() << std::endl;
            discovered.push_back(this->adjacencyList[startNode][0]->get_origin());
                //std::cout << "test 2" << std::endl;

            while (newheap->returnSize() > 0) { //this function returns a number that accounts for the 0th index being occupied by 0 -- 0 is right
                if (!(newheap->returnMax()->get_destination()->getDiscoveryStatus())) {
                    edge * max = newheap->extractMax();
                    if (mstGraph->adjacencyList[max->get_destination()->getRn()].size() == 0) {
                        mstGraph->insert(max->get_origin()->getRn(), max->get_destination()->getRn(), max->get_weight(), false);
                        //std::cout << "added " << max->get_origin()->getRn() << " ---" << max->get_weight() << "--> " << max->get_destination()->getRn() << std::endl;
                    }
                        //std::cout << "test 3" << std::endl;
                    if (max->get_origin()->getDiscoveryStatus() != true) {
                        max->get_origin()->changeDiscoveryStatus();
                        //std::cout << max->get_origin()->getRn() << " is now changed to " << max->get_origin()->getDiscoveryStatus() << std::endl;
                        discovered.push_back(max->get_origin());
                    }
                    //std::cout << "test 4" << std::endl;
                    for (int i{1}; i<this->adjacencyList[max->get_destination()->getRn()].size(); ++i) {
                        newheap->addNewEdge(this->adjacencyList[max->get_destination()->getRn()][i]);
                        //std::cout << "test 4.25" << std::endl;
                        if (!trackingTable[max->get_destination()->getRn()]) {
                            trackingTable[max->get_destination()->getRn()] = true;
                        }
                        //std::cout << "test 4.75" << std::endl;
                    }
                        //std::cout << "test 5" << std::endl;
                } else {
                    newheap->extractMax();
                }
            }
            //std::cout << "comparing " << mstGraph->returnSize() << " to " << highestMst << std::endl;
            if (mstGraph->returnSize() > highestMst) {
                highestMst = mstGraph->returnSize();
            }
            
            for (int i{0}; i<discovered.size(); ++i) {
                if (discovered[i]) {
                    discovered[i]->changeDiscoveryStatus();
                    //std::cout << discovered[i]->getRn() << std::endl;
                }
            }
            discovered.clear();

            delete mstGraph;
            delete newheap;
        }
    }
    std::cout << highestMst << std::endl;
}

void graph::printAdjs(int RN) {
    if ( RN > 23133 || RN < 1) {
        illegal_exception A;
        throw A;
    }
    if (adjacencyList[RN].size() >= 0) {
        for (int i{1}; i<adjacencyList[RN].size(); ++i) {
            std::cout << adjacencyList[RN][i]->get_destination()->getRn();
            if (i != adjacencyList[RN].size()-1 ) {
                std::cout << " ";
            }
        }
    }
}

int graph::returnSize() {
    return vertexCount;
}