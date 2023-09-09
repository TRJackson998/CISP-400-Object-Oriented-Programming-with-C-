#include "std_lib_facilities.h"
#include "B.h"

int main() {
    //B1 bug_object;
    D1 d1Object;
    d1Object.f();
    d1Object.vf();
    d1Object.pvf();

    B1& ptr = d1Object;
    ptr.f();
    ptr.vf();
    ptr.pvf();

    D2 d2Object;
    d2Object.f();
    d2Object.vf();
    d2Object.pvf();

    D21 d21Object;
    D22 d22Object;

    f(d21Object);
    f(d22Object);

    return 0;
}