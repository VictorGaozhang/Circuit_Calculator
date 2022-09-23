//
// Created by macbookpro on 24/11/2021.
//

#ifndef ELECTRONICCIRCUIT_CIRCUITELEMENT_H
#define ELECTRONICCIRCUIT_CIRCUITELEMENT_H

#include <string>
#include <vector>
#include "Node.h"

class CircuitElement {
public:
    CircuitElement(){};
    CircuitElement(std::string type, int nodeA, int nodeB, double data);

    void setData(double data);//setter
    void setType(std::string s);
    void addNode(int node);

    std::string getType();//getter
    double getData();
    std::vector<int> getNodes();

private:
    double data;//the value of register/source
    std::string type;//source or register
    std::vector<int> nodes;//the nodes connect to it
};


#endif //ELECTRONICCIRCUIT_CIRCUITELEMENT_H
