#include "Matrices.h"
#include "../std_lib_facilities.h"

using namespace Matrices;

/*
void PrintFourLines() {
    cout << endl << endl << endl << endl;
}
*/
void PrintTwoLines() {
    cout << endl << endl;
}

int main() {
    Matrix a(2,2);
    Matrix b(2,4);
    //Matrix c(2,4);

    //values for matrix a
        a(0,0) = 0;
        a(0,1) = -1;

        a(1,0) = 1;
        a(1,1) = 0;
        
    //values for matrix b
        b(0,0) = 1;
        b(0,1) = 0.866025;
        b(0,2) = 1;
        b(0,3) = 0.5;

        b(1,0) = 0;
        b(1,1) = 0.5;
        b(1,2) = 1;
        b(1,3) = 0.866025;

    //output matrix a and b
    cout << "a:";
    PrintTwoLines();
    cout << a;
    PrintTwoLines();
    cout << "b:";
    PrintTwoLines();
    cout << b;
    PrintTwoLines();
    //output addition
    cout << "c = b + b:";
    PrintTwoLines();
    cout << b+b;
    PrintTwoLines();
    //output multiplication
    cout << "c = a * b:";
    PrintTwoLines();
    cout << a * b;
    

    return 0;
}