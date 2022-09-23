//
// Created by macbookpro on 24/11/2021.
//

#ifndef ELECTRONICCIRCUIT_CIRCUIT_H
#define ELECTRONICCIRCUIT_CIRCUIT_H

#include "CircuitElement.h"
#include "Node.h"
#include <vector>
#include <map>

class Circuit {
public:
    Circuit(int number_of_Nodes);//创建nodeMap和lineMap
    void add_Element(std::string line, std::string type, double value);//在lineMap中添加元素

    std::map<std::string, std::vector<CircuitElement*>*> getLineMap();

    void calculateCoefficients();

    int min(int a, int b){return a<b?a:b;}
    int max(int a, int b){return a>b?a:b;}

    double **getCoefficientMatrix() const;

private:
    int number;//number of nodes
    std::map<int, Node*> nodeMap;//Create nodes, each node has a number, the node with key 0 is the base node
    std::map<std::string, std::vector<CircuitElement*>*> lineMap; //Create elements for each line,
                                                  // the number of lines is determined by the number of nodes
    double **coefficientMatrix;
};



#endif //ELECTRONICCIRCUIT_CIRCUIT_H
