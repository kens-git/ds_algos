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

// Iterative DFS
void DFS(const Graph& graph, unsigned int startID, unsigned int searchID);

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

    DFS(graph, 0, 19);

    return 0;
}

void DFS(const Graph &graph, unsigned int startID, unsigned int searchID) {
    DArray<Node> stack;
    bool found = false;

    graph.getNode(startID).setVisited(true);
    stack.push_back(graph.getNode(startID));

    while (stack.size() != 0 && found != true) {
        if (stack.back().numEdges() != 0) {
            // Loop through each edge of the current node
            for (int i = 0; i < stack.back().numEdges(); i++) {
                // If it hasn't been visited, push it onto the stack (unless it's the node we're looking for)
                if (stack.back().getEdge(i).getNode().getVisited() == false) {
                    if (stack.back().getEdge(i).getNode().getID() == searchID) {
                        for (int j = 0; j < stack.size(); j++) {
                            cout << stack[j].getID() << " -> ";
                        }
                        cout << searchID << endl;

                        found = true;
                        break;
                    }

                    stack.back().getEdge(i).getNode().setVisited(true);
                    // Putting the Depth in Depth First Search; the first neighboring node
                    // of the current node will be searched next
                    stack.push_back(stack.back().getEdge(i).getNode());
                    break;
                }
                // If the last edge of the node has been visited, then every edge has been visited, so pop it
                else if (stack.back().getEdge(stack.back().numEdges() - 1).getNode().getVisited() == true) {
                    stack.pop_back();
                    break;
                }
            }
        }
        else {
            stack.pop_back();
        }
    }
    if (!found) {
        cout << "Couldn't find node with ID " << searchID << endl;
    }
}
