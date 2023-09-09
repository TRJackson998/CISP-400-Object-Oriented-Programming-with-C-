#include "Record.h"

int main() {
    vector<Record> recVec;
    Record rec1, rec2, rec3;
    rec1.name = "Rick Astley Greatest Hits";
    rec1.money = 69.99;

    rec2.name = "Razzmatazz";
    rec2.money = 199.98;

    rec3.name = "The White Album";
    rec3.money = 199.99;

    recVec.push_back(rec1);
    recVec.push_back(rec2);
    recVec.push_back(rec3);

    std::sort(recVec.begin(), recVec.end(), CmpName());
    cout << recVec;

    rec3.name = "ABBA Greatest Hits";
    recVec.push_back(rec3);

    rec2.money = 10.50;
    recVec.push_back(rec2);

    recVec.at(1).money = 100;

    std::sort(recVec.begin(), recVec.end(), CmpMoney());
    cout << recVec;

    
    return 0;
}