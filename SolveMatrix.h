//
// Created by macbookpro on 01/12/2021.
// Some code of this file references from：https://www.cnblogs.com/l2017/p/7856623.html
//

#ifndef ELECTRONICCIRCUIT_SOLVEMATRIX_H
#define ELECTRONICCIRCUIT_SOLVEMATRIX_H

#include <iostream>
#include <random>
#include <time.h>
#include "Matrix.h" //Matrix：http://www.stroustrup.com/Programming/Matrix/Matrix.h
                    // Source:Bjarne Stroustrup
#include "MatrixIO.h"//MatrixIO：http://www.stroustrup.com/Programming/Matrix/MatrixIO.h
                   // Source:Bjarne Stroustrup

using namespace Numeric_lib;//The matrix library is defined in the namespace Numeric_lib
using namespace std;
typedef Numeric_lib::Matrix<double, 2> Matrix2;
typedef Numeric_lib::Matrix<double, 1> Vector;


Vector back_substitution(const Matrix2 &A, const Vector &b);

void elim_with_partial_pivot(Matrix2 &A, Vector &b);

Vector classic_gaussian_elimination(Matrix2 A, Vector b);

void solve_system(Index n, Matrix2 A, Vector b);


#endif //ELECTRONICCIRCUIT_SOLVEMATRIX_H
