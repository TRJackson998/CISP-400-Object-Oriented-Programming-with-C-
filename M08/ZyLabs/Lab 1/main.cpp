#include "std_lib_facilities.h"

void print_array(ostream &os, int *a, int n) {
    for(int i = 0; i < n; i++) {
        os << a[i] << " ";
    }
    os << endl;
}

int* allocate_n(int n) {
    int *a = new int[n];
    for(int i = 0; i < n; i++) {
        a[i] = 100 + i;
    }
    return a;
}

void print_vector(ostream &os, const vector<int> &v) {
    for(unsigned int i = 0; i < v.size(); i++) {
        os << v.at(i) << " ";
    }
    os << endl;
}

vector<int> construct_v(int n) {
    vector<int> vect(n, 100);
    for(int i = 0; i < n; i++) {
        vect.at(i) += i;
    }
    return vect;
}

int* copy_n(int* a, int n) {
    int* b = new int[n];
    for(int i = 0; i < n; i++) {
        b[i] = a[i];
    }
    return b;
}

int main() {
    int *testPtr;
    testPtr = allocate_n(20);
    print_array(cout, testPtr, 20);

    vector<int> testVector;
    testVector = construct_v(20);
    print_vector(cout, testVector);

    print_array(cout, copy_n(testPtr, 20), 20);

    delete[] testPtr;
}