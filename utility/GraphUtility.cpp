#include "GraphUtility.hpp"

#include "Graph.hpp"
#include "Node.hpp"

#include <iostream>
using std::cout;
using std::endl;

namespace Utilities {
    void outputGraph(const Graph &graph) {
        // This makes the assumption that the IDs are sequential
        for (unsigned int i = 0; i < graph.numNodes(); i++) {
            Node node = graph.getNode(i);
            cout << node.getID() << " - " << node.getName() << endl;

            for (unsigned int j = 0; j < node.numEdges(); j++) {
                Edge tempEdge = node.getEdge(j);
                // TODO: fix the bug that happens when the size of the graph is >100
                Node tempNode = tempEdge.getNode();
                cout << "\t" << node.getEdge(j).getNode().getID()
                     << " " << node.getEdge(j).getNode().getName() << endl;
                cout << "\tWeight: " << node.getEdge(i).getWeight() << endl << endl;
            }
            if (node.numEdges() == 0) {
                cout << endl;
            }
        }
    }
}
