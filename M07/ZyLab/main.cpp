#include "Person.h"

int main() {
    Person goof("Goofy", 63);
    cout << goof << endl;

    vector<Person> personVector;
    while (cin) {
        Person input;
        cin >> input;
        personVector.push_back(input);
    }

    for (unsigned int i = 0; i < personVector.size() - 1; i++) {
        cout << personVector[i] << endl;
    }


    return 0;
}