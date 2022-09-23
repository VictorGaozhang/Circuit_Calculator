//
// Created by macbookpro on 05/12/2021.
//

#ifndef MAINPROJECT_GETNODEANDELEMENT_H
#define MAINPROJECT_GETNODEANDELEMENT_H

#include "Circuit.h"
#include <iostream>
#include <string>
#include <cmath>
#include <regex>


class GetNodeAndElement {
public:
    GetNodeAndElement(int number_of_nodes);
    void getElement();

    int getNumber();
    std::string getLine();
    std::string getType();
    double getValue(std::string type);

    bool is_integer(std::string str);
    bool is_double(const std::string str);

    Circuit *getCircuit() const;


private:
    Circuit* c;
    int number_of_nodes;
    int number_of_elements;

};


#endif //MAINPROJECT_GETNODEANDELEMENT_H
