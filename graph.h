#include "heap.h"

class graph {
    private:
        std::vector<edge*> adjacencyList[23134]; //decided to go up one more slot to make accessing the lists easier -- so index 23133 exists
        int vertexCount;
    public:
        graph();
        ~graph();
        void printSize();
        void insert(int a, int b, double weight, bool print);
        int returnSize();
        void deleteNode(int RNtoDelete);
        void mst();
        void printAdjs(int RN);
        /*
            ------------for adding----------------

            check parameters to make sure...
                they are in range
                the edge doesn't already exist

            check to see if origin and destination already exists..
                if origin doesnt exist
                    increment size
                    create a new edge pointing to itself (explore edges that'll be easy to identify to prevent mst errors)
                if destination doesn't exist
                    increment size
                    create new edge pointing to itself (create bool maybe in node class)

                else
                    push a new edge into origin's list
                    add to destinations "includedAsDestination" list

            ------------for deleting-----------------

            check parameter to make sure...
                it's in range
                if node exists

            if exists
                access the edges where its included in its "includedAsDestination" list
                    -> delete those edges
                ...then access its list in the adjaceny matrix and delete those edges
                finally delete self


            ------------for printing----------------------
            make sure node exists
                ->create a function to do so
            iterate through passed nodes list in the adjaceny list and print Researcher# in order it was inserted

            --------------mst-----------------------------

            use prims algorithm
            apply the heap class made already

            try and survive :(
        */
        
};