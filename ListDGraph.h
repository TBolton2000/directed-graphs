#ifndef LISTDGRAPH_H
#define LISTDGRAPH_H
#include<vector>
#include"ListNode.h"

namespace List {
    class DGraph {
    private:
        std::vector<Node*> vertices;
        int num_of_vertices;
    public: 
        DGraph();
        DGraph(int,int);
        ~DGraph();

        void addVertex(int val);
        void removeVertex(Node*);
        void addEdge(Node*, Node*);
        void removeEdge(Node*, Node*);
        bool isEdge(Node*, Node*);
        std::vector<Node*> getVertices();
        std::vector<Node*> getNeighbors(Node*);
        std::vector<List::Node*>::iterator getVertexIterator(int index);
        std::vector<List::Node*>::iterator begin();
        std::vector<List::Node*>::iterator end();
    };
};

#endif