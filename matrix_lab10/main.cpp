#include <iostream>
#include "Matrix2D.h"
#include "Matrix3D.h"
using namespace std;

int main()
{
    Matrix2D matrix2a, matrix2b;
    Matrix3D matrix3a, matrix3b;
    cout << "matrix2a \n\n"
         << matrix2a << endl;
    cout << "matrix2b \n\n"
         << matrix2b << endl;
    cout << "matrix3a \n\n"
         << matrix3a << endl;
    cout << "matrix3b \n\n"
         << matrix3b << endl;

    matrix3a += matrix3b;
    matrix2a *= 8;

    cout << "matrix3a + matrix3b \n\n"
         << matrix3a << endl;
    cout << "matrix2a * 8 \n\n"
         << matrix2a << endl;

    return 0;
}
