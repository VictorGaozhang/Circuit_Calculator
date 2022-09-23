//
// Created by macbookpro on 24/11/2021.
//

#include "Circuit.h"
#include <stdlib.h>

Circuit::Circuit(int number_of_nodes) {
    for (int i = 0; i < number_of_nodes; i++)
        nodeMap[i] = new Node();
    for (int i = 0; i < number_of_nodes - 1; i++) {
        for (int j = i + 1; j < number_of_nodes; j++) {
            std::string line = std::to_string(i) + '_' + std::to_string(j);//创建lineMap的关键词
            lineMap[line] = new std::vector<CircuitElement *>();
        }
    }
    coefficientMatrix = new double *[number_of_nodes];
    for (int i = 0; i < number_of_nodes - 1; i++)
        coefficientMatrix[i] = new double[number_of_nodes]();
    number = number_of_nodes;
}

void Circuit::add_Element(std::string line, std::string type, double value) {
    int mid = line.find('_');
    int node1 = atoi(line.substr(0, mid).c_str());
    int node2 = atoi(line.substr(mid + 1).c_str());
    lineMap[line]->push_back(new CircuitElement(type, node1, node2, value));
}

std::map<std::string, std::vector<CircuitElement *> *> Circuit::getLineMap() {
    return lineMap;
};

void Circuit::calculateCoefficients() {
    for (int i = 1; i < number; i++) {
        double *tmp_coefficient = new double[number]();//generate a temporary array to store the correlation matrix coefficients of the node
        for (int j = 1; j < number; j++) {
            if (i == j)
                continue;
            std::string tmp_line = std::to_string(min(i, j)) + "_" + std::to_string(max(i, j));//generate keywords for "line"
            int n = lineMap[tmp_line]->size();
            for (int k = 0; k < n; k++) {//Iterate over each element connected in parallel at the same two nodes
                if ((*lineMap[tmp_line])[k]->getType() == "resistor") {//Determining the type of element
                    tmp_coefficient[i - 1] += (1 / (*lineMap[tmp_line])[k]->getData());
                    tmp_coefficient[j - 1] -= (1 / (*lineMap[tmp_line])[k]->getData());
                } else if ((*lineMap[tmp_line])[k]->getType() == "current_source") {
                    if (i < j)
                        tmp_coefficient[number - 1] += ((*lineMap[tmp_line])[k]->getData());
                    else
                        tmp_coefficient[number - 1] -= ((*lineMap[tmp_line])[k]->getData());
                }
            }
        }
        for (int l = 0; l < number; l++) {
            coefficientMatrix[i - 1][l] = tmp_coefficient[l];
        }
    }
    for (int i = 1; i < number; i++) {//iterate the element connected between nodes that contained '0'
        std::string tmp_line = "0_" + std::to_string(i);
        int n = lineMap[tmp_line]->size();
        for (int k = 0; k < n; k++) {
            if ((*lineMap[tmp_line])[k]->getType() == "resistor") {
                coefficientMatrix[i - 1][i - 1] += (1 / (*lineMap[tmp_line])[k]->getData());
            } else if (((*lineMap[tmp_line])[k]->getType() == "current_source")) {
                coefficientMatrix[i - 1][number - 1] += ((*lineMap[tmp_line])[k]->getData());
            }
        }
    }
}

double **Circuit::getCoefficientMatrix() const {
    return coefficientMatrix;
}
