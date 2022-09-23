//
// Created by macbookpro on 24/11/2021.
//

#include "CircuitElement.h"

CircuitElement::CircuitElement(std::string type, int nodeA, int nodeB, double data) {
    setType(type);
    addNode(nodeA);
    addNode(nodeB);
    setData(data);
}

void CircuitElement::setType(std::string s) {
    CircuitElement::type = s;
}

void CircuitElement::addNode(int node) {
    nodes.push_back(node);
}

void CircuitElement::setData(double data) {
    this->data = data;
}

std::string CircuitElement::getType() {
    return type;
}

double CircuitElement::getData() {
    return data;
}

std::vector<int> CircuitElement::getNodes() {
    return nodes;
}
