#include "Node.hpp"

#include <string>
#include <iostream>

using std::cout;
using std::endl;

#include "Edge.hpp"

using std::string;

Node::Node() {
    // TODO: default ID
    // TODO: default name
    //mEdges.push_back(Edge());
}

Node::Node(unsigned int ID) {
    mID = ID;
}

Node::Node(string name) {
    mName = name;
}

Node::Node(unsigned int ID, string name) {
    mID = ID;
    mName = name;
}

void Node::addEdge(Edge& edge) {
    mEdges.push_back(edge);
}

Edge& Node::getEdge(unsigned int index) {
    return mEdges[index];
}

void Node::setID(unsigned int ID) {
    mID = ID;
}

unsigned int Node::getID() {
    return mID;
}

void Node::setName(string name) {
    mName = name;
}

string& Node::getName() {
    return mName;
}

void Node::setVisited(bool visited) {
    mVisited = visited;
}

bool Node::getVisited() {
    return mVisited;
}

unsigned int Node::numEdges() {
    return mEdges.size();
}
