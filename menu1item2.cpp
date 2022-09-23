//
// Created by macbookpro on 05/12/2021.
//
#include "menu1item2.h"

bool is_integer(std::string basicString);

void menu1item2(){
    int number_of_nodes = getNumber();
    GetNodeAndElement *getThings = new GetNodeAndElement(number_of_nodes);
    Circuit *c = getThings->getCircuit();
    c->calculateCoefficients();
    Matrix2 matrix(number_of_nodes - 1, number_of_nodes - 1);
    for (int i = 0; i < number_of_nodes - 1; i++) {
        for (int j = 0; j < number_of_nodes - 1; j++) {
            matrix[i][j] = c->getCoefficientMatrix()[i][j];
        }
    }

    Vector b(number_of_nodes - 1);
    for (int i = 0; i < number_of_nodes - 1; i++) {
        b[i] = c->getCoefficientMatrix()[i][number_of_nodes - 1];
    }

    solve_system(number_of_nodes - 1, matrix, b);
}

int getNumber() {
    std::string numberStr;
    bool valid_input;
    do{
        valid_input = true;
        std::cout << "Welcome to Circuit Node Voltage Divider Calculator\nPlease enter the number of nodes:" << std::endl;
        std::cin >> numberStr;
        if(!is_integer_this(numberStr)){
            valid_input = false;
            std::cout << "The input variable is not a positive integer!" << std::endl;
        }
    }while(valid_input == false);
    return stoi(numberStr);
}

bool is_integer_this(std::string str) {
    return std::regex_match(str, std::regex("[+-]?[0-9]+"));
}
