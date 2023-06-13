#include "node.h"

node::node(int RN) {
    ResearcherNo = RN;
    discovered = false;
}
node::node() {
    ResearcherNo = 0;
    discovered = false;
}
node::~node() {
    includedAsDestination.clear();
}
int node::getRn() {
    return ResearcherNo;
}
void node::addToDests(node* toAdd) {
    includedAsDestination.push_back(toAdd);
}
void node::deleteFromDests(int RN) {
    int position = searchDests(RN);
    if (position == -1) {
        std::cout << "failed to delete" << std::endl;
    } else {
        includedAsDestination.erase(includedAsDestination.begin()+position, includedAsDestination.begin()+position+1);
    }
}
int node::searchDests(int RN) {
    for (int i{0}; i<includedAsDestination.size(); ++i) {
        if (includedAsDestination[i]->getRn() == RN) {
            return i;
        }
    }
    return -1;
}

void node::changeDiscoveryStatus() {
    discovered = !discovered;
}

int node::getDestListSize() {
    return includedAsDestination.size();
}

node * node::getDest(int index) {
    return includedAsDestination[index];
}

bool node::getDiscoveryStatus () {
    return discovered;
}