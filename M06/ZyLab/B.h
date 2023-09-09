#include "std_lib_facilities.h"

class B1 {
    public:
        virtual void vf() {
            cout << "B1::vf()\n";
        }
        void f() {
            cout << "B1::f()\n";
        }
        virtual void pvf() const = 0;
};

class D1 : public B1 {
    public:
        void f() {
            cout << "D1::f()\n";
        }
        void vf() override {
            cout << "D1::vf()\n";
        }
        void pvf() const override {
            cout << "D1::pvf()\n";
        }
};

class D2 : public D1 {
    public:
        void pvf() const override {
            cout << "D2::pvf()\n";
        }
};

class B2 {
    public:
        virtual void pvf() const = 0;
};

class D21 : public B2 {
    public:
        string str = "D21::pvf()";
        void pvf() const {
            cout << str << endl;
        }
};

class D22 : public B2 {
    public:
        int integer = 22;
        void pvf() const {
            cout << integer << endl;
        }
};

void f(B2& b2address) {
    b2address.pvf();
}