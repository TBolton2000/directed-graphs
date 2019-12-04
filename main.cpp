#include<iostream>
#include"ListNode.h"
#include"ListDGraph.h"

int main() {
    /* !!! TESTING THE LIST NODE !!! */
    // std::vector<List::Node*> myNodes;
    // for(int i = 0; i < 11; i++)
    //     myNodes.push_back(new List::Node(i));
    
    // myNodes.at(1)->addEdge(myNodes.at(2));
    // myNodes.at(1)->addEdge(myNodes.at(8));
    // myNodes.at(1)->addEdge(myNodes.at(6));
    // myNodes.at(1)->addEdge(myNodes.at(5));
    // myNodes.at(1)->addEdge(myNodes.at(3));
    // myNodes.at(1)->addEdge(myNodes.at(9));

    // std::vector<List::Node*> neighbors = myNodes.at(1)->getNeighbors();

    // for(auto it = neighbors.begin(); it != neighbors.end(); it++)
    //     std::cout << (*it)->getValue();
    
    /* !!! TESTING THE LIST DGRAPH !!! */
    // List::DGraph myGraph;
    // for(int i=0; i < 100; i++) {
    //     myGraph.addVertex(i);
    // }

    // for(std::vector<List::Node*>::iterator it = myGraph.getVertexIterator(1); it != myGraph.end(); it++) {
    //     myGraph.addEdge(*(myGraph.begin()), *it);
    //     std::cout << "Added edge bewteen " << (*myGraph.begin())->getValue() << " and " << (*it)->getValue() << std::endl;
    // }

    // std::cout << "Printing the neighbors of node 0, should be all nodes values 1-99" << std::endl;
    // std::vector<List::Node*> neighbors = myGraph.getNeighbors(*myGraph.begin());
    // for(auto it = neighbors.begin(); it != neighbors.end(); it++)
    //     std::cout << (*it)->getValue();

    /* !!! TESTING THE NEW CLIQUE AND CYCLE CONSTRUCTOR DGraph(int type,int size) where type 1 is cycle, type 2 is clique */
    /* type 3 is a random with edge probability 25%, type 4 is a random with edge probability 75% */
    List::DGraph myGraph(3,80);
    // std::vector<List::Node*> nodes = myGraph.getVertices();
    // for(auto it = nodes.begin(); it != nodes.end(); it++) {
    //     std::cout << "Current Node is: " << (*it)->getValue() << std::endl << "Its neighbors are: ";
    //     std::vector<List::Node*> neighbors = (*it)->getNeighbors();
    //     for(auto it2 = neighbors.begin(); it2 != neighbors.end(); it2++) {
    //         std::cout << (*it2)->getValue() << " ";
    //     }
    //     std::cout << "# of neigh: " << neighbors.size() << std::endl;
    // }

    myGraph.BFS_Wrapper();

    return 0;
}

