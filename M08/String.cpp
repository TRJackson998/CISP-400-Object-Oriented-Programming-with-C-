#include "String.h"

using std::ostream; using std::istream; using std::cin; using std::cout; using std::endl;
using std::ofstream; using std::ifstream; using std::streambuf; using std::ios;

namespace String {
    string::string() : sz(0), pChars(nullptr), space(0) {
        //
    }
    string::string(const char* s) : sz(strlen(s)), pChars(new char[strlen(s)]), space(strlen(s)) {///Constructor using a null-terminated C String
        for(size_t i = 0; i < strlen(s); i++) {
            pChars[i] = s[i];
        }
    }
    string::string(const string& s) : sz(s.sz), pChars(new char[s.sz]), space(s.space) {                ///copy constructor
        for(size_t i = 0; i < s.sz; i++) {
            pChars[i] = s.pChars[i];
        }
    }
    string& string::operator=(const string& s) {     ///copy assignment
        if(this == &s) return *this;

        if(s.sz <= space) {
            for(int i = 0; i < s.sz; i++) {
                pChars[i] = s.pChars[i];
            }
            sz = s.sz;
            return *this;
        }
        string temp(s);
        delete[] pChars;
        pChars = temp.pChars;
        sz = temp.sz;
        space = temp.sz;
        temp.pChars = nullptr;
        return *this;
    }
    string& string::operator=(const char* s) {       ///copy assignment using a null-terminated C String
        if(this->pChars == s) return *this;

        if(strlen(s) <= space) {
            for(int i = 0; i < strlen(s); i++) {
                pChars[i] = s[i];
            }
            sz = strlen(s);
            return *this;
        }
        string temp(s);
        delete[] pChars;
        pChars = temp.pChars;
        sz = temp.sz;
        space = temp.sz;
        temp.pChars = nullptr;
        return *this;
    }
    string& string::operator=(string&& s) {          ///move assignment
        cout << "Move" << endl;
        delete[] pChars;
        pChars = s.pChars;
        sz = s.sz;
        space = s.space;

        s.pChars = nullptr;
        s.sz = 0;
        s.space = 0;

        return *this;
    }
    string::~string() {
        delete[] pChars;
    }

    char& string::operator[](size_t pos){               ///set operator
        return pChars[pos];
    }
    const char& string::operator[](size_t pos) const {   ///get operator
        return pChars[pos];
    }
    void string::reserve(size_t n) {
        if(n <= space) return;
        char* temp = new char[n];
        for(size_t i = 0; i < sz; i++) {
            temp[i] = pChars[i];
        }
        delete[] pChars;
        pChars = temp;
        space = n;
    }
    void string::push_back(const char c) {                   ///push char c to the end
        //cout << "Pushback called.\n";
        if(sz == 0 || sz == space) {
            reserve(1 + (2 * space));
        }
        pChars[sz] = c;
        sz++;
    }
    size_t string::find(const char* s, size_t pos) const { ///return index of first occurrence of s, SIZE_MAX if not found
        bool found = false;
        size_t index = SIZE_MAX;
        
        for(size_t i = pos; i < sz; i++) {
            if(pChars[i] == s[0]) {
                index = i;
                for(size_t j = 0; (j < strlen(s)) && (i < sz) && (index != SIZE_MAX); j++) {
                    if(pChars[i] != s[j]) {
                        index = SIZE_MAX;
                        found = false;
                    }
                    else {
                        i++;
                        found = true;
                    }
                }
                if(found) {
                    return index;
                }
            }
        }
        return index;
    }

    bool operator==(const string& lhs, const string& rhs) {  ///check equality (same size, all chars the same)
        if(lhs.size() != rhs.size()) {
            return false;
        }
        for(size_t i = 0; i < lhs.size(); i++) {
            if(lhs[i] != rhs[i]) {
                return false;
            }
        }
        return true;
    }
    bool operator==(const string& lhs, const char* rhs) {    ///equality with null terminated C string
        if(lhs.size() != strlen(rhs)) {
            return false;
        }
        for(size_t i = 0; i < lhs.size(); i++) {
            if(lhs[i] != rhs[i]) {
                return false;
            }
        }
        return true;
    }
    bool operator>(const string& lhs, const string& rhs) {   ///greater than operator, true if lhs > rhs
        int i = 0;
        for(i; (lhs[i] == rhs[i]) && (i < lhs.size()) && (i < rhs.size()); i++) {
            //correct, keep reading
        }
        if(!(lhs[i] > rhs[i])) {
            return false;
        }
        else {
            return true;
        }
    }
    string operator+(const string& lhs, const string& rhs) { ///concatenate two MyStrings, return the result
        string monsterString;
        for(size_t i = 0; i < lhs.size(); i++) {
            monsterString.push_back(lhs[i]);
        }
        for(size_t i = 0; i < rhs.size(); i++) {
            monsterString.push_back(rhs[i]);
        }
        return monsterString;
    }
    ostream& operator<<(ostream& os, const string& s) {
        for(size_t i = 0; i < s.size(); i++) {
            os << s[i];
        }
        return os;
    }
    istream& operator>>(istream& is, string& s) {
        char c;
        while((is.get(c)) && (!isspace(c))) {
            s.push_back(c);
        }
        return is;
    }
}