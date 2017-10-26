#include "DArray.hpp"
#include "Graph.hpp"
#include "Node.hpp"
#include "GraphUtility.hpp"

#include <iostream>
using std::cout;
using std::endl;

#include <random>
using std::random_device;
using std::mt19937;
using std::uniform_int_distribution;

using Utilities::outputGraph;

// Iterative BFS
void BFS(const Graph& graph, unsigned int startID, unsigned int searchID);

int main() {
    random_device rndDev;
    mt19937 rndEng(rndDev());

    Graph graph(Node(0));
    for (int i = 1; i < 20; i++) {
        // This method of generating nodes and edges tends to cluster the edges around the first
        // few nodes, which works better for example problems
        uniform_int_distribution<unsigned int> dist(0, i - 1);
        graph.addNode(dist(rndEng), Node(i));
    }

    outputGraph(graph);

    BFS(graph, 0, 19);

    return 0;
}

void BFS(const Graph &graph, unsigned int startID, unsigned int searchID) {
    DArray<Node> queue;
    bool found = false;

    // Obviously using an actual Queue implementation would be much faster than using
    // a dynamic array, but for this simple example it will suffice
    queue.push_back(graph.getNode(startID));
    queue[0].setVisited(true);

    // Because BFS doesn't use a stack like DFS, we can't just output the results
    // of the search as elements in the stack, so we're printing out each visited
    // elements as it's visited, and it will stop printing when it's found the
    // element it's looking for
    cout << endl << endl << "Running BFS for node with ID " << searchID << endl;
    while (queue.size() != 0 && found != true) {
        cout << queue[0].getID() << endl;
        for (int i = 0; i < queue[0].numEdges(); i++) {
            cout << "   " << queue[0].getEdge(i).getNode().getID() << endl;

            if (queue[0].getEdge(i).getNode().getID() == searchID) {
                found = true;
                break;
            }

            queue.push_back(queue[0].getEdge(i).getNode());
        }
        queue.remove(0);
    }
    if (!found) {
        cout << "Couldn't find node with ID " << searchID << endl;
    }
}
