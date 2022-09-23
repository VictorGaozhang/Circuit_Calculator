//Some code of this file references from：https://www.cnblogs.com/l2017/p/7856623.html

#include "SolveMatrix.h"

Vector back_substitution(const Matrix2 &A, const Vector &b) {
    const Index n = A.dim1();
    Vector x(n);

    for (Index i = n - 1; i >= 0; --i) {
        double s = b(i) - dot_product(A[i].slice(i + 1), x.slice(i + 1));

        if (double m = A(i, i))
            x(i) = s / m;
        else;
    }
    return x;
}

void elim_with_partial_pivot(Matrix2 &A, Vector &b) {
    const Index n = A.dim1();

    for (Index j = 0; j < n; ++j) {
        Index pivot_row = j;

        //Find a suitable primary element
        for (Index k = j + 1; k < n; ++k)
            if (abs(A(k, j)) > abs(A(pivot_row, j))) pivot_row = k;

            //If we find a better master element, swap two lines.
        if (pivot_row != j) {
            A.swap_rows(j, pivot_row);
            std::swap(b(j), b(pivot_row));
        }

        //Eliminate：
        for (Index i = j + 1; i < n; ++i) {
            const double pivot = A(j, j);
            if (pivot == 0)error("can't solve:pivot==0");
            const double mult = A(i, j) / pivot;
            A[i].slice(j) = scale_and_add(A[j].slice(j), -mult, A[i].slice(j));
            b(i) -= mult * b(j);

        }
    }
}

Vector classic_gaussian_elimination(Matrix2 A, Vector b) {
    elim_with_partial_pivot(A, b);
    return back_substitution(A, b);
}

void solve_system(Index n, Matrix2 A, Vector b) {
    cout << "A=" << A << '\n';
    cout << "b=" << b << '\n';
    try {
        Vector x = classic_gaussian_elimination(A, b);
        cout << "Node voltages from Node 1 to Node "<< x.size() << " is " << x << " volts" << '\n';

    }
    catch (const exception &e) {
        cerr << e.what() << '\n';
    }

}

