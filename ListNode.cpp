#include"ListNode.h"

using namespace List;

Node::Node(int val): val(val), edges(std::vector<Node*>()), back_edges(std::vector<Node*>()), visited(false) {}

Node::~Node() {
    for(int i = 0; i < back_edges.size(); i++) {
        back_edges.at(i)->removeEdge(this);
    }
}

int Node::getValue() {
    return val;
}

Node* Node::getNext() {
    return edges.at(0);
}

std::vector<Node*> Node::getNeighbors() {
    return edges;
}

bool Node::isVisited() {
    return visited;
}

void Node::visit() {
    visited = true;
}

void Node::unvisit() {
    visited = false;
}

void Node::addEdge(Node* toAdd) {
    int i;
    for(i = 0; i < edges.size(); i++) {
        if(edges.at(i)->val > toAdd->val) {
            break;
        }
    }
    edges.insert(edges.begin()+i, toAdd);
    toAdd->back_edges.push_back(this);
}

void Node::removeEdge(Node* toRemove) {
    for(auto it = toRemove->back_edges.begin(); it != toRemove->back_edges.end(); it++) {
        if(this == *it) {
            toRemove->back_edges.erase(it);
            break;
        }
    }
    for(auto it = edges.begin(); it != edges.end(); it++) {
        if(toRemove == *it) {
            edges.erase(it);
            break;
        }
    }
}

Node* Node::getNodeWith(int val) {
    for(auto it = edges.begin(); it != edges.end(); it++) {
        if((*it)->getValue() == val)
            return *it;
    }
    return nullptr;
}

Node* Node::getNodeWith(Node* node) {
    for(auto it = edges.begin(); it != edges.end(); it++) {
        if((*it) == node)
            return *it;
    }
    return nullptr;
}