//
// Created by Lenovo on 2021/12/9.
//

#ifndef ELEC2645CW2_2_SOLVEMATRIX_CHAO_H
#define ELEC2645CW2_2_SOLVEMATRIX_CHAO_H

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Node_chao.h"
#include "Element_chao.h"
#include "Resistor_chao.h"
#include "CurrentSource_chao.h"
#include "VoltageSource_chao.h"
#include "Test_chao.h"
#include "SolveMatrix.h"

struct result_chao {
    double Thevenin_voltage;
    double Thevenin_resistance;
};

result_chao solveMatrix_chao(std::vector<Node_chao> &nodes, std::vector<Element_chao> &elements, GraphNode** &graph) ;
#endif //ELEC2645CW2_2_SOLVEMATRIX_CHAO_H
