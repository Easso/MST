#include <iostream>
#include <fstream>
#include "graph.h"
#include "illegal_exception.h"

int main() {

    std::string command = "";
    int a, b = 0;
    double w = 0;
    bool exited = false;
    graph *newGraph = new graph();
   
            std::fstream fin("paperCollabWeighted.txt");
           
                while (fin >> a >> b >> w) {
                    newGraph->insert(a, b , w, false);
                }
                fin.close();
                newGraph->mst();

                delete newGraph;
       
    return 0;
}