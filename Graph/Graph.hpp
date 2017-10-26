#pragma once

#include "DArray.hpp"

class Node;
class string;

class Graph {
    public:
        Graph() = delete;
        Graph(const Node& initialNode);
        virtual ~Graph();

        void addNode(unsigned int neighborID, const Node& newNode);
        void removeNode(unsigned int ID);
        void removeNode(const string& name);

        Node& getNode(unsigned int ID) const;
        //Node& getNode(const string& name) const;

        void addEdge(unsigned int from, unsigned int to);
        void addUndirectedEdge(unsigned int node1, unsigned int node2);

        unsigned int numNodes() const;

        // utility to set all node's status to unvisited, for use with searching
        void unvisitAll();
  
    private:
        DArray<Node> mNodes;
};
