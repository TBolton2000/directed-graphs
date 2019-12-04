#include"ListDGraph.h"
#include"ListNode.h"
#include<random>
#include<iostream>

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
        for(int i = 0; i < size; i++) {
            this->addVertex(i);
        }
        for(int i = 0; i < size; i++) {
            for (int j = 1; j < size; j++) {
                this->addEdge(*getVertexIterator(i),*getVertexIterator((i+j)%size));
            }
        }
    }
    else if(choice == 3) {
        for(int i = 0; i < size; i++) {
            this->addVertex(i);
        }
        for(int i = 0; i < size; i++) {
            for (int j = 1; j < size; j++) {
                if(rand()%4 == 0)
                    this->addEdge(*getVertexIterator(i),*getVertexIterator((i+j)%size));
            }
        }
    }
    else if(choice == 4) {
        for(int i = 0; i < size; i++) {
            this->addVertex(i);
        }
        for(int i = 0; i < size; i++) {
            for (int j = 1; j < size; j++) {
                if(rand()%4 != 0)
                    this->addEdge(*getVertexIterator(i),*getVertexIterator((i+j)%size));
            }
        }
    }
    else {
        throw "Bad Choice Buddy";
    }

    
}

void DGraph::DFS_Wrapper() {
    DFS(*getVertexIterator(0));
}

void DGraph::DFS(Node* current) {
    current->visit();
    for(int i = 0; i < current->getNeighbors().size(); i++) {
        if(!(current->getNeighbors().at(i)->isVisited())) {
            current->setTreePath(i);
            std::cout << "At: " << current->getValue() << " and Going To: " << current->getNeighbors().at(i)->getValue() << std::endl;
            DFS(current->getNeighbors().at(i));
        }
    }

}

void DGraph::BFS_Wrapper() {
    BFS(*getVertexIterator(0));
}

void DGraph::BFS(Node* start) {
    std::vector<std::vector<Node*>> levels;
    levels.push_back(std::vector<Node*>(1,start));
    start->visit();
    int i = 0;
    while(levels.at(i).size() != 0) {
        levels.push_back(std::vector<Node*>());
        for(int j = 0; j < levels.at(i).size(); j++) {
            std::vector<Node*> local_neighbors = levels.at(i).at(j)->getNeighbors();
            for(int k = 0; k < local_neighbors.size(); k++) {
                if(local_neighbors.at(k)->isVisited()) {
                    levels.at(i).at(j)->setCrossEdge(k);
                }
                else{
                    levels.at(i+1).push_back(local_neighbors.at(k));
                    levels.at(i).at(j)->setTreePath(k);
                    local_neighbors.at(k)->visit();
                }
            }
        }
        std::cout << "Level " << i+1 << ": " << std::endl;
        for(int j = 0; j < levels.at(i).size(); j++) {
            std::cout << levels.at(i).at(j)->getValue() << " ";
        }
        std::cout << std::endl;
        i++;
    }
}