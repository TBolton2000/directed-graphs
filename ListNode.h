#ifndef LISTNODE_H
#define LISTNODE_H
#include<vector>
#include<string>

namespace List {
    class Node {
    private:
        int val;
        std::vector<Node*> edges;
        std::vector<Node*> back_edges;
        bool visited;
        std::vector<std::string> edgeType;
    public:
        Node(int val);
        ~Node();
        int getValue();
        Node* getNext(); //The neighbor with the lowest value stored
        std::vector<Node*> getNeighbors();
        bool isVisited();
        void visit();
        void unvisit();
        void setTreePath(int);
        void setCrossEdge(int);
        void addEdge(Node*);
        void removeEdge(Node*);
        Node* getNodeWith(int val);
        Node* getNodeWith(Node* node);
    };
};

#endif