#include <vector>
#include <iostream>
#include <fstream>
#include <numeric>
#include <algorithm>



using namespace std;
template <typename T>
ostream& operator<<(ostream& os, vector<T> vec) {
    for(T elem : vec) {
        os << elem << " ";
    }
    os << endl;
    return os;
}

template <typename T>
istream& operator>>(istream& is, vector<T> &vec) {
    T input;
    is >> input;
    vec.push_back(input);
    return is;
}

struct lessMean {
    double mean;
    lessMean(double inMean) : mean(inMean) {}
    bool operator()(double input) {return input < mean;}
};

vector<double> vd;
int main() {
    
    ifstream ifs;
    ifs.open("doubles.txt");
    if(!ifs.is_open()) {
        cout << "File could not open.\n";
        return 1;
    }

    while(!ifs.eof()) {
        ifs >> vd;
    }

    cout << vd;

    vector<int> vi(vd.size());
    copy(vd.begin(), vd.end(), vi.begin());
    cout << vi;

    double dSum = accumulate(vd.begin(), vd.end(), 0.0);
    int iSum = accumulate(vi.begin(), vi.end(), 0);

    cout << "Sum of vd: " << dSum << endl;
    cout << "diff of sums: " << dSum - iSum << endl;

    reverse(vd.begin(), vd.end());
    cout << "Reversed:\n" << vd;

    double dMean = dSum / vd.size();
    cout << "Mean: " << dMean << endl;

    vector<double> vd2(vd.size());
    copy_if(vd.begin(), vd.end(), vd2.begin(), lessMean(dMean));
    cout << vd2;
    sort(vd.begin(), vd.end());
    cout << vd;

    return 0;
}