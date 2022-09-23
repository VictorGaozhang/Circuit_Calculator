//
// Created by macbookpro on 05/12/2021.
//

#include "GetNodeAndElement.h"

GetNodeAndElement::GetNodeAndElement(int number_of_nodes) {
    c = new Circuit(number_of_nodes);
    this->number_of_nodes = number_of_nodes;
    getElement();
}

void GetNodeAndElement::getElement() {
    number_of_elements = getNumber();
    for (int i = 0; i < number_of_elements; i++) {
        std::string line = getLine();
        std::string type = getType();
        double value = getValue(type);
        c->add_Element(line, type, value);
    }
}

int GetNodeAndElement::getNumber() {
    std::string numberStr;
    bool valid_input;
    do{
        valid_input = true;
        std::cout << "Please enter the number of elements:" << std::endl;
        std::cin >> numberStr;
        if(!is_integer(numberStr)){
            valid_input = false;
            std::cout << "The input variable is not a positive integer!" << std::endl;
        }
    }while(valid_input == false);
    return stoi(numberStr);
}

std::string GetNodeAndElement::getLine() {
    std::string line;
    bool valid_input;
    do {
        valid_input = true;
        std::cout << "Please enter the line name(for example, '0_1' represents the line between nodes 0 and 1)"
                  << std::endl;
        std::cin >> line;
        int mid = line.find('_');
        if (mid == std::string::npos) {
            valid_input = false;
            std::cout << "Invalid input of line!" << std::endl;
            continue;
        }
        if (!is_integer(line.substr(0, mid))) {
            valid_input = false;
            std::cout << "Invalid input of first node!" << std::endl;
            continue;
        }
        if (!is_integer(line.substr(mid + 1))) {
            valid_input = false;
            std::cout << "Invalid input of second node!" << std::endl;
            continue;
        }
        if(stoi(line.substr(0,mid))>=number_of_nodes){
            valid_input = false;
            std::cout << "Invalid input of first node!" << std::endl;
            continue;
        }
        if(stoi(line.substr(mid+1))>=number_of_nodes){
            valid_input = false;
            std::cout << "Invalid input of second node!" << std::endl;
            continue;
        }
        if(stoi(line.substr(0,mid))>=stoi(line.substr(mid+1))){
            valid_input = false;
            std::cout << "First node should be smaller than second one!" << std::endl;
        }
    } while (valid_input == false);
    return line;
}

std::string GetNodeAndElement::getType() {
    std::string typeNumber;
    bool valid_input;
    do {
        valid_input = true;
        std::cout << "Please enter the type of the element\n1 for resistor\n2 for current source:" << std::endl;
        std::cin >> typeNumber;
        if(!is_integer(typeNumber)){
            valid_input = false;
            std::cout << "Invalid input!" << std::endl;
            continue;
        }
        if (stoi(typeNumber) != 1 && stoi(typeNumber) != 2) {
            valid_input = false;
            std::cout << "Invalid input!" << std::endl;
        }
    } while (valid_input == false);
    if (stoi(typeNumber) == 1)
        return "resistor";
    else
        return "current_source";
}

double GetNodeAndElement::getValue(std::string type) {
    std::string valueStr;
    bool valid_input;
    do {
        valid_input = true;
        std::cout << "Please input value of the element(ohms for resistor, amps for current source):" << std::endl;
        std::cin >> valueStr;
        if (!is_double(valueStr)) {
            valid_input = false;
            std::cout << "The input is not a number!" << std::endl;
            continue;
        }
        if (type == "resistor" && stod(valueStr) <= 0) {
            valid_input = false;
            std::cout << "The resistance value must be a positive number!" << std::endl;
        }
    } while (valid_input == false);
    return std::stod(valueStr);
}

bool GetNodeAndElement::is_integer(std::string str) {
    return std::regex_match(str, std::regex("[+-]?[0-9]+"));
}

bool GetNodeAndElement::is_double(const std::string str) {
    char *p = nullptr;
    double d = strtod(str.c_str(), &p);
    return d != HUGE_VAL && *p == '\0';
}

Circuit *GetNodeAndElement::getCircuit() const {
    return c;
}


