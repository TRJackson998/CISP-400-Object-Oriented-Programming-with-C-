#include "Matrices.h"
#include "../std_lib_facilities.h"
using namespace std;

namespace Matrices {
    /*
    Construct a matrix of the specified size
    Initialize each element to 0
    Use vector.resize() on member variable a with num rows
    loop through each row and resize each a[i] to the number of columns
    Remember that a is a vector of vectors, so element a[i] represents one vector that contains the ith row.
    */
    Matrix::Matrix(int _rows, int _cols) {
        a.resize(_rows);
        for (int r = 0; r < _rows; r++) {
            a.at(r).resize(_cols);
        }
        rows = _rows;
        cols = _cols;
    }

    /*
    Add each corresponding element
    Construct a local matrix to store the result and return it
    usage: c = a + b;
    If a and b do not have the same number of rows and columns, throw an error
    */
    Matrix operator+(const Matrix& a, const Matrix& b) {
        //Matrix to hold the sum
        Matrix resultant_matrix(a.getRows(), a.getCols()); 

        //If the two inputs cannot be added
        if ((b.getRows() != a.getRows()) || (b.getCols() != a.getCols())) {
            error("Matrices cannot be added.");
        }

        //If the two inputs can be added
        double a_entry, b_entry;
        for (int r = 0; r < a.getRows(); r++) {
            for (int c = 0; c < a.getCols(); c++) {
                a_entry = a(r,c); //get the num @ the (row, col)
                b_entry = b(r,c);
                resultant_matrix(r,c) = a_entry + b_entry; //set the sum @ the (row, col)
            }
        }

        return resultant_matrix;
    }

    ///Matrix multiply.  See description.
    ///usage:  c = a * b;
    /*
    Matrices a(i,j) b(j,k)
    c(i,k) = a(i,0) * b(0,k) + a(i,1) * b(1,k) + a(i,2) * b(2,k) + ...
    The elements at row i of matrix a are multiplied and summed with the elements in column k of matrix b, 
    storing the resulting sum in element (i,k) in matrix c.
    This can be done with a triple nested for loop
    Let the outermost loop control k, the column index for b
    Let the loop inside of that control i, the row for a
    The innermost loop will control j, which will determine which column to use from a and which row to use from b. 
    Multiply each a(i,j) * b(j,k) and create a running sum.
    When the j loop is finished, store the resulting sum in c(i,k)
    In order for this to work, the number of columns in a have to equal the number of rows in b.  If they do not, throw an error.
    Test your calculated results against handwritten examples to make sure it is working
    Construct a local matrix to store the result and return it
    usage: c = a * b;
    In the example below,
    c(0,0)=a(0,0)*b(0,0)+a(0,1)*b(1,0) = 0*1+(-1)*0 = 0
    c(0,1)=a(0,0)*b(0,1)+a(0,1)*b(1,1) = 0*0.866025+-1*0.5 = -0.5
    c(0,2)=a(0,0)*b(0,2)+a(0,1)*b(1,2) = 0*1+-1*1 = -1
    ...
    c(1,3)=a(1,0)*b(0,3)+a(1,1)*b(1,3) = 1*0.5+0*0.866025=0.5
    */
    Matrix operator*(const Matrix& a, const Matrix& b) {
        if (a.getCols() != b.getRows()) { //if matrices are not multiplicable
            error("Matrices cannot be multiplied");
        }
        //else resultant matrix will have a.rows by b.cols
        Matrix resultant_matrix(a.getRows(), b.getCols());
        double a_entry, b_entry, sum_entry = 0.0;

        for (int k = 0; k < b.getCols(); k++) {
            for (int i = 0; i < a.getRows(); i++) {
                for (int j = 0; j < a.getCols(); j++) {
                    a_entry = a(i,j);
                    b_entry = b(j,k);
                    sum_entry += (a_entry * b_entry);
                    /*
                    cout << "a(" << i << ", " << j << ") = " << a_entry 
                         << " * b(" << j << ", " << k << ") = " << b_entry
                         << " == " << (a_entry * b_entry) << endl;
                    cout << "sum_entry is: " << sum_entry << endl;
                    */
                }
                resultant_matrix(i,k) = sum_entry;
                sum_entry = 0;
                //cout << "result at " << i << " " << k << " = " << resultant_matrix(i,k) << endl << endl;
            }
        }
        
        return resultant_matrix;
    }

    /*
    Matrix comparison. Usage a == b
    If the rows and columns are not equal, return false
    If any element (i,j) does not match, return false
    Otherwise return true
    */
    bool operator==(const Matrix& a, const Matrix& b) {
        bool equal = true;
        
        //if the rows and cols aren't equal, set false flag
        if ((b.getRows() != a.getRows()) || (b.getCols() != a.getCols())) {
            equal = false;
        }

        int a_entry, b_entry;
        for (int r = 0; r < a.getRows(); r++) {
            for (int c = 0; c < a.getCols(); c++) {
                a_entry = a(r,c); //get the num @ the (row, col)
                b_entry = b(r,c);
                if (a_entry != b_entry) { //if the nums aren't the same, set false flag
                    equal = false;
                }
            }
        }
        return equal;    
    }

    ///Matrix comparison, opposite of a == b. Usage:  a != b
    bool operator!=(const Matrix& a, const Matrix& b) {
        return !(a == b);
    }

    ///Output matrix.
    ///Separate columns by ' ' and rows by '\n'
    ostream& operator<<(ostream& os, const Matrix& a) {
        for (int r = 0; r < a.getRows(); r++) {
            for (int c = 0; c < a.getCols(); c++) {
                os << setw(10) << a(r,c) << ' ';
            }
            os << "\n";
        }
        return os;
    }

}