#include "node.h"

class edge {
    private:
        node * origin;
        node * destination;
        double weight;
    public:
        edge(node * newOrigin, node * newDestination, double newWeight);
        edge();
        ~edge();
        node * get_origin();
        node * get_destination();
        double get_weight();
};