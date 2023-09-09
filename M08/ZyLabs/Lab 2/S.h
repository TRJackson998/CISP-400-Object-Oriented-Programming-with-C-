#include "std_lib_facilities.h"

template <typename T>
struct S {
    private:
        T val;
    public:
        S(T userVal) {val = userVal;}
        T& get() {return val;}
        const T& get() const {return val;}
        S<T>& operator=(const T& t) {val = t; return *this;}
};

template<typename T> istream& operator>>(istream& is, S<T>& s) {
    T temp;
    is >> temp;
    s = temp;
    return is;
}

template<typename T> ostream& operator<<(ostream& os, const S<T>& s) {
    os << s.get() << " ";
    return os;
}

template<typename T> istream& operator>>(istream& is, vector<T>& v) {
    T v1, v2, v3;
    char comma, bracket;
    vector<T> tempV;
    if(is >> bracket >> v1 >> comma >> v2 >> comma >> v3 >> bracket) {
        tempV.push_back(v1);
        tempV.push_back(v2);
        tempV.push_back(v3);

        v.resize(3);

        v[0] = tempV[0];
        v[1] = tempV[1];
        v[2] = tempV[2];
    }
    return is;
}

template<typename T> ostream& operator<<(ostream& os, const vector<T>& v) {
    char comma = ',', oBracket = '{', cBracket = '}';
    os << oBracket << v[0] << comma << v[1] << comma << v[2] << cBracket;
    return os;
}