#include "S.h"

int main() {
    S<int> inty(0);
    S<char> chary('0');
    S<double> dub(0.0);
    S<string> str("0");
    S<vector<int>> vect{{0}};

    cin >> inty >> chary >> dub >> str >> vect;
    cout << inty << endl << chary << endl << dub << endl << str << endl << vect;

    return 0;
}