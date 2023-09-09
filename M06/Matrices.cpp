#include "Matrices.h"

namespace Matrices {
    Matrix::Matrix(int _rows, int _cols) : rows(_rows), cols(_cols) {
        a.resize(_rows);
        for (int r = 0; r < _rows; r++) {
            a.at(r).resize(_cols);
        }
    }

    void Matrix::addCoordinate(double x, double y) {
        ///push back x into the first row and y into the second row
        a.at(0).push_back(x);
        a.at(1).push_back(y);
        ///add one to cols member variable to keep track
        cols += 1;
    }

    ///usage:  c = a + b;
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
                }
                resultant_matrix(i,k) = sum_entry;
                sum_entry = 0;
            }
        }
        return resultant_matrix;
    }

    ///Matrix comparison.  See description.
    ///usage:  a == b
    bool operator==(const Matrix& a, const Matrix& b) {
        bool equal = true;
        
        //if the rows and cols aren't equal, set false flag
        if ((b.getRows() != a.getRows()) || (b.getCols() != a.getCols())) {
            equal = false;
        }

        double a_entry, b_entry;
        for (int r = 0; r < a.getRows(); r++) {
            for (int c = 0; c < a.getCols(); c++) {
                a_entry = a(r,c); //get each entry at the (row, col)
                b_entry = b(r,c);
                if (a_entry != b_entry) { //if the nums aren't the same, set false flag
                    equal = false;
                }
            }
        }
        return equal;    
    }

    ///Matrix comparison.  See description.
    ///usage:  a != b
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


    RotationMatrix::RotationMatrix(double theta) : Matrix(2,2) {
        ///Call the parent constructor to create a 2x2 matrix
        ///Then assign each element as follows:
        /*
        cos(theta)  -sin(theta)
        sin(theta)   cos(theta)
        */
        a.at(0).at(0) = cos(theta);
        a.at(0).at(1) = -sin(theta);
        a.at(1).at(0) = sin(theta);
        a.at(1).at(1) = cos(theta);
        ///theta represents the angle of rotation in radians, counter-clockwise
    }


    ScalingMatrix::ScalingMatrix(double scale) : Matrix(2,2) {
        ///Call the parent constructor to create a 2x2 matrix
        ///Then assign each element as follows:
        /*
        scale   0
        0       scale
        */
        a.at(0).at(0) = scale;
        a.at(0).at(1) = 0;
        a.at(1).at(0) = 0;
        a.at(1).at(1) = scale;
        ///scale represents the size multiplier
    }

    TranslationMatrix::TranslationMatrix(double xShift, double yShift, int nCols) : Matrix(2,nCols) {
        ///Call the parent constructor to create a 2xn matrix
        ///Then assign each element as follows:
        /*
        xShift  xShift  xShift  ...
        yShift  yShift  yShift  ...
        */
        for (int c = 0;c < nCols; c++) {
            a.at(0).at(c) = xShift;
            a.at(1).at(c) = yShift;
        }
        ///paramaters are xShift, yShift, and nCols
        ///nCols represents the number of columns in the matrix
        ///where each column contains one (x,y) coordinate pair
    }

}