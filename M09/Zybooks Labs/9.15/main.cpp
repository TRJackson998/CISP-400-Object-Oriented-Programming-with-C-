#include <iostream>
#include <list>
#include <vector>
#include <array>
#include <algorithm>

using namespace std;

template<typename Iter1>
ostream& print_container(Iter1 f1, Iter1 e1, ostream &os) {
    while(f1 != e1) {
        os << *f1 << " ";
        f1++;
    }
    os << endl;
    return os;
}

template<typename Iter1, typename T>
void addX(Iter1 f1, Iter1 e1, const T& x) {
    while(f1 != e1) {
        *f1 += x;
        f1++;
    }
}

template<typename Iter1, typename T>
Iter1 my_find(Iter1 f1, Iter1 e1, const T& x) {
    while(f1 != e1) {
        if(*f1 == x) {
            return f1;
        }
        f1++;
    }
    return e1;
}

template<typename Iter1, typename Iter2>
Iter2 my_copy(Iter1 f1, Iter1 e1, Iter2 f2) {
    while(f1 != e1) {
        *f2 = *f1;
        f1++;
        f2++;
    }
    return f2;
}

int main() {
    array<int, 10> arr = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> vec(arr.begin(), arr.end());
    list<int> lst(arr.begin(), arr.end());

    addX(arr.begin(), arr.end(), 2);
    addX(vec.begin(), vec.end(), 3);
    addX(lst.begin(), lst.end(), 5);

    my_copy(arr.begin(), arr.end(), vec.begin());
    my_copy(lst.begin(), lst.end(), arr.begin());

    print_container(arr.begin(), arr.end(), cout);
    print_container(vec.begin(), vec.end(), cout);
    print_container(lst.begin(), lst.end(), cout);

    if(my_find(vec.begin(), vec.end(), 3) != vec.end()) {
        cout << "3 found in the vector at index 1" << endl;
    }
    else {
        cout << "3 not found in the vector.\n";
    }

    if(my_find(lst.begin(), lst.end(), 27) != lst.end()) {
        cout << "27 found in the vector at index 1" << endl;
    }
    else {
        cout << "27 not found in the list.\n";
    }


    return 0;
}
