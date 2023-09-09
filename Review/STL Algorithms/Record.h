#ifndef RECORD_H
#define RECORD_H

#include "../std_lib_facilities.h"

struct Record {
    public:
        string name;
        double money;
};

struct CmpName {
    bool operator()(const Record& lhs, const Record& rhs) { return lhs.name < rhs.name; }
};

struct CmpMoney {
    bool operator()(const Record& lhs, const Record& rhs) { return lhs.money < rhs.money; }
};

ostream& operator<<(ostream& os, vector<Record> recVec) {
    for(size_t i = 0; i < recVec.size(); i++) {
        os << fixed << setprecision(2)
           << recVec.at(i).name << " $" << recVec.at(i).money << " ";
    }
    os << endl;
    return os;
}

#endif