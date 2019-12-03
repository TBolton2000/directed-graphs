#ifndef LISTNODE_H
#define LISTNODE_H
#include<vector>

namespace List {
    class Node {
    private:
        int val;
        std::vector<Node*> edges;
        std::vector<Node*> back_edges;
        bool visited;
    public:
        Node(int val);
        ~Node();
        int getValue();
        Node* getNext(); //The neighbor with the lowest value stored
        std::vector<Node*> getNeighbors();
        bool isVisited();
        void visit();
        void unvisit();
        void addEdge(Node*);
        void removeEdge(Node*);
        Node* getNodeWith(int val);
        Node* getNodeWith(Node* node);
    };
};

#endif