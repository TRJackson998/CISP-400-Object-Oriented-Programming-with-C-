#include "Person.h"

Person::Person() {
    name = "noname";
    age = 0;
}

Person::Person(string name, int age) {
    vector<string> illegalCharacters = {";", ":", "\"", "\'", "[", "]", "*", "&", "^", "%", "$", "#", "@", "!"};
    for (unsigned int i = 0; i < illegalCharacters.size(); i++) {
        if (name.find(illegalCharacters[i]) != string::npos) {
            error("Illegal character.\n");
        }
    }

    if (age > -1 && age < 150) {
        this -> name = name;
        this -> age = age;
    }
}

string Person::getName() const {
    return name;
}

int Person::getAge() const {
    return age;
}

istream& operator>>(istream &is, Person &person) {
    string nameStr;
    int ageInt;
    is >> nameStr >> ageInt;
    person = Person{nameStr, ageInt};
    return is;
}

ostream& operator<<(ostream &os, const Person &person) {
    os << person.name << " " << person.age;
    return os;
}