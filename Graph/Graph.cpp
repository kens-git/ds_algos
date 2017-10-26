#include "Graph.hpp"

#include <iostream>
#include <string>

#include "Node.hpp"
#include "Edge.hpp"

using std::cout;
using std::endl;
using std::string;

Graph::Graph(const Node &initialNode) {
    mNodes.push_back(initialNode);
}

Graph::~Graph() {
    // TODO: what does this destructor do?
}

void Graph::addNode(unsigned int neighborID, const Node& newNode) {
    // TODO: check for duplicates
    for (int i = 0; i < mNodes.size(); i++) {
        if (mNodes.at(i).getID() == neighborID) {
            mNodes.push_back(newNode);
            Edge temp(mNodes.at(mNodes.size() - 1));
            mNodes.at(i).addEdge(temp);
            return;
        }
    }
}

void Graph::removeNode(unsigned int ID) {
    //TODO: remove all edges directed to node
    for (int i = 0; i < mNodes.size(); i++) {
        if (mNodes.at(i).getID() == ID) {
            mNodes.remove(i);
        }
    }
}

Node& Graph::getNode(unsigned int ID) const {
    for (int i = 0; i < mNodes.size(); i++) {
        if (mNodes[i].getID() == ID) {
            return mNodes[i];
        }
    }
}

void Graph::addEdge(unsigned int fromID, unsigned int toID) {
    Edge tempEdge(getNode(toID));
    getNode(fromID).addEdge(tempEdge);
}

void Graph::addUndirectedEdge(unsigned int node1, unsigned int node2) {

}

//Node& Graph::getNode(const string& name) {
//    for (int i = 0; i < mNodes.size(); i++) {
//        if (mNodes[i].getName() == name) {
//            return mNodes[i];
//        }
//    }
//}

unsigned int Graph::numNodes() const {
    return mNodes.size();
}

void Graph::unvisitAll() {
    for (int i = 0; i < mNodes.size(); i++) {
        mNodes.at(i).setVisited(false);
    }
}
