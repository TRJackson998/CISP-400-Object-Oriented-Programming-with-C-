#include "std_lib_facilities.h"

struct Person {
    string name;
    int age;
    string getName() const;
    int getAge() const;

    Person();
    Person(string name, int age);
};

istream& operator>>(istream &is, Person &person);
ostream& operator<<(ostream &os, const Person &person);
