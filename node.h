#include <iostream>
#include <vector>

class node {
    private:
        int ResearcherNo;
        std::vector<node*> includedAsDestination;
        bool discovered;
    public:
        node(int RN);
        node();
        ~node();
        int getRn();
        void addToDests(node* toAdd);
        void deleteFromDests(int RN);
        int searchDests(int RN);
        void changeDiscoveryStatus();
        int getDestListSize();
        node * getDest(int index);
        bool getDiscoveryStatus();
};