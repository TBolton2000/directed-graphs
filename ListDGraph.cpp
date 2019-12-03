#include"ListDGraph.h"
#include"ListNode.h"

using namespace List;

DGraph::DGraph():num_of_vertices(0),vertices(std::vector<Node*>()) {}

DGraph::~DGraph() {
    for(int i = 0; i < vertices.size(); i++) {
        delete vertices.at(i);
    }
}

void DGraph::addVertex(int val) {
    Node* newNode = new Node(val);
    vertices.push_back(newNode);
}

void DGraph::removeVertex(Node* toRemove) {
    delete toRemove;
}

void DGraph::addEdge(Node* src, Node* dest) {
    src->addEdge(dest);
}

void DGraph::removeEdge(Node* src, Node* dest) {
    src->removeEdge(dest);
}

bool DGraph::isEdge(Node* src, Node* dest) {
    if(src->getNodeWith(dest) == nullptr)
        return false;
    return true;
}

std::vector<Node*> DGraph::getVertices() {
    return vertices;
}

std::vector<Node*> DGraph::getNeighbors(Node* node) {
    return node->getNeighbors();
}

std::vector<List::Node*>::iterator DGraph::getVertexIterator(int index) {
    return vertices.begin()+index;
}

std::vector<List::Node*>::iterator DGraph::begin() {
    return vertices.begin();
}

std::vector<List::Node*>::iterator DGraph::end() {
    return vertices.end();
}

//Generates different graphs depending on choice and size
DGraph::DGraph(int choice, int size): num_of_vertices(0),vertices(std::vector<Node*>()) {
    if(choice == 1) { //Generate Cycle graph
        for(int i = 0; i < size; i++) {
            this->addVertex(i);
        }
        for(int i = 0; i < size; i++) {
            this->addEdge(*getVertexIterator(i),*getVertexIterator((i+1)%size));
        }
    }
    else if(choice == 2) {

    }
    else {
        throw "Bad Choice Buddy";
    }
}