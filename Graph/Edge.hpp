#pragma once

class Node;

class Edge {
    public:
        Edge();
        Edge(Node& neighbor);
        Edge(double weight, Node& neighbor);
        ~Edge();

        void setNode(Node& node);
        Node& getNode();

        void setWeight(double weight);
        double getWeight();

    private:
        double mWeight;

        // the neighboring node
        Node* mNode;
};
