#include <string>
#include <map>
#include <algorithm>
#include <iostream>
#include <numeric>

using namespace std;

template <typename T1, typename T2>
ostream& operator <<(ostream& os, map<T1, T2> mapperooni) {
    for(auto elem : mapperooni) {
        os << elem.first << " " << elem.second << endl;
    }
    return os;
}

istream& operator >>(istream& is, map<string, int> &mapperooni) {
    string key;
    int val;
    is >> key >> val;
    mapperooni.emplace(key, val);
    if(mapperooni.at(key) != val) {
        mapperooni.at(key) = val;
    }
    return is;
}

int summer(int init, pair<string, int> one) { return one.second + init; }

int main() {
    map<string, int> msi;

    msi["abc"] = 55;
    msi["def"] = 66;
    msi["ghi"] = 77;
    msi["jkl"] = 88;
    msi["mno"] = 99;

    cout << msi << endl;
    msi.erase(msi.begin(), msi.end());

    for(int i = 0; i < 5; i++) {
        cin >> msi;
    }

    cout << endl;
    cout << msi;
    cout << endl;


    cout << "Sum: " << accumulate(msi.begin(), msi.end(), 0, summer) << endl;

    map<int, string> mis;
    for(auto elem : msi) {
        mis.emplace(elem.second, elem.first);
    }
    
    cout << mis;


    return 0;
}