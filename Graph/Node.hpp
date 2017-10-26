#pragma once

#include <string>

#include "DArray.hpp"
#include "Edge.hpp"

using std::string;

class Node {
    public:
        Node();
        Node(unsigned int ID);
        Node(string name);
        Node(unsigned int ID, string name);


        //TODO: replace default assignment operator and copy constructor
        // to see if that fixes the default capacity issue

        void setID(unsigned int ID);
        unsigned int getID();
        void setName(string name);
        string& getName();

        void setVisited(bool visited);
        bool getVisited();

        void addEdge(Edge& edge);
        Edge& getEdge(unsigned int index);

        unsigned int numEdges();

    private:
        unsigned int mID;
        string mName;
        bool mVisited = false;

        DArray<Edge> mEdges;
};
