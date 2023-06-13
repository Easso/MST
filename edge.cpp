#include "edge.h"

edge::edge(node * newOrigin, node * newDestination, double newWeight) {
    origin = newOrigin;
    destination = newDestination;
    weight = newWeight;
}
edge::edge() {
    origin = nullptr;
    destination =nullptr;
    weight = 0;
}
edge::~edge() {
    origin = nullptr;
    destination = nullptr;
    delete origin;
    delete destination;
    std::cout << "i ran" << std::endl;
}
node * edge::get_origin() {
    return origin;
}
node * edge::get_destination() {
    return destination;
}
double edge::get_weight() {
    return weight;
}