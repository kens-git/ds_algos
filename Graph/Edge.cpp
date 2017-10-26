#include "Edge.hpp"
#include "Node.hpp"

Edge::Edge() {

}

Edge::~Edge() {
    mNode = nullptr;
}

Edge::Edge(Node& neighbor) {
    mNode = &neighbor;
    mWeight = 0;
}

Edge::Edge(double weight, Node &neighbor) {
    mWeight = weight;
    mNode = &neighbor;
}

void Edge::setNode(Node& node) {
    mNode = &node;
}

Node& Edge::getNode() {
    return *mNode;
}

void Edge::setWeight(double weight) {
    mWeight = weight;
}

double Edge::getWeight() {
    return mWeight;
}
